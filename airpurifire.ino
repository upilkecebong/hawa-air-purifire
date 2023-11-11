#define relay D5
#define led A0
#define mq135 D1
#define mq7 D2
#define mq2 D3

int valmq2;
int valmq7;
int valmq135;

void setup() {
  Serial.begin(9600);
  pinMode(mq2,INPUT);
  pinMode(mq7,INPUT);
  pinMode(mq135,INPUT);
  pinMode(relay, OUTPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  valmq2=digitalRead(mq2);
  valmq7=digitalRead(mq7);
  valmq135=digitalRead(mq135);
  
  if(valmq2!=1 || valmq7!=1 || valmq135!=1 ){
    digitalWrite(relay,LOW); 
    digitalWrite(led,HIGH); 
    Serial.print("GAS DETECTED! ");
    Serial.print("MQ2: ");
    Serial.println(valmq2);
    Serial.print("MQ7: ");
    Serial.println(valmq7);
    Serial.print("MQ135: ");
    Serial.println(valmq135);
    delay(130000);
  }
  else{
    digitalWrite(relay,HIGH); 
    digitalWrite(led,LOW); 
    Serial.print("AIR CLEAR ");
    Serial.print("MQ2: ");
    Serial.println(valmq2);
    Serial.print("MQ7: ");
    Serial.println(valmq7);
    Serial.print("MQ135: ");
    Serial.println(valmq135);
  }
  delay(1000);

}
