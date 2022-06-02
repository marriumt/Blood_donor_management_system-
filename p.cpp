#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
void search();
void insert();
void search_list();
void deleted();
void update();
struct donor{
string name;
string phone;
string blood_group;
string ID;
string Address;
string last_date_donation;
string donation_count;
};
donor a;
	
int main()
	{
		
		int ch;
		char x,y;
		while(y!='y'||y!='Y')
		{
		system("cls");
		cout<<"\t\t\t----------------------------------------"<<endl;
		cout<<"\t\t\t | BLOOD DONOR MANAGEMENT SYSTEM |"<<endl;
		cout<<"\t\t\t----------------------------------------"<<endl;
		cout<<"\t\t\t 1. Add donor's record"<<endl;
		cout<<"\t\t\t 2. Search the donor's record based on name"<<endl;
		cout<<"\t\t\t 3. Search a list of donors based on blood group"<<endl;
		cout<<"\t\t\t 4. Update the donor's record after successful donation"<<endl;
		cout<<"\t\t\t 5. Remove donor's record"<<endl;
		cout<<"\t\t\t 6. Exit"<<endl;
		cout<<"\t\t\t----------------------------------------"<<endl;
		cout<<"\t\t\t Choose option :[1,2,3,4,5,6]"<<endl;
		cout<<"\t\t\t----------------------------------------"<<endl;
		cout<<"Enter number for desired operation: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			do
			{
				insert();
				cout<<endl<<"Add another donor record (Y/N): ";
				cin>>x;
			}
				while(x=='y'||x=='Y');
				break;
			
			case 2:
				do
			{
				search();
				cout<<endl<<"Do you want to Search by name again (Y/N)? ";
				cin>>x;
			}
				while(x=='y'||x=='Y');
				break;
			case 3:
				do
			{
				search_list();
				cout<<endl<<"Do you want to Search by Blood group again (Y/N)? ";
				cin>>x;
			}
				while(x=='y'||x=='Y');
				break;
			case 4:
				do
			{
				update();
				cout<<endl<<"Do you want to Update again (Y/N): ";
				cin>>x;
			}
				while(x=='y'||x=='Y');
				break;
			case 5:
					do
			{
				deleted();
				cout<<endl<<"Do you want to Delete again (Y/N): ";
				cin>>x;
			}
				while(x=='y'||x=='Y');
				break;
			break;
			case 6:
			exit(0);
			break;
			default:
			cout<<"\t\t\t Invalid choice";
		}
	}
   }
	void insert()
	{
		donor a;
	system("cls");
	fstream file;
	cout<<"\n---------------------------------------------";
	cout<<endl<<"------------Enter Donor  Record----------"<<endl;
	cout<<"Enter donor's name : ";
	cin>>a.name;
	cout<<"Enter donor's phone number : ";
	cin>>a.phone;
	cout<<"Enter donor's blood group : ";
	cin>>a.blood_group;
	cout<<"Enter donor's ID : ";
	cin>>a.ID;
	cout<<"Enter donor's Address : ";
	cin>>a.Address;
	cout<<"Enter the number of times the donor donated : ";
	cin>>a.donation_count;
	cout<<"Enter donor's last date of donation : ";
	cin>>a.last_date_donation;
	file.open("bds_donor_data.txt",ios::app | ios::out);
	file<<a.name<<endl<<a.phone<<endl<<a.blood_group<<endl<<a.ID<<endl<<a.Address<<endl<<a.donation_count<<endl<<a.last_date_donation<<endl;
	file.close();
 }
 void search()
 {
 	system("cls");
	fstream file;
	int found=0;
	file.open("bds_donor_data.txt",ios::in);
	if(!file)
	{
		cout<<"----------No data is present---------";
	}
	else
	{
	string n;
	cout<<"\t\t---------------------------------------------";
	cout<<endl<<"------------Enter the name of the donor whose record you want to search----------"<<endl;
	cin>>n;
	file>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
	while(!file.eof())
	{
		if(n==a.name)
		{
			cout<<"\t\t\tName : "<<a.name<<endl;
			cout<<"\t\t\tPhone number : "<<a.phone<<endl;
			cout<<"\t\t\tBlood group : "<<a.blood_group<<endl;
			cout<<"\t\t\t Donor ID: "<<a.ID<<endl;
			cout<<"\t\t\tAddress: "<<a.Address<<endl;
			cout<<"\t\t\tSuccessful donations: "<<a.donation_count<<endl;
			cout<<"\t\t\tLast date of donation : "<<a.last_date_donation<<endl<<endl<<endl;
		
			found++;
	
			
	}
	file>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
		}
		if(found==0)
		{
			cout<<"Donor name is not found "<<endl;
		}
		file.close();
 }
}

 void search_list()
 {
 	system("cls");
	fstream file;
	int found=0;
	file.open("bds_donor_data.txt",ios::in);
	if(!file)
	{
		cout<<"----------No data is present---------";
		file.close();
	}
	else
	{
	string n;
	cout<<"\t\t---------------------------------------------";
	cout<<endl<<"------------Enter blood group of the donor whose record you want to search----------"<<endl;
	cin>>n;
	file>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
	while(!file.eof())
	{
		if(n==a.blood_group)
		{
			cout<<"\t\t\tName : "<<a.name<<endl;
			cout<<"\t\t\tPhone number : "<<a.phone<<endl;
			cout<<"\t\t\tBlood group : "<<a.blood_group<<endl;
			cout<<"\t\t\t Donor ID: "<<a.ID<<endl;
			cout<<"\t\t\tAddress: "<<a.Address<<endl;
			cout<<"\t\t\tSuccessful donations: "<<a.donation_count<<endl;
			cout<<"\t\t\tLast date of donation : "<<a.last_date_donation<<endl<<endl<<endl;
		
			found++;
	
			
	}
	file>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
		}
		if(found==0)
		{
			cout<<"Donor's blood group is not found "<<endl;
		}
		file.close();
 }
}

 void update()
 {
	ifstream file1;
	ofstream file;
	file1.open("bds_donor_data.txt");
	file.open("updated.txt",ios::app);
	

	string n;
	cout<<endl<<"------------Enter donor's ID whose record you want to update'----------"<<endl;
	cin>>n;
//	file1>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
	while(!file1.eof())
	{
			file1>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
			if(n!=a.ID)
			{
			file<<a.name<<endl<<a.phone<<endl<<a.blood_group<<endl<<a.ID<<endl<<a.Address<<endl<<a.donation_count<<endl<<a.last_date_donation<<endl;
			}
			
		else if(n==a.ID)
		{
			cout<<endl<<"\t\t\t Enter Name : ";
			cin.ignore();
			cin>>a.name;
			cout<<endl<<"\t\t\t Enter Phone number : ";
			cin>>a.phone;
			cout<<endl<<"\t\t\tEnter Blood group : ";
			cin>>a.blood_group;
			cout<<endl<<"\t\t\t Enter Donor's ID: ";
			cin>>a.ID;
			cout<<endl<<"\t\t\tEnter Address: ";
			cin>>a.Address;
			cout<<endl<<"\t\t\tEnter Successful donations: ";
			cin>>a.donation_count;
			cout<<endl<<"\t\t\tEnter Last date of donation : ";
			cin>>a.last_date_donation;
			cout<<endl<<endl<<endl;
 	file<<a.name<<endl<<a.phone<<endl<<a.blood_group<<endl<<a.ID<<endl<<a.Address<<endl<<a.donation_count<<endl<<a.last_date_donation<<endl;
	
	}
		
	}
		file1.close();file.close();
		remove("bds_donor_data.txt");
		rename("updated.txt","bds_donor_data.txt");
				cout<<"UPDATED SUCCESSFULLY";
	
}
void deleted()
{
	
	ofstream file;
	string n;
	cout<<endl<<"------------Enter donor's ID whose record you want to delete----------"<<endl;
	cin>>n;
	ifstream file1;
	file1.open("bds_donor_data.txt");
	file.open("deleted.txt",ios::app);
	while(!file1.eof())
	{
		file1>>a.name>>a.phone>>a.blood_group>>a.ID>>a.Address>>a.donation_count>>a.last_date_donation;
		if(n!=a.ID)
		{
		file<<a.name<<endl<<a.phone<<endl<<a.blood_group<<endl<<a.ID<<endl<<a.Address<<endl<<a.donation_count<<endl<<a.last_date_donation<<endl;
		}
		
	}
	file1.close();
	file.close();
	remove("bds_donor_data.txt");
	rename("deleted.txt","bds_donor_data.txt");
	cout<<"Deleted successfully";
}
