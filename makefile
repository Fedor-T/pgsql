objects = pgDriver.o  pgConnection.o Author.o pgAuthor.o

links = -I /usr/include/postgresql -l pq 
INSTDIR = bin/

pgsql-bin : libpgsql main.o 
	g++ main.o  -o bin/pgsql-bin -L./bin -lpgsql -lpq

libpgsql: $(objects)
	@if [  -d $(INSTDIR) ]; \
	then \
		cp pgsql/config.cfg bin/config.cfg; \
		g++ -shared -o bin/libpgsql.so $(objects) $(links); \
		echo "App compiled 'make clean && make' for rebuild";\
	else	\
		mkdir bin; \
		cp pgsql/config.cfg bin/config.cfg; \
		g++ -shared -o bin/libpgsql.so $(objects) $(links); \
		echo "compile success" ;\
		echo "Run 'sudo make install'" ;\
	fi


main.o : 
	cp Client/main.cpp pgsql/main.cpp
	g++ -c pgsql/main.cpp  -I /usr/include/postgresql -l pq  bin/
	rm pgsql/main.cpp
	
pgConnection.o : pgsql/pgConnection.h pgsql/pgConnection.cpp 
	g++ -fPIC -c pgsql/pgConnection.h pgsql/pgConnection.cpp $(links)

pgDriver.o : pgsql/pgDriver.h pgsql/pgDriver.cpp
	g++ -fPIC -c pgsql/pgDriver.h pgsql/pgDriver.cpp $(links)

Author.o : pgsql/Author.cpp pgsql/Author.h
	g++ -fPIC -c pgsql/Author.cpp pgsql/Author.h $(links)

pgAuthor.o : pgsql/pgAuthor.cpp pgsql/pgAuthor.h 
	g++ -fPIC -c pgsql/pgAuthor.cpp pgsql/pgAuthor.h $(links)

install:
	cp bin/libpgsql.so /usr/lib/
	echo "app instaled run cd bin && ./pgsql-bin";\

uninstall:
	@if [  -e /usr/lib/libpgsql.so ]; \
	then \
		rm /usr/lib/libpgsql.so;\
		echo "app installed" ;\
	else \
		echo "app didn't install" ;\
	fi

.PHONY : clean   
clean :   
	rm -f *.o bin -r