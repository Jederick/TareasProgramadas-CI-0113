FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/arbol.cpp -o bin/arbol.o
	g++ $(FLAGS) src/nodoArbol.cpp -o bin/nodoArbol.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -o bin/final bin/main.o bin/nodoArbol.o bin/arbol.o


make test:
	mkdir -p bin
	
	g++ $(FLAGS) src/profesionalPorHoras.cpp -o bin/profesionalPorHoras.o
	g++ $(FLAGS) src/tipoEmpleado.cpp -o bin/tipoEmpleado.o
	g++ $(FLAGS) tests/tipoEmpleado_Tests.cpp -o bin/tipoEmpleado_Tests.o
	g++ -g -o bin/tests bin/tipoEmpleado_Tests.o bin/profesionalPorHoras.o bin/tipoEmpleado.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
