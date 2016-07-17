BUILDDIR = build/
OBJS = $(BUILDDIR)/geneticPopulation.o $(BUILDDIR)/geneticIndividual.o
INCLUDEDIR = include/
SRCDIR = src/
CXX = g++
CFLAGS = -fPIC -c -I$(INCLUDEDIR)
LFLAGS = -shared

libgenetics.so: $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o libgenetics.so

$(BUILDDIR)/geneticPopulation.o: $(SRCDIR)/geneticPopulation.cpp $(INCLUDEDIR)/Genetics/geneticPopulation.hpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/geneticPopulation.cpp -o $(BUILDDIR)/geneticPopulation.o

$(BUILDDIR)/geneticIndividual.o: $(SRCDIR)/geneticIndividual.cpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/geneticIndividual.cpp -o $(BUILDDIR)/geneticIndividual.o

clean:
	rm $(OBJS)
