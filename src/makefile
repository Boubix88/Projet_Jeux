CC = gcc

#OBJS specifies quels fichiers seront compilés pour le programme prison
OBJS = main.c renderer.c map.c inputEvents.c world.c graphics.c miniMap.c deplacements.c
CFLAGS= -W -Wall $(shell sdl2-config --cflags)
LDFLAGS=-export-dynamic $(shell sdl2-config --libs) -lm -lSDL2_ttf


#OBJ_NAME specifie le nom de l'executable pour prison
OBJ_NAME = ../bin/./prison   #Mettre ../bin/prison à la fin

#C'est la cible ou est compilé l'executable de prison
prison : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OBJ_NAME) $(LDFLAGS)


#Suppression des .o
clean:
	rm -rf *.o *~

#Suppression des .o et .exe
maxclean: clean
	rm -rf prison
	rm -rf map
