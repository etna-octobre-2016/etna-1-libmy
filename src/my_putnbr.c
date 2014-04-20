#include        "headers/my.h"

int             my_putnbr(int nb, int base, int uppercase)
{
  int           i;
  int           figure;
  int           output_length;
  static char   *baseChars = "0123456789abcdef";

  if (nb == INT_MIN)
  {
    my_putstr("my_putnbr: error: integer overflow\n");
    return (-1);
  }
  if (base > my_strlen(baseChars))
  {
    my_putstr("my_putnbr: error: base over limit\n");
    return (-1);
  }
  output_length = 0;
  for (i = 0; i < base; ++i)
  {
    figure = (nb < 0) ? -(nb % base) : (nb % base);
    if (i == figure)
    {
      if (nb >= base || nb <= -base)
        output_length += my_putnbr(nb / base, base, uppercase);
      else if (nb < 0)
        output_length += my_putchar('-');

      if (uppercase && baseChars[i] >= 97 && baseChars[i] <= 122)
        output_length += my_putchar((baseChars[i] - 32));
      else
        output_length += my_putchar(baseChars[i]);
    }
  }
  return (output_length);
}