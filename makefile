CC=g++
CFLAGS=-std=c++11 -Wall
TARGET= ./bin/tp3

BUILD_DIR    = ./obj
SRC_DIR    = ./src
INCLUDE_DIR  = ./include


${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/ConfigSaida.o ${BUILD_DIR}/ConfigEntrada.o ${BUILD_DIR}/Node.o ${BUILD_DIR}/ListString.o ${BUILD_DIR}/Word.o ${BUILD_DIR}/ElementList.o ${BUILD_DIR}/OrdenedListString.o ${BUILD_DIR}/List.o ${BUILD_DIR}/HashTable.o ${BUILD_DIR}/AVLNode.o ${BUILD_DIR}/AVLTree.o ${BUILD_DIR}/Dicionario.o ${BUILD_DIR}/main.o 
	${CC} ${CFLAGS} -o ./${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/ConfigSaida.o: ${INCLUDE_DIR}/ConfigSaida.hpp ${SRC_DIR}/ConfigSaida.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ConfigSaida.cpp -o ${BUILD_DIR}/ConfigSaida.o

${BUILD_DIR}/ConfigEntrada.o: ${INCLUDE_DIR}/ConfigEntrada.hpp ${SRC_DIR}/ConfigEntrada.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ConfigEntrada.cpp -o ${BUILD_DIR}/ConfigEntrada.o

${BUILD_DIR}/Node.o: ${INCLUDE_DIR}/Node.hpp ${SRC_DIR}/Node.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Node.cpp -o ${BUILD_DIR}/Node.o

${BUILD_DIR}/ListString.o: ${INCLUDE_DIR}/ListString.hpp  ${INCLUDE_DIR}/ConfigSaida.hpp ${INCLUDE_DIR}/Node.hpp ${SRC_DIR}/ListString.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ListString.cpp -o ${BUILD_DIR}/ListString.o

${BUILD_DIR}/ElementList.o: ${INCLUDE_DIR}/ElementList.hpp  ${INCLUDE_DIR}/Word.hpp ${SRC_DIR}/ElementList.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ElementList.cpp -o ${BUILD_DIR}/ElementList.o

${BUILD_DIR}/Word.o: ${INCLUDE_DIR}/Word.hpp  ${INCLUDE_DIR}/ConfigSaida.hpp ${INCLUDE_DIR}/ListString.hpp ${SRC_DIR}/Word.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Word.cpp -o ${BUILD_DIR}/Word.o

${BUILD_DIR}/OrdenedListString.o: ${INCLUDE_DIR}/OrdenedListString.hpp ${INCLUDE_DIR}/ListString.hpp ${SRC_DIR}/OrdenedListString.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/  -c ${SRC_DIR}/OrdenedListString.cpp -o ${BUILD_DIR}/OrdenedListString.o

${BUILD_DIR}/List.o: ${INCLUDE_DIR}/List.hpp ${INCLUDE_DIR}/ElementList.hpp ${SRC_DIR}/List.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/  -c ${SRC_DIR}/List.cpp -o ${BUILD_DIR}/List.o

${BUILD_DIR}/HashTable.o: ${INCLUDE_DIR}/HashTable.hpp ${INCLUDE_DIR}/Word.hpp ${INCLUDE_DIR}/Method.hpp ${INCLUDE_DIR}/List.hpp ${INCLUDE_DIR}/OrdenedListString.hpp ${SRC_DIR}/HashTable.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/  -c ${SRC_DIR}/HashTable.cpp -o ${BUILD_DIR}/HashTable.o

${BUILD_DIR}/AVLNode.o: ${INCLUDE_DIR}/AVLNode.hpp ${INCLUDE_DIR}/Word.hpp ${SRC_DIR}/AVLNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/  -c ${SRC_DIR}/AVLNode.cpp -o ${BUILD_DIR}/AVLNode.o

${BUILD_DIR}/AVLTree.o: ${INCLUDE_DIR}/AVLTree.hpp ${INCLUDE_DIR}/Word.hpp ${INCLUDE_DIR}/Method.hpp ${INCLUDE_DIR}/AVLNode.hpp ${SRC_DIR}/AVLTree.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/  -c ${SRC_DIR}/AVLTree.cpp -o ${BUILD_DIR}/AVLTree.o

${BUILD_DIR}/Dicionario.o: ${INCLUDE_DIR}/AVLTree.hpp ${INCLUDE_DIR}/Word.hpp ${INCLUDE_DIR}/Method.hpp ${INCLUDE_DIR}/HashTable.hpp ${INCLUDE_DIR}/ConfigEntrada.hpp ${SRC_DIR}/Dicionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/  -c ${SRC_DIR}/Dicionario.cpp -o ${BUILD_DIR}/Dicionario.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Word.hpp ${INCLUDE_DIR}/Dicionario.hpp ${INCLUDE_DIR}/ConfigEntrada.hpp  ${INCLUDE_DIR}/ConfigSaida.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o


clean:
	rm -f ${BUILD_DIR}/* 
