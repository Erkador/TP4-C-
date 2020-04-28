/**
 * \file Entraineur.h
 * \brief Fichier contenant l'interface de la classe Entraineur qui permet le stockage d'un entraineur et des ses informations.
 * \author David Jalbert Ross
 * \version 1.0
 * \date 16 avril 2020
 */

#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include "Date.h"
#include "ContratException.h"
#include "Personne.h"


static const int AGE_MINIMAL_ENTRAINEUR = 18;

/**
 * \namespace Hockey
 * \brief Ce namespace contient le code spécifique au développement d'un outils de gestion d'annuaire
 */
namespace hockey
{

/**
 * \class Entraineur
 * \brief Cette classe permet le stockage d'informations associées à un entraineur
 *
 * 		On peut cloner l'entraineur à l'aide de la méthode clone()
 *
 * 		Attributs: m_numRAMQ: un string contenant le numéro de RAMQ de l'entraineur
 * 				   m_sexe : un char contenant le sexe de l'entraineur (M/F)
 */
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
	void verifieInvariant() const;
	std::string m_numRAMQ;
	char m_sexe;
};
}

#endif
