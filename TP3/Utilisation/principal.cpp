/**
 * \file Principal.cpp
 * \brief Fichier principal contenant un programme minimaliste de création d'un objet Personne
 * \author David Jalbert Ross
 * \version 2.0
 * \date 16 avril 2020
 */

#include <iostream>
#include "Personne.h"
#include "validationFormat.h"
#include "Date.h"
#include "Joueur.h"
#include "Entraineur.h"
#include "Annuaire.h"

using namespace std;

int main()
{
	cout << "Bienvenue à l'outil d'ajout d'une personne" << endl;
	cout << "-----------------------------------------" << endl;

	bool valide(true);
	string nom;

	do
	{
		cout << "Entrer le nom du joueur" << endl;
		cin >> nom;
		valide = util::validerFormatNom(nom);
		if(!valide)
		{
			cout << "Le nom du joueur ne doit comporter que des lettres" << endl;
		}
	}
	while(!valide);

	string prenom;

	do
	{
		cout << "Entrer le prénom du joueur" << endl;
		cin >> prenom;
		valide = util::validerFormatNom(prenom);
		if(!valide)
		{
			cout << "Le prénom du joueur ne doit comporter que des lettres" << endl;
		}
	}
	while(!valide);

	string telephone;
	char buffer[25];
	cin.ignore();
	do
	{
		cout << "Entrer le numéro de téléphone du joueur" << endl;
		cin.getline(buffer, 25);
		telephone = buffer;
		valide = util::validerTelephone(telephone);
		if(!valide)
		{
			cout << "Le numéro de téléphone doit avoir un format valide" << endl;
		}
	}
	while(!valide);

	bool ageInvalide = false;
	long jour;
	long mois;
	long annee;

	do
	{
		cout << "Veuillez entrer sa date de naissance" << endl;
		cout << "Le jour [1...31]";
		cin >> jour;
		cout << "Le mois [1...12]";
		cin >> mois;
		cout << "L'année [1970...]";
		cin >> annee;
		valide = util::Date::validerDate(jour,mois,annee);

		if(!valide)
		{
			cout << "La date doit être dans un format valide" << endl;
		}
		else
		{
			util::Date dateAujourdhui;
			util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_JOUEUR));
			ageInvalide = !(util::Date (jour,mois,annee) <  dateNaissanceMinimale);
			if(!ageInvalide)
			{
				util::Date dateNaissanceMaximale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MAXIMAL_JOUEUR - 1));
				ageInvalide = !(dateNaissanceMaximale < (util::Date (jour,mois,annee)));
			}
			if(ageInvalide)
			{
				cout << "Date invalide, le joueur doit être agé entre 15 et 17 ans" << endl;
			}
		}
	}
	while(!valide || ageInvalide);

	string position;

	do
	{
		cout << "Entrer la position du joueur" << endl;
		cin >> position;
		valide = true;
		if(position != "ailier" && position != "centre" && position != "défenseur" && position != "gardien")
		{
			valide = false;
		}
		if(!valide)
		{
			cout << "La position du joueur est invalide" << endl;
		}
	}
	while(!valide);

	util::Date dateTempJoueur(jour, mois, annee);
	hockey::Joueur tempJoueur(nom, prenom, dateTempJoueur, telephone, position);

	do
	{
		cout << "Entrer le nom de l'entraineur" << endl;
		cin >> nom;
		valide = util::validerFormatNom(nom);
		if(!valide)
		{
			cout << "Le nom de l'entraineur ne doit comporter que des lettres" << endl;
		}
	}
	while(!valide);

	do
	{
		cout << "Entrer le prénom de l'entraineur" << endl;
		cin >> prenom;
		valide = util::validerFormatNom(prenom);
		if(!valide)
		{
			cout << "Le prénom de l'entraineur ne doit comporter que des lettres" << endl;
		}
	}
	while(!valide);

	cin.ignore();
	do
	{
		cout << "Entrer le numéro de téléphone de l'entraineur" << endl;
		cin.getline(buffer, 25);
		telephone = buffer;
		valide = util::validerTelephone(telephone);
		if(!valide)
		{
			cout << "Le numéro de téléphone doit avoir un format valide" << endl;
		}
	}
	while(!valide);

	do
	{
		cout << "Veuillez entrer sa date de naissance" << endl;
		cout << "Le jour [1...31]";
		cin >> jour;
		cout << "Le mois [1...12]";
		cin >> mois;
		cout << "L'année [1970...]";
		cin >> annee;
		valide = util::Date::validerDate(jour,mois,annee);

		if(!valide)
		{
			cout << "La date doit être dans un format valide" << endl;
		}
		else
		{
			util::Date dateAujourdhui;
			util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_ENTRAINEUR));
			ageInvalide = !(util::Date (jour,mois,annee) <  dateNaissanceMinimale);
			if(ageInvalide)
			{
				cout << "Date invalide, l'entraineur doit être majeur" << endl;
			}
		}
	}
	while(!valide || ageInvalide);


	char sexe;

	do
	{
		cout << "Veuillez entrer le sexe de l'entraineur : M ou F" << endl;
		cin >> sexe;
		valide = true;
		if(sexe != 'M' && sexe != 'F')
		{
			valide = false;
		}
		if(!valide)
		{
			cout << "Le sexe est invalide" << endl;
		}
	}
	while(!valide);

	string numRAMQ;

	cin.ignore();
	do
	{
		cout << "Entrez le numéro de RAMQ de l'entraîneur" << endl;
		cin.getline(buffer, 25);
		numRAMQ = buffer;
		valide = util::validerNumRAMQ(numRAMQ, nom, prenom, jour, mois, annee, sexe);
		if(!valide)
		{
			cout << "Le numéro de RAMQ doit être dans un format valide" << endl;
		}
	}
	while(!valide);

	util::Date dateTempEntraineur(jour, mois, annee);
	hockey::Entraineur tempEntraineur(nom, prenom, dateTempEntraineur, telephone, numRAMQ, sexe);

	hockey::Annuaire annuaire("Winners de hockeyville");
	annuaire.ajouterPersonne(tempJoueur);
	annuaire.ajouterPersonne(tempEntraineur);
	cout << annuaire.reqAnnuaireFormate();

	return 0;
}


