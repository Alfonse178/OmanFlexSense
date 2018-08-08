
//made by Alfie Sargent & Chidera Unigwe

const int FLEX_PIN = A0; // Pin connected to voltage divider output
const int LED5 = 3; //pin connected to LED5
const int LED4 = 4; //pin connected to LED4
const int LED3 = 5; //pin connected to LED3
const int LED2 = 6; //pin connected to LED6
const int LED1 = 7; //pin connected to LED7

float r=0;
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 0; // resistance when straight
const float BEND_RESISTANCE = 350000.0; // resistance at 90 deg

void setup()
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);//flex pin
  pinMode (LED5, OUTPUT);//LED5
  pinMode (LED4, OUTPUT);//LED4
  pinMode (LED3, OUTPUT);//LED3
  pinMode (LED2, OUTPUT);//LED2
  pinMode (LED1, OUTPUT);//LED1
}

void loop()
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC / 1023.0;
  float flexRi = (R_DIV * (VCC / flexV - 1.0));
  float flexR = flexRi-r;
  //if statement for checking the resistance of the flex sensor and then
  //making certian LED's high
  if (r ==0){
 r=flexRi;
  }
    float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                    0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  
  if (angle >=0 && angle <= 18) {
    digitalWrite (LED1, HIGH);
  }
  else if (angle > 18 && angle <= 36 ) {
    digitalWrite (LED1, HIGH);
    digitalWrite (LED2, HIGH);
  }
  else if (angle > 36 && angle <= 54) {
    digitalWrite (LED1, HIGH);
    digitalWrite (LED2, HIGH);
    digitalWrite (LED3, HIGH);
  }
  else if (angle > 54 && angle <= 72) {
    digitalWrite (LED1, HIGH);
    digitalWrite (LED2, HIGH);
    digitalWrite (LED3, HIGH);
    digitalWrite (LED4, HIGH);
  }
  else if (angle > 72 && angle <= 90) {
    digitalWrite (LED1, HIGH);
    digitalWrite (LED2, HIGH);
    digitalWrite (LED3, HIGH);
    digitalWrite (LED4, HIGH);
    digitalWrite (LED5, HIGH);
  }
  //resetting all the values of the LED's to low
  
  delay (100);
  digitalWrite (LED1, LOW);
  digitalWrite (LED2, LOW);
  digitalWrite (LED3, LOW);
  digitalWrite (LED4, LOW);
  digitalWrite (LED5, LOW);
  

  //printing the resistance of the sensor
  Serial.println("Resistance: " + String(flexR) + " ohms");

  //determining the angle that the flex sensor is at, just a bit of extra info that might not be needed.

  delay(100);
}

