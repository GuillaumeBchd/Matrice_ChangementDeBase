/**
 * \file CMatricePassage.h
 * \brief Fichier header de la classe CMatricePassage.
 * \author Guillaume.Bouchard Colin.Troisemaine
 * \version 0.1
 * \date 28 mai 2019
 *
 * Fichier header contenant une classe CMatricePassage héritant de la classe template CMatrice. Elle contient les accesseurs simples de cet objet et 
 * les méthodes permettant de créer les objets de cette classe. Pour faire des operations sur ces matrices, inclure COperationsComplexesMatricesPassages.h dans votre fichier également.
 * /!\ Attention /!\ Ce fichier contenant des méthodes et fonctions template, toutes les fonctions ont été écrites en inline et sont donc présent dans ce fichier header, merci de ne pas modifier
 * ces méthodes pour la bonne utilisation de cette librairie.
 *
 */

#ifndef CMatricePassage_h
#define CMatricePassage_h

#include "CMatrice.h"
#include "CException.h"

//Codes d'erreur : à partir de 400 pour cette classe
#define EXC_NullMatrix 400
#define EXC_ChangementImpossible 401

template <class MType>
class CMatricePassage : public CMatrice<MType> {

    //Attributs
private:

	/** Base de départ de la matrice de passage */
    unsigned int uiMAPBaseDepart;
	/** Base d'arrivée de la matrice de passage */
    unsigned int uiMAPBaseArrivee;
    

    //Constructeurs et Destructeurs
public:

	/**
	 * \fn CMatricePassage<MType>::CMatricePassage()
	 * \brief Constructeur par défaut de la classe CMatricePassage
	 *
	 * Ce constructeur appelle le constructeur par défaut de la classe CMatrice.
	 *
	 */
    CMatricePassage();

	/**
	 * \fn CMatricePassage<MType>::CMatricePassage(CMatricePassage & MAPMatrice)
	 * \brief Constructeur de recopie de la classe CMatricePassage prenant en paramètre un lvalue.
	 *
	 * Ce constructeur appelle le constructeur de recopie de la classe CMatrice.
	 *
	 * \param MAPMatrice CMatricePassage que l'on souhaite recopier.
	 */
    CMatricePassage(CMatricePassage & MAPMatrice);

	/**
	 * \fn CMatricePassage<MType>::CMatricePassage(CMatricePassage && MAPMatrice)
	 * \brief Constructeur de recopie de la classe CMatricePassage prenant en paramètre un rvalue.
	 *
	 * Ce constructeur appelle le constructeur de recopie de la classe CMatrice.
	 *
	 * \param MAPMatrice CMatricePassage que l'on souhaite recopier.
	 */
    CMatricePassage(CMatricePassage && MAPMatrice);

	/**
	 * \fn CMatricePassage<MType>::CMatricePassage(unsigned int uiBaseDepart, unsigned int uiBaseArrivee)
	 * \brief Constructeur de confort de la classe CMatricePassage
	  *
	 * Ce constructeur appelle le constructeur par défaut de la classe CMatrice.
	 *
	 * \param uiBaseDepart unsigned int qui spécifie la base de départ de la CMatricePassage créée.
	 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de la CMatricePassage créée.
	 */
    CMatricePassage(unsigned int uiBaseDepart, unsigned int uiBaseArrivee);

	/**
	 * \fn CMatricePassage<MType>::CMatricePassage(unsigned int uiNbLignes, unsigned int uiNbColonnes, unsigned int uiBaseDepart, unsigned int uiBaseArrivee)
	 * \brief Constructeur de confort de la classe CMatricePassage
	  *
	 * Ce constructeur appelle le constructeur de confort de la classe CMatrice prenant en paramètre un nombre de lignes et un nombre de colonnes.
	 *
	 * \param uiNbLignes unsigned int qui spécifie le nombre de lignes que possédera la CMatrice créée.
	 * \param uiNbColonnes unsigned int qui spécifie le nombre de colonnes que possédera la CMatrice créée.
	 * \param uiBaseDepart unsigned int qui spécifie la base de départ de la CMatricePassage créée.
	 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de la CMatricePassage créée.
	 */
    CMatricePassage(unsigned int uiNbLignes, unsigned int uiNbColonnes, unsigned int uiBaseDepart, unsigned int uiBaseArrivee);

	/**
	 * \fn CMatricePassage<MType>::CMatricePassage(CMatricePassage && MAPMatrice)
	 * \brief Constructeur de confort de la classe CMatricePassage
	 *
	 * Ce constructeur appelle le constructeur de recopie de la classe CMatrice.
	 * Ce constructeur permet de "convertir" une CMatrice en CMatricePassage.
	 *
	 * \param MATMatrice CMatrice<MType> que l'on souhaite recopier.
	 * \param uiBaseDepart unsigned int qui spécifie la base de départ de la CMatricePassage créée.
	 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de la CMatricePassage créée. 
	 */
    CMatricePassage(CMatrice<MType> & MATMatrice, unsigned int uiBaseDepart, unsigned int uiBaseArrivee);

	/**
	 * \fn CMatricePassage<MType>::~CMatricePassage()
	 * \brief Destructeur de la classe CMatricePassage
	 */
    ~CMatricePassage();
    
    //Méthodes
public:
	/**
	 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatricePassage & MAPMatrice)
	 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatricePassage dans une autre.
	 *
	 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
	 *
	 * \param MAPMatrice CMatricePassage qui est la CMatricePassage que l'on souhaite recopier (en lvalue).
	 *
	 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
	 */
    CMatricePassage operator=(CMatricePassage & MAPMatrice);
	/**
	 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatricePassage && MAPMatrice)
	 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatricePassage dans une autre.
	 *
	 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
	 *
	 * \param MAPMatrice CMatricePassage qui est la CMatricePassage que l'on souhaite recopier (en rvalue).
	 *
	 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
	 */
    CMatricePassage operator=(CMatricePassage && MAPMatrice);

	/**
	 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatrice<MType> & MATMatrice)
	 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une CMatricePassage.
	 *
	 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
	 *
	 * \param MATMatrice CMatrice<MType> qui est la CMatrice que l'on souhaite recopier (en lvalue).
	 *
	 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
	 */
	CMatricePassage operator=(CMatrice<MType> & MATMatrice);
	/**
	 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatrice<MType> && MATMatrice)
	 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une CMatricePassage.
	 *
	 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
	 *
	 * \param MATMatrice CMatrice<MType> qui est la CMatrice que l'on souhaite recopier (en rvalue).
	 *
	 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
	 */
	CMatricePassage operator=(CMatrice<MType> && MATMatrice);
    
	/**
	 * \fn unsigned int CMatricePassage<MType>::MAPGetBaseDepart()
	 * \brief Accesseur en lecture sur uiMAPBaseDepart.
	 *
	 * \return unsigned int qui représente la base de départ de la CMatricePassage.
	 */
    unsigned int MAPGetBaseDepart() { return uiMAPBaseDepart; }

	/**
	 * \fn unsigned int CMatricePassage<MType>::MAPGetBaseArrivee()
	 * \brief Accesseur en lecture sur uiMAPBaseArrivee.
	 *
	 * \return unsigned int qui représente la base d'arrivée de la CMatricePassage.
	 */
    unsigned int MAPGetBaseArrivee() { return uiMAPBaseArrivee; }

	/**
	 * \fn void CMatricePassage<MType>::MAPSetBaseDepart(unsigned int uiBaseDepart)
	 * \brief Accesseur en écriture sur uiMAPBaseDepart.
	 *
	 * \param uiBaseDepart unsigned int qui représente la base de départ de la CMatricePassage.
	 */
    void MAPSetBaseDepart(unsigned int uiBaseDepart) { uiMAPBaseDepart = uiBaseDepart; }

	/**
	 * \fn void CMatricePassage<MType>::MAPSetBaseArrivee(unsigned int uiBaseArrivee)
	 * \brief Accesseur en écriture sur uiMAPBaseArrivee.
	 *
	 * \param uiBaseArrivee unsigned int qui représente la base d'arrivée de la CMatricePassage.
	 */
    void MAPSetBaseArrivee(unsigned int uiBaseArrivee) { uiMAPBaseArrivee = uiBaseArrivee; }
    
};

/*** Constructeurs et Destructeur ***/

/**
 
 * \fn CMatricePassage<MType>::CMatricePassage()
 * \brief Constructeur par défaut de la classe CMatricePassage
 *
 * Ce constructeur appelle le constructeur par défaut de la classe CMatrice.
 *
 */
template<class MType>
inline CMatricePassage<MType>::CMatricePassage() :CMatrice<MType>()
{
    uiMAPBaseDepart = 0;
    uiMAPBaseArrivee = 0;
}

/**
 * \fn CMatricePassage<MType>::CMatricePassage(CMatricePassage & MAPMatrice)
 * \brief Constructeur de recopie de la classe CMatricePassage prenant en parametre un lvalue.
 *
 * Ce constructeur appelle le constructeur de recopie de la classe CMatrice.
 *
 * \param MAPMatrice CMatricePassage que l'on souhaite recopier.
 */
template<class MType>
inline CMatricePassage<MType>::CMatricePassage(CMatricePassage & MAPMatrice) :CMatrice<MType>(MAPMatrice)
{
    uiMAPBaseDepart = MAPMatrice.uiMAPBaseDepart;
    uiMAPBaseArrivee = MAPMatrice.uiMAPBaseArrivee;
}

/**
 * \fn CMatricePassage<MType>::CMatricePassage(CMatricePassage && MAPMatrice)
 * \brief Constructeur de recopie de la classe CMatricePassage prenant en parametre un rvalue.
 *
 * Ce constructeur appelle le constructeur de recopie de la classe CMatrice.
 *
 * \param MAPMatrice CMatricePassage que l'on souhaite recopier.
 */
template<class MType>
inline CMatricePassage<MType>::CMatricePassage(CMatricePassage && MAPMatrice) :CMatrice<MType>(MAPMatrice)
{
    uiMAPBaseDepart = MAPMatrice.uiMAPBaseDepart;
    uiMAPBaseArrivee = MAPMatrice.uiMAPBaseArrivee;
}

/**
 * \fn CMatricePassage<MType>::CMatricePassage(unsigned int uiBaseDepart, unsigned int uiBaseArrivee)
 * \brief Constructeur de confort de la classe CMatricePassage
 *
 * Ce constructeur appelle le constructeur par défaut de la classe CMatrice.
 *
 * \param uiBaseDepart unsigned int qui spécifie la base de départ de la CMatricePassage créée.
 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de la CMatricePassage créée.
 */
template<class MType>
inline CMatricePassage<MType>::CMatricePassage(unsigned int uiBaseDepart, unsigned int uiBaseArrivee) :CMatrice<MType>()
{
    uiMAPBaseDepart = uiBaseDepart;
    uiMAPBaseArrivee = uiBaseArrivee;
}

/**
 * \fn CMatricePassage<MType>::CMatricePassage(unsigned int uiNbLignes, unsigned int uiNbColonnes, unsigned int uiBaseDepart, unsigned int uiBaseArrivee)
 * \brief Constructeur de confort de la classe CMatricePassage
 *
 * Ce constructeur appelle le constructeur de confort de la classe CMatrice prenant en paramètre un nombre de lignes et un nombre de colonnes.
 *
 * \param uiNbLignes unsigned int qui spécifie le nombre de lignes que possédera la CMatrice créée.
 * \param uiNbColonnes unsigned int qui spécifie le nombre de colonnes que possédera la CMatrice créée.
 * \param uiBaseDepart unsigned int qui spécifie la base de départ de la CMatricePassage créée.
 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de la CMatricePassage créée.
 */
template<class MType>
inline CMatricePassage<MType>::CMatricePassage(unsigned int uiNbLignes, unsigned int uiNbColonnes, unsigned int uiBaseDepart, unsigned int uiBaseArrivee) :CMatrice<MType>(uiNbLignes, uiNbColonnes)
{
    uiMAPBaseDepart = uiBaseDepart;
    uiMAPBaseArrivee = uiBaseArrivee;
}

/**
 * \fn CMatricePassage<MType>::CMatricePassage(CMatricePassage && MAPMatrice)
 * \brief Constructeur de confort de la classe CMatricePassage
 *
 * Ce constructeur appelle le constructeur de recopie de la classe CMatrice.
 * Ce constructeur permet de "convertir" une CMatrice en CMatricePassage.
 *
 * \param MATMatrice CMatrice<MType> que l'on souhaite recopier.
 * \param uiBaseDepart unsigned int qui spécifie la base de départ de la CMatricePassage créée.
 * \param uiBaseArrivee unsigned int qui spécifie la base d'arrivée de la CMatricePassage créée.
 */
template<class MType>
inline CMatricePassage<MType>::CMatricePassage(CMatrice<MType> & MATMatrice, unsigned int uiBaseDepart, unsigned int uiBaseArrivee) :CMatrice<MType>(MATMatrice)
{
    uiMAPBaseDepart = uiBaseDepart;
    uiMAPBaseArrivee = uiBaseArrivee;
}

/**
 * \fn CMatricePassage<MType>::~CMatricePassage()
 * \brief Destructeur de la classe CMatricePassage
 */
template<class MType>
inline CMatricePassage<MType>::~CMatricePassage()
{
    //Appelle par défaut le destructeur de CMatrice
}


/*** Méthodes ***/

/**
 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatricePassage & MAPMatrice)
 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatricePassage dans une autre.
 *
 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
 *
 * \param MAPMatrice CMatricePassage qui est la CMatricePassage que l'on souhaite recopier (en lvalue).
 *
 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
 */
template<class MType>
inline CMatricePassage<MType> CMatricePassage<MType>::operator=(CMatricePassage<MType> & MAPMatrice)
{
    CMatrice<MType>::operator=((CMatrice<MType>)MAPMatrice);
    uiMAPBaseDepart = MAPMatrice.uiMAPBaseDepart;
    uiMAPBaseArrivee = MAPMatrice.uiMAPBaseArrivee;
    
    return *this;
}

/**
 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatricePassage && MAPMatrice)
 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatricePassage dans une autre.
 *
 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
 *
 * \param MAPMatrice CMatricePassage qui est la CMatricePassage que l'on souhaite recopier (en rvalue).
 *
 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
 */
template<class MType>
inline CMatricePassage<MType> CMatricePassage<MType>::operator=(CMatricePassage<MType> && MAPMatrice)
{
    CMatrice<MType>::operator=((CMatrice<MType>)MAPMatrice);
    uiMAPBaseDepart = MAPMatrice.uiMAPBaseDepart;
    uiMAPBaseArrivee = MAPMatrice.uiMAPBaseArrivee;
    
    return *this;
}

/**
 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatrice<MType> & MATMatrice)
 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une CMatricePassage.
 *
 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
 *
 * \param MATMatrice CMatrice<MType> qui est la CMatrice que l'on souhaite recopier (en lvalue).
 *
 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
 */
template<class MType>
inline CMatricePassage<MType> CMatricePassage<MType>::operator=(CMatrice<MType> & MATMatrice)
{
	CMatrice<MType>::operator=(MATMatrice);

	return *this;
}

/**
 * \fn CMatricePassage CMatricePassage<MType>::operator=(CMatrice<MType> && MATMatrice)
 * \brief Surcharge d'operateur d'affectation permettant de recopier correctement une CMatrice dans une CMatricePassage.
 *
 * Cette méthode appelle la surcharge d'operateur d'affectation de la méthode CMatrice.
 *
 * \param MATMatrice CMatrice<MType> qui est la CMatrice que l'on souhaite recopier (en rvalue).
 *
 * \return CMatricePassage une fois qu'elle a été recopiée. Permet de faire : A = B = C; (Avec A,B,C des CMatricePassage)
 */
template<class MType>
inline CMatricePassage<MType> CMatricePassage<MType>::operator=(CMatrice<MType> && MATMatrice)
{
	CMatrice<MType>::operator=(MATMatrice);

	return *this;
}

#endif /* CMatricePassage_h */