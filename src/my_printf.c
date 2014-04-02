#include "headers/my.h"
#include "headers/my_printf.h"

void            my_printf(char *format, ...)
{
  t_identifier  ids[IDENTIFIERS_COUNT];

  init_identifiers(ids);
  if (identifiers_valid(format, ids))
  {
    my_putstr("identifers are valid\n");
  }
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
        printf("lorsque je trouve l'item, id = %c et que je passe un pointeur\n", ids[i].id);
        identifier->id = ids[i].id;
        identifier->func = ids[i].func;
      }
      return (1);
    }
  }
  return (0);
}

int             identifiers_valid(char *format, t_identifier *ids)
{
  int           format_length;
  int           i;
  int           identifier_found;
  int           valid;

  format_length = my_strlen(format);
  valid = 1;
  for (i = 0; format[i] != '\0' && valid == 1; i++)
  {
    if (format[i] == '%')
    {
      if (i == (format_length - 1)) /* When % is the last char */
      {
        my_putstr("my_printf: Error: Undefined identifier in format string\n");
        valid = 0;
      }
      else
      {
        identifier_found = 1;
      }
    }
    else if (identifier_found)
    {
      if (format[i] == ' ')
      {
        my_putstr("my_printf: Error: Undefined identifier in format string\n");
        valid = 0;
      }
      else if (identifier_match(format[i], ids, NULL) == 0)
      {
        my_putstr("my_printf: Error: Unknown identifier %");
        my_putchar(format[i]);
        my_putstr(" in format string\n");
        valid = 0;
      }
      else
      {
        identifier_found = 0;
      }
    }
  }
  return (valid);
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