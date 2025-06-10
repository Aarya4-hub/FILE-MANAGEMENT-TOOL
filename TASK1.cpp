#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
using namespace std;
fstream file1,file2;
class Student
{
    protected:
    int id,marks;
    string name;
    public:
    void menu();
};
class Studinfo: public Student{
    public:
void getinfo();
void putinfo();
void writedata();
void readdata();
void appenddata();

};
Studinfo stud;
void Studinfo::getinfo()
{
    cout<<"\n\t\tEnter Student ID";
    cin>>id;
    cout<<"\n\t\tEnter Student Name";
    cin>>name;
    cout<<"\n\t\tEnter Student Marks";
    cin>>marks;
}
void Studinfo::putinfo()
{
  cout<<setw(28)<<id;
  cout<<setw(28)<<name;
  cout<<setw(28)<<marks<<endl;
}
void Studinfo::writedata()
{
    
    file1.open("stud.txt",ios::out|ios::binary);
        stud.getinfo();
        file1.write((char *)&stud,sizeof(stud));
        file1.close();
        menu();
}
void Studinfo::readdata()
{
    file1.open("stud.txt",ios::in | ios::binary);
    if(!file1)
    {
        cout<<"\n\tFile not exist";
        exit(0);

    }
    else{
        file1.read((char *)&stud,sizeof(stud));
        while(!file1.eof())
    {
           stud.putinfo();
           file1.read((char *)&stud,sizeof(stud));

    }
    }
    file1.close();
    menu();
}
void Studinfo::appenddata()
{

    char ch='y';
    file1.open("gropro.txt",ios::app | ios::binary);
    while(ch=='y' || ch=='Y')
    {
        stud.getinfo();
        file1.write((char*)&stud,sizeof(stud));
        cout<<"\n\t\t\t\t\t To add another student information press...(Y/N)";
        cin>>ch;
    }
    file1.close();
    menu();

}

void Student::menu()
{
    Studinfo s3;
    int choice;
    cout<<"\n\t\t---- Application to read,write or append data into text files----";
    cout<<"\n\t\t----File Operation Menu----";
    cout<<"\n\t\t1.Write data into the file";
    cout<<"\n\t\t2.Append data to the file";
    cout<<"\n\t\t3.Read data  from the file";
    cout<<"\n\t\tEnter Your choice";
    cin>>choice;
    switch(choice)
    {
        system("cls");
        case 1:s3.writedata();
               break;
        case 2:s3.appenddata();
               break;
        case 3:s3.readdata();
               break;
        default:cout<<"\n Enter only 1,2,3 and for exit enter 4";                     
    }
}
int main()
{
    Studinfo s1;
    s1.menu();
    return 0;
}
