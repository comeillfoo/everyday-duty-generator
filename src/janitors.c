#include "janitors.h"

const struct janitor BLOCK_JANITORS[] = {
  [ 0 ] = { .name = "*****", .room = RT_THREE_ROOM, .priority = 0 },
  [ 1 ] = { .name = "*****", .room =   RT_TWO_ROOM, .priority = 1 },
  [ 2 ] = { .name = "*****", .room = RT_THREE_ROOM, .priority = 2 },
  [ 3 ] = { .name = "*****", .room =   RT_TWO_ROOM, .priority = 3 },
  [ 4 ] = { .name = "*****", .room = RT_THREE_ROOM, .priority = 4 }
};
