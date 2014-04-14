#include  "headers/my.h"

int       my_convert_to_base(int number, int base)
{
  int     result;

  if (number == 0 || base == 10)
    result = number;
  else
    result = (number % base) + (10 * my_convert_to_base(number / base, base));

  return (result);
}
