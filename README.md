# AlBannaDesigner-OpenGL
This is opengl-multi-core  program i create it when i learn open gl
this source code consist of many parts 
#### so : to run any part you need to convert `#if 0` to `#if 1` 
> Warn : You can't run/build many cores at the same time `There is just one start point`

### Notic
due to github repository size limitation and git tracking system limitation with binary/blob files
I can not provide dll files and exe files here since it is not in git tracking system
so this may force you to download all those files manualy 
##### For that,
I Upload the whole project to mega cloude, so you can just download it , and use it directly
Also notice it's includes all generated binary files for all development steps
including `fractal shader engine`

##### [Project Link On Mega](https://mega.nz/#F!D0YmiYyT!DXa8ySaJ5UX0EsYPRMNplw)

###### Also notice:
due to complexity of containing pure OpenGl window inside HWND pointer wrappers for most of libraries I record this video to explain
containing openGL inside Qt container `only qt dlls needed, without need to qt creator/studio or any scaffolding or WISWIG tools` this video i pretty long `1:46:16` Also i used java `i used java for this demonstration , you can use what you want` to get/update dll references in C++ project

###### [Qt+OpenGL Video](https://mega.nz/#!f4oQWAgS!acDF7rFMB8roCbeJO9cgVUTD4bI8ZSMAvkd8msh-ykU)

#### Features
* Implement most of light physics princibles for 2d and 3d models
* Load 2d and 3d models with texturing, and apply custom filters
* Easly move in the environment with mouse and keyboard, also support zoom
* Shading object borders with tensile shader
  <a href="https://ibb.co/tQthkdW"><img src="https://i.ibb.co/9cLvzMC/tensile.png" alt="tensile" border="0"></a>
  
#### Not Implemented Features
* This projects does not implement body/mass physics engine, it is pretty complex and out of scope of OpenGL itself
so i prefered to not wast my time by implementing it

#### Screenshots

* ShaderBox

<a href="https://ibb.co/LQ4MT2k"><img src="https://i.ibb.co/RhL1XVv/sh1.png" alt="sh1" border="0"></a>
<a href="https://ibb.co/yNmRZS8"><img src="https://i.ibb.co/0npX6tf/sh2.png" alt="sh2" border="0"></a>
<a href="https://ibb.co/RNBxX4z"><img src="https://i.ibb.co/W0Pbrpg/sh3.png" alt="sh3" border="0"></a>
<a href="https://ibb.co/k2YmFJh"><img src="https://i.ibb.co/9HRZjhq/sh4.png" alt="sh4" border="0"></a>

* General

<a href="https://ibb.co/N7h8Lrh"><img src="https://i.ibb.co/BwDXgGD/box2.png" alt="box2" border="0"></a>
<a href="https://ibb.co/6Zs2C7T"><img src="https://i.ibb.co/Ct0qG3Y/cont2.png" alt="cont2" border="0"></a>
<a href="https://ibb.co/hfyHBz4"><img src="https://i.ibb.co/bJPLs9C/ligh1.png" alt="ligh1" border="0"></a>
<a href="https://ibb.co/vh6xc4n"><img src="https://i.ibb.co/0KRjnyb/light.png" alt="light" border="0"></a>

