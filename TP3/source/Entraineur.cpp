/**
 * \file Entraineur.cpp
 * \brief Fichier d'implementation de la classe Entraineur
 * \author David Jalbert Ross
 * \version 1.0
 * \date 16 avril 2020
 */


#include "Entraineur.h"
#include <sstream>
#include "validationFormat.h"


using namespace std;

namespace hockey
{

/**
 * \brief Constructeur avec paramètres
 * 		  On construit un objet Entraineur avec les paramètres d'entrés
 * \param[in] p_nom est un string qui contient le nom de l'entraineur, uniquement des lettres et non vide
 * \param[in] p_prenom est un string qui contient le prénom de l'entraineur, uniquement des lettres et non vide
 * \param[in] p_dateNaissance est un objet Date qui contient la date de naissance de l'entraineur, doit être une date valide
 * \param[in] p_telephone est un string qui contient le numéro de téléphone de l'entraineur, doit être un numéro valide
 * \param[in] p_numRAMQ est un string qui contient le numéro de RAMQ de l'entraineur, doit être un numéro valide
 * \param[in] p_sexe est un char qui contient le sexe de l'entraineur, doit être 'M' ou 'F'
 */
Entraineur::Entraineur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   	       const std::string& p_telephone, const std::string& p_numRAMQ, char p_sexe):
					   Personne::Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_numRAMQ(p_numRAMQ), m_sexe(p_sexe)
{
	PRECONDITION(util::validerNumRAMQ(reqNumRAMQ(), reqNom(), reqPrenom(), reqDateNaissance().reqJour(), reqDateNaissance().reqMois(),
			reqDateNaissance().reqAnnee(), reqSexe()));
	util::Date dateAujourdhui;
	util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_ENTRAINEUR));
	PRECONDITION(reqDateNaissance() <  dateNaissanceMinimale)
	POSTCONDITION(reqNumRAMQ() == p_numRAMQ)
	POSTCONDITION(reqSexe() == p_sexe)
	INVARIANTS();
}

/**
 * \brief Retourne le numéro de RAMQ de l'entraineur
 * \return un string contenant le numéro de RAMQ de l'entraineur
 */
const std::string Entraineur::reqNumRAMQ() const
{
	return m_numRAMQ;
}

/**
 * \brief Retourne le sexe de l'entraineur
 * \return un char contenant le sexe de l'entraineur
 */
char Entraineur::reqSexe() const
{
	return m_sexe;
}

/**
 * \brief Retourne les informations de l'entraineur en format formaté
 * 		  Selon le format :
 * 		  Nom               : Louis
 *		  Prenom            : Jean
 *		  Date de naissance : Samedi le 12 mai 1979
 *		  Telephone         : 418 656-2131
 *		  Numero de RAMQ    : JEAL 7905 1203
 * \return un string contenant les informations formatés
 */
std::string Entraineur::reqPersonneFormate() const
{
	ostringstream oss;

	oss << Personne::reqPersonneFormate();
	oss << "Numero de RAMQ    : " << m_numRAMQ << endl;
	oss << "---------------------" << endl;

	return oss.str();
}

/**
 * \brief Retourne une copie de l'objet Entraineur
 * \return un objet Entraineur contenant l'entraineur
 */
Personne* Entraineur::clone() const
{
	return new Entraineur(*this);
}

/**
 * \brief Vérification des invariants de la classe Entraineur
 */
void Entraineur::verifieInvariant() const
{
	INVARIANT(util::validerNumRAMQ(reqNumRAMQ(), reqNom(), reqPrenom(), reqDateNaissance().reqJour(), reqDateNaissance().reqMois(),
			reqDateNaissance().reqAnnee(), reqSexe()));
	util::Date dateAujourdhui;
	util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_ENTRAINEUR));
	INVARIANT(reqDateNaissance() <  dateNaissanceMinimale)
}

}
