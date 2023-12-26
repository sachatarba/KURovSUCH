#include "./ui/main-window.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
//  if (argc == 4) {
    std::string config_file = "/home/sachatarba/course/bmstu-cg-term-paper-main/app/meta/sphere02.txt";
    std::string engine_file = "/home/sachatarba/course/bmstu-cg-term-paper-main/app/meta/coefs.txt";

//    if (!strcmp(argv[1], "-window")) {
      QApplication a(argc, argv);
      MainWindow w(nullptr, config_file, engine_file);
      w.show();
      a.exec();
//      return EXIT_SUCCESS;
//    } else if (!strcmp(argv[1], "-silent")) {
//      SilentMode a(config_file, engine_file);
//      a.excecute();
//      return EXIT_SUCCESS;
//    } else {
//      std::cout << "invalid mode argument.";
//      return EXIT_FAILURE;
//    }
//  } else {
//    std::cout << "invalid arguments count.";
//    return EXIT_FAILURE;
//  }
//  return EXIT_SUCCESS;
}
