#include "polka.h"

#include <cmath>
#include <iostream>
#include <stack>

void s21::POLKA::polka() {
  res = 0;
  int a = 0, k = 0;
  int num = 0;
  std::stack<int> st;
  while (input[a] != EQUALLY) {
    if (input[a] == NUM || input[a] == X) {
      output[k] = input[a];
      k++;
      num++;
    } else if (input[a] == BEG) {
      st.push(input[a]);

    } else if (input[a] == END) {
      if (st.empty() == true) {
        res = EILSEQ;
        break;
      } else {
        while (st.top() != BEG) {
          if (st.empty() == true) {
            res = EILSEQ;
            break;
          }
          output[k] = st.top();
          st.pop();
          k++;
        }
        if (res == EILSEQ) break;
        st.pop();
      }
    } else if (input[a] == SUM || input[a] == SUB) {
      if (a == 0 || input[a - 1] == BEG) {
        output[k] = NUM;
        k++;
        num++;
        st.push(output[a]);
      } else if (input[a - 1] != NUM && input[a - 1] != X &&
                 input[a - 1] != END) {
        if (input[a] == SUB) {
          number[num] *= -1;
        }
      } else if (st.empty() == false && (st.top() > -9 && st.top() < 10) &&
                 (st.top() != (1 || -1))) {
        while (st.empty() == false && st.top() != BEG) {
          output[k] = st.top();
          st.pop();
          k++;
        }
        st.push(input[a]);
      } else {
        st.push(input[a]);
      }
    } else if (input[a] == MUL || input[a] == DIV) {
      if (st.empty() == false && ((st.top() > -9 && st.top() < -2) ||
                                  (st.top() < 10 && st.top() > 2))) {
        output[k] = st.top();
        st.pop();
        st.push(input[a]);
        k++;
      } else {
        st.push(input[a]);
      }
    } else if ((input[a] > -9 && input[a] < -3) ||
               (input[a] > 3 && input[a] < 10)) {
      if (st.empty() == false && ((st.top() > -9 && st.top() < -3) ||
                                  (st.top() < 10 && st.top() > 3))) {
        output[k] = st.top();
        st.pop();
        st.push(input[a]);
        k++;
      } else {
        st.push(input[a]);
      }
    } else {
      res = EILSEQ;
      break;
    }
    a++;
  }
  while (st.empty() == false) {
    if (st.top() == BEG) {
      res = EILSEQ;
      break;
    }
    output[k] = st.top();
    st.pop();
    k++;
  }
}

double s21::POLKA::result() {
  if (res != EILSEQ) {
    int f = 0, k = 0, i = 0;
    double temp[70];
    while (output[k] != EQUALLY) {
      if (output[k] == NUM) {
        temp[f] = number[i];
        i++;
        f++;
      } else if (output[k] == X) {
        temp[f] = x;
        f++;
      } else if (output[k] == SUM) {
        temp[f - 2] = temp[f - 2] + temp[f - 1];
        f--;
      } else if (output[k] == MUL) {
        temp[f - 2] = temp[f - 2] * temp[f - 1];
        f--;
      } else if (output[k] == SUB) {
        temp[f - 2] = temp[f - 2] - temp[f - 1];
        f--;
      } else if (output[k] == DIV) {
        if (temp[f - 1] == 0) {
          res = EILSEQ;
          break;
        }
        temp[f - 2] = temp[f - 2] / temp[f - 1];
        f--;
      } else if (output[k] == POW) {
        temp[f - 2] = pow(temp[f - 2], temp[f - 1]);
        f--;
      } else if (output[k] == MOD) {
        temp[f - 2] = fmod(temp[f - 2], temp[f - 1]);
        f--;
      } else if (output[k] == COS) {
        temp[f - 1] = cos(temp[f - 1]);
      } else if (output[k] == TAN) {
        temp[f - 1] = tan(temp[f - 1]);
      } else if (output[k] == SIN) {
        temp[f - 1] = sin(temp[f - 1]);
      } else if (output[k] == ASIN) {
        if (temp[f - 1] > 1 || temp[f - 1] < -1) {
          res = EILSEQ;
          break;
        }
        temp[f - 1] = asin(temp[f - 1]);
      } else if (output[k] == ACOS) {
        if (temp[f - 1] > 1 || temp[f - 1] < -1) {
          res = EILSEQ;
          break;
        }
        temp[f - 1] = acos(temp[f - 1]);
      } else if (output[k] == ATAN) {
        temp[f - 1] = atan(temp[f - 1]);
      } else if (output[k] == SQRT) {
        if (temp[f - 1] < 0) {
          res = EILSEQ;
          break;
        }
        temp[f - 1] = sqrt(temp[f - 1]);
      } else if (output[k] == LN) {
        if (temp[f - 1] < 0) {
          res = EILSEQ;
          break;
        }
        temp[f - 1] = log(temp[f - 1]);
      } else if (output[k] == LOG) {
        if (temp[f - 1] < 0) {
          res = EILSEQ;
          break;
        }
        temp[f - 1] = log10(temp[f - 1]);
      }
      k++;
    }
    if (res != EILSEQ) res = temp[0];
  }
  return res;
}

void s21::POLKA::set_num(double num, int i) {
  if (i != 0) number[i - 1] = num;
}

void s21::POLKA::set_func(double fun, int i) { input[i] = fun; }

void s21::POLKA::func_test(const int *in) {
  int i = 0;
  while (in[i] != 0) {
    input[i] = in[i];
    i++;
  }
}

void s21::POLKA::num_test(const double *in) {
  int i = 0;
  while (in[i] != 0) {
    number[i] = in[i];
    i++;
  }
}

void s21::POLKA::set_x(double n) { x = n; }
