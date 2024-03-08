# Mandelbrot set

Visualisation of mandelbrot set made in C++ using SFML and boost. Click to zoom in. Precision isn't too good so after zooming a few times it won't give you more details -
maybe someday I will optimize it to achive more zoom.

## How to run it

Since it is made using SFML and boost you need to install those libraries first.

### Installing SFML

- Download SFML from [here](https://www.sfml-dev.org/download.php)
- Unzip it
- Configure your project dependencies like [this](https://www.sfml-dev.org/tutorials/2.6/start-vc.php)

### Installing boost

- Download boost from [here](https://www.boost.org/users/download/)
- Unzip it
- Add directory containing boost to compiler include path:  
Project Properties -> Configuration Properties -> C/C++ -> General -> Additional Include Directories  
Add your C://.../boost_1_xx_x directory here

### Building boost

This project uses boost libraries that must be built separately, don't wory - it's easy.  
- Open powershell and change your working directory to boost directory ``$ cd C://.../boost_1_xx_x``
- Run bootstrap ``$ ./bootstrap``
- Build boost libraries ``$ ./b2``, it can take a while
- Add directory containing generated libs to linker library path:
Project Properties -> Configuration Properties -> Linker -> General -> Additional Library Directories
Add your C://../boost_1_xx_x/stage/lib directory here

Now, boost should be working properly, but if it isn't check [this](https://levelup.gitconnected.com/the-definite-guide-on-compiling-and-linking-boost-c-libraries-for-visual-studio-projects-c79464d7282d) out

## Game engine

Game engine template was created by Sonar Systems, updated and modified by me. I know it's a bit overkill for small project like this but whatever.
