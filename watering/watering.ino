
#define analogPin0 A0
#define analogPin1 A1

int moisture_1 = 0;
int moisture_2 = 0;
int relay_pin = 7;
int moist=500;

void setup() {
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
}

void loop() {

  moisture_1 = analogRead(analogPin0);
  moisture_2 = analogRead(analogPin1);

  Serial.print("Moisture on sensor 1: ");
  Serial.println(moisture_1);
  Serial.print("Moisture on sensor 2: ");
  Serial.println(moisture_2);
  if ((moisture_1 > moist)||(moisture_2 > moist)) {
    Serial.println("Sensors dry, WATERING ON");
    digitalWrite(relay_pin, HIGH);
    delay(3600);
  }
  else{
    digitalWrite(relay_pin, LOW);
    Serial.println("Sensors wet, WATERING OFF");
    }

  delay(500);
}
