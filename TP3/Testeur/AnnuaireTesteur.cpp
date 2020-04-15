#include <gtest/gtest.h>
#include "Personne.h"
#include "Date.h"
#include "validationFormat.h"

TEST(AnnuaireConstructeur, AnnuaireVideValide)
{
	hockey::Annuaire a("Test");
	ASSERT_TRUE(a.m_vMembres.size() == 0);
	ASSERT_TRUE(a.reqNomClub() == "Test");
}

TEST(AnnuaireConstructeur, AnnuaireNonVideValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
	hockey::Annuaire a("Test");
	a.ajouterPersonne(j);
	hockey::Annuaire b(a);
	ASSERT_TRUE(b.m_vMembres.size() == 1);
	ASSERT_TRUE(b.reqNomClub() == "Test");
}

class AnnuaireBase : public ::testing::Test
{
public:
	AnnuaireBase():f_annuaireBase("Test"){}

	hockey::Annuaire f_annuaireBase;
};

TEST_F(AnnuaireBase, reqNomClubValide)
{
	ASSERT_EQ("Test", f_annuaireBase.reqNomClub());
}

TEST_F(AnnuaireBase, ajouterPersonneValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
	f_annuaireBase.ajouterPersonne(j);
	ASSERT_TRUE(f_annuaireBase.m_vMembres.size() == 1);
}

TEST_F(AnnuaireBase, AssignerValide)
{
	hockey::Annuaire a = f_annuaireBase;
	ASSERT_TRUE(a.reqNomClub() == "Test");

}

