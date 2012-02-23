// tests.cpp : Defines the entry point for the console application.
//
//14.	� ��������� ������ ����������� ������, �� ������ ��� ��� ������������ ���������� �������: 
//<�������>, <4 ������� ��������>, <����� ��������� ������>. �������� �����. 
//���������� ����� �������� � ������ �������� ����� 5 ������ (����� ��� �� ������� ���� ���������),
//�� ������� � ���� ������ ������� ������ �������. ������� ����������� ����� ������ � � ������� ������� ������� ����� ������. 
#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

struct test   //��� ���������� ���������� ��� �����
{
	string que;
	string ans[4];
	int right;
};

int main()
{ 
int n;
cout<<" Enter a number of  questions: ";
cin>>n;
test *x=new test[n];

for(int i=0;i<n;i++)
{ 
	cout<<"Enter your question:  \n";
	cout<<i+1<<". ";
	cin>>x[i].que;
	cout<<"Enter 4 possible answers:  \n";
	for(int j=0; j<4; j++){
		cout<<"\t"<<j+1<<")";
		cin>>x[i].ans[j];}
	cout<<"Enter the right answer(1/2): ";
	cin>>x[i].right;
}
//system("cls");
// ������ 5 ���������������� �����, �� �� ������������(������� - �� 0 �� �-�� ��������)
srand(time(NULL));
int temp[5], k, i, j;
bool present;
for (i = 0; i < 5; i++ ) {
 temp[i] = -1;
 do {
 present = 0;
 k = rand() % n;
 for ( j = 0; j < i; j++ ) {
 if ( temp[j] == k ) present = 1;
 }
 } while ( present );
 temp[i] = k;
 //cout<<temp[i]+1<<" ";
}
// ������� �����������
int a;
for(i=0; i<5; i++){
	int t=temp[i];
	cout<<"\n"<<i+1<<". "<<x[t].que<<endl;
	for(int j=0; j<4; j++){
		cout<<"\t"<<j+1<<")"<<x[t].ans[j];
	}
	cout<<"\nYour answer is: ";
	cin>>a;
	if(a==x[t].right) cout<<"Ok! You're right!";
	else cout<<"Not good. The right answer is "<<x[t].right;
}
delete[]x;
system("pause");
return 0;
}

