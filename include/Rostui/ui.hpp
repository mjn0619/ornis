#ifndef UI_H_
#define UI_H_

#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#include "ftxui/component/component.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

enum class CurrentWindow {
  MONITORS = 0,
  OPTIONS = 1,
  HELP = 2,
};

class Ui {
public:
  Ui();
  ~Ui();

  void setValues(const std::map<std::string, std::vector<std::string>> values);

  // Re-draw flag, for updated value, or changed console dimensions
  std::atomic_bool redraw_flag_;

  std::atomic_bool screen_loop_;

private:
  // Stores the width of the terminal at startup. Used for scaling the ui
  uint term_width_;

  CurrentWindow current_window_;

  void renderMonitors();
  void renderOptions();
  void refreshUi();
  void signalHandler(int sig);

  // Primary loop function
  void spin();

  std::thread *content_thread_;
  std::thread *screen_thread_;

  std::map<std::string, std::vector<std::string>> object_information_;

  ftxui::ScreenInteractive screen_ = ftxui::ScreenInteractive::TerminalOutput();

  std::mutex data_mutex_;
};

#endif // UI_H_
