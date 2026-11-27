CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

EXEC = crashTech

SRC = main.c lecteur.c annee.c age.c accident.c
OBJ = $(SRC:.c=.o)
HEADERS = lecteur.h annee.h age.h accident.h

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

re: clean all

.PHONY: all clean re
