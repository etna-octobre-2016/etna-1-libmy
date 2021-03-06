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
  int       my_putnbr_base(int, char *);
  int       my_putnbr_base_u(unsigned int, char *);
  int       my_putnbr(int);
  int       my_putnbr_u(unsigned int);
  int       my_strlen(char *);
#endif
