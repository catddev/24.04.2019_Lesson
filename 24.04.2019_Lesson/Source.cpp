#include"Stack.h"

int main() {
	
	Stack<double> s;
	s.push(1.5);
	s.push(2.2);
	s.push(3.4);
	s.push(9.5);
	s.push(8.2);
	s.push(7.7);
	s.print();

	s.pop();
	cout << "last" << s.top() << endl;

	while (!s.empty()) {//prints while stack s is not empty, the same: while(s.size()!=0)
		cout << s.top() << endl;
		s.pop();
	}
	if (s.empty()) cout << "empty now" << endl;

	Stack<char> par;
	string str;
	int choice = 0;
	while (true) {
		cout << "Enter 1 to exit" << endl;
		cout << "Enter 2 to continue" << endl;
		cin >> choice;
		if (choice == 1) break;
		cout << "Enter a string" << endl;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (par.empty() && str[i] == ')') {
				cout << "wrong" << endl;
				break;
			}
			if (str[i] == '(') par.push('(');
			if (str[i] == ')') par.pop();

			if ((i == str.length()-1) && par.empty())
				cout << "right" << endl;
			else if ((i == str.length()-1) && !par.empty())
				cout << "wrong" << endl;
		}
	}






	system("pause");
	return 0;
}