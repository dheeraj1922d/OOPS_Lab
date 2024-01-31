#include<iostream>
using namespace std;
#include<cmath>
#include<typeinfo>

double power(double m , int n=2){
	cout<<"result with double base and int exponent:";
	return pow( m , n);
}

double power(int m , int n=2){
	cout<<"result with int base and int exponent:";
	return pow( static_cast<double>(m) , n );
}

int main(){
	//perfoning function with double base and int power
	int expo;
	double base;
	
	//take the inputs from the user 
	cout<<"Enter the base"<<endl;
	cin>>base;
	cout<<"Enter The Exponent"<<endl;
	cin>> expo;
	
	cout<<power( base , expo)<<endl;
	
	//performing function with int base and int exponent
	
	cout<<(power( int(base) , expo ))<<endl;
	
	return 0;
	
}
