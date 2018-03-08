#include <Arduino.h>
#include "ESP8266WiFi.h"
#include "RestClient.h"

const char* ssid = "SSID";
const char* password = "PASSWORD";

const int request_delay = 5000;

RestClient client = RestClient("arduino-http-lib-test.herokuapp.com");

void setup(void){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

String response;
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Send Sensor Data");

  /*response = "";
  int statusCode = client.post("/data", "POSTDATA", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);*/

  response = "";

  client.setHeader("X-Test-Header1: one");
  client.setHeader("X-Test-Header2: two");

  int statusCode = client.get("/get", &response);

  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(request_delay);
}