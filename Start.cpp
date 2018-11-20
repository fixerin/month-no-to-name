#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Konfiguracja{
private:
	ifstream cFile();

	vector <string> key;
	vector <string> value;

public:
	void czytaj(ifstream &cFile){

		cFile.open("config.cfg");
		if (cFile.is_open())
		{
			std::string line;
			while (getline(cFile, line)) {
				line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
				if (line[0] == '#' || line.empty()) //sprawdza komentarz
					continue;
				int delimiterPos = line.find("="); // znajduje pozycjê znaku '='
				 
				key.push_back(line.substr(0, delimiterPos)); // zapisuje klucz do 'key'

				value.push_back(line.substr(delimiterPos + 1)); // zapisuje wartosc do 'value'
				
			}
		}
		else {
			std::cerr << "Couldn't open config file for reading.\n";
		}
	}

	//Getters & Setters
	vector <string> getKey() {
		return key;
	}

	vector <string> getValue() {
		return value;
	}

	vector <string> setKey(string x) {
		key.push_back(x);
	}

	vector <string> setValue(string x) {
		value.push_back(x);
	}

	void displayValues(vector <string> displayValue) {
		for (int x = 0; x != displayValue.size(); ++x)
		{
			cout << displayValue[x] << endl;
		}
	}

	void displayKeys(vector <string> displayKey) {
		for (int x = 0; x != displayKey.size(); ++x)
		{
			cout << displayKey[x] << endl;
		}
	}
};


int main() {
	
	Konfiguracja cfg;

	ifstream cfgFile;
	vector <string> lokalizacja;;
	string jezyk;
	int nrMiesiaca;
	

	cfg.czytaj(cfgFile); // odczytanie z pliku konfiguracyjnego

	//cfg.displayValues(cfg.getValue());

	lokalizacja = cfg.getValue(); // przypisanie wartosci do wektora lokalizacji

	jezyk = lokalizacja[0];
	
	//cout << jezyk << endl;
	
	transform(jezyk.begin(), jezyk.end(), jezyk.begin(), tolower);

	map<int, string> month;

	month[1] = "January";
	month[2] = "February";
	month[3] = "March";
	month[4] = "April";
	month[5] = "May";
	month[6] = "June";
	month[7] = "July";
	month[8] = "August";
	month[9] = "September";
	month[10] = "October";
	month[11] = "November";
	month[12] = "December";

	map<int, string> miesiac;

	miesiac[1] = "Styczen";
	miesiac[2] = "Luty";
	miesiac[3] = "Marzec";
	miesiac[4] = "Kwiecien";
	miesiac[5] = "Maj";
	miesiac[6] = "Czerwiec";
	miesiac[7] = "Lipiec";
	miesiac[8] = "Sierpien";
	miesiac[9] = "Wrzesien";
	miesiac[10] = "Pazdziernik";
	miesiac[11] = "Listopad";
	miesiac[12] = "Grudzien";

	map<int, string> monat;

	monat[1] = "Januar";
	monat[2] = "Februar";
	monat[3] = "März";
	monat[4] = "April";
	monat[5] = "Mai";
	monat[6] = "Juni";
	monat[7] = "Juli";
	monat[8] = "August";
	monat[9] = "September";
	monat[10] = "Oktober";
	monat[11] = "November";
	monat[12] = "Dezember";

	cout << "Month number: ";
	cin >> nrMiesiaca;
	cout << endl;


	if (jezyk == "polski") {
		cout << miesiac[nrMiesiaca] << endl;
	}
	else if (jezyk == "angielski") {
		cout << month[nrMiesiaca] << endl;
	}
	else if (jezyk == "niemiecki") {
		cout << monat[nrMiesiaca] << endl;
	}
	else {
		cout << "Error in config file." << endl;
	}


	system("pause");
}