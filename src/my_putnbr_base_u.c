#include            "headers/my.h"

int                 my_putnbr_base_u(unsigned int nb, char *base)
{
  int               output_length;
  unsigned int      baseLength;
  unsigned int      i;
  unsigned int      figure;

  if (nb == UINT_MAX)
    return (UINT_MAX);

  baseLength = my_strlen(base);
  output_length = 0;
  for (i = 0; i < baseLength; ++i)
  {
    figure = nb % baseLength;
    if (i == figure)
    {
      if (nb >= baseLength)
        output_length += my_putnbr_base(nb / baseLength, base);

      output_length += my_putchar(base[i]);
    }
  }
  return (output_length);
}