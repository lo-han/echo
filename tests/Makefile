CC=gcc

CORE_FOLDER=../core
INFRA_FOLDER=../infra
PORT_FOLDER=../port

MOCK_FOLDER=./mock

MEMORY_FOLDER=$(CORE_FOLDER)/memory
REPLY_FOLDER=$(CORE_FOLDER)/reply
TRIGGER_FOLDER=$(CORE_FOLDER)/trigger

CFLAGS=-I $(MEMORY_FOLDER) -I $(REPLY_FOLDER) -I $(TRIGGER_FOLDER) -I $(PORT_FOLDER)

echo_mock: $(MEMORY_FOLDER)/safe_memory.c $(TRIGGER_FOLDER)/trigger.c $(MOCK_FOLDER)/mock_protocol.c $(REPLY_FOLDER)/reply.c $(MOCK_FOLDER)/main.c
	@$(CC) -o echo_mock $(CFLAGS) -I $(MOCK_FOLDER) $(MEMORY_FOLDER)/safe_memory.c $(TRIGGER_FOLDER)/trigger.c $(MOCK_FOLDER)/mock_protocol.c $(REPLY_FOLDER)/reply.c $(MOCK_FOLDER)/main.c

clean:
	@rm echo_mock
