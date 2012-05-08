objects = pgDriver.o  pgConnection.o Author.o pgAuthor.o  main.o

links = -I /usr/include/postgresql -l pq
INSTDIR = bin/

pgsql-bin : $(objects)
	@if [  -d $(INSTDIR) ]; \
	then \
		cp pgsql/config.cfg bin/config.cfg; \
		g++ -o bin/pgsql-bin pgDriver.o pgConnection.o Author.o pgAuthor.o main.o $(links); \
		echo "App compiled 'make clean && make' for rebuild";\
	else	\
		mkdir bin; \
		cp pgsql/config.cfg bin/config.cfg; \
		g++ -o bin/pgsql-bin pgDriver.o pgConnection.o Author.o pgAuthor.o main.o $(links); \
		echo "Complited! run cd bin && ./pgsql-bin";\
	fi

main.o : pgDriver.o pgConnection.o Author.o pgAuthor.o
	g++ -c pgsql/main.cpp $(links)

pgConnection.o : pgsql/pgConnection.h pgsql/pgConnection.cpp 
	g++ -c pgsql/pgConnection.h pgsql/pgConnection.cpp $(links)

pgDriver.o : pgsql/pgDriver.h pgsql/pgDriver.cpp
	g++ -c pgsql/pgDriver.h pgsql/pgDriver.cpp $(links)

Author.o : pgsql/Author.cpp pgsql/Author.h
	g++ -c pgsql/Author.cpp pgsql/Author.h $(links)

pgAuthor.o : pgsql/pgAuthor.cpp pgsql/pgAuthor.h 
	g++ -c pgsql/pgAuthor.cpp pgsql/pgAuthor.h $(links)

.PHONY : clean   
clean :   
	rm -f *.o bin -r