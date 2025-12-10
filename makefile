CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

all: moneda

moneda: src/main.cpp src/MonedaMonteCarlo.cpp
	$(CXX) $(CXXFLAGS) -o moneda $^

run: moneda
	./moneda

clean:
	rm -f moneda results/simulacion.csv figuras/*.png

.PHONY: all run clean