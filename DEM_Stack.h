//#include <iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomanip>

using namespace std;

struct Stack
 { 
	string cusname;
    string carname;
    string carmodel;
    string carid;
    int rentPday;
    int rentalfee;
    char data;
    Stack* next; 
};

class QStack{
public:


Stack *front;
Stack *rear;
QStack(){
	front=NULL;
	rear=NULL;	
} 
 
void ReopenQstack(){
    Stack* temp = front;	
	ifstream read("Customer.txt");
	if(read.is_open()){		
		while(!read.eof()){
			Stack* ptr = new Stack;
			read>>ptr->cusname;
			read>>ptr->carname;
			read>>ptr->carmodel;
			read>>ptr->carid;
			read>>ptr->data;
			read>>ptr->rentPday;
			read>>ptr->rentalfee;
			if(temp == NULL){
				ptr->next = NULL;
				front = ptr;
				rear = ptr;				
			}
			else{
				rear->next = ptr;
				rear = ptr;
			}
			temp = ptr;
		}
		rear->next = NULL;
	}
	else{
		cout<<"  File is Empty so Cannot open...Sorry"<<endl;
	}  
}
 
bool isempty()
{
 if(front == NULL && rear == NULL)
 	return true;
 else
 	return false;
}

void push(string Cusname,string Carname,string Carmodel,string Carid,char Data,int rent,int rentfee)
{
	
 Stack *ptr = new Stack();
 ptr->cusname= Cusname;
 ptr->carname= Carname;
 ptr->carmodel= Carmodel;
 ptr->carid = Carid;
 ptr->data = Data;
 ptr->rentPday = rent;
 ptr->rentalfee = rentfee;
 ptr->next = NULL;
 
 ofstream file;
 file.open("Customer.txt", ios::app | ios::out);
 file<<"\n"<<ptr->cusname;
 file<<"\n"<<ptr->carname;
 file<<"\n"<<ptr->carmodel;
 file<<"\n"<<ptr->carid;
 file<<"\n"<<ptr->data;
 file<<"\n"<<ptr->rentPday;
 file<<"\n"<<ptr->rentalfee<<"\n";

 //If inserting the first element/node
 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->next = ptr;
  rear = ptr;
 }
 cout<<"\n\n----->>>Succesfully New Customer Inserted<<<-------\n\n"; 
 file.close(); 
}

void pop(string Name)
{ 
	system("cls");
    int found = 0;

	if(isempty()) 
		cout << "\n\t\t\tNo Data is Present.."; 
	else 
	{ 
		ofstream write;
		write.open("temp.txt");
		ifstream read;
		read.open("Customer.txt");

		Stack *ptr = front; 
		while (ptr != NULL && ptr->cusname != Name ){
			
			write<<"\n"<<ptr->cusname;
 			write<<"\n"<<ptr->carname;
 			write<<"\n"<<ptr->carmodel;
 			write<<"\n"<<ptr->carid;
			write<<"\n"<<ptr->data;
			write<<"\n"<<ptr->rentPday;
			write<<"\n"<<ptr->rentalfee<<"\n";
			
			ptr = ptr->next; 				
		}
					
		if (ptr == NULL) 
			cout << "\n\t\t\tNo Data is Present..";
		else if (ptr == front) 
		{ 
			front = front->next; 
			
			free(ptr); 
		} 
		else
		{ 
			Stack *temp = front; 
			while (temp->next != ptr) 
				temp = temp->next; 
			temp->next = ptr->next; 
			free(ptr); 
		} 
		//Write the remaining cars in the queue to the file
		ptr = front;
		while (ptr != NULL){
			write<<"\n"<<ptr->cusname;
 			write<<"\n"<<ptr->carname;
 			write<<"\n"<<ptr->carmodel;
 			write<<"\n"<<ptr->carid;
			write<<"\n"<<ptr->data;
			write<<"\n"<<ptr->rentPday;
			write<<"\n"<<ptr->rentalfee<<"\n";
			ptr = ptr->next; 
		}

		read.close();
		write.close();
		remove("Customer.txt");
		rename("temp.txt", "Car.txt");
	} 
}
void calculate(string name){
	//	sleep(1);
		system ("CLS");
		cout<<"Calculating rent. Please wait......"<<endl;
	//	sleep(2);
		Stack S2;
	fstream read;
    int found = 0;
    read.open("Customer.txt", ios::in);
    if (!read)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Customer Data is Unavailable-----------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        read >> S2.cusname >> S2.carname >> S2.carmodel >> S2.carid >> S2.data >> S2.rentPday >>S2.rentalfee;
        int days = S2.rentalfee/S2.rentPday;
        while (!read.eof())
        {
            if (name == S2.cusname)
            {
                cout << "\n                       Car Rental - Customer Invoice                  "<<endl;
    			cout << "	///////////////////////////////////////////////////////////"<<endl;
    			cout << "	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
    			cout << "	| Customer Name:"<<"-----------------|"<<setw(10)<<S2.cusname<<" |"<<endl;
    			cout << "	| Car Name  :"<<"--------------------|"<<setw(10)<<S2.carname<<" |"<<endl;
    			cout << "	| Car Model :"<<"--------------------|"<<setw(10)<<S2.carmodel<<" |"<<endl;
    			cout << "	| Car No. :"<<"----------------------|"<<setw(10)<<S2.carid<<" |"<<endl;
    			cout << "	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
    			cout << "	| Your Rental Amount is :"<<"--------|"<<setw(10)<<S2.rentalfee<<" |"<<endl;
    			cout << "	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    			cout << "	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    			cout << "	 ________________________________________________________"<<endl;
    			cout <<"\n";
    			cout << "	| Total Rental Amount is :"<<"-------|"<<setw(10)<<S2.rentalfee<<" |"<<endl;
    			cout << "	 ________________________________________________________"<<endl;
    			cout << "	 # This is a computer generated invoce and it does not"<<endl;
    			cout << "	 require an authorised signture #"<<endl;
    			cout <<" "<<endl;
    			cout << "	///////////////////////////////////////////////////////////"<<endl;
    			cout << "	You are advised to pay up the amount before due date."<<endl;
    			cout << "	Otherwise penelty fee will be applied"<<endl;
    			cout << "	///////////////////////////////////////////////////////////"<<endl;
                found++;
            }
            read >> S2.cusname >> S2.carname >> S2.carmodel >> S2.carid >> S2.data >> S2.rentPday >>S2.rentalfee;
            
        }
        if (found == 0)
            {
                cout << "\n\t\t\t Car Roll NO. Not Found....";
            }
        read.close();
    }
}


//void DispalyStack()
//{  
////	Reopenqueue();
//	system("cls");
//    cout << "\n------------------------------------------------------------------------------------------------------------" << endl;
//    cout << "------------------------------------- Customer Record Table -----------------------------------------------------" << endl;
//    
//	cout << "=================================================================================================================\n" ;
//	cout << "Cus_Name " << "  \tCar Name  " << "\t" << "Car Model" << "\t"<< "Car ID "<< "\t"  << "     UD(Unique Data)" <<setw(4) <<"   Rent Per Day"<<"  Rent fee"<<"     Days"<< "  |" << endl;
//	cout << "=================================================================================================================\n"; 
//
// int total = 1;
// if (isempty())
//  cout << "\n\t\t\tNo Data is Present... ";
// else
// {
//  Stack *ptr = front;
//  while( ptr !=NULL)
//  {
//  	int days = ptr->rentalfee / ptr->rentPday;
//        	  cout << ptr->cusname<<"\t\t" << setw(5);
//        	  cout << ptr->carname << "\t" << setw(4);
//        	  cout << ptr->carmodel << "\t\t" << setw(4);
//        	  cout << ptr->carid << "\t" << setw(5);
//        	  cout << ptr->data << "\t\t" << setw(4);
//        	  cout << ptr->rentPday << "\t\t" << setw(4);
//        	  cout << ptr->rentalfee << "\t  ";
//        	  cout << days << endl;
//    
//	cout << "------------------------------------------------------------------------------------------------------------\n";  
//    ptr= ptr->next;
//  }
//  
// }
// 
//}

void DispalyStack()
{  
	Stack S1;
    system("cls");
    ifstream read;
    int total = 1;
    cout << "\n-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Customer Record Table -----------------------------------------------------" << endl;
    
	cout << "=================================================================================================================\n" ;
	cout << "Cus_Name " << "  \tCar Name  " << "\t" << "Car Model" << "\t"<< "Car ID "<< "\t"  << "     UD(Unique Data)" <<setw(4) <<"   Rent Per Day"<<"  Rent fee"<<"     Days"<< "  |" << endl;
	cout << "=================================================================================================================\n"; 
	
    read.open("Customer.txt");
    if (!read)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        read.close();
    }else
	{
		read >> S1.cusname >> S1.carname >> S1.carmodel >> S1.carid >> S1.data >> S1.rentPday >>S1.rentalfee;

 		while (!read.eof())
        {	
        	  int days = S1.rentalfee / S1.rentPday;
        	  cout << S1.cusname<<"\t\t" << setw(5);
        	  cout << S1.carname << "\t" << setw(4);
        	  cout << S1.carmodel << "\t\t" << setw(4);
        	  cout << S1.carid << "\t" << setw(5);
        	  cout << S1.data << "\t\t" << setw(4);
        	  cout << S1.rentPday << "\t\t" << setw(4);
        	  cout << S1.rentalfee << "\t  ";
        	  cout << days << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------\n";

			read >> S1.cusname >> S1.carname >> S1.carmodel >> S1.carid >> S1.data >> S1.rentPday >>S1.rentalfee; 
        }
 		
 	  }
        read.close();    
    	
}

void SearchFromStack(){
//	Reopenqueue();
	char Udata;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- CUSTOMER Search Table --------------------------------------------" << endl;
        cout << "\nEnter Unique Data. of Customer which you want to search: ";
        cin >> Udata;
    int found = 0;    
	Stack* CurrNode = front;
	int CurrIndex=1;
	while(CurrNode && CurrNode->data != Udata){
		CurrNode=CurrNode->next;
		CurrIndex++;
	}
	if(CurrNode){
		cout << "\t\t\tCustomer Name: " << CurrNode->cusname << "\n";
        cout << "\t\t\tCar Name: " << CurrNode->carname << "\n";
        cout << "\t\t\tCar Model: " << CurrNode->carmodel << "\n";
        cout << "\t\t\tCar ID: " << CurrNode->carid << "\n";
        cout << "\t\t\tCar UD(Unique Data): " << CurrNode->data << "\n";
        cout << "\t\t\tCar Rent Per Day: " << CurrNode->rentPday << "\n";
        cout << "\t\t\tCar Rental Fee: " << CurrNode->rentalfee << "\n";
        found++;
	}else{
        cout << "\n\t\t\tNo Data is Present... " << endl;
	}
	if (found == 0)
    {
        cout << "\n\t\t\t Customer Roll NO. Not Found....";
    }
          
}



void DeleteStack()
{ 
	system("cls");

    int found = 0;
    char Udata;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete CUSTOMER Details ------------------------------------------" << endl;
    cout << "\nEnter UD(Uniqueue Data) of Customer which you want Delete Data: ";
    cin >> Udata;

	if(isempty()) 
		cout << "\n\t\t\tNo Data is Present.."; 
	else 
	{ 
		ofstream write;
		write.open("temp.txt");
		ifstream read;
		read.open("Customer.txt");

		Stack *ptr = front; 
		while (ptr != NULL && ptr->data != Udata){
			write<<"\n"<<ptr->cusname;
 			write<<"\n"<<ptr->carname;
 			write<<"\n"<<ptr->carmodel;
 			write<<"\n"<<ptr->carid;
			write<<"\n"<<ptr->data;
			write<<"\n"<<ptr->rentPday;
			write<<"\n"<<ptr->rentalfee<<"\n";
			
			ptr = ptr->next; 				
		}
					
		if (ptr == NULL) 
			cout << "\n\t\t\tNo Data is Present..";
		else if (ptr == front) 
		{ 
			front = front->next; 
			
			free(ptr); 
		} 
		else
		{ 
			Stack *temp = front; 
			while (temp->next != ptr) 
				temp = temp->next; 
			temp->next = ptr->next; 
			free(ptr); 
		} 
		//Write the remaining customers in the queue to the file
		ptr = front;
		while (ptr != NULL){
			write<<"\n"<<ptr->cusname;
 			write<<"\n"<<ptr->carname;
 			write<<"\n"<<ptr->carmodel;
 			write<<"\n"<<ptr->carid;
			write<<"\n"<<ptr->data;
			write<<"\n"<<ptr->rentPday;
			write<<"\n"<<ptr->rentalfee<<"\n";
			ptr = ptr->next; 
		}

		read.close();
		write.close();
		remove("Customer.txt");
		rename("temp.txt", "Customer.txt");
	} 
}

//void DeleteStack()
//{
//    system("cls");
//    fstream file, file1;
//    Stack D1;
//    int found = 0;
//    char Udata;
//    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
//    cout << "------------------------------------- Delete Car Details ------------------------------------------" << endl;
//    file.open("Customer.txt", ios::in);
//    if (!file)
//    {
//        cout << "\n\t\t\tNo Data is Present..";
//        file.close();
//    }
//    else
//    {
//        cout << "\nEnter UD(Uniqueue Data) of Customer which you want Delete Data: ";
//        cin >> Udata;
//        file1.open("record.txt", ios::app | ios::out);
//        file >> D1.cusname >> D1.carname >> D1.carmodel >> D1.carid >> D1.data >> D1.rentPday >> D1.rentalfee;
//        while (!file.eof())
//        {
//            if (Udata != D1.data)
//            {
//                file1<<"\n"<<D1.cusname;
// 				file1<<"\n"<<D1.carname;
// 				file1<<"\n"<<D1.carmodel;
// 				file1<<"\n"<<D1.carid;
//				file1<<"\n"<<D1.data;
//				file1<<"\n"<<D1.rentPday;
//				file1<<"\n"<<D1.rentalfee<<"\n";
//            }
//            else
//            {
//                found++;
//                cout << "\n\t\t\tSuccessfully Data Deleted !....";
//            }
//            file >> D1.cusname >> D1.carname >> D1.carmodel >> D1.carid >> D1.data >> D1.rentPday >> D1.rentalfee;
//        }
//        if (found == 0)
//        {
//            cout << "\n\t\t\t Cutomerr UD(Uniqueue Data). Not Found....";
//        }
//        file1.close();
//        file.close();
//        remove("Customer.txt");
//        rename("record.txt", "Customer.txt");
//    }
//  }
  
  void ModifyStack(){
{
    system("cls");
    fstream file, file1;
    Stack m1;
    char mdata;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Customer Modify Details ------------------------------------------" << endl;
    file.open("Customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter UD(Uniqueue Data) of Customer which you want to Modify: ";
        cin >> mdata;
        file1.open("record.txt", ios::app | ios::out);
        file >> m1.cusname >> m1.carname >> m1.carmodel >> m1.carid >> m1.data >> m1.rentPday >> m1.rentalfee;
        while (!file.eof())
        {
            if (mdata != m1.data){
                file1<<"\n"<<m1.cusname;
 				file1<<"\n"<<m1.carname;
 				file1<<"\n"<<m1.carmodel;
 				file1<<"\n"<<m1.carid;
				file1<<"\n"<<m1.data;
				file1<<"\n"<<m1.rentPday;
				file1<<"\n"<<m1.rentalfee<<"\n";
            }else
            {
                cout<<"\t\tEnter Customer Name:- ";
				cin.ignore();
				getline(cin,m1.cusname);
				cout<<"\t\tEnter CAR Name:- ";
				cin.ignore();
				getline(cin,m1.carname);
				cout<<"\t\tEnter Car Model:- ";
				cin.ignore();
				getline(cin,m1.carmodel);
				cout<<"\t\tEnter Car ID:- ";
				cin.ignore();
				getline(cin,m1.carid);
				cout<<"\t\tEnter Car UD(Unique data):- ";
				cin>>m1.data;
				cout<<"\t\tEnter Car Rent per Day:- ";
				cin>>m1.rentPday;
				cout<<"\t\tEnter Car Rental Fee:- ";
				cin>>m1.rentalfee;
                file1<<"\n"<<m1.cusname;
 				file1<<"\n"<<m1.carname;
 				file1<<"\n"<<m1.carmodel;
 				file1<<"\n"<<m1.carid;
				file1<<"\n"<<m1.data;
				file1<<"\n"<<m1.rentPday;
				file1<<"\n"<<m1.rentalfee<<"\n";
                found++;
            }
            file >> m1.cusname >> m1.carname >> m1.carmodel >> m1.carid >> m1.data >> m1.rentPday >> m1.rentalfee;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Customer Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("Customer.txt");
        rename("record.txt", "Customer.txt");
    }
  }	
}
 
};




