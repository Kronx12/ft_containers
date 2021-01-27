# LIB #
# NAME			=	ft_containers.a

# Exec #
LIST			=	list_test
MAP				=	map_test
QUEUE			=	queue_test
STACK			=	stack_test
VECTOR			=	vector_test

# Exec Path #
LIST_PATH		=	$(addprefix $(TEST_DIR)/,$(LIST))
MAP_PATH		=	$(addprefix $(TEST_DIR)/,$(MAP))
QUEUE_PATH		=	$(addprefix $(TEST_DIR)/,$(QUEUE))
STACK_PATH		=	$(addprefix $(TEST_DIR)/,$(STACK))
VECTOR_PATH		=	$(addprefix $(TEST_DIR)/,$(VECTOR))

# Test #
TEST			=	$(LIST) $(STACK) $(QUEUE) $(VECTOR) $(MAP)

# Path #
TEST_DIR		=	test
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
TEST_INCS		=	$(addprefix $(MAIN_DIR),/Tester.hpp)
TEST_MAIN		=	$(addprefix $(MAIN_DIR),/mainglobal.cpp)
LIST_MAIN		=	$(addprefix $(MAIN_DIR),/mainlist.cpp)
MAP_MAIN		=	$(addprefix $(MAIN_DIR),/mainmap.cpp)
STACK_MAIN		=	$(addprefix $(MAIN_DIR),/mainstack.cpp)
QUEUE_MAIN		=	$(addprefix $(MAIN_DIR),/mainqueue.cpp)
VECTOR_MAIN		=	$(addprefix $(MAIN_DIR),/mainvector.cpp)

# Compile #
CC				=	clang++
CFLAGS			=	-Wall -Wextra -g3 -Werror -g3 -fsanitize=address
CVERSION		=	-std=c++98
LFLAGS  		=	-I $(TEST_INCS) -I $(INCS_DIR)
CALLF			=	$(CC) $(CFLAGS) $(CVERSION)
CALLFLIB		=	$(CC) $(CFLAGS) $(CVERSION) $(LFLAGS)

# Defauilt Make #
all				:	directories #ART

# ifdef INPUT
# 	@\rm -rf test/*
# endif

# Start all tester #
all_test		:	list stack queue vector map

# Restart exec #
listrm			:
ifdef INPUT
	@\rm -rf test/$(LIST)
endif

vectorrm			:
ifdef INPUT
	@\rm -rf test/$(VECTOR)
endif

maprm			:
ifdef INPUT
	@\rm -rf test/$(MAP)
endif

stackrm			:
ifdef INPUT
	@\rm -rf test/$(STACK)
endif

queuerm			:
ifdef INPUT
	@\rm -rf test/$(QUEUE)
endif

# Containers test #
list			:	all listrm $(LIST_PATH)
	./$(addprefix $(TEST_DIR)/,$(LIST))

$(LIST_PATH)	: $(LIST_MAIN) $(TEST_MAIN) $(TEST_INCS) $(INCS_PATH)
	$(CALLFLIB) ${INPUT} $(LIST_MAIN) $(TEST_MAIN) -o $(LIST_PATH)

stack			:	all stackrm $(STACK_PATH)
	./$(addprefix $(TEST_DIR)/,$(STACK))

$(STACK_PATH)	:	$(STACK_MAIN) $(TEST_MAIN) $(TEST_INCS) $(INCS_PATH)
	$(CALLFLIB) ${INPUT} $(STACK_MAIN) $(TEST_MAIN) -o $(addprefix $(TEST_DIR)/,$(STACK))

queue			:	all queuerm $(QUEUE_PATH)
	./$(addprefix $(TEST_DIR)/,$(QUEUE))

$(QUEUE_PATH)	:	$(QUEUE_MAIN) $(TEST_MAIN) $(TEST_INCS) $(INCS_PATH)
	$(CALLFLIB) ${INPUT} $(QUEUE_MAIN) $(TEST_MAIN) -o $(addprefix $(TEST_DIR)/,$(QUEUE))

map				:	all maprm $(MAP_PATH)
	./$(addprefix $(TEST_DIR)/,$(MAP))

$(MAP_PATH)		:	$(MAP_MAIN) $(TEST_MAIN) $(TEST_INCS) $(INCS_PATH)
	$(CALLFLIB) ${INPUT} $(MAP_MAIN) $(TEST_MAIN) -o $(addprefix $(TEST_DIR)/,$(MAP))

vector			:	all vectorrm $(VECTOR_PATH)
	./$(addprefix $(TEST_DIR)/,$(VECTOR))

$(VECTOR_PATH)	:	$(VECTOR_MAIN) $(TEST_MAIN) $(TEST_INCS) $(INCS_PATH)
	$(CALLFLIB) ${INPUT} $(VECTOR_MAIN) $(TEST_MAIN) -o $(addprefix $(TEST_DIR)/,$(VECTOR))

# Make the Directories #
directories		:
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(TEST_DIR)

# Clean obj #
clean			:
	@rm -f $(OBJS_PATH)
	$(info Build done! Cleaning object files...)

# Clean all #
fclean			:	clean
	@rm -rf $(OBJS_DIR) $(addprefix $(TEST_DIR)/,$(TEST)) $(TEST_DIR)
	@rm -f $(NAME)
	$(info Build done! Cleaning exec...)

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

.PHONY			:	all fclean clean re directories ART list listrm vectorrm maprm stackrm queuerm
