 /*
  Жмуркевич Владислава, ІП-72
  Рівень Б
	Використовуючи STL, створити шаблон класу, в якому міститься масив об'єктів заданого типу,
	крім базових типів, в шаблоні необхідно передбачити використання призначених для користувача типів заданих в таблиці
	(hex numbers, string). Для призначених для користувача типів перевантажити всі необхідні для маніпуляцій операції.
	Розробити для даного класу алгоритми сортування відповідно до варіанту(Сортування вибором).
  */
#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class HexNumber {
	string numb;
	int counter = 0;
public:
	HexNumber();
	void createNumb();
	int getCounter();
	int toInt();
	bool operator>(HexNumber val);
	bool operator<(HexNumber val);
	friend ostream& operator<<(ostream& out, const HexNumber& hex) {

		out << hex.numb;
		return out;
	};
	string getHexNumb();
	void show();
};

HexNumber::HexNumber()
{
	this->numb = " ";
}



void HexNumber::createNumb() {


	cout << "input hex number: ";
	cin >> numb;
	cout << endl;

	counter = numb.length();
	if ((numb[0] != '0') || numb[1] != 'x') {
		cout << "it is not correct";
	}
}

int HexNumber::getCounter() {
	return counter;
}

int HexNumber::toInt() {
	counter = getCounter();
	int count = counter - 2;
	int i = 2;

	int number = 0;
	int k;
	int p = count - 1;
	for (i = 2; i < counter; i++) {
		switch (toupper(numb[i]))
		{
		case 'A': k = 10; break;
		case 'B': k = 11; break;
		case 'C': k = 12; break;
		case 'D': k = 13; break;
		case 'E': k = 14; break;
		case 'F': k = 15; break;
		case '1': k = 1; break;
		case '2': k = 2; break;
		case '3': k = 3; break;
		case '4': k = 4; break;
		case '5': k = 5; break;
		case '6': k = 6; break;
		case '7': k = 7; break;
		case '8': k = 8; break;
		case '9': k = 9; break;
		case '0': k = 0; break;
		}
		number = number + k * pow(16, p);
		p--;
	}
	//cout << "Your number is: " << number<< endl;
	return number;

}

bool HexNumber::operator>(HexNumber val) {
	return (toInt() > val.toInt());
};

bool HexNumber::operator<(HexNumber val) {
	return (toInt() < val.toInt());
};

string HexNumber::getHexNumb() {
	return numb;
}

void HexNumber::show() {
	cout << numb;
}



class String {
	string str;
	int counter = 0;
public:
	String();
	void createString();
	string getString();
	int getCounter();
	void show();
	bool operator>(String s);
	bool operator<(String s);
	friend ostream& operator<<(ostream& out, const String& s) {
		out << s.str;
		return out;
	};
};

String::String() {
	this->str = " ";
}

void String::createString() {
	cout << "input string: ";
	cin >> str;

	cout << endl;
	counter = str.length();
}

string String::getString() {
	return str;
}

int String::getCounter() {
	return counter;
}

void String::show() {
	cout << str;
}

bool String::operator>(String s) {
	if (str > s.getString()) {
		return true;
	}
	else return false;
}

bool String::operator<(String s) {
	if (str < s.getString()) {
		return true;
	}
	else return false;
}



template <class Type>
class Sort {
	Type *arr;
	int n;
public:
	Sort() :arr(0) {};
	Sort(Type *a, int);
	~Sort();
	void show();
	void swap(Type *x, Type *y);
	void sort();
};



template <class Type>
Sort<Type>::Sort(Type *a, int k) {
	this->n = k;
	arr = new Type[n];
	for (int i = 0; i < n; i++) arr[i] = a[i];
}

template <class Type>
Sort<Type>::~Sort() {
	delete[]arr;
}

template <class Type>
void Sort<Type>::show() {
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class Type>
void Sort<Type>::swap(Type *x, Type *y) {
	Type temp = *x;
	*x = *y;
	*y = temp;
}

template <class Type>
void Sort<Type>::sort() {
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(&arr[min_idx], &arr[i]);
	}
}
template<>
class Sort<char*> {
	char** arr;
	int n;
public:
	Sort(char **arr1, int n) {
		this->n = n;
		arr = new char*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = arr1[i];
		}
	}
	~Sort() {
		for (int i = 0; i < 6; i++)
		{
			arr[i] = 0;
		}
		delete[]arr;
	}

	void show() {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << endl;
		}
	}

	char **findSmallest(char **c, int len) {
		char **smalest = &c[0];
		for (char i = 1; i < len; i++) {
			if (strcmp(*smalest, c[i]) > 0)
				smalest = &c[i];
		}
		return(smalest);
	}

	void swap(char **x, char **y) {
		char *temp = *x;
		*x = *y;
		*y = temp;
	}

	void sort() {
		char **smalest;
		char **end = arr + n - 1;
		for (char **p = arr; p < end; p++) {
			int len = (end - p) + 1;
			smalest = findSmallest(p, len);
			swap(smalest, p);
		}
	}
};






int main()
{

	char ch;
	do {
		HexNumber h;
		h.createNumb();
		HexNumber j;
		j.createNumb();
		HexNumber z;
		z.createNumb();
		HexNumber* arr = new HexNumber[3];
		arr[0] = h;
		arr[1] = j;
		arr[2] = z;
		Sort<HexNumber> s(arr, 3);
		s.sort();
		s.show();
		String a;
		a.createString();
		String b;
		b.createString();
		String c;
		c.createString();
		String* arr2 = new String[3];
		arr2[0] = a;
		arr2[1] = b;
		arr2[2] = c;
		Sort<String> k(arr2, 3);
		k.sort();
		k.show();
		//s.show();

		cout << "Do you want to continue? y/n" << endl;
		cout << ">> ";
		cin >> ch;
		cout << endl;
	}

	while (ch != 'n');

}

