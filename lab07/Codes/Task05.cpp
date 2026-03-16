#include <iostream>
using namespace std;

class Media{
	protected:
		string title, publicationDate, uniqueID, publisher;
	public:
		Media(string title, string date, string ID, string publisher) : title(title), publicationDate(date), uniqueID(ID), publisher(publisher){}
		virtual void displayInfo(){ cout<< "\t\t\t\tTitle: " << title << endl << "\t\t\t\tID: "<< uniqueID << endl <<"\t\t\t\tPublisher: " << publisher << endl << "\t\t\t\tPublication Date: " << publicationDate << endl << endl;}
		void checkOut(){cout << uniqueID << " (" << title << ") has been checked out"<< endl << endl;}
		void returnItem(){cout << uniqueID << " (" << title << ") has been returned"<< endl << endl;}
};

class Book : public Media{
	string author, ISBN;
	int numberOfPages;
	
	public:
		Book(string title, string date, string ID, string publisher, string author, string isbn, int pages): Media(title, date, ID, publisher), author(author), ISBN(isbn), numberOfPages(pages){}
		void displayInfo() override{ 
		cout << "\t\t\t\t_________________ Book Details________________" << endl << endl;
		cout<< "\t\t\t\tTitle: " << title << endl << "\t\t\t\tISBN: "<< ISBN << endl <<"\t\t\t\tAuthor: " << author << endl << "\t\t\t\tNumber Of Pages: " << numberOfPages << endl << endl;}
};
class DVD : public Media{
	string director, duration;
	double rating;
	
	public:
		DVD(string title, string date, string ID, string publisher, string dir, string dur, double rating): Media(title, date, ID, publisher), director(dir), duration(dur), rating(rating){}
		void displayInfo() override{ 
		cout << "\t\t\t\t_________________ DVD Details________________" << endl << endl;
		cout<< "\t\t\t\tTitle: " << title << endl << "\t\t\t\tDirector: " << director << endl << "\t\t\t\tDuration: " << duration << endl <<"\t\t\t\tRating: "<< rating<< endl << endl;}
};
class CD : public Media{
	string artist, genre;
	int numberOfTracks;
	
	public:
		CD(string title, string date, string ID, string publisher, string artist, int tracks, string genre): Media(title, date, ID, publisher), artist(artist), numberOfTracks(tracks), genre(genre){}
		void displayInfo() override{ 
		cout << "\t\t\t\t_________________ CD Details________________" << endl << endl;
		cout<< "\t\t\t\tTitle: " << title << endl << "\t\t\t\tArtist: " << artist << endl << "\t\t\t\tNumber Of Tracks: " << numberOfTracks<< endl <<"\t\t\t\tGenre: "<< genre << endl << endl;}
};
class Searching{

    public:
        void search(string title){cout << "Searching media with Title: " << title << endl << endl;}
        void search(string title, string author){cout << "Searching Book: " << title << " by " << author << endl << endl;}
        void search(int year){cout << "Searching media published in year: " << year << endl << endl;}
};
int main(){

    Book b("A Thousand Splendid Suns","2007","B102","Riverhead Books","Khaled Hosseini","9781594483851",372);
    b.displayInfo();
    b.returnItem();

    DVD d("Despicable Me","2010","D101","Universal Pictures","Pierre Coffin & Chris Renaud","95 minutes",7.6);
    d.displayInfo();
    d.checkOut();

    CD c("After Hours", "2020", "CD201", "XO/Republic Records", "The Weeknd", 14, "R&B/Pop");
    c.displayInfo();
    
    Searching search;         
    search.search("A Thousand Splendid Suns", "Khaled Hosseini"); 
    search.search(2010);                       
    search.search("After Hours");                        


}
