#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Controller.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  void on__0_clicked();

  void on__1_clicked();

  void on__2_clicked();

  void on__3_clicked();

  void on__4_clicked();

  void on__5_clicked();

  void on__6_clicked();

  void on__7_clicked();

  void on__8_clicked();

  void on__9_clicked();

  void on__BEG_clicked();

  void on__END_clicked();

  void on__ACOS_clicked();

  void on__ASIN_clicked();

  void on__ATAN_clicked();

  void on__COS_clicked();

  void on__DIV_clicked();

  void on__LG_clicked();

  void on__LN_clicked();

  void on__MOD_clicked();

  void on__MUL_clicked();

  void on__POW_clicked();

  void on__SIN_clicked();

  void on__SQRT_clicked();

  void on__SUB_clicked();

  void on__SUM_clicked();

  void on__TAN_clicked();

  void on_clean_all_clicked();

  void on_EQUALLY_clicked();

  void Error();

  void digit(char ch);

  void on__E_clicked();

  void on__point_clicked();

  void on__X_clicked();

  void on_pushButton_clicked();

 private:
  Ui::MainWindow *ui;
  int in[255];
  double num[255];
  int i = 0;
  int symbols = 0;
  QString str;
  double res;
  s21::Controller *view;
  //    s21::POLKA model;
};

#endif  // MAINWINDOW_H
