FLAGS = -g -fPIC -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ -shared -o bin/libtienda.so obj/tienda.o obj/producto.o
	mkdir -p bin/include
	cp src/producto.h bin/include
	cp src/tienda.h bin/include
	cp -r src/excepciones bin/include
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) tests/producto_tests.cpp -o obj/producto_tests.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/tienda_tests.cpp -o obj/tienda_tests.o
	g++ -g -o bin/tests obj/tienda.o obj/producto.o obj/tienda_tests.o obj/producto_tests.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm -Rf obj
	rm -Rf tienda_test.dat