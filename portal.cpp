#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int option;
string username,pass;

void choose();
void Register();
void Login();

void choose()
{  cout<<"Please choose an option\n1. Registration\n2. Login"<<endl;
	cin>>option;
	switch(option)
	{
		case 1: Register(); break;
		case 2: Login(); break;
		default: cout<<"Invalid Input !! Please Try again...\n"; choose();
	}
}
void Register()
{	
	cout<<"Enter Username: "; cin>>username;
	ifstream file;
	file.open(username);
	if(file) {file.close(); cout<<"Username taken !!! Try another one\n"; Register();}
	else{
		cout<<"Enter Password: "; cin>>pass;
		ofstream fout;
		fout.open(username);
		if (!fout) 
		{
			cout << "System Error :( \n";
		}
		else 
		{
			fout<<pass;
			fout.close(); 
		}
		cout<<"User created Successfully\n";
	}
}
void Login()
{	
	int error=0;
	cout<<"Enter Username: "; cin>>username;
	cout<<"Enter Password: "; cin>>pass;
	ifstream fin;
	fin.open(username);
	string checker;
	if(!fin) error=1;
	else
	{
		fin >> checker;
		if(pass!=checker) error=1;
	}
	fin.close();
	if(!error) cout<<"Successfully Logged In\n";
	else cout<<"Incorrect Username or Password\n";
	
}
int main()
{
	
	cout<<"Welcome to the Portal !!  ";
	choose();
	
}
