#include <iostream>
using namespace std;
//Class string
class str
{
	int size=0;
	char* word;

public:
	//Constructor (standart)
	str() {
		word = new char[size+1];
		word[0] = '\0';
	}
	//Constructor copy
	str(const str& other)
	{
		size = other.size;
		word = new char[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			word[i] = other.word[i];
		}
	}
	//Constructor char
	str(const char* const arr) {
		size = strlen(arr);
		word = new char[size+1];
		for (int i = 0; i < size+1; i++)
		{
			word[i] = arr[i];
		}
	}

	//Overload operator = for string
	void operator=(const char* const arr)
	{
		if (!(word == nullptr))
		{
			delete[] word;
			word = nullptr;
		}
		size = strlen(arr);
		word = new char[size+1];
		for (int i = 0; i < size+1; i++)
		{
			word[i] = arr[i];
		}
	}
	//Overload operator = for str
	char* operator=(const str other)
	{
		if (!(word == nullptr))
		{
			delete[] word;
			word = nullptr;
		}
		size = other.size;
		word = new char[size+1];
		for (int i = 0; i < size+1; i++)
		{
			word[i] = other.word[i];
		}
		return word;
	}
	//Operator overload + for string
	char* operator+(const char*const arr)
	{
		int size = strlen(word) + strlen(arr);
		char* dual_arr = new char[size+1];
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
		dual_arr[size] = '\0';
		return dual_arr;
	}
	//Operator overload + for str
	char* operator+(const str& other)
	{
		int size = strlen(word) + strlen(other.word);
		char* dual_arr = new char[size+1];
		int i = 0;
		int j = 0;
		while (word[j] != '\0')
		{
			dual_arr[i] = word[j];
			i++;
			j++;
		}
		j = 0;
		while (other.word[j] != '\0')
		{
			dual_arr[i] = other.word[j];
			i++;
			j++;
		}
		dual_arr[size] = '\0';
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
//-------------------------------
int main()
{
	str a;
	a = "A";
	str b = a;
	cout << b.Get_Word();
}