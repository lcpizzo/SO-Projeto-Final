#include "../useHeaders/horizontalScroller.h"

#include <semaphore.h>

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/player.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

// class semaphore {
//   std::mutex mutex_;
//   std::condition_variable condition_;
//   unsigned long count_ = 0;  // Initialized as locked.

//  public:
//   void release() {
//     std::lock_guard<decltype(mutex_)> lock(mutex_);
//     ++count_;
//     condition_.notify_one();
//   }

//   void acquire() {
//     std::unique_lock<decltype(mutex_)> lock(mutex_);
//     while (!count_)  // Handle spurious wake-ups.
//       condition_.wait(lock);
//     --count_;
//   }

// bool try_acquire() {
//   std::lock_guard<decltype(mutex_)> lock(mutex_);
//   if (count_) {
//     --count_;
//     return true;
//   }
//   return false;
// }
// }
// ;

bool checkVehicle(bool end, float x, float y, HorizontalScroller *vehicle) {
  if (x >= vehicle->position.x && x <= vehicle->position.x + vehicle->size.x && y >= vehicle->position.y && y <= vehicle->position.y + 85) return true;
  return end;
}

bool checkCollision(bool end, float x, float y, std::vector<HorizontalScroller> *enemies) {
  end = checkVehicle(end, x, y, &(*enemies)[0]);
  end = checkVehicle(end, x, y, &(*enemies)[1]);
  end = checkVehicle(end, x, y, &(*enemies)[2]);
  end = checkVehicle(end, x, y, &(*enemies)[3]);
  end = checkVehicle(end, x, y, &(*enemies)[4]);
  return end;
}

void updateVehicle(HorizontalScroller *vehicle) {
  // movement
  if (vehicle->position.x > 0) {
    vehicle->position.x -= vehicle->movement.x * vehicle->speed.x;
  } else {
    vehicle->position.x = GetScreenWidth() + (vehicle->size.x + 100);
  }
}

// void updateVehicleRight(HorizontalScroller *vehicle) {
//   // movement
//   if (vehicle->position.x > 0) {
//     vehicle->position.x += vehicle->movement.x * vehicle->speed.x;
//   } else {
//     vehicle->position.x = GetScreenWidth() + (vehicle->size.x + 100);
//   }
// }

void updateEnemies(std::vector<HorizontalScroller> *enemies) {
  std::thread threadUpdateTruck(updateVehicle, &(*enemies)[0]);
  std::thread threadUpdateRedCar(updateVehicle, &(*enemies)[1]);
  std::thread threadUpdateBlueCar(updateVehicle, &(*enemies)[2]);
  std::thread threadUpdateYellowCar(updateVehicle, &(*enemies)[3]);
  std::thread threadUpdateYellowCar2(updateVehicle, &(*enemies)[4]);

  threadUpdateTruck.join();
  threadUpdateRedCar.join();
  threadUpdateBlueCar.join();
  threadUpdateYellowCar.join();
  threadUpdateYellowCar2.join();
}
