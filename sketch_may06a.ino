#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiManager.h> 
WiFiManager wifiManager;
void setup() {
  Serial.begin(115200);
  delay(200);
  if ( WiFi.status() != WL_CONNECTED ) {
      wifiManager.resetSettings();
      wifiManager.autoConnect("ESP32-1");
      Serial.println("connected :)");
  }
}
void loop() {

 if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
    String Data="00000000";
    HTTPClient http;
    String url="https://api-test.technofield.net/api/data?token=TEST_TOKEN_123";
    url +="&data=";
     url +=Data;
    http.begin(url); //Specify the URL 
    int httpCode = http.GET();                                                  //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.print(httpCode);
        Serial.print(payload);
        Serial.print("\n");
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
}
