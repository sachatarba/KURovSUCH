#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <QMatrix4x4>

#include "../drop/drop.h"

#define GRAVITY 9.8

class Engine {
public:
  Engine() = default;
  Engine(std::string config_file);
  void changeCurrentState(Drop &drop);

private:
  float planeZ = -500;

  QVector3D attrtactionForce(const QVector3D &, const QVector3D &);
  QVector3D repulsionForce(const QVector3D &, const QVector3D &, const float &,
                           const float &);
  QVector3D gravityForce(const float &);
  QVector3D viscocityForce(QVector3D &);
  QVector3D collision(QVector3D &);
  QVector3D externalForce(const float &m);

  QVector3D _externalForce;
  float _attraction_coef;
  float _viscosity;
  float _collision_coef;
};

#endif // ANIMATOR_H
