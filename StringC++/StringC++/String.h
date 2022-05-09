#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int len;
public:
	String();  //����Ʈ ������
	String(const char* pStr); //���ڰ� �ִ� ������
	String(const String& ref); //���� ������ //���� ����
	~String(); //�Ҹ���

	String& operator=(const String& ref); //���� ���� //���� ����
	String operator+(const String& ref);
	String& operator+=(String& ref);
	bool operator==(const String& ref);

	friend ostream& operator<<(ostream& os, const String& ref);
	friend istream& operator<<(istream& is, String& ref);
};
