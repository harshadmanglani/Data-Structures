#include<stack>
#include<iostream>
#include<string>
using namespace std;

bool isOperand(char a) {
	return ((64<a && a<91) || (a>96 && a<123));
}
bool checkParantheses(string s) {
	int open=0,close=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		open++;
		if(s[i]==')')
		close++;
	}
	if(open==close)
	return true;
	else 
	return false;	
}
bool isOperator(char a){
	return (a=='^' || a=='*' || a=='+' || a=='-' || a=='(' || a==')'|| a=='/');
}

bool isValid(string s) {
	bool a,b;
	for(int i=0;i<s.size();i++)
	{
	a=isOperand(s[i]) && isOperator(s[i]);
	if(a==false)
		break;
	
	}
b=checkParantheses(s);
return (a && b);
}

int priorityNumber(char a) {
	if(a=='^')
	return 0;
	
	if(a=='*' || a=='/')
	return 1;
	
	if(a=='+' || a=='-')
	return 2;
	
	if(a=='(')
	return 3;
}

bool checkPriority(char current, char stacktop)
{
	if(priorityNumber(current)<priorityNumber(stacktop))
	return true;
	else 
	return false;
}

string intopos(string in) {
	int i=0,j=0;
	char pos[50]="";
	stack<char> os;
	while(in[i]!='\0') {
		char a=in[i];
		
		if(isOperand(a))
		{
			pos[j]=a;
			j++;
		}
		
		else
		{
			if(os.empty() && a!=')')
			{
				os.push(a);
				i++;
				continue;
			}
			
			else if(a=='(')
			{
				os.push(a);
			}
			
			else {
				if(checkPriority(a,os.top()))
				os.push(a);
				
				else
			{
					while(!os.empty())
				{	
					if(os.top()=='(')
					{
						os.pop();
						break;
					}
					pos[j]=os.top();
					j++;
					os.pop();
				}
				if(a!=')')
				os.push(a);
			}
		}
	
		}
	i++;		
	}
    while(!os.empty()) {
        pos[j]=os.top();
        os.pop();
        j++;
    }
return pos;
}

int main() {
	string s;
	s="a*b^c*(d+e)/t";
	string d=intopos(s);
	cout<<d;
	return 0;
}

