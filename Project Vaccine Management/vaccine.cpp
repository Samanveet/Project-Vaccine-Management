#include<iostream>
#include<stdio.h>//standard input output
#include<fstream>
#include<conio.h>//console input output
#include<string.h>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info
int num_of_vaccine = 200 ;
using namespace std;
int password();//b
void menu();//c
void show();//a
class Vaccine
{
int age;
int temperature;
int bloodPressure;
char gender;
char name[100];
char citizenship[100];
char profession[100];
char address[100];
char mobileNumber[100];
char vaccine[100];
public:
void setData();//1
void addNew();//2
void showData();//3
void showList();//4
// void searchData();//6
 void viewVaccine();//5
// void search_by_citizenship();//6.1
//      void search_by_age();//6.2
//      void search_by_profession();//6.3
//      void search_by_gender();//6.4
//      void search_by_vaccine();//6.5
     void view_all();//6.6
};
//----------------------------------------
void Vaccine::setData()//1
{
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
   
    cout<<"\n\t\t\t***************\n";
    cout<<"\t\t\t\t ENTER THE DETAILS ";
    cout<<"\n\t\t\t***************\n\n";
    fflush(stdin);
        cout<<"\n\t\t Enter your name :-  ";
        gets(name);
         cout<<"\n\t\t Enter your Aadhar no no :-  ";
         gets(citizenship);
        cout<<"\n\t\t Enter your gender (M|F) :-  ";
        cin>>gender;
        cout<<"\n\t\t Enter your age:- ";
        cin>>age;
        fflush(stdin);
        cout<<"\n\t\t Enter your profession :-  ";
        gets(profession);
        cout<<"\n\t\t Enter your B.P. :-  ";
        cin>>bloodPressure;
        cout<<"\n\t\t Enter your Body temperature:-  ";
        cin>>temperature;
        fflush(stdin);
        cout<<"\n\t\t Enter your permanent address :-  ";
        gets(address);
        cout<<"\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
        cout<<"\n\t\t Enter the vaccine injected :- ";
        gets(vaccine);
}
//------------------------------------------------------
void Vaccine::addNew()//2
{
    fstream outin;
    outin.open("vaccinetrial.txt",ios::app|ios::out);
    setData();
    outin.write((char*)this,sizeof(Vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();
    outin.close();
    num_of_vaccine--  ;

}
void Vaccine::showList()//4
{
    cout<<"\n";
    cout<<setw(15)<<setiosflags(ios::left)<<name;
    cout<<setw(15)<<citizenship;
    cout<<setw(15)<<age;
    cout<<setw(15)<<profession;
    cout<<setw(15)<<bloodPressure;
    cout<<setw(15)<<temperature;
    cout<<setw(15)<<gender;
    cout<<setw(15)<<mobileNumber;
    cout<<setw(15)<<address;
    cout<<setw(15)<<vaccine<<endl;
    
    
}
void show()//a
{
cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(15)<<"Aadhar No.";
    cout<<setw(15)<<"Age";
    cout<<setw(15)<<"Profession";
    cout<<setw(15)<<"B.P.";
    cout<<setw(15)<<"Temperature";
    cout<<setw(15)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<setw(15)<<"Address";
    cout<<setw(15)<<"Vaccine"<<endl;
}
void Vaccine ::viewVaccine()//5
{
    ifstream ind;
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(Vaccine)))
    {
        i++;
        cout << i << endl ;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
       cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t Powered By:- TEAM AC/DC "<<endl<<endl;
    cout<<"\n\t\t\t***************\n";
    cout<<"\t\t\t\tVACCINE STATISTICS";
    cout<<"\n\t\t\t***************\n\n";
    cout<<"\t\t 1. Add more        \t\t\t2.View available \n\t\t\t\t\t 3. Back"<<endl;
    cin>>ch;
    int f_var=0;
    fstream file("count.txt",ios::in);
    file>>f_var;
    file.close();
    switch(ch)
    {
    case 1:
        int m;
        cout<<"\t Enter number of vaccines you want to add :"<<endl;
        cin>>m;
        f_var=f_var+m;
        file.open("count.txt",ios::out);
        file.seekg(0);
        file<<f_var;
        cout<<"\t\t Now total number of vaccines are : "<<f_var+num_of_vaccine;
        file.close();
        break;
    case 2:
     file.open("count.txt",ios::in);
        cout<<"\n\nAvailable number of vaccines are : "<<num_of_vaccine;
        file.close();
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout<<"\nEnter valid option "<<endl;
        menu();
    }
    file.close();
    getch();
}
void Vaccine::view_all(){
    
fstream outfile;
outfile.open("vaccinetrial.txt",ios::binary|ios::in);
if(!outfile){
cout<<"File doesnot exist";
}
cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
     
      cout<<"\n\t\t\t***************\n";
      cout<<"\t\t\t\t\tALL DATA ";
      cout<<"\n\t\t\t***************\n\n";
show();
while(!outfile.eof()){
if(outfile.read(reinterpret_cast<char*>(this),sizeof(*this))){
showList();
}
}
getch();
outfile.close();
}

int password()//b
{
    char cname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    // srand(time(0));
    // cap=rand();
    // cout<<"\n\n\t\t\t\t\tCAPTURE:-> "<<cap<<endl;
    // cout<<" Please enter the valid capture :-   ";
    // cin>>capt;
    if( (strcmp(cname,"a")==0) && (strcmp(pass,"b")==0))
        return 1;
    else
        return 0;
}
// //----------------------------------------
void menu()//c
{
    system("cls");
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;

    cout<<"\n\t\t\t***************\n";
    cout<<"\t\t\t\t WELCOME TO THE MAIN MENU";
    cout<<"\n\t\t\t***************\n";
    cout<<"\n\t\t1: Add NEW Record\t\t\t 2: View All Data\t\t\t 4:view vaccine data"<<endl;
    
    cout<<"\n\t\t3: exit"<<endl;
}
//----------------------------------------
int main()//MAINFUNCTION---------------------------------------------------------------------------------------------
{
     Vaccine obj;
     int k=3;
     int num_vac;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
    B:
   // system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t*****************";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t*****************\n";
    while(k>=1)
    {
    int c =  password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
             
              goto B;
        }
    }
     int ch;
      do{
            cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
            
            menu();
            cout<<"\n\t\n\tChoose according to your need : ";
            cin>>ch;
             Vaccine v1;
       switch(ch)
        {
          case 1: system("cls");
              obj.addNew();
                  break;
   
           case 2:system("cls");
              obj.view_all();
                 
        
          case 3:  system("cls");
                     exit(0);
          case 4: system("cls") ;
              obj.viewVaccine() ;
          default: system("cls");
                   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                   cout<<"\n\n\t\t\t\t\t***HAVE A NICE DAY**";
                   Sleep(3000);
                   exit(0);
        }
       }while(ch!=0);
 
      return 0;
}