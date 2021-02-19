SOURCES = src/main.c
OBJECTS = $(subst .c,.o,$(SOURCES))

COMMON_FLAGS = -Wall -Wextra -Wpedantic
ifdef DEBUG
	CFLAGS = $(COMMON_FLAGS) -O0 -g
else
	CFLAGS = $(COMMON_FLAGS) -O3 -DNDEBUG
endif

all: LocalMaxima

LocalMaxima: $(OBJECTS)
	$(CC) $(CFLAGS) -o LocalMaxima $^

.PHONY:

clean:
	rm -f LocalMaxima
	rm -f src/*.o
