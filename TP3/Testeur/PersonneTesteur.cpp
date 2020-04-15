#include <gtest/gtest.h>
#include "Personne.h"
#include "Date.h"
#include "validationFormat.h"

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

class PersonneBase : public ::testing::Test
{
public:
	PersonneBase():f_personneBase("Nom", "Prenom", (util::Date (25, 8, 2004)), "418 498-4193", "centre"){}

	hockey::Joueur f_personneBase;
};

TEST_F(PersonneBase, reqNomValide)
{
	ASSERT_EQ("Nom", f_personneBase.reqNom());
}

TEST_F(PersonneBase, reqPrenomValide)
{
	ASSERT_EQ("Prenom", f_personneBase.reqPrenom());
}

TEST_F(PersonneBase, reqDateNaissanceValide)
{
	ASSERT_EQ((util::Date (25, 8, 2004)), f_personneBase.reqDateNaissance());
}

TEST_F(PersonneBase, reqTelephoneValide)
{
	ASSERT_EQ("418 498-4193", f_personneBase.reqTelephone());
}

TEST_F(PersonneBase, asgTelephoneValide)
{
	f_personneBase.asgTelephone("581 337-2278");
	ASSERT_EQ("581 337-2278", f_personneBase.reqTelephone());
}

TEST_F(PersonneBase, asgTelephoneInvalide)
{
	ASSERT_THROW(f_personneBase.asgTelephone("57"),PreconditionException);
}

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
