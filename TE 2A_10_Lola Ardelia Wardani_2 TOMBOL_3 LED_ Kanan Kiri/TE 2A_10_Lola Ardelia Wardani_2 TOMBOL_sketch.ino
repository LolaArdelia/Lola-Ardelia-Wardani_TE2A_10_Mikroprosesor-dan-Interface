const int rightButtonPin = 10;  
const int leftButtonPin = 9;    
const int greenLedPin = 13;     
const int blueLedPin = 12;      
const int redLedPin = 11;       

int lastRightButtonState = LOW;  
int lastLeftButtonState = LOW;   

void setup() {
  pinMode(rightButtonPin, INPUT);    
  pinMode(leftButtonPin, INPUT);     
  pinMode(greenLedPin, OUTPUT);      
  pinMode(blueLedPin, OUTPUT);       
  pinMode(redLedPin, OUTPUT);        
}

void loop() {
  int rightButtonState = digitalRead(rightButtonPin); 
  int leftButtonState = digitalRead(leftButtonPin);    
  
  if (rightButtonState == HIGH && lastRightButtonState == LOW) {
    delay(50);  
    if (digitalRead(rightButtonPin) == HIGH) {
      shiftRight();  
    }
  }
  
  if (leftButtonState == HIGH && lastLeftButtonState == LOW) {
    delay(50);  
    if (digitalRead(leftButtonPin) == HIGH) {
      shiftLeft();  
    }
  }
  
  lastRightButtonState = rightButtonState;
  lastLeftButtonState = leftButtonState;
}


void shiftRight() {
  digitalWrite(greenLedPin, HIGH);  
  delay(300);  
  digitalWrite(greenLedPin, LOW);   
  digitalWrite(blueLedPin, HIGH);   
  delay(300);  
  digitalWrite(blueLedPin, LOW);    
  digitalWrite(redLedPin, HIGH);    
  delay(300);  
  digitalWrite(redLedPin, LOW);     
}


void shiftLeft() {
  digitalWrite(redLedPin, HIGH);    
  delay(300);  
  digitalWrite(redLedPin, LOW);     
  digitalWrite(blueLedPin, HIGH);   
  delay(300);  
  digitalWrite(blueLedPin, LOW);    
  digitalWrite(greenLedPin, HIGH);  
  delay(300);  
  digitalWrite(greenLedPin, LOW);   
}
