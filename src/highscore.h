#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <iostream>
#include <fstream>
#include "game.h"
#include "user.h"

class HighScore {
  public:
    HighScore(std::string fileName);
    void CheckForHighScore(User &user, Game &game);
    void ResetHighScore();

    private:
        void ReadFile();
        void WriteFile();
        std::string _fileName;
        bool newHighScore{false};
        std::string easyLine, hardLine;
        int easyScore, hardScore, prevScore;
};

#endif