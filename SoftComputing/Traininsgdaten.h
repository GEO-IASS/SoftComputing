#pragma once
#include "Tag.h"
#include "Defines.h"
#include <vector>

class Traininsgdaten 
{
public:
	
	vector<Tag> *mtTagVector;
	Traininsgdaten();
	~Traininsgdaten();

	void traininsgdatenLesen();
	

	void SubSetTraininsgdaten(vector<Tag>* tArra);


	

		
	
};

