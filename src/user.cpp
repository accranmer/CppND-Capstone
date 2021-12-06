#include "user.h"
#include <string>

std::string User::getDifficultyString() const {
    if (difficulty == 0)
        return "Easy";
    else
        return "Hard";
}