#include <gtest/gtest.h>
#include "Personne.h"
#include "Date.h"
#include "validationFormat.h"

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

TEST(JoueurBase, reqPositionValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
	ASSERT_EQ("centre", j.reqPosition());
}