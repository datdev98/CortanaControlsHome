int livingRoom = 3;
int kitchen = 6;
int bedroom = 9;
String cmd;

void setup() {
  // put your setup code here, to run once:
  pinMode(livingRoom, OUTPUT);
  pinMode(kitchen, OUTPUT);
  pinMode(bedroom, OUTPUT);
  Serial.begin(9600);

  while (!Serial) {
    ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    if (isDigit(inChar))
      cmd += inChar;

    if (cmd.length() == 2) {
      switch (cmd[0]) {
        case '1':
          control(livingRoom, cmd[1]);
          break;
        case '2':
          control(kitchen, cmd[1]);
          break;
        case '3':
          control(bedroom, cmd[1]);
          break;
      }
      cmd = "";
    }
  }
}

void control(int room, char state) {
  if (state == '0')
    digitalWrite(room, LOW);
  else
    digitalWrite(room, HIGH);
}



