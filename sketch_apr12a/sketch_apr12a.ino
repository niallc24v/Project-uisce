void setup() {
  // put your setup code here, to run once:
  //pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  //digitalWrite(13, LOW);
  //digitalWrite(13, HIGH);

  // Listen for incoming connection only from localhost
  // (no one from the external network could connect)
  //server.listenOnLocalhost();
  //server.begin();
   Serial.begin(9600); 
}

void loop() {
      //our added code from here
    const int analogueInPin = A2;
    
    int sensorValue = analogRead(A2);
    //int outputValue;
    int outputValue = map(sensorValue, 0, 1023, 0, 255);
    //analogWrite(analogOutPin, outputValue);
    Serial.print("sensor = ");
    Serial.print(sensorValue);
    delay(1000);

    //sensorValue=800;
    
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
}
