TARGET_NAME = tower_defense

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = lib

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(INCLUDE_DIR) -g

LIBS = -L$(LIB_DIR) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')

OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(TARGET_NAME)

$(BUILD_DIR)/$(TARGET_NAME): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $^ -o $@ $(LIBS)
	@echo ":: Compilado con éxito: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(BUILD_DIR)/$(TARGET_NAME)
