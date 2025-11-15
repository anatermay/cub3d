# **************************************************************************** #
#                                                                              #
#                                   MAKEFILE                                   #
#                                                                              #
#                             🐙 GitHub: AnaTerMay                             #
#                        📧 aternero@student.42malaga.com                      #
#                                                                              #
# **************************************************************************** #

# *** THE INIT ____________________________________________________________*** #

NAME 					= cub3D
CC 						= cc
CFLAGS 					= -Wall -Werror -Wextra -g
MLX42 					= ./MLX42
LIBFT 					= ./resources/libft
FT_PRINTF				= ./resources/ft_printf
INCLUDES 				= -I$(MLX42)/include -I$(LIBFT)/include -I$(FT_PRINTF) -Iincludes
LIBS 					= $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf
HEADERS					= -I./header_files

SOURCES_DIRECTORY 		= ./sources
OBJECTS_DIRECTORY 		= ./objects

SOURCES_FILES 			= main.c\
							parser/0_parser.c\
							parser/1_init_game.c\
							parser/2_init_file.c\
							parser/3_gnl_to_file.c\
							parser/4_init_coordinates.c\
							parser/5_count_coord.c\
							parser/6_init_vertical.c\
							parser/7_sorting.c\
							parser/8_process_data.c\
							parser/9_process_coordinates.c\
							parser/10_process_vertical.c\
							parser/11_process_map.c\
							parser/12_extract_map.c\
							parser/13_map_check.c\
							parser/14_valid_characters.c\
							parser/15_single_player.c\
							parser/16_flood_fill.c\
							parser/17_textures_loading.c\
							parser_utils/pu_ids.c\
							parser_utils/pu_length.c\
							parser_utils/pu_lines.c\
							parser_utils/pu_memfree.c\
							parser_utils/pu_memfree1.c\
							parser_utils/pu_player_position.c\
							parser_utils/pu_print.c\
							parser_utils/pu_space.c\
							parser_utils/pu_split.c\
							game_logic/start_game.c\
							game_logic/run_game.c\
							display/load_imgs.c\
							display/display.c\
							display/raycast.c\
							movement/mov_handler.c\
							movement/mov_loop.c\
							free.c

OBJECTS 			= $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES_FILES:.c=.o))

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@mkdir -p $(dir $@) > /dev/null
	@$(CC) $(HEADERS) $(CFLAGS) $(INCLUDES) -c $< -o $@ > /dev/null

$(NAME): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(MLX42)/build/libmlx42.a $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS) > /dev/null
	@echo "CUB3D: MAKE\t\t\t\t\t\t. . . OK"

$(MLX42)/build/libmlx42.a:
	@cmake -S $(MLX42) -B $(MLX42)/build > /dev/null
	@cmake --build $(MLX42)/build -j4 > /dev/null
	@echo "CUB3D: MLX42\t\t\t\t\t\t. . . OK"

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "CUB3D: LIBFT\t\t\t\t\t\t. . . OK"

$(FT_PRINTF)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF) > /dev/null
	@echo "CUB3D: FT_PRINTF\t\t\t\t\t. . . OK"

all: $(NAME)
	@echo "CUB3D: MAKE ALL\t\t\t\t\t\t. . . OK"

clean:
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@echo "CUB3D: MAKE CLEAN\t\t\t\t\t\t. . . OK"

fclean:
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@$(MAKE) -C $(LIBFT) fclean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) fclean > /dev/null
	@$(RM) -rf $(MLX42)/build
	@$(RM) $(NAME)
	@$(RM) sources/*.o
	@echo "CUB3D: MAKE FCLEAN\t\t\t\t\t. . . OK"

re: fclean all
	@echo "CUB3D: MAKE RE\t\t\t\t\t\t. . . OK"

.PHONY: all clean fclean re


# *** THE END _____________________________________________________________*** #

# **************************************************************************** #
#                                                                              #
#                                 END OF FILE                                  #
#                                                                              #
#                           ⭐ Made with passion at 42                         #
#                            🚀 Keep coding, keep growing                      #
#                                                                              #
# **************************************************************************** #
