#include "Algorithmen.h"





void main() {
		
	Traininsgdaten tabelle;

	tabelle.traininsgdatenLesen();
	
	
		Attribut b;
		vector <Attribut> a;
		//Attribut *b;
		//b = new Attribut (AUSBLICK_ID, 0.23);
		
	/*	b.setmiAttributID(AUSBLICK_ID);
		b.setmdAttributEntropie(0.123);
		a.push_back(b);
		wurzelAusgabe(a.at(0));*/
		//cout << b.miAttributID;

		
		int wurzel= sucheBesteAtrribut(&tabelle).miAttributID;
		
		machBinaerbaum(wurzel,&tabelle);
	


	
	//cin.ignore(1);
	
}//END OF MAIN



 









