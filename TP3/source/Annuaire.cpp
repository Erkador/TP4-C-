/**
 * \file Annuaire.cpp
 * \brief Fichier d'implementation de la classe Annuaire
 * \author David Jalbert Ross
 * \version 1.0
 * \date 16 avril 2020
 */


#include "Annuaire.h"
#include <sstream>
#include "validationFormat.h"


using namespace std;

namespace hockey
{

/**
 * \brief Constructeur avec paramètres string
 * 		  On construit un objet Entraineur avec son nom de club
 * \param[in] p_nomClub est un string qui contient le nom du club
 */
Annuaire::Annuaire(const std::string p_nomClub):
		 	       m_nomClub(p_nomClub)
{
}

/**
 * \brief Constructeur avec paramètres Annuaire
 * 		  On construit un objet Entraineur avec un autre objet Annuaire
 * \param[in] p_annuaire est un objet Annuaire
 */
Annuaire::Annuaire(const Annuaire& p_annuaire)
{
	std::vector<Personne*> vPersonne = p_annuaire.m_vMembres;
	m_nomClub = p_annuaire.reqNomClub();

	int nbPersonne = vPersonne.size();

	for(int i = 0; i < nbPersonne; i++)
	{
		this->ajouterPersonne(*vPersonne[i]);
	}
}

/**
 * \brief Retourne le nom de club associé à l'annuaire
 * \return un string contenant le nom du club associé à l'annuaire
 */
const std::string Annuaire::reqNomClub() const
{
	return m_nomClub;
}

/**
 * \brief Retourne les informations sotckés dans l'annuaire en format formaté pour chaque membre
 * 		  Selon le format :
 * 		  Club   : Le club des gagnants
 *		  --------------------
 * 		  Nom               : Louis
 *		  Prenom            : Jean
 *		  Date de naissance : Samedi le 12 mai 1979
 *		  Telephone         : 418 656-2131
 *		  Numero de RAMQ    : JEAL 7905 1203
 *		  --------------------
 *		  [...]
 * \return un string contenant les informations formatés
 */
const std::string Annuaire::reqAnnuaireFormate() const
{
	std::vector<Personne*> vPersonne = m_vMembres;

	ostringstream oss;

	oss << "Club   : " << m_nomClub << endl;
	oss << "--------------------" << endl;

	int nbPersonne = vPersonne.size();

	for(int i = 0; i < nbPersonne; i++)
	{
		std::string formater = vPersonne[i]->reqPersonneFormate();
		oss << formater;
	}

	return oss.str();
}

/**
 * \brief Assigne un nouveau membre au club de l'annuaire
 * \param[in] p_personne est un objet héritant de la classe Personne
 */
void Annuaire::ajouterPersonne (const Personne& p_personne)
{
	m_vMembres.push_back(p_personne.clone());
}

/**
 * \brief surcharge de l'opérateur =
 * \param[in] p_annuaire est un objet Annuaire
 */
void Annuaire::operator=(const Annuaire& p_annuaire)
{
	m_vMembres.clear();

	std::vector<Personne*> vPersonne = p_annuaire.m_vMembres;
	m_nomClub = p_annuaire.reqNomClub();

	int nbPersonne = vPersonne.size();

	for(int i = 0; i < nbPersonne; i++)
	{
		this->ajouterPersonne(*vPersonne[i]);
	}
}

/**
 * \brief Destructeur qui supprime le contenu du vector de membres
 */
Annuaire::~Annuaire()
{
	std::vector<Personne*> vPersonne = m_vMembres;

	int nbPersonne = vPersonne.size();

	for(int i = 0; i < nbPersonne; i++)
	{
		delete vPersonne[i];
	}
}
}
