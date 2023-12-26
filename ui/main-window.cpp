#include "main-window.h"
#include "ui_mainwindow.h"

#include <cmath>

MainWindow::MainWindow(QWidget *parent, std::string config_file,
                       std::string engine_file)
    : QMainWindow(parent), ui(new Ui::MainWindow), drop(config_file) {
  ui->setupUi(this);
  _config_file = config_file;
  animator = Engine(engine_file);

  _scene = new QGraphicsScene();
  ui->graphicsView->setScene(_scene);
  drawer.setScene(_scene);

  QColor color;
  color.setRgb(65, 105, 225);
  drawer.drawModel(drop, color);
  drawer.show();

  QObject::connect(&_timer, &QTimer::timeout, [this]() {
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
                       std::chrono::steady_clock::now() - start_t)
                       .count();
    if (elapsed >= 15) {
      _timer.stop();
    }
    drawer.clear();
    animator.changeCurrentState(drop);
    QColor color;
    color.setRgb(65, 105, 225);
    drawer.drawModel(drop, color);
    drawer.show();
  });
}

MainWindow::~MainWindow() {
  delete ui;
  delete _scene;
}

void MainWindow::on_pushButton_clicked() {
  start_t = std::chrono::steady_clock::now();
  _timer.setInterval(1000 / 24);
  _timer.start();
}

void MainWindow::on_forward_clicked() {
  drawer.setWidth(1.0 / 1.1 * drawer.width());
  drawer.setHeight(1.0 / 1.1 * drawer.height());

  drawer.clear();
  QColor color;
  color.setRgb(65, 105, 225);
  drawer.drawModel(drop, color);
  drawer.show();
}

void MainWindow::on_backward_clicked() {
  drawer.setWidth(1.1 * drawer.width());
  drawer.setHeight(1.1 * drawer.height());

  drawer.clear();
  QColor color;
  color.setRgb(65, 105, 225);
  drawer.drawModel(drop, color);
  drawer.show();
}

void MainWindow::on_checkBox_clicked(bool checked) {
  if (checked) {
    this->resize(1525, 810);
  } else {
    this->resize(1300, 810);
  }
}

void MainWindow::on_pushButton_3_clicked() {
  drawer.clear();
  drop = Drop(_config_file);
  QColor color;
  color.setRgb(65, 105, 225);
  drawer.drawModel(drop, color);
  drawer.show();
}

void MainWindow::on_pushButton_4_clicked() {
  float x = ui->x_light->value();
  float y = ui->y_light->value();
  float z = ui->z_light->value();

  float intensity = ui->light_intens->value();
  LightSource ls = LightSource(QVector3D{x, y, z}, intensity);
  drawer.setLight(ls);

  drawer.clear();
  QColor color;
  color.setRgb(65, 105, 225);
  drawer.drawModel(drop, color);
  drawer.show();
}

void MainWindow::on_pushButton_2_clicked() {
  float d = ui->bg->value();
  float r = ui->diffuse->value();
  float m = ui->reflect->value();

  drawer.setBGLight(d);
  drawer.setReflectLight(r);
  drawer.setSpecLight(m);

  drawer.clear();
  QColor color;
  color.setRgb(65, 105, 225);
  drawer.drawModel(drop, color);
  drawer.show();
}

void MainWindow::on_stop_clicked() {
  if (_timer.isActive()) {
    _timer.stop();
  }
}
