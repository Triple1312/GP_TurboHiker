# GP TurboHiker
 
```mermaid
graph TD
  Maingame --> View
  Maingame --> C
  subgraph Model
  C{Widget} --> Field
  C --> Menu
  C --> Scoreboard
  Field --> E
  E{Entity} --> Player
  E --> Obstacle
  E --> Item
  end
```