#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <cmath>

// globalus kintamieji
const int width = 32; // eilutės ilgis

using namespace std;

// išvedame info apie autorių
void printAuthor() {
	string vardas = "Erikas";
	string pavarde = "Stanys";
	string grupe = "PRM24SONL";
	cout << vardas << " " << pavarde << ", " << grupe << endl;
}

void printTitle() {
	string line = string(width, '-');
	cout << line << endl;
	cout << "  Programavo" << endl << "  ";
	printAuthor();
	cout << line << endl;
}

// išvedame meniu
void printMenu(string meniu[4]) {
	string line = string(width, '*');
	cout << line << "\n";
	for (int i = 0; i < 4; i++) {
		printf("%s\n", meniu[i].data());
  };
	cout << line << "\n\n";
}

// išvedame meniu punktą
void printMenuItem(string menuTitle) {
	string line = string(width, '*');
	system("clear");
	cout << line << "\n";
  cout << menuTitle << "\n";
  cout << line << "\n\n";
}

/* 
	Negaliu naudoti system("pause"), nes ši komanda skirta tik Windows operacinei sistemai.
	Taip pat nesu tikras ar veiks system("clear") Windows aplinkoje (system("clr") pakaitalas).
*/
void pressAnyKey() {
	char anyKey;
	cout << "\nPress any key return to menu";
	cin.get(anyKey);
	//getc(stdin);
	system("clear");
}

void runSkaiciuotuvas(string menuTitle) {
	char cr;
	float num1;
	float num2;
	char op;
	vector<string> results {};
	string input = "";
	//------------------
	while (cr != 'n' && cr != 'N') {
		system("clear");
		printMenuItem(menuTitle);
		for (string result : results) {
    cout << result << "\n";
  	}

		input = "";
    printf("\nĮveskite skaičių: ");
		getline(cin, input);
		while (!input.empty() && input.find_first_not_of("1234567890.-") != string::npos ) {
			cout << "Klaidingas skaičius. Pamėginkite dar kartą.\n";
			printf("\nĮveskite skaičių: ");
			getline(cin, input);
		}
		num1 = atof(input.c_str());

		input = "";
    printf("Įveskite veiksmo simbolį +, -, *, /: ");
		getline(cin, input);
		if (!input.empty()) {
			op = input.at(0);
		}
		while (op != '+' && op != '-' && op != '*' && op != '/') {
				printf("Netinkamas ženklas. Pabandykite dar kartą.\n\n");
				printf("Įveskite veiksmo simbolį +, -, *, /: ");
	    	getline(cin, input);
				if (!input.empty()) {
					op = input.at(0);
				}
		}
		
		input = "";
    printf("Įveskite antrą skaičių: ");
		getline(cin, input);
    while (!input.empty() && input.find_first_not_of("1234567890.-") != string::npos ) {
			cout << "Klaidingas skaičius. Pamėginkite dar kartą.\n";
			printf("\nĮveskite skaičių: ");
			getline(cin, input);
		}
		num2 = atof(input.c_str());

		ostringstream oss;
		switch(op) {
			case '+':
      	oss << num1 << " + " << num2 << " = " << num1 + num2;
      	break;
	    case '-':
  	    oss << num1 << " - " << num2 << " = " << num1 - num2;
    	  break;
	    case '*':
  	    oss << num1 << " * " << num2 << " = " << num1 * num2;
    	  break;
	    case '/':
  	    oss << num1 << " / " << num2 << " = " << num1 / num2;
    	  break;
	    default:
    	  oss << "Klaida! neteisingas veiksmas";
      	break;
  	}
		cout << oss.str();
		results.push_back(oss.str());
		oss.clear();

		cr = 't';
		input = "";
		printf("\nAr pageidaujate tęsti? [T/n]: ");
    getline(cin, input);
		if (!input.empty()) {
			if (input.at(0) == 'n' || input.at(0) == 'N') {
				cr = input.at(0);
			}
		}
	}
}

int main()
{
		string meniu[] = {
			"*  Meniu:                      *",
			"*  [1] - Autorius              *",
			"*  [2] - SKAIČIUOTUVAS         *",
			"*  [x] - PABAIGA               *",
		};
		string numbers = "1234567890";
		string lt = "ĄČĘĖĮŠŲŪŽąčęėįšųūž";
		char cr;
		//-----------------
		printTitle();
		printMenu(meniu);

		while (cr != 'x') {
			string input = "";
			cout << "Pasirinkite meniu punktą: ";
			getline(cin, input);
			if (!input.empty()) {
				if (input.length() > 1) {
					if (input.length() == 2 && lt.find(input) < 34) {
						printf("Lietuviškos raidės netinka. Pabandykite dar kartą.\n\n");
					}
					else {
						printf("Užtenka įvesti 1 simbolį. Pabandykite dar kartą.\n\n");
					}
					cr = '0';
				}
				else {
					cr = input.at(0);
				}
			}
			if (!cin.good()) {
				break;
			}
			switch(cr) {
			  case '0':
			    break;
			  case '1':
					printMenuItem(meniu[(cr - '0')]);
        	printAuthor();
					pressAnyKey();
					printMenu(meniu);
			    break;
				case '2':
        	runSkaiciuotuvas(meniu[(cr - '0')]);
					pressAnyKey();
					printMenu(meniu);
			    break;
				case 'x':
					printf("\nAčiū už dėmesį. Viso geriausio!\n\n");
					break;
			  default:
					printf("Tokio meniu punkto nėra. Pabandykite dar sykį.\n\n");
			}
		}
		return 0;
}