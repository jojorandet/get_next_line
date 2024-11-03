NAME = libftgetnextline.a
DIR_SRC = ./ #specifies that the source files are located in the current dir.
DIR_BUILD = build
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
ALL_CFLAGS = -I. $(CFLAGS)

SOURCES		=	get_next_line_utils.c
				get_next_line.c
FUNCTIONS	= $(subst .c,,$(notdir $(SOURCES)))
OBJECTS		= $(addsuffix .o, $(addprefix $(DIR_BUILD)/$(FUNCTIONS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^ 
	echo "compiled"
#@ auotmatic variable that expands to the name of the target being created-> in this case NAME so the oytput files, the dollar expands to the prerequisites of the target
$(DIR_BUILD)/%.o: $(DIR_SRC)/%c | $(DIR_BUILD)
	cc $(ALL_CFLAGS) -c $^ -o $@

$(DIR_BUILD)
	mkdir $(DIR_BUILD)
#creates the dirbuild if it doesnt exist, thus the pipe dependency above
clean:
	rm -rf $(DIR_BUILD)

fclean: cleab
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re