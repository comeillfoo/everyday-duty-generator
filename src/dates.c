#include "dates.h"

static const enum weekdays ANCHOR_YEARS[] = {
  [ 0 ] = WD_WEDNESDAY,
  [ 1 ] = WD_TUESDAY,
  [ 2 ] = WD_SUNDAY,
  [ 3 ] = WD_FRIDAY
};

static const uint8_t NUMBER_DAYS_IN_MONTHS[] = {
  [ M_JANUARY   ] = 31,
  [ M_FEBRUARY  ] = 28,
  [ M_MARCH     ] = 31,
  [ M_APRIL     ] = 30,
  [ M_MAY       ] = 31,
  [ M_JUNE      ] = 30,
  [ M_JULY      ] = 31,
  [ M_AUGUST    ] = 31,
  [ M_SEPTEMBER ] = 30,
  [ M_OCTOBER   ] = 31,
  [ M_NOVEMBER  ] = 30,
  [ M_DECEMBER  ] = 31
};

const char* RU_BRIEF_MONTH_NAME[] = {
  [ M_JANUARY   ] = "янв",
  [ M_FEBRUARY  ] = "фев",
  [ M_MARCH     ] = "мар",
  [ M_APRIL     ] = "апр",
  [ M_MAY       ] = "май",
  [ M_JUNE      ] = "июн",
  [ M_JULY      ] = "июл",
  [ M_AUGUST    ] = "авг",
  [ M_SEPTEMBER ] = "сен",
  [ M_OCTOBER   ] = "окт",
  [ M_NOVEMBER  ] = "ноя",
  [ M_DECEMBER  ] = "дек"
};

static bool is_leap_year( const int16_t year ) {
  return ( ( year % 4 ) == ( year % 100 ) ); // ( year % 4 == 0 ) xor ( year % 100 == 0 )
}

static enum weekdays weekday_find_century_anchor( const int16_t year ) {
  return ANCHOR_YEARS[ ( year / 100 + 1 ) % 4 ];
}

static enum weekdays weekday_find_year_anchor( const int16_t year ) {
  const int16_t ylst2digs = year % 100;
  const int16_t lst2fits12 = ylst2digs / 12;  // calculation 1
  const int16_t lst2rest = ylst2digs % 12;    // calculation 2
  const int16_t lst2restfits4 = lst2rest / 4; // calculation 3
  const enum weekdays century_anchor =
    weekday_find_century_anchor( year );      // calculation 4
  return ( enum weekdays ) ( ( lst2fits12 + lst2rest + lst2restfits4 + century_anchor ) % 7 ); // doomsday of the provided year
}

static const int8_t JAN_DOOMSDAY = 3;

// calculating using Doomsday algorithm
struct date date_find_first_year_weekday( const enum weekdays weekday, const int16_t year ) {
  const enum weekdays curyearwkday = weekday_find_year_anchor( year );
  const int8_t wkdaydiff = ( weekday - curyearwkday ); // 0
  const int8_t day = JAN_DOOMSDAY + ( is_leap_year( year )? 1 : 0 ) + wkdaydiff;
  return ( struct date ) { .day = day + ( ( day < 0 )? 7 : 0 ), .weekday = weekday, .month = M_JANUARY, .year = year };
}

struct date date_next_weekday( const struct date date ) {
  const int8_t number_days_in_current_month = NUMBER_DAYS_IN_MONTHS[ date.month ] + ( ( date.month == M_FEBRUARY && is_leap_year( date.year ) )? 1 : 0 );
  const int8_t next_day = date.day + 7;
  const enum months next_month = date.month + ( ( next_day > number_days_in_current_month )? 1 : 0 );
  const int16_t next_year = date.year + ( ( next_month > 12 )? 1 : 0 );
  return ( struct date ) { .day = next_day % ( ( next_day == number_days_in_current_month )? ( next_day + 1 ) : number_days_in_current_month ), .weekday = date.weekday, .month = next_month % 12, .year = next_year };
}