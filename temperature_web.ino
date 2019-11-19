#include <ESP8266WiFi.h>
#include"dht.h"
#define PIN D0
dht  dht1;
float temp;
float hum;
const char *ssid =  "Bibek";     // replace with your wifi ssid and wpa2 key
const char *pass =  "uchihabibek";

WiFiServer server(100);
 
void setup() 
{
 Serial.begin(9600);
  delay(10);
  
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
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() 
{      
    dht1.read11(PIN);
    temp=dht1.temperature;
    hum=dht1.humidity;
    // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
     delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

    // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println(" <meta http-equiv=\"refresh\" content=\"0;URL='http://10.0.0.36:100/'\" /> ");
  client.println("</head>");
  client.println("<body>");
  client.println("<br>Temperature:");
  client.print(temp);
  client.print("  C<br>");
  client.println("<br>Humidity:");
  client.print(hum);
  client.print("  %<br>");
    
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  
}
