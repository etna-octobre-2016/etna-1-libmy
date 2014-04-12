#ifndef MY_PRINTF
  #define         MY_PRINTF
  #define         IDENTIFIERS_COUNT 3
  typedef struct  s_identifier
  {
    char          id;
    int           (*func)();
  }               t_identifier;
  void            init_identifiers(t_identifier *);
  void            add_to_buffer(char, char *);
  int             identifier_match(char, t_identifier *, t_identifier *);
  int             count_identifiers(char *, t_identifier *);
  char            *init_buffer(char *);
#endif
