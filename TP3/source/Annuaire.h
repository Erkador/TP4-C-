/**
 * \file Annuaire.h
 * \brief Fichier contenant l'interface de la classe Annuaire qui permet le stockage de joueurs et d'entraineurs
 * \author David Jalbert Ross
 * \version 1.0
 * \date 16 avril 2020
 */

#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_

#include "Date.h"
#include <vector>
#include "ContratException.h"
#include "Personne.h"

/**
 * \namespace Hockey
 * \brief Ce namespace contient le code spécifique au développement d'un outils de gestion d'annuaire
 */
namespace hockey
{

/**
 * \class Annuaire
 * \brief Cette classe permet le stockage de joueurs et d'entraineurs dans un vector
 *
 * 		On peut ajouter un membre à l'annuaire avec la méthode ajouterPersonne()
 *
 * 		Attributs: m_vMembres: un vector de Personne contenant les personnes membres du club
 * 				   m_nomClub : un string contenant le nom du club
 */
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
