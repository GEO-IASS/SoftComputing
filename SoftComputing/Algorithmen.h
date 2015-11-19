#pragma once

#include "Tag.h"
#include "Traininsgdaten.h"
#include "Attribut.h"
#include "Defines.h"
#include <cmath>



double getEntropieZielattributes(Traininsgdaten *tD);
double berechneInfoOutlook(Traininsgdaten *tD);
double berechneInfoWindy(Traininsgdaten *tD);
double splitInfoOutlook(Traininsgdaten *tD);
double splitInfoWindy(Traininsgdaten *tD);
string sucheBesteAtrribut(Traininsgdaten *tD);

double berechneInfo(int Attribute, Traininsgdaten *traininsgdaten);
double berechneGain(int Attribute, Traininsgdaten *traininsgdaten);
double berechneSplitInfo(int Attribute, Traininsgdaten *traininsgdaten);
double berechneGainRatio(int Attribute, Traininsgdaten *traininsgdaten);

