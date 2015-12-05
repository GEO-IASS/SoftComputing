#include <iostream>
#include <iomanip>
#include <string>
#include "Attribut.h"
using namespace std;
#pragma once



class Tag 
{

public:	
	Attribut maAttribut;
	
	Tag(int iAusbl, int iLuft, int iTemp, int iWwind, int iSpiel);
	Tag();
	~Tag();
	int		getAusblick();
	int		getTemperatur();
	int		getLuftfeuchtigkeit();
	int		getWind();
	int		getSpiel();

	
	
	void tagAusgabe();
	
};

