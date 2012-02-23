// vokal_kolektuv.cpp : Defines the entry point for the console application.
//

//17.	� ��������� ������ ����������� ����� ��� ������� ��������� ������: <����� ���������>, <г� ���������>,
//<ʳ������ ��������>, <�������>. ������������ ������ ��� � ������ �������, 
//������������ �� �� ������� ��������� � ���������� �������. 
//���������� ����� ������� � ������ 3 ��������� � ��������� ����� ��� ������� ���������.  
#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct Kolektiv   //��� ���������� ���������� ��� ��������� ��������
{
	char name[20];
	int year;
	int amount;
	char lead[10];
};


void sort_Name(Kolektiv *p, int n);		// ����� ��������� �� ������ � ���������� �������

int main()
{ 
int n;
cout<<" Enter a number of  vocal groups: ";
cin>>n;
Kolektiv *x=new Kolektiv[n];
cout<<"Enter information about them(Name, Year of foundation, number of members, leader name):  \n";
for(int i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>x[i].name>>x[i].year>>x[i].amount>>x[i].lead;
}
// ������ 3 �������������� �����, �� �� ������������(������� - �� 0 �� �-�� ���������)
srand(time(NULL));
int temp[3], k, i, j;
bool present;
for (i = 0; i < 3; i++ ) {
 temp[i] = -1;
 do {
 present = 0;
 k = rand() % n;
 for ( j = 0; j < i; j++ ) {
 if ( temp[j] == k ) present = 1;
 }
 } while ( present );
 temp[i] = k;
 cout<<temp[i]+1<<" ";
}
//������ �������� � ������������ ������� �������� � 3 ������������ ����������
int max=x[temp[0]].amount, imax=0;
for(i=1; i<3; i++){
	int t=temp[i];
	if(x[t].amount>max) {max=x[t].amount; imax=t;}
}
cout<<"The most numerous group: "<<x[imax].name<<" "<<x[imax].year<<" "<<x[imax].amount<<" "<<x[imax].lead;
sort_Name(x, n);
cout.setf(ios::left, ios::fixed);
cout<<setw(10)<<"\n\nName    Year of foundation   Number of members   Leader name"<<endl;
for(int i=0;i<n;i++)
	cout<<setw(10)<<x[i].name<<setw(10)<<x[i].year<<setw(15)<<x[i].amount<<setw(15)<<x[i].lead<<endl;

delete[]x;
system("pause");
return 0;
}
// ����� ��������� �� ������ � ���������� �������
void sort_Name(Kolektiv *p, int n)
{
int i,j;
Kolektiv y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if(strcmp((p+j)->name,(p+j+1)->name)>0)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}

