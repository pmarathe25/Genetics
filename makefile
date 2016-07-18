BUILDDIR = build/
INCLUDEDIR = include/
SRCDIR = src/
LIBDIR = lib/
LIBS = Genetics/libgenetics.so
OBJS = $(BUILDDIR)/geneticPopulation.o $(BUILDDIR)/geneticIndividual.o
CXX = g++
CFLAGS = -fPIC -c -I$(INCLUDEDIR) -std=c++11
LFLAGS = -shared

$(LIBDIR)/Genetics/libgenetics.so: $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(LIBDIR)/Genetics/libgenetics.so

$(BUILDDIR)/geneticPopulation.o: $(SRCDIR)/geneticPopulation.cpp $(INCLUDEDIR)/Genetics/geneticPopulation.hpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/geneticPopulation.cpp -o $(BUILDDIR)/geneticPopulation.o

$(BUILDDIR)/geneticIndividual.o: $(SRCDIR)/geneticIndividual.cpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/geneticIndividual.cpp -o $(BUILDDIR)/geneticIndividual.o

clean:
	rm $(OBJS)
