#include "Algorithmen.h"
#include <iostream>

//cout << ARRAY_SIZE(tDaten.mtTagArray) << endl;

int Tag::miTagCounter = 0;



void splitTraininsgdaten(int attribut, Traininsgdaten *tD);

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
	cout << "Bestes Atribut: " << "\t"<<	sucheBesteAtrribut(&tabelle) << endl ; // Nach gain gewählt siehe code






	

	
	
	///-----!----Kleine Sortierung --->TESTEN NACH Attributs ----!----------	
	// hier ist nur beispiels
	

	


	

	splitTraininsgdaten(AUSBLICK_ID, &tabelle);
	
	for (int i = 0; i < tabelle.mtTagVector->size(); i++)
		tabelle.mtTagVector->at(i).tagAusgabe();
	
	cout << tabelle.mtTagVector->size() << endl;
	cout << "Info: " << "\t\t" << berechneInfo(AUSBLICK_ID, &tabelle) << endl;
	
	//cin.ignore(1);
	
}//END OF MAIN
vector<Tag> tagarr;

 void splitTraininsgdaten(int attribut, Traininsgdaten *tD) {
	 
	 
	 int size = tD->mtTagVector->size();
	
	 switch (attribut)
	 {
	 
	 case AUSBLICK_ID:for (int i = 0; i < size; i++) {
		 if (tD->mtTagVector->at(i).getAusblick() == REGEN)
			 tagarr.push_back(tD->mtTagVector->at(i));
			 }  tD->SubSetTraininsgdaten(&tagarr); break;
	
  }//end Switch
}









