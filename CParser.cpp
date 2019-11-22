/**
 * \file CParser.cpp
 * \brief Fichier de méthodes de la classe CParser.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 2 mai 2019
 *
 * Fichier de méthodes d'une classe template et donc inclus à la fin du .h, exclure ce cpp du projet pour
 * le bon fonctionnement de celui-ci.
 *
 */

#include "CParser.h"

const char *pcMotsCles[] = { "TypeMatrice", "NBLignes", "NBColonnes", "Matrice", "[", "]" };
const char *pcValeurs[] = { "double" };

/**
 * \fn int CParser::PARLectureMot(std::ifstream & fichier, char * pcMot)
 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : Lecture du mot suivant du ifstream & fichier passé en paramètre
 *
 * \param fichier ifstream & : fichier ouvert (au moins en mode lecture),
 * \param pcMot char * : chaine de caractères ou sera stocké
 * \return 0=mot-clé, 1=endOfFile (fichier.oef()) et 5=valeur.
 */
int CParser::PARLectureMot(std::ifstream & fichier, char * pcMot)
{
	char cMyChar;
	unsigned int uiIndice = 0;

	//Tant que l'on a pas atteint la fin du fichier, on continue le programme :
	while (!fichier.eof()) {
		fichier.get(cMyChar);
		//Si on lit un caractere qui démarque la séparation d'un mot, arrete de remplir pcMot et on avance jusqu'au prochain mot
		if (cMyChar == ' ' || cMyChar == '\n' || cMyChar == '=') {
			while ((cMyChar == ' ' || cMyChar == '\n' || cMyChar == '=') && !fichier.eof()) {
				if (cMyChar == '=') {
					pcMot[uiIndice] = '\0';
					return 5;
				}
				fichier.get(cMyChar);
			}
			pcMot[uiIndice] = '\0';
			if (uiIndice > 0) {
				fichier.unget();
				return 0;
			}
			uiIndice = 0;
		}
		//Dernière ligne du fichier
		if (fichier.eof() || fichier.fail()) {
			pcMot[uiIndice] = '\0';
			return 0;
		}
		pcMot[uiIndice] = cMyChar;
		uiIndice++;
	}
	pcMot[uiIndice] = '\0';
	if (uiIndice > 0) {
		fichier.unget();
		return 0;
	}

	return 0;
}

/**
 * \fn int CParser::PARStringCompare(char * pcString1, const char * pcString2)
 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : On compare si deux chaînes de caractères sont identiques.
 *
 * \param pcString1 char * : Premiere chaine à comparer.
 * \param pcString2 const char * Deuxième chaine (constante) à comparer.
 * \return 0=Les chaines sont différentes et 1=Les chaines sont identiques.
 */
int CParser::PARStringCompare(char * pcString1, const char * pcString2)
{
	char *pcPointeur1 = pcString1;
	const char *pcPointeur2 = pcString2;
	while (*pcPointeur1 == *pcPointeur2) {
		if (*pcPointeur1 == '\0' && *pcPointeur2 == '\0') {
			return 1;
		}
		pcPointeur1++;
		pcPointeur2++;
	}
	return 0;
}

/**
 * \fn int CParser::PARGetCodeMotCle(char * pcString)
 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : On récupère le numéro d'un mot-clé.
 *
 * \param pcString char * : Mot-clé dont on désire récupérer le code.
 * \return -1=Mot-clé inconnu, sinon code correspondant à la position dans pcMotsCles.
 */
int CParser::PARGetCodeMotCle(char * pcString)
{
	for (int iIndice = 0; iIndice < sizeof(pcMotsCles); iIndice++) {
		if (PARStringCompare(pcString, pcMotsCles[iIndice])) {
			return iIndice;
		}
	}

	return -1;
}

/**
 * \fn int CParser::PARGetCodeValeur(char * pcString)
 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : On récupère le numéro d'une valeur.
 *
 * \param pcString char * : Valeur dont on désire récupérer le code.
 * \return -1=Valeur inconnue, sinon code correspondant à la position dans pcValeurs.
 */
int CParser::PARGetCodeValeur(char * pcString)
{
	for (int iIndice = 0; iIndice < sizeof(pcValeurs); iIndice++) {
		if (PARStringCompare(pcString, pcValeurs[iIndice])) {
			return iIndice;
		}
	}

	return -1;
}