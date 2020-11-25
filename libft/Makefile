# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ayundina <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/07 12:38:25 by ayundina       #+#    #+#                 #
#    Updated: 2019/11/12 21:06:27 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc
GCCFLAGS = -g -Wall -Wextra -Werror

FILES_STDLIB = ft_atoi \
							 ft_bzero \
							 ft_isalnum \
							 ft_isalpha \
							 ft_isascii \
							 ft_isdigit \
							 ft_isprint \
							 ft_itoa \
							 ft_memalloc \
							 ft_memccpy \
							 ft_memchr \
							 ft_memcmp \
							 ft_memcpy \
							 ft_memdel \
							 ft_memmove \
							 ft_memset \
							 ft_putchar_fd \
							 ft_putchar \
							 ft_putendl_fd \
							 ft_putendl \
							 ft_putnbr_fd \
							 ft_putnbr \
							 ft_putstr_fd \
							 ft_putstr \
							 ft_strcat \
							 ft_strchr \
							 ft_strclr \
							 ft_strcmp \
							 ft_strcpy \
							 ft_strdel \
							 ft_strdup \
							 ft_strequ \
							 ft_striter \
							 ft_striteri \
							 ft_strjoin \
							 ft_strlcat \
							 ft_strlen \
							 ft_strmap \
							 ft_strmapi \
							 ft_strncat \
							 ft_strncmp \
							 ft_strncpy \
							 ft_strnequ \
							 ft_strnew \
							 ft_strnstr \
							 ft_strrchr \
							 ft_strsplit \
							 ft_strstr \
							 ft_strsub \
							 ft_strtrim \
							 ft_tolower \
							 ft_toupper \
							 ft_lstnew \
							 ft_lstdelone \
							 ft_lstdel \
							 ft_lstadd \
							 ft_lstiter \
							 ft_lstmap \
							 ft_intlen \
							 ft_getnum \
							 ft_dupword \
							 ft_getwords \
							 ft_countwords \
							 ft_beg_sp ft_end_sp \
							 get_next_line \
							 ft_isint \
							 ft_error \
							 ft_modulo \
							 ft_iswhitespace

FILES_PRINTF = ft_printf \
							 ft_read_flags \
							 ft_upply_options \
							 ft_fl_hh \
							 ft_fl_h \
							 ft_fl_l \
							 ft_fl_ll \
							 ft_fl_capitll \
							 ft_fl_hash \
							 ft_conv_csp \
							 ft_conv_dibouxf \
							 ft_conv_none \
							 ft_fl_hash \
							 ft_fl_plus \
							 ft_fl_sp \
							 ft_fl_precision \
							 ft_fl_minus \
							 ft_fl_zero \
							 ft_fl_width \
							 ft_ulltoa_base \
							 ft_dtoa \
							 ft_arandomtoi 

HEADERS = libft \
					libftprintf

SRCFOLDER_STDLIB = ft_stdlib
SRC_STDLIB = $(FILES_STDLIB:%=$(SRCFOLDER_STDLIB)/%.c)
OBJFOLDER_STDLIB = obj_stdlib
OBJ_STDLIB = $(FILES_STDLIB:%=$(OBJFOLDER_STDLIB)/%.o)

SRCFOLDER_PRINTF = ft_printf
SRC_PRINTF = $(FILES_PRINTF:%=$(SRCFOLDER_PRINTF)/%.c)
OBJFOLDER_PRINTF = obj_printf
OBJ_PRINTF = $(FILES_PRINTF:%=$(OBJFOLDER_PRINTF)/%.o)

INCLUDEFOLDER = include
INCLUDE = $(HEADERS:%=$(INCLUDEFOLDER)/%.h)
RM = rm -rf
GREEN = \033[32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ_STDLIB) $(OBJ_PRINTF)
	@ ar rc $(NAME) $(OBJ_STDLIB) $(OBJ_PRINTF)
	@ ranlib $(NAME)
	@ echo "${GREEN}	Compiled" $(NAME) "${NC}"

$(OBJFOLDER_STDLIB)/%.o : $(SRCFOLDER_STDLIB)/%.c $(INCLUDE)
	@ mkdir -p $(OBJFOLDER_STDLIB)
		$(GCC) $(GCCFLAGS) -I $(INCLUDEFOLDER) $< -c -o $@

$(OBJFOLDER_PRINTF)/%.o : $(SRCFOLDER_PRINTF)/%.c $(INCLUDE)
	@ mkdir -p $(OBJFOLDER_PRINTF)
		$(GCC) $(GCCFLAGS) -I $(INCLUDEFOLDER) $< -c -o $@

clean:
	@ $(RM) $(OBJFOLDER_STDLIB) $(OBJFOLDER_PRINTF)
	@ echo "${GREEN}	Cleaned libft objects${NC}"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "${GREEN}	Cleaned" $(NAME) "${NC}"

re: clean fclean all
