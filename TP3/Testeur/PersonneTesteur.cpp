/**
 * \file PersonneTesteur.cpp
 * \brief  Fichier de tests unitaires pour la classe Personne
 * \author David J Ross
 * \version 1
 * \date 16 avril 2020
 */


#include <gtest/gtest.h>
#include "Joueur.h"
#include "Date.h"
#include "validationFormat.h"


/**
 * \brief Test du Constructeur Personne::Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   const std::string& p_telephone) en passant par le constructeur enfant Joueur
 * cas valide : <br>
 * 	PersonneValide :	Personne avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	PersonneNomInvalide: Personne avec un nom invalide (qui n'est pas uniquement composé de lettres)
 * 	PersonnePrenomInvalide: Personne avec un prenom invalide (qui n'est pas uniquement composé de lettres)
 * 	PersonneDateNaissanceInvalide : Personne avec une date de naissance non valide
 * 	PersonneTelephoneInvalide : Personne avec un téléphone non valide
 */
TEST(PersonneConstructeur, PersonneValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
	ASSERT_TRUE(util::validerFormatNom(j.reqNom()));
	ASSERT_TRUE(util::validerFormatNom(j.reqPrenom()));
	ASSERT_TRUE(util::validerTelephone(j.reqTelephone()));
	ASSERT_TRUE(util::Date::validerDate(j.reqDateNaissance().reqJour(), j.reqDateNaissance().reqMois(), j.reqDateNaissance().reqAnnee()));
}

TEST(PersonneConstructeur, PersonneNomInvalide)
{
	util::Date d(25, 8, 2004);
	ASSERT_THROW(hockey::Joueur j("Nom6", "Prenom", d, "418 498-4193", "centre"),PreconditionException);
}

TEST(PersonneConstructeur, PersonnePrenomInvalide)
{
	util::Date d(25, 8, 2004);
	ASSERT_THROW(hockey::Joueur j("Nom", "Prenom6", d, "418 498-4193", "centre"),PreconditionException);
}

TEST(PersonneConstructeur, PersonneDateNaissanceInvalide)
{
	ASSERT_THROW(hockey::Joueur j("Nom", "Prenom", (util::Date (25, 8, 2)), "418 498-4193", "centre"),PreconditionException);
}

TEST(PersonneConstructeur, PersonneTelephoneInvalide)
{
	util::Date d(25, 8, 2004);
	ASSERT_THROW(hockey::Joueur j("Nom", "Prenom", d, "41893", "centre"),PreconditionException);
}

/**
 * \class PersonneBase
 * \brief Fixture pour la création d'un objet Personne avec des informations de base
 * utilisé dans plusieurs tests
 */
class PersonneBase : public ::testing::Test
{
public:
	PersonneBase():f_personneBase("Nom", "Prenom", (util::Date (25, 8, 2004)), "418 498-4193", "centre"){}

	hockey::Joueur f_personneBase;
};


/**
 * \brief Test de la méthode const std::string reqNom() const
 * cas valide : <br>
 * 	reqNomValide :	Personne avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(PersonneBase, reqNomValide)
{
	ASSERT_EQ("Nom", f_personneBase.reqNom());
}

/**
 * \brief Test de la méthode const std::string reqPrenom() const
 * cas valide : <br>
 * 	reqPrenomValide :	Personne avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(PersonneBase, reqPrenomValide)
{
	ASSERT_EQ("Prenom", f_personneBase.reqPrenom());
}

/**
 * \brief Test de la méthode const Date reqDateNaissance() const
 * cas valide : <br>
 * 	reqDateNaissanceValide :	Personne avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(PersonneBase, reqDateNaissanceValide)
{
	ASSERT_EQ((util::Date (25, 8, 2004)), f_personneBase.reqDateNaissance());
}


/**
 * \brief Test de la méthode const std::string reqTelephone() const
 * cas valide : <br>
 * 	reqTelephoneValide :	Personne avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(PersonneBase, reqTelephoneValide)
{
	ASSERT_EQ("418 498-4193", f_personneBase.reqTelephone());
}

/**
 * \brief Test de la méthode void asgTelephone(const std::string& p_telephone)
 * cas valide : <br>
 * 	asgTelephoneValide :	Assignation avec un numéro de téléphone valide
 * <br>
 * cas invalide : <br>
 * 	asgTelephoneInvalide : 	Assignation avec un numéro de téléphone invalide
 */
TEST_F(PersonneBase, asgTelephoneValide)
{
	f_personneBase.asgTelephone("581 337-2278");
	ASSERT_EQ("581 337-2278", f_personneBase.reqTelephone());
}

TEST_F(PersonneBase, asgTelephoneInvalide)
{
	ASSERT_THROW(f_personneBase.asgTelephone("57"),PreconditionException);
}

/**
 * \brief Test de la méthode bool operator ==(const Personne& p_personne) const
 * cas valide : <br>
 * 	egualeValide :	Égualité valide entre deux personnes identiques
 * <br>
 * cas invalide : <br>
 * 	egualeInvalide : 	Égualité invalide entre deux personnes différentes
 */
TEST_F(PersonneBase, egualeValide)
{
	hockey::Joueur j("Nom", "Prenom", (util::Date (25, 8, 2004)), "418 498-4193", "centre");
	ASSERT_TRUE(f_personneBase == j);
}

TEST_F(PersonneBase, egualeInvalide)
{
	hockey::Joueur j("NomDifferent", "Prenom", (util::Date (25, 8, 2004)), "418 498-4193", "centre");
	ASSERT_FALSE(f_personneBase == j);
}

