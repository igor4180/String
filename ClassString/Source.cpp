#include"String.h"

//#define CONSTRUCTORS_CHECK
#define MOVE_METHODS_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK



	String str1;  //Default constructor
	str1.print();

	String str2(5); //Single-Argument constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3;
	str4.print();

	String str5;
	str5 = str4;
	str5.print();
#endif CONSTRUCTORS_CHECK

#ifdef MOVE_METHODS_CHECK
	String str1 = "Hello";
	String str2("World");
	//String str3 = str1 + " " + str2;
	String str3;
	str3 = str1 + str2;
	//str3.print();
	cout << str3 << endl;

	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;
	cout << delimiter << endl;
#endif

#ifdef CALLING_CONSTRUCTORS
	//Способы вызова и написания конструкторов
	String str1;	// – конструктор по умолчанию
	String str2(55);// -конструктор с 1 параметром
	String str3 = "Hello";// с 1 параметром(const char* || const char[])
	str3.print();
	String str4 = str3; //конструктор копирования
	String str5;
	str5 = str4; //оператор присваивания
	str5.print();
	String str6();  //не вызывается никаких конструкторов и не создается объект.Здесь объявляется функция str6(), которая ничего не принимает и возвращает объект класса string
	String str7{}; //явный вызов конструктора по умолчанию
#endif
}