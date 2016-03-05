
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string usn;
    string  name;
    string branch;
    string sem;
public:
    void read();
    void pack(string filename);
    void search(string,string);
    void unpack(string);
    void unpack(ifstream &);
    };
int main()
{
    int ch;
    //fstream f;

    Student s;
    string filename,key;
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
            cin >> filename;
            s.pack(filename);
            break;
        case 2:
            cout<<"Enter the USN to be searched\n";
            cin>>key;
            cout<<"enter filename ";
                        cin >> filename;
            s.search(key,filename);
            break;
        case 3:
            //s.modify;
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
void Student::pack(string filename){
    string buffer;
    ofstream myf(filename.c_str(),ios::app);
    buffer= usn+"|"+name+"|"+sem+"|"+branch;
    buffer.resize(100,'$');
    myf<<buffer<<endl;
    myf.close();

}void Student::unpack(ifstream &myf)
{
	string temp;
    getline(myf,usn,'|');
    getline(myf,name,'|');
    getline(myf,branch,'|');
    getline(myf,sem,'$');
    getline(myf,temp);

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
void Student::search(string key,string filename)
{
    Student s[10];
    int i=0;

    ifstream myf(filename.c_str());
    //cout<<myf;
    while(!myf.eof())
    {
    cout<<"In search\n";
    s[i].unpack(myf);
    if(key==s[i].usn)
    {
                cout<<"record found\n";
                cout<<s[i].usn<<"\t"<<s[i].name;
                break;
    }
    i++;
    }



    myf.close();
}
