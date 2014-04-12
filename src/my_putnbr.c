#include        "headers/my.h"

int             my_putnbr(int nb)
{
  int           i;
  int           figure;
  int           output_length;
  char          current_char;
  static char   zero_char = '0';

  if (nb == INT_MIN)
  {
    my_putstr("my_putnbr: error: integer overflow\n");
    return (-1);
  }
  current_char = '0';
  output_length = 0;
  for (i = 0; i < 10; ++i)
  {
    figure = (nb < 0) ? -(nb % 10) : (nb % 10);
    if (i == figure)
    {
      current_char = zero_char + i;
      if (nb > 10 || nb < -10)
      {
        output_length += my_putnbr(nb / 10);
      }
      else if (nb < 0)
      {
        output_length += my_putchar('-');
      }
      output_length += my_putchar(current_char);
    }
  }
  return (output_length);
}