#include <iostream>
#include <string>
#include "Attribut.h"
using namespace std;
#pragma once



class Tag 
{
private:  
	
	static int miTagCounter;

public:	
	Attribut maAttribut;
	Tag(string sAusbl, int iLuft, int iTemp, bool bWwind, bool bSpiel);
	Tag();
	~Tag();
	string	getAusblick();
	int		getTemperatur();
	int		getLuftfeuchtigkeit();
	bool	getWind();
	bool	getSpiel();

	static int getTagCounter();
	
	void tagAusgabe();
	
};

