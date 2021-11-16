CC = gcc

#OBJS specifies which files to compile as part of the project
OBJS = main.c renderer.c map.c
CFLAGS= -W -Wall $(shell sdl2-config --cflags)
LDFLAGS=-export-dynamic $(shell sdl2-config --libs)

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = prison

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OBJ_NAME) $(LDFLAGS)

clean:
	rm -rf *.o *~

maxclean: clean
	rm -rf prison
