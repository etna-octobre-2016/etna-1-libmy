# Shell commands variables
# -----------------------------------------------
AR = ar -r
CC = gcc -W -Wall -Werror -std=c89
RM = rm -f

# Library variables
# -----------------------------------------------
NAME = libmy.a
SRC  = src/my_putchar.c\
	src/my_putstr.c\
	src/my_strlen.c\
	src/my_putnbr.c
OBJ  = $(SRC:%.c=%.o)

# Archiving and indexing
# -----------------------------------------------
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

# Compiling
# -----------------------------------------------
$(OBJ):	$(SRC)
	$(foreach file, $(SRC), $(CC) -c $(file) -o $(file:%.c=%.o);)

# Default rule
# -----------------------------------------------
all: $(NAME)

# Object files removing
# -----------------------------------------------
clean:
	$(RM) $(OBJ)

# Object files and binary removing
# -----------------------------------------------
fclean: clean
	$(RM) $(NAME)

# Recompiling everything
# -----------------------------------------------
re: fclean all
