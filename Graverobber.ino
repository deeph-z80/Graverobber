#include <Gamebuino-Meta.h>

#define TILE_SIZE                 8
#define TILE_BLOCKING_LIMIT       9
#define PLAYER_HEIGHT             13+2 // +2 to "center" the sprite on the tile
#define ZOMBIE_HEIGHT             11+2
#define ZOMBIE_AMOUNT             2
#define ZOMBIE_TURN_DELAY         4
#define ZOMBIE_PROXIMITY_TRIGGER  20
#define ZOMBIE_MOVES_ATTEMPTS     3
#define ZOMBIES_ANIMATION_SPEED   4
#define FOG_DISTANCE              3

#include "sprites.h"

int music = -1;
uint32_t turn = 1;

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
    const uint8_t *data;
    uint8_t width, height;
    void draw(), draw_fog();
};
map_ current_map;

class zombie_ {
  public:
    uint8_t x, y, direction, animation, scrolling;
    int8_t x_velocity, y_velocity, x_offset, y_offset;
    boolean is_moving, has_ended_turn;
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
      int8_t tile_x = camera.x / TILE_SIZE + x;
      int8_t tile_y = camera.y / TILE_SIZE + y;
      //if (tile_x >= 0 && tile_x < width && tile_y >= 0 && tile_y < height) {
        tile_set.setFrame(data[tile_y * width + tile_x]);
        tile_x = x * TILE_SIZE - camera.x % TILE_SIZE;
        tile_y = y * TILE_SIZE - camera.y % TILE_SIZE;
        gb.display.drawImage(tile_x, tile_y, tile_set);
      //}
    }
  }
}

void map_::draw_fog() {
  for (byte y = 0; y <= gb.display.height() + TILE_SIZE; y += TILE_SIZE) {
    for (byte x = 0; x <= gb.display.width() + TILE_SIZE; x += TILE_SIZE) {
      int8_t fog_dist = sqrt(sq(player.x * TILE_SIZE + player.x_offset - camera.x - x) + sq(player.y * TILE_SIZE + player.y_offset - camera.y - y)) + TILE_SIZE / 2;
      if (fog_dist > (FOG_DISTANCE - 1) * TILE_SIZE) {
        fog_sprite_set.setFrame((fog_dist > (FOG_DISTANCE + 1) * TILE_SIZE) + 2 * (fog_dist == (FOG_DISTANCE + 1) * TILE_SIZE) + 3 * (fog_dist == FOG_DISTANCE * TILE_SIZE) - 1);
        gb.display.drawImage(x, y, fog_sprite_set);
      }
    }
  }
}

void zombie_::draw() {
  animation += (gb.frameCount % ZOMBIES_ANIMATION_SPEED == 0);
  animation *= animation < 3;
  zombie_sprite_set.setFrame(direction * 3 + animation);
  gb.display.drawImage(x * TILE_SIZE - camera.x + x_offset, y * TILE_SIZE - camera.y + y_offset - (ZOMBIE_HEIGHT - TILE_SIZE), zombie_sprite_set);
}

void zombies_draw() {
  for (uint8_t i = 0; i <= ZOMBIE_AMOUNT - 1; i++) {
    zombies[i].draw();
  }
}

void zombie_::handle() {
  if (!has_ended_turn) {
    if (!is_moving) {
      x_velocity = y_velocity = 0;
      //if (abs(x - player.x) <= ZOMBIE_PROXIMITY_TRIGGER && abs(y - player.y) <= ZOMBIE_PROXIMITY_TRIGGER) {
      if (abs(x - player.x) > abs(y - player.y)) {
        x_velocity = (x < player.x) - (x > player.x);
      } else {
        y_velocity = (y < player.y) - (y > player.y);
      }
      /*} else {
        if (random(2)) {
          x_velocity = random(2);
          x_velocity -= (x_velocity == 0);
        } else {
          y_velocity = random(2);
          y_velocity -= (y_velocity == 0);
        }
        }*/
      uint8_t attempts = 0;
      do {
        if (current_map.data[(y + y_velocity) * current_map.width + x + x_velocity] < TILE_BLOCKING_LIMIT &&
            !zombies_collide(x + x_velocity, y + y_velocity) &&
            (player.x != x + x_velocity && player.y != y + y_velocity)) {
          is_moving = true;
        } else {
          x_velocity = y_velocity = 0;
          attempts++;
          if (random(2)) {
            x_velocity = random(2);
            x_velocity -= (x_velocity == 0);
          } else {
            y_velocity = random(2);
            y_velocity -= (y_velocity == 0);
          }
        }
        if (attempts > ZOMBIE_MOVES_ATTEMPTS) {
          x_velocity = y_velocity = 0;
          has_ended_turn = true;
          break;
        }
      } while (!is_moving);
      direction = (1 + x_velocity) * (x_velocity != 0);
      direction = (2 + y_velocity) * (y_velocity != 0 || direction == 0);
    } else {
      scrolling++;
      x_offset += x_velocity;
      y_offset += y_velocity;
      if (scrolling == TILE_SIZE) {
        scrolling = x_offset = y_offset = 0;
        is_moving = false;
        has_ended_turn = true;
        x += x_velocity;
        y += y_velocity;
      }
    }
  }
};

void zombies_update() {
  if (turn % ZOMBIE_TURN_DELAY == 0) {
    uint8_t moving_counter = 0;
    for (uint8_t i = 0; i <= ZOMBIE_AMOUNT - 1; i++) {
      zombies[i].handle();
      if (!zombies[i].has_ended_turn) moving_counter++;
    }
    if (moving_counter == 0) {
      for (uint8_t i = 0; i <= ZOMBIE_AMOUNT - 1; i++) {
        zombies[i].has_ended_turn = false;
      }
      turn++;
    }
  }
}

uint8_t zombies_find_index(uint8_t x, uint8_t y) {
  for (uint8_t i = 0; i < ZOMBIE_AMOUNT; i++) {
    if (zombies[i].x + zombies[i].x_velocity == x && zombies[i].y + zombies[i].y_velocity == y) return i;
  }
}

boolean zombies_collide(uint8_t x, uint8_t y) {
  for (uint8_t i = 0; i < ZOMBIE_AMOUNT; i++) {
    if (zombies_find_index(x, y) != i) {
      if (zombies[i].x + zombies[i].x_velocity == x && zombies[i].y + zombies[i].y_velocity == y) return true;
    }
  }
  return false;
}

boolean zombies_collide_with_player(uint8_t x, uint8_t y) {
  for (uint8_t i = 0; i < ZOMBIE_AMOUNT; i++) {
    if (zombies[i].x == x && zombies[i].y == y) return true;
  }
  return false;
}

void player_::draw() {
  player_sprite_set.setFrame(direction * 3 + animation);
  gb.display.drawImage(x * TILE_SIZE - camera.x + x_offset, y * TILE_SIZE - camera.y + y_offset - (PLAYER_HEIGHT - TILE_SIZE), player_sprite_set);
}

void player_::update() {
  if (turn % ZOMBIE_TURN_DELAY != 0) {
    if (!is_moving) {
      x_velocity = y_velocity = 0;
      x_velocity = -gb.buttons.repeat(BUTTON_LEFT, 1) * (x > 0) + gb.buttons.repeat(BUTTON_RIGHT, 1) * (x < current_map.width - 1);
      y_velocity = -gb.buttons.repeat(BUTTON_UP, 1) * (y > 0) + gb.buttons.repeat(BUTTON_DOWN, 1) * (y < current_map.height - 1);
      if (!x_velocity != !y_velocity) {
        direction = (1 + x_velocity) * (x_velocity != 0);
        direction = (2 + y_velocity) * (y_velocity != 0 || direction == 0);
        if (current_map.data[(y + y_velocity) * current_map.width + x + x_velocity] < TILE_BLOCKING_LIMIT &&
            !zombies_collide_with_player(x + x_velocity, y + y_velocity)) is_moving = true;
      }
    } else {
      scrolling++;
      animation += scrolling % 2;
      animation *= animation < 3 && scrolling < TILE_SIZE;
      x_offset += x_velocity;
      y_offset += y_velocity;
      if (scrolling == TILE_SIZE) {
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
  gb.setFrameRate(50);
  current_map.data = map01;
  current_map.width = current_map.height = 32;
  camera.x = camera.y = 0;
  player.x = player.y = 4;
  player.direction = player.animation = 0;
  player.is_moving = false;
  zombies[0].x = zombies[0].y = 5;
  zombies[0].direction = zombies[0].x_velocity = zombies[0].y_velocity = 0;
  zombies[0].is_moving = zombies[0].has_ended_turn = false;
  zombies[1].x = zombies[1].y = 8;
  zombies[1].direction = zombies[1].x_velocity = zombies[1].y_velocity = 0;
  zombies[1].is_moving = zombies[1].has_ended_turn = false;
}

void loop() {
  music = gb.sound.play("music/cruising_for_goblins.wav", true);
  while (true) {
    player.update();
    zombies_update();
    camera.update();
    current_map.draw();
    player.draw();
    zombies_draw();
    current_map.draw_fog();

    // debug
    /*gb.display.setColor(WHITE);
      gb.display.setCursor(0, 0);
      gb.display.print(turn);*/

    while (!gb.update());
  }
}
