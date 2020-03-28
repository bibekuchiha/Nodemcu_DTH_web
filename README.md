<h1> Nodemcu_DTH_web</h1>
<h2>Introduction</h2>
<p>I was enlivened to make a temperature sensor that I can screen over wifi. This task isn't new, yet I like having middle of the road layer for security and not opening port in your switch to your IoT gadget.</p>
<br>The temperature sensor is associated with the simple contribution of the ESP8266 WIFI module, which will occasionally present the temperature on a cloud based facilitating (right now am just utilizing webserver with php server side scripting). At that point you can get to the temperature anyplace from the cloud (webserver) to check what is the present temperature.</br>
<h2> Installation</h2>
<p>Introduce the Arduino IDE, it bolster differing stage, windows, Linux and Mac. Simply utilize the one you are alright with. 

I am expecting you are agreeable to introduce and get this moving. 

Once Arduino is introduced the time has come to test your ESP8266 wifi load up. You can interface the board utilizing USB link to your PC. The PC ought to identify this consequently. 

- Select the right board from Tools->Board-> NodeMCU 1.0 (ESP-12E module) 

- The subsequent stage is to choose the port where your ESP8266 is associated with, so go to Tools->Port-> mine come up as/dev/cu.wchusbserial14750, (you could have something different) 

When you have this associated you can test the association and the board by stacking the model sketch 

- Select File->Examples->ESP8266->Blink 

This will open the Blink sketch, you can tap on the "Transfer" catch to transfer your sketch. In the event that all goes well the Led on your ESP8266 should begin squinting.</p>
<h2>Connect temperature Sensor</h2>
<p>The temperature sensor LM35 have 3 legs, the principal leg is VCC, you can interface this to the 5V (ESP8266 board's yield is 3.3V). The center leg is Vout (where the temperature is perused from, you can interface this to the simple contribution of the ESP8266 pin AD0, this is situated at the upper right hand side of the board as appeared in picture. Also, the correct leg ought to be associated with the ground. Presently your circuit is finished.</p>
<h2> Execute the program</h2>
By executing the program you will get the current temperature in your system.
