#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include <ESPAsyncTCP.h>
#include <FS.h>
#include <Adafruit_Sensor.h>
#include "MQ7.h"
#include <TinyGPS++.h>                                  
#include <SoftwareSerial.h>  
#include "DHTesp.h"
float vi;
float vh;
float vele;
float vvt;






DHTesp dht; 

MQ7 mq7(A0,3.3);



// Replace with your network credentials
const char* ssid = 
const char* password = 
static const int RXPin = 3, TXPin = 1; 
static const uint32_t GPSBaud = 9600;  
TinyGPSPlus gps;                                    
SoftwareSerial ss(RXPin, TXPin); 
                       
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

int ledpin = 2;
String ledState;



//******************************************************
//                    SERVICE_LOAD_SEND
//******************************************************
String readgas() 
{float t = mq7.getPPM();if (isnan(t)) {return "--";}
else {return String(t);}}
String readalt() 
{return String(gps.location.lat(),3);}
String readlng() 
{return String(gps.location.lng(),3);}
String readheure() 
{return String(gps.time.hour());}
String readminute() 
{return String(gps.time.minute());}
String readseconde() 
{return String(gps.time.second());}
String readnbsat()
{return String(gps.satellites.value());}
String readtemperature()
{return String(vi);}
String readhumidity()
{return String(vh);}
String readele()
{return String(vele);}
String readroute()
{return String(gps.course.deg());}
String readvitesse()
{return String(vvt);}

String processor(const String& var){
  Serial.println(var);
  if(var == "STATE"){
    if(digitalRead(ledpin)){
      ledState = "ON";
    }
    else{
      ledState = "OFF";
    }
    Serial.print(ledState);
    return ledState;
  }
}
void setup(){

  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH); 
  delay(500); 
  digitalWrite(4,LOW); 
  //***********************************************************************
  //                     SPIFFS, Wifi & Server CONFIGURATION
  //***********************************************************************
  Serial.println ( "" ); 
  Serial.print ( "Démarrage de l'ESP8266" );
  delay(1000);
  if(!SPIFFS.begin()){return;}
  Serial.println ( "" ); 
  Serial.println ( "" );
  Serial.print ( "Le chargement SPIFFS est terminé" );
  Serial.println ( "" ); 
  Serial.println ( "" ); 
  Serial.print ( "Décompte avant la configuration de l'interface Wifi : " );
  Serial.print( "3" );delay(1000);Serial.print( ",2" );delay(1000);Serial.print( ",1" );delay(1000);  
  WiFi.mode(WIFI_STA);
  Serial.println ( "" );
  Serial.println ( "" ); 
  WiFi.begin(ssid,password);while (WiFi.status() != WL_CONNECTED) 
  {delay(650);Serial.print(".");}
  Serial.println ( "" ); 
  Serial.println ( "" ); delay(1000);
  Serial.print( "connecte au reseau " );
  digitalWrite(4,HIGH);delay(250);digitalWrite(4,LOW);delay(250);
  digitalWrite(4,HIGH);delay(250);digitalWrite(4,LOW);delay(250);
  digitalWrite(4,HIGH);delay(250);digitalWrite(4,LOW);delay(250);
  Serial.println ( "" ); 
  Serial.print ( "Démarrage du serveur dans 3 " );delay(1000); Serial.print ( ",2 " );delay(1000); Serial.print ( ",1" );delay(1000);  
  Serial.println ( "" ); 
  server.begin(); 
  Serial.println ("Serveur Operationnel");
  delay(500);
  digitalWrite(4,HIGH);delay(250);digitalWrite(4,LOW);delay(250);
  digitalWrite(4,HIGH);delay(250);digitalWrite(4,LOW);delay(250);
  digitalWrite(4,HIGH);delay(250);digitalWrite(4,LOW);delay(250);
  ss.begin(GPSBaud);  
  String thisBoard= ARDUINO_BOARD;
  dht.setup(5, DHTesp::DHT11);  
  digitalWrite(4,HIGH); 
  delay(500); 
  digitalWrite(4,LOW); 
  
  //***********************************************************************
  //                          PAGE CONFIGURATION
  //***********************************************************************
  // Route for root / web page-------------------------------------------
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/final.html", "text/html");});
  // Javascript----------------------------------------------------------
  server.on("/final5.js", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/final5.js", "text/js");});
  // Javascript----------------------------------------------------------
  server.on("/bouton.js", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/bouton.js", "text/js");});
  // CSS_Files-----------------------------------------------------------
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/style.css", "text/css");});
  // Images_Files-----------------------------------------------------------
  server.on("/iut.png", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/iut.png", "image/png");});
  // **********************************************************************
  //                          SERVICE PAGE SENSORS
  // **********************************************************************
  server.on("/liregas", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readgas().c_str());
  });
   server.on("/lirealt", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readalt().c_str());
  });
    server.on("/lirelng", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readlng().c_str());
  });
    server.on("/liretime", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readheure().c_str());
  });
  server.on("/lireminute", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readminute().c_str());
  });
   server.on("/lireseconde", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readseconde().c_str());
  });
   server.on("/lirenbsat", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readnbsat().c_str());
  });
    server.on("/liretemperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readtemperature().c_str());
  });
    server.on("/lirehumidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readhumidity().c_str());
  });
     server.on("/lireele", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readele().c_str());
  });
     server.on("/lireroute", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readroute().c_str());
  });
     server.on("/lirevitesse", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readvitesse().c_str());
  });//******************************************************************************************7
    server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledpin, HIGH);    
    request->send(SPIFFS, "/final.html", String(), false, processor);
  });
  
  // Route to set GPIO to LOW
  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledpin, LOW);    
    request->send(SPIFFS, "/final.html", String(), false, processor);
  });

    
}
 
void loop(){
  WiFiClient client;
   smartDelay(500); 
   delay(dht.getMinimumSamplingPeriod());  
  float h = dht.getHumidity();
  float i = dht.getTemperature();
  vi = i; 
  vh = h;
  float ve = gps.altitude.meters();
  vele = ve;
  float vt = gps.speed.kmph(); 
  vt = vvt;
}

static void smartDelay(unsigned long ms)                // Version custum de delay() qui permet d'assurer que l'objet "gps" a bien reçu des données (les plus récentes).
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}
