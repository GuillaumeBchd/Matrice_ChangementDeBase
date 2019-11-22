/**
 * \file CMatrice.cpp
 * \brief Fichier de méthodes de la classe CMatrice.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 30 avril 2019
 *
 * Fichier de méthodes d'une classe template et donc inclus à la fin du .h, exclure ce cpp du projet pour
 * le bon fonctionnement de celui-ci.
 *
 */

 /***
					 Constructeurs
  ***/

  /**
   * \fn  template<class MType> CMatrice<MType>::CMatrice()
   * \brief Constructeur par défaut de la classe CMatrice
   *
   */
template<class MType> CMatrice<MType>::CMatrice()
{
	pMATMatrice = NULL;
	uiMATLignes = 0;
	uiMATColonnes = 0;
}

/**
 * \fn template<class MType> CMatrice<MType>::CMatrice(char * nomFichier)
 * \brief Fonction qui lit le contenu d'un fichier et crée une nouvelle matrice allouée dynamiquement.
 *
 * \param pcNomFichier char * : Chemin du fichier à lire.
 */
template<class MType> CMatrice<MType>::CMatrice(const char * pcNomFichier)
{
	unsigned int uiCompteur;
	unsigned int uiCompteurLigne;
	unsigned int uiIndiceLigne;
	unsigned int uiIndiceColonne;
	unsigned int uiIndiceTableauValeurs;
	char pcMotCle[256];
	int iCode;
	unsigned int uiNbColonnes;
	unsigned int uiNbLignes;
	unsigned int uiTabSize;
	unsigned int uiNbValeursTrouvee;
	double *pValeursMatrice;

	std::ifstream fichier(pcNomFichier, std::ios::in);  // ouvrir le fichier en mode lecture

	if (fichier) { // Si on a pu ouvrir
		iCode = 0;

		// Valeurs récupérées pour créer la matrice :
		uiTabSize = 2;
		uiNbValeursTrouvee = 0;
		pValeursMatrice = (double*)malloc((uiTabSize) * sizeof(double));

		while (((iCode = CParser::PARLectureMot(fichier, pcMotCle)) != 1) && !fichier.eof() && !fichier.fail()) {

			if (iCode == 5) { //On doit forcément commencer par lire un mot-clé, sinon exception

				if ((iCode = CParser::PARGetCodeMotCle(pcMotCle)) != -1) { //On vérifie ensuite que le mot-clé est connu

					switch (iCode) {
					case 0: //TypeMatrice
						//On s'attend ici à lire une valeur pour TypeMatrice, sinon exception
						if (((iCode = CParser::PARLectureMot(fichier, pcMotCle)) != 1)) {
							//On vérifie ensuite que le TYPE est bien double :
							if ((iCode = CParser::PARGetCodeValeur(pcMotCle)) == 0) {
								//Rien a faire ici, on confirme que c'est bien un double, sinon exception
								//puisqu'il n'y a que double
							}
							else {
								CException EXCUnknownMatrixType(EXC_UnknownMatrixType);
								throw EXCUnknownMatrixType;
							}
						}
						else {
							CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
							throw EXCUnexpectedSymbol;
						}
						break;

					case 1: //NBLignes
						//On s'attend ici à lire une valeur pour TypeMatrice, sinon exception
						if (((iCode = CParser::PARLectureMot(fichier, pcMotCle)) != 1)) {
							uiNbLignes = std::atoi(pcMotCle);
							if (uiNbLignes == 0) {
								for (uiCompteur = 0; uiCompteur < strlen(pcMotCle); uiCompteur++) {
									if (pcMotCle[uiCompteur] != '0') {
										CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
										throw EXCUnexpectedSymbol;
									}
								}
							}
						}
						else {
							CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
							throw EXCUnexpectedSymbol;
						}
						break;

					case 2: //NBColonnes
						//On s'attend ici à lire une valeur pour TypeMatrice, sinon exception
						if (((iCode = CParser::PARLectureMot(fichier, pcMotCle)) != 1)) {
							uiNbColonnes = std::atoi(pcMotCle);
							if (uiNbColonnes == 0) {
								for (uiCompteur = 0; uiCompteur < strlen(pcMotCle); uiCompteur++) {
									if (pcMotCle[uiCompteur] != '0') {
										CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
										throw EXCUnexpectedSymbol;
									}
								}
							}
						}
						else {
							CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
							throw EXCUnexpectedSymbol;
						}
						break;

					case 3: //Matrice
						if (((iCode = CParser::PARLectureMot(fichier, pcMotCle)) != 1) && *pcMotCle == '[') {
							int iIndice = 0;
							while (((iCode = CParser::PARLectureMot(fichier, pcMotCle)) != 1) && *pcMotCle != ']') {
								if (uiTabSize == iIndice) {
									uiTabSize = uiTabSize * 2;
									pValeursMatrice = (double *)realloc(pValeursMatrice, (uiTabSize * 2 + 1) * sizeof(double));
								}
								pValeursMatrice[iIndice] = std::atof(pcMotCle);
								//Partie pour vérifier que si atof a renvoyé 0 il s'agit bien de 0 et pas d'un caractère :
								if (pValeursMatrice[iIndice] == 0.0) {
									for (uiCompteur = 0; uiCompteur < strlen(pcMotCle); uiCompteur++) {
										if (pcMotCle[uiCompteur] != '.' && pcMotCle[uiCompteur] != '0') {
											CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
											throw EXCUnexpectedSymbol;
										}
									}
								}
								iIndice++;
								uiNbValeursTrouvee++;
							}
						}
						else {
							CException EXCUnexpectedKeyWord(EXC_UnexpectedKeyWord);
							throw EXCUnexpectedKeyWord;
						}

						//lecture du ']' de fermeture :
						if (*pcMotCle != ']') {
							CException EXCUnexpectedKeyWord(EXC_UnexpectedKeyWord);
							throw EXCUnexpectedKeyWord;
						}
						break;

					default: //Cas possible pour [ et ] mal placés et si on rajoute des mots clés non gérés dans pcMotsCles
						CException EXCUnexpectedKeyWord(EXC_UnexpectedKeyWord);
						throw EXCUnexpectedKeyWord;
						break;
					}
				}
				else {
					CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
					throw EXCUnexpectedSymbol;
				}
			}
			else {
				CException EXCUnexpectedSymbol(EXC_UnexpectedSymbol);
				throw EXCUnexpectedSymbol;
			}
		}
		fichier.close();

		//Si le nombre de valeurs lues et la taille de la matrice sont incohérentes, erreur.
		if ((uiNbLignes * uiNbColonnes != uiNbValeursTrouvee) || ((uiNbColonnes == 0) && (uiNbLignes != 0) || (uiNbColonnes != 0) && (uiNbLignes == 0))) {
			CException EXCMatrixParameters(EXC_InvalidMatrixParameters);
			throw EXCMatrixParameters;
		}

		//On alloue ici la matrice
		uiMATLignes = uiNbLignes;
		uiMATColonnes = uiNbColonnes;

		if (uiMATLignes > 0 && uiMATColonnes > 0) {
			pMATMatrice = new MType*[uiNbLignes];
			if (pMATMatrice == NULL) {
				CException EXCMallocFail(EXC_MallocError);
				throw EXCMallocFail;
			}
			for (uiCompteurLigne = 0; uiCompteurLigne < uiNbLignes; uiCompteurLigne++) {
				pMATMatrice[uiCompteurLigne] = new MType[uiNbColonnes];
				if (pMATMatrice[uiCompteurLigne] == NULL) {
					CException EXCMallocFail(EXC_MallocError);
					throw EXCMallocFail;
				}
			}
		}

		//Puis on parcourt notre tableau de valeurs pValeursMatrice pour remplir notre nouvelle matrice
		uiIndiceTableauValeurs = 0;
		for (uiIndiceLigne = 0; uiIndiceLigne < uiNbLignes; uiIndiceLigne++) {
			for (uiIndiceColonne = 0; uiIndiceColonne < uiNbColonnes; uiIndiceColonne++) {
				MATModifierElement(pValeursMatrice[uiIndiceTableauValeurs], uiIndiceLigne, uiIndiceColonne);
				uiIndiceTableauValeurs++;
			}
		}
	}
	else {
		CException EXCOuvertureFichier(EXC_OuvertureFichier);
		throw EXCOuvertureFichier;
	}
}


/**
 * \fn template<class MType> CMatrice<MType>::CMatrice(unsigned int uiLigne, unsigned int uiColonne)
 * \brief Constructeur de confort de la classe CMatrice
 *
 * \param uiLigne unsigned int qui spécifie le nombre de lignes que possédera la CMatrice créée.
 * \param uiColonne unsigned int qui spécifie le nombre de colonnes que possédera la CMatrice créée.
 */
template<class MType> CMatrice<MType>::CMatrice(unsigned int uiLigne, unsigned int uiColonne)
{
	uiMATLignes = uiLigne;
	uiMATColonnes = uiColonne;

	if (uiMATLignes > 0 && uiMATColonnes > 0) {
		pMATMatrice = new MType*[uiLigne];
		if (pMATMatrice == NULL) {
			CException EXCMallocFail(EXC_MallocError);
			throw EXCMallocFail;
		}
		for (unsigned int uiCompteurLigne = 0; uiCompteurLigne < uiLigne; uiCompteurLigne++) {
			pMATMatrice[uiCompteurLigne] = new MType[uiColonne];
			if (pMATMatrice[uiCompteurLigne] == NULL) {
				CException EXCMallocFail(EXC_MallocError);
				throw EXCMallocFail;
			}
		}
	}
}


/**
 * \fn template<class MType> CMatrice<MType>::CMatrice(CMatrice<MType> & MATMatrice)
 * \brief Constructeur de recopie de la classe CMatrice
 *
 * \param MATMatrice CMatrice que l'on souhaite recopier.
 */
template<class MType> CMatrice<MType>::CMatrice(CMatrice<MType> & MATMatrice)
{
	unsigned int uiCompteurLigne;
	unsigned int uiCompteurColonne;

	uiMATLignes = MATMatrice.uiMATLignes;
	uiMATColonnes = MATMatrice.uiMATColonnes;

	if (uiMATLignes > 0 && uiMATColonnes > 0) {
		pMATMatrice = new MType*[uiMATLignes];
		if (pMATMatrice == NULL) {
			CException EXCMallocFail(EXC_MallocError);
			throw EXCMallocFail;
		}

		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			pMATMatrice[uiCompteurLigne] = new MType[uiMATColonnes];
			if (pMATMatrice[uiCompteurLigne] == NULL) {
				CException EXCMallocFail(EXC_MallocError);
				throw EXCMallocFail;
			}
		}

		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			for (uiCompteurColonne = 0; uiCompteurColonne < MATMatrice.uiMATColonnes; uiCompteurColonne++) {
				pMATMatrice[uiCompteurLigne][uiCompteurColonne] = MATMatrice.pMATMatrice[uiCompteurLigne][uiCompteurColonne];
			}
		}
	}
}


/**
 * \fn template<class MType> CMatrice<MType>::CMatrice(CMatrice<MType> && MATMatrice)
 * \brief Constructeur de recopie de la classe CMatrice qui nous permet de faire : CMatrice<> c = a+b;
 *
 * \param MATMatrice CMatrice que l'on souhaite recopier.
 */
template<class MType> CMatrice<MType>::CMatrice(CMatrice<MType> && MATMatrice)
{
	unsigned int uiCompteurLigne;
	unsigned int uiCompteurColonne;

	uiMATLignes = MATMatrice.uiMATLignes;
	uiMATColonnes = MATMatrice.uiMATColonnes;

	if (uiMATLignes > 0 && uiMATColonnes > 0) {
		pMATMatrice = new MType*[uiMATLignes];
		if (pMATMatrice == NULL) {
			CException EXCMallocFail(EXC_MallocError);
			throw EXCMallocFail;
		}

		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			pMATMatrice[uiCompteurLigne] = new MType[uiMATColonnes];
			if (pMATMatrice[uiCompteurLigne] == NULL) {
				CException EXCMallocFail(EXC_MallocError);
				throw EXCMallocFail;
			}
		}

		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			for (uiCompteurColonne = 0; uiCompteurColonne < MATMatrice.uiMATColonnes; uiCompteurColonne++) {
				pMATMatrice[uiCompteurLigne][uiCompteurColonne] = MATMatrice.pMATMatrice[uiCompteurLigne][uiCompteurColonne];
			}
		}
	}
}

/***
						Destructeurs
 ***/

 /**
  * \fn template<class MType> CMatrice<MType>::~CMatrice()
  * \brief Destructeur de la classe CMatrice
  */
template<class MType> CMatrice<MType>::~CMatrice()
{
	unsigned int uiCompteurLigne;

	if (pMATMatrice != NULL) {
		for (uiCompteurLigne = 0; uiCompteurLigne < uiMATLignes; uiCompteurLigne++) {
			delete(pMATMatrice[uiCompteurLigne]);
			pMATMatrice[uiCompteurLigne] = NULL;
		}
		delete(pMATMatrice);
		pMATMatrice = NULL;
	}
}


/***
						Méthodes
 ***/

 /**
  * \fn template<class MType> MType CMatrice<MType>::MATGetElement(unsigned int uiLigne, unsigned int uiColonne)
  * \brief Accesseur de la classe CMatrice pour récupérer un élément de la matrice en position (uiLigne, uiColonne)
  *
  * \param uiLigne unsigned int qui spécifie la ligne de l'élément recherché.
  * \param uiColonne unsigned int qui spécifie la colonne de l'élément recherché.
  *
  * \return MType qui est l'élément que l'on souhaite récupérer.
  */
template<class MType> MType CMatrice<MType>::MATGetElement(unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiLigne >= uiMATLignes || uiColonne >= uiMATColonnes) {
		CException EXCOutOfBounds(EXC_OutOfBounds);
		throw EXCOutOfBounds;
	}

	return pMATMatrice[uiLigne][uiColonne];
}

/**
  * \fn template<class MType> unsigned int CMatrice<MType>::MATGetNbLignes()
  * \brief Accesseur de la classe CMatrice pour récupérer le nombre de lignes de la matrice.
  *
  * \return unsigned int qui est le nombre de lignes de la matrice.
  */
template<class MType> unsigned int CMatrice<MType>::MATGetNbLignes()
{
	return uiMATLignes;
}

/**
  * \fn template<class MType> unsigned int CMatrice<MType>::MATGetNbColonnes()
  * \brief Accesseur de la classe CMatrice pour récupérer le nombre de colonnes de la matrice.
  *
  * \return unsigned int qui est le nombre de colonnes de la matrice.
  */
template<class MType> unsigned int CMatrice<MType>::MATGetNbColonnes()
{
	return uiMATColonnes;
}

/**
 * \fn template<class MType> void CMatrice<MType>::MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne)
 * \brief Accesseur de la classe CMatrice pour modifier l'élément de la matrice en position (uiLigne, uiColonne)
 *
 * \param MTPElement MType élément que l'on souhaite placer dans la matrice.
 * \param uiLigne unsigned int qui spécifie la ligne de l'élément que l'on souhaite modifier.
 * \param uiColonne unsigned int qui spécifie la colonne de l'élément que l'on souhaite modifier.
 */
template<class MType> void CMatrice<MType>::MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiLigne >= uiMATLignes || uiColonne >= uiMATColonnes) {
		CException EXCOutOfBounds(EXC_OutOfBounds);
		throw EXCOutOfBounds;
	}

	pMATMatrice[uiLigne][uiColonne] = MTPElement;
}

/**
  * \fn template<class MType> void CMatrice<MType>::MATAfficherMatrice()
  * \brief Méthode permettant d'afficher la matrice.
  */
template<class MType> void CMatrice<MType>::MATAfficherMatrice()
{
	unsigned int iIndiceLigne;
	unsigned int iIndiceColonne;

	for (iIndiceLigne = 0; iIndiceLigne < uiMATLignes; iIndiceLigne++) {
		for (iIndiceColonne = 0; iIndiceColonne < uiMATColonnes; iIndiceColonne++) {
			std::cout << MATGetElement(iIndiceLigne, iIndiceColonne) << " ";
		}
		std::cout << std::endl;
	}
}

//Surcharge operateur simple

/**
 * \fn template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice & MATMatrice)
 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une autre.
 *
 * /!\ Attention /!\, si la CMatrice possède déjà un tableau 2D alloué, celui-ci sera désalloué mais les éléments présents à l'intérieur de celui-ci ne le seront pas.
 *
 * \param MATMatrice CMatrice qui est la CMatrice que l'on souhaite recopier.
 *
 * \return CMatrice une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatrices)
 */
template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice & MATMatrice)
{
	unsigned int uiCompteurLigne;
	unsigned int uiCompteurColonne;

	if (MATMatrice.uiMATLignes > 0 && MATMatrice.uiMATColonnes > 0) {
		//Si la CMatrice possède déjà un tableau alloué, on le désalloue.
		if (pMATMatrice != NULL) {
			for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
				delete(pMATMatrice[uiCompteurLigne]);
				pMATMatrice[uiCompteurLigne] = NULL;
			}
			delete(pMATMatrice);
			pMATMatrice = NULL;
		}

		//On affecte les nouvelles valeurs nbDeLignes et nbDeColonnes
		uiMATLignes = MATMatrice.uiMATLignes;
		uiMATColonnes = MATMatrice.uiMATColonnes;

		//On crée le tableau 2D
		pMATMatrice = new MType*[uiMATLignes];
		if (pMATMatrice == NULL) {
			CException EXCMallocFail(EXC_MallocError);
			throw EXCMallocFail;
		}
		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			pMATMatrice[uiCompteurLigne] = new MType[uiMATColonnes];
			if (pMATMatrice[uiCompteurLigne] == NULL) {
				CException EXCMallocFail(EXC_MallocError);
				throw EXCMallocFail;
			}
		}

		//On remplit la matrice.
		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			for (uiCompteurColonne = 0; uiCompteurColonne < MATMatrice.uiMATColonnes; uiCompteurColonne++) {
				pMATMatrice[uiCompteurLigne][uiCompteurColonne] = MATMatrice.pMATMatrice[uiCompteurLigne][uiCompteurColonne];
			}
		}

	}

	return *this;
}

/**
 * \fn template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice && MATMatrice)
 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une autre. Version permettant de faire C = A+B; (Avec A,B,C des CMatrices)
 *
 * /!\ Attention /!\, si la CMatrice possède déjà un tableau 2D alloué, celui-ci sera désalloué mais les éléments présents à l'intérieur de celui-ci ne le seront pas.
 *
 * \param MATMatrice CMatrice qui est la CMatrice que l'on souhaite recopier.
 *
 * \return CMatrice une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatrices)
 */
template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice && MATMatrice)
{
	unsigned int uiCompteurLigne;
	unsigned int uiCompteurColonne;

	if (MATMatrice.uiMATLignes > 0 && MATMatrice.uiMATColonnes > 0) {
		//Si la CMatrice possède déjà un tableau alloué, on le désalloue.
		if (pMATMatrice != NULL) {
			for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
				delete(pMATMatrice[uiCompteurLigne]);
				pMATMatrice[uiCompteurLigne] = NULL;
			}
			delete(pMATMatrice);
			pMATMatrice = NULL;
		}

		//On affecte les nouvelles valeurs nbDeLignes et nbDeColonnes
		uiMATLignes = MATMatrice.uiMATLignes;
		uiMATColonnes = MATMatrice.uiMATColonnes;

		//On crée le tableau 2D
		pMATMatrice = new MType*[uiMATLignes];
		if (pMATMatrice == NULL) {
			CException EXCMallocFail(EXC_MallocError);
			throw EXCMallocFail;
		}
		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			pMATMatrice[uiCompteurLigne] = new MType[uiMATColonnes];
			if (pMATMatrice[uiCompteurLigne] == NULL) {
				CException EXCMallocFail(EXC_MallocError);
				throw EXCMallocFail;
			}
		}

		//On remplit la matrice.
		for (uiCompteurLigne = 0; uiCompteurLigne < MATMatrice.uiMATLignes; uiCompteurLigne++) {
			for (uiCompteurColonne = 0; uiCompteurColonne < MATMatrice.uiMATColonnes; uiCompteurColonne++) {
				pMATMatrice[uiCompteurLigne][uiCompteurColonne] = MATMatrice.pMATMatrice[uiCompteurLigne][uiCompteurColonne];
			}
		}

	}

	return *this;
}

/**
 * \fn template<class MType> CMatrice<MType> CMatrice<MType>::operator*(double dNombre)
 * \brief Surcharge d'operateur * permettant de multiplier correctement une CMatrice avec un double. Version permettant de faire A*c; (Avec A une CMatrice et c un double)
 *
 *	/!\ Attention /!\, les éléments de la CMatrice doivent être capables de se multiplier par un double. De plus la multiplication s'effectue dans le sens E*c (Avec E un MType et c un double).
 *
 * \param dNombre double qui est la constante qui multiplie la CMatrice.
 *
 * \return CMatrice une fois qu'elle a été multipliée. Permet de faire : A * B * C; (Avec A,B,C des CMatrices)
 */
template<class MType> CMatrice<MType> CMatrice<MType>::operator*(double dNombre)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	if (uiMATColonnes == 0 || uiMATLignes == 0) {
		CException EXCInvalidDimensions(EXC_InvalidDimensions);
		throw EXCInvalidDimensions;
	}

	CMatrice<MType> MATResult(uiMATLignes, uiMATColonnes);
	if (MATResult.pMATMatrice == NULL) {
		CException EXCMallocFail(EXC_MallocError);
		throw EXCMallocFail;
	}

	for (uiCompteurLignes = 0; uiCompteurLignes < uiMATLignes; uiCompteurLignes++) {
		for (uiCompteurColonnes = 0; uiCompteurColonnes < uiMATColonnes; uiCompteurColonnes++) {
			MATResult.pMATMatrice[uiCompteurLignes][uiCompteurColonnes] = pMATMatrice[uiCompteurLignes][uiCompteurColonnes] * dNombre;
		}
	}

	return MATResult;
}

/**
 * \fn template<class MType> CMatrice<MType> operator*(double dNombre, CMatrice<MType> & MATMatrice)
 * \brief Surcharge d'operateur * permettant de multiplier correctement une CMatrice avec un double. Version permettant de faire c*A; (Avec A une CMatrice et c un double)
 *
 *	/!\ Attention /!\, les éléments de la CMatrice doivent être capables de se multiplier par un double, de plus la multiplication s'effectue dans le sens E*c (Avec E un MType et c un double).
 *
 * \param dNombre double qui est la constante qui multiplie la CMatrice.
 * \param MATMatrice CMatrice qui est la matrice que l'on souhaite multiplier.
 *
 * \return CMatrice une fois qu'elle a été multipliée. Permet de faire : A * B * C; (Avec A,B,C des CMatrices)
 */
template<class MType> CMatrice<MType> operator*(double dNombre, CMatrice<MType> & MATMatrice)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	if (MATMatrice.MATGetNbColonnes() == 0 || MATMatrice.MATGetNbLignes() == 0) {
		CException EXCInvalidDimensions(EXC_InvalidDimensions);
		throw EXCInvalidDimensions;
	}

	CMatrice<MType> MATResult(MATMatrice.MATGetNbLignes(), MATMatrice.MATGetNbColonnes());
	if (MATResult.pMATMatrice == NULL) {
		CException EXCMallocFail(EXC_MallocError);
		throw EXCMallocFail;
	}


	for (uiCompteurLignes = 0; uiCompteurLignes < MATMatrice.MATGetNbLignes(); uiCompteurLignes++) {
		for (uiCompteurColonnes = 0; uiCompteurColonnes < MATMatrice.MATGetNbColonnes(); uiCompteurColonnes++) {

			MType MTPElement = MATMatrice.MATGetElement(uiCompteurLignes, uiCompteurColonnes) * dNombre;

			MATResult.MATModifierElement(MTPElement, uiCompteurLignes, uiCompteurColonnes);

		}
	}

	return MATResult;
}

/**
 * \fn template<class MType> CMatrice<MType> CMatrice<MType>::operator/(double dNombre)
 * \brief Surcharge d'operateur * permettant de diviser correctement une CMatrice avec un double.
 *
 *	/!\ Attention /!\, les éléments de la CMatrice doivent être capables de se diviser par un double, de plus la division s'effectue dans le sens E/c (Avec E un MType et c un double).
 *
 * \param dNombre double qui est la constante qui divise la CMatrice.
 *
 * \return CMatrice une fois qu'elle a été divisée. Permet de faire : A / B / C; (Avec A,B,C des CMatrices)
 */
template<class MType> CMatrice<MType> CMatrice<MType>::operator/(double dNombre)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	if (uiMATColonnes == 0 || uiMATLignes == 0) {
		CException EXCInvalidDimensions(EXC_InvalidDimensions);
		throw EXCInvalidDimensions;
	}
	if (dNombre == 0) {
		CException EXCDivisionByZero(EXC_DivisionByZero);
		throw(EXCDivisionByZero);
	}

	CMatrice<MType> MATResult(uiMATLignes, uiMATColonnes);

	if (MATResult.pMATMatrice == NULL) {
		CException EXCMallocFail(EXC_MallocError);
		throw EXCMallocFail;
	}

	for (uiCompteurLignes = 0; uiCompteurLignes < uiMATLignes; uiCompteurLignes++) {
		for (uiCompteurColonnes = 0; uiCompteurColonnes < uiMATColonnes; uiCompteurColonnes++) {

			MATResult.pMATMatrice[uiCompteurLignes][uiCompteurColonnes] = pMATMatrice[uiCompteurLignes][uiCompteurColonnes] / dNombre;

		}
	}

	return MATResult;
}