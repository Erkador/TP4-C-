/**
 * \file EntraineurTesteur.cpp
 * \brief  Fichier de tests unitaires pour la classe Entraineur
 * \author David J Ross
 * \version 1
 * \date 16 avril 2020
 */

#include <gtest/gtest.h>
#include "Entraineur.h"
#include "Date.h"
#include "validationFormat.h"


/**
 * \brief Test du Constructeur Entraineur::Entraineur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			   const std::string& p_telephone, const std::string& p_numRAMQ, char p_sexe)
 * cas valide : <br>
 * 	EntraineurValide :	Entraineur avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	EntraineurRAMQInvalide: Entraineur avec un numéro de RAMQ invalide
 * 	EntraineurAgeInvalide: Entraineur avec un âge invalide, inférieur a 18
 */
TEST(EntraineurConstructeur, EntraineurValide)
{
	util::Date d(25, 8, 1999);
	hockey::Entraineur e("Jalbert", "David", d, "418 498-4193", "JALD 9908 2511", 'M');
	ASSERT_TRUE(util::validerNumRAMQ( e.reqNumRAMQ(), e.reqNom(), e.reqPrenom(), e.reqDateNaissance().reqJour(), e.reqDateNaissance().reqMois(),
			e.reqDateNaissance().reqAnnee(), e.reqSexe()));
}

TEST(EntraineurConstructeur, EntraineurRAMQInvalide)
{
	util::Date d(25, 8, 1999);
	ASSERT_THROW(hockey::Entraineur e("Jalbert", "David", d, "418 498-4193", "9908", 'M'), PreconditionException);
}

TEST(EntraineurConstructeur, EntraineurAgeInvalide)
{
	util::Date d(25, 8, 2005);
	ASSERT_THROW(hockey::Entraineur e("Jalbert", "David", d, "418 498-4193", "JALD 0508 2511", 'M'), PreconditionException);
}


/**
 * \class EntraineurBase
 * \brief Fixture pour la création d'un objet Entraineur avec des informations de base
 * utilisé dans plusieurs tests
 */
class EntraineurBase : public ::testing::Test
{
public:
	EntraineurBase():f_entraineurBase("Jalbert", "David", util::Date (25, 8, 1999), "418 498-4193", "JALD 9908 2511", 'M'){}

	hockey::Entraineur f_entraineurBase;
};

/**
 * \brief Test de la méthode const std::string reqRAMQ() const
 * cas valide : <br>
 * 	reqRAMQValide :	Entraineur avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(EntraineurBase, reqRAMQValide)
{
	ASSERT_EQ("JALD 9908 2511", f_entraineurBase.reqNumRAMQ());
}


/**
 * \brief Test de la méthode char reqSexe() const
 * cas valide : <br>
 * 	reqRAMQValide :	Entraineur avec des infos valides
 * <br>
 * cas invalide : <br>
 * 	Aucun d'identifié
 */
TEST_F(EntraineurBase, reqSexeValide)
{
	ASSERT_EQ('M', f_entraineurBase.reqSexe());
}
