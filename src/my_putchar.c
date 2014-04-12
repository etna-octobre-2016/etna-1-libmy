#include  "headers/my.h"

int       my_putchar(int c)
{
  write(1, &c, 1);
  return (1);
}
