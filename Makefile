CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = sound
OBJECTS = main.o soundSource.o visualizer.o
DEPEND = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lpulse-simple -lpulse -lfftw3 -lm

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
