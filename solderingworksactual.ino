#include <Servo.h>

Servo myservoX; 
Servo myservoY; 

int posX = 0;
int posY = 0;

int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;

int readingX1;
int readingY1;
int readingX2;
int readingY2;


int x = 8;
int y = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservoX.attach(x);
  myservoY.attach(y);
}

int AverageX1(int r1, int r2){
  return (r1 + r2) / 2;
}

int AverageX2(int r3, int r4){
  return (r3 + r4) / 2;
}

int AverageY1(int r1, int r3){
  return (r1 + r3) / 2;
}

int AverageY2(int r2, int r4){
  return (r2 + r4) / 2;
}

void moveX(int X1, int X2){
  if(X1 < X2){
    myservoX.write(150);
  }
  else{
    myservoX.write(0);
  }
}

void moveY(int Y1, int Y2){
  if(Y1 < Y2){
    myservoY.write(0);
  }
  else{
    myservoY.write(150);
  }
}


void loop() {

  readingX1 = AverageX1(analogRead(ldr1),analogRead(ldr2));
  readingX2 = AverageX2(analogRead(ldr3),analogRead(ldr4));
  readingY1 = AverageY1(analogRead(ldr1),analogRead(ldr3));
  readingY2 = AverageY2(analogRead(ldr2),analogRead(ldr4));

  // moveX(readingX1,readingX2);
  // moveY(readingY1,readingY2);

  int servoAngleX = map(readingX1 - readingX2, -700, 700, 0, 180);
  int servoAngleY = map(readingY1 - readingY2, -700, 700, 0, 180);

  myservoX.write(servoAngleX);
  myservoY.write(servoAngleY);

  // Serial.print(readingX1);
  // Serial.print(" ");
  // Serial.print(readingX2);
  // Serial.print(" ");
  // Serial.print(readingY1);
  // Serial.print(" ");
  // Serial.print(readingY2);
  // Serial.println();

  Serial.print(servoAngleX);
  Serial.print(" ");
  Serial.print(servoAngleY);
  Serial.println();

 
  delay(200);
}
