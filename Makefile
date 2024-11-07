CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Wall -O2 -g -fsanitize=address,undefined
INCLUDES = -Iinclude
NAME = ac-onefiler
SRC_DIR = src
OBJ_DIR = obj
############################################################
#### Edit to your path of nlohmann/json.hpp ################
NLOHMANN_HEADER_PATH = /home/linuxbrew/.linuxbrew/include
############################################################
UTILS_DIR = utils
UTILS = get_include_directive.cpp
UTILS := $(addprefix $(UTILS_DIR)/, $(UTILS))
SRCS = main.cpp \
	data.cpp \
	library.cpp \
	onefiler.cpp \
	setting.cpp \
	$(UTILS)
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INCLUDES += $(addprefix -I, \
	$(NLOHMANN_HEADER_PATH) \
)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR) $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re