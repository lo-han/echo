CC=gcc

CORE_FOLDER=../src/core
LISTENER_FOLDER=$(CORE_FOLDER)/listener
INFRA_FOLDER=../infra
MOCK_FOLDER=./mock/static
LIB_FOLDER=../lib
INCLUDE_FOLDER=../include

CFLAGS=-I $(INCLUDE_FOLDER) -I $(LISTENER_FOLDER)

echo_mock: $(LISTENER_FOLDER)/listener.c $(MOCK_FOLDER)/mock_protocol.c $(MOCK_FOLDER)/main.c
	@$(CC) -o echo_mock $(CFLAGS) -I $(MOCK_FOLDER) $(LIB_FOLDER)/safe_memory.o $(LISTENER_FOLDER)/listener.c $(MOCK_FOLDER)/mock_protocol.c $(MOCK_FOLDER)/main.c

clean:
	@rm echo_mock
