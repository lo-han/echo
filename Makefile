CC=gcc

CORE_FOLDER=./core
INFRA_FOLDER=./infra
PORT_FOLDER=./port

MOCK_FOLDER=$(INFRA_FOLDER)/mock
MEMORY_FOLDER=$(CORE_FOLDER)/memory
REPLY_FOLDER=$(CORE_FOLDER)/reply
TRIGGER_FOLDER=$(CORE_FOLDER)/trigger

CFLAGS_MOCK=-I $(MEMORY_FOLDER) -I $(REPLY_FOLDER) -I $(TRIGGER_FOLDER) -I $(MOCK_FOLDER) -I $(PORT_FOLDER)

echo_test: $(MEMORY_FOLDER)/safe_memory.c $(TRIGGER_FOLDER)/trigger.c $(MOCK_FOLDER)/mock_protocol.c $(REPLY_FOLDER)/reply.c main.c
	@$(CC) -o echo_lib $(CFLAGS_MOCK) $(MEMORY_FOLDER)/safe_memory.c $(TRIGGER_FOLDER)/trigger.c $(MOCK_FOLDER)/mock_protocol.c $(REPLY_FOLDER)/reply.c main.c

clean:
	@rm echo_lib
