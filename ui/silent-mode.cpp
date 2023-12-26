#include "silent-mode.h"
#include <filesystem>

SilentMode::SilentMode(std::string config_file, std::string engine_file)
    : drop(config_file) {
  if (!std::filesystem::create_directories(frame_folder_path)) {
    for (const auto &entry :
         std::filesystem::directory_iterator(frame_folder_path))
      std::filesystem::remove_all(entry.path());
  }
  drawer.setScene();
  animator = Engine(engine_file);
}

void SilentMode::excecute() {
  for (size_t i = 0; i < 350; i++) {
    drawer.clear();
    QColor color;
    color.setRgb(65, 105, 225);
    animator.changeCurrentState(drop);
    drawer.drawModel(drop, color);
    //    drawer.show();

    std::string filepath =
        frame_folder_path + "/frame-" + std::to_string(screenshot_num) + ".png";
    screenshot_num++;
    drawer.exportFrame(filepath);
  }
}
