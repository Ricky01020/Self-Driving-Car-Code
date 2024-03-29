void BT() 
{
if(mySerial.available())  
{
  Movement =mySerial.read();
  Serial.println(Movement);
  Serial.print("\n");       
}
 
if(Movement == 'F')
  {            
    digitalWrite (frontright,LOW);
    digitalWrite(backright,HIGH);                       
    digitalWrite (frontleft,LOW);
    digitalWrite(backleft,HIGH);
    
   analogWrite(Sen1,0);
   analogWrite(Sen2,0);    
   analogWrite(MotorA, velocity);
   analogWrite(MotorB, velocity);       
  }
  
  else if(Movement == 'S')
  {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);   
  }

  else if(Movement == 'L')
  {      
    digitalWrite (frontright,LOW);
    digitalWrite(backright,HIGH);                       
    digitalWrite (frontleft,HIGH);
    digitalWrite(backleft,LOW);
    
    analogWrite(Sen1,0);
    analogWrite(Sen2,0);    
   analogWrite(MotorA, turn_velocity);
   analogWrite(MotorB, velocity);     
  }
   
  else if(Movement == 'R')
  {      
    digitalWrite (frontright,HIGH);
    digitalWrite(backright,LOW);                       
    digitalWrite (frontleft,LOW);
    digitalWrite(backleft,HIGH);
    
    analogWrite(Sen1,0);
    analogWrite(Sen2,0);    
    analogWrite(MotorA, velocity);
    analogWrite(MotorB, turn_velocity); 
  }
  else if(Movement == 'B')
  {
    digitalWrite (frontright,HIGH);
    digitalWrite(backright, LOW);                       
    digitalWrite (frontleft,HIGH);
    digitalWrite(backleft,LOW);
    
    analogWrite(Sen1,0);
    analogWrite(Sen2,0);
    analogWrite(MotorA, velocity);
    analogWrite(MotorB, turn_velocity); 
  }
  else if(Movement == 'W') // Turn on line
  {
    analogWrite(Sen1,HIGH);
    analogWrite(Sen2,HIGH);
  }
delay(5);
}
