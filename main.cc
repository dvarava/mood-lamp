#include <IRremote.hpp>

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
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  pinMode(ledPinR,OUTPUT);
  pinMode(ledPinG,OUTPUT);
  pinMode(ledPinB,OUTPUT);
}

void loop(){
  if (IrReceiver.decode()) 
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);

    switch(IrReceiver.decodedIRData.decodedRawData)
    {
      case 0xEF10BF00:
        Serial.println("1(Happy)");
      	setColorBrightness(happyColor, happyBrightness);
        break;
      case 0xEE11BF00:
      	Serial.println("2(Sad)");
 		setColorBrightness(sadColor, sadBrightness);
        break;
      case 0xED12BF00:
      	Serial.println("3(Sleepy)");
 		setColorBrightness(sleepyColor, sleepyBrightness);
        break;
      case 0xEB14BF00:
      	Serial.println("4(Focused)");
 		setColorBrightness(focusedColor, focusedBrightness);
        break;
      case 0xEA15BF00:
      	Serial.println("5(Creative)");
 		setColorBrightness(creativeColor, creativeBrightness);
        break;
      case 0xE916BF00:
      	Serial.println("6(Calm)");
 		setColorBrightness(calmColor, calmBrightness);
        break;
      case 0xE718BF00:
      	Serial.println("7(Energetic)");
 		setColorBrightness(energeticColor, energeticBrightness);
        break;
      default:
        break;
    }

    IrReceiver.resume(); // Enable receiving of the next value
  }
}

void setColorBrightness(const int color[], const int brightness) {
  // Set the LED color and brightness
  analogWrite(ledPinR, color[0] * brightness / 255);
  analogWrite(ledPinG, color[1] * brightness / 255);
  analogWrite(ledPinB, color[2] * brightness / 255);
}
