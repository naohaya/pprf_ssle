CXX = g++
AR = ar -r 
LIBS = ./libs
CODEC = ./libs/libviterbi.a
VTBBINS = viterbi_main viterbi_test
BINS = test pprf.a ./libs/libviterbi.a ./viterbi/viterbi.o 

all: viterbi.o libviterbi.a pprf.a commitment.a test

viterbi.o: ./viterbi/viterbi.cpp
	cd ./viterbi; make; cd ..

libviterbi.a: ./viterbi/viterbi.o
	$(AR) $(CODEC) ./viterbi/viterbi.o

pprf.a: pprf.cpp $(CODEC)
	$(CXX) -std=c++11 -I./libs -c pprf.cpp $(CODEC)
	$(AR) $@ pprf.o

commitment.a: commitment.cpp ./libs/randbit.hpp
	$(CXX) -std=c++11 -I./libs -c $<
	$(AR) $@ commitment.o

test: pprf.a $(CODEC) test_pprf.cpp
	$(CXX) -std=c++11 -I./libs -o $@ test_pprf.cpp $< $(CODEC) 


clean:
	rm -f *.o ./libs/*.o ./viterbi/*.o $(VTBBINS) $(BINS) 

.PHONY: all clean
