# FlappyBird

This program is an implementation of the popular mobile game Flappy Bird, developed in C++ using the Windows API. 
The player controls a bird that must fly between pairs of pipes without hitting them. 
The player earns points for each pair of pipes they successfully pass through. The game ends when the bird hits a pipe.

# How to Run/Play the Game:
- Download and install a C++ compiler such as Visual Studio or Mingw-w64 on your Windows computer.
- Download the source code for the game and open it in your compiler.
- Build and run the program.
- Press the spacebar to make the bird jump and navigate through the pipes.

# Required Libraries
The following libraries are required to run this program:
- iostream is used for input and output operations such as cout and endl.
- cstdlib is used for the srand() and rand() functions, which are used to generate random numbers.
- ctime is used for the time() function, which is used to seed the random number generator.
- Windows.h is used for the Sleep() function, which is used to pause the execution of the program for a certain amount of time (in milliseconds), 
allowing the game to run at a slower pace and creating the illusion of animation.
- conio.h is used for the getch() function, which is used to pause the game and wait for the player to press a key before exiting.

# Technical Overview
The program is implemented using the C++ programming language and the Windows API. 
The main logic of the game is contained in the main() function, which runs in an infinite loop until the game is over.

The main() function starts by initializing several variables, including the bird's position, 
the pipes' positions, the bird's velocity, and the player's score. It then enters the main game loop, which continues running until the game is over.

The game loop starts by handling user input. It uses the GetAsyncKeyState() function to check if the player has pressed the spacebar. 
If the spacebar is pressed, the bird's velocity is set to -1, causing the bird to move upward on the next iteration of the loop.

The game state is then updated. The bird's position is updated by adding the bird's velocity to the bird's y-coordinate. 
The velocity is also incremented by 1, simulating the effect of gravity. The pipes' positions are also updated by decrementing their x-coordinates by 1, 
simulating the pipes moving to the left. If a pipe's x-coordinate becomes less than or equal to 0, the pipe is moved back to the right side of 
the screen and a new random y-coordinate is generated for it.

The program then checks for collisions between the bird and the pipes. If the bird's x-coordinate is equal 
to the x-coordinate of a pipe and the bird's y-coordinate is outside of the gap between the pipes, 
the game is over and the gameOverScreen() function is called to display the game over message and the player's final score.

If the bird's x-coordinate is equal to the x-coordinate of a pipe + 1, the player's score is incremented by 1.

Finally, the program uses the drawScreen() function to display the current state of the game on the screen. 
The Sleep() function is then used to pause the execution of the program for a brief period of time, 
allowing the game to run at a slower pace and creating the illusion of animation. 
The loop then starts again, waiting for user input and updating the game state
