#include <iostream>
using namespace std;
// Function output count symbols in word
int word_n(const char* const arr)
{
	int i = 0;
	while (!(arr[i] == '\0'))
	{
		i++;
	}
	return i;
}
//Class string
class str
{
	int size;
	char* word;

public:
	//Constructor (standart)
	str() {}
	//Constructor copy
	str(str& other)
	{
		size = other.size;
		word = other.word;
	}
	//Overload operator = for string
	void operator=(const char* const arr)
	{
		size = word_n(arr) + 1;
		word = new char[size];
		for (int i = 0; i < size; i++)
		{
			word[i] = arr[i];
		}
	}
	//Overload operator = for str
	char* operator=(str& other)
	{
		if (!(word == nullptr))
		{
			delete[] word;
			word = nullptr;
		}
		size = other.size;
		word = new char[size];
		for (int i = 0; i < size; i++)
		{
			word[i] = other.word[i];
		}
		return word;
	}
	//Overload operator << (DANGEON)
	char* output()
	{
		return word;
	}
	//Overload operator + for string
	char* operator+(const char* const arr)
	{
		int size = word_n(word) + word_n(arr) + 1;
		char* dual_arr = new char[size];
		int i = 0;
		int j = 0;
		while (word[j] != '\0')
		{
			dual_arr[i] = word[j];
			i++;
			j++;
		}
		j = 0;
		while (arr[j] != '\0')
		{
			dual_arr[i] = arr[j];
			i++;
			j++;
		}
		dual_arr[size - 1] = '\0';
		return dual_arr;
	}
	//Get_Size
	int Get_Size()
	{
		return size;
	}
	//Get_Word
	char* Get_Word()
	{
		return word;
	}
	//Deconstructor, delete Dynamic array with memory
	~str()
	{
		delete[] word;
		word = nullptr;
	}
};
void foo(str o)
{
	cout << o.output();
}
//-------------------------------
int main()
{
}