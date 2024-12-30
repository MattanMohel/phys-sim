# name of binary 
BIN = bin

LIB = m stdc++ SDL2 SDL2_image
SRC =. 
INC =. include /usr/include/eigen3
ARG = 

CC  = gcc
OPT = -O0

# cmake dependency flags
DEPFLAGS = -MP -MD
FLAGS    = -Wall -Wextra -g $(foreach D,$(INC),-I$(D)) $(OPT) $(DEPFLAGS)

# create list of c files using the src directories
FILES = $(foreach D,$(SRC),$(wildcard $(D)/*.cpp))

# create a %.o for every %.cpp file
OBJ = $(patsubst %.cpp,%.o,$(FILES))
# create a %.d for every %.c file
DEP = $(patsubst %.cpp,%.d,$(FILES))
# create a -l% for every library %
LNK = $(patsubst %,-l%,$(LIB))

all: $(BIN)

run: $(BIN)
	./$(BIN) $(ARG)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(LNK)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(BIN) $(OBJ) $(DEP)

-include $(DEP)

.PHONY: all clean
