#include <iostream>
using namespace std;
// ������� ������ ���������� �������� � ����� (�� ������ 0 ������������)
int word_n(const char* const arr)
{
	int i = 0;
	while (!(arr[i] == '\0'))
	{
		i++;
	}
	return i;
}
//����� string
class str
{
	int size;
	char* word;

public:
	//����������� (�����������)
	str() {}
	//����������� �����������
	str(str& other)
	{
		size = other.size;
		word = other.word;
	}
	//���������� ��������� = ��� ������
	void operator=(const char* const arr)
	{
		size = word_n(arr) + 1;
		word = new char[size];
		for (int i = 0; i < size; i++)
		{
			word[i] = arr[i];
		}
	}
	//���������� ��������� = ��� str
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
	//���������� ��������� <<
	char* output()
	{
		return word;
	}
	//���������� ��������� +
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
		char* time = dual_arr;
		/*delete[]dual_arr;
		dual_arr = nullptr;*/
		return time;
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
	//�������������, ��������� ������������ ������ � ������/
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