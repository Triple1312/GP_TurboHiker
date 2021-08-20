# GP TurboHiker
 
This project is game made for the course Advanced Programming at the university of Antwerp.

## Gamerules
You are a person racing against robots. These robots are pink racers. If you hit a racer robot you respawn on a random lane. On the lanes are obstacles. If you hit any of the obstacles you get penalized in score and speed so try to avoid them by moving. Don’t jump off the map though! If you do jump off, you will get penalized in score and will respawn. Then at last there are black suicide robots that run in the opposite direction. If you get hit by a suicide robot it explodes and you die which ends the run. You have a way to protect yourself against these evil robots with an emp-charge. This emp charge needs time to charge up. If a racer robot is in a specific range when you emp he will slow down significantly depending on how far he is from you. If a suicide robot is in range, they will instantly be destroyed. The last trick that will help you is picking up collectables , they look light blue and give you a boost in one of the following ways: restore your emp, give extra score, catapult you in the air, give a speed boost … When you hit the finish line the end screen comes up with all your stats of the run.

##Build
build with "sudo bash ./build"

##Dependencies

- Glad: https://github.com/Dav1dde/glad  
  To make calls to OpenGL
- SFML: https://www.sfml-dev.org/  
  For the canvas and input
- Glm: https://github.com/g-truc/glm  
  For matrix and vector calculations
- https://github.com/nlohmann/json  
  To read and write json files
- GLText: https://github.com/vallentin/glText  
  To write text on the screen

