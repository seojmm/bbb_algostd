#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	string str; 
	cin >> str;
	stack<char> stk;
	bool flag = true;

	for (int i = 0; i < str.length(); i++) {
		if(!stk.empty())
			cout << stk.top() << endl;
		if (str.at(i) == '(' || str.at(i) == '[')
			stk.push(str.at(i));
		else if (str.at(i) == ')'){
			if (stk.top() == '(')
				stk.pop();
			else if (stk.empty() || str.at(i) == ']') {
				flag = false;
				break;
			}
		}
		else if (str.at(i) == ']') {
			if (stk.top() == '[')
				stk.pop();
			else if (stk.empty() || str.at(i) == ']') {
				flag = false;
				break;
			}
		}
	}

	if (flag && stk.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}