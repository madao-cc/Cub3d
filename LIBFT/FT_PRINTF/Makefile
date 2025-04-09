CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rc

RM = rm -rf

# TEXT COLOR
GREEN = \033[92m
RESET = \033[0m

# SOURCE FOLDER
SRCFOLDER = src

# OBJS FOLDER
OBJFOLDER = obj

SRC =	$(SRCFOLDER)/ft_dec2hex.c\
		$(SRCFOLDER)/ft_dec2hexptr.c\
		$(SRCFOLDER)/ft_intdup.c\
		$(SRCFOLDER)/ft_itoa_u.c\
		$(SRCFOLDER)/ft_lstprint.c\
		$(SRCFOLDER)/ft_parsemarker.c\
		$(SRCFOLDER)/ft_printf.c\
		$(SRCFOLDER)/ft_strout.c\
		$(SRCFOLDER)/ft_type.c\
		$(SRCFOLDER)/ft_type_c.c\
		$(SRCFOLDER)/ft_type_di.c\
		$(SRCFOLDER)/ft_type_p.c\
		$(SRCFOLDER)/ft_type_perc.c\
		$(SRCFOLDER)/ft_type_s.c\
		$(SRCFOLDER)/ft_type_u.c\
		$(SRCFOLDER)/ft_type_x.c\

OBJS = $(patsubst $(SRCFOLDER)/%.c, $(OBJFOLDER)/%.o, $(SRC))

TRIGGER_HEADERS = $(SRCFOLDER)/ft_printf.h

all: $(TRIGGER_HEADERS) $(OBJS)
	@echo "[$(GREEN)SUCCESS$(RESET)] FT PRINTF - OBJS CREATED"

$(OBJFOLDER)/%.o: $(SRCFOLDER)/%.c $(TRIGGER_HEADERS)
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< -o $@ -pg

clean:
	$(RM) $(OBJFOLDER)
	@echo "[$(GREEN)SUCCESS$(RESET)] FT PRINTF - ALL OBJS DELETED."

fclean: clean

re: fclean all

.SILENT:

.PHONY: all clean fclean re
