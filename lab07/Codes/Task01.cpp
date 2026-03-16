#include <iostream>
using namespace std;

class Account{
	protected:
	    int accountNumber;
	    double balance;
	    string accountHolderName, accountType;
	
	public:
		Account(int num, double bal, string name, string type): accountNumber(num), balance(bal), accountHolderName(name), accountType(type){}
		void deposit(double amount){
			balance += amount;
			cout <<"Amount Deposited Successfully" <<endl << endl;
		}
		virtual void withdraw(double amount){
			if((balance -amount) < 0){
				cout<< "Insufficient Balance" << endl << endl;
				return;
			}
			balance -= amount;
			cout << "Amount Successfuly Withdrawn" << endl << endl;
		}
		virtual void calculateInterest(){
			double interest = balance *0.05;
			balance += interest;
			cout << "Your Interest is: " << interest << endl << "Balance AFter Interest Is: " << balance << endl<< endl;
		}
		virtual void printStatement(){
			cout << "\t\t\t_________________Account Statement_________________" << endl;
			cout<< "\n\t\t\tAccount Holder Name: " << accountHolderName<<endl;
			cout<<"\t\t\tAcount Number: " << accountNumber<< endl;
			cout<<"\t\t\tAccount Type: " << accountType << endl;
			cout <<"\t\t\tCurrent Balance: " << balance << endl <<endl;
		}
		void getAccountInfo(){
			cout<<"\t\t\t_________________Account Information_________________" << endl;
			cout<< "Account Holder Name: " << accountHolderName<<endl;
			cout<<"Acount Number: " << accountNumber<< endl;
		}
};

class SavingsAccount : public Account{
	double interestRate, minimumBalance;
	public:
		SavingsAccount(int num, double balance, string name, double rate, double minBal) : Account(num, balance, name, "Saving"), interestRate(rate), minimumBalance(minBal){}
    void changeInterest(double rate){
    	interestRate = rate;
	}   
    void calculateInterest() override {
     	double interest = balance * (interestRate/100);
     	balance += interest;
     	cout << "Your Interest Is: "<< interest << endl << "Balance AFter Interest Is: " << balance << endl<< endl;
    }
    void withdraw(double amount) override {
    	if((balance - amount) < minimumBalance){
    		cout<< "Can Not Withdraw due to minimum balance requirement"<<endl << endl;
    		return;
		}
		balance -= amount;
		cout << "Amount Successfuly Withdrawn" << endl << endl;
	}
	void printStatement() override {
			cout << "\t\t\t_________________Account Statement_________________" << endl;
			cout<< "\n\t\t\tAccount Holder Name: " << accountHolderName<<endl;
			cout<<"\t\t\tAcount Number: " << accountNumber<< endl;
			cout<<"\t\t\tAccount Type: SAVINGS"  << endl;
			cout <<"\t\t\tCurrent Balance: " << balance << endl <<endl;
	}
}; 

class CheckingAccount : public Account{
	public:
		CheckingAccount(int num, double bal, string name): Account(num, bal, name, "Checking"){}
		void calculateInterest() override {
			cout<< "No interest On Checking Account" <<endl << endl;
		}
		void printStatement() override {
			cout << "\t\t\t_________________Account Statement_________________" << endl;
			cout<< "\n\t\t\tAccount Holder Name: " << accountHolderName<<endl;
			cout<<"\t\t\tAcount Number: " << accountNumber<< endl;
			cout<<"\t\t\tAccount Type: CHECKING"  << endl;
			cout <<"\t\t\tCurrent Balance: " << balance << endl <<endl;
	    }
};
struct Date
{
    int day;
    int month;
    int year;
};
class FixedDepositAccount : public Account{
	double fixedInterestRate;
	Date maturityDate;
	
	public:
		FixedDepositAccount(int num, double bal, string name, double rate, int day,int month, int year):Account(num, bal, name, "Fixed Deposit"), fixedInterestRate(rate){
		    maturityDate.day = day;
		    maturityDate.month = month;
		    maturityDate.year = year;
		}
		void calculateInterest() override {
     	    double interest = balance * (fixedInterestRate/100);
     	    balance += interest;
     	    cout << "Your Interest Is: "<< interest << endl << "Balance AFter Interest Is: " << balance << endl<< endl;
        }
	    void withdraw(double amount) override {
	    	Date currentDate = {16,03,2026};
	    	if(currentDate.year > maturityDate.year){ //assuming year comparision
	    		if(currentDate.month > maturityDate.month){
	    			if(currentDate.day > maturityDate.day){
	    				if(balance-amount > 0){
						    balance -= amount;
						    cout<< "Amount Withdrawn Successfully" << endl << endl;
						    maturityDate.year = currentDate.year;
						    maturityDate.month = currentDate.month;
						    maturityDate.day = currentDate.day;
						    return;
						}
						cout<< "Insufficient Balance"<< endl << endl;
				        return;
					}
				}
			}
	    	cout <<"Maturity Date Not Reached" << endl << endl;
		}
		void printStatement() override {
			cout << "\t\t\t_________________Account Statement_________________" << endl;
			cout<< "\n\t\t\tAccount Holder Name: " << accountHolderName<<endl;
			cout<<"\t\t\tAcount Number: " << accountNumber<< endl;
			cout<<"\t\t\tAccount Type: FIXED DEPOSIT"  << endl;
			cout <<"\t\t\tCurrent Balance: " << balance << endl <<endl;
	    }
};
int main() {
    SavingsAccount sa(31, 31000, "Aaisha", 5.0, 1000);
    CheckingAccount ca(93, 93000, "Sumi");
    FixedDepositAccount fda(126, 126000, "Zainu", 7.0, 10, 1, 2025);

    sa.calculateInterest();
    sa.withdraw(4500);
    sa.printStatement();
    
	ca.calculateInterest();
	ca.withdraw(1500);
	ca.printStatement();
    
    fda.calculateInterest();	
    fda.withdraw(5000);	
	fda.printStatement();
}
