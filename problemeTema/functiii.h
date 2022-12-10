using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//todo functie ce citeste un vector

void citire(int v[], int& n) {
	ifstream f("vector.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> v[i];
	}
}

//todo functie ce afiseaza un vector

void afisare(int v[], int n, int i) {
	if (i < n) {
		cout << v[i] << ' ';
		i = i + 1;
		afisare(v, n, i);
	}
}

//todo functie ce returneaza indicele minimului

int indiceMin(int v[], int n, int i, int min, int imin) {
	if (i == n) {
		return imin;
	}
	if (i < n) {
		if (v[i] < min) {
			min = v[i];
			imin = i;
		}
		i++;
		indiceMin(v, n, i, min, imin);
	}
}

//todo functie ce returneaza indicele maximului

int indiceMax(int v[], int n, int i, int max, int imax) {
	if (i == n) {
		return imax;
	}
	if (i < n) {
		if (v[i] > max) {
			max = v[i];
			imax = i;
		}
		i++;
		indiceMax(v, n, i, max, imax);
	}
}

//todo functie ce determina câte elemente ale vectorului sunt egale cu diferența 
//dintre cea mai mare și cea mai mică valoare din vector

int contorElemente(int v[], int n, int i, int dif, int ct) {
	if (i == n - 1) {
		return ct;
	}
	else {
		if (v[i] == dif) {
			ct++;
		}
		i++;
		contorElemente(v, n, i, dif, ct);
	}
}

//todo functie ce afiseaza elementele cuprinse între elementul cu valoarea minimă și cel cu valoare maximă din vector, inclusiv acestea.

void afisareElementeMinMax(int v[], int n, int poz1, int poz2) {
	if (poz1 <= poz2) {
		cout << v[poz1] << ' ';
		poz1++;
		afisareElementeMinMax(v, n, poz1, poz2);
	}
}

//todo functie ce calculeaza suma elementelor din vector

int sumaElemente(int v[], int n, int i, int suma) {
	if (i == n) {
		return suma;
	}
	else {
		suma += v[i];
		i++;
		sumaElemente(v, n, i, suma);
	}
}

//todo functie ce detrmina câte dintre elemente au valoarea strict mai mare decât media aritmetică a elementelor vectorului

int ctElementeMa(int v[], int n, int i, int ma, int ct) {
	if (i == n) {
		return ct;
	}
	else {
		if (v[i] > ma) {
			ct++;
		}
		i++;
		ctElementeMa(v, n, i, ma, ct);
	}
}

//todo functie ce calculeaza cmmdc a 2 nr

int cmmdc(int a, int b) {
	int r;
	if (b == 0) {
		if (a == 0) {
			return -1;
		}
		else {
			return a;
		}
	}
	else {
		do {
			r = a % b;
			a = b;
			b = r;
		} while (r != 0);
	}
	return a;
}

//todo functie ce verifica daca 2 nr sumt prime intre ele

bool primeIntreEle(int a, int b) {
	if (cmmdc(a, b) == 1) {
		return true;
	}
	return false;
}

//todo functie ce determina câte dintre perechile de elemente egal depărtate de capetele vectorului sunt prime între ele

int ctPerechiPrim(int v[], int n, int i, int j, int ct) {
	if (i > j) {
		return ct;
	}
	else {
		if (primeIntreEle(v[i], v[j]) == 1) {
			ct++;
		}
		i++;
		j--;
		ctPerechiPrim(v, n, i, j, ct);
	}
}

//todo functiec ce returneaza suma cifrelor unui numar

int sumaCifrelor(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n % 10 + sumaCifrelor(n / 10);
	}
}

//todo functie ce construieste un vector cu proprietatea ca
//y[i] este egal cu restul împărțirii lui x[i] la suma cifrelor lui x[i]

void construireVector(int x[], int n, int i, int y[]) {
	if (i < n) {
		y[i] = x[i] % sumaCifrelor(x[i]);
		i++;
		construireVector(x, n, i, y);
	}
}

//todo functie ce verifica daca un numar este prim

bool prim(int n) {
	for (int d = 2; d < n / 2; d++) {
		if (n % d == 0) {
			return false;
		}
	}
	return true;
}

//todo functie ce construieste un alt vector, y, care să conțină elementele prime din x, în ordine inversă

void constrVectInvers(int x[], int n, int y[], int& m, int i) {
	if (i >= 0) {
		if (prim(x[i])) {
			y[m] = x[i];
			m++;
		}
		i--;
		constrVectInvers(x, n, y, m, i);
	}
}

//todo functie ce verifica daca un numar e mai mic decât toate elementele din vectorul y

bool maiMic(int n, int y[], int m, int i) {
	if (i == m) {
		return true;
	}
	else {
		if (n >= y[i]) {
			return false;
		}
		i++;
		maiMic(n, y, m, i);
	}
}

//todo functie ce citeste 2 functii

void citire2(int x[], int& n, int y[], int& m) {
	ifstream f("vectori.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> x[i];
	}
	f >> m;
	for (int j = 0; j < m; j++) {
		f >> y[j];
	}
}

//todo functie ce afiseaza toate elementele din vectorul x care sunt mai mici decât toate elementele din vectorul y

void afisareElemMaiMici(int x[], int n, int y[], int m, int i, int j) {
	if (i < n) {
		if (maiMic(x[i], y, m, j) == 1) {
			cout << x[i] << ' ';
		}
		i++;
		afisareElemMaiMici(x, n, y, m, i, j);
	}
}

//todo functie ce afiseaza elementele vectorului în următoarea ordine: primul, ultimul, al doilea, penultimul, etc

void afisareOrdine(int v[], int n, int i, int j) {
	if (i < j) {
		cout << v[i] << ' ' << v[j]<< ' ';
		i++;
		j--;
		afisareOrdine(v, n, i, j);
	}
	else {
		if (i == j) {
			cout << v[i] << ' ';
		}
	}
}

//todo functie ce returneaza nr elementelor nenule din vector

int ctElemNenule(int v[], int n, int i, int ct) {
	if (i == n) {
		return ct;
	}
	else {
		if (v[i] != 0) {
			ct++;
		}
		i++;
		ctElemNenule(v, n, i, ct);
	}
}

//todo functie ce inlocuieste toate elementele nule din vector
//cu partea întreagă a mediei aritmetice a elementelor nenule din vector

void inlocuire(int v[], int n, int i, int m) {
	if (i < n) {
		if (v[i] == 0) {
			v[i] = m;
		}
		i++;
		inlocuire(v, n, i, m);
	}
}

//todo functie ce returneaza suma tuturor numerelor naturale mai mici sau egale cu n

int sumaGauss(int i, int n) {
	if (i == n) {
		return 0;
	}
	else {
		i++;
		return i + sumaGauss(i, n);
	}
}

//todo functie ce returneaza valoarea lui n!

int factorial(int i, int n, int fact) {
	if (i > n) {
		return fact;
	}
	else {
		fact = fact * i;
		i++;
		factorial(i, n, fact);
	}
}

//todo functie ce returneaza produsul primelor n pătrate perfecte nenule

int prodPp(int n, int prod, int i) {
	if (i > n) {
		return prod;
	}
	else {
		prod = prod * (i * i);
		i++;
		prodPp(n, prod, i);
	}
}

//todo functie ce determina produsul cifrelor impare ale unui număr natural

int prodCifreImp(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		if ((n % 10) % 2 == 1) {
			return n % 10 * prodCifreImp(n / 10);
		}
		else {
			prodCifreImp(n / 10);
		}
	}
}

//todo functie ce calculeaza suma cifrelor lui n care sunt mai mari sau egale cu 3 și mai mici sau egale cu 7

int sumaCifreN(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		if (n % 10 >= 3 && n % 10 <= 7) {
			return n % 10 + sumaCifreN(n / 10);
		}
		else {
			sumaCifreN(n / 10);
		}
	}
}

//todo functie ce determina cea mai mare cifră a unui număr natural

int cifraMax(int n, int max) {
	if (n == 0) {
		return max;
	}
	else {
		if (n % 10 > max) {
			max = n % 10;
		}
		cifraMax(n / 10, max);
	}
}

//todo functie ce determina nr de cifre ale unui nr

int nrCifre(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return 1 + nrCifre(n / 10);
	}
}

//todo functie ce determina suma divizorilor unui nr

int sumaDiv(int n, int d, int suma) {
	if (d > n) {
		return suma;
	}
	else {
		if (n % d == 0) {
			suma = suma + d;			
		}
		d++;
		sumaDiv(n, d, suma);
	}
}

//todo functie ce determina câți divizori pari are un număr

int ctDivPari(int n, int d, int ct) {
	if (d > n) {
		return ct;
	}
	else {
		if (n % d == 0 && d % 2 == 0) {
			ct++;
		}
		d++;
		ctDivPari(n, d, ct);
	}
}

//todo functie ce returneaza nr format din cifrele impare ale lui n

int nrNouCifImp(int n, int m, int p) {
	if (n == 0) {
		return m;
	}
	else {
		if ((n % 10) % 2 == 1) {
			m = m + (n % 10) * p;
			p *= 10;
		}
		nrNouCifImp(n / 10, m, p);
	}
}

//todo functie ce returneaza nr format din cifrele pare ale lui n

int nrNouCifPare(int n, int m, int p) {
	if (n == 0) {
		return m;
	}
	else {
		if ((n % 10) % 2 == 0) {
			m = m + (n % 10) * p;
			p *= 10;
		}
		nrNouCifPare(n / 10, m, p);
	}
}