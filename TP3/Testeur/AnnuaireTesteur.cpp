/**
 * \file AnnuaireTesteur.cpp
 * \brief  Fichier de tests unitaires pour la classe Annuaire
 * \author David J Ross
 * \version 1
 * \date 16 avril 2020
 */


#include <gtest/gtest.h>
#include "Annuaire.h"
#include "Joueur.h"
#include "Date.h"
#include "validationFormat.h"



/**
 * \brief Test du Constructeur Annuaire::Annuaire(const std::string p_nomClub) et de
								Annuaire::Annuaire(const Annuaire& p_annuaire)
 * cas valide : <br>
 * 	AnnuaireVideValide :	Annnuaire valide avec uniquement un nom de club
 * 	AnnuaireNonVideValide : Annuaire valide construit à partir d'un autre annuaire valide
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
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

/**
 * \class AnnuaireBase
 * \brief Fixture pour la création d'un objet Annuaire avec un nom de club valide
 * utilisé dans plusieurs tests
 */
class AnnuaireBase : public ::testing::Test
{
public:
	AnnuaireBase():f_annuaireBase("Test"){}

	hockey::Annuaire f_annuaireBase;
};

/**
 * \brief Test de la méthode const std::string reqNomClub() const
 * cas valide : <br>
 * 	reqNomClubValide :	Annuaire avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(AnnuaireBase, reqNomClubValide)
{
	ASSERT_EQ("Test", f_annuaireBase.reqNomClub());
}

/**
 * \brief Test de la méthode void ajouterPersonne (const Personne& p_personne)
 * cas valide : <br>
 * 	ajouterPersonneValide :	Ajout d'un joueur valide
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(AnnuaireBase, ajouterPersonneValide)
{
	util::Date d(25, 8, 2004);
	hockey::Joueur j("Nom", "Prenom", d, "418 498-4193", "centre");
	f_annuaireBase.ajouterPersonne(j);
	ASSERT_TRUE(f_annuaireBase.m_vMembres.size() == 1);
}

/**
 * \brief Test de la méthode void operator=(const Annuaire& p_annuaire)
 * cas valide : <br>
 * 	ajouterPersonneValide :	Assignation d'un annuaire valide avec un opérateur =
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(AnnuaireBase, AssignerValide)
{
	hockey::Annuaire a = f_annuaireBase;
	ASSERT_TRUE(a.reqNomClub() == "Test");

}

