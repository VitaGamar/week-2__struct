// perumetr_truk.cpp : Defines the entry point for the console application.
//З клавіатури ввести послідовність даних, які містять координати вершин трикутників.  
//Роздрукувати введені дані у вигляді таблиці, відсортувавши їх у порядку спадання величин 
//периметрів цих трикутників. Визначити відсоток трикутників, периметр яких перевищує мінімальний  
//периметр більше, ніж у 2 рази. 

#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>

using namespace std;
struct Point{	//координати однієї вершини
	double x, y;
};
struct Triangle 	// сруктура з 3ох точок, які утворюють трикутник та його периметр
{
	Point a,b,c;
	double perim;
};
double len(Point p1, Point p2)  // функція, яка знаходить довжину відрізка за 2ма точками
{
	double y,z;
	y=(p2.x-p1.x);
	z=(p2.y-p1.y);
	return sqrt(pow(y,2)+pow(z,2));
}

void sort_Per(Triangle *p, int n);	// сортуємо масив за спаданням периметрів трикуників

int main()
{ 
int n, k=0;
double min=0;
cout<<" Enter number of triangle : ";
cin>>n;
Triangle *x=new Triangle[n];		//динамічно створюємо масив структур
cout<<"Enter coordinates of 3 points:  \n";
for(int i=0;i<n;i++)		// ввід точок
{ 
	cout<<i+1<<". ";
	cout<<"Enter first point: "; cin>>x[i].a.x>>x[i].a.y;
	cout<<"Enter second point: "; cin>>x[i].b.x>>x[i].b.y;
	cout<<"Enter third point: "; cin>>x[i].c.x>>x[i].c.y;
	x[i].perim=len(x[i].a, x[i].b)+len(x[i].b, x[i].c)+len(x[i].c, x[i].a);	// обчислення периметру
}
min=x[0].perim;
for(int i=1;i<n;i++)  // знаходимо мінімальний периметр
	min=(x[i].perim<min)? x[i].perim:min;
for(int i=0;i<n;i++)
	if (2*(x[i].perim)>min) k++;	// відсоток трикутників периметр яких перевижує мінімальний більше ніж в 2 рази
min=(double)k/n;
sort_Per(x, n);

cout.setf(ios::left, ios::fixed);		// вивід точок та периметрів
cout<<setw(10)<<"\n\n           Points               Perimetr"<<endl;
for(int i=0;i<n;i++)
	cout<<"\n ("<<x[i].a.x<<","<<x[i].a.y<<") , "<<"("<<x[i].b.x<<","<<x[i].b.y<<") , "<<"("<<x[i].c.x<<","<<x[i].c.y<<")  "<<setw(15)<<x[i].perim<<endl;
cout<<" Min perimetr: "<<min<<"\n percentage of triangles, perimeter greater than the minimum perimeter of more than 2 times: "<<min*100<<"%";
delete[]x;		// звільняємо ДП
system("pause");
return 0;
}

void sort_Per(Triangle *p, int n)  		// сортуємо методом бульбашки
{
int i,j;
Triangle y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if((p+j)->perim<(p+j+1)->perim)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}

