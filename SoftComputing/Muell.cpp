/* Aufruf Trainingsdaten(a);
Hier wird das Datum call-by-value übergeben.x enthält eine Kopie des Werts,
der durch den Aufrufer übergeben wurde.
Eine Änderung von x innerhalb der Methode ist beim Aufrufer nicht sichtbar.
*/
void Trainingsdaten(int &fTag) {
	int b;
	b = fTag;
	fTag = b + 3;
}

/*Aufruf Trainingsdaten(&a);
Hier wird das Datum call-by-Referenz übergeben. Dafür sorgt der Referenzoperator &. x zeigt nun auf dasselbe Objekt (in diesem Fall einen Integer),
auf das auch der Aufrufer zugreift. Mehr noch, x ist dieselbe Referenz, die auch dem Aufrufer zur Verfügung steht.
Dadurch ist eine Änderung der Referenz (d.h. ein ‚Umbiegen‘ auf ein anderes Objekt) auch beim Aufrufer sichtbar.
Dies ist beachtenswert, weil das in Java und Python nicht der Fall ist.
*/
void Trainingsdaten(int *fTag) {
	int *b = new int;
	*b = 2;
	*fTag = *fTag + *b;
}

/*
Tag * arrayTagAndern(Tag arr[]) {
Tag *temp;
temp = new Tag{ "*****", HEISS, HOCH, SCHWACH, SPIELEN };
arr[2] = *temp;

return arr;
}// nur fürs Testen

*/



//Tag *D1 = new Tag();
//cout << D1->getAusblick() << endl;

//--------Trainingsdaten
/*
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



*/

/*


C[0,1,2,3].....> die Werte des Zielattributes "Tenis spielen ,NICHt spielen

T  > sind Beispiele genau gesagt anzahl von Besipelen hier anzahal von Tagen D1...D14

Informationsgehlat(T) = I(P), wobei P die Wahrscheinlichkeitsverteilung
Entropie(T)=Informationsgehlat(T) ;

T[0,1,2,3...] > die Werte eines Nicht-Zielattributes X)

Entropie(X,T) = Summme von( (|T[]|/|T|)*Entropie(T[])
*/

//Tag Tag::sortierenNachAttributs(Traininsgdaten *tDaten){}
//Tag *D1;
//D1 = new Tag{ "*****", HEISS, HOCH, SCHWACH, SPIELEN };
//vector <Tag> vec;
// D1->tagAusgabe();
//vec = tabelle.mtTagArray;
//tabelle.mtTagArray = arrayTagAndern(tabelle.mtTagArray);