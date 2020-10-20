project: project.c veclib.o project.h
	gcc -o project project.c projectlib.o
veclib.o: projectlib.c project.h
	gcc -c projectlib.c
clean:
	rm -rf *.o project
