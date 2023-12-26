#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <QColor>
#include <QVector3D>

#define LIGHT_REFLECT 0.4
#define BG_LIGHT 0.3
#define SPEC_LIGHT 0.3

class LightSource {
public:
  LightSource(const QVector3D pos, const float intens);

  QVector3D position() { return _position; }
  void setPosition(const QVector3D new_pos) { _position = new_pos; }

  float intensity() { return _intensity; };
  void setIntensity(float new_intens) { _intensity = new_intens; }

private:
  QVector3D _position;
  float _intensity;
};

#endif // LIGHTSOURCE_H
