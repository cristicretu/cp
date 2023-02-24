#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

string s;
unsigned long i;
int eval();
int eval1();
int eval2();

int eval() {
	int ans = eval1();
	
	while (s[i] == '+' || s[i] == '-') {
		if (s[i] == '+') {
			++i;
			ans += eval1();
		} else {
			++i;
			ans -= eval1();
		}
	}
	
	return ans;
}

int eval1() {
	int ans = eval2();
	
	while (s[i] == '*' || s[i] == '/') {
		if (s[i] == '*') {
			++i;
			ans *= eval2();
		} else {
			++i;
			ans /= eval2();
		}
	}
	
	return ans;
}

int eval2() {
	int ans = 0;
	
	if (s[i] == '(') {
		++i;
		ans += eval();
		++i;
	} else {
		while (s[i] >= '0' && s[i] <= '9') {
			ans = ans * 10 + (s[i] - '0');
			++i;
		}
	}
	
	return ans;
}

int main() {
	fin >> s;
	fout << eval();
}
