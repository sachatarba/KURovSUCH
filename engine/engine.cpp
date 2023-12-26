#include "engine.h"

#include <math.h>
#include <sstream>

Engine::Engine(std::string config_file) {
  std::ifstream stream;
  stream.open(config_file);

  if (!stream.is_open()) {
    throw std::exception();
  }

  std::string line;
  std::getline(stream, line);
  std::stringstream str(line);

  str >> _attraction_coef >> _viscosity >> _collision_coef;
}

void Engine::changeCurrentState(Drop &drop) {
  std::size_t n_points = drop.nPoints();
  float tau = 0.3;

  for (size_t i = 0; i < n_points; i++) {
    QVector3D new_point = drop.point(i) + tau * drop.velocity(i);
    drop.setPoint(new_point, i);
  }

  for (size_t i = 0; i < n_points; i++) {
    QVector3D force = QVector3D{0, 0, 0};
    for (std::size_t j = 0; j < n_points; j++) {
      force = force + attrtactionForce(drop.point(i), drop.point(j));
    }
    for (std::size_t j = 0; j < n_points; j++) {
      force = force + repulsionForce(drop.point(i), drop.point(j), drop.mass(i),
                                     drop.mass(j));
    }
    QVector3D v = drop.velocity(i);
    force = force + viscocityForce(v);
    force = force + collision(drop.point(i));
    force = force + gravityForce(drop.mass(i));
    force += externalForce(drop.mass(i));

    QVector3D new_velocity = v + tau * force;
    drop.setVelocity(new_velocity, i);
  }
  drop.calculateNormals();
  drop.calculateMassCenter();
}

QVector3D Engine::attrtactionForce(const QVector3D &point_i,
                                   const QVector3D &point_j) {
  if (point_i == point_j) {
    return QVector3D{0, 0, 0};
  }
  QVector3D force = _attraction_coef * (point_i - point_j);
  return force;
}

QVector3D Engine::repulsionForce(const QVector3D &point_i,
                                 const QVector3D &point_j, const float &m_i,
                                 const float &m_j) {
  if (point_i == point_j) {
    return QVector3D{0, 0, 0};
  }
  QVector3D force =
      m_i * m_j * (point_i - point_j) / pow((point_i - point_j).length(), 1.5);
  return force;
}

QVector3D Engine::gravityForce(const float &m) {
  float term = -m * GRAVITY;
  QVector3D force{0, 0, term};
  return force;
}

QVector3D Engine::externalForce(const float &m) {
//  float term = m * GRAVITY;
    QVector3D force = m * QVector3D{5, 0, 0};
  return force;
}

QVector3D Engine::viscocityForce(QVector3D &velocity) {
  QVector3D force = _viscosity * velocity;
  return force;
}

QVector3D Engine::collision(QVector3D &point) {
  QVector3D force;

  if (point.z() > planeZ) {
    force = QVector3D{0, 0, 0};
  } else {
    force = QVector3D{0, 0, _collision_coef};
  }
  return force;
}
