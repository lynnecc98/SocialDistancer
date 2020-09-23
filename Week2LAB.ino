// Written by Chloe Lynne Choi

// define pins
#define REDPIN 12
#define GREENPIN 11
#define BLUEPIN 10

#define echoPin 2
#define trigPin 3

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

// define colors
int colors[8][3] = {{255,0,0},{0,255,0},{0,0,255},{255,255,125},{0,255,255},{255,0,255},{255,255,0},{255,255,255}};
int colorIndex = 0;

void setup() {
  // Sets up RGB pins
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  // Sets up Ultrasensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 200) {
    RGB_color(255, 0, 0); // Red
    delay(250);
    RGB_color(0, 0, 0); // Red
    delay(250);
  } else {
    RGB_color(colors[colorIndex][0],colors[colorIndex][1],colors[colorIndex][2]);
    delay(1000);
    colorIndex++;
    if (colorIndex > 8) {
      colorIndex = 0;
    }
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(REDPIN, red_light_value);
  analogWrite(GREENPIN, green_light_value);
  analogWrite(BLUEPIN, blue_light_value);
}
