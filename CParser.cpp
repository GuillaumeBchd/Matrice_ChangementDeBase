/**
 * \file CParser.cpp
 * \brief Fichier de m�thodes de la classe CParser.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 2 mai 2019
 *
 * Fichier de m�thodes d'une classe template et donc inclus � la fin du .h, exclure ce cpp du projet pour
 * le bon fonctionnement de celui-ci.
 *
 */

#include "CParser.h"

const char *pcMotsCles[] = { "TypeMatrice", "NBLignes", "NBColonnes", "Matrice", "[", "]" };
const char *pcValeurs[] = { "double" };

/**
 * \fn int CParser::PARLectureMot(std::ifstream & fichier, char * pcMot)
 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : Lecture du mot suivant du ifstream & fichier pass� en param�tre
 *
 * \param fichier ifstream & : fichier ouvert (au moins en mode lecture),
 * \param pcMot char * : chaine de caract�res ou sera stock�
 * \return 0=mot-cl�, 1=endOfFile (fichier.oef()) et 5=valeur.
 */
int CParser::PARLectureMot(std::ifstream & fichier, char * pcMot)
{
	char cMyChar;
	unsigned int uiIndice = 0;

	//Tant que l'on a pas atteint la fin du fichier, on continue le programme :
	while (!fichier.eof()) {
		fichier.get(cMyChar);
		//Si on lit un caractere qui d�marque la s�paration d'un mot, arrete de remplir pcMot et on avance jusqu'au prochain mot
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
		//Derni�re ligne du fichier
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
 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : On compare si deux cha�nes de caract�res sont identiques.
 *
 * \param pcString1 char * : Premiere chaine � comparer.
 * \param pcString2 const char * Deuxi�me chaine (constante) � comparer.
 * \return 0=Les chaines sont diff�rentes et 1=Les chaines sont identiques.
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
 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : On r�cup�re le num�ro d'un mot-cl�.
 *
 * \param pcString char * : Mot-cl� dont on d�sire r�cup�rer le code.
 * \return -1=Mot-cl� inconnu, sinon code correspondant � la position dans pcMotsCles.
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
 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : On r�cup�re le num�ro d'une valeur.
 *
 * \param pcString char * : Valeur dont on d�sire r�cup�rer le code.
 * \return -1=Valeur inconnue, sinon code correspondant � la position dans pcValeurs.
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