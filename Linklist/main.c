#include<iostream>
#include<string>
using namespace std;
void myPrlong long(long long num,long long a,long long b){
	if(b==0){
		cout<<"Inf";
		return;
	}
	if(b<0&&a>0){
		b = -b;
		a = -a;
	}
	if(num<0||a<0)
		cout<<"(";
	if(num!=0){
		cout<<num;
		if(a!=0)
			cout<<" ";
	}
	if(a!=0)
		cout<<a<<"/"<<b;
	if(num==0&&a==0)
		cout<<"0";
	if(num<0||a<0)
		cout<<")";		
}
void simplify(long long &num,long long &a,long long &b){
	if(b==0)
		return;
	long long temp = -1;
	long long t1 = a,t2 = b;
	if(a<0)
		t1 = -a;
	if(b<0)
		t2 = -b;
	num = a / b;
	if(num<0)
		a = -a;
	a %= b;
	long long min = t1<t2?t1:t2;
	for(long long i=2;i<=min;i++) {
		if(a%i==0&&b%i==0)
			temp = i;
	}
	if(temp!=-1){
		a /= temp;
		b /= temp;
	}
}
void addition(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * b2 + a2 * b1;
	long long mother = b1 * b2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrlong long(num1,a1,b1);
	cout<<" + ";
	myPrlong long(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrlong long(num,child,mother);
	cout<<endl;
}
void subtraction(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * b2 - a2 * b1;
	long long mother = b1 * b2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrlong long(num1,a1,b1);
	cout<<" - ";
	myPrlong long(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrlong long(num,child,mother);
	cout<<endl;
}
void mutiply(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * a2;
	long long mother = b1 * b2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrlong long(num1,a1,b1);
	cout<<" * ";
	myPrlong long(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrlong long(num,child,mother);
	cout<<endl;
}
long long division(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * b2;
	long long mother = b1 * a2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrlong long(num1,a1,b1);
	cout<<" / ";
	myPrlong long(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrlong long(num,child,mother);
	cout<<endl;
}
int main(){
	long long a1,b1,a2,b2;
	scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
	addition(a1,b1,a2,b2);
	subtraction(a1,b1,a2,b2);
	mutiply(a1,b1,a2,b2);
	division(a1,b1,a2,b2);
}