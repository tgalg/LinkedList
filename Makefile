Lab03: main.o Test.o
	g++ -std=c++11 -g -Wall main.o Test.o -o Lab03

main.o: main.cpp Node.h Node.hpp DoubleLinkedList.h DoubleLinkedList.hpp Test.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp


	
clean:
	rm *.o Lab03
	echo clean done

