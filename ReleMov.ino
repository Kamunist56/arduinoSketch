
const byte relPin1 = 8;
const byte relPin2 = 9;  
bool status = false;
bool newStatus = false;

void setup() {
  
    Serial.begin(9600);
    pinMode(relPin1, OUTPUT);  
    pinMode(relPin2, OUTPUT);   
    Serial.println("Запуск");
    Serial.println("Инициализация...");    

    checkLamp(relPin1);
    checkLamp(relPin2);    
    
    Serial.println("Готово");
    
}

void loop(){

  switchLamp(relPin1, A1);
  switchLamp(relPin2, A0);

  printStatus();
//  Serial.println(analogRead(A3));
//  delay(1000);   
}

void checkLamp(int pin) {
   
    digitalWrite(pin, LOW);
    delay(1000);
    digitalWrite(pin, HIGH);
    delay(1000);
    
 }


void printStatus(){
  
  if (status != newStatus)
    {
        Serial.print("relPin1 = ");
        Serial.println(digitalRead(relPin1));
        Serial.print("relPin2 = ");
        Serial.println(digitalRead(relPin2));
        status = newStatus;
        Serial.println(analogRead(A1));
    }
}  

void switchLamp(int relPin, int pinmov){

//    if ((analogRead(pinmov) > 500) && (analogRead(A3) > 5))
      if (analogRead(pinmov) > 500)
      {
          digitalWrite(relPin, LOW);
          Serial.println("Движение");
      }   
      else //if (analogRead(pinmov) < 500)
      {
          digitalWrite(relPin, HIGH);
          newStatus = false;
      }
   
}
