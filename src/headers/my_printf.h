#ifndef MY_PRINTF
  #define         MY_PRINTF

  typedef struct  s_identifier
  {
    char          id;
    void          (*func)();
  }               t_identifier;
  void init_identifiers(t_identifier *);
#endif
