/**
 * \file Joueur.cpp
 * \brief Fichier d'implementation de la classe Joueur
 * \author David Jalbert Ross
 * \version 1.0
 * \date 16 avril 2020
 */

#include "Joueur.h"
#include <sstream>
#include "validationFormat.h"


using namespace std;

namespace hockey
{

/**
 * \brief Constructeur avec paramètres
 * 		  On construit un objet Joueur avec les paramètres d'entrés
 * \param[in] p_nom est un string qui contient le nom du joueur, uniquement des lettres et non vide
 * \param[in] p_prenom est un string qui contient le prénom du joueur, uniquement des lettres et non vide
 * \param[in] p_dateNaissance est un objet Date qui contient la date de naissance du joueur, doit être une date valide
 * \param[in] p_telephone est un string qui contient le numéro de téléphone du joueur, doit être un numéro valide
 * \param[in] p_position est un string qui contient la position du joueur, doi être une position valide
 */
Joueur::Joueur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   const std::string& p_telephone, const std::string& p_position):
			   Personne::Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_position(p_position)
{
	PRECONDITION(verifiePosition(m_position));
	util::Date dateAujourdhui;
	util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_JOUEUR));
	PRECONDITION(reqDateNaissance() <  dateNaissanceMinimale)
	util::Date dateNaissanceMaximale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MAXIMAL_JOUEUR - 1));
	PRECONDITION(dateNaissanceMaximale < reqDateNaissance())
	POSTCONDITION(reqPosition() == m_position)
	INVARIANTS();
}

/**
 * \brief Retourne la position du joueur
 * \return un string contenant la position du joueur
 */
const std::string Joueur::reqPosition() const
{
	return m_position;
}

/**
 * \brief Retourne les informations du joueur en format formaté
 * 		  Selon le format :
 * 		  Nom               : Louis
 *		  Prenom            : Jean
 *		  Date de naissance : Samedi le 12 mai 1979
 *		  Telephone         : 418 656-2131
 *		  Position          : centre
 * \return un string contenant les informations formatés
 */
std::string Joueur::reqPersonneFormate() const
{
	ostringstream oss;

	oss << Personne::reqPersonneFormate();
	oss << "Position          : " << m_position << endl;
	oss << "---------------------" << endl;

	return oss.str();
}

/**
 * \brief Retourne une copie de l'objet joueur
 * \return un objet Joueur contenant le joueur
 */
Personne* Joueur::clone() const
{
	return new Joueur(*this);
}

/**
 * \brief Verifie si la string est une position valide
 * \param[in] p_position est une string contenant un position a valider
 * \return un bool indiquant si la position est valide ou non
 */
bool Joueur::verifiePosition(const std::string& p_position) const
{
	bool valide = true;
	if(p_position != "ailier" && p_position != "centre" && p_position != "défenseur" && p_position != "gardien")
	{
		valide = false;
	}

	return valide;
}

/**
 * \brief Vérification des invariants de la classe Joueur
 */
void Joueur::verifieInvariant() const
{
	INVARIANT(verifiePosition(m_position));
	util::Date dateAujourdhui;
	util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_JOUEUR));
	INVARIANT(reqDateNaissance() <  dateNaissanceMinimale)
	util::Date dateNaissanceMaximale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MAXIMAL_JOUEUR - 1));
	INVARIANT(dateNaissanceMaximale < reqDateNaissance())
}
}
