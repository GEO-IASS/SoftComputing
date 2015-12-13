#pragma once

#include "Tag.h"
#include "Traininsgdaten.h"
#include "Attribut.h"
#include "Defines.h"
#include <cmath>

void wurzelAusgabe(Attribut b);

double getEntropieZielattributes(Traininsgdaten *tD);
double berechneInfoOutlook(Traininsgdaten *tD);
double berechneInfoWindy(Traininsgdaten *tD);
double berechneInfoLuft(Traininsgdaten *tDaten);

double splitInfoOutlook(Traininsgdaten *tD);
double splitInfoWindy(Traininsgdaten *tD);
double splitInfoLuft(Traininsgdaten *tD);

double berechneInfo(int Attribute, Traininsgdaten *traininsgdaten);
double berechneGain(int Attribute, Traininsgdaten *traininsgdaten);
double berechneSplitInfo(int Attribute, Traininsgdaten *traininsgdaten);
double berechneGainRatio(int Attribute, Traininsgdaten *traininsgdaten);

Attribut sucheMaximum(vector <Attribut> vector);
Attribut sucheBesteAtrribut(Traininsgdaten *tDaten);
void teilenTraininsgdaten(int attribut, int attributWert, Traininsgdaten *tD);
void machBinaerbaum(Traininsgdaten *tD);

void allesReset(Traininsgdaten *tD);
void allesResetenAuﬂerWurzel(int WurzelAttributID);


void InfoAusgabe(Traininsgdaten *tD);


