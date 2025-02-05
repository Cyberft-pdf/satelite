#define VIB_SENSOR D2  //GPIO4

int vibThreshold = 800;  
int vibCount = 0;

void setup() {
    pinMode(VIB_SENSOR, INPUT);
    Serial.begin(115200);
    Serial.println("Senzor připraven - detekuje silné rány...");
}

void loop() {
    if (digitalRead(VIB_SENSOR) == HIGH) {
        vibCount++;  

        if (vibCount >= vibThreshold) {
            Serial.println(" Silné bouchnutí detekováno!");
            vibCount = 0;  
        }
    } else {
        vibCount = 0;  
    }
    delay(20); 
}
