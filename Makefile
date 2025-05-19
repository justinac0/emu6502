COMPILER=gcc
CFLAGS=-pedantic -W -Wextra -std=c99
LDFLAGS=

APP_NAME=emu6502
EXECUTABLE=bin/$(APP_NAME)

SRC = src
SOURCES=$(wildcard $(SRC)/*.c $(SRC)/**/*.c)
HSOURCES = $(wildcard $(SRC)/*.h $(SRC)/*/*.h)
OBJECTS=$(SOURCES:.c=.o)

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(LDFLAGS) -o $@ $^

%.o: %.c $(HSOURCES)
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(EXECUTABLE) $(OBJECTS)

run:
	./$(EXECUTABLE)

.PHONY: all clean run