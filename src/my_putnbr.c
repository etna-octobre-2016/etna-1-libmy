#include        "headers/my.h"

void            my_putnbr(int nb)
{
  int           i;
  int           figure;
  char          current_char;
  static char   zero_char = '0';

  if (nb == INT_MIN)
  {
    my_putstr("my_putnbr: error: integer overflow\n");
    return;
  }
  current_char = '0';
  for (i = 0; i < 10; ++i)
  {
    figure = (nb < 0) ? -(nb % 10) : (nb % 10);
    if (i == figure)
    {
      current_char = zero_char + i;
      if (nb > 10 || nb < -10)
      {
        my_putnbr(nb / 10);
      }
      else if (nb < 0)
      {
        my_putchar('-');
      }
      my_putchar(current_char);
    }
  }
}