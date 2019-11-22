/**
 * \file COperationsComplexesMatrices.h
 * \brief Fichier header de la classe COperationsComplexesMatrices.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 4 mai 2019
 *
 * Fichier header contenant une classe COperationComplexeMatrice contenant les op�rations complexes de la classe CMatrice.
 * Cette classe n'a pas pour but initial d'�tre instanci� mais seulement de servir de recueil de m�thodes pour la classe CMatrice.
 * /!\ Attention /!\ Ce fichier contenant des m�thodes et fonctions template, un fichier cpp contenant les m�thodes est inclut � la fin.
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
	/* === M�thodes === */
public:

	/**
	 * \fn template <class MType> static CMatrice<MType> OCMTransposee(CMatrice<MType> & MATMatrice)
	 * \brief M�thode permettant de cr�er la transpos�e d'une CMatrice.
	 *
	 * \param MATMatrice CMatrice qui sp�cifie la CMatrice dont on veut trouver la transpos�e.
	 *
	 * \return CMatrice la transpos�e calcul�e.
	 */
	template <class MType> static CMatrice<MType> OCMTransposee(CMatrice<MType> & MATMatrice);
};

/**
 * \fn template <class MType1, class MType2> auto operator+(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2)
 * \brief Surcharge de l'operateur + pour additionner deux matrices entre elles, celles-ci doivent �tre de m�mes tailles.
 *
 * Cette m�thode permet d'additioner deux CMatrices de deux types diff�rents.
 * /!\ Attention /!\ La CMatrice r�sultante de l'op�ration poss�de le type que donne le r�sultat de l'addition : MType1 + MType2.
 *
 * \param MATMatrice1 CMatrice qui sp�cifie l'une des CMatrice que l'on veut additionner.
 * \param MATMatrice2 CMatrice qui sp�cifie l'une des CMatrice que l'on veut additionner.
 *
 * \return CMatrice la CMatrice calcul�e qui est �gale � MATMatrice1 + MATMatrice2.
 */
template <class MType1, class MType2> auto operator+(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2);

/**
 * \fn template <class MType1, class MType2> auto operator-(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2*
 * \brief Surcharge de l'operateur - pour soustraire deux matrices entre elles, celles-ci doivent �tre de m�mes tailles.
 *
 * Cette m�thode permet de soustraire deux CMatrices de deux types diff�rents.
 * /!\ Attention /!\ La CMatrice r�sultante de l'op�ration poss�de le type que donne le r�sultat de la soustraction : MType1 - MType2.
 *
 * \param MATMatrice1 CMatrice qui sp�cifie l'une des CMatrice que l'on veut soustraire.
 * \param MATMatrice2 CMatrice qui sp�cifie l'une des CMatrice que l'on veut soustraire.
 *
 * \return CMatrice la CMatrice calcul�e qui est �gale � MATMatrice1 - MATMatrice2.
 */
template <class MType1, class MType2> auto operator-(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2);

/**
 * \fn template <class MType1, class MType2> auto operator*(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2*
 * \brief Surcharge de l'operateur * pour multiplier deux matrices entre elles, MATMatrice1 doit avoir le m�me nombre de colonnes que MATMatrice2 a de lignes.
 *
 * Cette m�thode permet de multiplier deux CMatrices de deux types diff�rents.
 * /!\ Attention /!\ La CMatrice r�sultante de l'op�ration poss�de le type que donne le r�sultat de la multiplication : MType1 * MType2.
 *
 * \param MATMatrice1 CMatrice qui sp�cifie l'une des CMatrice que l'on veut multiplier.
 * \param MATMatrice2 CMatrice qui sp�cifie l'une des CMatrice que l'on veut multiplier.
 *
 * \return CMatrice la CMatrice calcul�e qui est �gale � MATMatrice1 * MATMatrice2.
 */
template <class MType1, class MType2> auto operator*(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2);

#include "COperationsComplexesMatrices.cpp"

#endif /* COperationsComplexesMatrices_h */


