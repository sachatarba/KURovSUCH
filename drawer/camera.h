#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>

class Camera {
public:
  Camera();
  QVector3D rotate(double angle, QVector3D vec_for, QVector3D vec_who);
  QVector3D projectToPlane(QVector3D point);

  int width() { return _w; }
  int height() { return _h; }

  void setWidth(int width);
  void setHeight(int height);

  void setCameraPos(QVector3D &, QVector3D &, QVector3D &);
  QVector3D eye() { return _eye; }
  QVector3D vecView() { return _vec_view; }
  QVector3D vecUp() { return _vec_up; }
  QVector3D vecRight() { return _vec_right; }

private:
  int _w = 739, _h = 453;

  QVector3D _eye, _vec_view, _vec_up, _vec_right;
  QVector3D _top_left, _btm_left;
  QVector3D _top_right, _btm_right;
};

#endif // CAMERA_H
