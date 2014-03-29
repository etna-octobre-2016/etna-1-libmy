#ifndef MY_PRINTF
  #define         MY_PRINTF
  #define         IDENTIFIERS_COUNT 2
  typedef struct  s_identifier
  {
    char          id;
    void          (*func)();
  }               t_identifier;
  void            init_identifiers(t_identifier *);
  void            add_to_buffer(char, char *);
  int             identifier_match(char, t_identifier *, t_identifier *);
#endif
