#include "system_manager.h"

SystemManager sysMananger;

void setup() {
  sysMananger.systemInit();
}

void loop() {
  sysMananger.systemLoop();
}
