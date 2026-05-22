#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "polka.h"

namespace s21 {
class Controller {
 private:
  POLKA *model;
  int i = 0;
  int k = 0;

 public:
  Controller() { model = new POLKA(); }

  ~Controller() { delete model; }

  void function(int fun);

  double equally();

  void set_number(double num);

  void new_x(double x);
};
}  // namespace s21

#endif
