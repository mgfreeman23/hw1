#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  //check push_back functionality
  ULListStr list = ULListStr();
  std::string valToAdd = "hello1";
  list.push_back(valToAdd);
  valToAdd = "hello2";
  list.push_back(valToAdd);
  valToAdd = "hello3";
  list.push_back(valToAdd);
  valToAdd = "hello4";
  list.push_back(valToAdd);
  valToAdd = "hello5";
  list.push_back(valToAdd);
  valToAdd = "hello6";
  list.push_back(valToAdd);
  valToAdd = "hello7";
  list.push_back(valToAdd);
  valToAdd = "hello8";
  list.push_back(valToAdd);
  valToAdd = "hello9";
  list.push_back(valToAdd);
  valToAdd = "hello10";
  list.push_back(valToAdd);
  valToAdd = "hello11";
  list.push_back(valToAdd);

  for(int i = 0; i < 11; i++){
    std::cout << list.get(i) << std::endl;
  }

  ULListStr list1 = ULListStr();
  //check push back and pop back functionality
	for(int index = 0; index < 4; ++index)
	{
    std::string valToAdd = "test";
    list1.push_back(valToAdd);
    std::cout << "string in list: " << list1.get(0) << std::endl;
		list1.pop_back();
    std::cout << "list size: " << list1.size() << std::endl;
	}

  //check push front and pop front functionality
  ULListStr list2 = ULListStr();
	for(int index = 0; index < 4; ++index)
	{
    std::string valToAdd = "test";
    list2.push_front(valToAdd);
    std::cout << "string in list: " << list2.get(0) << std::endl;
		list2.pop_front();
    std::cout << "list size: " << list2.size() << std::endl;
	}

  //check back and front functionality
  ULListStr list3 = ULListStr();
  list3.push_front("hello");
  list3.push_back("world");
  std::cout << "first string: " << list3.front() << std::endl;
  std::cout << "last string: " << list3.back() << std::endl;


}
  


