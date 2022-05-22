// RajoutFichierCSV.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Source2,"PlayCount","Title","Artist","Composer","RecordLabel",      

//AE,"13","Where Are You Now (ft. Callum Scott)","Lost Frequencies","",""
/*
FC,"13","Belle","Statzz, Bnyofficial","",""
FC,"13","Lune de miel","Syelle","",""
FC,"13","Été 90","Therapie Taxi","",""
FC,"12","Attends (ft. Exky)","Avril Jensen","",""
AC,"8","What They Say (ft. Karl Wolf et Doug St. Louis)","Dom Devino X Skilteck","",""
*/



int main()
{

	string Source2;
	int PlayCount;
	string Title;
	string Artist;
	string Composer;
	string RecordLabel;
	
	string buffer;


	string nameFile = "Machin.txt";

	ifstream textFile;

	textFile.open(nameFile, ifstream::in);
	//Bon va te faire foutre enculer


	if (!textFile.is_open()) {
		cerr << "Couldn't read file: " << nameFile << "\n";
		return 1;

	}

	getline(textFile, buffer);
	cout << buffer;


	while (!textFile.eof()) {
		for (int i = 0; i <= 6; i++) {
			getline(textFile, buffer);
			cout << buffer;
		}
	}
	
		



}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
