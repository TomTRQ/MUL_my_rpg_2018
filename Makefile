##
## EPITECH PROJECT, 2019
## makefile
## File description:
## use to compile
##

DISPLAY =   ./src/display/
STATE   =   ./src/state/
BUTTON  =   ./src/button/
PLAYER  =   ./src/player/
ENEMIES =   ./src/enemies/
PNJ     =   ./src/pnj/
MUSIC   =   ./src/music/
FIGHT   =   ./src/fight/
LIB     =   ./lib/
FIGHT 	=	src/fight/
INVENTORY	=	./src/inventory/

SRC	=	$(DISPLAY)display.c		\
		$(DISPLAY)change_scene.c	\
		$(DISPLAY)modify_cursor.c	\
		$(DISPLAY)night.c		\
		$(DISPLAY)print_text_line.c \
		$(DISPLAY)boat_particule.c	\
		$(DISPLAY)destroy_free_all.c    \
		$(DISPLAY)is_map_or_not.c   \
		main.c				\
		$(FIGHT)anim_fight.c	\
		$(FIGHT)end_fight.c		\
		$(FIGHT)fight.c			\
		$(FIGHT)turns_fight.c		\
		$(FIGHT)check_fight.c		\
		$(FIGHT)lifebar.c   \
		$(FIGHT)print_damage.c  \
		$(STATE)initiate_button.c	\
		$(STATE)initiate_scene.c	\
		$(STATE)initiate_sf_object.c	\
		$(STATE)initiate_state.c	\
		$(STATE)initiate_clock_struct.c	\
		$(STATE)load_map.c		\
		$(BUTTON)change_volume.c	\
		$(BUTTON)check_button.c	\
		$(BUTTON)exit_game.c		\
		$(BUTTON)pause_game.c		\
		$(BUTTON)start_game.c		\
		$(PLAYER)ask_name_player.c	\
		$(PLAYER)initiate_player.c	\
		$(PLAYER)handle_player_movements.c	\
		$(PLAYER)look_environement.c		\
		$(PLAYER)go_out_in_building.c	\
		$(PLAYER)boat.c		\
		$(PLAYER)move_camera.c	\
		$(PLAYER)walk_effect.c	\
		$(PLAYER)move_to_boss.c \
		$(ENEMIES)initiate_enemies.c	\
		$(ENEMIES)initiate_enemies_on_scene.c   \
		$(PNJ)initiate_pnj.c		\
		$(PNJ)initiate_dialogs.c	\
		$(PNJ)pnj_pictures_and_name.c	\
		$(MUSIC)initiate_music.c \
		$(MUSIC)destroy_music.c  \
		$(MUSIC)fight_musics.c  \
		$(LIB)get_word.c  \
		$(LIB)check_element_str.c \
		$(LIB)compare_str.c		\
		$(LIB)free_all.c			\
		$(LIB)my_countlen.c		\
		$(LIB)my_getnbr.c			\
		$(LIB)my_strcopy.c		\
		$(LIB)parsing_with_char.c		\
		$(LIB)my_convert_to_int.c   \
		$(LIB)add_end_str.c		\
		$(LIB)out_of_map.c		\
		$(INVENTORY)display_head_inventory.c	\
		$(INVENTORY)display_inventory.c		\
		$(INVENTORY)init_inventory.c		\
		$(INVENTORY)inventory.c		\
		$(INVENTORY)inventory_game.c	\
		$(INVENTORY)left_corner_inventory.c		\
		$(INVENTORY)text_inventory.c	\
		$(INVENTORY)lib/int_to_str.c	\
		$(INVENTORY)lib/my_strdup.c	\

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LIBS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

CFLAGS	=	-pedantic -W -Wextra -Wall -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(TEST_O)
	@echo "Removing *.o"

fclean: clean
	@rm -f $(NAME)
	@echo "Removing binary"

re: clean fclean all

debug: clean change_rule

change_rule:
	$(eval CFLAGS = -pedantic -W -Wextra -Wall -Iinclude -g3)
