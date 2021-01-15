PUSH_SWAP = push_swap
INT_GENERATOR = random_int_set
CXX = gcc
CXXFLAGS = -Wall -Wextra -Werror -g

PS_FILES =	main \
				create_stack_a_and_b \
				print_stack \
				operation \

IG_FILES = int_set_generator

HEADERS =	push_swap

SRCFOLDER = src
PS_SRC = $(PS_FILES:%=$(SRCFOLDER)/%.c)
IG_SRC = $(IG_FILES:%=$(SRCFOLDER)/%.c)

OBJFOLDER = obj
PS_OBJ = $(PS_FILES:%=$(OBJFOLDER)/%.o)
IG_OBJ = $(IG_FILES:%=$(OBJFOLDER)/%.o)

INCLFOLDER = include
INCLUDE = $(HEADERS:%=$(INCLFOLDER)/%.h)

LIBFTINCLFOLDER = libft/include
LIBFTFOLDER = libft
LIBFT = libft/libft.a

RM = rm -f
GREEN = \033[32m
NC = \033[0m

all: $(OBJFOLDER) $(PUSH_SWAP) $(INT_GENERATOR)

$(OBJFOLDER):
	@ mkdir -p $(OBJFOLDER)

$(OBJFOLDER)/%.o : $(SRCFOLDER)/%.c $(INCLUDE)
	$(CXX) $(CXXFLAGS) -I $(INCLFOLDER) -I $(LIBFTINCLFOLDER) $< -c -o $@

$(PUSH_SWAP): $(PS_OBJ) $(LIBFT)
	@ echo "${GREEN}	Compiled object files${NC}"
	$(CXX) $(CXXFLAGS) -I $(INCLFOLDER) $(PS_OBJ) -o $(PUSH_SWAP) -L $(LIBFTFOLDER) -lft
	@ echo "${GREEN}	Compiled" $(PUSH_SWAP) "${NC}"

$(LIBFT):
	@ make -C $(LIBFTFOLDER)

$(INT_GENERATOR): $(IG_OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLFOLDER) $(IG_OBJ) -o $(INT_GENERATOR)
	@ echo "${GREEN}	Compiled" $(INT_GENERATOR) "${NC}"

clean:
	@ make clean -C $(LIBFTFOLDER)
	@ $(RM) -rf $(OBJFOLDER)
	@ echo "${GREEN}	Cleaned objects${NC}"

fclean: clean
	@ make fclean -C $(LIBFTFOLDER)
	@ $(RM) $(PUSH_SWAP) $(INT_GENERATOR)
	@ echo "${GREEN}	Cleaned" $(PUSH_SWAP) $(INT_GENERATOR) "${NC}"

re: fclean all
