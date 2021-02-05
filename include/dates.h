#ifndef _DATES_H
#define _DATES_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define FIRST_CENTURY 1900

enum months {
  M_JANUARY = 0,
  M_FEBRUARY,
  M_MARCH,
  M_APRIL,
  M_MAY,
  M_JUNE,
  M_JULY,
  M_AUGUST,
  M_SEPTEMBER,
  M_OCTOBER,
  M_NOVEMBER,
  M_DECEMBER
};

// Haruhi easter egg
enum weekdays {
  WD_SUNDAY = 0,
  WD_MONDAY,
  WD_TUESDAY,
  WD_WEDNESDAY,
  WD_THURSDAY,
  WD_FRIDAY,
  WD_SATURDAY
};

struct date {
  int8_t day;
  enum weekdays weekday;
  enum months month;
  int16_t year;
};

struct date date_find_first_year_weekday( const enum weekdays weekday, const int16_t year );

struct date date_next_weekday( const struct date date );

#endif // _DATES_H