#include <gtest/gtest.h>
#include "Personne.h"
#include "Date.h"
#include "validationFormat.h"

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

class EntraineurBase : public ::testing::Test
{
public:
	EntraineurBase():f_entraineurBase("Jalbert", "David", util::Date (25, 8, 1999), "418 498-4193", "JALD 9908 2511", 'M'){}

	hockey::Entraineur f_entraineurBase;
};

TEST_F(EntraineurBase, reqRAMQValide)
{
	ASSERT_EQ("JALD 9908 2511", f_entraineurBase.reqNumRAMQ());
}

TEST_F(EntraineurBase, reqSexeValide)
{
	ASSERT_EQ('M', f_entraineurBase.reqSexe());
}
