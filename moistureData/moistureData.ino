// Take sensor data to generate guidelines for conditionals in complete program

void setup() {

  pinMode(A0, INPUT);  // Moisture Sensor 1
  pinMode(A1, INPUT);  // Moisture Sensor 2

  pinMode(9, OUTPUT); // Moisture Sensor 1 LED
  pinMode(10, OUTPUT); // Moisture Sensor 2 LED

  Serial.begin(9600); // Start Serial Monitor

}

void loop() {

  // Read and Map values

  int mst1 = map(analogRead(A0), 450, 650, 0, 255); // Map analog to digital <mst1>
  int mst2 = map(analogRead(A1), 450, 650, 0, 255); // Map analog to digital <mst2>

  // Write values to LEDs

  analogWrite(9, mst1); // Write to LED 1
  analogWrite(10, mst2); // Write to LED 2

  // Print values

  Serial.print("Sensor 1: ");
  Serial.println(mst1);

  Serial.print("Sensor 2: ");
  Serial.println(mst2);

  Serial.println();

  // Wait 100ms
  
  delay(100);
  
}
  
