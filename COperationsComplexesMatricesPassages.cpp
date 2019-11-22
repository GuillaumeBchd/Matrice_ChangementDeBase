/**
 * \file COperationsComplexesMatricesPassages.cpp
 * \brief Fichier de m�thodes de la classe COperationsComplexesMatricesPassages permettant d'effectuer des operations complexes sur des CMatricesPassages.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.3
 * \date 29 mai 2019
 *
 * Fichier de m�thodes template et donc inclus � la fin du .h, exclure ce cpp du projet pour
 * le bon fonctionnement de celui-ci.
 *
 */


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
template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice) 
{
	CMatrice<MType> MATResult(MATVecteur);
	unsigned int uiIndice;
	unsigned int uiBaseArriveePrecedente;

	if (pMAPMatrice == NULL) {
		CException EXCError(EXC_NullMatrix);
		throw EXCError;
	}

	//Simple v�rification que la base de d�part correspond :
	if (uiBaseDepart != pMAPMatrice[0].MAPGetBaseDepart()) {
		CException EXCError(EXC_ChangementImpossible);
		throw EXCError;
	}

	//Simple v�rification que les bases sont dans l'ordre logique :
	uiBaseArriveePrecedente = pMAPMatrice[0].MAPGetBaseArrivee();
	for (uiIndice = 1; uiIndice < uiTailleTabMatrice; uiIndice++) {
		if (uiBaseArriveePrecedente != pMAPMatrice[uiIndice].MAPGetBaseDepart()) {
			CException EXCError(EXC_ChangementImpossible);
			throw EXCError;
		}
		uiBaseArriveePrecedente = pMAPMatrice[uiIndice].MAPGetBaseArrivee();
	}

	//Une fois que l'on est arriv� au bout, on v�rifie que la derniere matrice de passage correspond :
	if (uiBaseArriveePrecedente != uiBaseArrivee) {
		CException EXCError(EXC_ChangementImpossible);
		throw EXCError;
	}

	for (uiIndice = 0; uiIndice < uiTailleTabMatrice; uiIndice++) {
		MATResult = MATResult * pMAPMatrice[uiIndice];
	}

	return MATResult;
}

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
template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, CMatricePassage<MType> *pMAPMatrice, unsigned int uiTailleTabMatrice) 
{
	CMatrice<MType> MATResult(MATVecteur);
	unsigned int uiIndice;
	unsigned int uiBaseArriveePrecedente;

	if (pMAPMatrice == NULL) {
		CException EXCError(EXC_NullMatrix);
		throw EXCError;
	}

	//Simple v�rification que les bases sont dans l'ordre logique :
	uiBaseArriveePrecedente = pMAPMatrice[0].MAPGetBaseArrivee();
	for (uiIndice = 1; uiIndice < uiTailleTabMatrice; uiIndice++) {
		if (uiBaseArriveePrecedente != pMAPMatrice[uiIndice].MAPGetBaseDepart()) {
			CException EXCError(EXC_ChangementImpossible);
			throw EXCError;
		}
		uiBaseArriveePrecedente = pMAPMatrice[uiIndice].MAPGetBaseArrivee();
	}

	for (uiIndice = 0; uiIndice < uiTailleTabMatrice; uiIndice++) {
		MATResult = MATResult * pMAPMatrice[uiIndice];
	}

	return MATResult;
}

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
template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiNbMatricesPassages, ... )
{
	unsigned int uiIndice;
	unsigned int uiBaseArriveePrecedente;

	va_list args;
	va_start(args, uiNbMatricesPassages);

	CMatrice<MType> MATResult(MATVecteur);
	CMatricePassage<MType> MAPMatricePass = va_arg(args, CMatricePassage<MType>);

	MATResult = MATResult * MAPMatricePass;

	uiBaseArriveePrecedente = MAPMatricePass.MAPGetBaseArrivee();
	for (uiIndice = 1; uiIndice < uiNbMatricesPassages; uiIndice++) {
		//On passe � la matrice suivante
		MAPMatricePass = va_arg(args, CMatricePassage<MType>);

		//Simple v�rification que les bases sont dans l'ordre logique :
		if (uiBaseArriveePrecedente != MAPMatricePass.MAPGetBaseDepart()) {
			CException EXCError(EXC_ChangementImpossible);
			throw EXCError;
		}
		uiBaseArriveePrecedente = MAPMatricePass.MAPGetBaseArrivee();

		//On change le vecteur de base avec la matrice de passage MAPMatricePass
		MATResult = MATResult * MAPMatricePass;
	}


	return MATResult;

}

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
template<class MType> static CMatrice<MType> COperationsComplexesMatricesPassages::OCPChangementDeBase(CMatrice<MType> & MATVecteur, unsigned int uiBaseDepart, unsigned int uiBaseArrivee, unsigned int uiNbMatricesPassages, ...)
{
	unsigned int uiIndice;
	unsigned int uiBaseArriveePrecedente;

	va_list args;
	va_start(args, uiNbMatricesPassages);

	CMatrice<MType> MATResult(MATVecteur);
	CMatricePassage<MType> MAPMatricePass = va_arg(args, CMatricePassage<MType>);

	//Simple v�rification que la base de d�part correspond :
	if (uiBaseDepart != MAPMatricePass.MAPGetBaseDepart()) {
		CException EXCError(EXC_ChangementImpossible);
		throw EXCError;
	}

	MATResult = MATResult * MAPMatricePass;

	uiBaseArriveePrecedente = MAPMatricePass.MAPGetBaseArrivee();
	for (uiIndice = 1; uiIndice < uiNbMatricesPassages; uiIndice++) {
		//On passe � la matrice suivante
		MAPMatricePass = va_arg(args, CMatricePassage<MType>);

		//Simple v�rification que les bases sont dans l'ordre logique :
		if (uiBaseArriveePrecedente != MAPMatricePass.MAPGetBaseDepart()) {
			CException EXCError(EXC_ChangementImpossible);
			throw EXCError;
		}
		uiBaseArriveePrecedente = MAPMatricePass.MAPGetBaseArrivee();

		//On change le vecteur de base avec la matrice de passage MAPMatricePass
		MATResult = MATResult * MAPMatricePass;
	}

	//Une fois que l'on est arriv� au bout, on v�rifie que la derniere matrice de passage correspond :
	if (uiBaseArriveePrecedente != uiBaseArrivee) {
		CException EXCError(EXC_ChangementImpossible);
		throw EXCError;
	}	


	return MATResult;
}

