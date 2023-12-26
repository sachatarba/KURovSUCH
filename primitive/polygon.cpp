#include "polygon.h"

#include <cmath>

#include <QDebug>

Polygon::Polygon(std::vector<QVector3D> points, QVector3D normal)
    : _points(points), _normal(normal) {}

Polygon::_iterator Polygon::begin() { return _points.begin(); }

Polygon::_iterator Polygon::end() { return _points.end(); }

Polygon::_const_iterator Polygon::cbegin() { return _points.cbegin(); }

Polygon::_const_iterator Polygon::cend() { return _points.cend(); }

Polygon::_const_iterator Polygon::begin() const { return _points.cbegin(); }

Polygon::_const_iterator Polygon::end() const { return _points.cend(); }

Polygon::_const_iterator Polygon::cbegin() const { return _points.cbegin(); }

Polygon::_const_iterator Polygon::cend() const { return _points.cend(); }

const QVector3D Polygon::normal() { return _normal; }

void Polygon::find_normal(QVector3D center) {
  float sum_x = _points[0].x() + _points[1].x() + _points[2].x();
  float sum_y = _points[0].y() + _points[1].y() + _points[2].y();
  float sum_z = _points[0].z() + _points[1].z() + _points[2].z();
  QVector3D poly_center = {sum_x / 3, sum_y / 3, sum_z / 3};

  QVector3D a = _points[0] - _points[1];
  QVector3D b = _points[0] - _points[2];

  _normal = QVector3D::normal(a, b);

  QVector3D v = poly_center - center;
  float prod = QVector3D::dotProduct(v, _normal);

  if (prod < 0) {
    _normal = -_normal;
  }
}
