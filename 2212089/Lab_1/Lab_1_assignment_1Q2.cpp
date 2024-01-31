#include<iostream>
using namespace std;

class bankDB{
	private:
		string depositor;
		long long accountNumber;
		string type;
		long double balance;
	
	public:
		void init(string depositor , long long accountNumber , string type , long double balance){
			this->depositor = depositor;
			this->accountNumber = accountNumber;
			this->type = type;
			this->balance = balance ;
		}
		
		void deposite(long double deposite){
			this->balance = this->balance + deposite ;
			cout<<"Your Current balance"<<this->balance<<endl;
		}
		
		void withdraw(long double withdrawAmount){
			cout<<"Your balance: "<<this->balance<<endl;
			this->balance = this->balance - withdrawAmount;
			cout<<"Your Current balance after withdrawing: "<<this->balance<<endl;
		}
		
		void displayAccount(){
			cout<<"Name:"<<this->depositor<<endl;
			cout<<"Your Current Balance: "<<this->balance<<endl;
		}
		
		
		
		  
};


int main(){
	
	bankDB bedanta;
	
	bedanta.init("Bedanta Buraguhain" , 4111898 , "seving" , 400.7890);
	bedanta.displayAccount();
	bedanta.deposite(400000);
	bedanta.withdraw(89.89);
	
	return 0;
}
