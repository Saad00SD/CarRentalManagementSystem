#include<iostream>
#include<string>
#include <sstream>
#include<fstream>
#include<iomanip>
#include"DEMCar_Queue.h"
#include"DEM_Stack.h"
using namespace std;

CQueue Q1;
QStack S1;

void Display();
void Search_From_Admin();

void Prof(){
	system ("CLS");
	cout<<"\t\t\t\t------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t ||           CAR RENTAL MANAGEMENT SYSTEM                || "<<endl;
	cout<<"\t\t\t\t ||_______________________________________________________|| "<<endl;			
	cout<<"\t\t\t\t-------------------------------------------------------------"<<endl;
   	cout<<"\n\t\t\t\t>>>------------------Project Implemented By-----------------<<<"<<endl;
   	cout<<"\t\t\t\t # Mohamed Saad"<<endl;
}

class welcome{;
 public:
 int welcum()
 {
   ifstream in("welcome.txt");
   if(!in) {
    	cout << "Cannot open input file.\n";
  	}
  	char str[1000];
  	while(in) {
    	in.getline(str, 1000);
    	if(in) cout << str << endl;
  	}
    in.close();
    //sleep(1);
    cout<<"\nStarting the program please wait....."<<endl;
    //sleep(1);
    cout<<"\nloading up files....."<<endl;
    //sleep(1);
    system ("CLS");
 }
 void thanks(){
  ifstream inf("thanks.txt");
  char str[300];

  while(inf) {
    inf.getline(str, 300);
    if(inf) cout << str << endl;
   }
  inf.close();
  //sleep(1);
  //sleep(1);
  system ("CLS");
 }
};


////////////////////////////////////////////////////////////////////

void CustomerPush()
{	
	string carID;
	string carName;
	int perdayrent;
	string carmodel;
	char data;
	system("cls");
	string cname;
	Q1.DisplayQueueNW();

	cout << "=======------------------------------------- Customer Car Rental Table --------------------------------------------=======\n" << endl;	
	cout<<"\n\n\n\t\tEnter Customer Name :- ";
	cin.ignore();
	getline(cin,cname);
	char udata;
	fstream file;
    int found = 0;
    file.open("Car.txt", ios::in);
    if (!file)
    {
        cout << "\n------------------------------------- Such UD Car is Not Available -----------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        cout<<"\t\tEnter CAR UD(Unique Data) of the Rented Car:- ";
	    cin>>udata;
	    while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid CAR UD(Unique Data)"<<endl;
				cout<<"\t\t\tEnter CAR UD(Unique Data) of the Rented Car:- ";
				cin>>udata;
			}
			if(!cin.fail())
				break;
			}
        file >> carID >> carName >> perdayrent >> carmodel >> data;
        while (!file.eof())
        {
            if (udata == data)
            {
            	int rentalfee;
				int days;
				cout<<"Number of days you wish to rent the car : ";
    			cin >> days;
    			while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\t\t\tNumber of days you wish to rent the car : ";
				cin>>days;
			}
			if(!cin.fail())
				break;
			}
    		rentalfee = days * perdayrent;
    		S1.push(cname, carName, carmodel,carID, data,perdayrent,rentalfee);
//				Q1.dequeue(data);	 
                
            }
            file >> carID >> carName >> perdayrent >> carmodel >> data;
            
        }
        file.close();
    }
	Q1.dequeue(udata);
	S1.calculate(cname);	
    cout<<"\n\n\t\t\t\tNew Customer data is Inserted!\n\n\n";
}

////////////////////////////////////////////////////////////////////
  	// Insert a new car details 
 void beg()
{	
	system("cls");
	Display();
	string cid;                //  quant    for quantity
	string name;
	int rentprice;            //  pre for price
	string mdl;
	char udata;
		
	cout<<"\n\n\t\tEnter CAR ID:- ";
	cin.ignore();
	getline(cin,cid);
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\t\t\tEnter CAR ID : ";
				cin.ignore();
				getline(cin,cid);
			}
			if(!cin.fail())
				break;
	}
	cout<<"\t\tEnter CAR Name:- ";
	cin.ignore();
	getline(cin,name);
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\t\t\tEnter CAR Name : ";
				cin.ignore();
				getline(cin,name);
			}
			if(!cin.fail())
				break;
	}
	cout<<"\t\tEnter CAR Rent per Day:- ";
	cin>>rentprice; 
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\t\t\tEnter CAR Rent Per Day : ";
				cin>>rentprice;
			}
			if(!cin.fail())
				break;
	}
	cout<<"\t\tEnter Car Model:- ";
	cin.ignore();
	getline(cin,mdl);
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\t\t\tEnter CAR Model : ";
				cin.ignore();
				getline(cin,mdl);
			}
			if(!cin.fail())
				break;
	}
	cout<<"\t\tEnter Car UD(Unique data):- ";
	cin>>udata;
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\t\t\tEnter CAR Model : ";
				cin>>udata;
			}
			if(!cin.fail())
				break;
	}
	
	Q1.Enqueue(cid, name, rentprice, mdl, udata);
		
	system("cls");
    cout<<"\n\n\t\t\t\tThis Car data is Inserted!\n\n\n";


}

void Search_From_Admin(){
	Q1.SearchFromQueue();
}
 
 ///////////////////////////////////////////////////////////////////////

void CustomerPop(){
	cout<<"\n\n>>>>>=============================================================<<<<<<<\n\n";
	char ch;
	cout<<"\tEnter the UD(Unique Data) of the Return Car of the Customer: ";
	cin>>ch;
    fstream file, file1;
    Stack S2;
    
    int found = 0;

    file.open("Customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        file1.open("record.txt", ios::app | ios::out);
        file >> S2.cusname >> S2.carname >> S2.carmodel >> S2.carid >> S2.data >> S2.rentPday >>S2.rentalfee;
        while (!file.eof())
        {
        	if (ch == S2.data)
            {
            	S1.calculate(S2.cusname);
				Q1.Enqueue (S2.carid, S2.carname, S2.rentPday, S2.carmodel, S2.data);
            }
            if (ch != S2.data)
            {
                file1<<"\n"<<S2.cusname;
 				file1<<"\n"<<S2.carname;
 				file1<<"\n"<<S2.carmodel;
 				file1<<"\n"<<S2.carid;
				file1<<"\n"<<S2.data;
				file1<<"\n"<<S2.rentPday;
				file1<<"\n"<<S2.rentalfee<<"\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Customer Return the Car without Due";
            }
            file >> S2.cusname >> S2.carname >> S2.carmodel >> S2.carid >> S2.data >> S2.rentPday >>S2.rentalfee;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Car UD(Uniqueue Data). Not Found....";
        }
        file1.close();
        file.close();
        remove("Customer.txt");
        rename("record.txt", "Customer.txt");
    }

//	Display();
	
}
void Display(){
	Q1.DisplayQueueNW();
}

void DeleteinQueue(){
	Q1.DeleteQueue();	
}
void ModifyinQueue(){
	Q1.ModifyQueue();	
}


void DeleteinStack(){
	S1.DeleteStack();
}
void ModifyinStack(){
	S1.ModifyStack();
}
void CustomerDisplay(){
	S1.DispalyStack();
}
void Search_CustomerinStack(){
	S1.SearchFromStack();
}

 /////////////////////////////////////////////////////////////////////////////////////////
    void administator()
	{
		system("cls");
		Prof();
			int ch;

 
		do {
		
			cout<<"\n\n\n\t\t============================================="<<endl;
			cout<<"\t\t|          Administator Portal              |"<<endl;
			cout<<"\t\t============================================="<<endl;
			
			cout<<"\t\t     Enter 1 for ADD a new Vehicle    "<<endl;
			cout<<"\t\t     Enter 2 to  DISPLAY all Vehicles   "<<endl;
			cout<<"\t\t     Enter 3 for MODIFY Existing Vehicle Details "<<endl;
			cout<<"\t\t     Enter 4 for DELETE a particular Vehicle "<<endl;
			cout<<"\t\t     Enter 5 for SEARCH Car "<<endl;
			cout<<"\t\t     Enter 6 for ADD a new Customer    "<<endl;
			cout<<"\t\t     Enter 7 for DISPLAY ALL Customers"<<endl;
			cout<<"\t\t     Enter 8 for MODIFY Customer Record "<<endl;
			cout<<"\t\t     Enter 9 for DELETE Customer Record "<<endl;
			cout<<"\t\t     Enter 10 for SEARCH Customer Record "<<endl;
			cout<<"\t\t     Enter 11 for Customer Car Return "<<endl;
			cout<<"\t\t     Enter 0 for Main Menu "<<endl;
			
			
			cout<<"\nEnter Your choice >>>"; 
			cin>>ch;
			while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\nEnter Your choice >>>";
				cin>>ch;
			}
			if(!cin.fail())
				break;
			}
			switch(ch){
			case 1:
				beg();
				break;
			case 2:
				system("cls");
			    Display();
			    break;
			case 3:
				system("cls");
				ModifyinQueue();
				Display();
				break;
			case 4:
				system("cls");
				Display();
				cout<<"\n\n>>>>>=============================================================<<<<<<<\n\n";
				DeleteinQueue();
				cout<<"\n-------Vehicle is Deleted-------\n";
				Display();
				break;
			case 5:
				system("cls");
			    cout<<"|============ Car Details ==============|"<<endl;
				Search_From_Admin();
				break;
			case 6:
				system("cls");
				cout<<"\t\t\t|============CUSTOMERS NAMES LIST==============|"<<endl;
				cout<<endl<<endl;
				CustomerPush();
				break;	
			case 7:
				system("cls");
				cout<<"\t\t\t|============CUSTOMERS NAMES LIST==============|"<<endl;
			    CustomerDisplay();
				break;
			case 8:
				system("cls");
				CustomerDisplay();
				ModifyinStack();
				CustomerDisplay();
				break;
			case 9:
				system("cls");
				CustomerDisplay();
				cout<<"\n\n>>>>>=============================================================<<<<<<<\n\n";
				DeleteinStack();
				cout<<"\n-------Customer is Deleted-------\n";
				CustomerDisplay();
				break;
			case 10:
				system("cls");
			    cout<<"|============ Customer Details ==============|"<<endl;
			    CustomerDisplay();
				Search_CustomerinStack();
				break;
			case 11:
    			system("cls");
				CustomerDisplay();
				CustomerPop();
    			break;
				
			default:
			    system("cls");
	
		}
		
	}while(ch!=0);
}

void login();

 
 
void mainfunction(){

    int ch;
    Prof();
	while(ch!=5){

    cout<<"\n\t\t\t||======--------<<Main Menu>>-----------======||";
    cout<<"\n\n";
	cout<<"\t\t\t 1] ADMINISTRATOR of RS RENTAL CAR YARD\n";
	cout<<"\t\t\t 2] DISPLAY CAR          				\n";
	cout<<"\t\t\t 3] DISPLAY CUSTOMER        			\n";
	cout<<"\t\t\t 4] CUSTOMER CAR RETURN      			\n";
	cout<<"\t\t\t 5] EXIT                    			\n";



	cout<<"\nEnter Your choice ==>>";
	cin>>ch;
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			//	system("cls");
				cout<<"\t\t\tYou have entered wrong input Please Enter Valid Data type."<<endl;
				cout<<"\nEnter Your choice >>>";
				cin>>ch;
			}
			if(!cin.fail())
				break;
	}
	switch(ch){
	case 1:
		system("cls");
		login();
		break;

	case 2:
		system("cls");
		Display();
	    break;
	    
	case 3:
		system("cls");
		cout<<endl<<endl;
		CustomerDisplay();
		mainfunction();
	    break;    
	
	case 4:
    	system("cls");
		CustomerDisplay();
		CustomerPop();
    	break;
    	
    case 5:
    	system("cls");
    	welcome obj2;
    	obj2.thanks();
    	//cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
    	
    	break;
   
	}
  }
  exit(0);
}

void login(){
	Prof();
	string username;
	string password="";
	int num;
	
	cout<<"\n\nPlease Enter Your User Name: ";
	cin>>username;
	cout<<"Please Enter Your Password: ";
	cin>>password;

	if(username == "Admin" && password == "admin@123"){
		system("cls");
		administator();
	}else{
		system("cls");
		cout<<"Wrong Password Or Username "<<endl;
		cout<<"Enter 1 For Try agin \nEnter 2 For Main Menu\nEnter 3 For Exit "<<endl;
		cin>>num;
		switch(num){
			case 1:
				system("cls");
				login();
				break;
			
			case 2:
				system("cls");
				mainfunction();
				break;					
		}
	}
}
int main(){
	welcome obj1;
	obj1.welcum();
	Q1.Reopenqueue();
	S1.ReopenQstack();
	cout<<"\t\t\t\t------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t ||        RS CAR RENTAL MANAGEMENT SYSTEM                || "<<endl;
	cout<<"\t\t\t\t ||_______________________________________________________|| "<<endl;			
			   
	cout<<"\t\t\t\t-------------------------------------------------------------"<<endl;
   	cout<<"\n\t\t\t\t>>>------------------Project Implemented By-----------------<<<"<<endl;
    cout<<"\t\t\t\t # Mohamed Rishad"<<endl;
   	cout<<"\t\t\t\t # Mohamed Saad"<<endl;
   	
	system("pause");
	system("cls");
	mainfunction();	
}
