//#include <iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomanip>
using namespace std;

struct V_Node
{
string carID;
string carName;
int perdayrent;
string carmodel;
char data;

V_Node *next;
};

class CQueue{
	
public:	

V_Node *front;
V_Node *rear;
CQueue(){
	front=NULL;
	rear=NULL;	
}
void Reopenqueue(){
    V_Node* temp = front;	
	ifstream read("Car.txt");
	if(read.is_open()){		
		while(!read.eof()){
			V_Node* ptr = new V_Node;
			read>>ptr->carID;
			read>>ptr->carName;
			read>>ptr->perdayrent;
			read>>ptr->carmodel;
			read>>ptr->data;
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

//Function to check if queue is empty or not
bool isempty()
{
 if(front == NULL && rear == NULL)
 	return true;
 else
 	return false;
}
//function to enter elements in queue
void Enqueue (string car_id,string crname, double dayrent, string mdl, char Data)
{
//  	Reopenqueue();
 V_Node *ptr = new V_Node();
 ptr->carID= car_id;
 ptr->carName= crname;
 ptr->perdayrent= dayrent;
 ptr->carmodel = mdl;
 ptr->data = Data;
 ptr->next = NULL;
 
 ofstream file;
 file.open("Car.txt", ios::app | ios::out);
 file<<"\n"<<ptr->carID;
 file<<"\n"<<ptr->carName;
 file<<"\n"<<ptr->perdayrent;
 file<<"\n"<<ptr->carmodel;
 file<<"\n"<<ptr->data<<"\n";

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
 cout<<"\n\n----->>>Succesfully New Car Inserted<<<-------\n\n"; 
 file.close(); 
}

void dequeue(char ch)
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
		read.open("Car.txt");

		V_Node *ptr = front; 
		while (ptr != NULL && ptr->data != ch ){
			write<<"\n"<<ptr->carID;
			write<<"\n"<<ptr->carName;
			write<<"\n"<<ptr->perdayrent;
			write<<"\n"<<ptr->carmodel;
			write<<"\n"<<ptr->data<<"\n";
			
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
			V_Node *temp = front; 
			while (temp->next != ptr) 
				temp = temp->next; 
			temp->next = ptr->next; 
			free(ptr); 
		} 
		//Write the remaining cars in the queue to the file
		ptr = front;
		while (ptr != NULL){
			write<<"\n"<<ptr->carID;
			write<<"\n"<<ptr->carName;
			write<<"\n"<<ptr->perdayrent;
			write<<"\n"<<ptr->carmodel;
			write<<"\n"<<ptr->data<<"\n";
			ptr = ptr->next; 
		}

		read.close();
		write.close();
		remove("Car.txt");
		rename("temp.txt", "Car.txt");
	} 
}


//void dequeue(char ch)
//{
//    system("cls");
//    fstream file, file1;
//    V_Node D1;
//    int found = 0;
////    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
////    cout << "------------------------------------- Delete Car Details ------------------------------------------" << endl;
//    file.open("Car.txt", ios::in);
//    if (!file)
//    {
//        cout << "\n\t\t\tNo Data is Present..";
//        file.close();
//    }
//    else
//    {
////        cout << "\nEnter UD(Uniqueue Data) of Car which you want Delete Data: ";
////        cin >> Udata;
//        file1.open("record.txt", ios::app | ios::out);
//        file >> D1.carID >> D1.carName >> D1.perdayrent >> D1.carmodel >> D1.data;
//        while (!file.eof())
//        {
//            if (ch != D1.data)
//            {
//                file1<<"\n"<<D1.carID ;
// 				file1<<"\n"<<D1.carName;
// 				file1<<"\n"<<D1.perdayrent;
// 				file1<<"\n"<<D1.carmodel;
// 				file1<<"\n"<<D1.data<<"\n";
//            }
//            else
//            {
//                found++;
//                cout << "\n\t\t\tSuccessfully Data Deleted";
//            }
//            file >> D1.carID >> D1.carName >> D1.perdayrent >> D1.carmodel >> D1.data;
//        }
//        if (found == 0)
//        {
//            cout << "\n\t\t\t Car UD(Uniqueue Data). Not Found....";
//        }
//        file1.close();
//        file.close();
//        remove("Car.txt");
//        rename("record.txt", "Car.txt");
//    }
//  }

void DisplayQueueNW()
{  
//	Reopenqueue();
	system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Car Record Table -----------------------------------------------------" << endl;
    
	cout << "============================================================================================================\n" ;
	cout << "Car_RNo " << " " << "    Car ID  " << "\t\t" << "    Car Name" << "\t"<< "    Rent Per Day "  << "\tCar Model"<< "\t"  << " UD(Unique Data)" <<setw(4) << "|" << endl;
	cout << "============================================================================================================\n"; 

 int total = 1;
 if (isempty())
  cout<<"Queue is empty\n";
 else
 {
  V_Node *ptr = front;
  while( ptr !=NULL)
  {
  	cout << total++ <<setw(18);
    cout << ptr->carID<<"\t\t" << setw(13);
    cout << ptr->carName << "\t" << setw(12);
    cout << ptr->perdayrent << "\t" << setw(12);
    cout << ptr->carmodel << "\t" << setw(12);
    cout << ptr->data << endl;
    
	cout << "------------------------------------------------------------------------------------------------------------\n";  
    ptr= ptr->next;
  }
  
 }
 
}


void SearchFromQueue(){
//	Reopenqueue();
	char Udata;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Car Search Table --------------------------------------------" << endl;
        cout << "\nEnter Unique Data. of Car which you want to search: ";
        cin >> Udata;
    int found = 0;    
	V_Node* CurrNode = front;
	int CurrIndex=1;
	while(CurrNode && CurrNode->data != Udata){
		CurrNode=CurrNode->next;
		CurrIndex++;
	}
	if(CurrNode){
		cout << "\t\t\tCar ID: " << CurrNode->carID << "\n";
        cout << "\t\t\tCar Name: " << CurrNode->carName << "\n";
        cout << "\t\t\tRent Per Day: " << CurrNode->perdayrent << "\n";
        cout << "\t\t\tCar Model: " << CurrNode->carmodel << "\n";
        cout << "\t\t\tCar UD(Unique Data): " << CurrNode->data << "\n";
        found++;
	}else{
        cout << "\n\t\t\tNo Data is Present... " << endl;
	}
	if (found == 0)
    {
        cout << "\n\t\t\t Car Roll NO. Not Found....";
    }
          
}



//void SearchFromQueue(){
////	Reopenqueue();
//	V_Node S1;
//	system("cls");
//    fstream file;
//    int found = 0;
//    file.open("Car.txt", ios::in);
//    if (!file)
//    {
//        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
//        cout << "------------------------------------- Car Search Data -----------------------------------------------" << endl;
//        cout << "\n\t\t\tNo Data is Present... " << endl;
//    }
//    else
//    {
//        char Udata;
//        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
//        cout << "------------------------------------- Car Search Table --------------------------------------------" << endl;
//        cout << "\nEnter Unique Data. of Car which you want to search: ";
//        cin >> Udata;
//        file >> S1.carID >> S1.carName >> S1.perdayrent >> S1.carmodel >> S1.data;
//        while (!file.eof())
//        {
//            if (Udata == S1.data)
//            {
//                cout << "\t\t\tCar ID: " << S1.carID << "\n";
//            	cout << "\t\t\tCar Name: " << S1.carName << "\n";
//            	cout << "\t\t\tRent Per Day: " << S1.perdayrent << "\n";
//            	cout << "\t\t\tCar Model: " << S1.carmodel << "\n";
//            	cout << "\t\t\tCar UD(Unique Data): " << S1.data << "\n";
//                found++;
//            }
//            file >> S1.carID >> S1.carName >> S1.perdayrent >> S1.carmodel >> S1.data;
//            
//        }
//        if (found == 0)
//            {
//                cout << "\n\t\t\t Car Roll NO. Not Found....";
//            }
//        file.close();
//    }
//}


void DeleteQueue()
{ 
	system("cls");

    int found = 0;
    char Udata;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Car Details ------------------------------------------" << endl;
    cout << "\nEnter UD(Uniqueue Data) of Car which you want Delete Data: ";
    cin >> Udata;

	if(isempty()) 
		cout << "\n\t\t\tNo Data is Present.."; 
	else 
	{ 
		ofstream write;
		write.open("temp.txt");
		ifstream read;
		read.open("Car.txt");

		V_Node *ptr = front; 
		while (ptr != NULL && ptr->data != Udata){
			write<<"\n"<<ptr->carID;
			write<<"\n"<<ptr->carName;
			write<<"\n"<<ptr->perdayrent;
			write<<"\n"<<ptr->carmodel;
			write<<"\n"<<ptr->data<<"\n";
			
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
			V_Node *temp = front; 
			while (temp->next != ptr) 
				temp = temp->next; 
			temp->next = ptr->next; 
			free(ptr); 
		} 
		//Write the remaining cars in the queue to the file
		ptr = front;
		while (ptr != NULL){
			write<<"\n"<<ptr->carID;
			write<<"\n"<<ptr->carName;
			write<<"\n"<<ptr->perdayrent;
			write<<"\n"<<ptr->carmodel;
			write<<"\n"<<ptr->data<<"\n";
			ptr = ptr->next; 
		}

		read.close();
		write.close();
		remove("Car.txt");
		rename("temp.txt", "Car.txt");
	} 
}
 
   
void ModifyQueue(){
{
    system("cls");
    fstream file, file1;
    V_Node m1;
    char mdata;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Car Modify Details ------------------------------------------" << endl;
    file.open("Car.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter UD(Uniqueue Data) of Car which you want to Modify: ";
        cin >> mdata;
        file1.open("record.txt", ios::app | ios::out);
        file >> m1.carID >> m1.carName >> m1.perdayrent >> m1.carmodel >> m1.data;
        while (!file.eof())
        {
            if (mdata != m1.data){
                file1<<"\n"<<m1.carID ;
 				file1<<"\n"<<m1.carName;
 				file1<<"\n"<<m1.perdayrent;
 				file1<<"\n"<<m1.carmodel;
 				file1<<"\n"<<m1.data<<"\n";
            }else
            {
                cout<<"\t\tEnter CAR ID:- ";
				cin.ignore();
				getline(cin,m1.carID);
				cout<<"\t\tEnter CAR Name:- ";
				cin.ignore();
				getline(cin,m1.carName);
				cout<<"\t\tEnter CAR Rent per Day:- ";
				cin>>m1.perdayrent; 
				cout<<"\t\tEnter Car Model:- ";
				cin.ignore();
				getline(cin,m1.carmodel);
				cout<<"\t\tEnter Car UD(Unique data):- ";
				cin>>m1.data;
                file1<<"\n"<<m1.carID ;
 				file1<<"\n"<<m1.carName;
 				file1<<"\n"<<m1.perdayrent;
 				file1<<"\n"<<m1.carmodel;
 				file1<<"\n"<<m1.data<<"\n";
                found++;
            }
            file >> m1.carID >> m1.carName >> m1.perdayrent >> m1.carmodel >> m1.data;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Car Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("Car.txt");
        rename("record.txt", "Car.txt");
    }
  }	
}
};






