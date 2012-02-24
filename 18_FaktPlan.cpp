//З клавіатури ввести послідовність даних з результатами роботи бригади за тиждень:
//<День>, <План>, <Фактичний виробіток>. Роздрукувати введені дані у вигляді таблиці,
//відсортувавши їх у порядку зростання плану. Визначити дні з найвищим і найменшим відсотком виконання плану.  

#include"stdafx.h"
#include<iomanip>
#include<iostream>
using namespace std;
struct Brugada 
{
	char days[10];	//день тижня
	double plan;	// планували випустии продукції
	double fact;	// насправді зробили
};

void sort_Plan(Brugada *p, int n);	//сортуємо дані у порядку зростання плану

int main()
{ 
int n;
cout<<" \n VVeditj kiljkistj dniv: ";
cin>>n;
Brugada *x=new Brugada[n]; 		// динамічно створюємо масив структур
cout<<"Enter day, planned output, actual output : \n";
for(int i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>x[i].days>>x[i].plan>>x[i].fact;
}
sort_Plan(x,n);			// сортуємо методом бульбашки
int nmax=0, nmin=0;
double max=(x[0].fact/x[0].plan)*100, min=max;	
for(int i=1;i<n;i++)		 // визначаємо найменший і найбільший відсоток виконання плану
{ 
	double temp=(x[i].fact/x[i].plan)*100;
	if(temp>max) {max=temp; nmax=i;}
	if(temp<min) {min=temp; nmin=i;}
}
cout.setf(ios::left, ios::fixed);	//виводимо у вигляді таблиці
cout<<setw(10)<<"\n\n          Day     Planned      Actual"<<endl;
for(int i=0;i<n;i++)
	cout<<i+1<<". "<<setw(10)<<x[i].days<<setw(10)<<x[i].plan<<setw(10)<<x[i].fact<<endl;
cout<<" \n Max % plan execution:  "<<x[nmax].days<<"  "<<x[nmax].plan<<"  "<<x[nmax].fact<<endl;
cout<<" \n Min % plan execution: "<<x[nmin].days<<"  "<<x[nmin].plan<<"  "<<x[nmin].fact<<endl;
delete[]x;		// звільнення ДП
system("pause");
return 0;
}

void sort_Plan(Brugada *p,int n)	// сортування бульбашкою
{
int i,j;
Brugada y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if((p+j)->plan>(p+j+1)->plan)	
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}

