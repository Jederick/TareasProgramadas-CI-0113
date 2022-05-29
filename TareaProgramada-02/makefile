FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) src/profesionalPorHoras.cpp -o bin/profesionalPorHoras.o
	g++ $(FLAGS) src/tipoEmpleado.cpp -o bin/tipoEmpleado.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -o bin/final bin/main.o bin/empleadoNomina.o bin/planilla.o bin/profesionalPorHoras.o bin/tipoEmpleado.o


make test:
	mkdir -p bin
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) src/profesionalPorHoras.cpp -o bin/profesionalPorHoras.o
	g++ $(FLAGS) src/tipoEmpleado.cpp -o bin/tipoEmpleado.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) tests/tipoEmpleado_Tests.cpp -o bin/tipoEmpleado_Tests.o
	g++ $(FLAGS) tests/planilla_Tests.cpp -o bin/planilla_Tests.o
	g++ -g -o bin/tests bin/tipoEmpleado_Tests.o bin/planilla_Tests.o bin/planilla.o bin/empleadoNomina.o bin/profesionalPorHoras.o bin/tipoEmpleado.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
