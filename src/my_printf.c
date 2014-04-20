#include "headers/my.h"
#include "headers/my_printf.h"

int             my_printf(char *format, ...)
{
  char          *buffer;
  int           i;
  int           identifier_found;
  int           ids_count;
  int           output_length;
  t_identifier  identifier;
  t_identifier  *identifier_ptr;
  t_identifier  ids[IDENTIFIERS_COUNT];
  va_list       params;

  init_identifiers(ids);
  ids_count = count_identifiers(format, ids);
  output_length = 0; /* do not increment for \0 character */
  if (ids_count > -1)
  {
    buffer = init_buffer(NULL);
    identifier_found = 0;
    identifier_ptr = &identifier;
    va_start(params, format);
    for (i = 0; format[i] != '\0'; i++)
    {
      if (format[i] == '%')
      {
        identifier_found = 1;
      }
      else if (identifier_found)
      {
        if (identifier_match(format[i], ids, identifier_ptr))
        {
          output_length += my_strlen(buffer);
          my_putstr(buffer);

          if (identifier_ptr->id == 'c')
            output_length += identifier_ptr->func(va_arg(params, int));
          else if (identifier_ptr->id == 's')
            output_length += identifier_ptr->func(va_arg(params, char *));
          else if (identifier_ptr->id == 'd' || identifier_ptr->id == 'i')
            output_length += identifier_ptr->func(va_arg(params, int *), 10, 0);
          else if (identifier_ptr->id == 'o')
            output_length += identifier_ptr->func(abs((int)va_arg(params, int *)), 8, 0);
          else if (identifier_ptr->id == 'u')
            output_length += identifier_ptr->func(abs((int)va_arg(params, int *)), 10, 0);
          else if (identifier_ptr->id == 'x')
            output_length += identifier_ptr->func(abs((int)va_arg(params, int *)), 16, 0);
          else if (identifier_ptr->id == 'X')
            output_length += identifier_ptr->func(abs((int)va_arg(params, int *)), 16, 1);

          buffer = init_buffer(buffer);
          identifier_found = 0;
        }
      }
      else
      {
        add_to_buffer(format[i], buffer);
      }
    }
    my_putstr(buffer);
    va_end(params);
    free(buffer);
  }
  return (output_length);
}

void            init_identifiers(t_identifier *ids)
{
  ids[0].id   = 'c';
  ids[0].func = &my_putchar;
  ids[1].id   = 's';
  ids[1].func = &my_putstr;
  ids[2].id   = 'd';
  ids[2].func = &my_putnbr;
  ids[3].id   = 'i';
  ids[3].func = &my_putnbr;
  ids[4].id   = 'o';
  ids[4].func = &my_putnbr;
  ids[5].id   = 'u';
  ids[5].func = &my_putnbr;
  ids[6].id   = 'x';
  ids[6].func = &my_putnbr;
  ids[7].id   = 'X';
  ids[7].func = &my_putnbr;
}

void            add_to_buffer(char c, char *buffer)
{
  int           len;

  len = my_strlen(buffer);
  buffer = realloc(buffer, sizeof(char));
  if (buffer == NULL)
  {
    perror("my_printf: Error: ");
    free(buffer);
    exit(1);
  }
  buffer[len] = c;
  buffer[(len + 1)] = '\0';
}

int             identifier_match(char id, t_identifier *ids, t_identifier *identifier)
{
  int           i;

  for (i = 0; i < IDENTIFIERS_COUNT; i++)
  {
    if (id == ids[i].id)
    {
      if (identifier != NULL)
      {
        identifier->id = ids[i].id;
        identifier->func = ids[i].func;
      }
      return (1);
    }
  }
  return (0);
}

int             count_identifiers(char *format, t_identifier *ids)
{
  int           format_length;
  int           i;
  int           id_found;
  int           ids_count;

  format_length = my_strlen(format);
  id_found = 0;
  ids_count = 0;
  for (i = 0; format[i] != '\0' && ids_count > -1; i++)
  {
    if (format[i] == '%')
    {
      if (i == (format_length - 1)) /* When % is the last char */
      {
        my_putstr("my_printf: Error: Undefined identifier in format string\n");
        ids_count = -1;
      }
      else
      {
        id_found = 1;
      }
    }
    else if (id_found)
    {
      if (format[i] == ' ')
      {
        my_putstr("my_printf: Error: Undefined identifier in format string\n");
        ids_count = -1;
      }
      else if (identifier_match(format[i], ids, NULL) == 0)
      {
        my_putstr("my_printf: Error: Unknown identifier %");
        my_putchar(format[i]);
        my_putstr(" in format string\n");
        ids_count = -1;
      }
      else
      {
        id_found = 0;
        ids_count++;
      }
    }
  }
  return (ids_count);
}

char            *init_buffer(char *old_buffer)
{
  char          *buffer;

  if (old_buffer != NULL)
    free(old_buffer);

  buffer = malloc(sizeof(char));
  if (buffer == NULL)
  {
    perror("my_printf: Error: ");
    exit(1);
  }
  buffer[0] = '\0';
  return (buffer);
}