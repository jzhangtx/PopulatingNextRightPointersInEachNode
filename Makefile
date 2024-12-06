PopulatingNextightPointers: PopulatingNextightPointers.o
	g++ -g -o PopulatingNextightPointers.exe PopulatingNextightPointers.o -pthread    

PopulatingNextightPointers.o: PopulatingNextightPointers/PopulatingNextightPointers.cpp
	g++ -g  -c -pthread PopulatingNextightPointers/PopulatingNextightPointers.cpp
