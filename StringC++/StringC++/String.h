#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int len;
public:
	String();  //디폴트 생성자
	String(const char* pStr); //인자가 있는 생성자
	String(const String& ref); //복사 생성자 //깊은 복사
	~String(); //소멸자

	String& operator=(const String& ref); //깊은 복사 //얕은 복사
	String operator+(const String& ref);
	String& operator+=(String& ref);
	bool operator==(const String& ref);

	friend ostream& operator<<(ostream& os, const String& ref);
	friend istream& operator<<(istream& is, String& ref);
};
