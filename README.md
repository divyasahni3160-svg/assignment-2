Professional README: Cake Making
Game
Cake Making Game
A fun, interactive console game where you
bake a cake step-by-step.
Choose the correct actions to successfully
bake the cake. One wrong choice, and the
cake is ruined!
How the Game Works
You will be shown 5 baking steps.
Each step has 3 choices.
Only one correct answer per step.
If you select the wrong option at any stage
GAME OVER
If all choices are correct → YOU WIN
Controls
Action Key
Select option Enter number (1/2/3)
Continue to next screen Press ENTER
Play again Press Y/y
Exit game Press N/n
Scoring
Correct Choices Score
Step completed correctly +1 Point
Total possible score 5 Points
Replay System
After the result:
Player can choose Play Again (y) or Exit (n).
Score resets automatically each new
round.
Features
Simple & humorous baking steps
Wrong choices instantly end the game
Score tracking system
Clear screen transitions for smooth play
Replay option after every completion
Code Structure
Part Function
clear() Clears the console screen
wait() Pauses the screen until ENTER is
pressed
END_GAME: Label for losing condition
ASK_AGAIN: Label for restart prompt
do...while loop Handles replay system
Dependencies
<stdio.h>
<stdlib.h>
<conio.h> (for Windows console input
handling)
