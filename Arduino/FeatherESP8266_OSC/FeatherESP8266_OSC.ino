#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCBundle.h>
#include "Adafruit_seesaw.h"

Adafruit_seesaw ss;

#define BUTTON_RIGHT 6
#define BUTTON_DOWN  7
#define BUTTON_LEFT  9
#define BUTTON_UP    10
#define BUTTON_SEL   14
uint32_t button_mask = (1 << BUTTON_RIGHT) | (1 << BUTTON_DOWN) | 
                (1 << BUTTON_LEFT) | (1 << BUTTON_UP) | (1 << BUTTON_SEL);

#define IRQ_PIN   2

char ssid[] = "[insert your SSID]";        // your network SSID (name)
char pass[] = "[insert your password]";    // your network password

WiFiUDP Udp;                                // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(192,168,2,10);        // remote IP of your computer
const unsigned int outPort = 9001;          // remote port to receive OSC
const unsigned int localPort = 8001;        // local port to listen for OSC packets (actually not used for sending)

int last_x = 0, last_y = 0;

void setup() {
    Serial.begin(115200);

    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(Udp.localPort());

    if(!ss.begin(0x49)){
      Serial.println("ERROR!");
      while(1);
    }
    else{
      Serial.println("seesaw started");
      Serial.print("version: ");
      Serial.println(ss.getVersion(), HEX);
    }
    ss.pinModeBulk(button_mask, INPUT_PULLUP);
    ss.setGPIOInterrupts(button_mask, 1);
    pinMode(IRQ_PIN, INPUT);
}

void loop() {
  int x = ss.analogRead(2);
  int y = ss.analogRead(3);
  
  if ( (abs(x - last_x) > 3)  ||  (abs(y - last_y) > 3)) {
    Serial.print(x); Serial.print(" "); 
    Serial.print(y); Serial.print(" ");
    last_x = x;
    last_y = y;
  } else {
    Serial.print(last_x); Serial.print(" "); 
    Serial.print(last_y); Serial.print(" ");
  }
  
  uint32_t buttons = ss.digitalReadBulk(button_mask);
  uint16_t bTop    = 0;
  uint16_t bDown   = 0;
  uint16_t bRight  = 0;
  uint16_t bLeft   = 0;
  uint16_t bSelect = 0;
  
  if (! (buttons & (1 << BUTTON_RIGHT))) { bRight = 1023; }
  Serial.print( bRight ); Serial.print(" ");
  
  if (! (buttons & (1 << BUTTON_DOWN))) { bDown = 1023; }
  Serial.print( bDown ); Serial.print(" ");
  
  if (! (buttons & (1 << BUTTON_LEFT))) { bLeft = 1023;  }
  Serial.print( bLeft ); Serial.print(" ");
  
  if (! (buttons & (1 << BUTTON_UP))) { bTop = 1023; }
  Serial.print( bTop ); Serial.print(" ");
  
  if (! (buttons & (1 << BUTTON_SEL))) { bSelect = 1023; }
  Serial.print( bSelect ); Serial.println(" ");

  OSCBundle bndl;
  bndl.add("/analog/0").add((int32_t)last_x);
  bndl.add("/analog/1").add((int32_t)last_y);
  
  bndl.add("/button/top").add((uint16_t)bTop);
  bndl.add("/button/down").add((uint16_t)bDown);
  bndl.add("/button/right").add((uint16_t)bRight);
  bndl.add("/button/left").add((uint16_t)bLeft);
  bndl.add("/button/select").add((uint16_t)bSelect);
  
  Udp.beginPacket(outIp, outPort);
  bndl.send(Udp);
  Udp.endPacket();
  bndl.empty();

  delay(10);
}
