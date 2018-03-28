# JoyPad with joy featherwing

How to create a simple joypad using the Adafruit joy featherwing.

![JoyPad 3D](https://github.com/Mauroalfieri/joy-featherwing/blob/master/3D%20images/openscad%20joy%20featherwing%203D%20all%20view.jpg?raw=true)

The repository contains:

* CAD files 2D DWG and DXF in mm  
* 3D images of Joypad
* 3D STL files ready for the printing
* Arduino & Processign OSC sketch

### Dedicated project post ( ITA )
You can read the full post in Italian language on the blog:

* [mauroalfieri.it Feather joy-featherwing] (http://www.mauroalfieri.it/elettronica/feather-joy-featherwing.html)
* [mauroalfieri.it joywing dwg dxf] (http://www.mauroalfieri.it/elettronica/feather-joywing-dwg-dxf.html)
* [mauroalfieri.it Feather joywing] (http://www.mauroalfieri.it/elettronica/feather-joywing.html)
* [mauroalfieri.it Feather ESP8266 battery] (http://www.mauroalfieri.it/elettronica/feather-esp8266-battery.html)
* [mauroalfieri.it joy feathering 3D] (http://www.mauroalfieri.it/elettronica/joy-featherwing-3d.html)
* [mauroalfieri.it Joypad OSC ESP8266] (http://www.mauroalfieri.it/elettronica/joypad-osc-esp8266.html)
* [mauroalfieri.it Joypad OSC Processing] (http://www.mauroalfieri.it/elettronica/joypad-osc-processing.html)
* [mauroalfieri.it joypad 3d] (http://www.mauroalfieri.it/elettronica/joypad-joy-featherwing-3d.html)

### How does it work ?

The board Feather esp8266 Adafruit is used to establish the connection WiFi and micro controller. The signals from joywing are readed by board esp8266 and transferred trought OSC ( Open Sound Control ) protocol to your Pc.

The Pc/Mac interface, written in Processing, receive the data through a connection Udp with protocol OSC and  renderize a graphic joypad:

![interface joypad processing](https://github.com/Mauroalfieri/joy-featherwing/blob/master/Processing/Processing_joypad_interface.jpg?raw=true)

### Demo - video
You can show the demo video on my [youtube channel](https://www.youtube.com/user/doctoralma77) or below:

[![JoyPad Demo](http://img.youtube.com/vi/FlawIXcAiWg/0.jpg)](https://www.youtube.com/watch?v=FlawIXcAiWg "Joypad Demo")

### License 
All source code are shared under CC-by-sa-4.0

Copyright (c) 2018-2022 Mauro Alfieri

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
