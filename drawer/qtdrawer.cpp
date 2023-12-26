#include "qtdrawer.h"

#include <QPainter>
#include <QString>
#include <QVector4D>

#include <QDebug>

#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std::chrono;

inline QRgb getColor(const QRgb rgb, const float i) {
  QColor col(rgb);

  int R, G, B;

  col.getRgb(&R, &G, &B);

  R *= i;
  G *= i;
  B *= i;

  if (R > 255) {
    R = 255;
  } else if (R < 0) {
    R = 0;
  }

  if (G > 255) {
    G = 255;
  } else if (G < 0) {
    G = 0;
  }

  if (B > 255) {
    B = 255;
  } else if (B < 0) {
    B = 0;
  }

  col.setRgb(R, G, B);
  return col.rgba();
}

QTDrawer::QTDrawer() {
  _camera = Camera();
  _lights.push_back(LightSource(QVector3D{200, 1000, 500}, 2500));
}

void QTDrawer::setScene(QGraphicsScene *scene) {
  this->_scene = scene;

  _img = QImage(1272, 782, QImage::Format_ARGB32);
  _img.fill(QColor::fromRgb(105, 105, 105));
}

void QTDrawer::clear() {
  _img.fill(QColor::fromRgb(105, 105, 105));
  if (_scene != nullptr) {
    _scene->clear();
  }
}

void QTDrawer::show() {
  QPixmap pixmap = QPixmap::fromImage(_img);
  _scene->clear();
  _scene->addPixmap(pixmap);
}

void QTDrawer::exportFrame(std::string file_name) {
  QString filepath = QString::fromUtf8(file_name.data(), int(file_name.size()));
  _img.save(filepath);
}

std::vector<QVector3D> generateWaveSurfacePoints(float startX, float endX, float startZ, float endZ, float spacing, float time) {
  std::vector<QVector3D> points;
  for (float y = startX; y <= endX; y += spacing) {
    for (float x = startZ; x <= endZ; x += spacing) {
      // cheta ne work
      float z = 10 * std::sin(0.5f * y + 0.3f * x + time) + 20 * std::sin(0.2f * y - 0.1f * x + time);
      points.push_back(QVector3D(x, y, z));
    }
}

  return points;
}

void drawWaveSurfacePoints(QImage& img, const std::vector<QVector3D>& points, float viewportWidth, float viewportHeight) {
  QPainter painter(&img);
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::black);
  for(const auto& point : points) {
    int x = static_cast<int>((point.x() + 1.0) * 0.5 * viewportWidth);
    int y = static_cast<int>((1.0 - (point.y() + 1.0) * 0.5) * viewportHeight);
    painter.drawPoint(x, y);
  }

  painter.end();
}

QVector3D getPolygonNormal(const QVector3D &p1, const QVector3D &p2,
                                 const QVector3D &p3) {
  QVector3D sum = p1 + p2 + p3;
  QVector3D p_cent = {sum.x() / 3, sum.y() / 3, sum.z() / 3};

  QVector3D a = p1 - p2;
  QVector3D b = p1 - p3;

  QVector3D nrm = QVector3D::normal(a, b);
  QVector3D v = p_cent;
  float prod = QVector3D::dotProduct(v, nrm);

  if (prod < 0) {
    nrm = -nrm;
  }
  return nrm;
}


float ticks = 0;


std::pair<std::vector<QVector3D>, std::vector<QVector3D>> createGrid(int countPoints) {
    const float NEGATIVE_BORDER = -500.f;
    const float POSITIVE_BORDER = 500.f;

    std::vector<QVector3D> vertices;
    std::vector<QVector3D> indices;

    for (int z = 0; z < countPoints; z++) {
        float t = NEGATIVE_BORDER + (POSITIVE_BORDER - NEGATIVE_BORDER) * float(z) / (countPoints - 1);
        for (int x = 0; x < countPoints; x++) {
            float s = NEGATIVE_BORDER + (POSITIVE_BORDER - NEGATIVE_BORDER) * float(x) / (countPoints - 1);
            vertices.push_back(QVector3D(s, 1.0f, t));

            if (x < countPoints - 1 && z < countPoints - 1) {
                int i = x + z * countPoints;
                indices.push_back(QVector3D(i, i + 1, i + countPoints));
                indices.push_back(QVector3D(i + countPoints, i + 1, i + countPoints + 1));
            }
        }
    }

    return {vertices, indices};
}

void QTDrawer::drawModel(Drop &drop, QColor color) {
  if (_scene != nullptr) {
    _scene->clear();
  }


//  auto now = std::chrono::system_clock::now();
//  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
//  float milliseconds = static_cast<float>(ms);
//  auto points = generateWaveSurfacePoints(-1000, 1000, -500, 100, 2, ticks++);
//    std::vector<QVector3D> polygons;
//    auto[verts, inds] = createGrid(1000);
//    for (auto ind: inds) {
//        polygons.
//    }
  //drawWaveSurfacePoints(_img, points, width(), height());
  std::size_t n_polys = drop.nPolygons();

  std::size_t i, j;
  for (i = 0; i < n_polys; i++) {
    auto poly = drop.polygon(i);

    QVector3D screen_coords[3];

    for (j = 0; j < 3; j++) {

      if (QVector3D::dotProduct(drop.normal(i), _camera.vecView()) <= 0) {
        break;
      }
      QVector3D tmp = _camera.projectToPlane(poly[j]);
      QVector3D v =
          QVector3D{tmp.x() / 2 / _camera.width() * _img.width(),
                    tmp.y() / 2 / _camera.height() * _img.height(), tmp.z()};
      screen_coords[j] = v;
    }

    QVector3D sum = poly[0] + poly[1] + poly[2];
    QVector3D p_cent = {sum.x() / 3, sum.y() / 3, sum.z() / 3};

    ShadeWhole(screen_coords[0], screen_coords[1], screen_coords[2], p_cent,
               drop.normal(i), color);
  }


//  for (auto i = 0; i < points.size(); i += 3) {
//          QVector3D sum = points[i]+ points[i + 1]+ points[i + 2];
//          QVector3D p_cent = {sum.x() / 3, sum.y() / 3, sum.z() / 3};
//      ShadeWhole(points[i], points[i + 1], points[i + 2], p_cent, drop.normal(0), color);
//  }


//    std::size_t n_polys = drop.nPolygons();

//    std::size_t i, j;
//    for (i = 0; i < points.size(); i += 3) {
//     auto poly = drop.polygon(i);
//      auto poly = QVector(points[i], points[i+1], points[i+2]);
//      QVector3D screen_coords[3];

//      for (j = 0; j < 3; j++) {

//        if (QVector3D::dotProduct(drop.normal(i), _camera.vecView()) <= 0) {
//          break;
//        }
//        QVector3D tmp = _camera.projectToPlane(points[i + j]);
//        QVector3D v =
//            QVector3D{tmp.x() / 2 / _camera.width() * _img.width(),
//                      tmp.y() / 2 / _camera.height() * _img.height(), tmp.z()};
//        screen_coords[j] = v;
//      }

//      QVector3D sum = points[i] + points[i + 1] + points[i + 2];
//      QVector3D p_cent = {sum.x() / 3, sum.y() / 3, sum.z() / 3};

//      ShadeWhole(screen_coords[0], screen_coords[1], screen_coords[2], p_cent, getPolygonNormal(screen_coords[0], screen_coords[1], screen_coords[2]), color);
    //}
}

void QTDrawer::ShadeWhole(QVector3D p1, QVector3D p2, QVector3D p3,
                          QVector3D center, QVector3D norm, QColor color) {
  QPainter p(&_img);

  QPolygon qp;
  qp << p1.toPoint() << p2.toPoint() << p3.toPoint();

  double v_prod = getWholeIntensity(center, norm);
  QColor p_color;
  if (v_prod == -1) {
    p_color = color;
  } else {
    p_color = getColor(color.rgba(), v_prod);
  }
  p.setBrush(p_color);
  p.setPen(p_color);
  p.drawPolygon(qp);
}

QVector3D reflect(QVector3D reflectDir, QVector3D norm) {
  return 2.f * QVector3D::dotProduct(reflectDir, norm) * norm - reflectDir;
}

float QTDrawer::getWholeIntensity(QVector3D point, QVector3D normal) {
  float wh_intensity = 0;
  float cur_intensity = 0;

  std::size_t lights_n = _lights.size();
  for (std::size_t i = 0; i < lights_n; i++) {
    cur_intensity = 0;
    LightSource ls = getLight(i);
    QVector3D dir = point - ls.position();

    cur_intensity +=
        (dir.x() * normal.x() + dir.y() * normal.y() + dir.x() * normal.z()) /
        pow(dir.length(), 2.0);
    cur_intensity *= ls.intensity() * _light_reflect;

    cur_intensity +=
        _spec_light *
        pow(QVector3D::dotProduct(normal, reflect(dir, normal).normalized()),
            1.33);

    cur_intensity = fmax(0.0, cur_intensity);
    cur_intensity = fmin(1.0, cur_intensity);

    cur_intensity = _bg_light + cur_intensity * (1 - _bg_light);
    wh_intensity += cur_intensity;
  }
  if (wh_intensity == 0) {
    return _bg_light;
  } else {
    wh_intensity /= lights_n;
  }
  return wh_intensity;
}
