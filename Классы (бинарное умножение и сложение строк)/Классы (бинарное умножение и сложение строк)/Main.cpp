#include<iostream>
#include<cstring>
#include"String_Summa.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");





	MyString first= "two merry geese" ;
	MyString second = " lived with granny";
	MyString concatenation = first + second;
	//MyString intersection = first * second;
	std::cout << "First: " << first << std::endl;
	std::cout << "Second: " << second << std::endl;
	std::cout << "Concatenation: " << concatenation << std::endl;
	//std::cout << "Intersection: " << intersection << std::endl;
	system("pause");







	system("pause");
	return 0;

}