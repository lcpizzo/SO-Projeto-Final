#include "../useHeaders/horizontalScroller.h"

#include <semaphore.h>

#include <iostream>
#include <thread>
#include <vector>

#include "raylib.h"

// Funcao que verifica o tamanho e posicao do veiculo para a colisao
void checkVehicle(bool& end, float x, float y, HorizontalScroller* vehicle) {
  if (x >= vehicle->position.x &&
      x <= vehicle->position.x + vehicle->size.x &&
      y >= vehicle->position.y &&
      y <= vehicle->position.y + 85)
    end = true;
}

// Funcao que verifica a colisao de cada 'inimigo' com o jogador
void checkCollision(bool& end, float x, float y, std::vector<HorizontalScroller>* enemies) {
  checkVehicle(end, x, y, &(*enemies)[0]);
  checkVehicle(end, x, y, &(*enemies)[1]);
  checkVehicle(end, x, y, &(*enemies)[2]);
  checkVehicle(end, x, y, &(*enemies)[3]);
  checkVehicle(end, x, y, &(*enemies)[4]);
}

// Funcao principal do movimento horizontal dos 'inimigos'/veiculos
void updateVehicle(HorizontalScroller* vehicle) {
  if (vehicle->position.x > 0) {
    vehicle->position.x -= vehicle->movement.x * vehicle->speed.x;
  } else {
    vehicle->position.x = GetScreenWidth() + (vehicle->size.x + 100);
  }
}

// Funcao de atualizar/movimentar os 'inimigos'
void updateEnemies(std::vector<HorizontalScroller>* enemies) {
  // Inicializacao das threads para cada 'inimigo'/veiculo, chamando a funcao updateVehicle
  std::thread threadUpdateTruck(updateVehicle, &(*enemies)[0]);
  std::thread threadUpdateRedCar(updateVehicle, &(*enemies)[1]);
  std::thread threadUpdateBlueCar(updateVehicle, &(*enemies)[2]);
  std::thread threadUpdateYellowCar(updateVehicle, &(*enemies)[3]);
  std::thread threadUpdateTruck2(updateVehicle, &(*enemies)[4]);

  // Espera as threads acima finalizarem
  threadUpdateTruck.join();
  threadUpdateRedCar.join();
  threadUpdateBlueCar.join();
  threadUpdateYellowCar.join();
  threadUpdateTruck2.join();
}
