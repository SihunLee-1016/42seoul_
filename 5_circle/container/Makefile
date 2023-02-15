NAME = container

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -std=c++98
# CXXFLAGS = -g3 -fsanitize=address


# Colors
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

container_SRC = main.cpp $(wildcard ./src/*.cpp) $(wildcard ./src/*/*.cpp)
container_OBJ = $(container_SRC:.cpp=.o)

# REQHANDLE_SRC = $(wildcard ./src/ReqHandler/*.cpp) $(wildcard ./src/gnl/*.cpp) ./src/rq_main.cpp
# REQHANDLE_OBJ = $(REQHANDLE_SRC:.cpp=.o)

# Default target
all: container

# Build the container executable
container: $(container_OBJ)
	@echo "$(YELLOW)Building $@...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(container_OBJ) -o $(NAME)
	@echo "$(GREEN)Done.$(RESET)"

# rp: $(REQHANDLE_OBJ)
# 	@echo "$(YELLOW)Req_Handle_Building $@...$(RESET)"
# 	@$(CXX) $(CXXFLAGS) $(REQHANDLE_OBJ) -o $(RH_NAME)
# 	@echo "$(GREEN)Done.$(RESET)"
# Clean up
clean:
	@echo "$(YELLOW)Cleaning up...$(RESET)"
	@rm -rf $(container_OBJ)
	@rm -rf $(REQHANDLE_OBJ)
	@echo "$(GREEN)Done.$(RESET)"

fclean:
	make clean
	@rm -f $(NAME)
	@rm -f $(RH_NAME)

re:
	make fclean
	make all

# Phony targets
.PHONY: all clean fclean re 