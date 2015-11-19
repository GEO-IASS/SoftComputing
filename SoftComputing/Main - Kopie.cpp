#include "Tag.h"
#include "Defines.h"

int Tag::miTagCounter = 0;


void main() {
	//Tag *D1 = new Tag();
	//cout << D1->getAusblick() << endl;

	Tag *Pday = new Tag[2]{
		{ "Sonnig", HEISS, HOCH, SCHWACH, true },
		{ "Regen", CALT, HOCH, STARK, false }
	};

	Tag Aday[2] = {
		{ "Sonnig", HEISS, HOCH, SCHWACH, true },
		{ "Regen", CALT, HOCH, STARK, false } };

	//Pday[1].tagAusgabe();
	//	Pday[1].tagAusgabe();

	//Aday[0].tagAusgabe();
	//Aday[1].tagAusgabe();
	//cout << "TAGNR:" << Tag::getTagCounter() << endl;


}
