uint32_t currentMicro, lastMicro = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  Serial.begin(115200);
  digitalWrite(3, LOW);
  
}
uint32_t periodLow = 9000;
uint32_t periodHigh = 1000;

void loop() {
  // put your main code here, to run repeatedly:
  lastMicro = micros();
  currentMicro = micros();
  while (currentMicro - lastMicro < periodLow)
    currentMicro = micros();
  digitalWrite(3, HIGH);
  lastMicro = micros();
  currentMicro = micros();
  while (currentMicro - lastMicro < periodHigh)
    currentMicro = micros();
  digitalWrite(3, LOW);
}
//periodLow (73,114)
void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    if (inChar == 'w')
      periodHigh = periodHigh+50;
    if (inChar == 's')
      periodHigh = periodHigh-50;
    if (inChar == 'a')
      periodHigh = 1000;
    if (inChar == 'd')
      periodHigh = 1800;
    periodLow = 10000 - periodHigh;
  }
  Serial.print("Pulse Width: ");
  Serial.println(periodHigh);
 
}
