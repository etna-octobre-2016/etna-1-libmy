#include "headers/my.h"
#include "headers/my_printf.h"

void            my_printf(char *format, ...)
{
  char          *buffer;
  int           i;
  int           identifier_found;
  t_identifier  ids[2];

  buffer = malloc(sizeof(char));
  buffer[0] = '\0';
  identifier_found = 0;
  init_identifiers(ids);
  for (i = 0; format[i] != '\0'; i++)
  {
    if (format[i] == '%')
    {
      identifier_found = 1;
    }
    else if (identifier_found)
    {
      break;
    }
    else
    {
      add_to_buffer(format[i], buffer);
    }
  }
  my_putstr(buffer);
  free(buffer);
}

void            init_identifiers(t_identifier *ids)
{
  ids[0].id   = 'c';
  ids[0].func = &my_putchar;
  ids[1].id   = 's';
  ids[1].func = &my_putstr;
}

void            add_to_buffer(char c, char *buffer)
{
  int           len;

  len = my_strlen(buffer);
  buffer = realloc(buffer, sizeof(char));
  buffer[len] = c;
  buffer[(len + 1)] = '\0';
}