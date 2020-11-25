NAME = push_swap
CXX = gcc
CXXFLAGS = -Wall -Wextra -Werror -g

FILES =	main \
				create_stack_a_and_b \
				find_num \
				operation

HEADERS =	push_swap

SRCFOLDER = src
SRC = $(FILES:%=$(SRCFOLDER)/%.c)
OBJFOLDER = obj
OBJ = $(FILES:%=$(OBJFOLDER)/%.o)

INCLFOLDER = include
INCLUDE = $(HEADERS:%=$(INCLFOLDER)/%.h)

LIBFTINCLFOLDER = libft/include
LIBFTFOLDER = libft
LIBFT = libft/libft.a

RM = rm -f
GREEN = \033[32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@ echo "${GREEN}	Compiled object files${NC}"
	$(CXX) $(CXXFLAGS) -I $(INCLFOLDER) $(OBJ) -o $(NAME) -L $(LIBFTFOLDER) -lft
	@ echo "${GREEN}	Compiled" $(NAME) "${NC}"

$(OBJFOLDER)/%.o : $(SRCFOLDER)/%.c $(INCLUDE)
	@ mkdir -p $(OBJFOLDER)
	$(CXX) $(CXXFLAGS) -I $(INCLFOLDER) -I $(LIBFTINCLFOLDER) $< -c -o $@

$(LIBFT):
	@ make -C $(LIBFTFOLDER)

clean:
	@ make clean -C $(LIBFTFOLDER)
	@ $(RM) $(OBJ)
	@ echo "${GREEN}	Cleaned objects${NC}"

fclean: clean
	@ make fclean -C $(LIBFTFOLDER)
	@ $(RM) $(NAME)
	@ echo "${GREEN}	Cleaned" $(NAME) "${NC}"

re: fclean all
