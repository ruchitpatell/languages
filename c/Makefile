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

datatypes:
	$(CC) $(CFLAGS) -c datatypes.c -o datatypes.o
	$(CC) $(CFLAGS) -o datatypes datatypes.o

control:
	$(CC) $(CFLAGS) -c control.c -o control.o
	$(CC) $(CFLAGS) -o control control.o

clean:
	rm -f $(EXEC) $(OBJ) control datatypes

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
