#include "Tag.h"
#include "Defines.h"




Tag::Tag() //: miLuftfeuchtigkeit(DEFAULT), miTemperatur(DEFAULT), mbSpiel(DEFAULT)
		 
{
	maAttribut.msAusblick		  = DEFAULT;
	maAttribut.miTemperatur		  =	DEFAULT;
	maAttribut.miLuftfeuchtigkeit = DEFAULT;
	maAttribut.mbWind			  =	DEFAULT;
	maAttribut.mbSpiel			  =	DEFAULT;

}


Tag::Tag(int iAusblik, int iTemp,int iLuft,int iWwind, int iSpiel) {
	this->maAttribut.msAusblick			= iAusblik;
	this->maAttribut.miTemperatur		= iTemp;
	this->maAttribut.miLuftfeuchtigkeit	= iLuft;
	this->maAttribut.mbWind				= iWwind;
	this->maAttribut.mbSpiel			= iSpiel;
	
}

Tag::~Tag(){}

int		Tag::getAusblick(){			return this->maAttribut.msAusblick; }
int		Tag::getTemperatur(){		return this->maAttribut.miTemperatur; }
int		Tag::getLuftfeuchtigkeit(){ return this->maAttribut.miLuftfeuchtigkeit; }
int		Tag::getWind(){				return this->maAttribut.mbWind; }
int		Tag::getSpiel(){			return this->maAttribut.mbSpiel; }




void Tag::tagAusgabe() {
	string a, t, f, w, s;
	if (maAttribut.msAusblick == SONNIG) a = "SONNIG  ";
	if (maAttribut.msAusblick == REGEN) a = "REGEN   ";
	if (maAttribut.msAusblick == BEWOELKT) a = "BEWOELKT";
	
	if (maAttribut.miTemperatur == HEISS) t = "HEISS   ";
	if (maAttribut.miTemperatur == MILD) t = "MILD    ";
	if (maAttribut.miTemperatur == CALT) t = "CALT    ";
	
	if (maAttribut.miLuftfeuchtigkeit == HOCH) f = "HOCH    ";
	if (maAttribut.miLuftfeuchtigkeit == NORMAL) f = "NORMAL  ";

	if (maAttribut.mbWind == STARK) w = "STARK   ";
	if (maAttribut.mbWind == SCHWACH) w = "SCHWACH ";
	
	if (maAttribut.mbSpiel == SPIELEN) s = "YES";
	if (maAttribut.mbSpiel == NICHT_SPIELEN) s = "NO";
	
	cout 
		<< "Ausblick:" << a <<"|"
		<< " Temp:" << t << " |"
		<< " Feucht:"<<f << "|"
		<<" Wind:"<< w << "|"
		<<" Spiel:"<< s<< "|" <<endl;
}

