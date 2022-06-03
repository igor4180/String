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
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//		Constructors:
	explicit String(int size = 80):size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Def1aConstructor:\t" << this << endl;
	}
	String(const char* str):String(strlen(str)+1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):String(other.str)
	{
		//CopyConstructor должен выполнять DeepCopy (Побитовое копирование)
		//т.е. , выделить новую память и скопировать в нее содержимое другого объекта
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//поверхностное копирование
		//this->size = other.size;
		//this->str = other.str;
		other.size = 0;
		other.str = nullptr; //зануляем адрес памяти в другом объекте
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//	Operators:
	String& operator=(const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	//		Metods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;

}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

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