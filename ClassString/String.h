#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n-------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	int size; //Размер строки в Байтах
	char* str; //Указатель на строку
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//		Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//	Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);

	const char& operator[](int i)const;
	char& operator[](int i);
	String& operator+=(const String& other);

	//		Metods:
	void print()const;
};

String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
