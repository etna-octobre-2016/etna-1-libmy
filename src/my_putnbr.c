#include      "headers/my.h"

int           my_putnbr(int nb)
{
  int         i;
  int         figure;
  int         output_length;
  static char zero = '0';

  if (nb == INT_MIN)
    return (INT_MIN);
  if (nb == INT_MAX)
    return (INT_MAX);

  output_length = 0;
  for (i = 0; i < 10; ++i)
  {
    figure = (nb < 0) ? -(nb % 10) : (nb % 10);
    if (i == figure)
    {
      if (nb >= 10 || nb <= -10)
        output_length += my_putnbr(nb / 10);
      else if (nb < 0)
        output_length += my_putchar('-');

      output_length += my_putchar((zero + i));
    }
  }
  return (output_length);
}