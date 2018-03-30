C = gcc
# pick on of the following
MEMWATCH = 
# MEMWATCH = -DMEMWATCH -DMW_STDIO
CFLAGS = -O4 -Wall -g $(MEMWATCH)
TIME_FORMAT = "max resident memory %M, times: user %U elapse %e, context switches %c" 

JAVA = java
JAVAC = javac

all: malloc_way my_way JavaWay.class


my_way: main_my_way.o allocator.o memwatch.o
	$(CC) $(CFLAGS) -o my_way main_my_way.o memwatch.o allocator.o -DMEMWATCH -DMW_STDIO


malloc_way: main_malloc_way.o memwatch.o
	$(CC) $(CFLAGS) -o malloc_way main_malloc_way.o memwatch.o -DMEMWATCH -DMW_STDIO


main_malloc_way.o: main.c memwatch.h memwatch.o
	$(CC) $(CFLAGS) -c main.c -o main_malloc_way.o -DMEMWATCH -DMW_STDIO


main_my_way.o: main.c memwatch.h allocator.h memwatch.o
	$(CC) $(CFLAGS) -DMYWAY -c main.c -o main_my_way.o -DMEMWATCH -DMW_STDIO


allocator.o: allocator.c memwatch.h allocator.h memwatch.o
	$(CC) $(CFLAGS) -DMYWAY -c allocator.c -o allocator.o -DMEMWATCH -DMW_STDIO


memwatch.o: memwatch.c memwatch.h 
	$(CC) $(MEMWATCH) -c memwatch.c


JavaWay.class: JavaWay.java
	$(JAVAC) JavaWay.java


memwatch.c:
	ln -s /home/class_projects/memwatch-2.71/memwatch.c


memwatch.h:
	ln -s /home/class_projects/memwatch-2.71/memwatch.h


.PHONY: clean
clean:
	-/bin/rm malloc_way my_way *.class *.o src.ps src.ps~ 


.PHONY: test
test: all
	-@echo -n "malloc_way "
	./malloc_way
	-@/usr/bin/time -f $(TIME_FORMAT)  malloc_way
	-@echo -n "my_way     "
	./my_way
	-@/usr/bin/time -f $(TIME_FORMAT)  my_way
	-@echo -n "JavaWay   "
	-@/usr/bin/time -f $(TIME_FORMAT)  $(JAVA) JavaWay
	# tail -n 4 memwatch.log


.PHONY: print
print:
	@ a2ps --delegate=no -T 4 -q -Avirtual -2 -L72 -o src.ps main.c \
           allocator.c MyJavaWay.java JavaWay.java Makefile
	@ echo "output in src.ps"

