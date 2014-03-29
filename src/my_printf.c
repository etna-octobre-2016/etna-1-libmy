#include "headers/my.h"
#include "headers/my_printf.h"

void          my_printf(char *format, ...)
{
  t_identifier ids[2];

  init_identifiers(ids);
  ids[0].func('Y');
  ids[0].func('E');
  ids[0].func('S');
  ids[0].func('!');
  ids[0].func('\n');
  ids[1].func(format);
}

void          init_identifiers(t_identifier *ids)
{
  ids[0].id   = 'c';
  ids[0].func = &my_putchar;
  ids[1].id   = 's';
  ids[1].func = &my_putstr;
}