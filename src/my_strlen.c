#include  "headers/my.h"

int       my_strlen(char *str)
{
  int     len;

  for (len = 0; str[len] != '\0'; len++);
  return (len);
}
