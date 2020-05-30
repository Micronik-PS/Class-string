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
		Dead(*this);
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
		Dead(*this);
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
		int size_object = strlen(this->str);
		int size_str = strlen(str);
		int size = size_object + size_str;
		MyString Duo_Str;
		Dead(Duo_Str);
		Duo_Str.str = new char[size+1];
		int j = 0;
		for (int i = 0; i < size_object;i++,j++) {
			Duo_Str.str[j] = (this->str)[i];
		}
		for (int i = 0; i < size_str; i++, j++) {
			Duo_Str.str[j] = str[i];
		}
		Duo_Str.str[size] = '\0';
		
		return Duo_Str;
	}
	// A + B
	MyString operator + (const MyString& other) {
		int size_this_object = strlen(str);
		int size_other_object = strlen(other.str);
		int size = size_this_object + size_other_object;
		MyString Duo_Str;
		Dead(Duo_Str);
		Duo_Str.str = new char[size + 1];
		int j = 0;
		for (int i = 0; i < size_this_object; i++, j++) {
			Duo_Str.str[j] = str[i];
		}
		for (int i = 0; i < size_other_object; i++, j++) {
			Duo_Str.str[j] = other.str[i];
		}
		Duo_Str.str[size] = '\0';

		return Duo_Str;
	}
	// A == B
	bool operator==(const MyString& other) {
		if (strlen(str) == strlen(other.str)) {
			int size = strlen(str);
			for (int i = 0; i < size; i++)
			{
				if (str[i] != other.str[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	// A != B
	bool operator!=(const MyString& other) {
		if (strlen(str) == strlen(other.str)) {
			int size = strlen(str);
			for (int i = 0; i < size; i++)
			{
				if (str[i] != other.str[i]) {
					return true;
				}
			}
			return false;
		}
		else {
			return true;
		}
	}
	//// cout << A;
	//char* operator <<(const MyString&other) {
	//	return str;
	//}

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
	void Dead(const MyString& object) {
		if (object.str != nullptr) {
			delete[]object.str;
		}
	}
};

int main() {
	MyString A = "One";
	MyString B = "One";
	
}