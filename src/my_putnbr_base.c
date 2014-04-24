#include  "headers/my.h"

int       my_putnbr_base(int nb, char *base)
{
  int     baseLength;
  int     i;
  int     figure;
  int     output_length;

  if (nb == INT_MIN)
    return (INT_MIN);
  if (nb == INT_MAX)
    return (INT_MAX);

  baseLength = my_strlen(base);
  output_length = 0;
  for (i = 0; i < baseLength; ++i)
  {
    figure = (nb < 0) ? -(nb % baseLength) : (nb % baseLength);
    if (i == figure)
    {
      if (nb >= baseLength || nb <= -baseLength)
        output_length += my_putnbr_base(nb / baseLength, base);
      else if (nb < 0)
        output_length += my_putchar('-');

      output_length += my_putchar(base[i]);
    }
  }
  return (output_length);
}