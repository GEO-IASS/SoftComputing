#include "Traininsgdaten.h"
#include "Algorithmen.h"
#define ANZAHLDATEN      tDaten->mtTagVector->size()





//-----------------------------------------
double getEntropieZielattributes(Traininsgdaten *tDaten) {

	double positiv = 0, negativ = 0, summe = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getSpiel()) positiv++;
		else negativ++;
	}
	summe = positiv + negativ;
	double A = positiv / summe;
	double B = negativ / summe;
	return -(A*log2(A) + B*log2(B));
}
//-----------------------------------------
double berechneInfoOutlook(Traininsgdaten *tDaten) {

	double summe = 0;
	double sunny_y = 0, sunny_n = 0, overcast_y = 0, overcast_n = 0, rain_y = 0, rain_n = 0;
	double sunny_sum = 0, overcast_sum = 0, rain_sum = 0;

	for (int j = 0; j <ANZAHLDATEN; j++) {
		
		if ((tDaten->mtTagVector->at(j).getAusblick() == SONNIG) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) sunny_y++;
		if ((tDaten->mtTagVector->at(j).getAusblick() == SONNIG) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) sunny_n++;
		if ((tDaten->mtTagVector->at(j).getAusblick() == BEWOELKT) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) overcast_y++;
		if ((tDaten->mtTagVector->at(j).getAusblick() == BEWOELKT) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) overcast_n++;
		if ((tDaten->mtTagVector->at(j).getAusblick() == REGEN) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) rain_y++;
		if ((tDaten->mtTagVector->at(j).getAusblick() == REGEN) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) rain_n++;
	}

	sunny_sum = sunny_y + sunny_n;
	overcast_sum = overcast_y + overcast_n;
	rain_sum = rain_y + rain_n;
	summe = sunny_sum + overcast_sum + rain_sum;

	double A_s = sunny_y / sunny_sum;
	double B_s = sunny_n / sunny_sum;
	double A_o = overcast_y / overcast_sum;
	double B_o = overcast_n / overcast_sum;
	double A_r = rain_y / rain_sum;
	double B_r = rain_n / rain_sum;
	double T_s = sunny_sum / summe;
	double T_o = overcast_sum / summe;
	double T_r = rain_sum / summe;

	if (A_s == 0) A_s = 1;
	if (B_s == 0) B_s = 1;
	if (A_o == 0) A_o = 1;
	if (B_o == 0) B_o = 1;
	if (A_r == 0) A_r = 1;
	if (B_r == 0) B_r = 1;

	double toreturn = -(T_s*(A_s*log2(A_s) + B_s*log2(B_s))) - (T_o*(A_o*log2(A_o) + B_o*log2(B_o))) - (T_r*(A_r*log2(A_r) + B_r*log2(B_r)));
	return toreturn;

}
//-----------------------------------------
double berechneInfoWindy(Traininsgdaten *tDaten) {

	double stark_y = 0, schwach_y = 0, stark_n = 0, schwach_n = 0, stark_sum = 0, schwach_sum = 0;
	double summe = 0;

	for (int j = 0; j < ANZAHLDATEN; j++) {
		if ((tDaten->mtTagVector->at(j).getWind() == STARK) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) stark_y++;
		if ((tDaten->mtTagVector->at(j).getWind() == STARK) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) stark_n++;
		if ((tDaten->mtTagVector->at(j).getWind() == SCHWACH) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) schwach_y++;
		if ((tDaten->mtTagVector->at(j).getWind() == SCHWACH) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) schwach_n++;
	}

	stark_sum = stark_y + stark_n;
	schwach_sum = schwach_y + schwach_n;
	summe = stark_sum + schwach_sum;

	double A_h = stark_y / stark_sum;		if (A_h == 0) A_h = 1;
	double B_h = stark_n / stark_sum;		if (B_h == 0) B_h = 1;
	double A_l = schwach_y / schwach_sum;	if (A_l == 0) A_l = 1;
	double B_l = schwach_n / schwach_sum;	if (B_l == 0) B_l = 1;
	double T_h = stark_sum / summe;
	double T_l = schwach_sum / summe;

	return -(T_h*(A_h*log2(A_h) + B_h*log2(B_h))) - (T_l*(A_l*log2(A_l) + B_l*log2(B_l)));
}
//-----------------------------------------
double berechneInfoLuft(Traininsgdaten *tDaten) {

	double hoch_y = 0, normal_y = 0, hoch_n = 0, normal_n = 0, hoch_sum = 0, normal_sum = 0;
	double summe = 0;

	for (int j = 0; j < ANZAHLDATEN; j++) {
		if ((tDaten->mtTagVector->at(j).getLuftfeuchtigkeit() == HOCH) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) hoch_y++;
		if ((tDaten->mtTagVector->at(j).getLuftfeuchtigkeit() == HOCH) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) hoch_n++;
		if ((tDaten->mtTagVector->at(j).getLuftfeuchtigkeit() == NORMAL) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) normal_y++;
		if ((tDaten->mtTagVector->at(j).getLuftfeuchtigkeit() == NORMAL) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) normal_n++;
	}

	hoch_sum = hoch_y + hoch_n;
	normal_sum = normal_y + normal_n;
	summe = hoch_sum + normal_sum;

	double A_h = hoch_y / hoch_sum;		if (A_h == 0) A_h = 1;
	double B_h = hoch_n / hoch_sum;		if (B_h == 0) B_h = 1;
	double A_l = normal_y / normal_sum;	if (A_l == 0) A_l = 1;
	double B_l = normal_n / normal_sum;	if (B_l == 0) B_l = 1;
	double T_h = hoch_sum / summe;
	double T_l = normal_sum / summe;

	return -(T_h*(A_h*log2(A_h) + B_h*log2(B_h))) - (T_l*(A_l*log2(A_l) + B_l*log2(B_l)));
}
//-----------------------------------------
double splitInfoOutlook(Traininsgdaten *tDaten) {

	double summe = 0, sunny = 0, overcast = 0, rain = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getAusblick() == SONNIG) sunny++;
		if (tDaten->mtTagVector->at(i).getAusblick() == BEWOELKT) overcast++;
		if (tDaten->mtTagVector->at(i).getAusblick() == REGEN) rain++;
	}

	summe = sunny + overcast + rain;
	double A = sunny / summe;
	double B = overcast / summe;
	double C = rain / summe;

	return -(A*log2(A) + B*log2(B) + C*log2(C));
}
//-----------------------------------------
double splitInfoWindy(Traininsgdaten *tDaten) {

	double summe = 0, stark = 0, schwach = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getWind() == STARK) stark++;
		if (tDaten->mtTagVector->at(i).getWind() == SCHWACH) schwach++;
	}

	summe = schwach + stark;
	double A = stark / summe;
	double B = schwach / summe;

	return -(A*log2(A) + B*log2(B));
}
//-----------------------------------------
double splitInfoLuft(Traininsgdaten *tDaten) {

	double summe = 0, hoch = 0, normal = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getLuftfeuchtigkeit() == HOCH) hoch++;
		if (tDaten->mtTagVector->at(i).getLuftfeuchtigkeit() == NORMAL) normal++;
	}

	summe = normal + hoch;
	double A = hoch / summe;
	double B = normal / summe;

	return -(A*log2(A) + B*log2(B));
}

//------------------AllgemeinAlgorithmenFürRekursion-----------------------

double berechneInfo(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;

	switch (Attribute)
	{
	case AUSBLICK_ID:
		rueckgabeVariable = berechneInfoOutlook(traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = berechneInfoWindy(traininsgdaten);
		break;
	case LUFTFEUCHTIGKEIT_ID:
		rueckgabeVariable = berechneInfoLuft(traininsgdaten);
		break;
		/*UND So Weiter für Andere Attribute falls nöitg*/
	}
	return rueckgabeVariable;

}
//-----------------------------------------
double berechneGain(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;

	switch (Attribute)
	{
	case AUSBLICK_ID:
		rueckgabeVariable = getEntropieZielattributes(traininsgdaten) - berechneInfoOutlook(traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = getEntropieZielattributes(traininsgdaten) - berechneInfoWindy(traininsgdaten);
		break;
	case LUFTFEUCHTIGKEIT_ID:
		rueckgabeVariable = getEntropieZielattributes(traininsgdaten) - berechneInfoLuft(traininsgdaten);
		break;
		/*UND So Weiter für Andere Attribute falls nöitg*/
	}
	return rueckgabeVariable;

}
//-----------------------------------------
double berechneSplitInfo(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;

	switch (Attribute)
	{
	case AUSBLICK_ID:
		rueckgabeVariable = splitInfoOutlook(traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = splitInfoWindy(traininsgdaten);;
		break;
	case LUFTFEUCHTIGKEIT_ID:
		rueckgabeVariable = splitInfoLuft(traininsgdaten);;
		break;
	}
	return rueckgabeVariable;

}

double berechneGainRatio(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;

	switch (Attribute)
	{
	case AUSBLICK_ID:
		rueckgabeVariable = 
		rueckgabeVariable = berechneGain (Attribute,  traininsgdaten) /berechneSplitInfo(Attribute,traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / berechneSplitInfo(Attribute, traininsgdaten);
		break;
	case LUFTFEUCHTIGKEIT_ID:
		rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / berechneSplitInfo(Attribute, traininsgdaten);
		break;
		//UND So Weiter für Andere Attribute falls nöitg
	}
	return rueckgabeVariable;

}
//-----------------------------------------
Attribut sucheMaximum(vector <Attribut> vector) {
	
	Attribut max (vector[0].miAttributID, vector[0].mdAttributEntropie);
	
	for (int i = 1; i < 3; i++) {
		if (max.mdAttributEntropie < vector[i].mdAttributEntropie)
			max.mdAttributEntropie = vector[i].mdAttributEntropie;
	}
	return max;
}

Attribut sucheBesteAtrribut(int blockAttribut, Traininsgdaten *tDaten) {
	//Der C4.5 - Algorithmus ist eine Spezialisierung von
	//Algorithmus 3.1, bei der die Relation “besser” f¨ur die Attributauswahl auf dem sogenannten normierten Iformationsgewinn GainRation
	// Das ist der Gewinn an Informationsgehalt durch das Attribut X.
	//Ranking zwischen Attributen möglich
	//Was will man dadurch erreichen ? Möglichst kleine Entscheidungsbäume, so dass Beispiele schon nach einigen Fragen identifiziert werden können


	vector<Attribut> besteAttributVector;
	

	Attribut besteAttribut;


	//for (int attribut=AUSBLICK_ID; attribut <= WIND_ID; attribut=attribut+AUSBLICK_ID) {
	//Nur Vorubegehend bis TEMPERATUR nicht implemetiert
	//if (attribut == TEMPERATUR_ID) attribut = attribut + AUSBLICK_ID;
	//	besteAttribut.push_back(berechneGainRatio(attribut, tDaten));}

	////    blockAttribut wird dann nicht berechnet 
	
	besteAttribut.setmdAttributEntropie( berechneGainRatio(AUSBLICK_ID, tDaten));
	besteAttribut.setmiAttributID(AUSBLICK_ID);
	besteAttributVector.push_back(besteAttribut);

	besteAttribut.setmdAttributEntropie(berechneGainRatio(LUFTFEUCHTIGKEIT_ID, tDaten));
	besteAttribut.setmiAttributID(LUFTFEUCHTIGKEIT_ID);
	besteAttributVector.push_back(besteAttribut);

	besteAttribut.setmdAttributEntropie(berechneGainRatio(WIND_ID, tDaten));
	besteAttribut.setmiAttributID(WIND_ID);
	besteAttributVector.push_back(besteAttribut);

	


		

			return  sucheMaximum(besteAttributVector);
}



void teilenTraininsgdaten(int attribut, int AttributWert, Traininsgdaten *tD) {
	vector<Tag> *tagVektor = new vector<Tag>;
	
	int size = tD->mtTagVector->size();
	switch (attribut)
	{
	case AUSBLICK_ID:
		if (AttributWert == 1000) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getAusblick() == SONNIG)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		if (AttributWert == 2000) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getAusblick() == REGEN)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		if (AttributWert == 3000) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getAusblick() == BEWOELKT)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}


		break;

	case LUFTFEUCHTIGKEIT_ID:for (int i = 0; i < size; i++) {
		if (tD->mtTagVector->at(i).getLuftfeuchtigkeit() == HOCH)
			tagVektor->push_back(tD->mtTagVector->at(i));
	}  tD->SubSetTraininsgdaten(tagVektor); break;


	case WIND_ID:for (int i = 0; i < size; i++) {
		if (tD->mtTagVector->at(i).getWind() == SCHWACH)
			tagVektor->push_back(tD->mtTagVector->at(i));
	}  tD->SubSetTraininsgdaten(tagVektor); break;
	
	}//end Switch
}



void machBinaerbaum(int besteAttribut, Traininsgdaten *tD) {
	
	int Wuerzel =  besteAttribut;
	
	for (int i = 0; i < tD->mtTagVector->size(); i++)
		tD->mtTagVector->at(i).tagAusgabe();
	
	cout << tD->mtTagVector->size() << endl;
	cout << "GainRatioAusblick: " << "\t\t" << berechneGainRatio(AUSBLICK_ID, tD) << endl;
	cout << "GainRatioLuftFeucht: " << "\t\t" << berechneGainRatio(LUFTFEUCHTIGKEIT_ID, tD) << endl;
	cout << "GainRatioWind: " << "\t\t" << berechneGainRatio(WIND_ID, tD) << endl;
	cout << "Bestes Atribut: " << "\t";  wurzelAusgabe(sucheBesteAtrribut(Wuerzel, tD));
	cout << "------------" << endl;
	
	teilenTraininsgdaten(AUSBLICK_ID, 1000, tD);
	
	for (int i = 0; i < tD->mtTagVector->size(); i++)
		tD->mtTagVector->at(i).tagAusgabe();

	cout << tD->mtTagVector->size() << endl;
	cout << "GainRatioAusblick: " << "\t\t" << berechneGainRatio(AUSBLICK_ID, tD) << endl;
	cout << "GainRatioLuftFeucht: " << "\t\t" << berechneGainRatio(LUFTFEUCHTIGKEIT_ID, tD) << endl;
	cout << "GainRatioWind: " << "\t\t" << berechneGainRatio(WIND_ID, tD) << endl;
	cout << "Bestes Atribut: " << "\t"; wurzelAusgabe(sucheBesteAtrribut(Wuerzel, tD)); // Nach gainratio gewählt siehe code
	cout << "------------" << endl;


	

}

void wurzelAusgabe(Attribut b) {
	cout << b.mdAttributEntropie << "|" << b.miAttributID << endl;
}