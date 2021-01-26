// Relay #1 - [Relay1] Digital Pin 2 (9v)
// Relay #2 - [Relay2] Digital Pin 3 (12v)
// Relay #3 - [Relay3] Digital Pin 4 (12v)

// Soil Sensor #1 - [E1] Analog Pin A1/15 (INPUT)
//    Correlating LED - [LED5] Digital Pin 10 (5v)
// Soil Sensor #2 - [E2] Analog Pin A0/14 (INPUT)
//    Correlating LED - [LED6] Digital Pin 9 (5v)

// Water Level Sensor - [E7] Digital Pin 12 (INPUT)
// Water Level LED - [E6] Digital Pin 11 (5v)

int pump    = 2;
int valve1  = 3;
int valve2  = 4;

int soilsensor1 = 15;
int soilsensor2 = 14;
int soilLED1 = 10;
int soilLED2 = 9;

int waterlevelsensor = 12;
int waterlevelled = 11;

void setup() {

    // Set pins to their respective modes
    pinMode(pump, OUTPUT);
    pinMode(valve1, OUTPUT);
    pinMode(valve2, OUTPUT);

    pinMode(soilsensor1, INPUT);
    pinMode(soilsensor1, INPUT);
    pinMode(soilLED1, OUTPUT);
    pinMode(soilLED2, OUTPUT);

    pinMode(waterlevelsensor, INPUT);
    pinMode(waterlevelled, OUTPUT);

    Serial.begin(9600);
}

void loop() {

    int soildata1 = analogRead(soilsensor1);
    int soildata2 = analogRead(soilsensor2);

    int mapped_soildata1 = map(soildata1, 400, 650, 0, 255);
    int mapped_soildata2 = map(soildata2, 400, 650, 0, 255);

    // LED Indicators
    analogWrite(soilLED1, mapped_soildata1);
    analogWrite(soilLED2, mapped_soildata2);

    // Check water storage 
    if(digitalRead(waterlevelsensor) != 1) {
        while(digitalRead(waterlevelsensor) != 1){
          digitalWrite(waterlevelled, HIGH);
          delay(60000);
        }
        digitalWrite(waterlevelled, LOW);
    } else {

        // Section 1
        if (soildata1 >= 350 ) {

            // Water
            digitalWrite(valve1, HIGH);     // Open the valve
            digitalWrite(pump, HIGH);       // Start the pump
            delay(5000);                    // Water for 5 sec
            digitalWrite(pump, LOW);        // Start the pump
            digitalWrite(valve2, LOW);      // Start the pump
        }

        // Section 2
        if (soildata2 >= 350 ) {

            // Water
            digitalWrite(valve2, HIGH);     // Open the valve
            digitalWrite(pump, HIGH);       // Start the pump
            delay(5000);                    // Water for 5 sec
            digitalWrite(pump, LOW);        // Start the pump
            digitalWrite(valve2, LOW);      // Start the pump
        }
    }
    
    // Repeat this loop every hour
   delay(3600 * 1000);

}