#include <Servo.h>
Servo arm1, arm2, grapper;
int sp = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  arm1.attach(8);
  arm2.attach(9);
  grapper.attach(10);
  grapper.write(0);
}

void loop() {
  char data = Serial.read();
  if(data == 'r') {
    arm1.write(arm1.read() + sp);
    arm2.write(arm2.read() + sp);
  }else if(data == 'l') {
    arm1.write(arm1.read() - sp);
    arm2.write(arm2.read() - sp);
  }else if(data == 'u') {
    arm1.write(arm1.read() + sp);
    arm2.write(arm2.read() - sp);
  }
  else if(data == 'd') {
    arm1.write(arm1.read() - sp);
    arm2.write(arm2.read() + sp);
  }else if(data == '1') {
    if(grapper.read() + 2*sp > 180)
      grapper.write(45);
    else
      grapper.write(grapper.read() + 2*sp);
  }else if(data == '2'){
    grapper.write(grapper.read() - 2*sp);
  }else if(data == '3'){
    sp += 1;
  }else if(data == '4'){
    sp -= 1;
  }
 
  if(sp > 10)
    sp = 10;
  else if(sp < 1)
    sp = 1;
  delay(50);
  Serial.println(data);
}
