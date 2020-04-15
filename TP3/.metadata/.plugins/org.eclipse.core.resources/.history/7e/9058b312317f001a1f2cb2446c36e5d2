/**
 * \file Personne.cpp
 * \brief Fichier d'implementation de la classe Personne
 * \author David Jalbert Ross
 * \version 1.0
 * \date 23 février 2019
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
	verifieInvariantPersonne();
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
	verifieInvariantPersonne();
}

/**
 * \brief Retourne les informations de la personnes en format formaté
 * 		  Selon le format :
 * 		  Nom               : Louis
 *		  Prenom            : Jean
 *		  Date de naissance : Samedi le 12 mai 1979
 *		  Telephone         : 418 656-2131
 * \return un string contenant les information formatés
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

void Personne::verifieInvariantPersonne() const
{
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));
	INVARIANT(util::Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee()));
}

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
	verifieInvariantEntraineur();
}

const std::string Entraineur::reqNumRAMQ() const
{
	return m_numRAMQ;
}

char Entraineur::reqSexe() const
{
	return m_sexe;
}

std::string Entraineur::reqPersonneFormate() const
{
	ostringstream oss;

	oss << Personne::reqPersonneFormate();
	oss << "Numero de RAMQ    : " << m_numRAMQ << endl;
	oss << "---------------------" << endl;

	return oss.str();
}
Personne* Entraineur::clone() const
{
	return new Entraineur(*this);
}

void Entraineur::verifieInvariantEntraineur() const
{
	INVARIANT(util::validerNumRAMQ(reqNumRAMQ(), reqNom(), reqPrenom(), reqDateNaissance().reqJour(), reqDateNaissance().reqMois(),
			reqDateNaissance().reqAnnee(), reqSexe()));
	util::Date dateAujourdhui;
	util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_ENTRAINEUR));
	INVARIANT(reqDateNaissance() <  dateNaissanceMinimale)
}

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
	verifieInvariantJoueur();
}

const std::string Joueur::reqPosition() const
{
	return m_position;
}

std::string Joueur::reqPersonneFormate() const
{
	ostringstream oss;

	oss << Personne::reqPersonneFormate();
	oss << "Position          : " << m_position << endl;
	oss << "---------------------" << endl;

	return oss.str();
}

Personne* Joueur::clone() const
{
	return new Joueur(*this);
}

bool Joueur::verifiePosition(const std::string& p_position) const
{
	bool valide = true;
	if(p_position != "ailier" && p_position != "centre" && p_position != "défenseur" && p_position != "gardien")
	{
		valide = false;
	}

	return valide;
}

void Joueur::verifieInvariantJoueur() const
{
	INVARIANT(verifiePosition(m_position));
	util::Date dateAujourdhui;
	util::Date dateNaissanceMinimale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MINIMAL_JOUEUR));
	INVARIANT(reqDateNaissance() <  dateNaissanceMinimale)
	util::Date dateNaissanceMaximale(dateAujourdhui.reqJour(), dateAujourdhui.reqMois(), (dateAujourdhui.reqAnnee() - AGE_MAXIMAL_JOUEUR - 1));
	INVARIANT(dateNaissanceMaximale < reqDateNaissance())
}

Annuaire::Annuaire(const std::string p_nomClub):
		 	       m_nomClub(p_nomClub)
{

}

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

const std::string Annuaire::reqNomClub() const
{
	return m_nomClub;
}
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

void Annuaire::ajouterPersonne (const Personne& p_personne)
{
	m_vMembres.push_back(p_personne.clone());
}

void Annuaire::operator=(const Annuaire& p_annuaire)
{
	Annuaire temp(p_annuaire);
	m_nomClub = temp.m_nomClub;
	m_vMembres = temp.m_vMembres;
}

Annuaire::~Annuaire()
{
	m_vMembres.clear();
}

}




