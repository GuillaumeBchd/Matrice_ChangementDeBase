/**
 * \file CMatrice.h
 * \brief Fichier header de la classe CMatrice.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.5
 * \date 1 juin 2019
 *
 * Fichier header contenant une classe template CMatrice contenant les op�rations simples de cet objet et les m�thodes permettant de cr�er les objets
 * de cette classe. Pour faire des operations sur ces matrices, inclure COperationsComplexesMatrices.h dans votre fichier �galement.
 * /!\ Attention /!\ Ce fichier contenant des m�thodes et fonctions template, un fichier cpp contenant les m�thodes est inclut � la fin.
 * Pour la bonne utilisation de cette librairie, ne pas inclure le fichier cpp dans le projet.
 *
 */

#ifndef CMatrice_h
#define CMatrice_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CException.h"
#include "CParser.h"

 //Codes d'erreur : � partir de 100 pour cette classe
#define EXC_OutOfBounds 100
#define EXC_MallocError 101
#define EXC_DivisionByZero 102
#define EXC_OuvertureFichier 103
#define EXC_UnexpectedSymbol 104
#define EXC_UnexpectedKeyWord 105
#define EXC_DuplicateLine 106
#define EXC_UnknownError 107
#define EXC_InvalidMatrixParameters 108
#define EXC_UnknownMatrixType 109
#define EXC_InvalidDimensions 207

template <class MType> class CMatrice
{
	/* === Attributs === */
private:
	/**Tableau 2D de MType contenant les �l�ments de la matrice. */
	MType **pMATMatrice;

	/** Nombre de lignes de la matrices */
	unsigned int uiMATLignes;
	/** Nombre de colonnes de la matrices */
	unsigned int uiMATColonnes;

	/* === Constructeurs/Destructeurs === */
public:
	/**
	 * \fn  template<class MType> CMatrice<MType>::CMatrice()
	 * \brief Constructeur par d�faut de la classe CMatrice
	 *
	 */
	CMatrice<MType>();

	/**
	 * \fn template<class MType> CMatrice<MType>::CMatrice(char * pcNomFichier)
	 * \brief Fonction qui lit le contenu d'un fichier et cr�e une nouvelle matrice allou�e dynamiquement.
	 *
	 * \param pcNomFichier char * : Chemin du fichier � lire.
	 */
	CMatrice<MType>(const char *pcNomFichier);

	/**
	 * \fn template<class MType> CMatrice<MType>::CMatrice(unsigned int uiLigne, unsigned int uiColonne)
	 * \brief Constructeur de confort de la classe CMatrice
	 *
	 * \param uiLigne unsigned int qui sp�cifie le nombre de lignes que poss�dera la CMatrice cr��e.
	 * \param uiColonne unsigned int qui sp�cifie le nombre de colonnes que poss�dera la CMatrice cr��e.
	 */
	CMatrice<MType>(unsigned int uiLigne, unsigned int uiColonne);


	/**
	 * \fn template<class MType> CMatrice<MType>::CMatrice(CMatrice<MType> & MATMatrice)
	 * \brief Constructeur de recopie de la classe CMatrice
	 *
	 * \param MATMatrice CMatrice que l'on souhaite recopier.
	 */
	CMatrice<MType>(CMatrice<MType> & MATMatrice);


	/**
	 * \fn template<class MType> CMatrice<MType>::CMatrice(CMatrice<MType> && MATMatrice)
	 * \brief Constructeur de recopie de la classe CMatrice qui nous permet de faire : CMatrice<> c = a+b;
	 *
	 * \param MATMatrice CMatrice que l'on souhaite recopier.
	 */
	CMatrice<MType>(CMatrice<MType> && MATMatrice);

	/**
	 * \fn template<class MType> CMatrice<MType>::~CMatrice()
	 * \brief Destructeur de la classe CMatrice
	 */
	~CMatrice<MType>();

	/* === M�thodes === */
public:
	/**
	 * \fn template<class MType> MType CMatrice<MType>::MATGetElement(unsigned int uiLigne, unsigned int uiColonne)
	 * \brief Accesseur de la classe CMatrice pour r�cup�rer un �l�ment de la matrice en position (uiLigne, uiColonne)
	 *
	 * \param uiLigne unsigned int qui sp�cifie la ligne de l'�l�ment recherch�.
	 * \param uiColonne unsigned int qui sp�cifie la colonne de l'�l�ment recherch�.
	 *
	 * \return MType qui est l'�l�ment que l'on souhaite r�cup�r�.
	 */
	MType MATGetElement(unsigned int uiLigne, unsigned int uiColonne);

	/**
	 * \fn template<class MType> unsigned int CMatrice<MType>::MATGetNbLignes()
	 * \brief Accesseur de la classe CMatrice pour r�cup�rer le nombre de lignes de la matrice.
	 *
	 * \return unsigned int qui est le nombre de lignes de la matrice.
	 */
	unsigned int MATGetNbLignes();

	/**
	 * \fn template<class MType> unsigned int CMatrice<MType>::MATGetNbColonnes()
	 * \brief Accesseur de la classe CMatrice pour r�cup�rer le nombre de colonnes de la matrice.
	 *
	 * \return unsigned int qui est le nombre de colonnes de la matrice.
	 */
	unsigned int MATGetNbColonnes();

	/**
	 * \fn template<class MType> void CMatrice<MType>::MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne)
	 * \brief Accesseur de la classe CMatrice pour modifier l'�l�ment de la matrice en position (uiLigne, uiColonne)
	 *
	 * \param MTPElement MType �l�ment que l'on souhaite placer dans la matrice.
	 * \param uiLigne unsigned int qui sp�cifie la ligne de l'�l�ment que l'on souhaite modifier.
	 * \param uiColonne unsigned int qui sp�cifie la colonne de l'�l�ment que l'on souhaite modifier.
	 */
	void MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne);

	/**
	 * \fn template<class MType> void CMatrice<MType>::MATAfficherMatrice()
	 * \brief M�thode permettant d'afficher la matrice.
	 */
	void MATAfficherMatrice();

	/**
	 * \fn template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice & MATMatrice)
	 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une autre.
	 *
	 * /!\ Attention /!\, si la CMatrice poss�de d�j� un tableau 2D allou�, celui-ci sera d�sallou� mais les �l�ments pr�sents � l'int�rieur de celui-ci ne le seront pas.
	 *
	 * \param MATMatrice CMatrice qui est la CMatrice que l'on souhaite recopier.
	 *
	 * \return CMatrice une fois qu'elle a �t� recopi�e. Permet de faire : A = B = C; (Avec A,B,C des CMatrices)
	 */
	CMatrice & operator=(CMatrice & MATMatrice);

	/**
	 * \fn template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice && MATMatrice)
	 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une autre. Version permettant de faire C = A+B; (Avec A,B,C des CMatrices)
	 *
	 * /!\ Attention /!\, si la CMatrice poss�de d�j� un tableau 2D allou�, celui-ci sera d�sallou� mais les �l�ments pr�sents � l'int�rieur de celui-ci ne le seront pas.
	 *
	 * \param MATMatrice CMatrice qui est la CMatrice que l'on souhaite recopier.
	 *
	 * \return CMatrice une fois qu'elle a �t� recopi�e. Permet de faire : A = B = C; (Avec A,B,C des CMatrices)
	 */
	CMatrice & operator=(CMatrice && MATMatrice);

	/**
	 * \fn template<class MType> CMatrice<MType> CMatrice<MType>::operator*(double dNombre)
	 * \brief Surcharge d'operateur * permettant de multiplier correctement une CMatrice avec un double. Version permettant de faire A*c; (Avec A une CMatrice et c un double)
	 *
	 *	/!\ Attention /!\, les �l�ments de la CMatrice doivent �tre capables de se multiplier par un double. De plus la multiplication s'effectue dans le sens E*c (Avec E un MType et c un double).
	 *
	 * \param dNombre double qui est la constante qui multiplie la CMatrice.
	 *
	 * \return CMatrice une fois qu'elle a �t� multipli�e. Permet de faire : A * B * C; (Avec A,B,C des CMatrices)
	 */
	CMatrice operator*(double dNombre);


	/**
	 * \fn template<class MType> CMatrice<MType> CMatrice<MType>::operator/(double dNombre)
	 * \brief Surcharge d'operateur * permettant de diviser correctement une CMatrice avec un double.
	 *
	 *	/!\ Attention /!\, les �l�ments de la CMatrice doivent �tre capables de se diviser par un double, de plus la division s'effectue dans le sens E/c (Avec E un MType et c un double).
	 *
	 * \param dNombre double qui est la constante qui divise la CMatrice.
	 *
	 * \return CMatrice une fois qu'elle a �t� divis�e. Permet de faire : A / B / C; (Avec A,B,C des CMatrices)
	 */
	CMatrice operator/(double dNombre);
};

/**
 * \fn template<class MType> CMatrice<MType> operator*(double dNombre, CMatrice<MType> & MATMatrice)
 * \brief Surcharge d'operateur * permettant de multiplier correctement une CMatrice avec un double. Version permettant de faire c*A; (Avec A une CMatrice et c un double)
 *
 *	/!\ Attention /!\, les �l�ments de la CMatrice doivent �tre capables de se multiplier par un double, de plus la multiplication s'effectue dans le sens E*c (Avec E un MType et c un double).
 *
 * \param dNombre double qui est la constante qui multiplie la CMatrice.
 * \param MATMatrice CMatrice qui est la matrice que l'on souhaite multiplier.
 *
 * \return CMatrice une fois qu'elle a �t� multipli�e. Permet de faire : A * B * C; (Avec A,B,C des CMatrices)
 */
template<class MType> CMatrice<MType> operator*(double dNombre, CMatrice<MType> & MATMatrice);

#include "CMatrice.cpp"

#endif /* CMatrice_h */