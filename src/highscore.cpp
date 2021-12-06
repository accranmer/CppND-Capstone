#include "highscore.h"
#include "game.h"
#include "user.h"
#include <iostream>
#include <fstream>

HighScore::HighScore(std::string fileName) : _fileName(fileName){
    ReadFile();
}

void HighScore::ResetHighScore() {
    easyLine = "Easy: 0,";
    hardLine = "Hard: 0,";
    WriteFile();
    std::cout << "High Scores Reset.\n";
}

void HighScore::ReadFile(){
  size_t found1, found2;
  // Read from the text file
  std::ifstream MyReadFile(_fileName);

  // Easy High Score
  getline (MyReadFile, easyLine); 
  found1 = easyLine.find(": ");
  found2 = easyLine.find(",");
  easyScore = std::stoi(easyLine.substr(found1+2,found2-found1-2));

  // Hard High Score
  getline (MyReadFile, hardLine); 
  found1 = hardLine.find(": ");
  found2 = hardLine.find(",");
  hardScore = std::stoi(hardLine.substr(found1+2,found2-found1-2));
  MyReadFile.close();
}

void HighScore::WriteFile(){
    // Create and open a text file
    std::ofstream MyWriteFile("../HighScores.txt");
    // Write to the file
    MyWriteFile << easyLine << "\n" << hardLine << "\n";
    // Close the file
    MyWriteFile.close();
}

void HighScore::CheckForHighScore(User &user, Game &game){
  ReadFile();
  if (user.getDifficultyString() == "Easy" && game.GetScore() > easyScore) {
    easyLine = "Easy: " + std::to_string(game.GetScore()) + ", " + user.getName();
    newHighScore = true;
    prevScore = easyScore;
  }
  else if (user.getDifficultyString() == "Hard" && game.GetScore() > hardScore) {
    hardLine = "Hard: " + std::to_string(game.GetScore()) + ", " + user.getName();
    newHighScore = true;
    prevScore = hardScore;
  }
  if (newHighScore){
        WriteFile();
        std::cout << "New High Score! Previously: " << prevScore << "\n";
    }
}

