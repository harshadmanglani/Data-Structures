/*
A music player simulation implemented using a linked list
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct song {
	string name;
	string singer;
	float duration;
};

class MusicPlayer {

	song s;
	list <song> playlist;
	list <song> :: iterator it;

public:

	void initiate(){it=playlist.begin();}
	void add(string name, string singer, float duration, int position);
	void del(int position);
	void next();
	void prev();
	void first();
	void last();
	void aplhasort();
	void durasort();
	void rev();	
	void displaylist();
	void displaycurrent();
	void jump(string name);
};


void MusicPlayer :: add (string name, string singer, float duration, int position) {
	s.name=name;
	s.singer=singer;
	s.duration=duration;
	list <song> :: iterator pos;
	pos=playlist.begin();

	int i=0;
	while(i<position-1 && position<=playlist.size())       //inserting the song in a specific position
	{
		i++;
		pos++;
	}
	if(position>playlist.size())
	pos=playlist.end();
	playlist.insert(pos, s);

}

void MusicPlayer :: del(int position) {
	
	list <song> :: iterator pos;
	pos=playlist.begin();

	int i=0;
	while(i<position-1 && position<=playlist.size())       //deleting the song from a specific position
	{
		i++;
		pos++;
	}
	if(position>playlist.size())
	pos=playlist.end();
	
	playlist.erase(pos);
}

void MusicPlayer :: next() {
	
	if(it!=playlist.end() && playlist.begin()!=playlist.end()  && playlist.size()>1)
	it++;
	else
	cout<<"Can't perform this operation, try something else."<<endl;
}

void MusicPlayer :: prev() {
	if(it!=playlist.begin() && playlist.begin()!=playlist.end()  && playlist.size()>1)
	it--;
	else
	cout<<"Can't perform this operation, try something else."<<endl;
}

void MusicPlayer :: first() {
	it=playlist.begin();
}

void MusicPlayer :: last() {
	it=playlist.end();
}

void MusicPlayer :: rev() {
	playlist.reverse();
}

bool title(song first, song second) {
	return first.name<second.name;
}

void MusicPlayer :: aplhasort() {
	playlist.sort(title);
}

bool dura(song first, song second) {
	return first.duration<second.duration;
}

void MusicPlayer :: durasort() {
	playlist.sort(dura);
}

void MusicPlayer :: displaylist() {
	list <song> :: iterator d;
	d=playlist.begin();
	cout<<"NAME\tSINGER\tDUR"<<endl;
	for(d;d!=playlist.end();d++)
	{
		cout<<d->name<<"\t"<<d->singer<<"\t";
		cout<<d->duration<<endl;
	}	
}

void MusicPlayer :: displaycurrent() {
	cout<<it->name<<" "<<it->singer<<" ";
	cout<<it->duration<<endl;
}

void MusicPlayer :: jump (string name) {
	list <song> :: iterator pos;
	pos=playlist.begin();
	for(pos;pos!=playlist.end();pos++)
	{
		if(pos->name==name)
		{
			it=pos;
			break;
		}
	}
}

int main() {
	MusicPlayer one;
	cout<<"Your music player is now active."<<endl;
	int i;
	cout<<"Select the corresponding number to choose your desired option.\n 1. Add a song to the list\n 2. Delete a song from the list\n";
	cout<<" 3. Reverse the list\n 4. Toggle next\n 5. Toggle previous\n 6. Go to the first song\n 7. Go to the last song\n 8. Jump to desired song\n 9. Display the entire playlist\n 10. Display the current song\n";
	cout<<" 11. Sort the list alphabetically\n 12. Sort the list by duration\n 13. Quit\n";
	
	while(i!=13)
	{
		cout<<endl<<"Enter your choice: ";
		cin>>i;
		cout<<endl;
		switch(i) {
			case 1: 
		{
		    	string nam,singe; float duratio; int positio;
				cout<<"Enter the name of the song, the singer and time duration."<<endl;
				cin>>nam>>singe>>duratio;
				cout<<"If you wish to specify the position please type 'Y' and then enter the position, else type 'N'."<<endl;
				char c;
				cin>>c;
				if(c=='Y')
				cin>>positio;
				else
				positio=1;
				one.add(nam, singe, duratio, positio);
				one.initiate();
				break;
		}
			case 2:
		{		
				int positio;
        		cout<<"Enter the position from which you wish to delete the song."<<endl;
				cin>>positio;
				one.del(positio);
				break;
		}
			case 3:
		{	
				cout<<"Reversing list..."<<endl;
				one.rev();
				break;
		}
			case 4:
		{
				cout<<"Toggling next..."<<endl;
				one.next();
				break;
		}
			case 5:
		{
				cout<<"Toggling previous..."<<endl;
				one.prev();
				break;
		}
			case 6:
		{
				cout<<"Jumping to the first song..."<<endl;
				one.first();
				break;
		}
			case 7:
		{
				cout<<"Jumping to the last song..."<<endl;
				one.last();
				break;
		}
			case 8:
		{
				string nam;
				cout<<"Enter the name of the song in the playlist you want to jump to:"<<endl;
				cin>>nam;
				one.jump(nam);
				break;
		}
			case 9:
		{
				cout<<"Displaying the entire playlist..."<<endl;
				one.displaylist();
				break;
		}
			case 10:
		{
				cout<<"Displaying the current song..."<<endl;
				one.displaycurrent();
				break;
		}
		 	case 11:
		{
		 		cout<<"Sorting the playlist alphabetically..."<<endl;
		 		one.aplhasort();
		 		break;
		}
		 	case 12:
		{
		 		cout<<"Sorting the playlist by duration..."<<endl;
		 		one.durasort();
		 		break;
		}
		 	case 13:
		{
		 		break;
		}
		 	default:
		 		cout<<"Invalid choice"<<endl;
		 		i=0;
		 		break;
		 		
		}
	}
	return 0;
}






