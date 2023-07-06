#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

using namespace std;



struct Employee{
	string Fname,Mname,Lname,Position,Id,Pin,taxes;
	float Gpay,wDay,Pnum,Psal,Ttax,bene,Npay;
};
Employee Employ[100];


int Psalary[6]={0,600,500,400,300,300};

int benefits=300;
float total;
string Pos[6]={" ","Manager","Supervisor","TeamLeader","LineCook","DishWasher"};



int opt=0, Ecount=0;

string user,pin;

void cls();
void login();
void admin();
void addEm();
void save();
void load();
void UpEmp();
void UpLast();
void DelEmp();
void UpFirst();
void UpMiddle();
void Upid();
void UpPos();
void UpWork();
void UpPin();
void UpAll();
void DelAll();

void border();
 
void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}




int main(){
	cls();
	border();
	gotoxy(55,3);
	cout<<"Menu";
    gotoxy(50,7);
	cout<<"[1] Login";
    gotoxy(50,8);
	cout<<"[2] Exit";
    gotoxy(48,10);
	cout<<"[             ] ";
		int x,style=205;
	gotoxy(3,12);
	for(x=3;x<=130;x++){
		printf("%c",style);
	}
    gotoxy(55,10);
	
	cin>>opt;
	
	
	switch(opt){
		case 1: login(); break;
		case 2: exit(0); break;
		default: 
	
	gotoxy(50,13);
		cout<<"Invalid Input";
		gotoxy(45,14);
		system("pause");
		main();
	}
	return 0;
}

void border(){
	int x,style=205;
	gotoxy(3,1);
	for(x=3;x<=130;x++){
		printf("%c",style);
	}
    gotoxy(3,5);
    for(x=3;x<=130;x++){
		printf("%c",style);
	}
   
}




void DelAll(){

	for(int i = 0; i <= Ecount; i++)
		{
		Employ[i] = Employ[i + 1];
		
		}
		Ecount=0;
        gotoxy(43,30);
		cout << "Record deleted successfully!";
        gotoxy(43,31);
		system("pause");
	
	save();
	admin();
	
	
	
}

void UpAll(){  
	cls();
	int num;
	border();
	gotoxy(55,3);
	cout<<"UPDATE All EMPLOYEE INFORMATION";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	
	
	gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
	cin.ignore();
    gotoxy(3,24);
	cout<<"Update  All Employee Information";
    gotoxy(3,25);
	cout<<"Enter Last Name : ";
	getline(cin, Employ[index].Lname);
    gotoxy(40,25);
	cout<<"Enter First Name : ";
	getline(cin, Employ[index].Fname);
    gotoxy(75,25);
	cout<<"Enter Middle Name : ";
	getline(cin, Employ[index].Mname);
	
	gotoxy(3,27);
	cout<<"Position List";
    gotoxy(3,28);
	cout<<"[1] Manager";
    gotoxy(3,29);
	cout<<"[2] Supervisor";
    gotoxy(3,30);
	cout<<"[3] TeamLeader";
    gotoxy(3,31);
	cout<<"[4] LineCook";
    gotoxy(3,32);
	cout<<"[5] DishWasher";
	gotoxy(3,33);
	cout<<"Enter Position : ";
	cin>>opt;

    switch(opt){
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		default: gotoxy(45,33); 
                cout<<"Invalid Input";
                gotoxy(45,34);
		system("pause");
		UpAll();
	}

	gotoxy(40,27);
	cout<<"Enter Work Day : ";
	cin>>Employ[index].wDay;
	gotoxy(75,27);
	cout<<"Enter ID : ";
    cin>>user;
	

    for(int i=0;i<Ecount;i++){
        if(user==Employ[i].Id ){
            gotoxy(45,33);
            cout<<"Same ID Other Employee";
            gotoxy(45,34);
            system("pause");
            UpAll();
        }

    }
    
    
    gotoxy(40,29);
	cout<<"Enter Pincode : ";
    cin>>pin;
	

    for(int i=0;i<Ecount;i++){
        if(pin==Employ[i].Pin ){
            gotoxy(45,33);
            cout<<"Same Pin Other Employee";
            gotoxy(45,34);
            system("pause");
            UpAll();
        }

    }

	Employ[index].Pin=pin;
    Employ[index].Id=user; 

	Employ[index].Psal=Psalary[opt];
	
	
	Employ[index].Position=Pos[opt];

	Employ[index].Gpay=Employ[index].Psal*Employ[index].wDay;
	
	
	if(Employ[index].Gpay <= 10000){
		Employ[index].taxes="15%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 10001 && Employ[index].Gpay <= 15000){
			Employ[index].taxes="20%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 15001 && Employ[index].Gpay <= 20000){
		Employ[index].taxes="25%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 20001){
		Employ[index].taxes="30%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}

        Employ[index].Npay=Employ[index].Gpay-Employ[index].Ttax; 
	gotoxy(45,33);
	cout<<"All Employee Information Updated Successful";
    gotoxy(45,34);
		system("Pause");
		save();

        }
        else{
        gotoxy(45,33);
		cout<<"Employee Record Not Found";
        gotoxy(45,34);
        system("pause");
	}
		admin();
			
		

	
	
}

void UpPin(){
	int num =0 ;
	cls();
	border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR PINCODE";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
    
	
		if(index !=-1){
		cin.ignore();
        gotoxy(3,24);
        cout<<"Current Pincode : "<<Employ[index].Pin;
        gotoxy(3,25);
		cout<<"Enter Updated Pin : ";
        cin>>pin;
     for(int i=0;i<Ecount;i++){
        if(pin==Employ[i].Pin ){
            gotoxy(45,27);
            cout<<"Same Pin Other Employee";
            gotoxy(45,28);
            system("pause");
            UpPin();
        }

    }
		Employ[index].Pin=pin;
		
        gotoxy(45,27);
		cout<<"Pin Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();
        
        }

        else{
        gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
	}

		admin();
			
		

}

void UpPos(){
	
	int num =0 ;
	cls();
	 border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR POSITION";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	
	gotoxy(3,18);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
		cin.ignore();
		gotoxy(3,19);
		cout<<"Position List";
        gotoxy(3,20);
		cout<<"[1] Manager";
        gotoxy(3,21);
		cout<<"[2] Supervisor";
        gotoxy(3,22);
		cout<<"[3] TeamLeader";
        gotoxy(3,23);
		cout<<"[4] LineCook";
        gotoxy(3,24);
		cout<<"[5] DishWasher";
		
		
	gotoxy(3,25);
	cout<<"Enter Updated Position : ";
	cin>>opt;
    
    switch(opt){
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        default:
                gotoxy(45,27);
                cout<<"Invalid Input";
                gotoxy(45,28);
                system("pause");
                UpPos();
    }
	
	Employ[index].Psal=Psalary[opt];
	

	Employ[index].Position=Pos[opt];

	Employ[index].Gpay=Employ[index].Psal*Employ[index].wDay;
	
	
	if(Employ[index].Gpay <= 10000){
		Employ[index].taxes="15%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 10001 && Employ[index].Gpay <= 15000){
			Employ[index].taxes="20%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 15001 && Employ[index].Gpay <= 20000){
		Employ[index].taxes="25%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 20001){
		Employ[index].taxes="30%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}

        Employ[index].Npay=Employ[index].Gpay-Employ[index].Ttax;
		
	
		gotoxy(45,27);
		cout<<"Position Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();
	
			
		

	
		
	}
	else{
        gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
	}
	admin();
	
}
void UpWork(){
	int num =0 ;
	cls();
	border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR WORKDAY";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	
	
	gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
		cin.ignore();
        gotoxy(3,24);
        cout<<"Current WorkDay Per Months : "<<Employ[index].wDay;
        gotoxy(3,25);
		cout<<"Enter Updated Work Day : ";
		cin>>Employ[index].wDay;

		Employ[index].Gpay=Employ[index].Psal*Employ[index].wDay;
	
	
	if(Employ[index].Gpay <= 10000){
		Employ[index].taxes="15%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 10001 && Employ[index].Gpay <= 15000){
			Employ[index].taxes="20%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 15001 && Employ[index].Gpay <= 20000){
		Employ[index].taxes="25%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}else if (Employ[index].Gpay >= 20001){
		Employ[index].taxes="30%";
			Employ[index].Ttax=(Employ[index].Gpay*.15)+benefits;
		}

        Employ[index].Npay=Employ[index].Gpay-Employ[index].Ttax;
		
        gotoxy(45,27);
		cout<<"WorkDay Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();
	
			
		

	
		
	}
	else{
        gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
	}
	admin();
	
}

void Upid(){
	int num =0 ;
	cls();
	border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR ID";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	
    gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
		cin.ignore();
        gotoxy(3,24);
        cout<<"Current ID : "<<Employ[index].Id;
        gotoxy(3,25);
		cout<<"Enter Updated ID : ";
        cin>>user;

         for(int i=0;i<Ecount;i++){
        if(user==Employ[i].Id ){
            gotoxy(45,27);
            cout<<"Same ID Other Employee";
            gotoxy(45,28);
            system("pause");
            Upid();
        }

    }
     
		Employ[index].Id=user;
		

        gotoxy(45,27);
		cout<<"ID Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();
	
			
		

	
		
	}
	else{gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
	}
	admin();
	
}

void UpFirst(){
		int num =0 ;
	cls();
	 border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR FIRSTNAME";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
		cin.ignore();
        gotoxy(3,24);
        cout<<"Current FirstName : "<<Employ[index].Fname;
        gotoxy(3,25);
		cout<<"Enter Updated FirstName : ";
		getline(cin,Employ[index].Fname);
		
        gotoxy(45,27);
		cout<<"FirstName Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();
	
			
		

	
		
	}
	else{
        gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
        
	}
	admin();
	
	
}

void UpMiddle(){
	int num =0 ;
	cls();
	 border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR MIDDLENAME";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
		cin.ignore();
        gotoxy(3,24);
        cout<<"Current MiddleName"<<Employ[index].Mname;
        gotoxy(3,25);
		cout<<"Enter Updated MiddleName : ";
		getline(cin,Employ[index].Mname);
		
        gotoxy(45,27);
		cout<<"MiddleName Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();
	
			
		

	
		
	}
	else{
        gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
	}
	admin();
	
	
}

void DelEmp(){
	int num = 0;
	cls();
	border();
	gotoxy(55,3);
	cout<<"DELETE EMPLOYEE";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	gotoxy(3,22);
	cout<<"Enter No. To Be Deleted : ";
	cin>>num;
	
	int index=-1;
	for(int i= 0; i<Ecount; i++){
		if(i+1==num){
			index = i;
			break;
		}
	}
	
	if (index != -1) 
	{
		for (int i = index; i < Ecount - 1; i++)
		{
		Employ[i] = Employ[i + 1];
		}
		Ecount--; 
        gotoxy(45,27);
		cout << "Record deleted successfully!";
        gotoxy(45,28);
		save();
	}
	else
	{   gotoxy(45,27);
		cout << "Record not found!";
        gotoxy(45,28);
        system("pause");
	}
	admin();
	
	
	
}

void UpLast(){
	int num =0 ;
	cls();
    border();
	gotoxy(55,3);
	cout<<"UPDATE EMPLOYEE FOR LASTNAME";
	 gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
	
	gotoxy(3,22);
	cout<<"Enter No. To Be Update : "; cin>>num;
	int index=-1;
	for (int i = 0; i < Ecount; i++)
	{
		if (i + 1 == num)
		{
			index = i; 
			break;
		}
	}
	
		if(index !=-1){
		cin.ignore();
        gotoxy(3,24);
        cout<<"Current LastName : "<<Employ[index].Lname;
        gotoxy(3,25);
		cout<<"Enter Updated LastName : ";
		getline(cin,Employ[index].Lname);
		
        gotoxy(45,27);
		cout<<"LastName Updated Successful";
        gotoxy(45,28);
		system("Pause");
		save();	
	}
	else{
        gotoxy(45,27);
		cout<<"Employee Record Not Found";
        gotoxy(45,28);
        system("pause");
	}
	admin();
	
	
}

void UpEmp(){
	cls();
	border();
	gotoxy(55,3);
    cout<<"UPDATE EMPLOYEE";
	gotoxy(43,6);
	cout<<"Choose What You Want To Update";
    gotoxy(43,7);
	cout<<"[1] LastName";
    gotoxy(43,8);
	cout<<"[2] FirstName";
    gotoxy(43,9);
	cout<<"[3] MiddleName";
    gotoxy(43,10);
	cout<<"[4] Work Day";
    gotoxy(43,11);
	cout<<"[5] Position";
    gotoxy(43,12);
	cout<<"[6] ID";
    gotoxy(43,13);
	cout<<"[7] Pin";
    gotoxy(43,14);
	cout<<"[8] All";
    gotoxy(43,15);
    cout<<"[9] Back";
    gotoxy(43,16);
	cout<<"--> "; cin>>opt;
	
	switch(opt){
		case 1: UpLast(); break;
		case 2: UpFirst(); break;
		case 3: UpMiddle(); break;
		case 4: UpWork(); break;
		case 5: UpPos(); break;
		case 6: Upid(); break;
		case 7: UpPin(); break;
		case 8: UpAll(); break;
        case 9: admin(); break;
		default:
                gotoxy(45,22);
                 cout<<"invalid Input";
                 gotoxy(45,23);
                 system("pause");
                 UpEmp();
	}

	
	
	
}



void load()
{	
	ifstream read;
	read.open("Employee_Info.txt");
	read >> Ecount; 
	read.ignore();

	for (int i = 0; i < Ecount; i++)
	{
		string value;
		getline(read, Employ[i].Lname, ',');
		getline(read, Employ[i].Fname, ',');
		getline(read, Employ[i].Mname, ',');
		getline(read, Employ[i].Position, ',');
		getline(read, value, ',');
		Employ[i].Psal = std::stof(value);
		getline(read, value, ',');
		Employ[i].wDay = stof(value);
		getline(read, value, ',');
		Employ[i].Gpay = stof(value);

		getline(read, Employ[i].taxes, ',');
		getline(read, value, ',');
		Employ[i].Ttax = stof(value);
		getline(read, value, ',');
		benefits = stoi(value);
        Employ[i].Npay = stof(value);
        getline(read, value, ',');
		getline(read,  Employ[i].Id, ',');
		getline(read, Employ[i].Pin, '\n');
	}
	read.close();
}

void save(){
	ofstream write;
	write.open("Employee_Info.txt");
	write << Ecount << endl;
	for(int i=0;i<Ecount;i++){
		
		
		write<<Employ[i].Lname<<",";
		write<<Employ[i].Fname<<",";
		write<<Employ[i].Mname<<",";
		write<<Employ[i].Position<<",";
		write<<Employ[i].Psal<<",";
		write<<Employ[i].wDay<<",";
		write<<Employ[i].Gpay<<",";
		write<<Employ[i].taxes<<",";
		write<<Employ[i].Ttax<<",";
		write<<benefits<<","; 
        write<<Employ[i].Npay<<",";
		write<<Employ[i].Id<<",";
		write<<Employ[i].Pin<<endl;

		
	}
	write.close();
	

	
}

void addEm(){
	cin.ignore();
	cls();
    border();
	gotoxy(55,3);
	cout<<"Add Employee";
    gotoxy(30,7);
	cout<<"Enter Last Name  : ";
    gotoxy(30,8);
    cout<<"Enter First Name : ";
    gotoxy(30,9);
    cout<<"Enter Middle Name : ";

    gotoxy(30,10);
	cout<<"Position List";
    gotoxy(30,11);
	cout<<"[1] Manager";
    gotoxy(30,12);
	cout<<"[2] Supervisor";
    gotoxy(30,13);
	cout<<"[3] TeamLeader";
    gotoxy(30,14);
	cout<<"[4] LineCook";
    gotoxy(30,15);
	cout<<"[5] DishWasher";
    gotoxy(30,16);	
	cout<<"Enter Position : ";
    gotoxy(30,17);
	cout<<"How many Day of Work : ";
    gotoxy(30,18);
	cout<<"Enter ID : ";
    gotoxy(30,19);
	cout<<"Enter pin : ";

    gotoxy(49,7);
	getline(cin, Employ[Ecount].Lname);
    gotoxy(49,8);
	getline(cin, Employ[Ecount].Fname);
     gotoxy(50,9);	
	getline(cin, Employ[Ecount].Mname);
    gotoxy(47,16);	
	cin>>opt;
	
	switch(opt){
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		default: cout<<"\nInvalid Input\n";
		system("pause");
		admin();
	}
	
	Employ[Ecount].Psal=Psalary[opt];
	Employ[Ecount].Position=Pos[opt];
	
    gotoxy(53,17);
	cin>>Employ[Ecount].wDay;

	
	Employ[Ecount].Gpay=Employ[Ecount].Psal*Employ[Ecount].wDay;
	
	
	if(Employ[Ecount].Gpay <= 10000){
		Employ[Ecount].taxes="15%";
			Employ[Ecount].Ttax=(Employ[Ecount].Gpay*.15)+benefits;
		}else if (Employ[Ecount].Gpay >= 10001 && Employ[Ecount].Gpay <= 15000){
			Employ[Ecount].taxes="20%";
			Employ[Ecount].Ttax=(Employ[Ecount].Gpay*.15)+benefits;
		}else if (Employ[Ecount].Gpay >= 15001 && Employ[Ecount].Gpay <= 20000){
		Employ[Ecount].taxes="25%";
			Employ[Ecount].Ttax=(Employ[Ecount].Gpay*.15)+benefits;
		}else if (Employ[Ecount].Gpay >= 20001){
		Employ[Ecount].taxes="30%";
			Employ[Ecount].Ttax=(Employ[Ecount].Gpay*.15)+benefits;
		}

        Employ[Ecount].Npay=Employ[Ecount].Gpay-Employ[Ecount].Ttax;
	
	
	
	
	
    gotoxy(41,18);
    cin>>user;
    
	
   

      for(int i=0;i<Ecount;i++){
        if(user==Employ[i].Id ){
             gotoxy(45,22);
			cout<<"There same id on other employee";
            gotoxy(45,23);
			system("pause");
			admin();
        }

    }
		

	
	
	
	
    gotoxy(43,19);
	cin>>pin;
	
	 for(int i=0;i<Ecount;i++){
        if(pin==Employ[i].Pin ){
             gotoxy(45,22);
			cout<<"There same id on other employee";
            gotoxy(45,23);
			system("pause");
			admin();
        }

    }
     
    Employ[Ecount].Id=user;
	Employ[Ecount].Pin=pin;
	

	 gotoxy(45,22);	
	cout<<"Employee Added!";
     gotoxy(45,23);
	system("pause");
	Ecount++;
	save();
	admin();

	
}

void admin(){
	cls();
	load();
    border();
	gotoxy(55,3);
	cout<<"Admin Inferface";
    gotoxy(3,6);
	cout<<"Records ";
    gotoxy(3,7);
	cout<<"No.";
    gotoxy(9,7);
    cout<<"LastName";
    gotoxy(20,7);
    cout<<"FirstName";
    gotoxy(33,7);
    cout<<"MiddleName";
    gotoxy(46,7);
    cout<<"Position";
    gotoxy(57,7);
    cout<<"Pos.Gpay";
    gotoxy(69,7);
    cout<<"WorkDay";
    gotoxy(78,7);
    cout<<"GrossPay";
    gotoxy(88,7);
    cout<<"Tax";
    gotoxy(94,7);
    cout<<"Contr.";
    gotoxy(101,7);
    cout<<"TotalTax";
    gotoxy(111,7);
    cout<<"NetPay";
    gotoxy(119,7);
    cout<<"ID";
    gotoxy(126,7);
    cout<<"Pin\n";
	for(int i=0;i<Ecount;i++){
		gotoxy(3,8+i);
		cout<<"["<<i+1<<"]";
        gotoxy(9,8+i);
		cout<<Employ[i].Lname;
         gotoxy(20,8+i);
		cout<<Employ[i].Fname;
         gotoxy(33,8+i);
		cout<<Employ[i].Mname;
         gotoxy(46,8+i);
		cout<<Employ[i].Position;
        gotoxy(60,8+i);
		cout<<Employ[i].Psal;
        gotoxy(71,8+i);
		cout<<Employ[i].wDay;
         gotoxy(79,8+i);
		cout<<Employ[i].Gpay;
        gotoxy(88,8+i);
		cout<<Employ[i].taxes;
        gotoxy(95,8+i);
		cout<<benefits;
        gotoxy(102,8+i);
        cout<<Employ[i].Ttax;
        gotoxy(112,8+i);
        cout<<Employ[i].Npay;
        gotoxy(119,8+i);
		cout<<Employ[i].Id;
        gotoxy(126,8+i);
		cout<<Employ[i].Pin<<endl;
	}
    gotoxy(13,20);
    cout<<"Menu";
	int x,style=205;
	gotoxy(3,21);
	for(x=3;x<=28;x++){
		printf("%c",style);
	}
	gotoxy(3,22);
	cout<<"[1] Add Employee";
    gotoxy(3,23);
	cout<<"[2] Update Employee";
    gotoxy(3,24);
	cout<<"[3] Delete Employee";
    gotoxy(3,25);
	cout<<"[4] Delete All Employee";
    gotoxy(3,26);
	cout<<"[5] Logout";



     gotoxy(103,20);
    cout<<"Description";
    gotoxy(84,21);
	for(x=84;x<=130;x++){
		printf("%c",style);
	}
     gotoxy(84,22);
    cout<<"Contribution";
     gotoxy(86,23);
     cout<<"Pag ibig - P100";
     gotoxy(86,24);
     cout<<"SSS - P100";
     gotoxy(86,25);
     cout<<"PhilHealth - P100";
     gotoxy(84,26);
     cout<<"Tax Computations";
     gotoxy(86,27);
     cout<<"15% - Below P10,000(Salary)";
     gotoxy(86,28);
     cout<<"20% - Above P10,001 and Below P15,000(Salary)";
     gotoxy(86,29);
     cout<<"25% - Above P15,001 and Below P20,000(Salary)";
     gotoxy(86,30);
     cout<<"30% - Above P20,001(Salary)";
     
     

    gotoxy(3,27);
	cout<<"-->  "; cin>>opt;
	
	switch(opt){
		case 1: addEm(); break;
		case 2: UpEmp(); break;
		case 3: DelEmp(); break;
		case 4: DelAll(); break;
		case 5: main(); break;
		default:
                gotoxy(43,30);
                cout<<"Invalid Input";
                gotoxy(43,31);
                system("pause");
                admin();
	}
}

void cls(){
	system("cls");
}

void login(){	
	load();
	cls();
	 int x,style=205;
	    gotoxy(3,11);
	    for(x=3;x<=130;x++){
		printf("%c",style);
	}
    border();
	gotoxy(55,3);
	printf("Login");
    gotoxy(50,7);
	printf("ID : ");
     gotoxy(50,9);
	printf("Pin : ");
    gotoxy(56,7);
	cin>>user;
    gotoxy(57,9);
	cin>>pin;
	
	if(user=="admin" && pin=="admin"){
		admin();
	}
	
	for(int i=0;i<Ecount;i++){
	
		if(user==Employ[i].Id && pin==Employ[i].Pin){
			cls();
			border();
			gotoxy(52,3);
			cout<<"Employee Payslip ";
			gotoxy(43,6);
			cout<<"SurName : "<<Employ[i].Lname;
			gotoxy(43,7);
			cout<<"First Name :"<<Employ[i].Fname;
			gotoxy(43,8);
			cout<<"Middle Name : "<<Employ[i].Mname;
			gotoxy(43,9);
			cout<<"Position : "<<Employ[i].Position;
			gotoxy(43,10);
			cout<<"Per Hour : P"<<Employ[i].Psal;
			gotoxy(43,11);
			cout<<"WorkDay : "<<Employ[i].wDay;
			gotoxy(43,12);
			cout<<"Gross Pay : P"<<Employ[i].Gpay;
			gotoxy(43,13);
			cout<<"Tax Percentage : "<<Employ[i].taxes;
			gotoxy(43,14);
			cout<<"Contributions : ";
			gotoxy(45,15);
			cout<<"Phil Health - P100";
			gotoxy(45,16);
			cout<<"Pag ibig - P100";
			gotoxy(45,17);
            cout<<"SSS -100";
			gotoxy(43,18);
			cout<<"Tax : P"<<Employ[i].Ttax;
			gotoxy(43,19);
			cout<<"Net Pay : P"<<Employ[i].Npay;

			gotoxy(3,21);
			char style=205;
    for(int x=3;x<=130;x++){
		printf("%c",style);
	}
			gotoxy(46,22);
			cout<<"To Logout ";
			system("pause");
			main();	
			break;
		
		}
			

		
		}
       
        gotoxy(46,12);
		cout<<"Incorrect User/Pin ";
        gotoxy(46,13);
        system("pause");
			main();
	
	
}  




