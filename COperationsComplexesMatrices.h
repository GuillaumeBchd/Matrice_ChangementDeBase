/**
 * \file COperationsComplexesMatrices.h
 * \brief Fichier header de la classe COperationsComplexesMatrices.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 4 mai 2019
 *
 * Fichier header contenant une classe COperationComplexeMatrice contenant les opérations complexes de la classe CMatrice.
 * Cette classe n'a pas pour but initial d'être instancié mais seulement de servir de recueil de méthodes pour la classe CMatrice.
 * /!\ Attention /!\ Ce fichier contenant des méthodes et fonctions template, un fichier cpp contenant les méthodes est inclut à la fin.
 * Pour la bonne utilisation de cette librairie, ne pas inclure le fichier cpp dans le projet.
 *
 */

#ifndef COperationsComplexesMatrices_h
#define COperationsComplexesMatrices_h

#include "CMatrice.h"
#include "CException.h"

#define EXC_DifferentDimensions 206

class COperationsComplexesMatrices
{
	/* === Méthodes === */
public:

	/**
	 * \fn template <class MType> static CMatrice<MType> OCMTransposee(CMatrice<MType> & MATMatrice)
	 * \brief Méthode permettant de créer la transposée d'une CMatrice.
	 *
	 * \param MATMatrice CMatrice qui spécifie la CMatrice dont on veut trouver la transposée.
	 *
	 * \return CMatrice la transposée calculée.
	 */
	template <class MType> static CMatrice<MType> OCMTransposee(CMatrice<MType> & MATMatrice);
};

/**
 * \fn template <class MType1, class MType2> auto operator+(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2)
 * \brief Surcharge de l'operateur + pour additionner deux matrices entre elles, celles-ci doivent être de mêmes tailles.
 *
 * Cette méthode permet d'additioner deux CMatrices de deux types différents.
 * /!\ Attention /!\ La CMatrice résultante de l'opération possède le type que donne le résultat de l'addition : MType1 + MType2.
 *
 * \param MATMatrice1 CMatrice qui spécifie l'une des CMatrice que l'on veut additionner.
 * \param MATMatrice2 CMatrice qui spécifie l'une des CMatrice que l'on veut additionner.
 *
 * \return CMatrice la CMatrice calculée qui est égale à MATMatrice1 + MATMatrice2.
 */
template <class MType1, class MType2> auto operator+(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2);

/**
 * \fn template <class MType1, class MType2> auto operator-(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2*
 * \brief Surcharge de l'operateur - pour soustraire deux matrices entre elles, celles-ci doivent être de mêmes tailles.
 *
 * Cette méthode permet de soustraire deux CMatrices de deux types différents.
 * /!\ Attention /!\ La CMatrice résultante de l'opération possède le type que donne le résultat de la soustraction : MType1 - MType2.
 *
 * \param MATMatrice1 CMatrice qui spécifie l'une des CMatrice que l'on veut soustraire.
 * \param MATMatrice2 CMatrice qui spécifie l'une des CMatrice que l'on veut soustraire.
 *
 * \return CMatrice la CMatrice calculée qui est égale à MATMatrice1 - MATMatrice2.
 */
template <class MType1, class MType2> auto operator-(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2);

/**
 * \fn template <class MType1, class MType2> auto operator*(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2*
 * \brief Surcharge de l'operateur * pour multiplier deux matrices entre elles, MATMatrice1 doit avoir le même nombre de colonnes que MATMatrice2 a de lignes.
 *
 * Cette méthode permet de multiplier deux CMatrices de deux types différents.
 * /!\ Attention /!\ La CMatrice résultante de l'opération possède le type que donne le résultat de la multiplication : MType1 * MType2.
 *
 * \param MATMatrice1 CMatrice qui spécifie l'une des CMatrice que l'on veut multiplier.
 * \param MATMatrice2 CMatrice qui spécifie l'une des CMatrice que l'on veut multiplier.
 *
 * \return CMatrice la CMatrice calculée qui est égale à MATMatrice1 * MATMatrice2.
 */
template <class MType1, class MType2> auto operator*(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2);

#include "COperationsComplexesMatrices.cpp"

#endif /* COperationsComplexesMatrices_h */


