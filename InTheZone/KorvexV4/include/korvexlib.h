#include "main.h"

// init encoders
Encoder leftencoder;
Encoder rightencoder;
Encoder chainencoder;
Encoder dr4bencoder;

// auto stacker globals
int coneIncrementGlobal; // this will hold the amount of cones we currently have
bool isDriverloadGlobal; // this will be true when we are stacking driver loads
bool autoStackerEnabled; // this will be true when the auto stacker is doing its thing
int chainBufferGlobal; // live tuning im loopy and i cant thinke weeeeeeeeeeeeeeeeeee

// autonomous selector
int lcdHoldGlobal; // this will hold the current screen, so we can have a 'scrollable' interface
int auton;

// debug enabler
bool debugGlobal; // set this to true whenever you want print statements in terminal

// rerun globals
bool isRecording; // ill get to this stuff eventually :wink:
bool isReplaying;

// ext globals
int driveSinceChange; // this will tell us how much time it has been since a brake
int driveDirection; // 1 is forward 0 is backward
int driveLastDirection; // 1 is forward 0 is backward, last significant direction

// opcontrol functions
void driveControl(int chassisControlLeft, int chassisControlRight);
void dr4bControl(int dr4bControl);
void fineControlToggle(int fineBtn, int fineBtn2, int reverseBtn,
                       int reverseBtn2);
void mobileGoalControl(int moboLiftBtnUp, int moboLiftBtnDown);
void coneHandlerControl(int clawBtnUp, int clawBtnDown, int chainControl);
void autoStackControl(int incrementUpBtn, int incrementDownBtn,
                      int incrementResetBtn, int driverloadBtn,
                      int fieldloadBtn, int incrementUpNoFuncBtn, int resetBtn, int bufferUp, int bufferDown);

// drive control
void driveTo(int leftTarget, int rightTarget, int waitTo); // drive pd control tuned for normal match
void driveToSkills(int leftTarget, int rightTarget, int waitTo); // drive pid control tuned for skills

// lift control
void liftTo(int liftTarget, int chainTarget, int waitTo); // lift pd control

// ext
void autoStacker(int coneIncrement, bool isDriverload); // autostack presets and run function
void lcdAutSel(int input); // lcd based autonomous selector
void rerunRecord(); // recoder for rerun