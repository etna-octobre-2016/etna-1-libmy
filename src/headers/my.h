#ifndef MY_H
  #define   MY_H
  #include  <limits.h>
  #include  <stdarg.h>
  #include  <stdio.h>
  #include  <stdlib.h>
  #include  <unistd.h>

  int       my_printf(char *, ...);
  int       my_putchar(int);
  int       my_putstr(char *);
  int       my_putnbr(int);
  int       my_strlen(char *);
  int       my_convert_to_base(int, int);
#endif
