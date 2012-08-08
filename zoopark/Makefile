# This is my make file

main: main.o btree/btree_unit_test.o opengl/opengl.o
	g++ -o main main.o btree/btree_unit_test.o opengl/opengl.o -D/usr/include/GL

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm main main.o btree/btree_unit_test.o opengl/opengl.o
