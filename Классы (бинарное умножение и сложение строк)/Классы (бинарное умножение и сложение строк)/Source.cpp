#include"String_Summa.h"
#include<iostream>

MyString::MyString()
{
	Lenght = 0;
	String=NULL;
}

MyString::MyString(const char* str)
{
	Lenght = strlen(str);
	String = new char[Lenght + 1];
	strcpy_s(String, Lenght+1, str);

}

MyString::MyString(const MyString & str)
{
	Lenght = strlen(str.String);
	String = new char[Lenght + 1];
	strcpy_s(String, Lenght+1, str.String);
}

MyString::MyString(const MyString && str)
{
	
	Lenght = strlen(str.String);
	String = new char[Lenght + 1];
	strcpy_s(String, Lenght+1, str.String);
}

MyString MyString::plus( MyString & str)const
{
	MyString New_string;
	New_string.Lenght = strlen(str.String);
	New_string.String = new char[str.Lenght + Lenght + 1];
	strcpy_s(New_string.String, Lenght + 1, String);
	strcat_s(New_string.String, New_string.Lenght + Lenght + 1, str.String);
	return New_string;
}

MyString&MyString::operator =(const MyString & str)
{
	if (this == &str)// предотвращение варианта присваивания самому себе (компилятору не нужно будет угадывать какую строку вы имели в виду, тут вы уже сразу возвращаете значение на на саму строку, если она равна самой себе, т.е. если она одинакова)
	{
		return *this;//возвращаем указатель на самого себя
	}

		delete[]String;
	
	Lenght = strlen(str.String);
	String = new char[Lenght + 1];
	strcpy_s(String, Lenght + 1, str.String);
	return *this;

}

MyString&MyString::operator =(const MyString && str)
{
	if (this == &str)// предотвращение варианта присваивания самому себе (компилятору не нужно будет угадывать какую строку вы имели в виду, тут вы уже сразу возвращаете значение на на саму строку, если она равна самой себе, т.е. если она одинакова)
	{
		return *this;//возвращаем указатель на самого себя
	}

		delete[]String;
	
	Lenght = strlen(str.String);
	String = new char[Lenght + 1];
	strcpy_s(String, Lenght + 1, str.String);
	return *this;
}




void MyString::Sort(MyString str_[], int Lenght)
{
	MyString temp;
	for (int i = 0; i < Lenght - 1; i++)
	{
		for (int j = Lenght - 1; j > i; j--)
			if (strcmp(str_[j].String, str_[j - 1].String) < 0)
			{
				temp = str_[j];
				str_[j] = str_[j - 1];
				str_[j - 1] = temp;
			}
	}

}

int cntchr(MyString string, char symbol)
{
	int count = 0;
	MyString tmp = strchr(string, symbol);
	while (tmp != nullptr)
	{
		count++;
		tmp = strchr(tmp + 1, symbol);
	}
	return count;
}

bool intersect(MyString string, MyString control, char symbol)
{
	int count_ctrl = cntchr(control, symbol);
	int count_smbl = cntchr(string, symbol);
	return count_ctrl >= count_smbl && isalnum(symbol);
}

MyString MyString:: operator *(const MyString & str)
{
	MyString temp;
	char* line = strpbrk(String, str.String);
	while (line != nullptr)
	{
		if (intersect(line, str.String, *line))
			temp = temp + *line;
		line = strpbrk(line + 1, str.String);
	}
	Sort(&temp, Lenght);
	return temp;
}

MyString MyString::operator +(char * ch)const
{
	char* str = new char[2]{ *ch,'\0' };
	MyString line = *this + str;
	delete[] str;
	return line;
}



MyString::~MyString()
{
	delete[]String;

}