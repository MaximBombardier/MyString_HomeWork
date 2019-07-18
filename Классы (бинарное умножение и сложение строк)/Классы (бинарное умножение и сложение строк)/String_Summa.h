#pragma once
class MyString
{
private:

	char* String;
	unsigned int Lenght;;

protected:
	MyString plus(MyString& str)const;

public:
	MyString();//конструктор по умолчанию
	MyString(const char * str);//конструктор принимающий строку от пользователя
	explicit MyString(const MyString & str);//конструктор копирования
	MyString(const MyString && str);//конструктор перемещения


	
	operator const char*() { return String; }//перегруженый оператор char* (преобразует в String)
	MyString operator *(const MyString & str);
	MyString &operator =(const MyString & str);
	MyString &operator =(const MyString && str);
	MyString operator +(MyString& str)const { return plus(str); }
	MyString operator +(char * ch)const;

	
	void Sort(MyString str_[], int quantity_of_strings);

	~MyString();
};

