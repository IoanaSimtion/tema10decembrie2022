#include "functiii.h"
#include "math.h"
#pragma once


//VECTORI

//553: Calculaţi indicele imin și indicele imax ai elementului cu valoarea minimă, respectiv cu valoarea maximă, din vectorul dat.

void sol1() {
	int v[100], n, imin=0, imax=0;
	citire(v, n);
	//afisare(v, n, 0);
	cout << "Indicele minimului: " << indiceMin(v, n, 0, INT_MAX, imin) << endl;
	cout << "Indicele maximului: " << indiceMax(v, n, 0, INT_MIN, imax) << endl;
}


//547: Să se determine câte elemente ale vectorului sunt egale cu diferența 
//dintre cea mai mare și cea mai mică valoare din vector.

void sol2() {
	int v[50], n, ct = 0, dif, imax = 0, imin = 0;
	citire(v, n);
	//cout << v[indiceMax(v, n, 0, INT_MIN, imax)] << endl;
	//cout << v[indiceMin(v, n, 0, INT_MAX, imin)] << endl;
	dif = abs(v[indiceMax(v, n, 0, INT_MIN, imax)] - v[indiceMin(v, n, 0, INT_MAX, imin)]);
	cout << contorElemente(v, n, 0, dif, ct);
}


//4151: Se citește un vector cu n elemente, numere naturale distincte.
//Să se afișeze elementele cuprinse între elementul cu valoarea minimă și cel cu valoare maximă din vector, inclusiv acestea.

void sol3() {
	int v[100], n, pozMin, imin = 0, imax = 0, pozMax;
	citire(v, n);
	pozMin = indiceMin(v, n, 0, INT_MAX, imin);
	pozMax = indiceMax(v, n, 0, INT_MIN, imax);
	if (pozMin < pozMax) {
		afisareElementeMinMax(v, n, pozMin, pozMax);
	}
	else {
		afisareElementeMinMax(v, n, pozMax, pozMin);
	}
}


//487: Se dă un vector cu n numere naturale.
//Să se determine câte dintre elemente au valoarea strict mai mare decât media aritmetică a elementelor vectorului.

void sol4() {
	int v[50], n, suma = 0, ct = 0;
	citire(v, n);
	cout << ctElementeMa(v, n, 0, sumaElemente(v, n, 0, suma) / n, ct);
}


//492: Se dă un vector cu n numere naturale. 
//Să se determine câte dintre perechile de elemente egal depărtate de capetele vectorului sunt prime între ele.

void sol5() {
	int v[50], n, ct = 0;
	citire(v, n);
	cout << ctPerechiPrim(v, n, 0, n - 1 , ct);
}


//493: Se dă un vector x cu n elemente, numere naturale. Să se construiască un alt vector, y, 
//cu proprietatea că y[i] este egal cu restul împărțirii lui x[i] la suma cifrelor lui x[i].

void sol6() {
	int x[50], n, y[50];
	citire(x, n);
	construireVector(x, n, 0, y);
	afisare(y, n, 0);
}


//495: Se dă un vector x cu n elemente, numere naturale.
//Să se construiască un alt vector, y, care să conțină elementele prime din x, în ordine inversă.

void sol7() {
	int x[50], n, y[50], m = 0;
	citire(x, n);
	constrVectInvers(x, n, y, m, n - 1);
	afisare(y, m, 0);
}


//4104: Se dă un vector x cu n elemente numere întregi, și un vector y cu m elemente, de asemenea numere întregi.
//Să se afișeze toate elementele din vectorul x care sunt mai mici decât toate elementele din vectorul y.

void sol8() {
	int x[50], n, y[50], m;
	//cout << maiMic(x[0], y, m, 0);
	citire2(x, n, y, m);
	afisareElemMaiMici(x, n, y, m, 0, 0);
}


//489: Se citește un vector cu n elemente, numere naturale.
//Să se afișeze elementele vectorului în următoarea ordine: primul, ultimul, al doilea, penultimul, etc.

void sol9() {
	int v[50], n;
	citire(v, n);
	afisareOrdine(v, n, 0, n - 1);
}


//161: Se dă un vector cu n elemente, numere naturale. Să se înlocuiască toate 
//elementele nule din vector cu partea întreagă a mediei aritmetice a elementelor nenule din vector.

void sol10() {
	int v[50], n, ct = 0, medie, suma = 0;
	citire(v, n);
	//cout << ctElemNenule(v, n, 0, ct);
	medie = sumaElemente(v, n, 0, suma) / ctElemNenule(v, n, 0, ct);
	//cout << medie;
	inlocuire(v, n, 0, medie);
	afisare(v, n, 0);
}


//NUMERE


//1360: Se citește n număr natural. Calculați suma tuturor numerelor naturale mai mici sau egale cu n.

void sol11() {
	int n = 7;
	cout << sumaGauss(0, n);
}


//49: Să se scrie un program care citește numărul natural n și determină valoarea lui n!.

void sol12() {
	int n = 4;
	cout << factorial(1, n, 1);
}


//4273: Se dă numărul natural nenul n. Să se determine produsul primelor n pătrate perfecte nenule.

void sol13() {
	int n = 4;
	cout << prodPp(n, 1, 1);
}


//65: Să se scrie un program care să determine produsul cifrelor impare ale unui număr natural citit de la tastatură.

void sol14() {
	int n = 2705;
	cout << prodCifreImp(n);
}


//3979: Se dă un număr natural nenul n. Calculați suma cifrelor lui n
//care sunt mai mari sau egale cu 3 și mai mici sau egale cu 7.

void sol15() {
	int n = 3590;
	cout << sumaCifreN(n);
}


//68: Să se scrie un program care să determine cea mai mare cifră a unui număr natural citit de la tastatură.

void sol16() {
	int n = 2705;
	cout << cifraMax(n, INT_MIN);
}


//3662: Se dă un număr natural n. Determinaţi câte cifre are suma cifrelor sale.

void sol17() {
	int n = 99;
	cout << nrCifre(sumaCifrelor(n));
}


//376: Se citește un număr natural n. Să se determine suma divizorilor săi.

void sol18() {
	int n = 6;
	cout << sumaDiv(n, 1, 0);
}


//388: Se citește un număr natural n. Să se determine câți divizori pari are acest număr.

void sol19() {
	int n = 12;
	cout << ctDivPari(n, 1, 0);
}


//1613: Se citește un număr natural nenul n. Numărul n1 este format doar din cifrele pare ale lui n. 
//Numărul n2 este format doar din cifrele impare ale lui n. Calculați valoarea absolută a diferenței lor.

void sol20() {
	int n = 120341, nImp = 0, nPar = 0;
	cout << nrNouCifImp(n, nImp, 1) << endl;
	cout << nrNouCifPare(n, nPar, 1) << endl;
	cout << "diferenta absoluta: " << abs(nrNouCifImp(n, nImp, 1) - nrNouCifPare(n, nPar, 1));
}