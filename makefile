OBJS = geneticPopulation.o geneticIndividual.o
CXX = g++
CFLAGS = -fPIC -c
LFLAGS = -shared

libgenetics.so: $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o libgenetics.so

geneticPopulation.o: geneticPopulation.hpp geneticPopulation.cpp geneticIndividual.hpp
	$(CXX) $(CFLAGS) geneticPopulation.cpp

geneticIndividual.o: geneticIndividual.hpp geneticIndividual.cpp
	$(CXX) $(CFLAGS) geneticIndividual.cpp

clean:
	rm $(OBJS)
