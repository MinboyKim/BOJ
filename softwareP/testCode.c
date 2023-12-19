#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "RVC_Controller.h"

// 테스트할 함수
int add(int a, int b) { return a + b; }

// 테스트 케이스
void testAddition() { CU_ASSERT(F_obstacle_exist() == 1); }

int main() {
  // CUnit 초기화
  CU_initialize_registry();

  // Test Suite 생성
  CU_pSuite suite = CU_add_suite("Suite", NULL, NULL);
  CU_pSuite suite2 = CU_add_suite("Suite", NULL, NULL);

  // 테스트 케이스 추가
  CU_add_test(suite, "testAddition", testAddition);

  CU_add_test(suite2, "testAddition2", testAddition);

  // 테스트 실행
  CU_basic_run_tests();

  // CUnit 정리
  CU_cleanup_registry();

  return 0;
}
