#pragma once
class MyString
{
private:

	char* String;
	int Lenght;

public:
	MyString();//конструктор по умолчанию
	MyString(const char * str);//конструктор принимающий строку от пользователя
	explicit MyString(const MyString & str);//конструктор копирования
	MyString(const MyString && str);//конструктор перемещения


	
	operator char*() { return String; }//перегруженый оператор char* (преобразует в String)
	MyString operator +(const MyString & str);//перегруженый оператор бинарного сложения (бинарный потому что складывает два операнда, тоесть аргумент слева знака плюс и аргумент справа знака плюс)
	MyString operator *(const MyString & str);
	MyString &operator =(const MyString & str);
	MyString &operator =(const MyString && str);

	void Sort(MyString str_[], int quantity_of_strings);

	~MyString();
};

