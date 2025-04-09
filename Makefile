MAKEFLAGS += -s

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

# TEXT COLOR
GREEN = \033[92m
RESET = \033[0m

NAME = cub3D

NAME_BONUS = cub3D_bonus

LIBFOLDER = LIBFT
LIBNAME = $(LIBFOLDER)/libft.a

LIBFOLDER2 = minilibx-linux
LIBNAME2 = $(LIBFOLDER2)/libmlx_Linux.a

# SOURCE FOLDER
SOURCEFOLDER = source
PARSERFOLDER = parser
INITCLOSEFOLDER = init_close
ERRORHANDLINGFOLDER = error_handling
GAMEFOLDER = game
MOVEMENTFOLDER = movement
RENDERFOLDER = render
PREGAMEFOLDER = pregame
MINIMAPFOLDER = minimap

# OBJS FOLDER
OBJFOLDER = obj

# HEADERS FOLDER
HEADFOLDER = includes

LIBX11 = -lX11 -lXext
LIBMATH = -lm

# FILES OF THE MANDATORY PART
SRC = 	$(SOURCEFOLDER)/main.c\
	$(SOURCEFOLDER)/$(ERRORHANDLINGFOLDER)/cub3d_error_handling_01.c\
	$(SOURCEFOLDER)/$(ERRORHANDLINGFOLDER)/furnace.c\
	$(SOURCEFOLDER)/$(ERRORHANDLINGFOLDER)/clean_and_leave.c\
	$(SOURCEFOLDER)/$(GAMEFOLDER)/game_loop.c\
	$(SOURCEFOLDER)/$(GAMEFOLDER)/ray.c\
	$(SOURCEFOLDER)/$(GAMEFOLDER)/ray_helpers.c\
	$(SOURCEFOLDER)/$(INITCLOSEFOLDER)/cub3d_init_close_01.c\
	$(SOURCEFOLDER)/$(MOVEMENTFOLDER)/check_movement.c\
	$(SOURCEFOLDER)/$(MOVEMENTFOLDER)/move_player.c\
	$(SOURCEFOLDER)/$(MOVEMENTFOLDER)/move_step.c\
	$(SOURCEFOLDER)/$(MOVEMENTFOLDER)/keyboard.c\
	$(SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_parser_01.c\
	$(SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_parser_02.c\
	$(SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_01.c\
	$(SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_02.c\
	$(SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_03.c\
	$(SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_04.c\
	$(SOURCEFOLDER)/$(PREGAMEFOLDER)/copy.c\
	$(SOURCEFOLDER)/$(PREGAMEFOLDER)/init.c\
	$(SOURCEFOLDER)/$(PREGAMEFOLDER)/init_helpers.c\
	$(SOURCEFOLDER)/$(PREGAMEFOLDER)/pregame.c\
	$(SOURCEFOLDER)/$(RENDERFOLDER)/rendering.c\
	$(SOURCEFOLDER)/$(RENDERFOLDER)/render_helpers.c\
	$(SOURCEFOLDER)/$(RENDERFOLDER)/texturing.c\

OBJS = $(patsubst $(SOURCEFOLDER)/%.c, $(OBJFOLDER)/%.o, $(SRC))

HEADER = $(HEADFOLDER)/cub.h

##################################
######## BONUS PART ##############
##################################
BONUS_FOLDER = bonus
BONUS_SOURCEFOLDER = $(BONUS_FOLDER)/source
BONUS_OBJFOLDER = $(BONUS_FOLDER)/obj

# FILES OF THE BONUS PART
BONUS_SRC = 	$(BONUS_SOURCEFOLDER)/main_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(MINIMAPFOLDER)/minimap_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(MINIMAPFOLDER)/minimap_2_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(ERRORHANDLINGFOLDER)/cub3d_error_handling_01_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(ERRORHANDLINGFOLDER)/furnace_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(ERRORHANDLINGFOLDER)/clean_and_leave_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(GAMEFOLDER)/game_loop_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(GAMEFOLDER)/ray_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(GAMEFOLDER)/ray_helpers_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(INITCLOSEFOLDER)/cub3d_init_close_01_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(MOVEMENTFOLDER)/check_movement_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(MOVEMENTFOLDER)/move_player_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(MOVEMENTFOLDER)/move_step_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(MOVEMENTFOLDER)/keyboard_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_parser_01_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_parser_02_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_01_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_02_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_03_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PARSERFOLDER)/cub3d_check_04_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PREGAMEFOLDER)/copy_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PREGAMEFOLDER)/init_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PREGAMEFOLDER)/init_helpers_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(PREGAMEFOLDER)/pregame_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(RENDERFOLDER)/rendering_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(RENDERFOLDER)/render_helpers_bonus.c\
	$(BONUS_SOURCEFOLDER)/$(RENDERFOLDER)/texturing_bonus.c\

BONUS_OBJS = $(patsubst $(BONUS_SOURCEFOLDER)/%.c, $(BONUS_OBJFOLDER)/%.o, $(BONUS_SRC))

##################################
########## RULES #################
##################################

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBNAME) $(LIBNAME2)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) $(LIBNAME2) -o $(NAME) $(LIBX11) $(LIBMATH)
	@echo "[$(GREEN)SUCCESS$(RESET)] $(NAME) CREATED."

$(OBJFOLDER)/%.o: $(SOURCEFOLDER)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBNAME):
	make -C $(LIBFOLDER)

$(LIBNAME2):
	make -C $(LIBFOLDER2)

##################################
######## BONUS RULES #############
##################################

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(HEADER) $(LIBNAME) $(LIBNAME2)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBNAME) $(LIBNAME2) -o $(NAME_BONUS) $(LIBX11) $(LIBMATH)
	@echo "[$(GREEN)SUCCESS$(RESET)] $(NAME_BONUS) CREATED."

$(BONUS_OBJFOLDER)/%.o: $(BONUS_SOURCEFOLDER)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#########################################################
########## VALGRIND, CLEAN, FCLEAN, RE ##################
#########################################################

valgrind:
	@valgrind --quiet --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck ./$(NAME) $(ARGS)

debug: CFLAGS += -g
debug: re

clean:
	$(RM) $(OBJFOLDER)/$(OBJS)
	$(RM) $(BONUS_OBJFOLDER)/$(BONUS_OBJS)
	make clean -C $(LIBFOLDER)
	@echo "[$(GREEN)SUCCESS$(RESET)] $(NAME) - ALL OBJS DELETED."

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFOLDER)
	make clean -C $(LIBFOLDER2)
	@echo "[$(GREEN)SUCCESS$(RESET)] $(NAME) - PROGRAM DELETED."

re: fclean all

.PHONY: all bonus clean fclean debug re valgrind
