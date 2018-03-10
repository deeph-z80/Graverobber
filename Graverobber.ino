#include <Gamebuino-Meta.h>
#include "sprites.h"

#define TILE_SIZE         8
#define ZOMBIE_HEIGHT     16
#define ZOMBIE_AMOUNT     1
#define ZOMBIE_TURN_DELAY 4

uint8_t turn = 1;

const uint8_t map01[] = {
  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9,
  9, 5, 5, 5, 5, 5, 5, 5, 9, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 9, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 9,
  9, 0, 0, 2, 1, 0, 0, 0, 5, 0, 0, 12, 0, 12, 0, 11, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 0, 6, 0, 6, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 11, 0, 12, 0, 11, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 9,
  9, 13, 13, 13, 14, 13, 13, 13, 13, 0, 0, 6, 0, 6, 0, 7, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 9, 9, 9, 9, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 9, 9, 9, 9,
  9, 10, 10, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 0, 0, 0, 10, 10, 10, 9,
  9, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 9, 5, 5, 5, 5, 5, 5, 5, 9, 5, 5, 5, 0, 0, 0, 5, 5, 5, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 2, 0, 0, 0, 0, 9, 0, 0, 0, 2, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 11, 0, 12, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10, 0, 0, 6, 0, 7, 0, 0, 10, 0, 0, 4, 0, 0, 0, 1, 0, 0, 9,
  9, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 3, 4, 0, 4, 0, 3, 0, 0, 0, 0, 0, 0, 4, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 9,
  9, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 0, 9, 0, 3, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 4, 3, 0, 0, 0, 9,
  9, 13, 13, 13, 0, 0, 0, 0, 13, 13, 14, 13, 13, 9, 0, 0, 0, 0, 11, 0, 0, 9, 0, 0, 2, 0, 0, 0, 0, 0, 0, 9,
  9, 5, 5, 5, 0, 0, 4, 0, 5, 5, 5, 5, 5, 9, 0, 0, 12, 0, 6, 1, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 2, 0, 0, 3, 0, 0, 2, 0, 0, 0, 9, 0, 0, 7, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 9, 13, 14, 13, 0, 0, 0, 13, 13, 13, 9,
  9, 0, 0, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 5, 5, 5, 0, 1, 0, 5, 5, 5, 9,
  9, 0, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 0, 0, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
  9, 9, 9, 9, 4, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
};

class camera_ {
  public:
    int16_t x, y;
    void update();
};
camera_ camera;

class map_ {
  public:
    const uint8_t *map_data;
    uint8_t width, height;
    void draw();
};
map_ current_map;

class zombie_ {
  public:
    uint8_t x, y, animation, scrolling;
    int8_t x_velocity, y_velocity, x_offset, y_offset;
    boolean is_moving;
    void draw(), handle();
};
zombie_ zombies[ZOMBIE_AMOUNT];

class player_ {
  public:
    uint8_t x, y, direction, animation, scrolling;
    int8_t x_velocity, y_velocity, x_offset, y_offset;
    boolean is_moving;
    void draw(), update();
};
player_ player;

void camera_::update() {
  x = player.x * TILE_SIZE - gb.display.width() / 2 + TILE_SIZE / 2 + player.x_offset;
  x = camera.x * (x > 0) + (current_map.width * TILE_SIZE - gb.display.width() - x) * (x > current_map.width * TILE_SIZE - gb.display.width());
  y = player.y * TILE_SIZE - gb.display.height() / 2 + TILE_SIZE / 2 + player.y_offset;
  y = camera.y * (y > 0) + (current_map.height * TILE_SIZE - gb.display.height() - y) * (y > current_map.height * TILE_SIZE - gb.display.height());
};

void map_::draw() {
  for (byte y = 0; y <= gb.display.height() / TILE_SIZE + 1; y++) {
    for (byte x = 0; x <= gb.display.width() / TILE_SIZE + 1; x++) {
      int tile_x = camera.x / TILE_SIZE + x;
      int tile_y = camera.y / TILE_SIZE + y;
      if (tile_x >= 0 && tile_x < width && tile_y >= 0 && tile_y < height) {
        tile_set.setFrame(map_data[tile_y * width + tile_x]);
        gb.display.drawImage(x * TILE_SIZE - camera.x % TILE_SIZE, y * TILE_SIZE - camera.y % TILE_SIZE, tile_set);
      }
    }
  }
}

void zombie_::draw() {
  zombie_sprite_set.setFrame(0);
  gb.display.drawImage(x * TILE_SIZE - camera.x + x_offset, y * TILE_SIZE - camera.y + y_offset - (ZOMBIE_HEIGHT - TILE_SIZE), zombie_sprite_set);
}

void zombies_draw() {
  for (uint8_t i = 0; i <= ZOMBIE_AMOUNT - 1; i++) {
    zombies[i].draw();
  }
}

void zombie_::handle() {
  if(!is_moving){
    scrolling = x_velocity = y_velocity = 0;
    if(abs(x - player.x) > abs(y - player.y)){
      x_velocity = (x < player.x) - (x > player.x);
    }else{
      y_velocity = (y < player.y) - (y > player.y);
    }
    is_moving = true;
  }else{
    scrolling++;
    x_offset += x_velocity;
    y_offset += y_velocity;
    if(scrolling == TILE_SIZE){
      x_offset = y_offset = 0;
      is_moving = false;
      x += x_velocity;
      y += y_velocity;
      turn++;
    }
  }
};

void zombies_update() {
  if (turn % ZOMBIE_TURN_DELAY == 0) {
    uint8_t moving_counter = 0;
    for (uint8_t i = 0; i <= ZOMBIE_AMOUNT - 1; i++) {
      zombies[i].handle();
      if(zombies[i].is_moving) moving_counter++;
    }
    if(moving_counter == 0) turn++;
  }
}

void player_::draw() {
  player_sprite_set.setFrame(direction * 2 + animation);
  gb.display.drawImage(x * TILE_SIZE - camera.x + x_offset, y * TILE_SIZE - camera.y + y_offset, player_sprite_set);
}

void player_::update() {
  if(turn % ZOMBIE_TURN_DELAY != 0){
    if(!is_moving){
      x_velocity = y_velocity = 0;
      x_velocity = -gb.buttons.repeat(BUTTON_LEFT, 1) * (x > 0) + gb.buttons.repeat(BUTTON_RIGHT, 1) * (x < current_map.width - 1);
      y_velocity = -gb.buttons.repeat(BUTTON_UP, 1) * (y > 0) + gb.buttons.repeat(BUTTON_DOWN, 1) * (y < current_map.height - 1);
      if (!x_velocity != !y_velocity) {
        direction = (1 + x_velocity) * (x_velocity != 0);
        direction = (2 + y_velocity) * (y_velocity != 0 || direction == 0);
        is_moving = true;
      }
    }else{
      scrolling++;
      animation += scrolling % 2;
      animation *= animation < 2 && scrolling < TILE_SIZE;
      x_offset += x_velocity;
      y_offset += y_velocity;
      if(scrolling == TILE_SIZE){
        scrolling = x_offset = y_offset = 0;
        is_moving = false;
        x += x_velocity;
        y += y_velocity;
        turn++;
      }
    }
  }
}

void setup() {
  gb.begin();
  current_map.map_data = map01;
  current_map.width = current_map.height = 32;
  camera.x = camera.y = 0;
  player.x = player.y = 4;
  player.direction = player.animation = 0;
  player.is_moving = false;
  zombies[0].x = zombies[0].y = 5;
}

void loop() {
  while (true) {
    player.update();
    zombies_update();
    camera.update();
    current_map.draw();
    player.draw();
    zombies_draw();
    while (!gb.update());
  }
}
