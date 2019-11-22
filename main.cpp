#include "COperationsComplexesMatricesPassages.h"
#include <iostream>

void testsUnitaires() {
	
	CMatricePassage<double> MAPM1(2, 2, 1, 2);
	MAPM1.MATModifierElement(1, 0, 0);
	MAPM1.MATModifierElement(1, 0, 1);
	MAPM1.MATModifierElement(1, 1, 0);
	MAPM1.MATModifierElement(1, 1, 1);
	CMatricePassage<double> MAPM2(MAPM1); MAPM2.MAPSetBaseDepart(2); MAPM2.MAPSetBaseArrivee(3);
	CMatricePassage<double> MAPM3; MAPM3 = MAPM1;
	
	printf("P1 : \nBase de départ : %d, Base d'arrivée : %d\n", MAPM1.MAPGetBaseDepart(), MAPM1.MAPGetBaseArrivee());
	MAPM1.MATAfficherMatrice();
	printf("\n");
	printf("P2 : \nBase de départ : %d, Base d'arrivée : %d\n", MAPM2.MAPGetBaseDepart(), MAPM2.MAPGetBaseArrivee());
	MAPM2.MATAfficherMatrice();
	printf("\n");
	printf("P3 : \nBase de départ : %d, Base d'arrivée : %d\n", MAPM3.MAPGetBaseDepart(), MAPM3.MAPGetBaseArrivee());
	MAPM3.MATAfficherMatrice();
	printf("\n");

	printf("=================================\n");

	MAPM2 = MAPM2 * 2;
	MAPM3 = MAPM3 + MAPM2; MAPM3.MAPSetBaseDepart(3); MAPM3.MAPSetBaseArrivee(4);

	printf("P1 : \nBase de départ : %d, Base d'arrivée : %d\n", MAPM1.MAPGetBaseDepart(), MAPM1.MAPGetBaseArrivee());
	MAPM1.MATAfficherMatrice();
	printf("\n");
	printf("P2 : \nBase de départ : %d, Base d'arrivée : %d\n", MAPM2.MAPGetBaseDepart(), MAPM2.MAPGetBaseArrivee());
	MAPM2.MATAfficherMatrice();
	printf("\n");
	printf("P3 : \nBase de départ : %d, Base d'arrivée : %d\n", MAPM3.MAPGetBaseDepart(), MAPM3.MAPGetBaseArrivee());
	MAPM3.MATAfficherMatrice();
	printf("\n");

	printf("=================================\n");

	CMatrice<double> MATVecteur(1, 2); MATVecteur.MATModifierElement(2, 0, 0); MATVecteur.MATModifierElement(2, 0, 1);
	CMatricePassage<double> tableauMatricesPassage[3];
	tableauMatricesPassage[0] = MAPM1; tableauMatricesPassage[1] = MAPM2; tableauMatricesPassage[2] = MAPM3;

	printf("Nouveau vecteur = \n");
	(COperationsComplexesMatricesPassages::OCPChangementDeBase(MATVecteur, 1, 4, tableauMatricesPassage, 3)).MATAfficherMatrice();
	printf("Nouveau vecteur = \n");
	(COperationsComplexesMatricesPassages::OCPChangementDeBase(MATVecteur, tableauMatricesPassage, 3)).MATAfficherMatrice();
	printf("Nouveau vecteur = \n");
	(COperationsComplexesMatricesPassages::OCPChangementDeBase(MATVecteur, 3, MAPM1, MAPM2, MAPM3)).MATAfficherMatrice();
	printf("Nouveau vecteur = \n");
	(COperationsComplexesMatricesPassages::OCPChangementDeBase(MATVecteur, 1, 4, 3, MAPM1, MAPM2, MAPM3)).MATAfficherMatrice();

}



int main(int argc, const char * argv[]) {

	testsUnitaires();

	return 0;
}
