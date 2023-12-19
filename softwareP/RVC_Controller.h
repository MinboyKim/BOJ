// robot_functions.h

#ifndef ROBOT_FUNCTIONS_H
#define ROBOT_FUNCTIONS_H

typedef struct OL {
    int F, L, R;
} OL;

void HW_MV_Forward(int isEnable);
void HW_MV_Backward(int isEnable);
void CLN_CMD(int isOn);
void HW_TRN_Left();
void HW_TRN_Right();
void Clean_Dust();
int F_obstacle_exist();
int L_obstacle_exist();
int R_obstacle_exist();
OL Det_OL();
int Det_DE();
void Wait(int ms);
void MV_Backward(OL obstacle_Location);
void obstacle_exist(OL obstacle_Location);

#endif // ROBOT_FUNCTIONS_H
