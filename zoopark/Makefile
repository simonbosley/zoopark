# This is my make file

CFLAGS = -DTARGET_LINUX_OS
LDLIBS = -lglut -lGL -lGLU

main: main.o btree/btree_unit_test.o opengl/opengl.o
\tg++ -o main main.o btree/btree_unit_test.o opengl/opengl.o ${LDLIBS}

main.o: main.cpp
\tg++ -c main.cpp ${CFLAGS}

opengl/opengl.o: opengl/opengl.cpp
\tg++ -c opengl/opengl.cpp -o opengl/opengl.o ${CFLAGS}

btree/btree_unit_test.o: btree/btree_unit_test.cpp
\tg++ -c btree/btree_unit_test.cpp -o btree/btree_unit_test.o ${CFLAGS}

clean:
\trm main main.o btree/btree_unit_test.o opengl/opengl.o

