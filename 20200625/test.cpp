#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//字符串拼接
class Solution1 {
public:
	string reverseLeftWords(string s, int n) {
		string ret = "";
		for (int i = n; i < s.size(); ++i) {
			ret += s[i];
		}
		for (int i = 0; i < n; ++i) {
			ret += s[i];
		}
		return ret;
	}
};
//
class String {
public:
	//构造函数
	String(const char* str) {
		_str = new char[strlen(str)+1];
		strcpy(_str, str);
		_size = strlen(str);
		_capacity = _size;
	}
	//拷贝构造函数
	/*String(const String& s)
		:_str(new char[s._capacity + 1])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);
	}*/
	//
	void Swap( String& s) {
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	//拷贝构造函数:现代写法
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0) 
	{
		String tmp(s._str);
		Swap(tmp);
	}
	  
	//赋值运算符
	/*String& operator=(const String& s) {
		if (this != &s) {
			char* tmp = new char[s._size + 1];
			strcpy(tmp, s._str);
			delete[]_str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}*/
	//赋值运算符:现代写法
	String& operator=(String s) {
		Swap(s);
		return *this;
	}
	//析构函数
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin() {
		return _str;
	}
	iterator end() {
		return _str + _size;
	}
	const_iterator begin() const{
		return _str;
	}
	const_iterator end()const {
		return _str + _size;
	}

	const char* c_str()const {
		return _str;
	}

	char& operator[](size_t pos) {
		if (pos < _size) {
			return _str[pos];
		}
	}
	const char& operator[](size_t pos)const {
		if (pos < _size) {
			return _str[pos];
		}
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
void PrintString(String& s) {
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	String::const_iterator cit = s.begin();
	while (cit != s.end()) {
		cout << *cit << " ";
		++cit;

	}
	cout << endl;
	//范围for:
	for (auto e : s) {
		cout << e << " ";
	}
	cout << endl;
}
void test() {
	String s("987654321");
	PrintString(s);
}
int main() {
	test();
	return 0;
}