#include "camera.h"
#include <cmath>

Camera::Camera() {
  _eye = QVector3D{-100, 0, 100};
  _vec_view = QVector3D{-100, 0, 0};
  _vec_up = QVector3D{0, 0, 1};

  setCameraPos(_eye, _vec_view, _vec_up);
}

QVector3D Camera::rotate(double angle, QVector3D vec_for, QVector3D vec_who) {
  qreal cs = cos(angle);
  qreal sn = sin(angle);
  qreal omcs = 1.0 - cs;

  qreal mXX = cs + omcs * vec_for.x() * vec_for.x();
  qreal mXY = omcs * vec_for.x() * vec_for.y() - sn * vec_for.z();
  qreal mXZ = omcs * vec_for.x() * vec_for.z() + sn * vec_for.y();

  qreal mYX = omcs * vec_for.x() * vec_for.y() + sn * vec_for.z();
  qreal mYY = cs + omcs * vec_for.y() * vec_for.y();
  qreal mYZ = omcs * vec_for.z() * vec_for.y() - sn * vec_for.x();

  qreal mZX = omcs * vec_for.x() * vec_for.z() - sn * vec_for.y();
  qreal mZY = omcs * vec_for.z() * vec_for.y() + sn * vec_for.x();
  qreal mZZ = cs + omcs * vec_for.z() * vec_for.z();

  QVector3D res;
  res.setX(mXX * vec_who.x() + mXY * vec_who.y() + mXZ * vec_who.z());
  res.setY(mYX * vec_who.x() + mYY * vec_who.y() + mYZ * vec_who.z());
  res.setZ(mZX * vec_who.x() + mZY * vec_who.y() + mZZ * vec_who.z());

  return res;
}

QVector3D Camera::projectToPlane(QVector3D point) {
  double x, y, z;
  point = point - _top_left;

  x = QVector3D::dotProduct(point, _vec_right);
  y = (-1) * QVector3D::dotProduct(point, _vec_up);
  z = QVector3D::dotProduct(point, _eye);

  return QVector3D(x, y, z);
}

void Camera::setWidth(int width) {
  _w = width;
  _top_left = _eye - 0.5 * _w * _vec_right;
  _btm_left = _top_left - 0.5 * _h * _vec_up;

  _top_left = _top_left + 0.5 * _h * _vec_up;
  _top_right = _eye + 0.5 * _w * _vec_right;

  _btm_right = _top_right - 0.5 * _h * _vec_up;
  _top_right = _top_right + 0.5 * _h * _vec_up;
}

void Camera::setHeight(int height) {
  _h = height;
  _top_left = _eye - 0.5 * _w * _vec_right;
  _btm_left = _top_left - 0.5 * _h * _vec_up;

  _top_left = _top_left + 0.5 * _h * _vec_up;
  _top_right = _eye + 0.5 * _w * _vec_right;

  _btm_right = _top_right - 0.5 * _h * _vec_up;
  _top_right = _top_right + 0.5 * _h * _vec_up;
}

void Camera::setCameraPos(QVector3D &eye, QVector3D &vec_view,
                          QVector3D &vec_up) {
  _eye = eye.normalized();
  _vec_view = vec_view.normalized();
  _vec_up = vec_up.normalized();

  _vec_right = QVector3D::crossProduct(_vec_view, _vec_up);

  _top_left = _eye - 0.5 * _w * _vec_right;
  _btm_left = _top_left - 0.5 * _h * _vec_up;

  _top_left = _top_left + 0.5 * _h * _vec_up;
  _top_right = _eye + 0.5 * _w * _vec_right;

  _btm_right = _top_right - 0.5 * _h * _vec_up;
  _top_right = _top_right + 0.5 * _h * _vec_up;
}
