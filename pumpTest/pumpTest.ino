// Ensure The pump works for long lengths of tubing

// Relay #1 - Digital Pin 2 (9v)
int PUMP = 2;
// Relay #2 - Digital Pin 3 (12v)
// Relay #3 - Digital Pin 4 (12v)

void setup() {

  pinMode(PUMP, OUTPUT);

  Serial.begin(9600); // Start Serial Monitor

}

void loop() {
  
    // Turn on PUMP for 5sec
    digitalWrite(PUMP, HIGH);
    delay(5000);

    // Turn off PUMP for 10sec
    digitalWrite(PUMP, LOW);
    delay(10000);

}
  
