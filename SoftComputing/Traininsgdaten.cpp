#include "Traininsgdaten.h"



Traininsgdaten::Traininsgdaten()
{

}
Traininsgdaten::~Traininsgdaten()
{
	delete[] mtTagArray;
	
}

void Traininsgdaten::traininsgdatenLesen() {
	traininsgdatenListe();
	mtTagArray = new Tag[mtTagVector->size()];
	
			for (int i = 0; i < mtTagVector->size(); i++) 
			{
			mtTagArray[i] = mtTagVector->at(i);
			}
}
void Traininsgdaten::traininsgdatenListe() {
	mtTagVector = new vector<Tag> {
		//	 (sAusblik, iTemp, iLuft,bWwind,  bSpiel)
		/*D1*/{ SONNIG,  HEISS, HOCH,   SCHWACH, NICHT_SPIELEN },
		/*D2*/{ SONNIG,  HEISS, HOCH,   STARK,   NICHT_SPIELEN },
		/*D3*/{ BEWOELKT,HEISS, HOCH,   SCHWACH, SPIELEN },
		/*D4*/{ REGEN,   MILD,  HOCH,   SCHWACH, SPIELEN },
		/*D5*/{ REGEN,   CALT,  NORMAL, SCHWACH, SPIELEN },
		/*D6*/{ REGEN,   CALT,  NORMAL, STARK,   NICHT_SPIELEN },
		/*D7*/{ BEWOELKT,CALT,  NORMAL, STARK,   SPIELEN },
		/*D8*/{ SONNIG,  MILD,  HOCH,   SCHWACH, NICHT_SPIELEN },
		/*D9*/{ SONNIG,  CALT,  NORMAL, SCHWACH, SPIELEN },
		/*D10*/{ REGEN,   MILD,  NORMAL, SCHWACH, SPIELEN },
		/*D11*/{ SONNIG,  MILD,  NORMAL, STARK,   SPIELEN },
		/*D12*/{ BEWOELKT,MILD,  HOCH,   STARK,   SPIELEN },
		/*D13*/{ BEWOELKT,HEISS, NORMAL, SCHWACH, SPIELEN },
		/*D14*/{ REGEN,   MILD,  HOCH,   STARK,   NICHT_SPIELEN },

		};

	
}

void Traininsgdaten::setNewTraininsgdaten(Tag *tArra) {
	delete[] mtTagArray;
	mtTagArray = tArra;
}