# Exec #
NAME	=	ft_containers

# PATH #
MAI_DIR	=	./main
SRS_DIR	=	./srcs
OBJ_DIR	=	./obj
VPATH	=	$(MAI_DIR):$(SRS_DIR):$(OBJ_DIR)
INC		=   includes

# File #
MAIN	=	$(MAI_DIR)/main.cpp
SRCS	=	$(wildcard $(SRS_DIR)/*.cpp)
OBJS	=	$(patsubst $(SRS_DIR)/%,$(OBJ_DIR)/%,$(SRCS:%.cpp=%.o))
# OBJS2	=	$(SRCS:$(SRS_DIR)/%.cpp=$(OBJ_DIR)/%.o)
HEADERS =	*.hpp

# Compile #
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -Wconversion -std=c++98
LFLAGS  =   -I $(INC)

# Defauilt Make #
all: directories $(NAME)

# Stuff #
$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(NAME)

$(OBJS):		$(OBJ_DIR)%.o:		$(SRS_DIR)%.cpp $(INC)/$(HEADERS)
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

# Make the Directories #
directories:
	@mkdir -p $(OBJ_DIR)

# Clean obj #
clean:
	@rm -f $(OBJS)
	@rm -rf obj
	$(info Build done! Cleaning object files...)

# Clean all #
fclean:			clean
	@rm -f $(NAME)
	$(info Build done! Cleaning $(NAME) exec...)

re:				fclean all

.PHONY:			all fclean clean re directories $(NAME)