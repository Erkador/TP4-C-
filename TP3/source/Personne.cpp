/**
 * \file Personne.cpp
 * \brief Fichier d'implementation de la classe Personne
 * \author David Jalbert Ross
 * \version 2.0
 * \date 16 avril 2020
 */

#include "Personne.h"
#include <sstream>
#include "validationFormat.h"

using namespace std;

namespace hockey
{
/**
 * \brief Constructeur avec paramètres
 * 		  On construit un objet Personne avec les paramètres d'entrés
 * \param[in] p_nom est un string qui contient le nom de la personne, uniquement des lettres et non vide
 * \param[in] p_prenom est un string qui contient le prénom de la personne, uniquement des lettres et non vide
 * \param[in] p_dateNaissance est un objet Date qui contient la date de naissance de la personne, doit être une date valide
 * \param[in] p_telephone est un string qui contient le numéro de téléphone de la personne, doit être un numéro valide
 */
Personne::Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_telephone):
m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
	PRECONDITION(util::validerFormatNom(m_nom));
	PRECONDITION(util::validerFormatNom(m_prenom));
	PRECONDITION(util::validerTelephone(m_telephone));
	PRECONDITION(util::Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee()));
	POSTCONDITION(reqNom() == p_nom);
	POSTCONDITION(reqPrenom() == p_prenom);
	POSTCONDITION(reqDateNaissance() == p_dateNaissance);
	POSTCONDITION(reqTelephone() == p_telephone);
	INVARIANTS();
}

/**
 * \brief Retourne le nom de la personne
 * \return un string contenant le nom de la personne
 */
const std::string& Personne::reqNom() const
{
	return m_nom;
}

/**
 * \brief Retourne le prénom de la personne
 * \return un string contenant le prénom de la personne
 */
const std::string& Personne::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief Retourne le date de naissance de la personne
 * \return un objet Date qui contient la date de naissance
 */
const util::Date& Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}

/**
 * \brief Retourne le numéro de téléphone de la personne
 * \return un string contenant le numéro de téléphone
 */
const std::string& Personne::reqTelephone() const
{
	return m_telephone;
}

/**
 * \brief Assigne un nouveau numéro de téléphone à la personne
 * \param[in] p_telephone est un string qui contient le numéro de téléphone de la personne, doit être un numéro valide
 */
void Personne::asgTelephone(const std::string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(reqTelephone() == p_telephone);
	INVARIANTS();
}

/**
 * \brief Retourne les informations de la personnes en format formaté
 * 		  Selon le format :
 * 		  Nom               : Louis
 *		  Prenom            : Jean
 *		  Date de naissance : Samedi le 12 mai 1979
 *		  Telephone         : 418 656-2131
 * \return un string contenant les informations formatés
 */
std::string Personne::reqPersonneFormate() const
{
	ostringstream oss;

	oss << "Nom               : " << m_nom << endl;
	oss << "Prenom            : " << m_prenom << endl;
	oss << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << endl;
	oss << "Telephone         : " << m_telephone << endl;

	return oss.str();
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_personne est un objet personne
 * \return un booléen indiquant si les deux personnes ont le même nom, prénom et date de naissance
 */
bool Personne::operator ==(const Personne& p_personne) const
{
	bool valide;

	if(m_nom == p_personne.reqNom() && m_prenom == p_personne.reqPrenom() && m_dateNaissance == p_personne.reqDateNaissance())
	{
		valide = true;
	}
	else
	{
		valide = false;
	}

	return valide;
}

/**
 * \brief Vérification des invariants de la classe Personne
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));
	INVARIANT(util::Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee()));
}

}




