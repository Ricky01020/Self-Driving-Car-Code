void LineTracker() 
{
  leftsensor=analogRead(A0);                   // Value for A0
  rightsensor=analogRead(A1);                  // Value for A1
  Serial.print(leftsensor);
  Serial.print("  ");
  Serial.print(rightsensor);
  if(rightsensor > 500 && leftsensor < 500)    // Move Right
{
  Serial.println("Right");
  digitalWrite (frontright,HIGH);
  digitalWrite(backright,LOW);                       
  digitalWrite (frontleft,LOW);
  digitalWrite(backleft,HIGH);
  delay(turn_delay);
  //STOP
  digitalWrite (frontright,LOW);
  digitalWrite(backright,LOW);                       
  digitalWrite (frontleft,LOW);
  digitalWrite(backleft,LOW);

  analogWrite(MotorA, velocity);            // Max velocity
  analogWrite(MotorB, turn_speed);          // Max Turn Speed

  }
if(rightsensor < 500 && leftsensor > 500)     // Move Left
{
  Serial.println("Left");
  
    digitalWrite (frontright,LOW);
    digitalWrite(backright,HIGH);                       
    digitalWrite (frontleft,HIGH);
    digitalWrite(backleft,LOW);
  delay(turn_delay);
  //STOP
  digitalWrite (frontright,LOW);
  digitalWrite(backright,LOW);                       
  digitalWrite (frontleft,LOW);
  digitalWrite(backleft,LOW);


  analogWrite(MotorA, turn_speed);      // Max Turn Speed
  analogWrite(MotorB, velocity);        // Max Velocity
}
if (rightsensor <500 && leftsensor <500)    //Move Forward
{
  Serial.println("Forward");
  digitalWrite (frontright, LOW);
  digitalWrite(backright,HIGH);                       
  digitalWrite (frontleft,LOW);
  digitalWrite(backleft,HIGH);  
  delay(turn_delay);
   
  analogWrite(MotorA, velocity);      // Max velocity
  analogWrite(MotorB, velocity);      // Max velocity
 }

}
