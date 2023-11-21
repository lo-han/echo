# Compiler
CC = gcc
# Source directory
SRC_DIR = ./src
# Compiler flags
LISTENER_FOLDER=$(SRC_DIR)/core/listener
INCLUDE_FOLDER=./include
IMPORT_FOLDER=./lib
MOCK_FOLDER=./tests/mock/static
CFLAGS = -I $(INCLUDE_FOLDER) -I $(LISTENER_FOLDER) -I $(MOCK_FOLDER)
# Object directory
OBJ_DIR = ./obj
# Source files
SRCS = $(SRC_DIR)/core/listener/listener.c ./tests/mock/static/mock_protocol.c 
# Object files
OBJS = $(patsubst %.c,%.o,$(SRCS))

# Default rule
all: $(OBJS)
	ld -r $< ./lib/safe_memory.o -o $(OBJ_DIR)/echo.o

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*.o
	@rm $(SRC_DIR)/*/*/*.o