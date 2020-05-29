#include <iostream>
using namespace std;
//Class string
class MyString
{
public:
	// MyString A = "Text";
	MyString(const char*const str) {
		int size = strlen(str);
		this->str = new char[size+1];
		for (int i = 0; i < size; i++)
		{
			(this->str)[i] = str[i];
		}
		(this->str)[size] = '\0';
	}
	// MyString A = B;
	MyString(const MyString& other) {
		int size = strlen(other.str);
		str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			str[i] = (other.str)[i];
		}
		str[size] = '\0';
	}
	// MyString A;
	MyString() {
		int size = 0;
		str = new char[size + 1];
		str[size] = '\0';
	}
	MyString& operator = (const char* const str) {
		Dead();
		int size = strlen(str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			(this->str)[i] = str[i];
		}
		(this->str)[size] = '\0';
		return *this;
	}
	// A = B;
	MyString& operator = (const MyString& other) {
		Dead();
		int size = strlen(other.str);
		str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			str[i] = (other.str)[i];
		}
		str[size] = '\0';
		return *this;
	}
	// A + "Text"
	MyString operator + (const char*const str) {
		char Duo_Str_Arr[255];
		int j = 0;
		int size_object = strlen(this->str);
		int size_str = strlen(str);
		for (int i = 0; i < size_object;i++,j++) {
			Duo_Str_Arr[j] = (this->str)[i];
		}
		for (int i = 0; i < size_str; i++, j++) {
			Duo_Str_Arr[j] = str[i];
		}
		Duo_Str_Arr[size_object + size_str] = '\0';
		MyString Duo_Str = Duo_Str_Arr;
		return Duo_Str;
	}
	// A + B
	MyString operator + (const MyString& other) {
		char Duo_Str_Arr[255];
		int j = 0;
		int size_this_object = strlen(str);
		int size_other_object = strlen(other.str);
		for (int i = 0; i < size_this_object; i++, j++) {
			Duo_Str_Arr[j] = str[i];
		}
		for (int i = 0; i < size_other_object; i++, j++) {
			Duo_Str_Arr[j] = other.str[i];
		}
		Duo_Str_Arr[size_this_object + size_other_object] = '\0';
		MyString Duo_Str = Duo_Str_Arr;
		return Duo_Str;
	}
	

	// Output str;
	void print() {
		int size = strlen(str);
		for (int i = 0; i < size; i++)
		{
			cout << str[i];
		}
	}
	// Deconstructor
	~MyString() {
		delete[]str;
		str = nullptr;
	}
private:
	char* str=nullptr;
	//Check Alive Word
	void Dead() {
		if (str != nullptr) {
			delete[]str;
		}
	}
};

int main() {

}