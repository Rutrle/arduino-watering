
#define analogPin0 A0
#define analogPin1 A1

int data = 0;
int data1 = 0;
int relay_pin=7

void setup() {

  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
}

void loop() {

  data = analogRead(analogPin0);
  data1 = analogRead(analogPin1);

  Serial.print("Hodnota nactena ze senzoru1: ");
  Serial.println(data);
  Serial.print("Hodnota nactena ze senzoru2: ");
  Serial.println(data1);
  if (data > 500) {
    Serial.println("Senzor na suchu, zapínám zavlažování!");
    digitalWrite(relay_pin, HIGH);
  }
  else{
    digitalWrite(relay_pin, LOW);
    }

  delay(500);
}
