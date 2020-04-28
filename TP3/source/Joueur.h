/**
 * \file Joueur.h
 * \brief Fichier contenant l'interface de la classe Joueur qui permet le stockage d'un joueur et des ses informations.
 * \author David Jalbert Ross
 * \version 1.0
 * \date 16 avril 2020
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Date.h"
#include "ContratException.h"
#include "Personne.h"

static const int AGE_MINIMAL_JOUEUR = 15;
static const int AGE_MAXIMAL_JOUEUR = 17;

/**
 * \namespace Hockey
 * \brief Ce namespace contient le code spécifique au développement d'un outils de gestion d'annuaire
 */
namespace hockey
{

/**
 * \class Joueur
 * \brief Cette classe permet le stockage d'informations associées à un joueur
 *
 * 		On peut cloner le joueur à l'aide de la méthode clone()
 *
 * 		Attributs: m_position: un string contenant la position du joueur
 */
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
	void verifieInvariant() const;
	std::string m_position;
};
}

#endif
