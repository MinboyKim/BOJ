

#include <CUnit/CUnit.h>

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

OL obstacle_Location;

char current_motor_state = 'S';

int current_cleaner_state = OFF;

char* obstacle_sensor_result;

char get_current_motor_state() { return current_motor_state; }

int get_clean_state() { return current_cleaner_state; }

void HW_MV_Forward(int isEnable) {
  if (isEnable) {
    // Move Forward cmd to Motor
    current_motor_state = 'F';
  } else {
    // Stop cmd to Motor
    current_motor_state = 'S';
  }
}

void HW_MV_Backward(int isEnable) {
  if (isEnable) {
    // Move Backward cmd to Motor
    current_motor_state = 'B';
  } else {
    // Stop cmd to Motor
    current_motor_state = 'S';
  }
}
void CLN_CMD(int isOn) {
  if (isOn) {
    current_cleaner_state = ON;
  } else {
    current_cleaner_state = OFF;
  }
}

void HW_TRN_Left() {
  // Turn Left in DEGREE trigger to Motor
  current_motor_state = 'L';
}

void HW_TRN_Right() {
  // Turn Right in DEGREE trigger to Motor
  current_motor_state = 'R';
}

int get_dust_state() { return current_cleaner_state; }

void Clean_Dust() {
  if (get_dust_state() == ON) {
    current_cleaner_state = TURBO;
  }
}

char* Obstacle_sensor_getter() { return obstacle_sensor_result; }

void Obstacle_sensor_result_setter(
    const char* obstacle) {  // use in sensor per 1ms
  obstacle_sensor_result = obstacle;
}

void Obstacle_sensor_result_to_obstacle_location(const char* obstacle) {
  obstacle_Location.F = OBSTACLE_NOT_EXIST;
  obstacle_Location.L = OBSTACLE_NOT_EXIST;
  obstacle_Location.R = OBSTACLE_NOT_EXIST;
  for (int i = 0; i < strlen(obstacle); i++) {
    if (obstacle[i] == 'F') {
      obstacle_Location.F = OBSTACLE_EXIST;
    }
    if (obstacle[i] == 'L') {
      obstacle_Location.L = OBSTACLE_EXIST;
    }
    if (obstacle[i] == 'R') {
      obstacle_Location.R = OBSTACLE_EXIST;
    }
  }
  return;
}

int F_obstacle_exist() { return obstacle_Location.F; }

int L_obstacle_exist() { return obstacle_Location.L; }

int R_obstacle_exist() { return obstacle_Location.R; }

void set_dust_state(int state) { current_cleaner_state = state; }

int Det_DE() {
  if (get_dust_state() == EXIST) {
    return EXIST;
  } else {
    return NOT_EXIST;
  }
}

void Wait(int ms) {
  // wait command
}

void MV_Backward() {
  HW_MV_Backward(ENABLE);
  while (1) {
    Wait(500);
    char* current_obstacle_result = Obstacle_sensor_getter();
    Obstacle_sensor_result_to_obstacle_location(current_obstacle_result);

    if (obstacle_Location.L == NOT_EXIST) {  // Turn Left
      HW_MV_Backward(DISABLE);
      HW_TRN_Left();
      break;
    }
    if (obstacle_Location.L && !obstacle_Location.R) {  // Turn Right
      HW_MV_Backward(DISABLE);
      HW_TRN_Right();
      break;
    }
  }
  return;
}

int obstacle_exist() {
  HW_MV_Forward(DISABLE);
  CLN_CMD(OFF);
  if (obstacle_Location.F && !obstacle_Location.L) {  // Turn Left
    HW_TRN_Left();
  }
  if (obstacle_Location.F && obstacle_Location.L &&
      !obstacle_Location.R) {  // Turn Right
    HW_TRN_Right();
  }
  if (obstacle_Location.F && obstacle_Location.L &&
      obstacle_Location.R) {  // Stop, Move BackWard
    MV_Backward(obstacle_Location);
  }
  for (int i = 0; i < 5; i++) Wait(500);
  HW_MV_Forward(ENABLE);
  CLN_CMD(ON);
}

// int main() {
//     OL obstacle_Location;
//     int dust_Existence;
//     int i = 0;

//     HW_MV_Forward(ENABLE);
//     CLN_CMD(ON);
//     while (1) {
//         char* current_obstacle_result = Obstacle_sensor_getter();
//         Obstacle_sensor_result_to_obstacle_location(current_obstacle_result);
//         dust_Existence = Det_DE();

//         if (F_obstacle_exist()) {
//             obstacle_exist(obstacle_Location);
//         }

//         if (dust_Existence == 1) {  // Clean Dust, Power Up
//             HW_MV_Forward(DISABLE);
//             Clean_Dust();
//             for (i = 0; i < 5; i++) Wait(500);
//             HW_MV_Forward(ENABLE);
//         }

//         Wait(500);
//     }

//     return 0;
// }