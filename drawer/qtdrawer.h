#ifndef QTDRAWER_H
#define QTDRAWER_H

#include "../drop/drop.h"
#include "camera.h"
#include "light-source.h"

#define FAULT 400

#include <QColor>
#include <QGraphicsScene>
#include <QImage>

#include <QVector2D>

#include <QMatrix4x4>

class QTDrawer {
public:
  QTDrawer();

  // QT DRAWING METHODS
  void setScene(QGraphicsScene *scene = nullptr);
  void clear();
  void show();
  void exportFrame(std::string file_name);

  // MODEL RELATED
  void drawModel(Drop &drop, QColor color);
  void ShadeWhole(QVector3D p1, QVector3D p2, QVector3D p3, QVector3D center,
                  QVector3D norm, QColor color);
  void shadeInterpolated(QVector3D p1, QVector3D p2, QVector3D p3, QVector3D n1,
                         QVector3D n2, QVector3D n3, QColor color);

  // CAMERA RELATED
  QVector3D eye() { return _camera.eye(); }
  QVector3D vecView() { return _camera.vecView(); }
  QVector3D vecUp() { return _camera.vecUp(); }
  QVector3D vecRight() { return _camera.vecRight(); }

  // LIGHT RELATED
  void setLight(LightSource light) { _lights.push_back(light); };
  LightSource getLight(std::size_t index) { return _lights[index]; }

  void setBGLight(float val) { _bg_light = val; }
  void setReflectLight(float val) { _light_reflect = val; }
  void setSpecLight(float val) { _spec_light = val; }

  int width() { return _camera.width(); }
  int height() { return _camera.height(); }

  void setWidth(int width) { _camera.setWidth(width); };
  void setHeight(int height) { _camera.setHeight(height); };

  QVector3D rotate(double angle, QVector3D vec_for, QVector3D vec_who);

private:
  Camera _camera;
  float getWholeIntensity(QVector3D point, QVector3D normal);

  QImage _img;
  QGraphicsScene *_scene;

  std::vector<LightSource> _lights;

  float _light_reflect = 0.4;
  float _bg_light = 0.6;
  float _spec_light = 0.1;
};

#endif // QTDRAWER_H
