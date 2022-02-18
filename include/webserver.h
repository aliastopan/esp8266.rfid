#ifndef WEBSERVER
#define WEBSERVER

// #include <ESP8266WiFi.h>
// #include <ESPAsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <DNSServer.h>
// #include <HTTPClient.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "Wifi@Home";
const char* password = "02062000";
// const int port = 80;
// AsyncWebServer server(port);
// DNSServer dns;

const char* serverName = "http://raslous-001-site1.itempurl.com/identity";

class WebServer
{
    public:
    static void Setup()
    {
        WiFi.begin(ssid, password);
  	    while (WiFi.status() != WL_CONNECTED)
	    {
    	    delay(1000);
    	    Serial.println("Connecting to WiFi...");
  	    }

  	    Serial.println(WiFi.localIP());
    }

    static void Start()
    {

    }

    static String httpGETRequest(const char* serverName)
    {
        WiFiClient client;
        HTTPClient http;
        // Your IP address with path or Domain name with URL path
        http.begin(client, serverName);

        // Send HTTP POST request
        int httpResponseCode = http.GET();

        String payload = "{}";

        if(httpResponseCode > 0)
        {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            payload = http.getString();
        }
        else
        {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
        }

        // Free resources
        http.end();

        return payload;
    }
};




#endif