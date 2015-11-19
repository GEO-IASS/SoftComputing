#include "Traininsgdaten.h"




//-----------------------------------------
double getEntropieZielattributes(Traininsgdaten *tDaten) {

	double positiv = 0, negativ = 0, summe = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagArray[i].maAttribut.mbSpiel) positiv++;
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

	for (int j = 0; j < ANZAHLDATEN; j++) {
		if ((tDaten->mtTagArray[j].maAttribut.msAusblick == SONNIG) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == SPIELEN)) sunny_y++;
		if ((tDaten->mtTagArray[j].maAttribut.msAusblick == SONNIG) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == NICHT_SPIELEN)) sunny_n++;
		if ((tDaten->mtTagArray[j].maAttribut.msAusblick == BEWOELKT) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == SPIELEN)) overcast_y++;
		if ((tDaten->mtTagArray[j].maAttribut.msAusblick == BEWOELKT) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == NICHT_SPIELEN)) overcast_n++;
		if ((tDaten->mtTagArray[j].maAttribut.msAusblick == REGEN) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == SPIELEN)) rain_y++;
		if ((tDaten->mtTagArray[j].maAttribut.msAusblick == REGEN) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == NICHT_SPIELEN)) rain_n++;
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

	return -(T_s*(A_s*log2(A_s) + B_s*log2(B_s))) - (T_o*(A_o*log2(A_o) + B_o*log2(B_o))) - (T_r*(A_r*log2(A_r) + B_r*log2(B_r)));

}
//-----------------------------------------
double berechneInfoWindy(Traininsgdaten *tDaten) {

	double stark_y = 0, schwach_y = 0, stark_n = 0, schwach_n = 0, stark_sum = 0, schwach_sum = 0;
	double summe = 0;

	for (int j = 0; j < ANZAHLDATEN; j++) {
		if ((tDaten->mtTagArray[j].maAttribut.mbWind == STARK) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == SPIELEN)) stark_y++;
		if ((tDaten->mtTagArray[j].maAttribut.mbWind == STARK) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == NICHT_SPIELEN)) stark_n++;
		if ((tDaten->mtTagArray[j].maAttribut.mbWind == SCHWACH) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == SPIELEN)) schwach_y++;
		if ((tDaten->mtTagArray[j].maAttribut.mbWind == SCHWACH) && (tDaten->mtTagArray[j].maAttribut.mbSpiel == NICHT_SPIELEN)) schwach_n++;
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
double splitInfoOutlook(Traininsgdaten *tDaten) {

	double summe = 0, sunny = 0, overcast = 0, rain = 0;
	for (int i = 0; i < ANZAHLDATEN; i++) {
		if (tDaten->mtTagArray[i].maAttribut.msAusblick == SONNIG) sunny++;
		if (tDaten->mtTagArray[i].maAttribut.msAusblick == BEWOELKT) overcast++;
		if (tDaten->mtTagArray[i].maAttribut.msAusblick == REGEN) rain++;
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
		if (tDaten->mtTagArray[i].maAttribut.mbWind == STARK) stark++;
		if (tDaten->mtTagArray[i].maAttribut.mbWind == SCHWACH) schwach++;
	}

	summe = schwach + stark;
	double A = stark / summe;
	double B = schwach / summe;

	return -(A*log2(A) + B*log2(B));
}
//-----------------------------------------
//-----------------------------------------

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
		/*UND So Weiter für Andere Attribute falls nöitg*/
	}
	return rueckgabeVariable;

}

double berechneGainRatio(int Attribute, Traininsgdaten *traininsgdaten) {
	double rueckgabeVariable;

	switch (Attribute)
	{
	case AUSBLICK_ID:
		rueckgabeVariable = (getEntropieZielattributes(traininsgdaten) - berechneInfoOutlook(traininsgdaten)) / splitInfoOutlook(traininsgdaten);
		break;
	case WIND_ID:
		rueckgabeVariable = (getEntropieZielattributes(traininsgdaten) - berechneInfoWindy(traininsgdaten)) / splitInfoWindy(traininsgdaten);
		break;
		/*UND So Weiter für Andere Attribute falls nöitg*/
	}
	return rueckgabeVariable;

}
//-----------------------------------------
string sucheBesteAtrribut(Traininsgdaten *tDaten) {
	//	Das ist der Gewinn an Informationsgehalt durch das Attribut X.
	//Ranking zwischen Attributen möglich
	//Was will man dadurch erreichen ? Möglichst kleine Entscheidungsbäume, so dass Beispiele schon nach einigen Fragen identifiziert werden können
	//berechneGain(); 
	//Let  D be the attribute with largest Gain(D,S) among attributes in R;
	//je große Gain desto besser -->> mehr Zunahme an Informationsgehalt !
	//return  besteAttribut


	string besteAttribut;

	if (berechneGain(AUSBLICK_ID, tDaten) > berechneGain(WIND_ID, tDaten))
		besteAttribut = "Ausblick";
	else
		besteAttribut = "Wind";

	return  besteAttribut;
}
