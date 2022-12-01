OBJECTS = profile.o network.o

main: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS) --std=c++11
tests: tests.o $(OBJECTS)
	g++ -o tests -g tests.o $(OBJECTS) --std=c++11


main.o: main.cpp profile.h

tests.o: tests.cpp profile.h doctest.h

profile.o: profile.cpp profile.h

network.o: network.cpp network.h profile.h

clean:
	rm -f main.o tests.o $(OBJECTS)