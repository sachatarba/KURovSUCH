#include "drop.h"

#include <iostream>
#include <sstream>

#include <QDebug>
#include <chrono>

Drop::Drop(std::string &fliename) {
  std::ifstream stream;
  stream.open(fliename);
  float mass = 0;

  if (!stream.is_open()) {
    throw std::exception();
  }
  std::vector<QVector3D> points;
  std::string line;
  while (!stream.eof()) {
    std::getline(stream, line);

    std::stringstream str(line);

    std::string type;
    str >> type;
    if (type == "v") {
      QVector3D point;
      float x, y, z;
      str >> x >> y >> z;

      point.setX(x);
      point.setY(y);
      point.setZ(z);

      _points.push_back(point);
    }
    if (type == "n") {
      QVector3D norm;
      float x, y, z;
      str >> x >> y >> z;

      norm.setX(x);
      norm.setY(y);
      norm.setZ(z);
      _vert_normals.push_back(norm);
    }
    if (type == "m") {
      str >> mass;
    }
    if (type == "p") {
      std::vector<std::pair<std::size_t, std::size_t>> poly;
      std::string polystr;

      while (std::getline(str, polystr, ' ')) {
        if (polystr.length() == 0)
          continue;
        if (polystr[0] == ' ')
          polystr.erase(0, 1);

        std::stringstream ipoly(polystr);
        std::size_t tmp[2];
        std::string item;
        for (size_t i = 0; std::getline(ipoly, item, '/'); i++) {
          std::stringstream num(item);
          num >> tmp[i];
        }
        auto pair = std::make_pair(tmp[0], tmp[1]);
        poly.push_back(pair);
      }
      _polygons.push_back(poly);
    }
  }

  _masses.resize(_points.size());
  for (std::size_t i = 0; i < _masses.size(); i++) {
    _masses[i] = mass;
  }
  _velocities.resize(_points.size());
  for (std::size_t i = 0; i < _velocities.size(); i++) {
    _velocities[i] = QVector3D{0, 0, 0};
  }

  calculateMassCenter();
  calculateNormals();
}

void Drop::calculateMassCenter() {
  QVector3D cent{0.f, 0.f, 0.f};
  for (std::size_t i = 0; i < _points.size(); i++) {
    cent += _points[i];
  }
  cent /= _points.size();
  _mass_center = cent;
}

void Drop::setPoint(QVector3D new_point, const std::size_t &inx) {
  _points[inx] = new_point;
}

void Drop::setVelocity(QVector3D v, const std::size_t &inx) {
  _velocities[inx] = v;
}

std::vector<QVector3D> Drop::polygon(const std::size_t &inx) {
  std::vector<QVector3D> polygon;
  std::size_t size = _polygons[inx].size();

  for (std::size_t i = 0; i < size; i++) {
    polygon.push_back(_points[_polygons[inx][i].first]);
  }

  return polygon;
}

QVector3D Drop::vertexNormal(const std::size_t &poly,
                             const std::size_t &vertex) {
  return _vert_normals[_polygons[poly][vertex].second].normalized();
}

QVector3D Drop::getPolygonNormal(const QVector3D &p1, const QVector3D &p2,
                                 const QVector3D &p3) {
  QVector3D sum = p1 + p2 + p3;
  QVector3D p_cent = {sum.x() / 3, sum.y() / 3, sum.z() / 3};

  QVector3D a = p1 - p2;
  QVector3D b = p1 - p3;

  QVector3D nrm = QVector3D::normal(a, b);
  QVector3D v = p_cent - _mass_center;
  float prod = QVector3D::dotProduct(v, nrm);

  if (prod < 0) {
    nrm = -nrm;
  }
  return nrm;
}

void Drop::calculateNormals() {
  _polygon_normals.clear();
  std::size_t n = _polygons.size();
  for (std::size_t i = 0; i < n; i++) {
    std::vector<QVector3D> p = polygon(i);
    QVector3D nrm = getPolygonNormal(p[0], p[1], p[2]);
    _polygon_normals.push_back(nrm);
  }
}
