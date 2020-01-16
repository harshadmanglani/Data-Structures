
//============================================================================
// Name        : Expression.cpp
// Author      : Harshad
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"
#include "List.h"
#include "List.cpp"
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Expression
{
	string equation;
	string prefix;
	string postfix;
	public:
	Expression();			//CONSTRUCTOR
	void input();
	bool isoperand(char);
	bool isoperator(char);
	bool parancheck();
	bool valid();
	int check(char);
	void topostfix();
	void toprefix();
	void prefix_eval();
	void postfix_eval();
	int assoc(char);
	int eval(int, int, char);
};

//sudo chown -R $USER: $HOME
Expression::Expression()
{
	prefix[0] = postfix[0] = equation[0] = '\0';
}
int Expression::check(char a)		//returns the precedence of math operators
{
	switch(a){
		case '+':
		case '-': return 1;
		
		case '*':
		case '/': return 2;
		
		case '^': return 3;
		
		case '(': return 4;
	}
	return -1;
}

bool Expression::valid()		//validate number of operators and operands
{
	int a = 0, b = 0;

	for(unsigned int i = 0; i < equation.size(); i++)
	{
		char c = equation[i];
		if(this->isoperand(c) && c!='(' && c!=')')
			a++;
		else if(this->isoperator(c) && c!='(' && c!=')')
			b++;
	}
	b++;
	if(a == b)
		return true;
	else
		return false;

	return false;
}
void Expression::input() //input func
{
	cout<<"Please enter a valid expression: ";
	cin>>equation;
	cout<<endl;
}

bool Expression::isoperand(char temp)		//returns true if the char is an operand
{
	if((temp>='A' && temp<='Z') || (temp>='a' && temp<='z'))
		return true;
	else
		return false;
}

bool Expression::isoperator(char temp)	//returns true if the char is an operator
{
	if(temp == '*' || temp == '/' || temp == '+' || temp == '-' || temp == '^' || temp == '(' || temp == ')')
		return true;
	else
		return false;
}

bool Expression::parancheck()			//checks the number of parantheses
{
	Stack<char> check;
	for(unsigned int i = 0; i < equation.size(); i++)
		{
			if(equation[i]=='(')
				check.push('(');
			else if(equation[i]==')')
				check.pop();
		}
	if(check.isempty() && this->valid())	//this statement checks validity
		return true;
	else{
		cout<<"Equation is invalid. Please choose to give input again.\n";
		return false;
		}
	}

int Expression::assoc(char c)		//returns l-r or r-l assosciativity
{
	switch(c){
		case '+':
		case '-':
		case '*':
		case '(':
		case '/': return 2;
		
		case '^':return 1;
	}
	return -1;
}
void Expression::topostfix()		//converts infix to postfix
{
	Stack<char> op;
	string output;
	cout<<"=====================================\n";
	cout<<"Charact | Stack   | Postfix\n";
	cout<<"=====================================\n";
	for(unsigned int i = 0; i < equation.size(); i++)
	{
		char c = equation[i];
		cout<<"  "<<c<<"\t| "; op.display();
		cout<<"\t  | "<<output<<endl;
		if(this->isoperator(c))			//this statement checks if char is operator
		{
			if(op.isempty() || op.top()=='(')
				op.push(c);
			else if(c ==')')
			{
				while(op.top()!='(')
				{
					output += op.top();
					op.pop();
				}
				op.pop();
			}
			else				//this statement checks if we have an operator, stack is not empty
			{
				int a = this->check(c);
				int b = this->check(op.top());
				if(a>b)			//this statement checks priority
				op.push(c);
				else if(a==b)
				{
					int t = this->assoc(c);
					if(t==1)
					{
						op.push(c);
					}
					else
					{
						output+=op.top();
						op.pop();
						op.push(c);
					}
				}
				else if(a<b)
				{
					output+=op.top();
					op.pop();
					if(!op.isempty())
					{
						b = this->check(op.top());
						while(a<b && !op.isempty())
						{
							output+=op.top();
							op.pop();
							b = this->check(op.top());
						}
					}
					else{
					op.push(c);
					}
				}
			}
		}
		else if(this->isoperand(c))		//this statement checks if char is operand
			output+=c;
	}
	while(!op.isempty())		//this statement checks if stack is empty, if not then while loop is entered
	{
		output+=op.top();
		op.pop();
		}
	cout<<"=====================================\n";
	cout<<"Postfix expression is: "<<output<<endl;
	postfix = output;
}

void Expression::toprefix()		//converts infix to prefix
{
	reverse(equation.begin(), equation.end());

	for(int i = 0; i< equation.size(); i++)
	{
		if (equation[i] == '(')//this statement checks if char is opening brace, then swaps it
		{
		    equation[i] = ')';
		    i++;
		}
		else if (equation[i] == ')')
		{
		    equation[i] = '(';
		    i++;
		}
	}
	Stack<char> op;
	string output;
	cout<<"=====================================\n";
	cout<<"Charact | Stack   | Prefix in reverse\n";
	cout<<"=====================================\n";
	for(int i = 0; i < equation.size(); i++)
	{
		char c = equation[i];
		cout<<"  "<<c<<"\t| "; op.display();
		cout<<"\t  | "<<output<<endl;
		if(this->isoperator(c))
		{
			if(op.isempty() || op.top()=='(')
				op.push(c);
			else if(c ==')')
			{
				while(op.top()!='(')
				{
					output += op.top();
					op.pop();
				}
				op.pop();
			}
			else
			{
				int a = this->check(c);
				int b = this->check(op.top());
				if(a>b)
				op.push(c);
				else if(a==b)
				{
					int t = this->assoc(c);
					if(t==1)
					{
						op.push(c);
					}
					else
					{
						output+=op.top();
						op.pop();
						op.push(c);
					}
				}
				else if(a<b)
				{
					output+=op.top();
					op.pop();
					b = this->check(op.top());
					while(a<b)
					{
						output+=op.top();
						op.pop();
						b = this->check(op.top());
					}
				}
			}
		}
		else if(this->isoperand(c))
			output+=c;
	}
	while(!op.isempty())
	{
		output+=op.top();
		op.pop();
		}
	reverse(output.begin(), output.end());
	cout<<"=====================================\n";
	cout<<"Prefix expression is: "<<output<<endl;
	prefix = output;
}
int power(int b, int d)		//power function: a^b
{
	int res=b;
	for(int i=1; i<d; i++)
	{
		res = res*b;
	}
	return res;
}
int Expression::eval(int b, int d, char c)		//helper function
{
	switch(c){
	case '+': return b+d;
	case '-': return b-d;
	case '*': return b*d;
	case '/': return b/d;
	case '^': return power(b, d);
	}
	return -1;
}

void Expression::postfix_eval()			//postfix evaluation
{

	Stack<int> op;
	for(int i = 0; i < postfix.size(); i++)
	{
		char c = postfix[i];
		if(this->isoperand(c))		//this statement checks if char is operand
		{
			int a;
			cout<<"Enter the value for "<<c<<": ";
			cin>>a;
			cout<<endl;
			op.push(a);
		}
		else if(this->isoperator(c))	//this statement checks if char is operator
		{
			int b = op.top(); op.pop();
			int d = op.top(); op.pop();
			op.push(this->eval(d, b, c));
		}
	}
	cout<<"Answer is: "<<op.top()<<endl;
	op.pop();

}

void Expression::prefix_eval()			//prefix evaluation
{
	Stack<int> op;
	for(int i = prefix.size()-1; i >= 0; i--)
	{
		char c = prefix[i];
		if(this->isoperand(c))		//this statement checks if char is operand
		{
			cout<<"Enter the value for "<<c<<": ";
			int a;
			cin>>a;
			cout<<endl;
			op.push(a);
		}

		else if(this->isoperator(c))	//this statement checks if char is operator
		{
			int b = op.top(); op.pop();
			int d = op.top(); op.pop();
			op.push(eval(b, d, c));
		}
	}
	cout<<"Answer is: "<<op.top()<<endl;
	op.pop();
}

int main() {

	Expression obj;
	int ch = 0;
	while(ch!=6)
	{
		cout<<"-------------------------------------\n";
		cout<<"MATHEMATICAL EXPRESSIONS - MENU     |\n";
		cout<<"-------------------------------------\n";
		cout<<"1. Input                            |\n";
		cout<<"2. To postfix                       |\n";
		cout<<"3. To prefix                        |\n";
		cout<<"4. Prefix evaluation                |\n";
		cout<<"5. Postfix evaluation               |\n";
		cout<<"6. Exit                             |\n";
		cout<<"-----------------------------------\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			obj.input();
			if(obj.parancheck())
			break;
			break;

		case 2:
			obj.topostfix();
			break;

		case 3:
			obj.toprefix();
			break;

		case 4:
			obj.prefix_eval();
			break;

		case 5:
			obj.postfix_eval();
			break;

		case 6:
			break;

		default:
			cout<<"Please enter a valid option.\n";
			break;

		}
	}
	return 0;
}
