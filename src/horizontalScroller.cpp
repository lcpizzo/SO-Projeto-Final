#include "../useHeaders/horizontalScroller.h"

#include <thread>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

void updateWaterLily(HorizontalScroller *waterLily, bool final) {
  // movement
  if (waterLily->position.x > 0) {
    waterLily->position.x -= waterLily->movement.x * waterLily->speed.x;
  } else {
    waterLily->position.x = GetScreenWidth() + (waterLily->size.x + 100);
  }
  // if (!final) {
  //   // printf("final\n");
  // }
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
  } else {
    vehicle->position.x = GetScreenWidth() + (vehicle->size.x + 100);
  }
}

void updateEnemies(bool final, HorizontalScroller *waterLily, HorizontalScroller *truck, HorizontalScroller *redCar) {
  std::thread threadUpdateWaterLily(updateWaterLily, waterLily, final);
  std::thread threadUpdateTruck(updateVehicle, truck, final);
  std::thread threadUpdateRedCar(updateVehicle, redCar, final);

  threadUpdateWaterLily.join();
  threadUpdateTruck.join();
  threadUpdateRedCar.join();
}
