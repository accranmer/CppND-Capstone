#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
#include "user.h"
#include "highscore.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::string name;
  int diff = 0; // Easy = 0, Hard = 1
  int diff_input, reset_input;
  std::cout << "Welcome to Snake Game!" << std::endl;
  std::cout << "Type your name:" << std::endl;
  std::cin >> name; // Get user input from the keyboard
  std::cout << "Select Difficulty: Easy(0), Hard(1):" << std::endl;
  std::cout << "Easy Difficulty: Medicine food slows you down." << std::endl;
  std::cout << "Hard Difficulty: No medicine, and speed increases faster." << std::endl;
  std::cin >> diff_input;
  std::cout << "Reset High Scores? Yes(1), No(0):" << std::endl;
  std::cin >> reset_input;
  if (diff_input == 1){
    diff = diff_input; // Enforce user can only set 0 or 1 buy defaulting to 0 if not 1
  }

  User user(name, diff);
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, user, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "*********************\n";
  std::cout << "*****  RESULTS  *****\n";
  std::cout << "*********************\n";
  std::cout << "Difficulty: " << user.getDifficultyString() << "\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  std::string fileName = "../HighScores.txt";
  HighScore highscore(fileName);
  
  if (reset_input == 1)
    highscore.ResetHighScore();

  // Check recorded high scores and update if beaten!
  highscore.CheckForHighScore(user, game);

  return 0;
}