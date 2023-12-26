#ifndef SILENTMODE_H
#define SILENTMODE_H

#include <QThread>
#include <QTimer>
#include <string>

#include "../drawer/qtdrawer.h"
#include "../engine/engine.h"

class SilentMode {
public:
  SilentMode(std::string config_file = "../../meta/drop-init.txt",
             std::string engine_file = "../../meta/coefs.txt");
  virtual ~SilentMode(){};

  void excecute();

private:
  std::chrono::steady_clock::time_point start_t;
  std::string frame_folder_path = "../../meta/frames";
  int screenshot_num = 0;
  QTDrawer drawer;
  Drop drop;
  Engine animator;
};

#endif // SILENTMODE_H
