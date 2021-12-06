#include "game.h"
#include "snake.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      gridWidth(grid_width),
      gridHeight(grid_height){
  PlaceFood();
  medicine.x = grid_width*2; // Initialize outside of game grid, so that Hard Difficulty does not render medicine on screen
  medicine.y = grid_height*2; 
}

void Game::Run(Controller const &controller, Renderer &renderer, User &user,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update(user);
    renderer.Render(snake, food, medicine);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    //std::cout << "Target Frame Duration; "<< target_frame_duration <<std::endl;
    //std::cout << "Time  = " << frame_end << std::endl;
    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlaceMedicine() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // medicine.
    if (!snake.SnakeCell(x, y) && x != food.x && y != food.y) {
      medicine.x = x;
      medicine.y = y;
      return;
    }
  }
}

void Game::Update(User &user) {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    //  Check user.difficulty here
    if (user.getDifficultyString() == "Easy" ) {
      snake.speed += 0.02;
    }
    else {
      snake.speed += 0.04;
    }
  }
  if (user.getDifficultyString() ==  "Easy" ) {
    // Check if there's medicine over here (Only on Easy Difficulty)
    if (medicine.x == new_x && medicine.y == new_y) {
        // Decrease speed.
        if (snake.speed > 0.03)
          snake.speed -= 0.02;
          PlaceMedicine();
    }
    else {
      double percent = ((double) rand() / (RAND_MAX)); // Random value between 0 and 1
      double medicineChance = .005; // 0.5 Percent chance per update to place medicine

      if (percent < medicineChance){
        PlaceMedicine();
      }
    }
  }
  
    
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }