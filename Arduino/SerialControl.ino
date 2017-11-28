int led = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    Serial.write(cmd);
    if (cmd == '1') {
      digitalWrite(led, HIGH);
      delay(500);
    }
    else if (cmd == '0') {
      digitalWrite(led, LOW);
      delay(500);
    }
  }
}

