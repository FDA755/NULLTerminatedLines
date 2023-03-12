//NULLTerminatedLines - ������, ��������������� �����. ���� �������� ��������� ����� ������ � ���������� NULL Terminator
#include<iostream>
#include<Windows.h>

using namespace std;

int string_lenght(const char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_polindrome(char str[]);

void main()
{
	setlocale(LC_ALL, "Rus");
	//cout << "Hello Strings" << endl;
	////char str[] = { 'H','e', 'l','l','o', 0 };
	//char  str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;
	cout << (int)'a' << endl;
	cout << (int)'A' << endl;
	cout << 'A' - 'a' << endl;
	const int n = 256;
	char str[n] = {};
	cout << "������� ������: "; //cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "�� ����� ������ ������� " << string_lenght(str) << " ��������: " << endl;
	cout << "�� ����� ������ ������� " << strlen(str) << " ��������: " << endl;  //strlen() - ����������� ������ ��������� ����� ������
	to_upper(str); cout << str << endl;
	to_lower(str); cout << str << endl;
	shrink(str); cout << str << endl;
	cout << "������ " << (is_polindrome(str) ? "" : "�� ") << "���������" << endl;
}

int string_lenght(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	int i = 0;
	for (; str[i]; i++)
	{
		//if (str[i] >= 'a' && str[i] <='z') str[i] -= ' ';   //������ ������ ����� int = 32
		//if (str[i] >= '�' && str[i] <='�') str[i] -= ' ';   //������ ������ ����� int = 32
		str[i] = toupper(str[i]); // toupper -����������� ������� C++
	}
}
void to_lower(char str[])
{
	int i = 0;
	for (; str[i]; i++)str[i] = tolower(str[i]);
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
bool is_polindrome(char str[])
{
	to_lower(str);
	remove_symbol(str, ' ');
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - 1 - i])return false;
	}
	return true;
}