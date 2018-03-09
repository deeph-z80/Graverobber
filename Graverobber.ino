#include <Gamebuino-Meta.h>

#define TILE_SIZE 8

const uint8_t tiles_sprites[] = {
  8, 8,   // tiles width & height
  15, 0,  // frames (tiles) amount lower & upper 8-bit
  0,      // frames loop (0 = no animation)
  0xFF,   // transparent color (greater than 0x0F = no transparency)
  1,      // color mode (1 = indexed)
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0x3c, 0xcc,
  0xcc, 0xc3, 0x3c, 0xcc,
  0x3c, 0xc3, 0x31, 0xcc,
  0x31, 0xc3, 0x1c, 0xcc,
  0xc1, 0xc1, 0xcc, 0x33,
  0xcc, 0xcc, 0xc3, 0x3c,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0x3c, 0xcc,
  0xc1, 0xc3, 0x3c, 0x1c,
  0xcc, 0x13, 0x31, 0x3c,
  0xcc, 0xc3, 0x13, 0x3c,
  0xc3, 0x3c, 0xc3, 0xcc,
  0xcc, 0x33, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xdd, 0xdd, 0xdd, 0xdc,
  0xdd, 0xdd, 0xdd, 0xdc,
  0xdd, 0xdd, 0xdd, 0xdc,
  0xdd, 0xdd, 0xdd, 0xdc,
  0xdd, 0xdd, 0xdd, 0xdc,
  0xdd, 0xdd, 0xdd, 0xdc,
  0x11, 0x11, 0x11, 0x1c,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcd, 0xdd, 0xdd, 0xcc,
  0xcd, 0xdd, 0xdd, 0xcc,
  0xcd, 0xdd, 0xdd, 0xcc,
  0xcd, 0xdd, 0xdd, 0xcc,
  0xc1, 0x11, 0x11, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xdd, 0xdd, 0xdc,
  0xcc, 0xdd, 0xdd, 0xdc,
  0xcc, 0xdd, 0xdd, 0xdc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xdd, 0xdd, 0xcc,
  0xcc, 0xdd, 0xdd, 0xcc,
  0xcc, 0xdd, 0xdd, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd,
  0x00, 0x00, 0x00, 0x00,
  0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11,
  0x11, 0x11, 0x11, 0x11,
  0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0x77, 0x77, 0x7c,
  0xcc, 0x11, 0x11, 0x1c,
  0xcc, 0x11, 0xd1, 0x1c,
  0xcc, 0x1d, 0x1d, 0x1c,
  0xcc, 0x11, 0xd1, 0x1c,
  0xcc, 0x11, 0xd1, 0x1c,
  0xcc, 0x11, 0x11, 0x1c,
  0xcc, 0x77, 0x77, 0xcc,
  0xcc, 0x11, 0x11, 0xcc,
  0xcc, 0x1d, 0xd1, 0xcc,
  0xcc, 0x1d, 0x11, 0xcc,
  0xcc, 0x11, 0xd1, 0xcc,
  0xcc, 0x11, 0x11, 0xcc,
  0xcc, 0x11, 0x11, 0xcc,
  0xcc, 0x11, 0x11, 0xcc,
  0xc7, 0x1c, 0xc7, 0x1c,
  0x77, 0x77, 0x77, 0x77,
  0x17, 0x11, 0x17, 0x11,
  0xc7, 0x1c, 0xc7, 0x1c,
  0xc7, 0x1c, 0xc7, 0x1c,
  0xc7, 0x1c, 0xc7, 0x1c,
  0x77, 0x17, 0x77, 0x17,
  0x17, 0x11, 0x17, 0x11,
  0x71, 0xcc, 0xcc, 0x71,
  0x77, 0x7c, 0x77, 0x77,
  0x17, 0x1c, 0x71, 0x11,
  0x77, 0x1c, 0xc7, 0x1c,
  0x11, 0xcc, 0xcc, 0x71,
  0x71, 0xcc, 0xcc, 0x71,
  0x77, 0x17, 0x77, 0x17,
  0x17, 0x11, 0x17, 0x11
};
Image tile_set(tiles_sprites);

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

const uint8_t player_sprites[] = {
  8, 8,   // sprites width & height
  12, 0,  // sprites amount lower & upper 8-bit
  0,      // frames loop (0 = no animation)
  7,      // transparent color (7 = white)
  1,      // color mode (1 = indexed)
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x70, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x00, 0x07, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x77, 0x07, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x07, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x70, 0x00, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x07,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x70, 0x77, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x00, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x00,
  0x77, 0x00, 0x00, 0x07,
  0x70, 0x70, 0x07, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x70, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x77, 0x00, 0x00, 0x77,
  0x70, 0x70, 0x07, 0x77,
  0x70, 0x00, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x07,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x77, 0x07, 0x00, 0x77,
  0x00, 0x70, 0x07, 0x77,
  0x70, 0x00, 0x00, 0x77,
  0x77, 0x70, 0x07, 0x07,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x00, 0x07, 0x77,
  0x77, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x70, 0x07, 0x07,
  0x77, 0x00, 0x00, 0x07,
  0x70, 0x70, 0x07, 0x77,
  0x77, 0x07, 0x70, 0x77,
  0x77, 0x07, 0x70, 0x77
};
Image player_sprite_set(player_sprites);

struct map_struct {
  const uint8_t *map_data;
  uint8_t width, height;
};
map_struct current_map;

struct player_struct {
  uint8_t x, y, direction, animation;
};
player_struct player;

struct camera_struct {
  int16_t x, y;
};
camera_struct camera;

void setup() {
  gb.begin();
  current_map.map_data = map01;
  current_map.width = current_map.height = 32;
  camera.x = camera.y = 0;
  player.x = player.y = 4;
  player.direction = player.animation = 0;
}

void loop() {
  while (true) {
    if (gb.update()) {
      int8_t x_direction = -gb.buttons.repeat(BUTTON_LEFT, 1) * (player.x > 0) + gb.buttons.repeat(BUTTON_RIGHT, 1) * (player.x < current_map.width - 1);
      int8_t y_direction = -gb.buttons.repeat(BUTTON_UP, 1) * (player.y > 0) + gb.buttons.repeat(BUTTON_DOWN, 1) * (player.y < current_map.height - 1);
      if (!x_direction != !y_direction) {
        player.direction = (1 + x_direction) * (x_direction != 0);
        player.direction = (2 + y_direction) * (y_direction != 0 || player.direction == 0);
        for (byte i = 1; i <= TILE_SIZE; i++) {
          draw_map();
          player.animation += i % 2;
          player.animation *= player.animation < 2 && i < TILE_SIZE;
          camera.x = player.x * TILE_SIZE - gb.display.width() / 2 + TILE_SIZE / 2 + i * x_direction;
          camera.x = camera.x * (camera.x > 0) + (current_map.width * TILE_SIZE - gb.display.width() - camera.x) * (camera.x > current_map.width * TILE_SIZE - gb.display.width());
          camera.y = player.y * TILE_SIZE - gb.display.height() / 2 + TILE_SIZE / 2 + i * y_direction;
          camera.y = camera.y * (camera.y > 0) + (current_map.height * TILE_SIZE - gb.display.height() - camera.y) * (camera.y > current_map.height * TILE_SIZE - gb.display.height());
          player_sprite_set.setFrame(player.direction * 2 + player.animation);
          gb.display.drawImage(player.x * TILE_SIZE - camera.x + i * x_direction, player.y * TILE_SIZE - camera.y + i * y_direction, player_sprite_set);
          while (!gb.update());
          delay(10);
        }
        player.x += x_direction;
        player.y += y_direction;
      }
      x_direction = y_direction = 0;
    }
  }
}

void draw_map() {
  for (byte y = 0; y <= gb.display.height() / TILE_SIZE + 1; y++) {
    for (byte x = 0; x <= gb.display.width() / TILE_SIZE + 1; x++) {
      int tile_x = camera.x / TILE_SIZE + x;
      int tile_y = camera.y / TILE_SIZE + y;
      if (tile_x >= 0 && tile_x < current_map.width && tile_y >= 0 && tile_y < current_map.height) {
        tile_set.setFrame(current_map.map_data[tile_y * current_map.width + tile_x]);
        gb.display.drawImage(x * TILE_SIZE - camera.x % TILE_SIZE, y * TILE_SIZE - camera.y % TILE_SIZE, tile_set);
      }
    }
  }
}
