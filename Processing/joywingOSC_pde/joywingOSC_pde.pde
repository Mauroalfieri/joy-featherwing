/*
Receives and visualizes OSCBundles sent over UDP

Use with /examples/UDPSendBundle

or with /examples/SerialSendBundle in conjunction 
with /Applicaitons/Processing/SLIPSerialToUDP
*/

import oscP5.*;
import netP5.*;
  
OscP5 oscP5;

int mouseStepX = 516;
int mouseStepY = 525;

int buttonTop    = 0;
int buttonLeft   = 0;
int buttonRight  = 0;
int buttonDown   = 0;

int buttonSelect = 0;
int buttonReset  = 0;

void setup() {
  size(700,300);
  frameRate(30);
  //set this to the receiving port
  oscP5 = new OscP5(this,9001);
}

void draw() {
  background(0); 
  
  /************* Text ************************************************/
  textSize(12);
  text("analog0:", 50, 270);     text(mouseStepX,    150, 270);
  text("analog1:", 50, 280);     text(mouseStepY,    150, 280);
  
  text("Select:", 275, 260);      text(buttonSelect, 350, 260);
  text("Reset: ", 275, 270);      text(buttonReset,  350, 270);
  
  text("ButtonTop:", 500, 260);   text(buttonTop,    600, 260);
  text("ButtonLeft:", 500, 270);  text(buttonLeft,   600, 270);
  text("ButtonRigh:", 500, 280);  text(buttonRight,  600, 280);
  text("ButtonDown:", 500, 290);  text(buttonDown,   600, 290);
  
  /************* Graph ***********************************************/
  noFill();
  stroke(255);
  rect(50, 20, 200, 200);

  fill(255);
  float mouseXPos = map(mouseStepX, 0, 1023, 50, 230);
  float mouseYPos = map(mouseStepY, 0, 1023, 20, 200);
  rect(mouseXPos, mouseYPos, 20, 20);
  
  /************* Button Right ****************************************/
  if ( buttonTop == 0 )     fill(255,0,0); else fill(255); ellipse(600, 75, 30, 30);
  if ( buttonRight == 0 )   fill(255,0,0); else fill(255); ellipse(650, 125, 30, 30);
  if ( buttonLeft == 0 )    fill(255,0,0); else fill(255); ellipse(550, 125, 30, 30);
  if ( buttonDown == 0 )    fill(255,0,0); else fill(255); ellipse(600, 175, 30, 30);
  
  /************* Button Left  ****************************************/
  if ( buttonSelect == 0 )  fill(255,0,0); else fill(255); ellipse(350, 50, 30, 30);
  if ( buttonReset  == 0 )  fill(255,0,0); else fill(255); ellipse(350, 135, 30, 30);
  
  fill(255);
}

// incoming osc message are forwarded to the oscEvent method. 
void oscEvent(OscMessage theOscMessage) {
  //println(theOscMessage.addrPattern());
  if (theOscMessage.addrPattern().equals("/analog/1")){
    mouseStepX = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/analog/0")){
    mouseStepY = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/button/top")){
    buttonTop = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/button/left")){
    buttonLeft = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/button/right")){
    buttonRight = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/button/down")){
    buttonDown = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/button/select")){
    buttonSelect = theOscMessage.get(0).intValue();
  } else if(theOscMessage.addrPattern().equals("/button/reset")){
    buttonReset = theOscMessage.get(0).intValue();
  }
}