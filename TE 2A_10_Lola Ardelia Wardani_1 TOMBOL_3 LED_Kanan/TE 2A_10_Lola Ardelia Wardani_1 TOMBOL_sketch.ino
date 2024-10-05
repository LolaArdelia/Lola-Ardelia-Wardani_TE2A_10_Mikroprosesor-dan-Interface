const int buttonPin = 10;   
const int greenLedPin = 13; 
const int blueLedPin = 12;  
const int redLedPin = 11;   

int lastButtonState = LOW;  
bool buttonPressed = false; 

void setup() {
  pinMode(buttonPin, INPUT);       
  pinMode(greenLedPin, OUTPUT);    
  pinMode(blueLedPin, OUTPUT);     
  pinMode(redLedPin, OUTPUT);     
}

void loop() {
  int buttonState = digitalRead(buttonPin);  

  
  if (buttonState == HIGH && lastButtonState == LOW && !buttonPressed) {
    delay(100);  
    
    if (digitalRead(buttonPin) == HIGH) {
      buttonPressed = true;  
      
      // Nyalakan LED satu per satu dengan jeda waktu
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
  } 
  
  if (buttonState == LOW && lastButtonState == HIGH) {
    buttonPressed = false;
  }

  lastButtonState = buttonState;  
}
