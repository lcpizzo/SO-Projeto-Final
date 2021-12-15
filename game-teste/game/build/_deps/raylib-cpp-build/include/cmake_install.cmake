# Install script for directory: /home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/AudioDevice.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/AudioStream.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/BoundingBox.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Camera2D.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Camera3D.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Color.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Font.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Functions.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Gamepad.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Image.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Material.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Matrix.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Mesh.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Model.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/ModelAnimation.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Mouse.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Music.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/physac.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Physics.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Ray.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/RayCollision.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/raylib-cpp-utils.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/raylib-cpp.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/raylib.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/raymath.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Rectangle.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/RenderTexture.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Shader.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Sound.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Texture.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Vector2.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Vector3.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Vector4.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/VrStereoConfig.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Wave.hpp"
    "/home/guijun/Área de Trabalho/grad/sistemOps/SO-Projeto-Final/game-teste/game/build/_deps/raylib-cpp-src/include/Window.hpp"
    )
endif()

