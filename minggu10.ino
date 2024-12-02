// Include necessary libraries
#include <AntaresESPMQTT.h> // Include the ESP32 HTTP library
//#include <Adafruit_SSD1306.h> // Include the OLED library
// Replace these with your own credentials
#define ACCESSKEY "5c62fe001d9e77a8:56d4923a3198a428" // Replace with your Antares account access key
#define WIFISSID "mabar" // Replace with your Wi-Fi SSID
#define PASSWORD "12345678" // Replace with your Wi-Fi password
#define projectName "TesESP32Aktuator_Akhfi" // Replace with the Antares application name that was created
#define deviceName "Lampu_4212201031" // Replace with the Antares device name that was created
//#define relayPin 25
#define ledPin1 12
#define ledPin2 25
#define ledPin3 2
#define ledPin4 15

const unsigned long interval = 10000; // 10 s interval to send message
unsigned long previousMillis = 0; // will store last time message sent
AntaresESPMQTT antares(ACCESSKEY);
void callback(char topic[], byte payload[], unsigned int length) {
 antares.get(topic, payload, length);
 Serial.println("New Message!");
 Serial.println("Topic: " + antares.getTopic());
 Serial.println("Payload: " + antares.getPayload());
 //String relayValue = antares.getString("Relay"); // Change data field to "Relay"
 String ledValue1 = antares.getString("LED1");
 String ledValue2 = antares.getString("LED2");
 String ledValue3 = antares.getString("LED3");
 String ledValue4 = antares.getString("LED4"); // Add reading for "LED" data field
 // Control relay based on received data
 //if (relayValue == "1") {
 //digitalWrite(relayPin, HIGH);
 //}
 //else if (relayValue == "0") {
 //digitalWrite(relayPin, LOW);
 //}
 // Control LED based on received data
 if (ledValue1 == "1") {
 digitalWrite(ledPin1, HIGH);
 }
 else if (ledValue1 == "0") {
 digitalWrite(ledPin1, LOW);
 }


 if (ledValue2 == "1") {
 digitalWrite(ledPin2, HIGH);
 }
 else if (ledValue2 == "0") {
 digitalWrite(ledPin2, LOW);
 }
 
 
 if (ledValue3 == "1") {
 digitalWrite(ledPin3, HIGH);
 }
 else if (ledValue3 == "0") {
 digitalWrite(ledPin3, LOW);
 }
 
 
 if (ledValue4 == "1") {
 digitalWrite(ledPin4, HIGH);
 }
 else if (ledValue4 == "0") {
 digitalWrite(ledPin4, LOW);
 }
 
 Serial.println(" | LED1: " + ledValue1);
 Serial.println(" | LED2: " + ledValue2);
 Serial.println(" | LED3: " + ledValue3);
 Serial.println(" | LED4: " + ledValue4);

}
void setup() {
 Serial.begin(115200); // Initialize serial communication
 antares.setDebug(true); // Enable debugging for Antares
 antares.wifiConnection(WIFISSID, PASSWORD); // Connect to WiFi
 antares.setMqttServer();
 antares.setCallback(callback);
 //pinMode(relayPin, OUTPUT); // Set relayPin as an output
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT);
 pinMode(ledPin4, OUTPUT); // Set ledPin as an output
}
void loop() {
/*
 Check if we're still connected to the MQTT broker/server.
 If disconnected, the device will try to reconnect.
 */
 antares.checkMqttConnection();
}
