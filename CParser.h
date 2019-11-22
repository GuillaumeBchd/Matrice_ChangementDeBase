/**
 * \file CParser.h
 * \brief Fichier header de la classe CParser.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 1 mai 2019
 *
 * Fichier header contenant la classe CParser contenant des méthodes pour lire des fichiers txt sous un certain format, et créer des CMatrices<double>.
 * Format de fichier compatible :
 * ##############################
 *
 * TypeMatrice=<type_base_C>
 * NBLignes=<Nombre_de_lignes_de_la_matrice>
 * NBColonnes=<Nombre_de_colonnes_de_la_matrice>
 * Matrice=[
 * <Ligne_1 : autant d'éléments que de colonnes>
 * <Ligne_n : autant d'éléments que de colonnes>
 * ...
 * <Ligne_NBLignes : autant d'éléments que de colonnes>
 * ]
 *
 * ##############################
 * /!\ Attention /!\ Ce fichier contenant des méthodes et fonctions template, un fichier cpp contenant les méthodes est inclut à la fin.
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

//Codes d'erreur : à partir de 300 pour cette classe
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
	 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : Lecture du mot suivant du ifstream & fichier passé en paramètre
	 *
	 * \param fichier ifstream & : fichier ouvert (au moins en mode lecture),
	 * \param pcMot char * : chaine de caractères ou sera stocké
	 * \return 0=mot-clé, 1=endOfFile (fichier.oef()) et 5=valeur.
	 */
	static int PARLectureMot(std::ifstream& fichier, char * pcMot);

	/**
	 * \fn static int CParser::PARStringCompare(char * pcString1, const char * pcString2)
	 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : On compare si deux chaînes de caractères sont identiques.
	 *
	 * \param pcString1 char * : Premiere chaine à comparer.
	 * \param pcString2 const char * Deuxième chaine (constante) à comparer.
	 * \return 0=Les chaines sont différentes et 1=Les chaines sont identiques.
	 */
	static int PARStringCompare(char *pcString1, const char * pcString2);
	 
	/**
	 * \fn static int CParser::PARGetCodeMotCle(char * pcString)
	 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : On récupère le numéro d'un mot-clé.
	 *
	 * \param pcString char * : Mot-clé dont on désire récupérer le code.
	 * \return -1=Mot-clé inconnu, sinon code correspondant à la position dans pcMotsCles.
	 */
	static int PARGetCodeMotCle(char *pcString);

	/**
	 * \fn static int CParser::PARGetCodeValeur(char * pcString)
	 * \brief Fonction nécessaire au bon fonctionnement de OCMLireFichier : On récupère le numéro d'une valeur.
	 *
	 * \param pcString char * : Valeur dont on désire récupérer le code.
	 * \return -1=Valeur inconnue, sinon code correspondant à la position dans pcValeurs.
	 */
	static int PARGetCodeValeur(char *pcString);
};

#endif /* CParser_h */