#ifdef _WIN32
  #include <Windows.h>
#else
  #include <unistd.h>
#endif
#include <iostream>
#include <string>
#include <cstdlib>

#include "Animal.h"

using namespace std;

void Datatypes() {
  int myNum = 5;              
  float myFloatNum = 5.99;     
  double myDoubleNum = 9.98;   
  char myLetter = 'D';         
  bool myBoolean = true;      
  string myText = "Hello";   
  string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"}; 
  string food = "Pizza";
  string &meal = food;
  string* ptr = &food;

  cout << food << "\n";  
  cout << meal << "\n";  
  cout << &food << "\n";  
  cout << ptr << "\n";
  cout << *ptr << "\n";

  *ptr = "Hamburger";
  cout << food << "\n";  
  cout << meal << "\n";  
  cout << &food << "\n";  
  cout << ptr << "\n";
  cout << *ptr << "\n";
}

void swapNums(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}

void Sum() {
  int x = 0, y = 0;
  cout << "\n\tEnter First Number: ";
  cin >> x;
  cout << "\tEnter Second Number: ";
  cin >> y;
  int result = x + y;
  cout << "\tResult: " << result << "\n";
}

int main() {

  // Datatypes();
  // Sum();

  Animal Cat;
  
  return 0;
}