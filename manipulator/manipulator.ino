#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeAuriga.h>
#include <MePS2.h>

//Encoder Motor
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);

void isr_process_encoder1(void)
{
      if(digitalRead(Encoder_1.getPortB()) == 0){
            Encoder_1.pulsePosMinus();
      }else{
            Encoder_1.pulsePosPlus();
      }
}

void isr_process_encoder2(void)
{
      if(digitalRead(Encoder_2.getPortB()) == 0){
            Encoder_2.pulsePosMinus();
      }else{
            Encoder_2.pulsePosPlus();
      }
}

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
            leftSpeed = -speed;
            rightSpeed = speed;
      }else if(direction == 2){
            leftSpeed = speed;
            rightSpeed = -speed;
      }else if(direction == 3){
            leftSpeed = -speed;
            rightSpeed = -speed;
      }else if(direction == 4){
            leftSpeed = speed;
            rightSpeed = speed;
      }
      Encoder_1.setTarPWM(leftSpeed);
      Encoder_2.setTarPWM(rightSpeed);
}
void moveDegrees(int direction,long degrees, int speed_temp)
{
      speed_temp = abs(speed_temp);
      if(direction == 1)
      {
            Encoder_1.move(-degrees,(float)speed_temp);
            Encoder_2.move(degrees,(float)speed_temp);
      }
      else if(direction == 2)
      {
            Encoder_1.move(degrees,(float)speed_temp);
            Encoder_2.move(-degrees,(float)speed_temp);
      }
      else if(direction == 3)
      {
            Encoder_1.move(-degrees,(float)speed_temp);
            Encoder_2.move(-degrees,(float)speed_temp);
      }
      else if(direction == 4)
      {
            Encoder_1.move(degrees,(float)speed_temp);
            Encoder_2.move(degrees,(float)speed_temp);
      }
}

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void TAKE();
double VTAKE;
MeDCMotor motor_2(2);
void __func__50();
MeLineFollower linefollower_9(9);
void __func__114_101_108_111_97_100_40_99_99_119_41();
void DOWN();
MeLimitSwitch sw_6_1(6,1);
MeDCMotor motor_1(1);
void CCW();
double VCWCCW;
void ControlProgramm();
#ifdef MeAuriga_H
MePS2 MePS2(PORT_16);
#elif defined(MeMegaPi_H)
MePS2 MePS2(PORT_15);
#elif defined(MeMegaPiPro_H)
MePS2 MePS2(PORT_15);
#else
MePS2 MePS2(PORT_5);
#endif
MeBuzzer buzzer;
void __func__51();
void UP();
MeLimitSwitch sw_6_2(6,2);
void CW();
void GET();
void __func__49();
void __func__114_101_108_111_97_100_40_99_119_41();
void STOP();
double VUPDOWN;
double Linel;
MeRGBLed rgbled_0(0, 12);
MeLineFollower linefollower_8(8);


void TAKE()
{
    motor_2.run((VTAKE) - (10));
    
    _delay(1.5);
    
    motor_2.run(0);
    
}

void __func__50()
{
    _delay(1);
    
    UP();
    
    _delay(0.2);
    
    CW();
    
    _delay(1);
    
    while(!(((linefollower_9.readSensors())==(2))))
    {
        _loop();
    }
    
    STOP();
    
    _delay(1);
    
    DOWN();
    
    _delay(1);
    
    GET();
    
    _delay(0.5);
    
    UP();
    
    _delay(1);
    
    CCW();
    
    while(!(((linefollower_9.readSensors())==(0))))
    {
        _loop();
    }
    
    STOP();
    
    _delay(1);
    
    DOWN();
    
    _delay(1);
    
}

void __func__114_101_108_111_97_100_40_99_99_119_41()
{
    CCW();
    
    while(!(((linefollower_9.readSensors())==(0))))
    {
        _loop();
    }
    
    STOP();
    
}

void DOWN()
{
    if(((sw_6_1.touched())==(0))){
        motor_1.run(200);
        while(!(((sw_6_1.touched())==(1))))
        {
            _loop();
        }
        motor_1.run(0);
    }
    
    motor_1.run(0);
    
}

void CCW()
{
    Encoder_1.setTarPWM(VCWCCW);
    
    Encoder_2.setTarPWM(VCWCCW);
    
}

void ControlProgramm()
{
    if(MePS2.ButtonPressed(12)){
        TAKE();
        __func__49();
    }
    
    if(MePS2.ButtonPressed(9)){
        TAKE();
        __func__50();
    }
    
    if(MePS2.ButtonPressed(10)){
        TAKE();
        __func__51();
    }
    
    if(MePS2.ButtonPressed(17)){
        __func__114_101_108_111_97_100_40_99_119_41();
    }
    
    if(MePS2.ButtonPressed(16)){
        __func__114_101_108_111_97_100_40_99_99_119_41();
    }
    
    if(MePS2.ButtonPressed(1)){
        TAKE();
    }
    
    if(MePS2.ButtonPressed(5)){
        GET();
    }
    
    if(MePS2.ButtonPressed(15)){
        VTAKE += -20;
        if((VTAKE) < (30)){
            VTAKE = 30;
            buzzer.tone(65, 500);
            delay(20);
        }else{
            buzzer.tone(262, 125);
            delay(20);
        }
    }
    
    if(MePS2.ButtonPressed(14)){
        VTAKE += 20;
        if((VTAKE) > (200)){
            VTAKE = 200;
            buzzer.tone(110, 500);
            delay(20);
        }else{
            buzzer.tone(440, 125);
            delay(20);
        }
    }
    
    if(MePS2.ButtonPressed(3)){
        DOWN();
    }
    
    if(MePS2.ButtonPressed(7)){
        UP();
    }
    
}

void __func__51()
{
    _delay(1);
    
    UP();
    
    _delay(0.2);
    
    CW();
    
    _delay(1);
    
    while(!(((linefollower_9.readSensors())==(0))))
    {
        _loop();
    }
    
    STOP();
    
    _delay(1);
    
    DOWN();
    
    _delay(1);
    
    GET();
    
    _delay(0.5);
    
    UP();
    
    _delay(1);
    
    CCW();
    
    _delay(1);
    
    while(!(((linefollower_9.readSensors())==(0))))
    {
        _loop();
    }
    
    STOP();
    
    _delay(1);
    
    DOWN();
    
    _delay(1);
    
}

void UP()
{
    if(((sw_6_2.touched())==(0))){
        motor_1.run(-200);
        while(!(((sw_6_2.touched())==(1))))
        {
            _loop();
        }
        motor_1.run(0);
    }
    
    motor_1.run(0);
    
}

void CW()
{
    Encoder_1.setTarPWM((VCWCCW) * (-1));
    
    Encoder_2.setTarPWM((VCWCCW) * (-1));
    
}

void GET()
{
    motor_2.run((VTAKE) * (-1));
    
    _delay(1.5);
    
    motor_2.run(0);
    
}

void __func__49()
{
    _delay(1);
    
    UP();
    
    _delay(0.2);
    
    CW();
    
    _delay(1);
    
    while(!(((linefollower_9.readSensors())==(1))))
    {
        _loop();
    }
    
    STOP();
    
    _delay(1);
    
    DOWN();
    
    _delay(1);
    
    GET();
    
    _delay(0.5);
    
    UP();
    
    _delay(1);
    
    CCW();
    
    while(!(((linefollower_9.readSensors())==(0))))
    {
        _loop();
    }
    
    STOP();
    
    _delay(1);
    
    DOWN();
    
    _delay(1);
    
}

void __func__114_101_108_111_97_100_40_99_119_41()
{
    CW();
    
    while(!(((linefollower_9.readSensors())==(0))))
    {
        _loop();
    }
    
    STOP();
    
}

void STOP()
{
    Encoder_1.setTarPWM(0);
    
    Encoder_2.setTarPWM(0);
    
}


void setup(){
    attachInterrupt(Encoder_1.getIntNum(), isr_process_encoder1, RISING);
    attachInterrupt(Encoder_2.getIntNum(), isr_process_encoder2, RISING);
    MePS2.begin(115200);
    buzzer.setpin(45);
    //Set Pwm 8KHz
    TCCR1A = _BV(WGM10);
    TCCR1B = _BV(CS11) | _BV(WGM12);
    TCCR2A = _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS21);
    
     rgbled_0.setpin(44);
    VUPDOWN = 200;
    VCWCCW = 40;
    VTAKE = 200;
    Linel = linefollower_9.readSensors();
    _delay(1);
    CCW();
    while(!(((0)==(linefollower_9.readSensors()))))
    {
        _loop();
    }
    STOP();
    _delay(0.5);
    DOWN();
    _delay(0.5);
    while(!(MePS2.ButtonPressed(11)))
    {
        _loop();
        ControlProgramm();
        rgbled_0.setColor(0,20,0,0);
        rgbled_0.show();
    }
    
}

void loop(){
    
    VUPDOWN = 200;
    VCWCCW = 40;
    VTAKE = 200;
    Linel = linefollower_9.readSensors();
    rgbled_0.setColor(0,0,20,0);
    rgbled_0.show();
    if((linefollower_8.readSensors()) > (0)){
        TAKE();
        if(((linefollower_8.readSensors())==(2))){
            __func__50();
        }else{
            if(((linefollower_8.readSensors())==(1))){
                __func__49();
            }else{
                if(((linefollower_8.readSensors())==(3))){
                    __func__51();
                }
            }
        }
    }
    if(MePS2.ButtonPressed(11)){
        buzzer.tone(349, 250);
        delay(20);
        _delay(0.5);
        while(!(MePS2.ButtonPressed(11)))
        {
            _loop();
            rgbled_0.setColor(0,20,0,0);
            rgbled_0.show();
            ControlProgramm();
        }
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    Encoder_1.loop();
    
    Encoder_2.loop();
    
    MePS2.loop();
    
    
}

