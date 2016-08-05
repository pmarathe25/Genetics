BUILDDIR = build/
INCLUDEDIR = include/
SRCDIR = src/
LIBDIR = lib/
LIBS = Genetics/libgenetics.so
OBJS = $(BUILDDIR)/geneticPopulation.o $(BUILDDIR)/geneticIndividual.o $(BUILDDIR)/computedPopulation.o $(BUILDDIR)/computedIndividual.o
CXX = g++
CFLAGS = -fPIC -c -I$(INCLUDEDIR) -std=c++11
LFLAGS = -shared

$(LIBDIR)/Genetics/libgenetics.so: $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(LIBDIR)/Genetics/libgenetics.so

$(BUILDDIR)/geneticPopulation.o: $(SRCDIR)/geneticPopulation.cpp $(INCLUDEDIR)/Genetics/geneticPopulation.hpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/geneticPopulation.cpp -o $(BUILDDIR)/geneticPopulation.o

$(BUILDDIR)/geneticIndividual.o: $(SRCDIR)/geneticIndividual.cpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/geneticIndividual.cpp -o $(BUILDDIR)/geneticIndividual.o

$(BUILDDIR)/computedPopulation.o: $(SRCDIR)/computedPopulation.cpp $(INCLUDEDIR)/Genetics/computedPopulation.hpp $(INCLUDEDIR)/Genetics/geneticPopulation.hpp \
	$(INCLUDEDIR)/Genetics/computedIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/computedPopulation.cpp -o $(BUILDDIR)/computedPopulation.o

$(BUILDDIR)/computedIndividual.o: $(SRCDIR)/computedIndividual.cpp $(INCLUDEDIR)/Genetics/computedIndividual.hpp $(INCLUDEDIR)/Genetics/geneticIndividual.hpp
	$(CXX) $(CFLAGS) $(SRCDIR)/computedIndividual.cpp -o $(BUILDDIR)/computedIndividual.o


clean:
	rm $(OBJS)
