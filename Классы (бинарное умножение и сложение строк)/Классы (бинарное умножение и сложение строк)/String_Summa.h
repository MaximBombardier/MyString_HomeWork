#pragma once
class MyString
{
private:

	char* String;
	unsigned int Lenght;

public:
	MyString();//����������� �� ���������
	MyString(const char * str);//����������� ����������� ������ �� ������������
	explicit MyString(const MyString & str);//����������� �����������
	MyString(const MyString && str);//����������� �����������


	
	operator const char*() { return String; }//������������ �������� char* (����������� � String)
	MyString operator +(const MyString & str);//������������ �������� ��������� �������� (�������� ������ ��� ���������� ��� ��������, ������ �������� ����� ����� ���� � �������� ������ ����� ����)
	MyString operator *(const MyString & str);
	MyString &operator =(const MyString & str);
	MyString &operator =(const MyString && str);

	void Sort(MyString str_[], int quantity_of_strings);

	~MyString();
};

