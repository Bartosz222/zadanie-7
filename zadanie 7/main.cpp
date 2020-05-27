#include <iostream>
#include <queue>
#include <fstream>
#include <String>
using namespace std;

class kolejka{
	public:
		kolejka();
		~kolejka();
		ifstream wejscie;
		ofstream wyjscie;
		int liczba;
		string liczba1;
		queue <int> Liczby;
	void sprawdzPlik();
	void wczytaj();
	void zapisz();
};
kolejka::kolejka(){
	wejscie.open("a.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"["<<endl;
}
kolejka::~kolejka(){
	wyjscie<<"]";
	wejscie.close();
	wyjscie.close();
}
void kolejka::sprawdzPlik(){
	if(wejscie.good()&&wyjscie.good()){}
	else {
		cout<<"Blad";
		exit(0);
	}
}
void kolejka::wczytaj(){
	while(!wejscie.eof()){
		wejscie>>liczba;
		cout<<liczba<<endl;
		Liczby.push(liczba);
	}
}
void kolejka::zapisz(){
	while(!Liczby.empty()){
		string liczba1 = to_string(Liczby.front());
		wyjscie<<"{\"liczba\":"+liczba1+"},"<<endl;
		Liczby.pop();
	}	
	
	system("pause");
}
int main() {
	kolejka k1;
	k1.sprawdzPlik();
	k1.wczytaj();
	k1.zapisz();
	return 0;
}
