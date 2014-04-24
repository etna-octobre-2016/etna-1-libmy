#include      "headers/my.h"

int           my_putnbr_u(unsigned int nb)
{
  int         i;
  int         figure;
  int         output_length;
  static char zero = '0';

  if (nb == UINT_MAX)
    return (UINT_MAX);

  output_length = 0;
  for (i = 0; i < 10; ++i)
  {
    figure = nb % 10;
    if (i == figure)
    {
      if (nb >= 10)
        output_length += my_putnbr(nb / 10);

      output_length += my_putchar((zero + i));
    }
  }
  return (output_length);
}