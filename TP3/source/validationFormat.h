/**
 * \file ValidationFormat.h
 * \brief Fichier contenant l'interface de différentes méthodes de validation de format
 * \author David Jalbert Ross
 * \version 1.1
 * \date 23 février 2019
 */

/**
 * \namespace util
 * \brief Ce namespace contient des méthodes et des classes utilitaires
 */
namespace util
{

bool validerTelephone(const std::string& p_telephone);
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const
std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int
p_anneeNaissance, char p_sex);
bool validerFormatNom(const std::string& p_nom);

}
