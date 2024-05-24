//5114_0

//const unsigned int led[7] = {2,3,4,5,6,7,8};
//
//
//const unsigned int num[10][7] = 
//{
//  {1,1,1,1,1,0,1},
//  {0,1,1,0,0,0,0},
//  {1,1,0,1,1,1,0},
//  {1,1,1,1,0,1,0},
//  {0,1,1,0,0,1,1},
//  {1,0,1,1,0,1,1},
//  {1,0,1,1,1,1,1},
//  {1,1,1,0,0,0,0},
//  {1,1,1,1,1,1,1},
//  {1,1,1,1,0,1,1},
//};
//
//
//void display_init(){
//  for(int x=0;x<7;x++){
//    pinMode(led[x], OUTPUT);
//  }
//}
//
//void display_clear(){
//  for(int x=0; x<7;x++){
//    digitalWrite(led[x],LOW);
//  }
//}
//
//
//void display_number(int n){
//  if(0<=n&&n<=9){
//    for(int x=0;x<7;x++){
//      digitalWrite(led[x], num[n][x]==1?HIGH:LOW);
//    }
//  }
//}
//
//
//void setup(){
//  display_init();
//}
//
//void loop(){
//  for(int n=0;n<=9;n++){
//    display_clear();
//    display_number(n);
//    delay(500);
//  }
//}


//5115_0
//
//const unsigned int led[7] = {2,3,4,5,6,7,8};
//const unsigned int num[10][7] = 
//{
//  {1,1,1,1,1,0,1},
//  {0,1,1,0,0,0,0},
//  {1,1,0,1,1,1,0},
//  {1,1,1,1,0,1,0},
//  {0,1,1,0,0,1,1},
//  {1,0,1,1,0,1,1},
//  {1,0,1,1,1,1,1},
//  {1,1,1,0,0,0,0},
//  {1,1,1,1,1,1,1},
//  {1,1,1,1,0,1,1},
//};
//
//void display_init(){
//  for(int x=0; x<7; x++){
//    pinMode(led[x], OUTPUT);
//  }
//}
//
//void display_clear(){
//  for(int x=0; x<7; x++){
//    digitalWrite(led[x], LOW);
//  }
//}
//
//void display_number(int n){
//  if(0<=n&&n<=9)
//  {
//    for(int x=0; x<7; x++)
//    {
//      digitalWrite(led[x], num[n][x] == 1?HIGH:LOW);
//    }
//  }
//}
//
//
//void setup(){
//  Serial.begin(115200);
//  display_init();
//}
//
//
//void loop(){
//  if(Serial.available()){
//    char userInput = Serial.read();
//    if('0' <= userInput && userInput <= '9'){
//      int num = userInput - '0';
//
//      display_clear();
//      display_number(num);
//    }
//  }
//}


//84

const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};
const unsigned int com[1+4] = {-1, 9, 10, 11, 12};

const unsigned int num[10][7] = 
{
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,1,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void display_init()
{
  for(int x=0; x<7; x++){
    pinMode(led[x], OUTPUT);  // 각 LED 핀을 출력 모드로 설정합니다.
  }
  for(int y=1; y<=4; y++){
    pinMode(com[y], OUTPUT);  // 각 LED 핀을 출력 모드로 설정합니다.
  }  
}

void display_clear()
{
  for(int x=0; x<7; x++){
    digitalWrite(led[x], LOW);  // 모든 LED를 끕니다.
  }
  for(int y=1; y<=4; y++){
    digitalWrite(com[y], HIGH);  // 모든 LED를 켭니다.
  }
}

void display_number(unsigned int n, unsigned int m)
{
  display_clear();

  if(0<=n&&n<=9 && 1<=m&&m<=4) {
    for(int x=0; x<7; x++) {
      digitalWrite(led[x], num[n][x] == 1?HIGH:LOW);
    }
    digitalWrite(com[m], LOW);
  }
}

void setup() 
{
  display_init();
}

void loop() 
{
  display_number(1, 1);
  delay(500);
  display_number(2, 2);
  delay(500);
  display_number(3, 3);
  delay(500);
  display_number(4, 4);
  delay(500);
}
