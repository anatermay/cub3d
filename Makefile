# **************************************************************************** #
#                                                                              #
#                                   MAKEFILE                                   #
#                                                                              #
#                             🐙 GitHub: AnaTerMay                             #
#                        📧 aternero@student.42malaga.com                      #
#                                                                              #
# **************************************************************************** #

# *** THE INIT ____________________________________________________________*** #

NAME 			= cub3d
CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra -g
MLX42 			= ./MLX42
LIBFT 			= ./resources/libft
FT_PRINTF		= ./resources/ft_printf
INCLUDES 		= -I$(MLX42)/include -I$(LIBFT)/include -I$(FT_PRINTF) -Iincludes

SOURCES_DIRECTORY 		= ./sources
OBJECTS_DIRECTORY 		= ./objects

SOURCES_FILES 		= 	main.c\
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
						pu_ids.c\
						pu_length.c\
						pu_memfree.c\
						pu_print.c\
						pu_space.c\
						pu_split.c

OBJECTS 			= $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES_FILES:.c=.o))

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@clear
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(OBJECTS)
	@clear
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
	@echo "MAKE\t\t\t\t. . . OK"

$(LIBFT)/libft.a:
	@clear
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "LIBFT\t\t\t\t. . . OK"

$(FT_PRINTF)/libftprintf.a:
	@clear
	@$(MAKE) -C $(FT_PRINTF) > /dev/null
	@echo "FT_PRINTF\t\t\t. . . OK"

all: $(NAME)
	@clear
	@echo "MAKE ALL\t\t\t. . . OK"

clean:
	@clear
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@echo "MAKE CLEAN\t\t\t. . . OK"

fclean:
	@clear
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) clean > /dev/null
	@$(RM) -r $(OBJECTS_DIRECTORY)
	@$(MAKE) -C $(LIBFT) fclean > /dev/null
	@$(MAKE) -C $(FT_PRINTF) fclean > /dev/null
	@$(RM) $(NAME)
	@$(RM) sources/*.o
	@echo "MAKE FCLEAN\t\t\t. . . OK"

re: fclean all
	@clear
	@echo "MAKE RE\t\t\t. . . OK"

.PHONY: all clean fclean re

valgrind: $(NAME)
	@clear
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) maps/map_0.cub

# *** THE END _____________________________________________________________*** #

# **************************************************************************** #
#                                                                              #
#                                 END OF FILE                                  #
#                                                                              #
#                           ⭐ Made with passion at 42                         #
#                            🚀 Keep coding, keep growing                      #
#                                                                              #
# **************************************************************************** #
