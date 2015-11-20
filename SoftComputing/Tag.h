#include <iostream>
#include <iomanip>
#include <string>
#include "Attribut.h"
using namespace std;
#pragma once



class Tag 
{
private:  
	
	

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

	
	
	void tagAusgabe();
	
};

