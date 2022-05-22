// PourcentageMusiqueJouer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iterator>

using namespace std;

void CalculePourcentage(float nombre, float total, float& result) {
	float a = 100;

	result = (nombre / total) * a;
}

void calculPourcentageTotal(float a, float b, float c, float d, float e, float& f, float& g, float& h) {

	f = c + d;			//PourcentageAnglais
	g = a + b;			//PourcentageFrancais
	h = a + c + e;		//PourcentageCanadien
};

void printPourcentage(float a, float b, float c, float d, float e, float f, float g, float h, int i) {
	cout << "Pourcentage musique francaise : " << g << "\n";
	cout << "Pourcentage musique anglaise : " << f << "\n";
	cout << "Pourcentage musique canadienne : " << h << "\n";

	cout << "Pourcentage musique FC : " << a << "\n";
	cout << "Pourcentage musique FE : " << b << "\n";
	cout << "Pourcentage musique AC : " << c << "\n";
	cout << "Pourcentage musique AE : " << d << "\n";
	cout << "Pourcentage musique IC : " << e << "\n";

	cout << "Total des musiques qui sont passer : " << i << endl;

};

int main() {

	//Déclaration des variables

	float fc = 0;
	float fe = 0;
	float ae = 0;
	float ac = 0;
	float ic = 0;

	float totalMusique = 0;

	float pourcentageFc, pourcentageFe, pourcentageAc, 
		pourcentageAe, pourcentageIc, pourcentageAnglais, 
		pourcentageFrancais, pourcentageCanadien = 0;
	float total = 0;

	string nameFile = "";

	cout << "Entrez le noms du fichier : (Entrez le .csv à la fin du fichier)" << "\t";
	cin >> nameFile;


	string filename{ nameFile };
	ifstream input{ filename };

	if (!input.is_open()) {
		cerr << "Couldn't read file: " << filename << "\n";
		return 1;
	}
	//string line;
	vector<vector<string>> csvRows;
	//getline(input, line);
	for (string line; getline(input, line);) {
		istringstream ss(move(line));
		vector<string> row;
		if (!csvRows.empty()) {	

			row.reserve(csvRows.front().size());
		}
		// Permet de split les différentes partie du fichier par le character ','
		for (string value; getline(ss, value, ',');) {
			row.push_back(move(value));
		}
		csvRows.push_back(move(row));
	}

		//Entrez des donnez en fonction de leur catégorie

		/*
		Param
		@csvRows Permet de faire une boucle qui boucle sur le nombre de ligne du fichier
		@vector<string>& row Permet de pouvoir prendre les donners de chaque ligne.

		@row[1].at(2) Permet d'avoir le playcount de chaque musique 
		
		@row[0].at(1) Permet d'avoir les data ASCII pour savoir si c'est un F ou un A
		@row[0].at(2) Permet d'avoir les data ASCII pour savoir si c'est un E ou un C


		Les chiffres sont les valeur ASCII des lettre F, C, A et E;
		*/

	for (const vector<string>& row : csvRows) {
		char numberBuffer = row[1].at(2);
		float playCount = numberBuffer - '0';


		if (row[0].at(1) == 70 && row[0].at(2) == 67) {
			fc = fc + playCount;
		}
		else if (row[0].at(1) == 70 && row[0].at(2) == 69) {
			fe = fe +playCount;
		}
		else if (row[0].at(1) == 65 && row[0].at(2) == 67) {
			ac = ac +playCount;
		}
		else if (row[0].at(1) == 65 && row[0].at(2) == 69) {
			ae = ae + playCount;
		}
		else if (row[0].at(1) == 73 && row[0].at(2) == 67) {
			ic = ic +playCount;
		}
				
		cout << "\n";
	}
		total = fc + fe + ac + ae + ic;


		CalculePourcentage(fc, total, pourcentageFc);
		CalculePourcentage(fe, total, pourcentageFe);
		CalculePourcentage(ac, total, pourcentageAc);
		CalculePourcentage(ae, total, pourcentageAe);
		CalculePourcentage(ae, total, pourcentageIc);

		calculPourcentageTotal(pourcentageFc, pourcentageFe, pourcentageAc,
			pourcentageAe, pourcentageIc, pourcentageAnglais,
			pourcentageFrancais, pourcentageCanadien);

		printPourcentage(pourcentageFc, pourcentageFe, pourcentageAc,
			pourcentageAe, pourcentageIc, pourcentageAnglais,
			pourcentageFrancais, pourcentageCanadien, total);

		//Permet d'avoir la fenêtre qui ne ferme pas automatiquement.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
