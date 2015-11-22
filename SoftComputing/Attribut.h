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

	int		  miAttributID;
	double	  mdAttributEntropie;
	
	void setmiAttributID(int ID);
	void setmdAttributEntropie(double entropie);
	
	Attribut();
	Attribut(int ID, double Entropie);
	~Attribut();
};

