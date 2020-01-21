# === === === === === Basic === === === === === 

MAIN=Main.cpp
INCLUDES=
FLAGS=-O0 -g -Wall -std=c++11

all:
    rm -f main
	g++ $(FLAGS) $(MAIN) -o main $(INCLUDES)

run:
	./$(MAIN:cpp=exe)

clean:
    rm -f main
    rm -f *.o

# === === === === === Advanced === === === === === 

# CODE=WE.cpp Graphics.cpp Game.cpp
# SRC=$(CODE:.cpp=.o)
# FLAGS=-O0 -g -Wall -std=c++11
# ifeq ($(OS),Windows_NT)
#     LIBS=-mconsole -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
# else
#     LIBS=-lSDL2main -lSDL2 -lSDL2_image
# endif

# main: $(SRC)
# 	g++ $(FLAGS) $(SRC) -o main $(LIBS)

# .cpp.o:
# 	g++ $(FLAGS) -c $(@:.o=.cpp) -o $@

# clean:
# 	rm -f main
# 	rm -f *.o