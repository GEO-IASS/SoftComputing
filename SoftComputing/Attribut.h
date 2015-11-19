#pragma once
#include <string>
using namespace std;

class Attribut
{	

public:
	
	string    msAusblick;
	int	      miTemperatur, miLuftfeuchtigkeit;
	bool	  mbWind;
	bool	  mbSpiel;   // Zielattribut 

	Attribut();
	~Attribut();
};

