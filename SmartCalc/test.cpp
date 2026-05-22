#include <gtest/gtest.h>

#include "polka.h"

TEST(test_1, first) {
  s21::POLKA *proba = new s21::POLKA();
  int test[12] = {9, 1, 8, 1, 10, 2, 10, 3, 10, -1, -1, 0};
  double test_2[4] = {2.5, 7.3, 0.5, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = sqrt(log(2.5 + 7.3 * 0.5));
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_2, second) {
  s21::POLKA *proba = new s21::POLKA();
  int test[13] = {10, -3, 1, 5, 1, 10, 2, 10, -1, 2, 10, -1, 0};
  double test_2[5] = {1, 30, 2, 2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = 1 / (sin(30 + 2) + 2);
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

//"1/2+(2+3)/sin(9-2)^2=";
TEST(test_3, third) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {10, -3, 10, 2,  1,  10, 2, 10, -1, -3,
                  5,  1,  10, -2, 10, -1, 4, 10, 0};
  double test_2[15] = {1, 2, 2, 3, 9, 2, 2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = 1.0 / 2.0 + (2.0 + 3.0) / pow(sin(9 - 2), 2);
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

//тесты на минусы
TEST(test_4, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {10, -2, 10, -2, 10, 0};
  double test_2[15] = {0.1, 2, 3, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = 0.1 - 2 - 3;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

//
TEST(test_5, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {10, 3, 10, -3, 10, 2, -5, 1, 10, -1, 0};
  double test_2[15] = {0.1, 2, 3, 0.2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = 0.1 * 2 / 3 + asin(0.2);
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_6, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {6, 1, 10, -1, -2, -6, 1, 10, -1, 2, 7, 1, 10, -1, 0};
  double test_2[15] = {0.1, 0.2, 3, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = cos(0.1) - acos(0.2) + tan(3);
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_7, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {1, 1, -2, 10, 2, 10, -1, 0};
  double test_2[15] = {0.1, 2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = EILSEQ;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_8, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {-7, 1, 10, -1, 2, 8, 1, 10, -1, 0};
  double test_2[15] = {0.1, -2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = EILSEQ;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_9, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {-8, 1, 10, -1, 0};
  double test_2[15] = {-0.1, 2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = EILSEQ;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_10, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {9, 1, 10, -1, 0};
  double test_2[15] = {-0.1, 2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = EILSEQ;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_11, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {-8, 1, 10, -1, 0};
  double test_2[15] = {2, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = log10(2);
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

//-5 1 10 -1 0 10 = 2
TEST(test_13, tests) {
  s21::POLKA *proba = new s21::POLKA();
  proba->set_func(-5, 0);
  proba->set_func(1, 1);
  proba->set_func(10, 2);
  proba->set_func(-1, 3);
  proba->set_func(0, 4);
  proba->set_num(2, 1);
  proba->polka();
  double out = proba->result();
  double res = EILSEQ;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

TEST(test_14, tests) {
  s21::POLKA *proba = new s21::POLKA();
  int test[30] = {1, 10, 2, 10, -1, -1, 0};
  double test_2[15] = {2, 3, 0};
  proba->func_test(test);
  proba->num_test(test_2);
  proba->polka();
  double out = proba->result();
  double res = EILSEQ;
  EXPECT_NEAR(out, res, 1e-6);
  delete proba;
};

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
