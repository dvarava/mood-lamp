#include <Bridge.h>
#include <BlynkSimpleYun.h>

#define BLYNK_TEMPLATE_ID "TMPL4aE1xXZAy"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "seWmbsdAoAH_C13CrgbzW9DH-5Fd-9dO"

// Define the color values for each mood
const int happyColor[] = {255, 255, 0};
const int sadColor[] = {160, 160, 160};
const int sleepyColor[] = {255, 191, 0};
const int focusedColor[] = { 0, 255, 0 };
const int creativeColor[] = { 255, 255, 0 };
const int calmColor[] = { 0, 0, 255 };
const int energeticColor[] = { 255, 0, 0 };


// Define the brightness values for each mood
const int happyBrightness = 255;
const int sadBrightness = 50;
const int sleepyBrightness = 75;
const int focusedBrightness = 210;
const int creativeBrightness = 200;
const int calmBrightness = 100;
const int energeticBrightness = 240;

const int IR_RECEIVE_PIN = 11;
int ledPinR=9;
int ledPinG=13;
int ledPinB=10;

void setup()
{
  Serial.begin(9600);

  // Initialize the Bridge
  Bridge.begin();

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN);

  // Set the LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  Blynk.run();
}

void setLedColor(int redValue, int greenValue, int blueValue) {
  // Set the PWM values for the LED pins
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Print the RGB values to the serial port
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print(", Green: ");
  Serial.print(greenValue);
  Serial.print(", Blue: ");
  Serial.println(blueValue);
}

// Blynk function to handle color selection
BLYNK_WRITE(V0) {
  // Get the RGB values from the Blynk app
  int redValue = param[0].asInt();
  int greenValue = param[1].asInt();
  int blueValue = param[2].asInt();

  // Set the LED color
  setLedColor(redValue, greenValue, blueValue);
}
