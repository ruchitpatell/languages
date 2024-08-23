CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic
CLANG_TIDY = clang-tidy
CPPHECK = cppcheck
PRETTIER = npx prettier
SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
EXEC = a.out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

control:
	$(CC) $(CFLAGS) -c control.c -o control.o
	$(CC) $(CFLAGS) -o control control.o
	rm -f control.o

functions:
	$(CC) $(CFLAGS) -c functions.c -o functions.o
	$(CC) $(CFLAGS) -o functions functions.o
	rm -f functions.o

datatypes:
	$(CC) $(CFLAGS) -c datatypes.c -o datatypes.o
	$(CC) $(CFLAGS) -o datatypes datatypes.o
	rm -f datatypes.o

struct:
	$(CC) $(CFLAGS) -c struct.c -o struct.o
	$(CC) $(CFLAGS) -o struct struct.o
	rm -f struct.o

enum:
	$(CC) $(CFLAGS) -c enum.c -o enum.o
	$(CC) $(CFLAGS) -o enum enum.o
	rm -f enum.o

union:
	$(CC) $(CFLAGS) -c union.c -o union.o
	$(CC) $(CFLAGS) -o union union.o
	rm -f union.o

keywords:
	$(CC) $(CFLAGS) -c keywords.c -o keywords.o
	$(CC) $(CFLAGS) -o keywords keywords.o
	rm -f keywords.o

preprocessor:
	$(CC) $(CFLAGS) -c preprocessor.c -o preprocessor.o
	$(CC) $(CFLAGS) -o preprocessor preprocessor.o
	rm -f preprocessor.o

argparse:
	$(CC) $(CFLAGS) -c argparse.c -o argparse.o
	$(CC) $(CFLAGS) -o argparse argparse.o
	rm -f argparse.o

pointers:
	$(CC) $(CFLAGS) -c pointers.c -o pointers.o
	$(CC) $(CFLAGS) -o pointers pointers.o
	rm -f pointers.o

undefined:
	$(CC) -Wno-everything -c undefined.c -o undefined.o
	$(CC) -Wno-everything -o undefined undefined.o
	rm -f undefined.o

memory:
	$(CC) -Wno-everything -c memory.c -o memory.o
	$(CC) -Wno-everything -o memory memory.o
	rm -f memory.o

clean:
	rm -f $(EXEC) $(OBJ) control datatypes functions enum struct union keywords preprocessor argparse pointers undefined memory

# # Run clang-tidy on all source files
# lint:
# 	@for file in $(SRC); do \
# 		echo "Running clang-tidy on $$file"; \
# 		$(CLANG_TIDY) $$file --checks=* --format-style=file; \
# 	done

# cppcheck:
# 	@$(CPPHECK) --enable=all --std=c99 $(SRC)

# format:
# 	@$(PRETTIER) --write $(SRC)

# check: lint cppcheck format

.PHONY: all clean lint cppcheck format check
