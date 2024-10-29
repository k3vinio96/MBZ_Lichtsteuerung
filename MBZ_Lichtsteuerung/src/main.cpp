#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_MCP23X17.h>

#include "html/indexPage.h"

// put function declarations here:
void StartAccessPoint(const char *, const char *);
void ServerHandler();
void handleRoot();
void handleRelay();


void handleRelay0();
void handleRelay1();
void handleRelay2();
void handleRelay3();
void handleRelay4();
void handleRelay5();
void handleRelay6();
void handleRelay7();
void handleRelay8();
void handleRelay9();
void handleRelay10();
void handleRelay11();
void handleRelay12();
void handleRelay13();
void handleRelay14();
void handleRelay15();

Adafruit_MCP23X17 mcp;

const char *ssid = "MBZ_Licht";
const char *password = "LangenLicht";

int RelayNo;

// port setzen
ESP8266WebServer server(80);
IPAddress local_IP(192, 168, 4, 1);

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.write("\n- - - - - - - - - - - - - - ");
  Serial.write("\nMBZ Lichtsteuerung gestartet");
  Serial.write("\n- - - - - - - - - - - - - - \n");

  // Pin Modes definieren
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Port Expander initialiseren
  if (mcp.begin_I2C())
  {
    // alle 16 IO's als OUTPUT setzen
    for (int i = 0; i < 16; i++)
    {
      mcp.pinMode(i, OUTPUT);
    }
  }

  // AccessPoint initialisieren
  StartAccessPoint(ssid, password);
  ServerHandler();
  server.begin();

  Serial.write("\nWebserver gestartet\n");

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
  // put your main code here, to run repeatedly:
  server.handleClient();
}

// put function definitions here:
void StartAccessPoint(const char *ssid, const char *password)
{
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
}

void ServerHandler()
{
  server.on("/", HTTP_GET, handleRoot);
  server.on("/RelayControl", HTTP_POST, handleRelay);
  server.on("/Relay1", HTTP_POST, handleRelay0);
  server.on("/Relay2", HTTP_POST, handleRelay1);
  server.on("/Relay3", HTTP_POST, handleRelay2);
  server.on("/Relay4", HTTP_POST, handleRelay3);
  server.on("/Relay5", HTTP_POST, handleRelay4);
  server.on("/Relay6", HTTP_POST, handleRelay5);
  server.on("/Relay7", HTTP_POST, handleRelay6);
  server.on("/Relay8", HTTP_POST, handleRelay7);
  server.on("/Relay9", HTTP_POST, handleRelay8);
  server.on("/Relay10", HTTP_POST, handleRelay9);
  server.on("/Relay11", HTTP_POST, handleRelay10);
  server.on("/Relay12", HTTP_POST, handleRelay11);
  server.on("/Relay13", HTTP_POST, handleRelay12);
  server.on("/Relay14", HTTP_POST, handleRelay13);
  server.on("/Relay15", HTTP_POST, handleRelay14);
  server.on("/Relay16", HTTP_POST, handleRelay15);
}

void handleRoot()
{
  Serial.println("GET /");
  server.send(200, "text/html", indexPage);
}

void handleRelay()
{
  // Parameter aus URI holen
  if (server.arg("RelayControl") == "")
  { // Parameter nicht gefunden
    Serial.write("\nParameter nicht gefunden\n");
  }
  else
  {
    RelayNo = server.arg("RelayControl").toInt();

    mcp.digitalWrite(RelayNo, !mcp.digitalRead(RelayNo));
  }

  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay0()
{
  mcp.digitalWrite(0, !mcp.digitalRead(0));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay1()
{
  mcp.digitalWrite(1, !mcp.digitalRead(1));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay2()
{
  mcp.digitalWrite(2, !mcp.digitalRead(2));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay3()
{
  mcp.digitalWrite(3, !mcp.digitalRead(3));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay4()
{
  mcp.digitalWrite(4, !mcp.digitalRead(4));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay5()
{
  mcp.digitalWrite(5, !mcp.digitalRead(5));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay6()
{
  mcp.digitalWrite(6, !mcp.digitalRead(6));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay7()
{
  mcp.digitalWrite(0, !mcp.digitalRead(7));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay8()
{
  mcp.digitalWrite(8, !mcp.digitalRead(8));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay9()
{
  mcp.digitalWrite(9, !mcp.digitalRead(9));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay10()
{
  mcp.digitalWrite(10, !mcp.digitalRead(10));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay11()
{
  mcp.digitalWrite(11, !mcp.digitalRead(11));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay12()
{
  mcp.digitalWrite(12, !mcp.digitalRead(12));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay13()
{
  mcp.digitalWrite(13, !mcp.digitalRead(13));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay14()
{
  mcp.digitalWrite(14, !mcp.digitalRead(14));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay15()
{
  mcp.digitalWrite(15, !mcp.digitalRead(15));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}