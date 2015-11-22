#include "Algorithmen.h"


//cout << ARRAY_SIZE(tDaten.mtTagArray) << endl;




void main() {
		
	Traininsgdaten tabelle;
		tabelle.traininsgdatenLesen();
	
	
	//cout << tabelle.mtTagVector->size() << endl;
	//tabelle.mtTagVector->erase(tabelle.mtTagVector->begin()+1);
	//cout << tabelle.mtTagVector->size() << endl;
	
	//for (int i = 0; i < tabelle.mtTagVector->size(); i++){
	//tabelle.mtTagVector->at(i).tagAusgabe();
	//	//	tagVektor.push_back( tabelle.mtTagArray[i]);
	//
	//}
	//cout << tabelle.mtTagVector->size() << endl;
	
	//cout <<"Zielattributes: "<< "\t" <<		getEntropieZielattributes(&tabelle)<< endl;
	//cout << "InfoOutlook: " <<	"\t\t"<<	berechneInfo(AUSBLICK_ID, &tabelle) << endl;
	//cout << "GainOutlook: " << "\t\t" <<	berechneGain(AUSBLICK_ID, &tabelle) << endl;
	//cout << "SplitInfoOutlook: " << "\t" << berechneSplitInfo(AUSBLICK_ID, &tabelle) << endl;
	
	//cout << "InfoWindy: " << "\t\t" <<		berechneInfo(WIND_ID, &tabelle) << endl;
	//cout << "GainWindy: " << "\t\t" <<		berechneGain(WIND_ID, &tabelle) << endl;
	//cout << "SplitInfoWindy: " << "\t" <<	berechneSplitInfo(WIND_ID, &tabelle) << endl;
	//cout << "GainRatioAusblick: " << "\t" << berechneGainRatio(AUSBLICK_ID, &tabelle) << endl;
	//cout << "GainRatioWind: " << "\t\t" <<	berechneGainRatio(WIND_ID, &tabelle) << endl;
	//cout << "GainRatioLuft: " << "\t\t" <<	berechneGainRatio(LUFTFEUCHTIGKEIT_ID, &tabelle) << endl;
	//cout << "Bestes Atribut: " << "\t"<<	sucheBesteAtrribut(AUSBLICK_ID,&tabelle) << endl ; // Nach gainratio gewählt siehe code
	//cout << "------------" << endl;

	
		Attribut b;
		vector <Attribut> a;
		//Attribut *b;
		//b = new Attribut (AUSBLICK_ID, 0.23);
		
		b.setmiAttributID(AUSBLICK_ID);
		b.setmdAttributEntropie(0.123);
		a.push_back(b);
		

		wurzelAusgabe(a.at(0));

		//cout << b.miAttributID;

		int hhh= sucheBesteAtrribut(5000, &tabelle).miAttributID;
		
		machBinaerbaum(hhh,&tabelle);
	


	
	//cin.ignore(1);
	
}//END OF MAIN



 









