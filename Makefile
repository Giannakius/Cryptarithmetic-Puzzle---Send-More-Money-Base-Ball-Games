objects = main.o Functions.o

Tournis : $(objects)
	gcc $(objects) -o Tournis -lm


main.o : HeaderFile.h 
Functions.o : HeaderFile.h 

clean : 
	rm Tournis $(objects)