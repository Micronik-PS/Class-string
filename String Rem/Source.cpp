#include <iostream>
using namespace std;
class String {
public:

	String() {
		size = 0;
		word = new char[1];
		word[0] = '\0';
	}
	String(const char *const word) {
		size = size_w(word);
		this->word = new char[size+1];
		for (int i = 0; i < size; i++) {
			this->word[i] = word[i];
		}
		this->word[size] = '\0';
	}
	String(const String& object){
		size = object.size;
		word = new char[size + 1];
		for (int i = 0; i < size; i++) {
			word[i] = object.word[i];
		}
		this->word[size] = '\0';
	}
	String(String&& object) {
		size = object.size; 
		word = object.word;
		object.word = nullptr;
	}
	~String(){
		delete[]word;
		word = nullptr;
	}

	String& operator=(const String& other) {
		this->del();
		size = other.size;
		word = new char[size+1];
		for (int i = 0; i < size; i++) {
			word[i] = other.word[i];
		}
		this->word[size] = '\0';
		return *this;
	}
	String operator+(const String& other) {
		String time;
		time.del();
		time.size = this->size + other.size;
		time.word = new char[time.size + 1];
		int j=0;
		for (int i = 0; i < this->size; i++,j++) {time.word[j] = this->word[i];}
		for (int i = 0; i < other.size; i++, j++) {time.word[j] = other.word[i];}
		time.word[time.size]='\0';
		return time;
	}
	bool operator==(const String& other) {
		if (size == other.size) {
			for (int i = 0; i < size; i++) {
				if (word[i] != other.word[i]) { return false; }
			}
			return true;
		}
		else { return false; }
	}
	bool operator!=(const String& other) {
		if (size == other.size) {
			for (int i = 0; i < size; i++) {
				if (word[i] != other.word[i]) { return true; }
			}
			return false;
		}
		else { return true; }
	}
	char& operator[] (const int i) {
		return word[i];
	}

	int lenght() {
		return size;
	}
	 	
	 
private:
	void del() {
		delete[]word;
		word = nullptr;
		size = 0;
	}
	int size_w(const char* const word) {
		int i = 0;
		while (word[i] != '\0') { i++; }
		return i;
	}

	char* word;
	int size;
};

int main() {
}