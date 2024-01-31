#include<iostream>
using namespace std;

class DB;
class DM{
	public:
		float centimeter;
		float meter;
		
		//constructor
		DM(float centi , float meter){
			this->centimeter =  centi;
			this->meter = meter ;
		}
		
		void read(){
			cout<<"Distance in centimeter"<<this->centimeter<<endl;
			cout<<"Distance in meter"<<this->meter<<endl;	
		}
		
		// Friend function for addition
    	friend DM addDistances(const DM&, const DB&);
};

class DB{
	public:
		float feet ;
		float inches;
		
		//constructor
		DB(float feet ,float inches){
			this->feet =feet;
			this->inches = inches;
		}
	
		void read(){
			cout<<"Distance in feet"<<this->feet<<endl;
			cout<<"Distance in inches"<<this->inches<<endl;	
		}
		
		// Friend function for addition
    	friend DM addDistances(const DM&, const DB&);
};



// Friend function definition
DM addDistances(const DM& d1, const DB& d2) {
    DM result( 0 , 0.0);

    // Convert DB to DM
    float totalCentimeters = (d2.feet * 30.48) + (d2.inches * 2.54);
    
    // Add DM and converted DB 
    result.meter = d1.meter + static_cast<int>(totalCentimeters / 100);
    result.centimeter = totalCentimeters - (result.meter * 100);

    return result;
}


int main(){
	float centi;
	float meter ;
	
	cout<<"Enter The Distance in centemeter and meter respectively:"<<endl;
	cin>>centi>>meter ;
	
	DM a(centi , meter);
	
	float feet ;
	float inches;
	
	cout<<"Enter the same distance in feet and inches:"<<endl;
	cin>>feet>>inches;
	
	DB b(feet , inches);
	
	
	DM result = addDistances( a , b);
	result.read();
		
	return 0;
}
