/**
 * \file COperationsComplexesMatricesPassages.h
 * \brief Fichier header de la classe COperationsComplexesMatricesPassages.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 29 mai 2019
 *
 * Fichier header contenant une classe COperationsComplexesMatricesPassages contenant les opérations complexes de la classe CMatricePassage.
 * Cette classe n'a pas pour but initial d'être instanciée mais seulement de servir de recueil de méthodes pour la classe CMatricePassage.
 * /!\ Attention /!\ Ce fichier contenant des méthodes et fonctions template, un fichier cpp contenant les méthodes est inclut à la fin.
 * Pour la bonne utilisation de cette librairie, ne pas inclure le fichier cpp dans le projet.
 *
 */

#ifndef COperationsComplexesMatricesPassages_h
#define COperationsComplexesMatricesPassages_h

//Codes d'erreur : à partir de 500 pour cette classe
#define EXC_WrongType 500

#include <cstdarg>
#include "CMatricePassage.h"
#include "COperationsComplexesMatrices.h"

class COperationsComplexesMatricesPassages
{
public:

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice)
	 * \brief Méthode de changement de base non-variadiques avec vérification des bases de départ et d'arrivée.
	 *
	 * \param MATVecteur CMatrice<MType> qui spécifie le vecteur dont on veut changer de base.
	 * \param uiBaseDepart unsigned int qui spécifie la base de départ de notre vecteur.
	 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de notre vecteur.
	 * \param pMAPMatrice CMatricePassage<MType>* qui spécifie le tableau regroupant nos CMatricePassage.
	 * \param uiTailleTabMatrice unsigned int qui spécifie la taille de notre tableau de CMatricePassage.
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectué.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice);

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice)
	 * \brief Méthode de changement de base non-variadiques sans vérification des bases de départ et d'arrivée.
	 *
	 * \param MATVecteur CMatrice<MType> qui spécifie le vecteur dont on veut changer de base.
	 * \param pMAPMatrice CMatricePassage<MType>* qui spécifie le tableau regroupant nos CMatricePassage.
	 * \param uiTailleTabMatrice unsigned int qui spécifie la taille de notre tableau de CMatricePassage.
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectué.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice);

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiNbMatricesPassages, ... )
	 * \brief Méthode de changement de base variadiques sans vérification des bases de départ et d'arrivée.
	 *
	 * \param MATVecteur CMatrice<MType> qui spécifie le vecteur dont on veut changer de base.
	 * \param uiNbMatricesPassages unsigned int qui spécifie le nombre de CMatricePassage passé en paramètre.
	 * \param ... /!\ Attention /!\ passez ici seulement des CMatricesPassages
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectué.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiNbMatricesPassages, ... );

	/**
	 * \fn template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, unsigned int uiNbMatricesPassages, ...)
	 * \brief Méthode de changement de base variadiques sans vérification des bases de départ et d'arrivée.
	 *
	 * \param MATVecteur CMatrice<MType> qui spécifie le vecteur dont on veut changer de base.
	 * \param uiBaseDepart unsigned int qui spécifie la base de départ de notre vecteur.
	 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de notre vecteur.
	 * \param uiNbMatricesPassages unsigned int qui spécifie le nombre de CMatricePassage passé en paramètre.
	 * \param ... /!\ Attention /!\ passez ici seulement des CMatricesPassages
	 *
	 * \return CMatrice<MType> notre vecteur une fois le changement de base effectué.
	 */
	template<class MType> static CMatrice<MType> OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, unsigned int uiNbMatricesPassages, ...);

};

#include "COperationsComplexesMatricesPassages.cpp"

#endif /* COperationsComplexesMatricesPassages_h */