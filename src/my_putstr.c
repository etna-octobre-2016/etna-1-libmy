#include  "headers/my.h"

int       my_putstr(char *str)
{
  int     i;

  for (i = 0; str[i] != '\0'; i++)
    my_putchar(str[i]);

  my_putchar('\0');
  return (i);
}
