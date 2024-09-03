#include <WiFi.h>
#include <ESP_Mail_Client.h>

#define WIFI_SSID "VinitNotFound"
#define WIFI_PASSWORD "password"
#define SMTP_server "smtp.gmail.com"
#define SMTP_Port 587
#define sender_email "esp32airquality@gmail.com"
#define sender_password "grvq tifa dojg eiza"
#define Recipient_email "esp32airquality@gmail.com"
#define Recipient_name ""

SMTPSession smtp;

int sensorAQ = 32;
int hydrogen = 33;
int methane = 34;
int carbonmono = 35;

int airQualityValue;
float hydrogenValue;
float methaneValue;
float carbonMonoxideValue;

bool emailSent = false; // Flag to track if email has been sent

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  smtp.debug(1);
}

void loop() {

  collectSensorValues(); 
  if (!emailSent) { 
    checkSensorValues();
  }
  delay(1000);
}


void collectSensorValues() {
  int airQualityRaw = analogRead(sensorAQ);
  float hydrogenRaw = analogRead(hydrogen);
  float methaneRaw = analogRead(methane);
  float carbonMonoRaw = analogRead(carbonmono);

  airQualityValue = (map(airQualityRaw, 0, 1023, 0, 300))-100;
  hydrogenValue = map(hydrogenRaw, 0, 1023, 0, 8000);
  methaneValue = map(methaneRaw, 0, 1023, 0, 8000);
  carbonMonoxideValue = map(carbonMonoRaw, 0, 1023, 0, 2000);

  Serial.print("Air Quality Value: ");
  Serial.println(airQualityValue);
  
  Serial.print("Hydrogen (ppm): ");
  Serial.println(hydrogenValue);
  
  Serial.print("Methane (ppm): ");
  Serial.println(methaneValue);
  
  Serial.print("Carbon Monoxide (ppm): ");
  Serial.println(carbonMonoxideValue);

}

void checkSensorValues() {
  const float hydrogenThreshold = 5000;
  const float methaneThreshold = 5000;
  const float carbonMonoxideThreshold = 1000;
  const int airQualityThreshold = 100;

  if (hydrogenValue > hydrogenThreshold ||
      methaneValue > methaneThreshold ||
      carbonMonoxideValue > carbonMonoxideThreshold ||
      airQualityValue > airQualityThreshold) {
    sendEmail();
  }
}

void sendEmail() {
  ESP_Mail_Session session;
  session.server.host_name = SMTP_server ;
  session.server.port = SMTP_Port;
  session.login.email = sender_email;
  session.login.password = sender_password;
  session.login.user_domain = "";

  SMTP_Message message;
  message.sender.name = "Air Quality Monitoring System";
  message.sender.email = sender_email;
  message.subject = "Your Air Quality is Deteriorated";
   message.addRecipient(Recipient_name, Recipient_email);

  String textMsg = "Hello Vinit! This is to inform you that your environment's air quality has been deteriorated\n\n";
  textMsg += "Hydrogen: " + String(hydrogenValue) + " ppm\n";
  textMsg += "Methane: " + String(methaneValue) + " ppm\n";
  textMsg += "Carbon Monoxide: " + String(carbonMonoxideValue) + " ppm\n";
  textMsg += "Air Quality Value: " + String(airQualityValue) + " ppm";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  if (!smtp.connect(&session))
    return;

  if (!MailClient.sendMail(&smtp, &message)) {
    Serial.println("Error sending Email, " + smtp.errorReason());
  } else {
    emailSent = true; 
  }
}
