#include "String.h"
#pragma warning(disable: 4996)

String::String() //default construction
{
	len = 0;
	str = NULL;
}

String::String(const char* pStr)
{
	len = strlen(pStr) + 1;
	str = new char[len]; //str = malloc(sizeof(char) * len);
	strcpy(str, pStr);
}

String::String(const String& ref)
{
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);
}

String::~String()
{
	if (str != NULL) delete[] str; //free(str);
}

String& String::operator=(const String& ref)
{
	if (str != NULL) delete[] str;
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);

	return *this;
}

String String::operator+(const String& ref)
{
	char* tempStr = new char[len + ref.len - 1];
	strcpy(tempStr, str);
	strcat(tempStr, ref.str);

	String temp(tempStr);
	delete[] tempStr;
	return temp;
}

String& String::operator+=(String& ref)
{
	char* tempStr = new char[len + ref.len - 1];
	strcpy(tempStr, str);
	strcat(tempStr, ref.str);

	if (str != NULL) delete[] str;

	str = tempStr;
	return *this;
}

bool String::operator==(const String& ref)
{
	return (strcmp(str, ref.str) ? false : true);
}

ostream& operator<<(ostream& os, const String& ref)
{
	os << ref.str;
	return os;
}

istream& operator<<(istream& is, String& ref)
{
	char temp[256];
	is >> temp;
	ref = String(temp);
	return is;
}

int main() {
	String str1, str2;

	str1 = "서울디지텍고";
	str2 = " 안승준";
	String a = str1 + str2;
	cout << a;
}