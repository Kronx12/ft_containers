# Exec #
NAME			=	ft_containers.a
LIST			=	list_test

# Test #
TEST			=	LIST 

# Path #
MAIN_DIR		=	main
SRCS_DIR		=	srcs
OBJS_DIR		=	objs
INCS_DIR		=	includes
VPATH			=	$(SRCS_DIR):$(OBJS_DIR):$(INCS_DIR):$(MAIN_DIR)

# File with Path #
SRCS_PATH		=	$(wildcard $(SRCS_DIR)/*.cpp)
OBJS_PATH		=	$(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS_PATH:%.cpp=%.o))
INCS_PATH		=	$(wildcard $(INCS_DIR)/*.hpp)

# File #
SRCS			=	$(notdir $(SRCS_PATH))
OBJS			=	$(notdir $(OBJS_PATH))
INCS			=	$(notdir $(INCS_PATH))

# Main #
LIST_MAIN		=	$(addprefix $(SRCS_MAIN),/mainlist.cpp)

# Compile #
CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
CVERSION		=	-std=c++98
LFLAGS  		=	-I $(INCS_DIR)
CALLF			=	$(CC) $(CFLAGS) $(CVERSION)
CALLFLIB		=	$(CC) $(CFLAGS) $(CVERSION) $(LFLAGS)

# Defauilt Make #
all				:	directories $(NAME) ART

# Stuff #
$(NAME)			:	$(OBJS_PATH)
	ar rc $(NAME) $(OBJS_PATH)
	ranlib $(NAME)

$(OBJS_DIR)/%.o	:	%.cpp $(INCS)
	$(CALLFLIB) -c $< -o $@

# Containers test #
list			:	all $(LIST_MAIN)
	$(CALLFLIB) $(NAME) $(LIST_MAIN) -o $(LIST)

# Make the Directories #
directories		:
	@mkdir -p $(OBJS_DIR)

# Clean obj #
clean			:
	@rm -f $(OBJS_PATH) $(TEST)
	$(info Build done! Cleaning object files...)

# Clean all #
fclean			:	clean
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	$(info Build done! Cleaning $(NAME) exec...)

re				:	fclean all

ART:
	@for i in {232..255} ; \
	do                                      \
		sleep 0.1;\
		clear;\
		for y in {22..27} {27..22};             \
		do \
			printf "\033[48;5;$${y}m      \033[0m" ;\
		done ; echo ;                              \
		echo "     \033[38;5;$${i}m_____ _____ _   _ _____ ___  _____ _   _  ___________  _____\033[0m";\
		echo "    \033[38;5;$${i}m/  __ \  _  | \ | |_   _/ _ \|_   _| \ | ||  ___| ___ \/  ___|\033[0m";\
		echo "    \033[38;5;$${i}m| /  \/ | | |  \| | | |/ /_\ \ | | |  \| || |__ | |_/ /\  --. \033[0m";\
		echo "    \033[38;5;$${i}m| |   | | | | . ' | | ||  _  | | | | . ' ||  __||    /  '--. \ \033[0m";\
		echo "    \033[38;5;$${i}m| \__/\ \_/ / |\  | | || | | |_| |_| |\  || |___| |\ \ /\__/ /\033[0m";\
		echo "     \033[38;5;$${i}m\____/\___/\_| \_/ \_/\_| |_/\___/\_| \_/\____/\_| \_|\____/\033[0m";\
		for y in {22..27} {27..22};             \
		do                                  \
			printf "\033[48;5;$${y}m      \033[0m" ;\
		done ; echo ;                              \
	done

.PHONY			:	all fclean clean re directories ART list
