# CPPND: Capstone Snake Game
A modern adaptation on the classic Snake game!  Try to eat as much food and grow the snake as large as you can!  As the snake eats more, its length and speed increase.  Keep going until the snake runs into its own body!

This game has two different difficulties: Easy Mode where the snake can find randomly occuring medicine (green blocks) that slow the snake down, and Hard Mode where there is no medicine, and each time the snake eats, its speed increases twice as fast as Easy Mode.

Keep track of the Highest Scores in the HighScores.txt file, which notes the top score and user name for the Easy and Hard modes, as well as the option to reset the high scores.

# New Classes: 
User - Keeps information on user name and difficulty mode chosen.
High Score - Handles reading high scores, checking for new high scores, writing new high scores, and reseting high scores.

# Additional Added Features
User input for name, and difficulty.
High Score feature with user option to reset scores, and maintaining historical best scores.
New food option: medicine that slows the snake down.  Random locations and random times at location.
Different snake speeds based on user chosen difficulty mode.

# Rubric Satisfaction
1. The project reads data from a file and process the data, or the program writes data to a file.  See HighScore class.
2. The project accepts user input and processes the input.  In main.cpp, line 20-28.
3. Classes use appropriate access specifiers for class members.  In HighScore class, the read and write functions are private and accessed by higher level public functions in the HighScore class.  Private variables hold data used to check and modify external text file.
4. Class constructors utilize member initialization lists.  See User Constructor and HighScore Constructor, both use initialization lists.
5. Classes encapsulate behavior.  High Score reading, checking against user's score and modification of the file are all encapsulated in the HighScore class with appropriate function calls for the main.cpp function to call.

<img src="snake_game.gif"/>


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
