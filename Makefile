CC=gcc

CORE_FOLDER=./core
INFRA_FOLDER=./infra
PORT_FOLDER=./port

MOCK_FOLDER=$(INFRA_FOLDER)/mock
MEMORY_FOLDER=$(CORE_FOLDER)/memory
REPLY_FOLDER=$(CORE_FOLDER)/reply
TRIGGER_FOLDER=$(CORE_FOLDER)/trigger

CFLAGS_MOCK= -I $(REPLY_FOLDER) -I $(TRIGGER_FOLDER) -I $(MEMORY_FOLDER) -I $(MOCK_FOLDER) -I $(PORT_FOLDER)
DEPS_MOCK = $(REPLY_FOLDER)/reply.h  $(MEMORY_FOLDER)/safe_memory.h $(TRIGGER_FOLDER)/triger.h $(MOCK_FOLDER)/mock_protocol.h

%.o: %.c $(DEPS_MOCK)
	@$(CC) -c -o $@ $< $(CFLAGS_MOCK)

echo_test: $(MEMORY_FOLDER)/safe_memory.o $(TRIGGER_FOLDER)/trigger.o $(MOCK_FOLDER)/mock_protocol.o $(REPLY_FOLDER)/reply.o main.o
	@$(CC) -o echo_lib $(MEMORY_FOLDER)/safe_memory.o $(TRIGGER_FOLDER)/trigger.o $(MOCK_FOLDER)/mock_protocol.o $(REPLY_FOLDER)/reply.o main.o

clean:
	@rm *.o $(MEMORY_FOLDER)/*.o $(REPLY_FOLDER)/*.o $(TRIGGER_FOLDER)/*.o $(MOCK_FOLDER)/*.o main.o log
