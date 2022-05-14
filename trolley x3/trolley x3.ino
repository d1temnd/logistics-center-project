#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);		

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 2){
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 4){
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
				
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void Forward();
double speed;
void back();
void Stop();
void zagruzili();
double white;
double black;
MeLimitSwitch sw_4_2(4,2);
void move_left();
void move_right();
void line();
double follow_line;
MeLineFollower linefollower_2(2);
void zagr_start();
double empty;
double busy;
MeLimitSwitch sw_1_1(1,1);
MeBuzzer buzzer;
MeLimitSwitch sw_1_2(1,2);
MeLimitSwitch sw_3_2(3,2);
MeLimitSwitch sw_4_1(4,1);


void Forward()
{
    motor_9.run((9)==M1?-(speed):(speed));
    
    motor_10.run((10)==M1?-(speed):(speed));
    
}

void back()
{
    motor_9.run((9)==M1?-((-1) * (speed)):((-1) * (speed)));
    
    motor_10.run((10)==M1?-((-1) * (speed)):((-1) * (speed)));
    
}

void Stop()
{
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
}

void zagruzili()
{
    while(!(((sw_4_2.touched())==(white))))
    {
        _loop();
        line();
    }
    
    while(!(((sw_4_2.touched())==(black))))
    {
        _loop();
        line();
    }
    
    Stop();
    
}

void move_left()
{
    motor_9.run((9)==M1?-(speed):(speed));
    
    motor_10.run((10)==M1?-(0):(0));
    
}

void move_right()
{
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(speed):(speed));
    
}

void line()
{
    follow_line = linefollower_2.readSensors();
    
    if(((follow_line)==(0))){
        Forward();
    }else{
        if(((follow_line)==(2))){
            move_left();
        }
        if(((follow_line)==(1))){
            move_right();
        }
    }
    
}

void zagr_start()
{
    line();
    
    while(!(((sw_4_2.touched())==(white))))
    {
        _loop();
    }
    
    while(!(((sw_4_2.touched())==(black))))
    {
        _loop();
        line();
    }
    
    Stop();
    
}


void setup(){
    empty = 1;
    busy = 0;
    black = 0;
    white = 1;
    _delay(1);
    speed = 100;
    zagruzili();
    while(!(((sw_1_1.touched())==(busy))))
    {
        _loop();
    }
    buzzer.tone(262, 250);
    delay(20);
    _delay(5);
    zagruzili();
    while(!(((sw_1_2.touched())==(busy))))
    {
        _loop();
    }
    buzzer.tone(294, 250);
    delay(20);
    _delay(5);
    zagruzili();
    while(!(((sw_3_2.touched())==(busy))))
    {
        _loop();
    }
    buzzer.tone(330, 250);
    delay(20);
    _delay(5);
    line();
    _delay(0.5);
    while(!(((sw_4_1.touched())==(0))))
    {
        _loop();
        line();
    }
    Stop();
    buzzer.tone(494, 500);
    delay(20);
    
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

