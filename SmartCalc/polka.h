#ifndef POLKA_H
#define POLKA_H

#include <cmath>
#include <iostream>
#include <stack>

namespace s21 {
enum encoding {
  BEG = 1,
  END = -1,
  SUM = 2,
  SUB = -2,
  MUL = 3,
  DIV = -3,
  MOD = -4,
  POW = 4,
  SIN = 5,
  ASIN = -5,
  COS = 6,
  ACOS = -6,
  TAN = 7,
  ATAN = -7,
  SQRT = 9,
  LN = 8,
  LOG = -8,
  NUM = 10,
  EXP = -9,
  EQUALLY = 0,
  X = -10,
};

class POLKA {
 private:
  double res;
  int output[255] = {};
  int input[255] = {};
  double number[200] = {};
  double x;

 public:
  POLKA() {
    res = 0;
    x = 0;
    // output[255] = {};
  }

  void func_test(const int *in);
  void num_test(const double *in);
  void set_func(double fun, int i);
  void set_num(double num, int i);
  void set_x(double x);
  void polka();
  double result();
};
}  // namespace s21

#endif
