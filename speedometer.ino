void setup() {
  //Serial通信を開始
  Serial.begin(57600);
  pinMode(A0, INPUT);
}


void loop() {
  double voltage = analogRead(A0)/ 1024.0 * 4.95;
  Serial.print("voltage = ");
  Serial.println(voltage);

}
