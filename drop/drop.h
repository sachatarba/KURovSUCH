#ifndef DROP_H
#define DROP_H

#include "../primitive/polygon.h"

#include <fstream>
#include <utility>

class Drop {
public:
  Drop(std::string &fliename);

  // физика капли
  void calculateMassCenter();
  QVector3D massCenter() { return _mass_center; };
  float mass(const std::size_t &inx) { return _masses.at(inx); }
  QVector3D velocity(const std::size_t &inx) { return _velocities.at(inx); }
  void setVelocity(QVector3D v, const std::size_t &inx);

  // точки
  std::size_t nPoints() { return _points.size(); };
  QVector3D &point(const std::size_t &inx) { return _points.at(inx); }
  void setPoint(QVector3D new_point, const std::size_t &inx);

  // полигоны
  std::size_t nPolygons() { return _polygons.size(); }
  std::vector<QVector3D> polygon(const std::size_t &);

  // нормали
  std::size_t nNormals() { return _polygon_normals.size(); }
  QVector3D normal(const std::size_t &inx) { return _polygon_normals.at(inx); }
  QVector3D vertexNormal(const std::size_t &, const std::size_t &);
  void calculateNormals();

  QVector3D getPolygonNormal(const QVector3D &, const QVector3D &,
                             const QVector3D &);

private:
  std::vector<QVector3D> _points;
  std::vector<std::vector<std::pair<std::size_t, std::size_t>>> _polygons;
  std::vector<QVector3D> _polygon_normals;
  std::vector<QVector3D> _vert_normals;

  std::vector<QVector3D> _velocities;
  std::vector<float> _masses;

  QVector3D _mass_center;
};

#endif // DROP_H
