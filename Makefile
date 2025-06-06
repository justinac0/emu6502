COMPILER=gcc
CFLAGS=-pedantic -W -Wextra -std=c99
LDFLAGS=-I include/

APP_NAME=emu6502
EXECUTABLE=bin/$(APP_NAME)

SRC = src
SOURCES=$(wildcard $(SRC)/*.c $(SRC)/**/*.c)
HSOURCES = $(wildcard $(SRC)/*.h $(SRC)/*/*.h)
OBJECTS=$(SOURCES:.c=.o)

$(EXECUTABLE): $(OBJECTS)
	mkdir -p bin
	$(COMPILER) $(LDFLAGS) -o $@ $^

%.o: %.c $(HSOURCES)
	$(COMPILER) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

all: $(EXECUTABLE)

clean:
	rm -fr $(EXECUTABLE) $(OBJECTS)

run:
	./$(EXECUTABLE)

.PHONY: all clean run