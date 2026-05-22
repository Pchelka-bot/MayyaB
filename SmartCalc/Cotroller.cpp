#include "Controller.h"

void s21::Controller::function(int fun) {
  model->set_func(fun, i);
  i++;
}

double s21::Controller::equally() {
  i = 0;
  k = 0;
  model->polka();
  return model->result();
}

void s21::Controller::set_number(double num) {
  model->set_num(num, k);
  k++;
}

void s21::Controller::new_x(double x) { model->set_x(x); }
