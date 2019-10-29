all: main

main: main.cpp graph.cpp files.cpp
	g++ main.cpp graph.cpp files.cpp -o main

clean: 
	rm -rf *.png *.dot main
