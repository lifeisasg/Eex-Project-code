
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

void setup() {
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read Red Pulse Width
  redPW = getRedPW();
  // Read Green Pulse Width
  greenPW = getGreenPW();
  // Read Blue Pulse Width
  bluePW = getBluePW();

  // Print output to Serial Monitor
  Serial.print("Red PW = ");
  Serial.print(redPW);
  Serial.print(" - Green PW = ");
  Serial.print(greenPW);
  Serial.print(" - Blue PW = ");
  Serial.println(bluePW);

  // Determine output based on color ranges
  if (redPW > 65 && redPW < 80 && 
      greenPW > 90 && greenPW < 115 && 
      bluePW > 90 && bluePW < 115) {
    Serial.println("Output: 10");
  } 
  else if (redPW > 40 && redPW < 60 && 
           greenPW > 60 && greenPW < 82 && 
           bluePW > 60 && bluePW < 85) {
    Serial.println("Output: 200");
  }
  else if (redPW > 60 && redPW < 80 && 
           greenPW > 75 && greenPW < 100 && 
           bluePW > 80 && bluePW < 110) {
    Serial.println("Output: 20");
  }
  else if (redPW > 80 && redPW < 100 && 
         greenPW > 90 && greenPW < 120 && 
         bluePW > 20 && bluePW < 50) {
  Serial.println("Checking for Output: 100");
  Serial.print("redPW: ");
  Serial.println(redPW);
  Serial.print("greenPW: ");
  Serial.println(greenPW);
  Serial.print("bluePW: ");
  Serial.println(bluePW);
  Serial.println("Output: 100");
}
 
  

  // Delay before next reading
  delay(1000); // Adjust delay time as needed
}

// Function to read Red Pulse Widths
int getRedPW() {
  // Set sensor to read Red only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Read the output Pulse Width
  int PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Green Pulse Widths
int getGreenPW() {
  // Set sensor to read Green only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Read the output Pulse Width
  int PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Blue Pulse Widths
int getBluePW() {
  // Set sensor to read Blue only
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Read the output Pulse Width
  int PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}