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
LIBS 					= -L$(MLX42)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm  -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

SOURCES_DIRECTORY 		= ./sources
OBJECTS_DIRECTORY 		= ./objects

SOURCES_FILES 			= main.c\
							0_parser.c\
							1_init_game.c\
							2_init_file.c\
							3_gnl_to_file.c\
							4_init_coordinates.c\
							5_count_coord.c\
							6_init_vertical.c\
							7_sorting.c\
							8_process_data.c\
							9_process_coordinates.c\
							10_process_vertical.c\
							11_process_map.c\
							12_extract_map.c\
							13_map_check.c\
							14_valid_characters.c\
							15_single_player.c\
							16_validation_walls.c\
							17_flood_fill.c\
							pu_ids.c\
							pu_length.c\
							pu_lines.c\
							pu_memfree.c\
							pu_memfree1.c\
							pu_player_position.c\
							pu_print.c\
							pu_space.c\
							pu_split.c

OBJECTS 			= $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES_FILES:.c=.o))

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(MLX42)/build/libmlx42.a $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)
	@echo "CUB3D: MAKE\t\t\t\t. . . OK"

$(MLX42)/build/libmlx42.a:
	@cmake -S $(MLX42) -B $(MLX42)/build
	@cmake --build $(MLX42)/build -j4
	@echo "CUB3D: MLX42\t\t\t\t. . . OK"

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "CUB3D: LIBFT\t\t\t\t. . . OK"

$(FT_PRINTF)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF) > /dev/null
	@echo "CUB3D: FT_PRINTF\t\t\t. . . OK"

all: $(NAME)
	@echo "CUB3D: MAKE ALL\t\t\t. . . OK"

clean:
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@echo "CUB3D: MAKE CLEAN\t\t\t. . . OK"

fclean:
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@$(MAKE) -C $(LIBFT) fclean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) fclean > /dev/null
	@$(RM) -rf $(MLX42)/build
	@$(RM) $(NAME)
	@$(RM) sources/*.o
	@echo "CUB3D: MAKE FCLEAN\t\t\t. . . OK"

re: fclean all
	@echo "CUB3D: MAKE RE\t\t\t. . . OK"

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
