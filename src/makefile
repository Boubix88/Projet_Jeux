CC = gcc

#OBJS specifies quels fichiers seront compilés pour le programme prison
OBJS = main.c renderer.c map.c inputEvents.c world.c graphics.c miniMap.c deplacements.c
#OBJS2 specifies quels fichiers seront compilés pour le programme map
OBJS2 = createMap.c addPlayerMap.c
CFLAGS= -W -Wall $(shell sdl2-config --cflags)
CFLAGS2= -W -Wall
LDFLAGS=-export-dynamic $(shell sdl2-config --libs) -lm -lSDL2_ttf
LDFLAGS2 = -lm 


#OBJ_NAME specifie le nom de l'executable pour prison
OBJ_NAME = prison   #Mettre ../bin/prison à la fin

#OBJ_NAME2 specifie le nom de l'executable pour map
OBJ2_NAME = map

#C'est la cible ou est compilé l'executable de prison
prison : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OBJ_NAME) $(LDFLAGS)

#C'est la cible ou est compilé l'executable de prison
map : $(OBJS2)
	$(CC) $(CFLAGS2) $(OBJS2) -o $(OBJ2_NAME) $(LDFLAGS2)
	./map

#Suppression des .o
clean:
	rm -rf *.o *~

#Suppression des .o et .exe
maxclean: clean
	rm -rf prison
	rm -rf map
