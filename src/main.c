#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "dates.h"
#include "rooms.h"
#include "janitors.h"

#define COLUMN_NUMBERS 20

extern const char* RU_BRIEF_MONTH_NAME[];
extern const char* RU_ROOM_TYPE_NAME[];
extern const struct janitor BLOCK_JANITORS[];

int main( int argc, char** argv ) {

  // step n: write document preamble
  printf( "\\documentclass[landscape, 8pt]{article}\n" );
  printf( "\\usepackage[default]{lato}" );
  printf( "\\usepackage[T2A]{fontenc}\n" );
  printf( "\\usepackage[utf8x]{inputenc}\n" );
  printf( "\\usepackage[english, russian]{babel}\n" );
  printf( "\\usepackage{vmargin}\n" );
  printf( "\\setmarginsrb{1cm}{0.2cm}{0.2cm}{0.2cm}{0pt}{0pt}{0pt}{0mm}\n" );
  printf( "\\setpapersize{A4}\n" );
  printf( "\\usepackage{booktabs}\n" );
  printf( "\\usepackage{pdflscape}\n" );
  printf( "\\renewcommand\\arraystretch{2}\n");
  printf( "\\pagestyle{empty}\n" );
  printf( "\\setlength{\\tabcolsep}{4pt}\n" );
  printf( "\\sloppy\n" );
  // step n+1: write document body
  printf( "\\begin{document}\n" );
  printf( "\\begin{landscape}\n" );
  printf( "\\section*{\\centerline{ График уборки }}\n" );
  printf( "\\paragraph*{\\centerline{ Ванна, раковина, зеркало, пол в ванной, туалет, мусорка, пол в туалете, пол в блоке } }\\mbox{}\\\n" );
  printf( "\\begin{table}[!ht]\n" );
  printf( "  \\scriptsize\n");
  printf( "  \\centering\n" );
  printf( "  \\begin{tabular}{cccccccccccccccccccccc}\n" );
  printf( "    \\toprule\n" );
  printf( "    " );
  const uint8_t total_duties = 100;
  for ( uint8_t duty_number = 1; duty_number < total_duties + 1; ++duty_number ) {
    printf( " & %"PRIu8, duty_number );
    if ( duty_number % COLUMN_NUMBERS == 0 ) {
      printf( "\\\\\\midrule\n" );
      for ( uint16_t room = 0; room < TOTAL_ROOM_TYPES; ++room ) {
        printf( "    %s", RU_ROOM_TYPE_NAME[ room ] );
        for ( uint16_t janitor = 0; janitor < COLUMN_NUMBERS; ++janitor )
          printf( " & %s", ( room == BLOCK_JANITORS[ janitor % 5 ].room )? BLOCK_JANITORS[ janitor % 5 ].name : "" );
        printf( "\\\\\n" );
      }
      printf( "    \\bottomrule\n" );
      printf( "  \\end{tabular}\n" );
      printf( "\\end{table}\n" );
      if ( duty_number == total_duties ) continue;
      printf( "\\begin{table}[!ht]\n" );
      printf( "  \\scriptsize\n");
      printf( "  \\centering\n" );
      printf( "  \\begin{tabular}{cccccccccccccccccccccc}\n" );
      printf( "    \\toprule\n" );
      printf( "    " );
    }
  }
  printf( "\\end{landscape}\n" );
  printf( "\\end{document}\n" );
  return 0;
}