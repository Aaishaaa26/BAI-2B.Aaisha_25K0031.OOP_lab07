#include <iostream>
using namespace std;

class Currency{
	protected:
		double amount, exchangeRate;
		string currencyCode, currencySymbol;
	public:
	    Currency(double amount, string code, string symbol, double rate) : amount(amount), currencyCode(code), currencySymbol(symbol), exchangeRate(rate){}
		virtual void convertToBase(){cout << currencySymbol << " to USD: " << amount*exchangeRate<< endl << endl; }
		virtual void convertTo(Currency& targetCurrency){cout<<targetCurrency.currencySymbol << " to " << currencySymbol << ": " << amount*exchangeRate/targetCurrency.exchangeRate <<endl << endl;}
		virtual void displayCurrency(){
			cout<< "\n\t\t\t\t_______________Currency Details_____________" << endl << endl;
			cout<< "\t\t\t\tCurrency Code: " << currencyCode <<endl<< "\t\t\t\tCurrency Symbol: " << currencySymbol <<endl<< "\t\t\t\tExchange Rate: " << exchangeRate <<endl << endl;	
		}
};

class Dollar : public Currency{
	public:
		Dollar(double amount): Currency(amount, "USD", "$", 1){}
		void convertToBase() override{ cout<< amount << " (Already Base Currency)" << endl<< endl; }
        void displayCurrency() override{
			cout<< "\n\t\t\t\t_______________Currency Details_____________" << endl << endl;
			cout<< "\t\t\t\tCurrency Code: USD" <<endl<< "\t\t\t\tCurrency Symbol: $" <<endl<< "\t\t\t\tExchange Rate: 1.0" <<endl << endl;	
		}
};
class Euro : public Currency{
	public:
		Euro(double amount): Currency(amount, "EURO", "€", 1.1){}
		void convertToBase() override{ cout << "EURO to USD: " << amount*exchangeRate<< endl << endl; }
        void displayCurrency ()override{
			cout<< "\n\t\t\t\t_______________Currency Details_____________" << endl << endl;
			cout<< "\t\t\t\tCurrency Code: EURO" <<endl<< "\t\t\t\tCurrency Symbol: €" <<endl<< "\t\t\t\tExchange Rate: 1.1" <<endl << endl;	
		}
};
class Rupee : public Currency{
	public:
		Rupee(double amount): Currency(amount, "PKR", "Rs", 0.0036){}
		void convertToBase() override{ cout << "PKR to USD: " << amount*exchangeRate<< endl << endl; }
        void displayCurrency() override{
			cout<< "\n\t\t\t\t_______________Currency Details_____________" << endl << endl;
			cout<< "\t\t\t\tCurrency Code: PKR" <<endl<< "\t\t\t\tCurrency Symbol: Rs" <<endl<< "\t\t\t\tExchange Rate: 0.0036" <<endl << endl;	
		}
};
int main(){

    Dollar d(100);
    d.displayCurrency();
    d.convertToBase();

    Euro e(70);
    e.displayCurrency();
    e.convertToBase();
    e.convertTo(d);

    Rupee r(5000);
    r.displayCurrency();
    r.convertToBase();
    r.convertTo(e);
}
