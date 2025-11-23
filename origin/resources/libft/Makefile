NAME			= libft.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

SOURCES			= ft_isalpha.c\
					ft_toupper.c\
					ft_isdigit.c\
					ft_tolower.c\
					ft_isalnum.c\
					ft_isascii.c\
					ft_isprint.c\
					ft_strlen.c\
					ft_strchr.c\
					ft_strrchr.c\
					ft_strlcpy.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strlcat.c\
					ft_memset.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memmove.c\
					ft_bzero.c\
					ft_atoi.c\
					ft_calloc.c\
					ft_strdup.c\
					ft_memcpy.c\
					ft_putchar_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_putendl_fd.c\
					ft_substr.c\
					ft_strjoin.c\
					ft_strtrim.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_itoa.c\
					ft_split.c\
					ft_lstnew.c\
					get_next_line.c\
					get_next_line_utils.c\
					ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\
					ft_lstmap.c\

OBJECTS 		= $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -c $(SOURCES)
	@ar -rcs $(NAME) $(OBJECTS)

all:
	$(NAME)
	@echo "LIBFT: MAKE ALL\t\t\t. . . OK"

clean:
	@rm -f $(OBJECTS)
	@echo "LIBFT: MAKE CLEAN\t\t\t. . . OK"

fclean:
	@rm -f $(OBJECTS)
	@rm -fr $(NAME)
	@echo "LIBFT: MAKE FCLEAN\t\t\t. . . OK"

re:
	@rm -f $(OBJECTS)
	@rm -fr $(NAME)
	$(NAME)
	@echo "LIBFT: MAKE RE\t\t\t\t. . . OK"

.PHONY: all clean fclean re bonus