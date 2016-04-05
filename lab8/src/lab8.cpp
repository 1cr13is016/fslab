/#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;
string merge(vector<string>fn,int left,int right)
{
 if(left==right)
  return fn[left];
 else if((right-left)==1)
   {
    string s1,s2;
    ifstream if1(fn[left].c_str());
    ifstream if2(fn[left].c_str());
    ofstream of((fn[left]+"a").c_str());
    while(!(if1.eof())&&!(if2.eof()))
    {
     getline(if1,s1);
     getline(if2,s2);
     if(s1==s2)
     {
      if(s1!="")
      {
      of<<s1<<endl;
      }
      getline(if1,s1);
      getline(if2,s2);
     }
     else if(s1<s2)
      {
       if(s1!="")
      {
       of<<s1<<endl;
      }
       getline(if1,s1);
      }
     else
      {
       if(s2!="")
      {
       of<<s2<<endl;
      }
       getline(if2,s2);
      }
    while(!if1.eof())
     {
      if(s1!="")
      {
       of<<s1<<endl;
     }
     getline(if1,s1);
    }
     while(!if2.eof())
     {
      if(s2!="")
      {
      of<<s2<<endl;
     }
     getline(if2,s2);
   }
    if1.close();
    if2.close();
    of.close();
    return fn[left]+"a";
   }
   }
   else
    {
     int mid=(left+right)/2;
      string f1,f2,f3;
      f1=merge(fn,left,mid);
      f2=merge(fn,mid+1,right);
      vector<string>str;
      str.push_back(f1);
      str.push_back(f2);
      f3=merge(str,0,1);
      return f3;
   }
}
int main()
{
 vector<string>fn;
 fn.push_back("1.txt");
 fn.push_back("2.txt");
 fn.push_back("3.txt");
 fn.push_back("4.txt");
 fn.push_back("5.txt");
 fn.push_back("6.txt");
 fn.push_back("7.txt");
 fn.push_back("8.txt");
 cout<<merge(fn,0,7);
}
     
