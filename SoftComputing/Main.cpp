#include "Algorithmen.h"
#include <iostream>

//cout << ARRAY_SIZE(tDaten.mtTagArray) << endl;

int Tag::miTagCounter = 0;


vector<Tag> tagVektor;

void main() {
		
	Traininsgdaten tabelle;
		tabelle.traininsgdatenLesen();
	
	
	//cout << tabelle.mtTagVector->size() << endl;
	//tabelle.mtTagVector->erase(tabelle.mtTagVector->begin()+1);
	//cout << tabelle.mtTagVector->size() << endl;
	
	for (int i = 0; i < tabelle.mtTagVector->size(); i++){
	tabelle.mtTagVector->at(i).tagAusgabe();
		//	tagVektor.push_back( tabelle.mtTagArray[i]);
	
	}
	cout << tabelle.mtTagVector->size() << endl;
	
	cout << endl << "Entropie des Zielattributes: " << getEntropieZielattributes(&tabelle)<< endl;
	cout << "InfoOutlook: " <<	"\t\t"<<	berechneInfo(AUSBLICK_ID, &tabelle) << endl;
	cout << "GainOutlook: " << "\t\t" <<	berechneGain(AUSBLICK_ID, &tabelle) << endl;
	cout << "SplitInfoOutlook: " << "\t" << berechneSplitInfo(AUSBLICK_ID, &tabelle) << endl;
	cout << "GainRatioOutlook: " << "\t" << berechneGainRatio(AUSBLICK_ID, &tabelle) << endl;
	cout << "InfoWindy: " << "\t\t" <<		berechneInfo(WIND_ID, &tabelle) << endl;
	cout << "GainWindy: " << "\t\t" <<		berechneGain(WIND_ID, &tabelle) << endl;
	cout << "SplitInfoWindy: " << "\t" <<	berechneSplitInfo(WIND_ID, &tabelle) << endl;
	cout << "GainRatioWindy: " << "\t" <<	berechneGainRatio(WIND_ID, &tabelle) << endl;
	////
	cout << "Bestes Atribut: " << "\t"<<	sucheBesteAtrribut(&tabelle) << endl ; // Nach gain gew�hlt siehe code






	

	vector<Tag> tagarr;
	
	///-----!----Kleine Sortierung --->TESTEN NACH Attributs ----!----------	
	// hier ist nur beispiels
	int k = 0;

	int AttributID = AUSBLICK_ID; //Hier die IDs  einsetzten siehe Defines.h

	switch (AttributID)
	{
	case WIND_ID:	for (int i = 0; i < 14; i++) {
		if (tabelle.mtTagVector->at(i).getWind() == STARK)

		{
			tagarr.push_back(tabelle.mtTagVector->at(i));
			k++;
			cout << "-----" << endl;
		}
	}	break;
	case AUSBLICK_ID:for (int i = 0; i < 14; i++) {
		if (tabelle.mtTagVector->at(i).getAusblick() == SONNIG)
		{
			tagarr.push_back(tabelle.mtTagVector->at(i));
			k++;
			cout << "-----" << endl;
		}

	}  break;
	default:break;
	}

	tabelle.SubSetTraininsgdaten(&tagarr);
	
	for (int i = 0; i < k; i++)
		tabelle.mtTagVector->at(i).tagAusgabe();
	
	cout << tabelle.mtTagVector->size() << endl;
	
	//cin.ignore(1);
	
}//END OF MAIN












