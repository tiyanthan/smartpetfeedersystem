#include <ESP8266WiFi.h>
#include <espnow.h>
#include <ArduinoJson.h>
#include <Arduino.h>
#include <Servo.h>
int val;
Servo servo;
const char* ssid = "TRK";
const char* password = "115599Traj";

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    String body;
} struct_message;

// Create a struct_message called myData
struct_message myData;
bool started=false;
// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
   char* buff = (char*) incomingData;
  String body = String(buff);
  Serial.println(body);
  
    if(body=="dog")
    {
      for(val = 0; val <= 180; val++){
      servo.write(180); // sets the servo position according to the scaled value
      Serial.print("Angle:");
      Serial.println(val);
      delay(1000); // waits for the servo to get there
      }
      delay(15000);
      for(val = 180; val >= 0; val--){
      servo.write(0); // sets the servo position according to the scaled value
      Serial.print("Angle:");
      Serial.println(val);
      delay(1000); // waits for the servo to get there
      }
    }else if(body=="cat")
    {
      for(val = 0; val <= 180; val++){
      servo.write(180); // sets the servo position according to the scaled value
      Serial.print("Angle:");
      Serial.println(val);
      delay(1000); // waits for the servo to get there
      }
      delay(10000);
      for(val = 180; val >= 0; val--){
      servo.write(0); // sets the servo position according to the scaled value
      Serial.print("Angle:");
      Serial.println(val);
      delay(1000); // waits for the servo to get there
      }
    }else if(body=="bird")
    {
      for(val = 0; val <= 180; val++){
      servo.write(180); // sets the servo position according to the scaled value
      Serial.print("Angle:");
      Serial.println(val);
      delay(1000); // waits for the servo to get there
      }
      delay(5000);
      for(val = 180; val >= 0; val--){
      servo.write(0); // sets the servo position according to the scaled value
      Serial.print("Angle:");
      Serial.println(val);
      delay(1000); // waits for the servo to get there
      }
    }
  
}
 
void setup() {

  Serial.begin(115200);

  servo.attach(2); //D4

  servo.write(0);

  // Set the device as a Station and Soft Access Point simultaneously
  WiFi.mode(WIFI_AP_STA);
  
  // Set device as a Wi-Fi Station
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Setting as a Wi-Fi Station..");
  }
  Serial.print("Station IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Wi-Fi Channel: ");
  Serial.println(WiFi.channel());

  // Init ESP-NOW
  if (esp_now_init() != ERR_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);


}

void loop() {

}
