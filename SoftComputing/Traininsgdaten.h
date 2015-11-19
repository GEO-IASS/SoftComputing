#pragma once
#include "Tag.h"
#include "Defines.h"
#include <vector>

class Traininsgdaten 
{
public:
	Tag *mtTagArray;
	vector<Tag> *mtTagVector;
	Traininsgdaten();
	~Traininsgdaten();

	void traininsgdatenLesen();
	void traininsgdatenListe();
	
};

