#ifndef _JANITOR_H
#define _JANITOR_H

#include <stdint.h>

#include "rooms.h"

#define TOTAL_JANITORS 5

struct janitor {
  const char* name; // 4 bytes
  enum room_types room; // 4 bytes
  uint8_t priority; // 2 bytes
};

#endif // _JANITOR_H