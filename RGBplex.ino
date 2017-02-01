const int pins[8] = {2,3,4,5,6,7,8,9};
const int r = 0;
const int g = 1;
const int b = 2;
int led[2];

void setup() {
  for (int i = 0; i < sizeof(pins); i++){
    pinMode(pins[i], INPUT);
  }
}
void loop() {
  //Test Cycle
  int cycle = ((millis()/125)%51);
  int level = (cycle%17);
  int color = (cycle/17);
  indicate(level,color);
}
void indicate(int level, int color){
  for (int i = 1;i <= level;i++){
    light(i,color);  
  }
}
int cathode(int level){
  return ((level - 1) % 8); 
}

int anode(int level, int color){
  if(level > 8){
    color += 3;
  }
  if (color >= cathode(level)){
    color += 1;
  }
  return color;
}

void light(int level, int color){
  led[0] = pins[cathode(level)];
  led[1] = pins[anode(level,color)];
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  digitalWrite(led[0],HIGH);
  digitalWrite(led[1],LOW);
  //delay();
  pinMode(led[0], INPUT);
  pinMode(led[1], INPUT);
}
