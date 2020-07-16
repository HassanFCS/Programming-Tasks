#include<iostream>
#include<string>
#include<sstream>
#include <algorithm>
#include<fstream>
using namespace std;
template <class T>
class Stack {
	T *data;
	int top = -1;
	const int MAX_SIZE = 30;
public:
	Stack() {
		data = new T[MAX_SIZE];
	}
	~Stack() {
		delete[]data;
	}
	void Push(const T newItem) {
		data[++top] = newItem;
	}
	T Pop() {
		T val = data[top--];
		return val;
	}
	T Top() {
		return data[top];
	}
	void clear() {
		top = -1;
	}
	bool isEmpty() const {
		return (top == -1);
	}
	bool isFull() const {
		return (top == MAX_SIZE - 1);
	}
};
class alphabetValue {
	static const char alphabet[26];
	int values[26], changed[26];
public:
	alphabetValue(){
		for (int i = 0; i < 26; i++)
			values[i] = changed[i] = 0;
	}
	int getvalue(char c) {
		for (int i = 0; i < 26; i++){
			if (alphabet[i] == c)
				return values[i];
		}
		return values[0];
	}
	void setvalue(char c, int num) {
		for (int i = 0; i < 26; i++)
		if (alphabet[i] == c) {
			changed[i] = num;
			break;
		}
	}
	void showChange(string sc) {
		int c = 0;
		for (int i = 0; i < 26; i++){
			if (values[i] != changed[i]) {
				cout << alphabet[i] << " = " << changed[i] << ", ";
				c++;
				char ch = alphabet[i];
				sc.erase(remove(sc.begin(), sc.end(), ch), sc.end());
			}
		}
		for (char c : sc){
			if (changed[c - 65] == 0){
				cout << alphabet[c - 65] << " = " << changed[c - 65] << ", ";
			}
		}
		if (c != 0)
			cout << "\b\b \n";
		else
			cout << "No Change\n";
	}
	void copyChange() {
		for (int i = 0; i < 26; i++)
			values[i] = changed[i];
	}
};

const char alphabetValue::alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

void execute(Stack <char>&stack_alp, Stack <int>&stack_num, Stack <char>&stack_op, alphabetValue &element) {
	char n, ch1, ch2;
	int num1, num2;
	while (stack_op.isEmpty() != true) {
		n = stack_op.Pop();
		if (n == '*' || n == '/' || n == '+' || n == '-') {
			if (stack_num.isEmpty()) {
				ch2 = stack_alp.Pop();
				ch1 = stack_alp.Pop();
				num1 = element.getvalue(ch1);
				num2 = element.getvalue(ch2);
			}
			else {
				num2 = stack_num.Pop();
				if (stack_num.isEmpty()) {
					ch1 = stack_alp.Pop();
					num1 = element.getvalue(ch1);
				}
				else
					num1 = stack_num.Pop();
			}
			int result;
			if (n == '*')
				result = num1*num2;
			else if (n == '/')
				result = num1 / num2;
			else if (n == '+')
				result = num1 + num2;
			else if (n == '-')
				result = num1 - num2;
			stack_num.Push(result);
		}
		else if (n == '=') {
			num1 = stack_num.Pop();
			ch1 = stack_alp.Pop();
			element.setvalue(ch1, num1);
			stack_num.Push(num1);
		}
		else if (n == '(')
			break;
	}
}
int main() {
	char c = '\n';
	int d, j = 0;
	string s[10], line;
	alphabetValue element;
	Stack <char>stack_alp;
	Stack <int>stack_num;
	Stack <char>stack_op;

	ifstream inf("input.txt");
	getline(inf, line);
	while (!inf.eof()) {
		s[j] = line;
		getline(inf, line);
		j++;
	}
	inf.close();

	string save_char = "";
	for (int i = 0; i < j; i++) {
		s[i] = s[i] + c;
		for (int k = 0; k < s[i].length(); k++) {
			if (s[i][k] >= 'A'&& s[i][k] <= 'Z'){
				stack_alp.Push(s[i][k]);
				save_char += s[i][k];
			}
			else if (s[i][k] >= '0' && s[i][k] <= '9') {
				string temp = "";
				while (true) {
					temp = temp + s[i][k];
					if (k == s[i].length() - 2)
						break;
					k++;
					if (s[i][k] == ' ' || s[i][k] == ')' || s[i][k] == '\n')
						break;
				}
				if (s[i][k] == ')')
					k--;
				stringstream(temp) >> d;
				stack_num.Push(d);
			}
			else if (s[i][k] == '~') {
				string temp = "";
				k++;
				while (true) {
					temp = temp + s[i][k];
					if (k == s[i].length() - 2)
						break;
					k++;
					if (s[i][k] == ' ' || s[i][k] == ')' || s[i][k] == '\n')
						break;
				}
				if (s[i][k] == ')')
					k--;
				stringstream(temp) >> d;
				stack_num.Push(-d);
			}
			else if (s[i][k] == '+' || s[i][k] == '-' || s[i][k] == '/' || s[i][k] == '*' || s[i][k] == '(' || s[i][k] == '=')
				stack_op.Push(s[i][k]);
			else if (s[i][k] == ')' || s[i][k] == '\n') {
				execute(stack_alp, stack_num, stack_op, element);
				if (s[i][k] == '\n') {
					element.showChange(save_char);
					element.copyChange();
					stack_alp.clear();
					stack_num.clear();
					stack_op.clear();
				}
			}
		}
		save_char = "";
	}
	system("PAUSE");
	return 0;
}
