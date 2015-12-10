#include "Traininsgdaten.h"
#include "Algorithmen.h"
#define ANZAHLDATEN      tDaten->mtTagVector->size()


int durchlauf = 0;
int AttributWert = 0;
bool stopRekursion = false;
int wurzel;
int test; 

//-----------------------------------------
double getEntropieZielattributes(Traininsgdaten *tDaten) {

	double positiv = 0, negativ = 0, summe = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getSpiel()==SPIELEN) positiv++;
		else negativ++;
	}
	summe = positiv + negativ;
	double A = positiv / summe;
	double B = negativ / summe;
	if (A == 0) A = 1;
	if (B == 0) B = 1;

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

	if (sunny_sum == 0) sunny_sum = 1;
	if (overcast_sum == 0) overcast_sum = 1;
	if (rain_sum == 0) rain_sum = 1;
	if (summe == 0) summe = 1;

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
double berechneInfoTemperatur(Traininsgdaten *tDaten) {

	double summe = 0;
	double heiss_y = 0, heiss_n = 0, mild_y = 0, mild_n = 0, calt_y = 0, calt_n = 0;
	double heiss_sum = 0, mild_sum = 0, calt_sum = 0;

	for (int j = 0; j <ANZAHLDATEN; j++) {

		if ((tDaten->mtTagVector->at(j).getTemperatur() == HEISS) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) heiss_y++;
		if ((tDaten->mtTagVector->at(j).getTemperatur() == HEISS) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) heiss_n++;
		if ((tDaten->mtTagVector->at(j).getTemperatur() == MILD) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) mild_y++;
		if ((tDaten->mtTagVector->at(j).getTemperatur() == MILD) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) mild_n++;
		if ((tDaten->mtTagVector->at(j).getTemperatur() == CALT) && (tDaten->mtTagVector->at(j).getSpiel() == SPIELEN)) calt_y++;
		if ((tDaten->mtTagVector->at(j).getTemperatur() == CALT) && (tDaten->mtTagVector->at(j).getSpiel() == NICHT_SPIELEN)) calt_n++;
	}

	heiss_sum = heiss_y + heiss_n;
	mild_sum = mild_y + mild_n;
	calt_sum = calt_y + calt_n;
	summe = heiss_sum + mild_sum + calt_sum;

	if (heiss_sum == 0) heiss_sum = 1;
	if (mild_sum == 0) mild_sum = 1;
	if (calt_sum == 0) calt_sum = 1;
	if (summe == 0) summe = 1;

	double A_s = heiss_y / heiss_sum;
	double B_s = heiss_n / heiss_sum;
	double A_o = mild_y / mild_sum;
	double B_o = mild_n / mild_sum;
	double A_r = calt_y / calt_sum;
	double B_r = calt_n / calt_sum;
	double T_s = heiss_sum / summe;
	double T_o = mild_sum / summe;
	double T_r = calt_sum / summe;

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

	if (stark_sum == 0) stark_sum = 1;
	if (schwach_sum == 0) schwach_sum = 1;
	if (summe == 0) summe = 1;

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
	
	if (hoch_sum == 0) hoch_sum = 1;
	if (normal_sum == 0) normal_sum = 1;
	if (summe == 0) summe = 1;

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
	if (summe == 0) summe = 1;

	double A = sunny / summe;
	double B = overcast / summe;
	double C = rain / summe;

	if (A == 0) A = 1;
	if (B == 0) B = 1;
	if (C == 0) C = 1;

	return -(A*log2(A) + B*log2(B) + C*log2(C));
}
//-----------------------------------------
double splitInfoTemperatur(Traininsgdaten *tDaten) {

	double summe = 0, heiss = 0, mild = 0, calt = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getTemperatur() == HEISS) heiss++;
		if (tDaten->mtTagVector->at(i).getTemperatur() == MILD) mild++;
		if (tDaten->mtTagVector->at(i).getTemperatur() == CALT) calt++;
	}

	summe = heiss + mild + calt;
	if (summe == 0) summe = 1;

	double A = heiss / summe;
	double B = mild / summe;
	double C = calt / summe;

	if (A == 0) A = 1;
	if (B == 0) B = 1;
	if (C == 0) C = 1;

	return -(A*log2(A) + B*log2(B) + C*log2(C));
}
//-----------------------------------------
double splitInfoLuft(Traininsgdaten *tDaten) {

	double summe = 0, hoch = 0, normal = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getLuftfeuchtigkeit() == HOCH) hoch++;
		if (tDaten->mtTagVector->at(i).getLuftfeuchtigkeit() == NORMAL) normal++;
	}

	summe = normal + hoch;
	if (summe == 0) summe = 1;

	double A = hoch / summe;
	double B = normal / summe;

	if (A == 0) A = 1;
	if (B == 0) B = 1;

	return -(A*log2(A) + B*log2(B));
}
//-----------------------------------------
double splitInfoWindy(Traininsgdaten *tDaten) {

	double summe = 0, stark = 0, schwach = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagVector->at(i).getWind() == STARK) stark++;
		if (tDaten->mtTagVector->at(i).getWind() == SCHWACH) schwach++;
	}

	summe = schwach + stark;
	if (summe == 0) summe = 1;
	
	double A = stark / summe;
	double B = schwach / summe;
	if (A == 0) A = 1;
	if (B == 0) B = 1;

	return -(A*log2(A) + B*log2(B));
}
//-----------------------------------------


//------------------AllgemeinAlgorithmenF�rRekursion-----------------------

double berechneInfo(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;

	switch (Attribute)
	{
	case AUSBLICK_ID:
		rueckgabeVariable = berechneInfoOutlook(traininsgdaten);
		break;
	case TEMPERATUR_ID:
		rueckgabeVariable = berechneInfoTemperatur(traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = berechneInfoWindy(traininsgdaten);
		break;
	case LUFTFEUCHTIGKEIT_ID:
		rueckgabeVariable = berechneInfoLuft(traininsgdaten);
		break;
		/*UND So Weiter f�r Andere Attribute falls n�itg*/
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
	case TEMPERATUR_ID:
		rueckgabeVariable = getEntropieZielattributes(traininsgdaten) - berechneInfoTemperatur(traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = getEntropieZielattributes(traininsgdaten) - berechneInfoWindy(traininsgdaten);
		break;
	case LUFTFEUCHTIGKEIT_ID:
		rueckgabeVariable = getEntropieZielattributes(traininsgdaten) - berechneInfoLuft(traininsgdaten);
		break;
		/*UND So Weiter f�r Andere Attribute falls n�itg*/
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
	case TEMPERATUR_ID:
		rueckgabeVariable = splitInfoTemperatur(traininsgdaten);
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
//-----------------------------------------
double berechneGainRatio(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;
	
	double teilenDurchNull= berechneSplitInfo(Attribute, traininsgdaten);

	switch (Attribute)
	{
	case AUSBLICK_ID:
		if (teilenDurchNull == 0) { 
			teilenDurchNull = 1; 
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		}
		else
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		break;
	case TEMPERATUR_ID:
		if (teilenDurchNull == 0) {
			teilenDurchNull = 1;
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		}
		else
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		break;
	case WIND_ID:
		if (teilenDurchNull == 0) {
			teilenDurchNull = 1;
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		}
		else
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		break;
	case LUFTFEUCHTIGKEIT_ID:
		if (teilenDurchNull == 0) {
			teilenDurchNull = 1;
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		}
		else
			rueckgabeVariable = berechneGain(Attribute, traininsgdaten) / teilenDurchNull;
		break;
		//UND So Weiter f�r Andere Attribute falls n�itg
	}
	return rueckgabeVariable;

}
//-----------------------------------------
Attribut sucheMaximum(vector <Attribut> vector) {

	Attribut max(vector[0].miAttributID, vector[0].mdAttributEntropie);

	for (int i = 1; i < 3; i++) {
		if (max.mdAttributEntropie < vector[i].mdAttributEntropie)
			max = vector[i];
	}
	if (max.mdAttributEntropie == 0) max.setmiAttributID(0);
	return max;
}
//-----------------------------------------
Attribut sucheBesteAtrribut(Traininsgdaten *tDaten) {
	//Der C4.5 - Algorithmus ist eine Spezialisierung von
	//Algorithmus 3.1, bei der die Relation �besser� f�ur die Attributauswahl auf dem sogenannten normierten Iformationsgewinn GainRation
	// Das ist der Gewinn an Informationsgehalt durch das Attribut X.
	//Ranking zwischen Attributen m�glich
	//Was will man dadurch erreichen ? M�glichst kleine Entscheidungsb�ume, so dass Beispiele schon nach einigen Fragen identifiziert werden k�nnen
	vector<Attribut> besteAttributVector;
	Attribut besteAttribut;


	//for (int attribut=AUSBLICK_ID; attribut <= WIND_ID; attribut=attribut+AUSBLICK_ID) {
	//Nur Vorubegehend bis TEMPERATUR nicht implemetiert
	//if (attribut == TEMPERATUR_ID) attribut = attribut + AUSBLICK_ID;
	//	besteAttribut.push_back(berechneGainRatio(attribut, tDaten));}

	////    blockAttribut wird dann nicht berechnet 
	
		besteAttribut.setmdAttributEntropie(berechneGainRatio(AUSBLICK_ID, tDaten));
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
//-----------------------------------------
void teilenTraininsgdaten(int attribut, int AttributWert, Traininsgdaten *tD) {
	
	vector<Tag> *tagVektor = new vector<Tag>;
	
	int size = tD->mtTagVector->size();
	switch (attribut)
	{
	case AUSBLICK_ID:
		if (AttributWert == SONNIG) {
			
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getAusblick() == SONNIG)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		if (AttributWert == REGEN) {
		
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getAusblick() == REGEN)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		if (AttributWert == BEWOELKT) {
				for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getAusblick() == BEWOELKT)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		break;

	case LUFTFEUCHTIGKEIT_ID:
		if (AttributWert == HOCH) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getLuftfeuchtigkeit() == HOCH)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		if (AttributWert == NORMAL) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getLuftfeuchtigkeit() == NORMAL)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}break;

	case WIND_ID:
		if (AttributWert == SCHWACH) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getWind() == SCHWACH)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}

		if (AttributWert == STARK) {
			for (int i = 0; i < size; i++) {
				if (tD->mtTagVector->at(i).getWind() == STARK)
					tagVektor->push_back(tD->mtTagVector->at(i));
			}  tD->SubSetTraininsgdaten(tagVektor);
		}break;
	
	}//end Switch
}






Traininsgdaten *SubDaten = new Traininsgdaten();
Traininsgdaten *WurzelDaten = new Traininsgdaten();

void machBinaerbaum(Traininsgdaten *tD) {
	//cout << "-------------------REKURSIONNUmmer" << i++ << "------------------------" << endl;
	
	
		InfoAusgabe(tD);

		wurzel = sucheBesteAtrribut(tD).miAttributID;
		
		teilenTraininsgdaten(wurzel, SONNIG, tD);
		// Wenn Ende des Blats von dem Baum nicht erreicht wurde geh noch tiefe 
		if (sucheBesteAtrribut(tD).mdAttributEntropie != 0) { SubDaten->mtTagVector = tD->mtTagVector; }
		InfoAusgabe(tD);

		tD->mtTagVector = SubDaten->mtTagVector;
		wurzel = sucheBesteAtrribut(tD).miAttributID;
		teilenTraininsgdaten(wurzel, HOCH, tD);
		InfoAusgabe(tD);

		tD->mtTagVector = SubDaten->mtTagVector;
		wurzel = sucheBesteAtrribut(tD).miAttributID;
		teilenTraininsgdaten(wurzel, NORMAL, tD);
		InfoAusgabe(tD);
	
		
		tD->traininsgdatenLesen();
		wurzel = sucheBesteAtrribut(tD).miAttributID;
		teilenTraininsgdaten(wurzel, BEWOELKT, tD);
		// Wenn Ende des Blats von dem Baum nicht erreicht wurde geh noch tiefe  
		if (sucheBesteAtrribut(tD).mdAttributEntropie != 0) { SubDaten->mtTagVector = tD->mtTagVector; } // Hier wird nix passiert ende des Blatts 
		InfoAusgabe(tD);

		
		tD->traininsgdatenLesen();
		wurzel = sucheBesteAtrribut(tD).miAttributID;
		teilenTraininsgdaten(wurzel, REGEN, tD);
		// Wenn Ende des Blats von dem Baum nicht erreicht wurde geh noch tiefe 
		if (sucheBesteAtrribut(tD).mdAttributEntropie != 0) { SubDaten->mtTagVector = tD->mtTagVector; }
		InfoAusgabe(tD);


		tD->mtTagVector = SubDaten->mtTagVector;
		wurzel = sucheBesteAtrribut(tD).miAttributID;
		teilenTraininsgdaten(wurzel, STARK, tD);
		InfoAusgabe(tD);

		tD->mtTagVector = SubDaten->mtTagVector;
		wurzel = sucheBesteAtrribut(tD).miAttributID;
		teilenTraininsgdaten(wurzel, SCHWACH, tD);
		InfoAusgabe(tD);
		

		
		//machBinaerbaum(tD);


	}// Ende Bin�rbaum

	

	
		
	

	
		
	


	
//-----------------------------------------
void wurzelAusgabe(Attribut b) {
	if(b.miAttributID==AUSBLICK_ID)
	cout << b.mdAttributEntropie << "|" << "AUSBLICK"<< endl;
	if (b.miAttributID == TEMPERATUR_ID)
	cout << b.mdAttributEntropie << "|" << "TEMPERATUR" << endl;
	if (b.miAttributID == LUFTFEUCHTIGKEIT_ID)
	cout << b.mdAttributEntropie << "|" << "LUFTFEUCHTIGKEIT" << endl;
	if (b.miAttributID == WIND_ID)
	cout << b.mdAttributEntropie << "|" << "WIND" << endl;

}
//-----------------------------------------
void InfoAusgabe(Traininsgdaten *tD) {

#ifdef AUSGABE1
	for (int i = 0; i < tD->mtTagVector->size(); i++)
		tD->mtTagVector->at(i).tagAusgabe();
	cout << tD->mtTagVector->size() << endl;
	cout << "GainRatioAusblick: " << "\t\t" << berechneGainRatio(AUSBLICK_ID, tD) << endl;
	cout << "GainRatioLuftFeucht: " << "\t\t" << berechneGainRatio(LUFTFEUCHTIGKEIT_ID, tD) << endl;
	cout << "GainRatioWind: " << "\t\t\t" << berechneGainRatio(WIND_ID, tD) << endl;
	cout << "Bestes Atribut: " << "\t\t";  wurzelAusgabe(sucheBesteAtrribut(tD)); cout << endl;
	cout << "------------" << endl;

#else 
	if (wurzel == 100 && test == 60)
	{
		cout << "\t\t\t\t\t\tregnerisch" << endl << endl;

	}
	if (wurzel == 100 && test == 70)
	{
		cout << "\t\t\t\tbewoelkt" << endl << endl;
		cout << "\t\t\t\tPlay" << endl << endl;

	}
	if (wurzel == 300 && test == 80)
	{
		cout << "Luftfeuchtigkeit" << endl << endl;
		cout << "Normal\t\tHoch" << endl << endl;
		cout << "Play\t\tDon't Play" << endl << endl;
	}
	if (wurzel == 400 && test == 90)
	{
		cout << "\t\t\t\t\t\tWind" << endl << endl;
		cout << "\t\t\t\t\t\tSchwach\t\tStark" << endl << endl;
		cout << "\t\t\t\t\t\tPlay\t\tDon't Play" << endl << endl;
	}
	if (wurzel == 100 && test == 50)
	{
		cout << "\t\t\t\tAusblick" << endl << endl;
		cout << "sonnig" << endl << endl;
	}
#endif

}

