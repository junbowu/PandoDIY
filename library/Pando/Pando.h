#ifndef Pando_h
#define Pando_h

#include <Servo.h>
#include <Oscillator.h>
#include <EEPROM.h>

// #include <US.h>
// #include "MaxMatrix.h"
#include "DFRobot_HT1632C.h"
#include <BatReader.h>

// #include "Pando_mouths.h"
#include "Pando_eyes.h"
#include "Pando_sounds.h"
#include "Pando_gestures.h"


//-- Constants
#define FORWARD     1
#define BACKWARD    -1
#define LEFT        1
#define RIGHT       -1
#define SMALL       5
#define MEDIUM      15
#define BIG         30

#define PIN_Buzzer  13
// #define PIN_Trigger 8
// #define PIN_Echo    9
#define PIN_NoiseSensor A3


class Pando
{
  public:

    //-- Pando initialization
    void init(int YL, int YR, int RL, int RR, bool load_calibration=true, int NoiseSensor=PIN_NoiseSensor, int Buzzer=PIN_Buzzer/*, int USTrigger=PIN_Trigger, int USEcho=PIN_Echo*/);

    //-- Attach & detach functions
    void attachServos();
    void detachServos();

    //-- Oscillator Trims
    void setTrims(int YL, int YR, int RL, int RR);
    void saveTrimsOnEEPROM();

    //-- Predetermined Motion Functions
    void _moveServos(int time, int  servo_target[]);
    void oscillateServos(int A[4], int O[4], int T, double phase_diff[4], float cycle);

    //-- HOME = Pando at rest position
    void home();
    bool getRestState();
    void setRestState(bool state);
    
    //-- Predetermined Motion Functions
    void jump(float steps=1, int T = 2000);

    void walk(float steps=4, int T=1000, int dir = FORWARD);
    void turn(float steps=4, int T=2000, int dir = LEFT);
    void bend (int steps=1, int T=1400, int dir=LEFT);
    void shakeLeg (int steps=1, int T = 2000, int dir=RIGHT);

    void updown(float steps=1, int T=1000, int h = 20);
    void swing(float steps=1, int T=1000, int h=20);
    void tiptoeSwing(float steps=1, int T=900, int h=20);
    void jitter(float steps=1, int T=500, int h=20);
    void ascendingTurn(float steps=1, int T=900, int h=20);

    void moonwalker(float steps=1, int T=900, int h=20, int dir=LEFT);
    void crusaito(float steps=1, int T=900, int h=20, int dir=FORWARD);
    void flapping(float steps=1, int T=1000, int h=20, int dir=FORWARD);

    //-- Sensors functions
    // float getDistance(); //US sensor
    int getNoise();      //Noise Sensor

    //-- Battery
    double getBatteryLevel();
    double getBatteryVoltage();
    
    //-- Mouth & Animations
    // void putMouth(unsigned long int mouth, bool predefined = true);
    // void putAnimationMouth(unsigned long int anim, int index);
    // void clearMouth();

    //-- Eye & Animations
    void print(const char str[], uint16_t speed);

    
    void putEyes(int eyeExpression);

    void smileEyes();
    void happyOpenEyes();
    void angryEyes();

    void sadEyes();
    void sadOpenEyes();
    void sadCloseEyes();

    void fartLeftEyes();
    void fartRightEyes();

    void bigEyes();
    void closeEyes();
    void surpriseEyes();
    void confusedEyes();
    void normalEyes();
    void normalEyesLeft();
    void normalEyesRight();
    void normalEyesUp();
    void normalEyesUpLeft();
    void normalEyesUpRight();
    void smallLoveEyes();
    void loveEyes();

    void blinkEyes();
    void binkLoveEyes();
    void gazeAround();








    //-- Sounds
    void _tone (float noteFrequency, long noteDuration, int silentDuration);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void sing(int songName);

    //-- Gestures
    void playGesture(int gesture);

  private:
    
    // MaxMatrix ledmatrix=MaxMatrix(12,10,11, 1);
    // DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR, CS);
    DFRobot_HT1632C ht1632c = DFRobot_HT1632C(11, 10, 12);

    BatReader battery;
    Oscillator servo[4];
    // US us;

    int servo_pins[4];
    int servo_trim[4];
    int servo_position[4];

    int pinBuzzer;
    int pinNoiseSensor;
    
    unsigned long final_time;
    unsigned long partial_time;
    float increment[4];

    bool isPandoResting;

    // unsigned long int getMouthShape(int number);
    // unsigned long int getAnimShape(int anim, int index);
    void _execute(int A[4], int O[4], int T, double phase_diff[4], float steps);

};

#endif


