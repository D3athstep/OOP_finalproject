#include<iostream>
#include<fstream>
using namespace std;

class Drug
{
	protected:
	string name;
	int id;
	public:
	void getda(string n,int ID)
	{
		name = n;
		id = ID;
	}
	void showda()
	{
		cout << name << endl;
		cout << id << endl;
	}


};


class DataBase : public Drug
{
	int sale_p, purchase_p, profit, TAOD, amount_sale, amount_left,validity_period;
	int manufacture_date, expiery_date;
public:
	void getdata(int saleprice,int purprice,int totaomuntofdrug, int amountsale )
	{
		sale_p = saleprice;
		purchase_p = purprice;
		TAOD = totaomuntofdrug;
		amount_sale = amountsale;
	}
	void showdata()
	{
		cout << sale_p << endl;
		cout << purchase_p << endl;
		cout << TAOD << endl;
		cout << amount_sale << endl;
	}
	void profitcal()
	{
		profit = sale_p - purchase_p;
		cout << profit << endl;
	}
	void leftamount()
	{
		amount_left = TAOD - amount_sale;
		cout << amount_left << endl;
	}
	void Validity()
	{
		if(manufacture_date - expiery_date>0)
		{
			cout << "The product is valid" << endl;
		}
		else
		{
			cout <<"Product is not valid" << endl;
		}
	}
	void inputFromFile(char filename[])
	{
		ifstream f;
		f.open(filename);
		f >> name;
		f >> id;
		f >> sale_p;
		f >> purchase_p;
		f >> manufacture_date;
		f >> expiery_date;
		f >> amount_left;
		f >> amount_sale;
		f >> TAOD;
		cout << name << endl;
		cout << id << endl;
		cout << sale_p << endl;
		cout << purchase_p << endl;
		cout <<  manufacture_date << endl;
		cout << expiery_date << endl;
		cout << amount_left << endl;
		cout << amount_sale << endl;
		cout << TAOD << endl;
		f.close();	
	}
	void writeInFile(char filename[])
	{
		ofstream f;
		f.open(filename);
		f << name;
		f << endl;
		f << id;
		f << endl;
		f << sale_p;
		f << endl;
		f << purchase_p;
		f << endl;
		f << manufacture_date;
		f << endl;
		f << expiery_date;
		f << endl;
		f << amount_left;
		f << endl;
		f << amount_sale;
		f << endl;
		f << TAOD;
	}


};
int main()
{
	cout << "-----------------------------------------------" << endl;
	cout << endl << "        DISPENSARY MANAGEMENT SYSTEM           " << endl;
	cout << "-----------------------------------------------" << endl;
	DataBase D[10];
	int choice;
	int sale,pur,taod,as;
	string name;
	int id;
	int i=0;
	
	while(choice !=7)
	{
	
		
		cout << "want to enter data with file? press 1" << endl;
		cout << "want to enter data manually? press 2" << endl;
		cout << "want to calculate profit? press 3" << endl;
		cout << "want to write data into a file? press 4" << endl;
		cout << "want to check validity? press 5" << endl;
		cout<<"want to display? press 6" << endl;
		cout << "want to exit? press 0" << endl;
		cin >> choice;
		if (choice  == 1)
		{
			char fname[100];
			cout << "enter file name: " << endl;
			cin >> fname;
			D[i].inputFromFile(fname);
		}
		
		else if (choice == 2)
		{
			cout<<"Enter name : " << endl;
			cin>>name;
			cout <<"Enter ID :" << endl;
			cin >> id;
			D[i].getda(name,id);
			cout <<"Enter Sale price :" << endl;
			cin >> sale;
			cout <<"Enter Purchase Price " << endl;
			cin >> pur ;
			cout <<"Enter Total amount of drugs" << endl;
			cin>> taod;
			cout << "Enter Amount sale" << endl;
			cin >> as;
			D[i].getdata(sale,pur,taod,as);
			//enter data into database D[i] with setters....
		}
		else if(choice == 3)
		{
			D[i].profitcal();
		}
		else if(choice == 4)
		{
			char fname[100];
			cout << "enter file name: " << endl;
			cin >> fname;
			D[i].writeInFile(fname);
			cout << "DATA SUCCESSFULLY WRITTEN IN THE FILE!!!" << endl;
		}
		else if (choice == 5)
		{
			D[i].Validity();
		}
		else if(choice == 6)
		{
			D[i].showda();
			D[i].showdata();
		}
		else if ( choice == 0)
		{
			break;
		
		}
		
		}
	return 0;
} 
