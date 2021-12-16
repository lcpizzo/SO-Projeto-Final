#include "../useHeaders/horizontalScroller.h"

#include <thread>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

void updateWaterLily(HorizontalScroller *waterLily, bool final) {
  // movement
  // if (waterLily->position.x > 0) {

  // }
  if (!final) {
    // printf("final\n");
    waterLily->position.x -= waterLily->movement.x * waterLily->speed.x;
  }
}

void updateWaterLilyRight(HorizontalScroller *waterLily, bool final) {
  if (final) {
    waterLily->position.x += waterLily->movement.x * waterLily->speed.x;
  }
}

void updateVehicle(HorizontalScroller *vehicle, bool final) {
  // movement
  if (vehicle->position.x > 0) {
    vehicle->position.x -= vehicle->movement.x * vehicle->speed.x;
  }
}

void updateEnemies(bool final, HorizontalScroller *waterLily, HorizontalScroller *truck, HorizontalScroller *redCar) {
  updateWaterLilyRight(waterLily, final);
  std::thread threadUpdateWaterLily(updateWaterLily, waterLily, final);
  // std::thread threadUpdateWaterLilyRight(updateWaterLilyRight, waterLily);
  std::thread threadUpdateVehicle(updateVehicle, truck, final);
  // updateVehicle(&truck);

  if (waterLily->position.x < (float)0) {
    final = true;
  }
  threadUpdateWaterLily.join();

  // threadUpdateWaterLilyRight.join();
  updateVehicle(redCar, final);
  threadUpdateVehicle.join();
}
