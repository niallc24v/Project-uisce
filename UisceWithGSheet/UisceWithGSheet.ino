/*
Derived from Yún HTTP Client Sketch

 This example for the Arduino Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 Additions added by Mary Loftus April 2018 
 - adapted from example by Tom DeBell - August 2017 - http://www.open-sensing.org/evaporometerblog/datalog
 */


  /////////////////
 // MODIFY HERE //
/////////////////

// Add your PushingBox Scenario DeviceID here:
  char devid[] = "vF502B137D637D7C";
  
  //////////////
 //   End    //
//////////////

char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  Serial.begin(9600);
  while (!Serial); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  //Testing value - when sensor is not connected - comment out when sketch is shown to be working - and take value from A0 instead
  //sensorValue=1500;
    const int analogueInPin = A2;
    int sensorValue = analogRead(A2);    
    int outputValue = map(sensorValue, 0, 1023, 0, 255);
    Serial.print("sensor = ");
    Serial.print(sensorValue);
    delay(1000);

        
    if(sensorValue>0 && sensorValue<500)
    {
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
    }
    else if(sensorValue>=500&& sensorValue<750)
    {
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
    }
    else if(sensorValue > 750)
    {
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
    }

  double volPercent = (sensorValue/1024)*100;

  // Make a HTTP request:  
  String APIRequest;
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag=100&TimeStamp=50&VolumePercent="+volPercent;
  client.get (APIRequest);
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();

  }
  Serial.flush();
  String UploadMessage;
  Serial.print("\n Uploaded volume percent: ");
  Serial.print(volPercent);
  delay(5000);//for demo, short delay. Real world would have 20min delay (20min*60*1000 = 180000ms delay)
}


