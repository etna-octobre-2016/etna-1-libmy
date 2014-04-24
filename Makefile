# Shell commands variables
# -----------------------------------------------
AR = ar -r
CC = gcc -W -Wall -Werror -std=c89
RM = rm -f

# Library variables
# -----------------------------------------------
NAME = libmy_printf_`uname -m`-`uname -s`
OBJ  = $(SRC:%.c=%.o)
SRC  = src/my_putchar.c\
	src/my_putstr.c\
	src/my_strlen.c\
	src/my_putnbr_base.c\
	src/my_putnbr.c\
	src/my_putnbr_u.c\
#	src/my_printf.c

# Default rule
# -----------------------------------------------
all: my_printf_static my_printf_dynamic

# Object files removing
# -----------------------------------------------
clean:
	$(RM) $(OBJ)

# Object files and binary removing
# -----------------------------------------------
fclean: clean
	$(RM) $(NAME).a $(NAME).so

# Static library compiling
# -----------------------------------------------
my_printf_static: $(SRC)
	$(foreach file, $(SRC), $(CC) -c $(file) -o $(file:%.c=%.o);)
	$(AR) $(NAME).a $(OBJ)
	ranlib $(NAME).a

my_printf_dynamic: $(SRC)
	$(CC) -shared -o $(NAME).so $(SRC)