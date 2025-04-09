CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rc

RM = rm -rf

# TEXT COLOR
GREEN = \033[92m
RESET = \033[0m

NAME = libft.a

# FOLDER PRINTF
FOLDER1 = FT_PRINTF

# FOLDER GET_NEXT_LINE
FOLDER2 = GET_NEXT_LINE

# SOURCE FOLDER
SRCFOLDER = src

# OBJS FOLDER
OBJFOLDER = obj

SRC =	$(SRCFOLDER)/ft_atoi.c\
		$(SRCFOLDER)/ft_bzero.c\
		$(SRCFOLDER)/ft_calloc.c\
		$(SRCFOLDER)/ft_isalnum.c\
		$(SRCFOLDER)/ft_isalpha.c\
		$(SRCFOLDER)/ft_isascii.c\
		$(SRCFOLDER)/ft_isdigit.c\
		$(SRCFOLDER)/ft_isprint.c\
		$(SRCFOLDER)/ft_itoa.c\
		$(SRCFOLDER)/ft_lstadd_back.c\
		$(SRCFOLDER)/ft_lstadd_front.c\
		$(SRCFOLDER)/ft_lstclear.c\
		$(SRCFOLDER)/ft_lstdelone.c\
		$(SRCFOLDER)/ft_lstiter.c\
		$(SRCFOLDER)/ft_lstlast.c\
		$(SRCFOLDER)/ft_lstmap.c\
		$(SRCFOLDER)/ft_lstnew.c\
		$(SRCFOLDER)/ft_lstsize.c\
		$(SRCFOLDER)/ft_memchr.c\
		$(SRCFOLDER)/ft_memcmp.c\
		$(SRCFOLDER)/ft_memcpy.c\
		$(SRCFOLDER)/ft_memmove.c\
		$(SRCFOLDER)/ft_memset.c\
		$(SRCFOLDER)/ft_putchar_fd.c\
		$(SRCFOLDER)/ft_putendl_fd.c\
		$(SRCFOLDER)/ft_putnbr_fd.c\
		$(SRCFOLDER)/ft_putstr_fd.c\
		$(SRCFOLDER)/ft_split.c\
		$(SRCFOLDER)/ft_strchr.c\
		$(SRCFOLDER)/ft_strdup.c\
		$(SRCFOLDER)/ft_striteri.c\
		$(SRCFOLDER)/ft_strjoin.c\
		$(SRCFOLDER)/ft_strlcat.c\
		$(SRCFOLDER)/ft_strlcpy.c\
		$(SRCFOLDER)/ft_strlen.c\
		$(SRCFOLDER)/ft_strmapi.c\
		$(SRCFOLDER)/ft_strncmp.c\
		$(SRCFOLDER)/ft_strnstr.c\
		$(SRCFOLDER)/ft_strrchr.c\
		$(SRCFOLDER)/ft_strtrim.c\
		$(SRCFOLDER)/ft_substr.c\
		$(SRCFOLDER)/ft_tolower.c\
		$(SRCFOLDER)/ft_toupper.c\

SRC2 =	$(FOLDER1)/$(SRCFOLDER)/ft_dec2hex.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_dec2hexptr.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_intdup.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_itoa_u.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_lstprint.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_parsemarker.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_printf.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_strout.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_c.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_di.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_p.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_perc.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_s.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_u.c\
		$(FOLDER1)/$(SRCFOLDER)/ft_type_x.c\

SRC3 = $(FOLDER2)/$(SRCFOLDER)/get_next_line_bonus.c

OBJS = $(patsubst $(SRCFOLDER)/%.c, $(OBJFOLDER)/%.o, $(SRC))
OBJS2 = $(patsubst $(FOLDER1)/$(SRCFOLDER)/%.c, $(FOLDER1)/$(OBJFOLDER)/%.o, $(SRC2))
OBJS3 = $(patsubst $(FOLDER2)/$(SRCFOLDER)/%.c, $(FOLDER2)/$(OBJFOLDER)/%.o, $(SRC3))

TRIGGER_HEADERS = $(SRCFOLDER)/libft.h

all: $(NAME)

$(NAME): $(TRIGGER_HEADERS) $(OBJS) other_objs
	$(AR) $(NAME) $(OBJS) $(OBJS2) $(OBJS3)
	ranlib $(NAME)
	@echo "[$(GREEN)SUCCESS$(RESET)] LIBFT - $(NAME) CREATED."
	
$(OBJFOLDER)/%.o: $(SRCFOLDER)/%.c $(TRIGGER_HEADERS)
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< -o $@ -pg

other_objs:
	make -C $(FOLDER1)
	make -C $(FOLDER2)

clean:
	make clean -C $(FOLDER1)
	make clean -C $(FOLDER2)
	$(RM) $(OBJFOLDER)
	@echo "[$(GREEN)SUCCESS$(RESET)] LIBFT - ALL OBJS DELETED."
	
fclean: clean
	make fclean -C $(FOLDER1)
	make fclean -C $(FOLDER2)
	$(RM) $(NAME)
	@echo "[$(GREEN)SUCCESS$(RESET)] LIBFT - LIBRARY DELETED."

re: fclean all

.SILENT:

.PHONY: all clean fclean re other_objs
