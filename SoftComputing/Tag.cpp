#include "Tag.h"
#include "Defines.h"



Tag::Tag() //: miLuftfeuchtigkeit(DEFAULT), miTemperatur(DEFAULT), mbSpiel(DEFAULT)
		 
{
	maAttribut.msAusblick		  = "DEFAULT";
	maAttribut.miTemperatur		  =	DEFAULT;
	maAttribut.miLuftfeuchtigkeit = DEFAULT;
	maAttribut.mbWind			  =	DEFAULT;
	maAttribut.mbSpiel			  =	DEFAULT;

}


Tag::Tag(string sAusblik, int iTemp,int iLuft,bool bWwind, bool bSpiel) {
	this->maAttribut.msAusblick			= sAusblik;
	this->maAttribut.miTemperatur		= iTemp;
	this->maAttribut.miLuftfeuchtigkeit	= iLuft;
	this->maAttribut.mbWind				= bWwind;
	this->maAttribut.mbSpiel			= bSpiel;
	
	++miTagCounter;
}

Tag::~Tag(){}

string  Tag::getAusblick(){			return this->maAttribut.msAusblick; }
int		Tag::getTemperatur(){		return this->maAttribut.miTemperatur; }
int		Tag::getLuftfeuchtigkeit(){ return this->maAttribut.miLuftfeuchtigkeit; }
bool	Tag::getWind(){				return this->maAttribut.mbWind; }
bool	Tag::getSpiel(){			return this->maAttribut.mbSpiel; }

int		Tag::getTagCounter(){return miTagCounter;}


void Tag::tagAusgabe() {
	cout 
		<< "Ausblick: " << this->maAttribut.msAusblick <<"  |"
		<< " Temp: " << this->maAttribut.miTemperatur << "  |"
		<< " Feuchtigkeit: "<<this->maAttribut.miLuftfeuchtigkeit << "  |"
		<<" Wind: "<< maAttribut.mbWind << "  |"
		<<" Spiel: "<< maAttribut.mbSpiel << "  |" <<endl;
}

