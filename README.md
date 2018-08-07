# Using OpenGL in Linux Environment

### OpenGL Installation on Linux
```
sudo apt-get install build-essential libgl1-mesa-dev  # Debian, Ubuntu
sudo dnf install make gcc-c++  # Fedora
```

### Libraries
```
sudo apt-get install libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev  # Debian, Ubuntu
sudo dnf install glew-devel SDL2-devel SDL2_image-devel glm-devel freetype-devel   # Fedora
sudo pacman -S glew sdl2 sdl2_image glm freetype2 # Arch
```


### Compiling

```
g++ test.cpp -lglut -lGL -lGLU #add flags per your need
```

# Real Time Analog Wall Clock

Animated graphics program which shows system time as an analog wall clock.

![alt text](https://github.com/kfoozminus/Analog-Wall-Clock-Graphics-Project-/blob/master/Screenshot.png)
