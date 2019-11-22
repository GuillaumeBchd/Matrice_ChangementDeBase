/**
 * \file COperationsComplexesMatrices.cpp
 * \brief Fichier de méthodes de la classe COperationsComplexesMatrices permettant d'effectuer des operations complexes sur des CMatrices.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 4 mai 2019
 *
 * Fichier de méthodes template et donc inclus à la fin du .h, exclure ce cpp du projet pour
 * le bon fonctionnement de celui-ci.
 *
 */


 /**
  * \fn template <class MType> static CMatrice<MType> OCMTransposee(CMatrice<MType> & MATMatrice)
  * \brief Méthode permettant de créer la transposée d'une CMatrice.
  *
  * \param MATMatrice CMatrice qui spécifie la CMatrice dont on veut trouver la transposée.
  *
  * \return CMatrice la transposée calculée.
  */
template <class MType>  CMatrice<MType> COperationsComplexesMatrices::OCMTransposee(CMatrice<MType> & MATMatrice)
{
	CMatrice<MType> MATNewMatrice(MATMatrice.MATGetNbColonnes(), MATMatrice.MATGetNbLignes());
	unsigned int uiIndiceColonne;
	unsigned int uiIndiceLigne;

	for (uiIndiceColonne = 0; uiIndiceColonne < MATMatrice.MATGetNbColonnes(); uiIndiceColonne++) {

		for (uiIndiceLigne = 0; uiIndiceLigne < MATMatrice.MATGetNbLignes(); uiIndiceLigne++) {
			MATNewMatrice.MATModifierElement(MATMatrice.MATGetElement(uiIndiceLigne, uiIndiceColonne), uiIndiceColonne, uiIndiceLigne);
		}

	}
	return MATNewMatrice;
}

/**
 * \fn template <class MType1, class MType2> auto operator+(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2*
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
template <class MType1, class MType2> auto operator+(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	if (MATMatrice1.MATGetNbColonnes() != MATMatrice2.MATGetNbColonnes() || MATMatrice1.MATGetNbLignes() != MATMatrice2.MATGetNbLignes()) {
		CException EXCDifferentDimensions(EXC_DifferentDimensions);
		throw EXCDifferentDimensions;
	}

	//On trouve automatiquement le type de la nouvelle matrice en regardant le premier élément de chaque matrice et grâce à delctype
	CMatrice<decltype(MATMatrice1.MATGetElement(0, 0) + MATMatrice2.MATGetElement(0, 0))> MATResult(MATMatrice1.MATGetNbLignes(), MATMatrice1.MATGetNbColonnes());

	for (uiCompteurLignes = 0; uiCompteurLignes < MATMatrice1.MATGetNbLignes(); uiCompteurLignes++) {

		for (uiCompteurColonnes = 0; uiCompteurColonnes < MATMatrice1.MATGetNbColonnes(); uiCompteurColonnes++) {

			MATResult.MATModifierElement(MATMatrice1.MATGetElement(uiCompteurLignes, uiCompteurColonnes) + MATMatrice2.MATGetElement(uiCompteurLignes, uiCompteurColonnes), uiCompteurLignes, uiCompteurColonnes);

		}
	}
	return MATResult;
}


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
template <class MType1, class MType2> auto operator-(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	if (MATMatrice1.MATGetNbColonnes() != MATMatrice2.MATGetNbColonnes() || MATMatrice1.MATGetNbLignes() != MATMatrice2.MATGetNbLignes()) {
		CException EXCDifferentDimensions(EXC_DifferentDimensions);
		throw EXCDifferentDimensions;
	}

	//On trouve automatiquement le type de la nouvelle matrice en regardant le premier élément de chaque matrice et grâce à delctype
	CMatrice<decltype(MATMatrice1.MATGetElement(0, 0) + MATMatrice2.MATGetElement(0, 0))> MATResult(MATMatrice1.MATGetNbLignes(), MATMatrice1.MATGetNbColonnes());

	for (uiCompteurLignes = 0; uiCompteurLignes < MATMatrice1.MATGetNbLignes(); uiCompteurLignes++) {

		for (uiCompteurColonnes = 0; uiCompteurColonnes < MATMatrice1.MATGetNbColonnes(); uiCompteurColonnes++) {

			MATResult.MATModifierElement(MATMatrice1.MATGetElement(uiCompteurLignes, uiCompteurColonnes) - MATMatrice2.MATGetElement(uiCompteurLignes, uiCompteurColonnes), uiCompteurLignes, uiCompteurColonnes);

		}
	}
	return MATResult;

}


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
template <class MType1, class MType2> auto operator*(CMatrice<MType1> & MATMatrice1, CMatrice<MType2> & MATMatrice2)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	if (MATMatrice1.MATGetNbColonnes() != MATMatrice2.MATGetNbLignes()) {
		CException EXCInvalidDimensions(EXC_InvalidDimensions);
		throw EXCInvalidDimensions;
	}

	//On trouve automatiquement le type de la nouvelle matrice en regardant le premier élément de chaque matrice et grâce à delctype
	CMatrice<decltype(MATMatrice1.MATGetElement(0, 0) + MATMatrice2.MATGetElement(0, 0))> MATResult(MATMatrice1.MATGetNbLignes(), MATMatrice2.MATGetNbColonnes());

	//On parcourt tout les éléments du resultat.
	for (uiCompteurLignes = 0; uiCompteurLignes < MATResult.MATGetNbLignes(); uiCompteurLignes++) {

		for (uiCompteurColonnes = 0; uiCompteurColonnes < MATResult.MATGetNbColonnes(); uiCompteurColonnes++) {

			auto AUTElement = MATMatrice1.MATGetElement(uiCompteurLignes, 0) * MATMatrice2.MATGetElement(0, uiCompteurColonnes);
			for (unsigned int uiIter = 1; uiIter < MATMatrice1.MATGetNbColonnes(); uiIter++) {
				AUTElement = AUTElement + MATMatrice1.MATGetElement(uiCompteurLignes, uiIter) * MATMatrice2.MATGetElement(uiIter, uiCompteurColonnes);
			}

			MATResult.MATModifierElement(AUTElement, uiCompteurLignes, uiCompteurColonnes);
		}
	}


	return MATResult;
}