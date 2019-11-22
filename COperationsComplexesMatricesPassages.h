/**
 * \file COperationsComplexesMatricesPassages.h
 * \brief Fichier header de la classe COperationsComplexesMatricesPassages.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 29 mai 2019
 *
 * Fichier header contenant une classe COperationsComplexesMatricesPassages contenant les op�rations complexes de la classe CMatricePassage.
 * Cette classe n'a pas pour but initial d'�tre instanci�e mais seulement de servir de recueil de m�thodes pour la classe CMatricePassage.
 * /!\ Attention /!\ Ce fichier contenant des m�thodes et fonctions template, un fichier cpp contenant les m�thodes est inclut � la fin.
 * Pour la bonne utilisation de cette librairie, ne pas inclure le fichier cpp dans le projet.
 *
 */

#ifndef COperationsComplexesMatricesPassages_h
#define COperationsComplexesMatricesPassages_h

//Codes d'erreur : � partir de 500 pour cette classe
#define EXC_WrongType 500

#include <cstdarg>
#include "CMatricePassage.h"
#include "COperationsComplexesMatrices.h"

class COperationsComplexesMatricesPassages
{
public:

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice)
	 * \brief M�thode de changement de base non-variadiques avec v�rification des bases de d�part et d'arriv�e.
	 *
	 * \param MATVecteur CMatrice<MType> qui sp�cifie le vecteur dont on veut changer de base.
	 * \param uiBaseDepart unsigned int qui sp�cifie la base de d�part de notre vecteur.
	 * \param uiBaseArrivee unsigned int qui sp�cifie la base d'arriv�e de notre vecteur.
	 * \param pMAPMatrice CMatricePassage<MType>* qui sp�cifie le tableau regroupant nos CMatricePassage.
	 * \param uiTailleTabMatrice unsigned int qui sp�cifie la taille de notre tableau de CMatricePassage.
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectu�.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice);

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice)
	 * \brief M�thode de changement de base non-variadiques sans v�rification des bases de d�part et d'arriv�e.
	 *
	 * \param MATVecteur CMatrice<MType> qui sp�cifie le vecteur dont on veut changer de base.
	 * \param pMAPMatrice CMatricePassage<MType>* qui sp�cifie le tableau regroupant nos CMatricePassage.
	 * \param uiTailleTabMatrice unsigned int qui sp�cifie la taille de notre tableau de CMatricePassage.
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectu�.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice);

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiNbMatricesPassages, ... )
	 * \brief M�thode de changement de base variadiques sans v�rification des bases de d�part et d'arriv�e.
	 *
	 * \param MATVecteur CMatrice<MType> qui sp�cifie le vecteur dont on veut changer de base.
	 * \param uiNbMatricesPassages unsigned int qui sp�cifie le nombre de CMatricePassage pass� en param�tre.
	 * \param ... /!\ Attention /!\ passez ici seulement des CMatricesPassages
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectu�.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiNbMatricesPassages, ... );

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, unsigned int uiNbMatricesPassages, ...)
	 * \brief M�thode de changement de base variadiques sans v�rification des bases de d�part et d'arriv�e.
	 *
	 * \param MATVecteur CMatrice<MType> qui sp�cifie le vecteur dont on veut changer de base.
	 * \param uiBaseDepart unsigned int qui sp�cifie la base de d�part de notre vecteur.
	 * \param uiBaseArrivee unsigned int qui sp�cifie la base d'arriv�e de notre vecteur.
	 * \param uiNbMatricesPassages unsigned int qui sp�cifie le nombre de CMatricePassage pass� en param�tre.
	 * \param ... /!\ Attention /!\ passez ici seulement des CMatricesPassages
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectu�.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, unsigned int uiNbMatricesPassages, ...);

};

#include "COperationsComplexesMatricesPassages.cpp"

#endif /* COperationsComplexesMatricesPassages_h */