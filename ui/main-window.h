#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

#include <QTimer>

#include <chrono>
#include <filesystem>

#include "../drawer/qtdrawer.h"
#include "../drop/drop.h"
#include "../engine/engine.h"
#include "ui/silent-mode.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr,
             std::string config_file = "../../meta/drop-init.txt",
             std::string engine_file = "../../meta/coefs.txt");
  ~MainWindow();

private slots:
  void on_pushButton_clicked();

  void on_forward_clicked();

  void on_backward_clicked();

  void on_checkBox_clicked(bool checked);

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_2_clicked();

  void on_stop_clicked();

private:
  std::string _config_file;
  std::chrono::steady_clock::time_point start_t;

  Ui::MainWindow *ui;
  QGraphicsScene *_scene;
  QTDrawer drawer;
  Engine animator;
  Drop drop;

  QTimer _timer;
};
#endif // MAINWINDOW_H
