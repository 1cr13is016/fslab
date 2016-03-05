
#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;

class Student {
    string usn;
    string  name;
    string branch;
    string sem;
public:
    void read();
    void pack(string filename);
    int search(string,string);
    void unpack(string);
    int modify(string key,string);
    };
int main()
{
    int ch;
    //fstream f;

    Student s;
    string key;
   string filename;
    while(1)
    {
    cout<<"1.insert 2.search 3.delete 4.modify\n";
    cout<<"enter your choice";
    cin>>ch;

         switch(ch)
        {
        case 1:
            s.read();
            cout<<"enter filename ";
            cin >>filename;
            s.pack(filename.c_str());
            break;
        case 2:
            cout<<"Enter the USN to be searched\n";
            cin>>key;
            cout<<"enter filename ";
                        cin >> filename;
            s.search(key,filename);
            break;
        case 3:
            s.modify(key,filename);
            break;
        case 4:
            //s.unpack();
            break;

            }
        }
}
void Student::read(){
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter usn"<<endl;
    cin>>usn;
    cout<<"enter branch"<<endl;
    cin>>branch;
    cout<<"enter sem"<<endl;
    cin>>sem;
}
void Student::pack(string filename)
{
    string buffer;
    fstream fp;
    fp.open(filename.c_str(),ios::out);
    buffer= usn+"|"+name+"|"+sem+"|"+branch;
    buffer.resize(100,'$');
    fp<<buffer<<endl;
    fp.close();

}
void Student::unpack(string filename)
{
	string temp;
    ifstream myf(filename.c_str());
    getline(myf,usn,'|');
    getline(myf,name,'|');
    getline(myf,branch,'|');
    getline(myf,sem,'$');
    getline(myf,temp);
    myf.close();

}
int Student::search(string key,string fname)
{
fstream fp;
	string buffer;
	int flag=0, pos=0;

	fp.open(fname.c_str(),ios::in);
	while (!fp.eof())
	{
		buffer.erase();
		getline(fp,buffer);
		unpack(fname.c_str());
		if (key==usn) {
			cout<<"\nFound the key. The record is  "<<buffer;
		pos=fp.tellp();
		cout<<"Printing the position\n"<<pos;
		flag=1;
		return pos;
		}
	}
	fp.close();
	if (!flag) {
		cout<<"\n Not Found \n\n"; return pos;
	}
return 0;
}
int Student::modify(string key,string filename)
{
	string buffer;
	fstream file;
	int choice,pos;
	cout<<"Enter the usn to be searched\n";
	cin>>key;
	cout<<"enter the filename";
			cin>>filename;
	pos=search(key,filename);
	pos=pos-100;
	if(pos){
	cout<<"\n What to modify?";
	cin>>choice;

	switch(choice)
	{
		case 1: cout<<"\nUSN:"; cin>>usn; break;
		case 2:	cout<<"\nName:";cin>>name;break;
		case 3:	cout<<"\nBranch:";cin>>branch;break;
		case 4:	cout<<"\nSemster:";cin>>sem;break;
		default: cout <<"Wrong Choice";
	}


	file.open(filename.c_str(),ios::out);
	pos-=101;//skip $\n
	file.seekp(pos,ios::beg);
	pack(filename);
	file.close();
	}
	else
		exit(0);
	return 0;
}
