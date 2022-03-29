#include<iostream>
#include<iomanip>
#include<string> 
using namespace std;
struct date 
{
		int ngay;
	 	int thang;
		int nam ; 	
		date()
		{
			(ngay,thang,nam)=0;
		}	
		~date()
		{
			;
		}
};
class KH
{
	private :
	char ht [30];
	date NS ;
 	char cmt [10];
	char hk [50]; 
	public:
	void Nhap();
	void xuat();
	void Nhap_ds(KH a[], int &n);
	void xuat_ds(KH a[], int n);
	void sxep(KH a[], int &n);
	void T12(KH a[] , int n );
		 
};
	void KH ::Nhap ()
	{
			cin.ignore(); 
		cout<<"	1.Nhap ho va ten cua khach hang : "; cin.getline(ht,30);
		cout<<"	3.Nhap chung minh thu : "; cin.getline(cmt,10);
		cout<<"	4.Nhap ho khau : "; cin.getline(hk,50); 
		cout<<"	2.Nhap ngay , thang , nam sinh :"<<endl; 
		cout<<"		Nhap ngay sinh : "; cin >>NS.ngay;
		cout<<"		Nhap thang sinh : "; cin >>NS.thang;
		cout<<"		Nhap nam sinh : "; cin >>NS.nam;
	}
	void KH::xuat ()
	{
		cout<<setw(20)<<"|"<<setw(20)<<ht<<"|"<<setw(2)<<NS.ngay<<"/"<<setw(2)<<NS.thang<<"/"<<setw(4)<<NS.nam<<"|";
		cout<<setw(10)<<cmt<<"|"<<setw(20)<<hk<<"|"<<endl; 
	}
	void KH ::Nhap_ds(KH a[] , int &n )
	{
		for(int i = 0 ; i <n ; i++)
		{
			cout <<"			Nhap thong tin khach hang thu "<<i+1<<endl; 
			a[i].Nhap(); 
		}
	}
	void tieu_de ()
 	{
 		cout<<"		   |---------------------------------------------------------------|"<<endl; 
		cout<<setw(20)<<"|"<<setw(20)<<"Ho ten "<<"|"<<setw(10)<<"Ngay sinh "<<"|";
		cout<<setw(10)<<"CMT "<<"|"<<setw(20)<<"Ho khau "<<"|"<<endl;
		cout<<"		   |---------------------------------------------------------------|"<<endl; 
	}
	void KH:: xuat_ds(KH a[] , int n)
	{
		tieu_de(); 
		for (int i =0 ; i<n ; i++)
		{ 
			a[i].xuat(); 
		}
		cout<<"		   |---------------------------------------------------------------|"<<endl; 
	}
	void KH ::sxep(KH a[], int &n)
	{
		for (int i = 0 ; i <n-1 ; i++)
		{
			for (int j = i+1 ; j <n ; j++) 
				if (strcmpi(a[i].ht,a[j].ht)>0)
				{
					KH tg = a[i];
					a[i]=a[j];
					a[j]=tg;
				}
		} 
	} 
	void KH ::T12(KH a[], int n)
	{
		cout <<"	Khach hang co thang sinh la 12 "<<endl; 
		int d =0;
		for(int i=0;i<n;i++)
		{
			if(a[i].NS.thang==12)
			{
			 	d++;
				if(d == 1)
				tieu_de();
				a[i].xuat(); 
				cout<<"		   |---------------------------------------------------------------|"<<endl; 
			}
		}
		if(d ==0)
		cout<<"		KHONG CO KHACH HANG NAO CO THANG SINH BANG 12"<<endl; 
}
		
int main ()
{
	int n ;
	cout <<"	Nhap so luong khach hang :"; cin >>n ;
	KH a[n];
	a[n].Nhap_ds(a,n);
	cout <<endl; 
	cout <<"Danh sach khach hang "<<endl; 
	a[n].sxep(a,n);
	a[n].xuat_ds(a,n);
	a[n].T12(a,n); 
}
