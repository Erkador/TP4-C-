/**
 * \file Personne.h
 * \brief Fichier contenant l'interface de la classe Personne qui permet le stockage d'une personnes et des ses informations.
 * \author David Jalbert Ross
 * \version 2.0
 * \date 16 avril 2020
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Date.h"
#include <vector>
#include "ContratException.h"


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
	void verifieInvariant() const;
	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;
};

}


#endif
