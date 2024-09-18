const int motor1RelayPin = 8; // Relay for motor 1 (inside brush)
const int motor2RelayPin = 9; // Relay for motor 2 (outer brush 1)
const int motor3RelayPin = 10; // Relay for motor 3 (outer brush 2)
const int conveyorRelayPin = 11; // Relay for conveyor belt

void setup() { 
  pinMode(motor1RelayPin, OUTPUT); 
  pinMode(motor2RelayPin, OUTPUT); 
  pinMode(motor3RelayPin, OUTPUT); 
  pinMode(conveyorRelayPin, OUTPUT); 

  // Initially all motors and conveyor are OFF
  digitalWrite(motor1RelayPin, HIGH); 
  digitalWrite(motor2RelayPin, HIGH); 
  digitalWrite(motor3RelayPin, HIGH); 
  digitalWrite(conveyorRelayPin, HIGH); 
}

void loop() { 
  // Some delay before starting
  delay(3000); 

  // Turning ON washing motors
  digitalWrite(motor1RelayPin, LOW); 
  digitalWrite(motor2RelayPin, LOW); 
  digitalWrite(motor3RelayPin, LOW); 

  // Washing jars for 30 seconds
  delay(30000); 

  // Turning OFF washing motors
  digitalWrite(motor1RelayPin, HIGH); 
  digitalWrite(motor2RelayPin, HIGH); 
  digitalWrite(motor3RelayPin, HIGH); 

  // Starting the conveyor belt to move jars for 3 seconds
  digitalWrite(conveyorRelayPin, LOW); 

  // Moving conveyor for 3 seconds
  delay(3000); 

  // Turning OFF the conveyor belt
  digitalWrite(conveyorRelayPin, HIGH); 
}
