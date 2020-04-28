/**
 * \file JoueurTesteur.cpp
 * \brief  Fichier de tests unitaires pour la classe Joueur
 * \author David J Ross
 * \version 1
 * \date 16 avril 2020
 */

#include <gtest/gtest.h>
#include "Joueur.h"
#include "Date.h"
#include "validationFormat.h"

/**
 * \brief Test du Constructeur Joueur::Joueur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   const std::string& p_telephone, const std::string& p_position)
 * cas valide : <br>
 * 	JoueurValide :	Joueur avec des informations valides
 * <br>
 * cas invalide : <br>
 * 	JoueurAgeInvalide: Joueur avec un age invalide, inférieur à 15 ou supérieur à 18
 * 	JoueurPositionInvalide : Joueur avec une position invalide (autre que centre, ailier, défenseur ou guardien)
 */

TEST(JoueurConstructeur, JoueurValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
}

TEST(JoueurConstructeur, JoueurAgeInvalide)
{
	util::Date d(25, 8, 2001);
	ASSERT_THROW(hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre"),PreconditionException);
}

TEST(JoueurConstructeur, JoueurPositionInvalide)
{
	util::Date d(25, 8, 2004);
	ASSERT_THROW(hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "wrabla"),PreconditionException);
}

/**
 * \brief Test de la méthode const std::string reqPosition() const
 * cas valide : <br>
 * 	reqPositionValide :	Joueur avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */

TEST(JoueurBase, reqPositionValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
	ASSERT_EQ("centre", j.reqPosition());
}
