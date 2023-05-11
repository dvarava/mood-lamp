#include <Bridge.h>
#include <BlynkSimpleYun.h>
#include <WiFiNINA.h>

#define BLYNK_TEMPLATE_ID "TMPL4aE1xXZAy"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "seWmbsdAoAH_C13CrgbzW9DH-5Fd-9dO"

const char* ssid = "ssd";
const char* password = "pass";
const IPAddress bulbIP(192, 168, 1, 100);

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
  
  Serial.print("Connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connectd");
}

  Bridge.begin();

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN);
}

void loop(){
  Blynk.run();
  // Get the selected mood from user input (e.g. Blynk app)
  int mood = getSelectedMood();
  
  // Set the color and brightness based on the selected mood
  int* color = NULL;
  int brightness = 0;
  
  switch (mood) {
    case 1:
      color = happyColor;
      brightness = happyBrightness;
      break;
    case 2:
      color = sadColor;
      brightness = sadBrightness;
      break;
    case 3:
      color = sleepyColor;
      brightness = sleepyBrightness;
      break;
    case 4:
      color = focusedColor;
      brightness = focusedBrightness;
      break;
    case 5:
      color = creativeColor;
      brightness = creativeBrightness;
      break;
    case 6:
      color = calmColor;
      brightness = calmBrightness;
      break;
    case 7:
      color = energeticColor;
      brightness = energeticBrightness;
      break;
    default:
      // Invalid mood selected
      break;
  }
  
  // Set the RGB values and brightness of the bulb
  setBulbColor(color);
  setBulbBrightness(brightness);
  
  // Wait for a few seconds before updating the mood again
  delay(5000);
}

int getSelectedMood() {
  //code to select a mood
}

void setBulbColor(int* color) {
  String command = "setrgb " + String(color[0]) + " " + String(color[1]) + " " + String(color[2]) + "\r\n";
  WiFiClient client;
  if (client.connect(bulbIP, 5577)) {
    client.print(command);
  }
