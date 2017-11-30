#include <ESP8266WiFi.h>

const char *ssid = "domek15";
const char *password = "qaedtg13579001";
const char *host = "www.example.com";

void setup() {
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(ssid, password);
  Serial.print("Łączenie");

  while (WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Połączono, adres IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client;
  Serial.printf("\nŁączenie z serwerem %s", host);
  
  if (client.connect(host,80))
    Serial.printf("\nPołączono");
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
  client.stop();
  Serial.println("\nRozłączono");
  
}
