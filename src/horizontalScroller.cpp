#include "../useHeaders/horizontalScroller.h"

#include <semaphore.h>

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

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

bool checkCollision(bool end, float x, float y, HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar, HorizontalScroller *yellowCar2) {
  end = checkVehicle(end, x, y, truck);
  end = checkVehicle(end, x, y, redCar);
  end = checkVehicle(end, x, y, blueCar);
  end = checkVehicle(end, x, y, yellowCar);
  end = checkVehicle(end, x, y, yellowCar2);

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

void updateEnemies(HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar, HorizontalScroller *yellowCar2) {
  std::thread threadUpdateTruck(updateVehicle, truck);
  std::thread threadUpdateRedCar(updateVehicle, redCar);
  std::thread threadUpdateBlueCar(updateVehicle, blueCar);
  std::thread threadUpdateYellowCar(updateVehicle, yellowCar);
  std::thread threadUpdateYellowCar2(updateVehicle, yellowCar2);

  threadUpdateTruck.join();
  threadUpdateRedCar.join();
  threadUpdateBlueCar.join();
  threadUpdateYellowCar.join();
  threadUpdateYellowCar2.join();
}
