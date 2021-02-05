#include "janitors.h"

const struct janitor BLOCK_JANITORS[] = {
  [ 0 ] = { .name =     "Ленар", .room = RT_THREE_ROOM, .priority = 0 },
  [ 1 ] = { .name =    "Даниил", .room =   RT_TWO_ROOM, .priority = 1 },
  [ 2 ] = { .name = "Никита Д.", .room = RT_THREE_ROOM, .priority = 2 },
  [ 3 ] = { .name = "Владислав", .room =   RT_TWO_ROOM, .priority = 3 },
  [ 4 ] = { .name = "Никита М.", .room = RT_THREE_ROOM, .priority = 4 }
};