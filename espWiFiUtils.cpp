//
// espWiFiUtils v1.0.0
// 2023.12.13
//

#include "espWiFiUtils.h"

void connectWiFi(const char* STASSID, const char* STAPSK, const char* WiFiHostname) {
  WiFi.mode(WIFI_STA);
  WiFi.hostname(WiFiHostname);
  WiFi.begin(STASSID, STAPSK);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - startTime) <= 10000) // Timeout WiFi connection attempt after 10 sec
  {
    delay(500);
    // Serial.println(".");
  }
  // Serial.println("WiFi Connected!");
}

void connectWiFi(const char* STASSID, const char* STAPSK, const char* WiFiHostname, int wifiLED) {
  // Bring LED pin LOW to turn on
  pinMode(wifiLED, OUTPUT);
  digitalWrite(wifiLED, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.hostname(WiFiHostname);
  WiFi.begin(STASSID, STAPSK);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - startTime) <= 10000) // Timeout WiFi connection attempt after 10 sec
  {
    delay(500);
    // Serial.println(".");
     digitalWrite(wifiLED, !digitalRead(wifiLED));
  }
   digitalWrite(wifiLED, HIGH);
}

void initializeOTA(const char* hostname, const char* password) {
  //Initialize Arduino OTA
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }
    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.setHostname(hostname);
  ArduinoOTA.setPassword(password);
  ArduinoOTA.begin();
}
