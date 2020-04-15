/**
 * \file ValidationFormat.cpp
 * \brief Fichier d'implementation des méthodes de validation
 * \author David Jalbert Ross
 * \version 1.1
 * \date 23 février 2019
 */

#include <iostream>
#include <string>
#include <cstring>


using namespace std;

namespace util
{
/**
 * \brief Détermine si un code régional est valide
 * \param[in] p_regional est un string contenant le code régional, doit être 3 caractères de long et composé de chiffres
 * \return un booléen indiquant si le code régional est valide
 */
bool checkRegionalCode(const std::string& p_regional)
{
	std::string regionalList[33] = {"403", "780", "604", "236", "250", "778", "902", "204", "506", "905",
									"519", "289", "705", "613", "807", "416", "647", "438", "514", "450"
									"579", "418", "581", "819", "873", "306", "709", "867", "800", "866"
									"877", "888", "855"};

	bool found{false};
	int i = 0;
	while(!found && i < 33)
	{
		if(p_regional == regionalList[i])
		{
			found = true;
		}
		i++;
	}

	if(p_regional[0] == '9')
	{
		found = true;
	}

	return found;
}

/**
 * \brief Détermine si un numéro de téléphone est valide
 * \param[in] p_telephone est un string contenant le numéro de téléphone à valider
 * \return un booléen indiquant si le numéro de téléphone est valide
 */
bool validerTelephone(const std::string& p_telephone)
{
	std::string regional;
	for(int i = 0; i < 3;i++)
	{
		regional+= p_telephone[i];
	}

	bool valide{true};
	valide = checkRegionalCode(regional);
	int lenStr = p_telephone.length();
	int i = 0;
	while(i < lenStr && valide)
	{
		if(i == 3)
		{
			if(p_telephone[i] != ' ')
			{
				valide = false;
			}
		}
		else if(i == 7)
		{
			if(p_telephone[i] != '-')
			{
				valide = false;
			}
		}
		else
		{
			if(!isdigit(p_telephone[i]))
			{
				valide = false;
			}
		}
		i++;
	}

	return valide;
}

/**
 * \brief Détermine si un numéro RAMQ est valide
 * \param[in] p_numero est un string contenant le numéro RAMQ à valider
 * \param[in] p_nom est un string contenant le nom associé au numéro RAMQ
 * \param[in] p_prenom est un string contenant le prenom associé au numéro RAMQ
 * \param[in] p_jourNaissance est un int contenant le jour de la date de naissance
 * \param[in] p_moisNaissance est un int contenant le mois de la date de naissance
 * \param[in] p_anneeNaissance est un int contenant l'annee de la date de naissance
 * \param[in] p_sex est un char contenant le sexe, doit être 'M' ou 'F'
 * \return un booléen indiquant si le numéro RAMQ est valide
 */
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const
std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int
p_anneeNaissance, char p_sex)
{
	bool valide{true};

	int lenStr = p_numero.length();
	if (lenStr != 14)
	{
		valide = false;
	}

	for(int i = 0; i < 3; i++)
	{
		if(toupper(p_numero[i]) != toupper(p_nom[i]))
		{
			valide = false;
		}
	}

	if(toupper(p_numero[3]) != toupper(p_prenom[0]))
	{
		valide = false;
	}

	if(p_numero[4] != ' ' || p_numero[9] != ' ')
	{
		valide = false;
	}

	if((p_numero[5] - 48) != (p_anneeNaissance / 10 % 10) || (p_numero[6] - 48) != (p_anneeNaissance % 10))
	{
		valide = false;
	}


	if(p_moisNaissance < 10)
	{
		if(p_sex == 'F')
		{
			if(p_numero[7] != '5' || (p_numero[8] - 48) != p_moisNaissance)
			{
				valide = false;
			}
		}
		else
		{
			if(p_numero[7] != '0' || (p_numero[8] - 48) != p_moisNaissance)
			{
				valide = false;
			}
		}
	}
	else
	{
		if(p_sex == 'F')
		{
			if(p_numero[7] != '6' || (p_numero[8] - 48) != (p_moisNaissance - 10))
			{
				valide = false;
			}
		}
		else
		{
			if(p_numero[7] != '1' || (p_numero[8] - 48) != (p_moisNaissance - 10))
			{
				valide = false;
			}
		}
	}

	if(p_jourNaissance < 10)
	{
		if(p_numero[10] != '0' || (p_numero[11] - 48) != p_jourNaissance)
		{
			valide = false;
		}
	}
	else if(p_jourNaissance < 20)
	{
		if(p_numero[10] != '1' || (p_numero[11] - 48) != p_jourNaissance - 10)
		{
			valide = false;
		}
	}
	else if(p_jourNaissance < 30)
	{
		if(p_numero[10] != '2' || (p_numero[11] - 48) != p_jourNaissance - 20)
		{
			valide = false;
		}
	}
	else
	{
		if(p_numero[10] != '3' || (p_numero[11] - 48) != p_jourNaissance - 30)
		{
			valide = false;
		}
	}

	return valide;
}

/**
 * \brief Détermine si un nom ou prénom est valide
 * \param[in] p_nom est un string contenant le nom ou prénom à valider
 * \return un booléen indiquant si le nom ou prénom est valide
 */
bool validerFormatNom(const std::string& p_nom)
{
	bool valide{true};

	int lenStr = p_nom.length();
	if (lenStr == 0)
	{
		valide = false;
	}
	else
	{
		int i = 0;
		while(i < lenStr && valide)
		{
			if(!isalpha(p_nom[i]))
			{
				valide = false;
			}
			i++;
		}
	}

	return valide;
}
}




