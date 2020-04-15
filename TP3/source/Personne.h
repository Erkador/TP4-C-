/**
 * \file Personne.h
 * \brief Fichier contenant l'interface de la classe Personne qui permet le stockage d'une personnes et des ses informations.
 * \author David Jalbert Ross
 * \version 1.0
 * \date 23 février 2019
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Date.h"
#include <vector>
#include "ContratException.h"


static const int AGE_MINIMAL_ENTRAINEUR = 18;
static const int AGE_MINIMAL_JOUEUR = 15;
static const int AGE_MAXIMAL_JOUEUR = 17;

/**
 * \namespace Hockey
 * \brief Ce namespace contient le code spécifique au développement d'un outils de gestion d'annuaire
 */
namespace hockey
{
/**
 * \class Personne
 * \brief Cette classe permet le stockage d'informations associées à une personne
 *
 * 		On peut assigner un nouveau numéro de téléphone à une personne avec
 * 		asgTelephone(std::string p_telephone)
 *
 * 		Attributs: m_nom: un string contenant le nom de la personne
 * 				   m_prenom: un string contenant le prénom de la personne
 * 				   m_dateNaissance: un objet Date contenant la date de naissance de la personne
 * 				   m_telephone: un string contenant le numéro de téléphone de la personne
 */
class Personne
{
public:
	Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_telephone);

	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const util::Date& reqDateNaissance() const;
	const std::string& reqTelephone() const;

	void asgTelephone(const std::string& p_telephone);

	bool operator ==(const Personne& p_personne) const;

	virtual std::string reqPersonneFormate() const;
	virtual ~Personne() {} ;
	virtual Personne* clone() const=0;

private:
	void verifieInvariantPersonne() const;
	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;
};

class Entraineur: public Personne
{
public:
	Entraineur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   const std::string& p_telephone, const std::string& p_numRAMQ, char p_sexe);

	const std::string reqNumRAMQ() const;
	char reqSexe() const;

	virtual std::string reqPersonneFormate() const;
	virtual ~Entraineur() {} ;
	virtual Personne* clone() const;
private:
	void verifieInvariantEntraineur() const;
	std::string m_numRAMQ;
	char m_sexe;
};

class Joueur: public Personne
{
public:
	Joueur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   const std::string& p_telephone, const std::string& p_position);

	const std::string reqPosition() const;
	virtual std::string reqPersonneFormate() const;
	virtual ~Joueur() {} ;
	virtual Personne* clone() const;

private:
	bool verifiePosition(const std::string& p_position) const;
	void verifieInvariantJoueur() const;
	std::string m_position;
};

class Annuaire
{
public:
	Annuaire(const std::string p_nomClub);
	Annuaire(const Annuaire& p_annuaire);

	const std::string reqNomClub() const;
	const std::string reqAnnuaireFormate() const;
	void ajouterPersonne (const Personne& p_personne);

	void operator=(const Annuaire& p_annuaire);

	~Annuaire();

	std::vector<Personne*> m_vMembres;

private:
	void verifieInvariantAnnuaire() const;
	std::string m_nomClub;
};

}


#endif
