CC = clang

CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LINKERFLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm

NAME = endgame

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) $(LINKERFLAGS) -o $(NAME) src/*.c

clean:
	rm -f $(NAME)

reinstall: clean $(NAME)

