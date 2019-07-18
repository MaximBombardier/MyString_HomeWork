#pragma once
class MyString
{
private:

	char* String;
	unsigned int Lenght;;

protected:
	MyString plus(MyString& str)const;

public:
	MyString();//����������� �� ���������
	MyString(const char * str);//����������� ����������� ������ �� ������������
	explicit MyString(const MyString & str);//����������� �����������
	MyString(const MyString && str);//����������� �����������


	
	operator const char*() { return String; }//������������ �������� char* (����������� � String)
	MyString operator *(const MyString & str);
	MyString &operator =(const MyString & str);
	MyString &operator =(const MyString && str);
	MyString operator +(MyString& str)const { return plus(str); }
	MyString operator +(char * ch)const;

	
	void Sort(MyString str_[], int quantity_of_strings);

	~MyString();
};

