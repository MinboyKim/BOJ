#define ENABLE 1
#define DISABLE 0
#define ON 1
#define OFF 0
#define DEGREE 30

typedef struct OL {
  int F, L, R;
} OL;

void HW_MV_Forward(int isEnable) {
  if (isEnable) {
    // Move Forward cmd to Motor
  } else {
    // Stop cmd to Motor
  }
}

void HW_MV_Backward(int isEnable) {
  if (isEnable) {
    // Move Backward cmd to Motor
  } else {
    // Stop cmd to Motor
  }
}
void CLN_CMD(int isOn) {
  if (isOn) {
    // Turn on cmd to Cleaner
  } else {
    // Turn off cmd to Cleaner
  }
}

void HW_TRN_Left() {
  // Turn Left in DEGREE trigger to Motor
}

void HW_TRN_Right() {
  // Turn Right in DEGREE trigger to Motor
}

void Clean_Dust() {
  // Clean Dust cmd to Cleaner
}

int F_obstacle_exist() {}

int L_obstacle_exist() {}

int R_obstacle_exist() {}

OL Det_OL() {
  OL ol;
  if (F_obstacle_exist())
    ol.F = 1;
  else
    ol.F = 0;
  if (L_obstacle_exist())
    ol.L = 1;
  else
    ol.L = 0;
  if (R_obstacle_exist())
    ol.L = 1;
  else
    ol.L = 0;
  return ol;
}

int Det_DE() { return 1; }

void Wait(int ms) {
  // wait command
}

void MV_Backward(OL obstacle_Location) {
  HW_MV_Backward(ENABLE);
  while (1) {
    Wait(500);
    obstacle_Location = Det_OL();
    if (obstacle_Location == 0b000 ||
        obstacle_Location == 0b001) {  // Turn Left
      HW_MV_Backward(DISABLE);
      HW_TRN_Left();
      break;
    }
    if (obstacle_Location == 0b010) {  // Turn Right
      HW_MV_Backward(DISABLE);
      HW_TRN_Right();
      break;
    }
  }
}

void obstacle_exist(OL obstacle_Location) {
  HW_MV_Forward(DISABLE);
  CLN_CMD(OFF);
  if (obstacle_Location == 0b100 || obstacle_Location == 0b101) {  // Turn Left
    HW_TRN_Left();
  }
  if (obstacle_Location == 0b110) {  // Turn Right
    HW_TRN_Right();
  }
  if (obstacle_Location == 0b111) {  // Stop, Move BackWard
    MV_Backward(obstacle_Location);
  }
  for (int i = 0; i < 5; i++) Wait(500);
  HW_MV_Forward(ENABLE);
  CLN_CMD(ON);
}

int main() {
  OL obstacle_Location;
  int dust_Existence;
  int i = 0;

  HW_MV_Forward(ENABLE);
  CLN_CMD(ON);
  while (1) {
    obstacle_Location = Det_OL();
    dust_Existence = Det_DE();

    if (obstacle_Location == 0b100 || obstacle_Location == 0b101 ||
        obstacle_Location == 0b110 || obstacle_Location == 0b111) {
      obstacle_exist(obstacle_Location);
    }

    if (dust_Existence == 1) {  // Clean Dust, Power Up
      HW_MV_Forward(DISABLE);
      Clean_Dust();
      for (i = 0; i < 5; i++) Wait(500);
      HW_MV_Forward(ENABLE);
    }

    Wait(500);
  }

  return 0;
}