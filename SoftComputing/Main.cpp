#include "Algorithmen.h"
#include <iostream>
//#include <vector>
//cout << ARRAY_SIZE(tDaten.mtTagArray) << endl;

int Tag::miTagCounter = 0;




void main() {
		
	Traininsgdaten tabelle;
	tabelle.traininsgdatenLesen();
		

	for (int i = 0; i < ANZAHLDATEN; i++)
		tabelle.mtTagArray[i].tagAusgabe();


	cout << endl << "Entropie des Zielattributes: " << getEntropieZielattributes(&tabelle) << endl;
	cout << "InfoOutlook: " <<	"\t\t"<<	berechneInfo(AUSBLICK_ID, &tabelle) << endl;
	cout << "InfoWindy: " << "\t\t" <<		berechneInfo(WIND_ID, &tabelle) << endl;
	cout << "GainWindy: " << "\t\t" <<		berechneGain(WIND_ID, &tabelle) << endl;
	cout << "GainOutlook: " << "\t\t" <<	berechneGain(AUSBLICK_ID, &tabelle) << endl;
	cout << "SplitInfoOutlook: " << "\t" << berechneSplitInfo(AUSBLICK_ID, &tabelle) << endl;
	cout << "SplitInfoWindy: " << "\t" <<	berechneSplitInfo(WIND_ID, &tabelle) << endl;
	cout << "GainRatioOutlook: " << "\t" << berechneGainRatio(AUSBLICK_ID, &tabelle) << endl;
	cout << "GainRatioWindy: " << "\t" <<	berechneGainRatio(WIND_ID, &tabelle) << endl;
	
	cout << "Bestes Atribut: " << "\t"<<	sucheBesteAtrribut(&tabelle) << endl ; // Nach gain gewählt siehe code






	/*

	Tag *tagarr;
	tagarr = new Tag[6];
	///-----!----Kleine Sortierung --->TESTEN NACH Attributs ----!----------	
	// hier ist nur beispiels
	int k = 0;

	int AttributID = WIND_ID; //Hier die IDs  einsetzten siehe Defines.h

	switch (AttributID)
	{
	case WIND_ID:	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tabelle.mtTagArray[i].getWind() == STARK)

		{
			tagarr[k] = tabelle.mtTagArray[i];
			k++;
			cout << "-----" << endl;
		}
	}	break;
	case AUSBLICK_ID:for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tabelle.mtTagArray[i].getAusblick() == SONNIG)
		{
			tagarr[k] = tabelle.mtTagArray[i];
			k++;
			cout << "-----" << endl;
		}

	}  break;
	default:break;
	}


	for (int i = 0; i < 6; i++)
		tagarr[i].tagAusgabe();

	cin.ignore(1);
	*/
}//END OF MAIN












