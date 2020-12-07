# GP TurboHiker
 
```mermaid
graph TD
  Maingame --> View
  Maingame --> C
  subgraph Model
  C{Widget} --> World
  C --> Menu
  C --> Scoreboard
  World --> E
  E{Entity} --> Player
  E --> Obstacle
  E --> Item
  end
```