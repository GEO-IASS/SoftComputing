#pragma once
#include "Tag.h"
#include "Defines.h"

class Traininsgdaten 
{
public:
	Tag *mtTagArray;
	Traininsgdaten();
	~Traininsgdaten();

	void traininsgdatenLesen();
};

