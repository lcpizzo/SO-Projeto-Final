#include "../useHeaders/horizontalScroller.h"

#include <semaphore.h>

#include <iostream>
#include <thread>
#include <vector>

#include "raylib.h"

void checkVehicle(sem_t* sem, bool& end, float x, float y, HorizontalScroller* vehicle) {
  if (x >= vehicle->position.x &&
      x <= vehicle->position.x + vehicle->size.x &&
      y >= vehicle->position.y &&
      y <= vehicle->position.y + 85)
    end = true;
}

void checkCollision(sem_t* sem, bool& end, float x, float y, std::vector<HorizontalScroller>* enemies) {
  checkVehicle(sem, end, x, y, &(*enemies)[0]);
  checkVehicle(sem, end, x, y, &(*enemies)[1]);
  checkVehicle(sem, end, x, y, &(*enemies)[2]);
  checkVehicle(sem, end, x, y, &(*enemies)[3]);
  checkVehicle(sem, end, x, y, &(*enemies)[4]);
}

void updateVehicle(HorizontalScroller* vehicle) {
  // movement
  if (vehicle->position.x > 0) {
    vehicle->position.x -= vehicle->movement.x * vehicle->speed.x;
  } else {
    vehicle->position.x = GetScreenWidth() + (vehicle->size.x + 100);
  }
}

void updateEnemies(std::vector<HorizontalScroller>* enemies) {
  std::thread threadUpdateTruck(updateVehicle, &(*enemies)[0]);
  std::thread threadUpdateRedCar(updateVehicle, &(*enemies)[1]);
  std::thread threadUpdateBlueCar(updateVehicle, &(*enemies)[2]);
  std::thread threadUpdateYellowCar(updateVehicle, &(*enemies)[3]);
  std::thread threadUpdateTruck2(updateVehicle, &(*enemies)[4]);

  threadUpdateTruck.join();
  threadUpdateRedCar.join();
  threadUpdateBlueCar.join();
  threadUpdateYellowCar.join();
  threadUpdateTruck2.join();
}
