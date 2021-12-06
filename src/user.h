#ifndef USER_H
#define USER_H

#include <string>

class User {
 public:
  User(std::string name, int diff)
      : name(name),
        difficulty(diff) {}

  std::string getDifficultyString() const;

  int getDifficulty() const {
    return difficulty;
  }    

  std::string getName() const {
    return name;
  }
  
private:
  int difficulty{0};
  std::string name;
};

#endif
