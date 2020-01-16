#include<stack>
#include<iostream>
using namespace std;

class textEditor {

	stack<char> lstack;
	stack<char> rstack;

	public:
		void insertWord(string word);				//identical to given program, modified paramter string
		void insertChar(char character);
		bool deleteChar();
		bool backspace();
		void movecursor(int position);
		void moveleft(int position);
		void moveright(int position);
		void far(char find, char replace);
		void examinetop();
		void display();
};

void textEditor::examinetop() {

	if(lstack.empty())
		cout<<"lstack:empty\t";
	else
		cout<<"lstack:"<<lstack.top()<<" "<<lstack.size()<<"\t\t";

	if(rstack.empty())
		cout<<"rstack:empty/t";
	else
		cout<<"lstack:"<<rstack.top()<<" "<<rstack.size()<<endl;
}

void textEditor::insertWord(string word) {
	int i=0;
	while(word[i]!='\0')
	{
		insertChar(word[i]);
		i++;
	}
}

void textEditor::insertChar(char character) {
	lstack.push(character);
}

bool textEditor::deleteChar() {
	if(!rstack.empty()) {
		rstack.pop();
		return true;
	}
	else
	{
	cout<<"Operation not possible"<<endl;
	return false;
	}
}

bool textEditor::backspace() {
	if(!lstack.empty()) {
		lstack.pop();
		return true;
	}
	else
	{
	cout<<"Operation not possible"<<endl;
	return false;
	}
}

void textEditor::moveleft(int position) {

		while(lstack.size()!=position)
		{
			rstack.push(lstack.top());
			lstack.pop();
		}
}

void textEditor::moveright(int position) {

	int rightSize, i=1;
	rightSize = rstack.size();

	if (position > rightSize)
	cout << "Cannot move the cursor, right, to the specified position";

	else
	while(i<=position) {
		lstack.push(rstack.top());
		rstack.pop();
		i++;
	}

	}


void textEditor::movecursor(int position) {
	int lsize=lstack.size(),count,rsize=rstack.size();

	count=position-lsize;

	if(position<lsize)
		moveleft(position);

	else
		moveright(count);
}

void textEditor::far(char find, char replace) {
	int count=1, cursorposition=lstack.size();
	movecursor(0);

	while(!rstack.empty()) {
		if(rstack.top()==find) {
			deleteChar();
			insertChar(replace);
		}
		else
		movecursor(count);

		count++;
	}
	movecursor(cursorposition);
}

void textEditor::display() {
	stack<char> left;
	stack<char> right;
	int n=lstack.size();
	int m=rstack.size();

	for(int i=0;i<n;i++)		//copies all elements to a new stack 'left' in reverse manner
	{
	left.push(lstack.top());
	lstack.pop();
	}


	for(int i=0;i<n;i++)		//copies them back to the original stack, printing top everytime
	{
		lstack.push(left.top());
		cout<<lstack.top();
		left.pop();
		}

	cout<<"|";					//prints cursor

	for(int i=0;i<m;i++)		//same for the right stack
	{

	right.push(rstack.top());
	rstack.pop();
	}

	for(int i=0;i<m;i++)		//same for the rstack
	{
		rstack.push(right.top());
		cout<<rstack.top();
		right.pop();
	}
}
int main()
{
	textEditor a;
	cout<<"1.Enter a new word"<<endl;
	cout<<"2.Enter a new character"<<endl;
	cout<<"3.Movecursor"<<endl;
	cout<<"4.Backspace"<<endl;
	cout<<"5.Find and replace"<<endl;
	cout<<"6.Display"<<endl;
	cout<<"7.Exit"<<endl;

	int i;

	do {
		cout<<"\nEnter your choice: ";
		cin>>i;
		cout<<endl;

		switch(i) {

			case 1: {
				string word;
				cout<<"Enter your word: ";
				cin>>word;
				a.insertWord(word);
				cout<<endl;
				break;
			}

			case 2: {
				char character;
				cout<<"Enter your character: ";
				cin>>character;
				a.insertChar(character);
				cout<<endl;
				break;
			}

			case 3:{
				cout<<"Enter cursor position: ";
				int g;
				cin>>g;
				a.movecursor(g);
				cout<<endl;
				break;
			}

			case 4:{
				a.backspace();
				break;
			}

			case 5: {
				char find,replace;
				cout<<"Enter the string to find: ";
				cin>>find;
				cout<<endl<<"Enter the string to replace all matches with: ";
				cin>>replace;
				a.far(find, replace);
				cout<<endl;
				break;
			}

			case 6: {
				a.display();
				break;
			}

			case 7: {
				break;
			}

			default:
				cout<<"Invalid option"<<endl;
		}

	}while(i!=7);


	return 0;
}
