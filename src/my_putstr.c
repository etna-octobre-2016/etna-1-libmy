#include  "headers/my.h"

void      my_putstr(char *str)
{
  int     i;

  for (i = 0; str[i] != '\0'; i++)
    my_putchar(str[i]);

  my_putchar('\0');
}
