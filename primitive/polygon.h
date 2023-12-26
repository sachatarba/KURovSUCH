#ifndef POLYGON_H
#define POLYGON_H

#include <QVector3D>
#include <vector>

class Polygon {
public:
  using _iterator = std::vector<QVector3D>::iterator;
  using _const_iterator = std::vector<QVector3D>::const_iterator;
  Polygon(std::vector<QVector3D> points, QVector3D normal);

  _iterator begin();
  _iterator end();

  _const_iterator cbegin();
  _const_iterator cend();

  _const_iterator begin() const;
  _const_iterator end() const;

  _const_iterator cbegin() const;
  _const_iterator cend() const;

  const QVector3D normal();

  void find_normal(QVector3D center);

  QVector3D at(std::size_t index) { return _points.at(index); }

private:
  std::vector<QVector3D> _points;
  QVector3D _normal;
};

#endif // POLYGON_H
