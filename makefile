# Exec #
NAME		=	ft_containers

# PATH #
MAIN_DIR	=	main
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
INCS_DIR	=   includes
VPATH		=	$(MAIN_DIR):$(SRCS_DIR):$(OBJS_DIR):$(INCS_DIR)

# File with Path #
SRCS_PATH	=	$(wildcard $(SRCS_DIR)/*.cpp)
OBJS_PATH	=	$(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS_PATH:%.cpp=%.o))
INCS_PATH	=	$(wildcard $(INCS_DIR)/*.hpp)

# File #
MAIN		=	main.cpp
SRCS		=	$(patsubst $(SRCS_DIR)/%,%,$(SRCS_PATH))
OBJS		=	$(patsubst $(SRCS_DIR)/%,%,$(SRCS_PATH:%.cpp=%.o))
INCS		=	$(patsubst $(INCS_DIR)/%,%,$(INCS_PATH))

# $(info main = $(MAIN))
# $(info srcs = $(SRCS))
# $(info objs = $(OBJS_PATH))
# $(info obj = $(OBJS))
# $(info test = $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS_PATH:%.cpp=%.o)) )

# Compile #
CC			=	clang++
CFLAGS		=	-Wall -Wextra -Werror -Wconversion -std=c++98
LFLAGS  	=   -I $(INCS_DIR)

# Defauilt Make #
all:			directories $(NAME)

# Stuff #
$(NAME):		$(OBJS_PATH)
	$(CC) $(CFLAGS) $(OBJS_PATH) -I $(INCS_DIR) $(MAIN_DIR)/$(MAIN) -o $(NAME)

$(OBJS_DIR)/%.o:	%.cpp $(INCS_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

# Make the Directories #
directories:
	@mkdir -p $(OBJS_DIR)

# Clean obj #
clean:
	@rm -f $(addprefix $(OBJS_DIR), $(OBJS))
	$(info Build done! Cleaning object files...)

# Clean all #
fclean:			clean
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	$(info Build done! Cleaning $(NAME) exec...)

re:				fclean all

.PHONY:			all fclean clean re directories $(NAME)