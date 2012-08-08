# This is my make file

CFLAGS = -DTARGET_LINUX_OS
LDLIBS = -lglut -lGL -lGLU

main: main.o btree/btree_unit_test.o opengl/opengl.o
        g++ -o main main.o btree/btree_unit_test.o opengl/opengl.o ${LDLIBS}

main.o: main.cpp
        g++ -c main.cpp ${CFLAGS}

opengl/opengl.o: opengl/opengl.cpp
        g++ -c opengl/opengl.cpp -o opengl/opengl.o ${CFLAGS}

btree/btree_unit_test.o: btree/btree_unit_test.cpp
        g++ -c btree/btree_unit_test.cpp -o btree/btree_unit_test.o ${CFLAGS}

clean:
        rm main main.o btree/btree_unit_test.o opengl/opengl.o