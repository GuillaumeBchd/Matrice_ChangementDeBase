/**
 * \file CParser.h
 * \brief Fichier header de la classe CParser.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 1 mai 2019
 *
 * Fichier header contenant la classe CParser contenant des m�thodes pour lire des fichiers txt sous un certain format, et cr�er des CMatrices<double>.
 * Format de fichier compatible :
 * ##############################
 *
 * TypeMatrice=<type_base_C>
 * NBLignes=<Nombre_de_lignes_de_la_matrice>
 * NBColonnes=<Nombre_de_colonnes_de_la_matrice>
 * Matrice=[
 * <Ligne_1 : autant d'�l�ments que de colonnes>
 * <Ligne_n : autant d'�l�ments que de colonnes>
 * ...
 * <Ligne_NBLignes : autant d'�l�ments que de colonnes>
 * ]
 *
 * ##############################
 * /!\ Attention /!\ Ce fichier contenant des m�thodes et fonctions template, un fichier cpp contenant les m�thodes est inclut � la fin.
 * Pour la bonne utilisation de cette librairie, ne pas inclure le fichier cpp dans le projet.
 *
 */

#ifndef CParser_h
#define CParser_h

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "CException.h"
#include "CMatrice.h"

//Codes d'erreur : � partir de 300 pour cette classe
#define EXC_OuvertureFichier 300
#define EXC_UnexpectedSymbol 301
#define EXC_UnexpectedKeyWord 302
#define EXC_DuplicateLine 303
#define EXC_UnknownError 304
#define EXC_InvalidMatrixParameters 305
#define EXC_UnknownMatrixType 306


class CParser {

private:

	/**
	 * \fn static int CParser::PARLectureMot(std::ifstream & fichier, char * pcMot)
	 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : Lecture du mot suivant du ifstream & fichier pass� en param�tre
	 *
	 * \param fichier ifstream & : fichier ouvert (au moins en mode lecture),
	 * \param pcMot char * : chaine de caract�res ou sera stock�
	 * \return 0=mot-cl�, 1=endOfFile (fichier.oef()) et 5=valeur.
	 */
	static int PARLectureMot(std::ifstream& fichier, char * pcMot);

	/**
	 * \fn static int CParser::PARStringCompare(char * pcString1, const char * pcString2)
	 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : On compare si deux cha�nes de caract�res sont identiques.
	 *
	 * \param pcString1 char * : Premiere chaine � comparer.
	 * \param pcString2 const char * Deuxi�me chaine (constante) � comparer.
	 * \return 0=Les chaines sont diff�rentes et 1=Les chaines sont identiques.
	 */
	static int PARStringCompare(char *pcString1, const char * pcString2);
	 
	/**
	 * \fn static int CParser::PARGetCodeMotCle(char * pcString)
	 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : On r�cup�re le num�ro d'un mot-cl�.
	 *
	 * \param pcString char * : Mot-cl� dont on d�sire r�cup�rer le code.
	 * \return -1=Mot-cl� inconnu, sinon code correspondant � la position dans pcMotsCles.
	 */
	static int PARGetCodeMotCle(char *pcString);

	/**
	 * \fn static int CParser::PARGetCodeValeur(char * pcString)
	 * \brief Fonction n�cessaire au bon fonctionnement de OCMLireFichier : On r�cup�re le num�ro d'une valeur.
	 *
	 * \param pcString char * : Valeur dont on d�sire r�cup�rer le code.
	 * \return -1=Valeur inconnue, sinon code correspondant � la position dans pcValeurs.
	 */
	static int PARGetCodeValeur(char *pcString);
};

#endif /* CParser_h */