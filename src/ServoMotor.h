#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>

class ServoMotor {
public:
    void begin(int pin);
    void setPosition(int position);
    void update();
    bool isConnected();
private:
    Servo _servo;
    int _position;
};

#endif

