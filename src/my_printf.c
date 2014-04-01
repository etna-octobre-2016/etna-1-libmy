#include "headers/my.h"
#include "headers/my_printf.h"

void            my_printf(char *format, ...)
{
  char          *buffer;
  int           i;
  int           identifier_found;
  t_identifier  identifier;
  t_identifier  *identifier_ptr;
  t_identifier  ids[IDENTIFIERS_COUNT];

  buffer = init_buffer(NULL);
  identifier_found = 0;
  identifier_ptr = &identifier;
  init_identifiers(ids);
  for (i = 0; format[i] != '\0'; i++)
  {
    if (format[i] == '%')
    {
      identifier_found = 1;
    }
    else if (identifier_found)
    {
      if (identifier_match(format[i], identifier_ptr, ids))
      {
        my_putstr(buffer);
        my_putchar('\n');
        buffer = init_buffer(buffer);
        identifier_found = 0;
      }
      else
      {
        my_putstr("Error: Unknown identifier\n");
      }
    }
    else
    {
      add_to_buffer(format[i], buffer);
    }
  }
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
  if (buffer == NULL)
  {
    perror("Error: ");
    free(buffer);
    exit(1);
  }
  buffer[len] = c;
  buffer[(len + 1)] = '\0';
}

int             identifier_match(char id, t_identifier *identifier, t_identifier *ids)
{
  int           i;

  for (i = 0; i < IDENTIFIERS_COUNT; i++)
  {
    if (id == ids[i].id)
    {
      printf("lorsque je trouve l'item, id = %c\n", ids[i].id);
      identifier->id = ids[i].id;
      identifier->func = ids[i].func;
      return (1);
    }
  }
  return (0);
}

char            *init_buffer(char *old_buffer)
{
  char          *buffer;

  if (old_buffer != NULL)
    free(old_buffer);

  buffer = malloc(sizeof(char));
  if (buffer == NULL)
  {
    perror("Error: ");
    exit(1);
  }
  buffer[0] = '\0';
  return (buffer);
}