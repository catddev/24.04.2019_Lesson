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
			else if (str[i] == ')') par.pop();

			if ((i == str.length()-1) && par.empty())
				cout << "right" << endl;
			else if ((i == str.length()-1) && !par.empty())
				cout << "wrong" << endl;
		}
	}

	//проверить, чтобы в монетнице были только монеты меньше 10
	cout << endl << endl;
	Stack<int>money;
	Stack<int>buf;
	
	int coin = -1;
	while (coin != 0) {
		cin >> coin;
		money.push(coin);//закидываем все монеты
	}
	money.pop(); //erasing 0

	while (!money.empty()) {
		if (money.top() < 10) {
			buf.push(money.top());//все монеты меньше 10 в буфер стек
		}
		money.pop();//пошагово очищаем первый стек (монетницу)
	}
	money = buf;//все из буфера в монетницу
	money.print();

	system("pause");
	return 0;
}