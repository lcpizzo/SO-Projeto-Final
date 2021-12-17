#include "../useHeaders/horizontalScroller.h"

#include <thread>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

void updateWaterLily(HorizontalScroller *waterLily) {
  // movement
  if (waterLily->position.x > 0) {
    waterLily->position.x -= waterLily->movement.x * waterLily->speed.x;
  } else {
    waterLily->position.x = GetScreenWidth() + (waterLily->size.x + 100);
  }
}

// void updateWaterLilyRight(HorizontalScroller *waterLily) {
//   if (final) {
//     waterLily->position.x += waterLily->movement.x * waterLily->speed.x;
//   }
// }

void updateVehicle(HorizontalScroller *vehicle) {
  // movement
  if (vehicle->position.x > 0) {
    vehicle->position.x -= vehicle->movement.x * vehicle->speed.x;
  } else {
    vehicle->position.x = GetScreenWidth() + (vehicle->size.x + 100);
  }
}

void updateEnemies(HorizontalScroller *waterLily, HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar) {
  std::thread threadUpdateWaterLily(updateWaterLily, waterLily);
  std::thread threadUpdateTruck(updateVehicle, truck);
  std::thread threadUpdateRedCar(updateVehicle, redCar);
  std::thread threadUpdateBlueCar(updateVehicle, blueCar);
  std::thread threadUpdateYellowCar(updateVehicle, yellowCar);

  threadUpdateWaterLily.join();
  threadUpdateTruck.join();
  threadUpdateRedCar.join();
  threadUpdateBlueCar.join();
  threadUpdateYellowCar.join();
}
