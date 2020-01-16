//============================================================================
// Name        : Priority.cpp
// Author      : Harshad
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "Priority_Q.cpp"
#include "Priority_Q.h"
using namespace std;

struct p_data				//structure for patient data
{
	int priority;
	string name;
	string phone;
	int age;
	string bgrp;
	char gender;
};
string checkp(int p)			//helper function
{
	switch(p)
	{
	case 1: return "Emergency";
	case 2: return "Follow up";
	case 3: return "General";
	}
	return "-1";
}
ostream& operator<<(ostream& out, p_data obj)		//operator overloading
{
	out<<"| "<<setw(8)<<obj.name<<" | "<<setw(11)<<checkp(obj.priority);
	out<<" | "<<setw(6)<<obj.bgrp<<" | "<<setw(3)<<obj.age<<" | ";
	return out;
}
class Patient			//class for priority queue patient
{
	Priority_Q<p_data> pq;
public:

	void add(p_data);
	void del();
	void display();
};

bool cphone(string phone)
{
	if(phone.size() == 10)
	{
		for(int i=0; i<10; i++)
		{
			if(!isdigit(char(phone[i])))
				return false;
		}
		return true;
	}
	return false;
}

bool cbgp(string bgp)
{
	if(bgp == "A+" || bgp == "A-" || bgp == "AB+" || bgp == "AB-" || bgp == "B+" || bgp == "B-" || bgp == "O+" || bgp == "O-")
	{
		return true;
	}
	else
		return false;
}

bool cname(string name)
{
	int i = 0;
	while(name[i]!='\0')
	{
		if(!isalpha(char(name[i])))
			return false;
		i++;
	}
	return true;
}
void Patient::add(p_data obj)		//add patient to queue according to priority
{

	cout<<"Enter patient details: \n";
	cout<<"Name: ";
	cin>>obj.name;
	while(1)
	{
		if(cname(obj.name))
			break;
		cout<<"Invalid name, please try again.\n";
		cin>>obj.name;
	}
	cout<<"\nPhone: ";
	//obj.phone = "12345";
	cin>>obj.phone;
	while(1)
	{
		if(cphone(obj.phone))
			break;
		cout<<"Invalid phone number, please try again.\n";
		cin>>obj.phone;
	}
	cout<<"\nBlood group: ";
	//obj.bgrp = "A-";
	cin>>obj.bgrp;
	while(1)
	{
		if(cbgp(obj.bgrp))
			break;
		cout<<"Invalid blood group, please try again.\n";
		cin>>obj.bgrp;
	}
	//obj.age = 40;
	cout<<"\nAge: ";
	cin>>obj.age;
	cout<<"\nGender (M/F): ";
	//obj.gender =  'F' ;
	cin>>obj.gender;
	cout<<"\nSelect category: \n";
	cout<<"\t1. Emergency\n\t2. Follow up appointment\n\t3. General\n";
	cin>>obj.priority;

	pq.enqueue(obj, obj.priority);
}

void Patient::del()				//delete a queue
{
	pq.dequeue();
}

void Patient::display()			//displaying the patient queue
{
	cout<<"Patient queue is: \n";
	cout<<"\n=============================================\n";
	cout<<"| "<<setw(8)<<"    Name | "<<"       Case | "<<setw(8)<<"BloodG | "<<setw(5)<<"Age |\n";
	cout<<"===============================================";
	pq.disp();
	cout<<"==============================================\n";
}
int main() {
	int c = 0;
	Patient hosp;
	p_data obj;
	while(c!=4)
	{
		cout<<"1. Enter new patient details\n2. Dequeue a patient\n3. Display current queue\n4. Exit\nEnter your choice: ";
		cin>>c;
		switch(c)
		{

		case 1:
			hosp.add(obj);
			break;

		case 2:
			hosp.del();
			break;

		case 3:
			hosp.display();
			break;

		case 4:
			break;

		default: break;

		}
	}
return 0;
}
