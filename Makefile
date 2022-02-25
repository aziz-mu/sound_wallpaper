CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = sound
OBJECTS = main.o soundSource.o
DEPEND = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
