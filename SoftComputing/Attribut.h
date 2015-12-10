#pragma once
#include <string>
using namespace std;

class Attribut
{	

public:
	
	int		msAusblick;
	int	    miTemperatur, miLuftfeuchtigkeit;
	int		mbWind;
	int		mbSpiel;   // Zielattribut 



	int		  miAttributID;
	double	  mdAttributEntropie;
	
	void setmiAttributID(int ID);
	void setmdAttributEntropie(double entropie);
	
	Attribut();
	Attribut(int ID, double Entropie);
	~Attribut();
};

