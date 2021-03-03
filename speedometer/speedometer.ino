int counter = 0;
bool old_pulse = false;
int hoge;
unsigned long old_time = millis();
unsigned long new_time;
float time_difference;
const int max_mgforce = 800;
const int min_mgforce = 500;
const float circumference = (0.0005 * 3.141592963);
//const float circumference = (タイヤの円周(km) * 円周率);
const int magnet_number = 8; //磁石の個数を記入


void setup() {
  //Serial通信を開始
  Serial.begin(57600);
  pinMode(A0, INPUT);
}

int pulse(bool new_pulse){
  if(new_pulse == false && old_pulse == true){
      //磁石が通り過ぎたあとの処理
      time_difference = (millis() - old_time);
      old_time = millis();
      old_pulse = new_pulse;
      return 1;
  }

  else{
    old_pulse = new_pulse;
    return 0;
  }
}


void loop(){
  //2進数化して渡す
  hoge = pulse(((max_mgforce + min_mgforce) / 2) <= analogRead(A0));
  if(hoge == 1){
      Serial.print(((circumference / magnet_number) / (time_difference / 1000)) * 3600, 10);
      Serial.print("\n");
 }
}
