objects = pgDriver.o  pgConnection.o Author.o pgAuthor.o

links = -I /usr/include/postgresql -l pq 
INSTDIR = bin/

pgsql-bin : pgsql-lib main.o 
	g++ main.o  -o bin/pgsql-bin -L./bin -lpgsql-lib

pgsql-lib : $(objects)
	@if [  -d $(INSTDIR) ]; \
	then \
		cp pgsql/config.cfg bin/config.cfg; \
		g++ -shared -o bin/pgsql-lib.so $(objects) $(links); \
		echo "App compiled 'make clean && make' for rebuild";\
	else	\
		mkdir bin; \
		cp pgsql/config.cfg bin/config.cfg; \
		g++ -shared -o bin/pgsql-lib.so $(objects) $(links); \
		echo "Complited! run cd bin && ./pgsql-bin";\
	fi


main.o : Client/main.cpp
	g++ -c Client/main.cpp  -I /usr/include/postgresql -I ../pgsql/ -I pgsql/ -l pq  bin/
	
pgConnection.o : pgsql/pgConnection.h pgsql/pgConnection.cpp 
	g++ -fPIC -c pgsql/pgConnection.h pgsql/pgConnection.cpp $(links)

pgDriver.o : pgsql/pgDriver.h pgsql/pgDriver.cpp
	g++ -fPIC -c pgsql/pgDriver.h pgsql/pgDriver.cpp $(links)

Author.o : pgsql/Author.cpp pgsql/Author.h
	g++ -fPIC -c pgsql/Author.cpp pgsql/Author.h $(links)

pgAuthor.o : pgsql/pgAuthor.cpp pgsql/pgAuthor.h 
	g++ -fPIC -c pgsql/pgAuthor.cpp pgsql/pgAuthor.h $(links)

.PHONY : clean   
clean :   
	rm -f *.o bin -r