// robot_functions.h

#ifndef ROBOT_FUNCTIONS_H
#define ROBOT_FUNCTIONS_H
#define ENABLE 1
#define DISABLE 0
#define EXIST 1
#define NOT_EXIST 0
#define TURBO 2
#define ON 1
#define OFF 0
#define DEGREE 45
#define OBSTACLE_EXIST 1
#define OBSTACLE_NOT_EXIST 0

typedef struct OL {
  int F, L, R;
} OL;

void HW_MV_Forward(int isEnable);
void HW_MV_Backward(int isEnable);
int CLN_CMD(int isOn);
void HW_TRN_Left();
void HW_TRN_Right();
int Clean_Dust();
int F_obstacle_exist();
int L_obstacle_exist();
int R_obstacle_exist();
int Det_DE();
OL Det_OL();
int Wait(int ms);
void MV_Backward(OL obstacle_Location);
int obstacle_exist(OL obstacle_Location);
int Dust_exist();
void Obstacle_sensor_result_to_obstacle_location(char* obstacle);
char get_current_motor_state();
char* Obstacle_sensor_getter();
void Obstacle_sensor_result_setter(char* obstacle);
int get_clean_state();
int get_dust_state();
void set_dust_state(int state);

#endif  // ROBOT_FUNCTIONS_H
