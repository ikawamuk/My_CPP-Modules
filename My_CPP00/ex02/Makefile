# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 19:24:02 by ikawamuk          #+#    #+#              #
#    Updated: 2025/10/10 00:31:38 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                  VARIABLES                                   #
# ---------------------------------------------------------------------------- #

# --- EXECUTABLE NAMES ---
NAME	= tests

# --- SOURCES ---
SRC_FILES	=	tests.cpp \
				Account.cpp

SRCS	= $(addprefix $(SRCDIR)/,$(SRC_FILES))

# --- DIRECTORIES ---
SRCDIR		= .
OBJDIR		= obj
INCDIRS		= include

# --- COMPILER & FLAGS ---
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
AR			= ar
ARFLAGS		= rcs

# --- COMMANDS ---
RM		= rm -f
RMDIR	= rm -rf

# --- OBJECTS ---
OBJS	= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# --- DEBUGGING ---
VALGRIND		= valgrind
VALGRIND_FLAGS	= --leak-check=full --track-origins=yes --show-leak-kinds=all
DFLAGS 			= -g -O0
ASAN_FLAGS 		= -g -O0 -fsanitize=address
SCAN_BUILD		= scan-build

TEST_NAME	= test_runner
TEST_SRC_FILES = $(filter-out main.cpp,$(SRC_FILES)) test.cpp
TEST_SRCS	= $(addprefix $(SRCDIR)/,$(TEST_SRC_FILES))
TEST_OBJS	= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SRCS))

# ---------------------------------------------------------------------------- #
#                                    RULES                                     #
# ---------------------------------------------------------------------------- #

# --- MAIN TARGETS ---
all: $(NAME)

# --- EXECUTABLE BUILDING ---
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "\n\033[1;32m'$(NAME)' has been created!\033[0m"

# --- OBJECT FILE COMPILATION ---
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- CLEANUP RULES ---
clean:
	@$(RMDIR) $(OBJDIR)
	@echo "\033[1;33mObject files cleaned.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31mAll cleaned.\033[0m"

re: fclean all

# --- DEBUGGING & TESTING ---
debug: fclean
	@$(MAKE) CXXFLAGS="$(CXXFLAGS) $(DFLAGS)" $(NAME)
	@echo "\n\033[1;35mLaunching LLDB for '$(NAME)'...\033[0m"
	@lldb $(NAME)

asan: fclean
	@$(MAKE) CXXFLAGS="$(CXXFLAGS) $(ASAN_FLAGS)" \
	LDFLAGS="$(ASAN_FLAGS)" $(NAME)
	@echo "\n\033[1;35mCompiled with AddressSanitizer. \
	Run './$(NAME)' to test.\033[0m"

valgrind: fclean
	@$(MAKE) CXXFLAGS="$(CXXFLAGS) $(DFLAGS)" $(NAME)
	@echo "\n\033[1;36mRunning Valgrind for '$(NAME)'...\033[0m"
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME)

scanb: fclean
	@echo "\n\033[1;34mRunning Clang Static Analyzer (scan-build) \
	for '$(NAME)'...\033[0m"
	@$(SCAN_BUILD) $(MAKE) all

test: $(TEST_OBJS)
	@echo "\033[1;36mRunning tests...\033[0m"
	@$(CXX) $(CXXFLAGS) $^ -o $(TEST_NAME)
# $(VALGRIND) $(VALGRIND_FLAGS) ./$(TEST_NAME)
	@./$(TEST_NAME)
	@$(RM) $(TEST_NAME)

# --- PHONY TARGETS ---
.PHONY: all clean fclean re debug asan valgrind scanb test