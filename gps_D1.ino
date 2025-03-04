#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define RX_PIN 0 // D7 (ESP8266 RX)
#define TX_PIN 1 // D6 (ESP8266 TX)

SoftwareSerial gpsSerial(RX_PIN, TX_PIN); 
TinyGPSPlus gps;

void setup() {
    Serial.begin(115200);
    gpsSerial.begin(9600);
    Serial.println("Čekám na GPS data...");

}

void loop() {
    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read()); 

        if (gps.location.isUpdated()) {
            Serial.print("Latitude: ");
            Serial.println(gps.location.lat(), 6);
            Serial.print("Longitude: ");
            Serial.println(gps.location.lng(), 6);
            Serial.print("Altitude: ");
            Serial.println(gps.altitude.meters());
        }
    }
}
//musím přepájet