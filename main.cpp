/*
	@file main.cpp
	@author Tommy Gallagher
	@date 09/26/15
	@main method
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "Test.h"

using namespace std;

void printMenu()
{
	   cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}

int main(){

DoubleLinkedList<int>* test = new DoubleLinkedList<int>;
int usr = 0;
int inp = 0;
int inp2 = 0;
while(usr!=9){

printMenu();

cin >> usr;

if(usr==1){

cout << "Give a value: ";
cin >> inp;
test -> pushFront(inp);
cout << "Pushing " << inp << " to the front of the list.";
}

if(usr==2){

cout << "Give a value: ";
cin >> inp;
test -> pushBack(inp);
cout << "Pushing " << inp << " to the back of the list.";
}



if(usr==3){

cout << "Enter a value to insert: ";
cin >> inp;
cout << "Pick a value to insert behind: ";
cin >> inp2;
try
{
	test -> insertBehind(inp2, inp);
}
catch (std::runtime_error& e)
{
	cout << e.what() << std::endl;
}

}

if(usr==4){

cout << "Enter a value to insert: ";
cin >> inp;
cout << "Pick a value to insert ahead of: ";
cin >> inp2;


try
{
	test -> insertAhead(inp2, inp);
}
catch (std::runtime_error& e)
{
	cout << e.what() << std::endl;
}


}

if(usr==5){

cout << "Attempting to remove from front of list...\n";
if(test -> removeFront()){
cout << "Removal Successful\n";
}else{
cout << "No values to remove\n";
}

}

if(usr==6){

cout << "Attempting to remove from back of list...\n";
if(test -> removeBack()){
cout << "Removal Successful\n";
}else{
cout << "No values to remove\n";
}

}


if(usr==7){

cout << "Enter a value to remove: ";
cin >> inp;
cout << "You entered " << inp << "...\n";
if(test -> remove(inp)){
cout << inp << " removed from list";
}else{
cout << inp << " is not in the list.";
}

}

if(usr==8){

cout << "Printing List: \n";
test -> printList();

}

if(usr==10){

Test myTester(std::cout);
myTester.runTests();

}
}
delete test;
test=nullptr;
	return(0);
}
