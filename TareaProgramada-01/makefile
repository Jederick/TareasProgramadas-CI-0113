FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ -c --std=c++17 src/envioFedex.cpp -o bin/envioFedex.o
	g++ -c --std=c++17 src/envioPostal.cpp -o bin/envioPostal.o 
	g++ -c --std=c++17 src/main.cpp -o bin/main.o 
	g++ -o bin/final bin/envioFedex.o bin/envioPostal.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/envioPostal.cpp -o bin/envioPostal.o
	g++ $(FLAGS) src/envioFedex.cpp -o bin/envioFedex.o
	g++ $(FLAGS) tests/envioPostal_tests.cpp -o bin/envioPostal_tests.o
	g++ $(FLAGS) tests/envioFedex_tests.cpp -o bin/envioFedex_tests.o
	g++ -g -o bin/tests bin/envioPostal_tests.o bin/envioPostal.o bin/envioFedex_tests.o bin/envioFedex.o -lgtest -lgtest_main -lpthread 


debug:
	mkdir -p bin
	g++ $(FLAGS) src/envioFedex.cpp -o bin/envioFedex.o
	g++ $(FLAGS) src/envioPostal.cpp -o bin/envioPostal.o 
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -o bin/debug bin/envioFedex.o bin/envioPostal.o bin/main.o

clean:
	rm -Rf bin
