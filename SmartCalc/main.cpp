#include <QApplication>

#include "Controller.h"
#include "mainwindow.h"
#include "polka.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
