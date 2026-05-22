#include "mainwindow.h"

#include "polka.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  view = new s21::Controller();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on__0_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "0");
  digit('0');
  symbols++;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__1_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "1");
  symbols++;
  digit('1');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__2_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "2");
  symbols++;
  digit('2');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__3_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "3");
  symbols++;
  digit('3');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__4_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "4");
  symbols++;
  digit('4');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__5_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "5");
  symbols++;
  digit('5');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__6_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "6");
  symbols++;
  digit('6');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__7_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "7");
  symbols++;
  digit('7');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__8_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "8");
  symbols++;
  digit('8');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__9_clicked() {
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "9");
  symbols++;
  digit('9');
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
}

void MainWindow::on__BEG_clicked() {
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "(");
  symbols++;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  //    view->function(in[i-2]);
  view->function(in[i - 1]);
}

void MainWindow::on__END_clicked() {
  in[i] = s21::END;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + ")");
  symbols++;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  //    view->function(in[i-2]);
  view->function(in[i - 1]);
}

void MainWindow::on__ACOS_clicked() {
  in[i] = s21::ACOS;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "acos(");
  symbols += 5;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__ASIN_clicked() {
  in[i] = s21::ASIN;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "asin(");
  symbols += 5;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__ATAN_clicked() {
  in[i] = s21::ATAN;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "atan(");
  symbols += 5;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__COS_clicked() {
  in[i] = s21::COS;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "cos(");
  symbols += 4;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__DIV_clicked() {
  QString new_label = ui->input->text();
  if (new_label[new_label.size() - 1] != '/') {
    in[i] = s21::DIV;
    i++;
    ui->input->setText(new_label + "/");
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
    view->function(in[i - 1]);
  }
}

void MainWindow::on__LG_clicked() {
  in[i] = s21::LOG;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "lg(");
  symbols += 3;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__LN_clicked() {
  in[i] = s21::LN;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "ln(");
  symbols += 3;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__MOD_clicked() {
  in[i] = s21::MOD;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "mod(");
  symbols += 4;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__MUL_clicked() {
  QString new_label = ui->input->text();
  if (new_label[new_label.size() - 1] != '*') {
    in[i] = s21::MUL;
    i++;
    ui->input->setText(new_label + "*");
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
    view->function(in[i - 1]);
  }
}

void MainWindow::on__POW_clicked() {
  if (in[i - 1] != s21::POW) {
    in[i] = s21::POW;
    i++;
    QString new_label = ui->input->text();
    ui->input->setText(new_label + "^");
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
    view->function(in[i - 1]);
  }
}

void MainWindow::on__SIN_clicked() {
  in[i] = s21::SIN;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "sin(");
  symbols += 4;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__SQRT_clicked() {
  in[i] = s21::SQRT;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "sqrt(");
  symbols += 5;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on__SUB_clicked() {
  QString new_label = ui->input->text();
  if (str != nullptr && str[str.size() - 1] == 'e') {
    ui->input->setText(new_label + "-");
    str += '-';
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
  } else if (i == 0 && str == nullptr) {
    num[1] = 0;
    view->function(s21::NUM);
    in[i] = s21::SUB;
    view->function(s21::SUB);
    i++;
    symbols++;
    ui->input->setText(new_label + "-");
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
  } else if (new_label[new_label.size() - 1] != '-') {
    in[i] = s21::SUB;
    i++;
    ui->input->setText(new_label + "-");
    symbols++;
    if (in[i - 1] == s21::BEG) {
      num[1] = 0;
      view->function(s21::NUM);
    }
    view->function(in[i - 1]);
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
  }
}

void MainWindow::on__SUM_clicked() {
  QString new_label = ui->input->text();
  if (new_label[new_label.size() - 1] != '+') {
    in[i] = s21::SUM;
    i++;
    ui->input->setText(new_label + "+");
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
    view->function(in[i - 1]);
  }
}

void MainWindow::on__TAN_clicked() {
  in[i] = s21::TAN;
  i++;
  in[i] = s21::BEG;
  i++;
  QString new_label = ui->input->text();
  ui->input->setText(new_label + "tan(");
  symbols += 4;
  ui->symbols->setText(QString::number(symbols));
  if (symbols > 255) Error();
  view->function(in[i - 2]);
  view->function(in[i - 1]);
}

void MainWindow::on_clean_all_clicked() {
  QString new_label;
  new_label = nullptr;
  ui->input->setText(new_label);
  symbols = 0;
  ui->symbols->setText(QString::number(symbols));
  i = 0;
  str = nullptr;
  ui->result->setText("=0");
  delete view;
  view = new s21::Controller();
  ui->grap->QCustomPlot::clearGraphs();
}

void MainWindow::on_EQUALLY_clicked() {
  in[i] = s21::EQUALLY;
  num[0] = str.toDouble();
  str = nullptr;
  view->set_number(num[0]);
  view->function(in[i]);
  view->new_x(ui->inout_X->text().toDouble());
  res = view->equally();
  if (res != EILSEQ) {
    ui->result->setText("=" + QString::number(res));
  } else {
    ui->result->setText("Error");
  }
  i = 0;
  delete view;
  view = new s21::Controller();
}

void MainWindow::Error() {
  i = 0;
  ui->input->setText("Error: too many characters");
  symbols = 0;
}

void MainWindow::digit(char ch) {
  if (in[i] != s21::NUM) {
    num[0] = str.toDouble();
    str = nullptr;
    in[i] = s21::NUM;
    view->set_number(num[0]);
    view->function(s21::NUM);
    str += ch;
  } else {
    str += ch;
  }
  if (num[1] == 0) {
    view->set_number(0);
    num[1] = 1;
  }
}

void MainWindow::on__E_clicked() {
  if (str == nullptr)
    ;
  //    ui->result->setText("Error: exp");
  else if (str[str.size() - 1] != 'e') {
    QString new_label = ui->input->text();
    ui->input->setText(new_label + "e");
    str += 'e';
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
  }
}

void MainWindow::on__point_clicked() {
  if (str == nullptr)
    ;
  //    ui->result->setText("Error: point");
  else if (str[str.size() - 1] != '.') {
    QString new_label = ui->input->text();
    ui->input->setText(new_label + ".");
    str += '.';
    symbols++;
    ui->symbols->setText(QString::number(symbols));
    if (symbols > 255) Error();
  }
}

void MainWindow::on__X_clicked() {
  if (in[i] != s21::X) {
    QString new_label = ui->input->text();
    ui->input->setText(new_label + "x");
    view->function(s21::X);
  }
}

void MainWindow::on_pushButton_clicked() {
  ui->grap->QCustomPlot::clearGraphs();
  QString new_label;
  if (str != nullptr) {
    num[0] = str.toDouble();
    str = nullptr;
    view->set_number(num[0]);
    view->function(in[i]);
  }
  view->new_x(ui->inout_X_0->text().toDouble());
  in[i] = s21::EQUALLY;
  double output = view->equally();

  if (output == EILSEQ) {
    ui->result->setText("Try again");
  } else {
    double h, X;
    QVector<double> x, y;
    h = 0.01;
    double X_0 = ui->inout_X_0->text().toDouble();
    double X_1 = ui->inout_X_1->text().toDouble();
    double Y_0 = ui->inout_Y_0->text().toDouble();
    double Y_1 = ui->inout_Y_1->text().toDouble();
    if (X_0 != X_1 && Y_0 != Y_1) {
      ui->grap->xAxis->setRange(X_0, X_1);
      ui->grap->yAxis->setRange(Y_0, Y_1);
      for (X = X_0; X <= X_1; X += h) {
        x.push_back(X);
        view->new_x(X);
        y.push_back(view->equally());
      }
      delete view;
      view = new s21::Controller();
      ui->grap->addGraph();
      ui->grap->graph(0)->addData(x, y);
      ui->grap->replot();
      x.clear();
      y.clear();
      x.squeeze();
      y.squeeze();
    }
  }
}
