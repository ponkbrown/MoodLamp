// Mood lamp, cambia entre loscolores de un led RGB

float RGB0[3];
float RGB1[3];
float RGB2[3];
float INC[3];

int red, green, blue;

int RedPin = 3;
int GreenPin = 5;
int BluePin = 6;

void setup(){
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;
  
  RGB2[0] = random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);
  
}

void loop(){
  
  randomSeed(analogRead(0));
  
  for (int x=0; x<3; x++){
    INC[x] = (RGB1[x] - RGB2[x]) / 256;
  }
  
  for (int x=0;  x < 256; x++){
    red = int(RGB1[0]);
    green = int(RGB1[1]);
    blue = int(RGB1[2]);
    
    analogWrite(RedPin, red);
    analogWrite(GreenPin, green);
    analogWrite(BluePin, blue);
    

    Serial.print("R:");
    Serial.print(red);
    Serial.print(" G:");
    Serial.print(green);
    Serial.print(" B:");
    Serial.println(blue);

    
    delay(1000);
    
    RGB1[0] -= INC[0];
    RGB1[1] -= INC[1];
    RGB1[2] -= INC[2];
  }
  
  for (int x=0; x<3; x++){
    RGB2[x] = random(556)-300;
    RGB2[x] = constrain(RGB2[x], 0, 255);
    Serial.print(RGB2[x]);
    
    delay(60000);
  }
}
