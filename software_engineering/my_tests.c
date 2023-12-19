#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "RVC_Controller.h"

// 테스트 케이스

void test_front_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("F00");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 0);
}

void test_left_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("0L0");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 0);
}

void test_right_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("00R");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 1);
}

void test_front_left_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("FL0");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 0);
}

void test_front_right_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("F0R");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 1);
}

void test_left_right_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("0LR");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 1);
}

void test_no_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("000");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 0);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 0);
}

void test_all_obstacle_exist() {
  Obstacle_sensor_result_to_obstacle_location("FLR");
  CU_ASSERT_EQUAL(F_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(L_obstacle_exist(), 1);
  CU_ASSERT_EQUAL(R_obstacle_exist(), 1);
}

void test_clean_on_state() {
  CLN_CMD(ON);
  CU_ASSERT_EQUAL(get_clean_state(), ON);
}

void test_clean_off_state() {
  CLN_CMD(OFF);
  CU_ASSERT_EQUAL(get_clean_state(), OFF);
}

void test_clean_turbo_state() {
  CLN_CMD(ON);
  Clean_Dust();
  CU_ASSERT_EQUAL(get_clean_state(), TURBO);
}

void test_if_cleaner_off_then_turbo_disabled() {
  CLN_CMD(OFF);
  Clean_Dust();
  CU_ASSERT_EQUAL(get_clean_state(), OFF);
}

void test_HW_MV_Forward() {
  HW_MV_Forward(1);
  char current_motor_state = get_current_motor_state();
  CU_ASSERT_EQUAL(current_motor_state, 'F');
}

void test_HW_MV_NOT_Forward() {
  HW_MV_Forward(0);
  char current_motor_state = get_current_motor_state();
  CU_ASSERT_EQUAL(current_motor_state, 'S');
}

void test_HW_MV_Backward() {
  HW_MV_Backward(1);
  char current_motor_state = get_current_motor_state();
  CU_ASSERT_EQUAL(current_motor_state, 'B');
}

void test_HW_MV_NOT_Backward() {
  HW_MV_Backward(0);
  char current_motor_state = get_current_motor_state();
  CU_ASSERT_EQUAL(current_motor_state, 'S');
}

void test_HW_TRN_Left() {
  HW_TRN_Left();
  char current_motor_state = get_current_motor_state();
  CU_ASSERT_EQUAL(current_motor_state, 'L');
}

void test_HW_TRN_Right() {
  HW_TRN_Right();
  char current_motor_state = get_current_motor_state();
  CU_ASSERT_EQUAL(current_motor_state, 'R');
}

void test_Dust_EXIST() {
  set_dust_state(EXIST);
  CU_ASSERT_EQUAL(Det_DE(), EXIST);
}

void test_Dust_NOT_EXIST() {
  set_dust_state(NOT_EXIST);
  CU_ASSERT_EQUAL(Det_DE(), NOT_EXIST);
}

int main() {
  // CUnit 초기화
  CU_initialize_registry();

  // Test Suite 생성
  CU_pSuite suite = CU_add_suite("suite", NULL, NULL);

  // 테스트 케이스 추가

  CU_add_test(suite, "test_front_obstacle_exist", test_front_obstacle_exist);
  CU_add_test(suite, "test_left_obstacle_exist", test_left_obstacle_exist);
  CU_add_test(suite, "test_right_obstacle_exist", test_right_obstacle_exist);
  CU_add_test(suite, "test_front_left_obstacle_exist",
              test_front_left_obstacle_exist);
  CU_add_test(suite, "test_front_right_obstacle_exist",
              test_front_right_obstacle_exist);
  CU_add_test(suite, "test_left_right_obstacle_exist",
              test_left_right_obstacle_exist);
  CU_add_test(suite, "test_no_obstacle_exist", test_no_obstacle_exist);
  CU_add_test(suite, "test_all_obstacle_exist", test_all_obstacle_exist);
  CU_add_test(suite, "test_HW_MV_Forward", test_HW_MV_Forward);
  CU_add_test(suite, "test_HW_MV_NOT_Forward", test_HW_MV_NOT_Forward);
  CU_add_test(suite, "test_HW_MV_Backward", test_HW_MV_Backward);
  CU_add_test(suite, "test_HW_MV_NOT_Backward", test_HW_MV_NOT_Backward);
  CU_add_test(suite, "test_HW_TRN_Left", test_HW_TRN_Left);
  CU_add_test(suite, "test_HW_TRN_Right", test_HW_TRN_Right);
  CU_add_test(suite, "test_clean_on_state", test_clean_on_state);
  CU_add_test(suite, "test_clean_off_state", test_clean_off_state);
  CU_add_test(suite, "test_clean_turbo_state", test_clean_turbo_state);
  CU_add_test(suite, "test_Dust_EXIST", test_Dust_EXIST);
  CU_add_test(suite, "test_Dust_NOT_EXIST", test_Dust_NOT_EXIST);
  CU_add_test(suite, "test_if_cleaner_off_then_turbo_disabled",
              test_if_cleaner_off_then_turbo_disabled);

  // 테스트 실행
  CU_basic_run_tests();

  // CUnit 정리
  CU_cleanup_registry();

  return 0;
}