#include "Attribut.h"





void Attribut::setmiAttributID(int ID)
{
	this->miAttributID = ID;
}

void Attribut::setmdAttributEntropie(double entropie)
{
	this->mdAttributEntropie = entropie;
}

Attribut::Attribut() {}
Attribut::Attribut(int ID, double Entropie)
{
	this->miAttributID = ID;
	this->mdAttributEntropie = Entropie;
}

Attribut::~Attribut(){}
