/*Andrei Tiberiu 30421

Algoritmi de sortare

Mai jos sunt implementati Insertion Sort, Selecting Sort si Bubble Sort.

In continuare vom prezenta fiecare algoritm.

De mentionat ca Insertion Sort a fost implementat folosind cautare binara.

1) Insertion Sort:

Iteram sirul dat, initial nesortat. La fiecare pas trebuie sa cautam pozitia din stanga elementului curent, ce respecta proprietatea
ca toate elementele din stanga acestei pozitii sunt mai mici sau egale cu elementul curent. Acest lucru se poate realiza intuitiv,
iterand in stanga pozitiei curente pana gasim un element mai mic sau egal cu elemetul nostru. Prin inductie se poate demonstra ca
primul element gasit mai mic decat elemtul curent ce se afla in stanga acestuia este cel la care ne oprim. Acest lucru este usor de observat,
de vreme ce, la orice pas i, tot subsirul din stanga lui i va fi sortat.
Sa presupunem ca am gasit pozitia cautata, fie ea p.
Odata gasit aceast p, trebuie sa shiftam la dreapta cu o pozitie toate elementele de la p pana la i - 1,
elementul de pe pozitia i urmand sa-l punem pe pozitia p. Astfel subsirul de la inceput pana la pozitia i
va fi sortat.

Aceasta este abordarea neoptimizata.

Cazul favorabil este cel in care sirul este gata sortat, avand complexitate O(n).

Cazul cel mai putin favorabil este cel in care sirul este sortat descrescator,
complexitatea fiind O(n^2)

Solutia optima foloseste cautarea binara pentru a gasi pozitia p.
Acest lucru este corect deoarece atunci cand vom fi la indicele i,
tot subsirul de la 1 pana la i - 1 va fi sortat

Folosind cautarea binara avem complexitate O(n*log2(n)).

In solutia cu cautare binara algoritmul nu este stabil, de vreme ce, atunci cand exista mai multe elementele egale in sir,
acestea nu isi pastreaza ordinea initiala in fisierul de iesire.

2) Selection Sort:

Parcurgem in mod repetat sirul dat incepand cu pozitia i, unde i este initial 1, apoi 2 ... n - 1.
Initial presupunem ca minimul pentru subsirul nesortat(cel de la i la n) se afla pe pozitia i. Deci initial pozMin = i. 
La fiecare index al iterarii, fie el j, comparam elementul de pe pozMin cu elementul de pe pozitia j,
urmand sa le interschimbam daca elementul de pe pozitia j este cel mai mic.

Cazul favorabil este cel in care sirul este gata sortat.

Cazul cel mai putin favorabil este cel in care sirul este sortat descrescator.

Solutia are complexitate O(n ^ 2) in ambele cazuri, cazul favorabil facand insa mai putine atribuiri.

Algoritmul nu este stabil.

3) Bubble Sort

Iteram sirul in mod repetat de la inceput pana la pozitia n - i,
i fiind initial 1, apoi 2 ... n - 1. La fiecare pas, cand gasim doua elemente vecine, astfel incat
elementul din stanga este mai mare decat elementul din dreapta, facem swap intre cele doua.
Acest lucru ne garanteaza ca la fiecare pas, sirul de la pozitia n - i + 1 pana la n va fi sortat.

Cazul favorabil este cel in care sirul este gata sortat.

Cazul cel mai putin favorabil este cel in care sirul este sortat descrescator.

Solutia are complexitate O(n ^ 2) in ambele cazuri.

Algoritmul este stabil deoarece conditia de swap este a[i - 1] > a[i](nu >=),
astfel elementele egale isi pastreaza ordinea in fisierul de iesire.*/

#include<fstream>
#include "Profiler.h"
using namespace std;
int a[1000005], b[1000005], c[1000005], n;

Profiler profiler("SortingAlgorithms");

void InsertionSort(int a[])
{

	profiler.countOperation("comparisonInsertion", n, n);
	profiler.countOperation("asignmentInsertion", n, n);
	for (int i = 1; i <= n; i++)
	{

		profiler.countOperation("asignmentInsertion", n, 3);
		int st = 1, dr = i, mij = 0;

		profiler.countOperation("comparisonInsertion", n, log2(i));
		while (st <= dr)
		{

			profiler.countOperation("asignmentInsertion", n);
			mij = st + (dr - st) / 2;

			profiler.countOperation("comparisonInsertion", n);
			if (a[mij] < a[i])
			{
				profiler.countOperation("asignmentInsertion", n);
				st = mij + 1;
			}
			else
			{
				profiler.countOperation("asignmentInsertion", n);
				dr = mij - 1;
			}
		}

		profiler.countOperation("asignmentInsertion", n);
		int ret = a[i];

		profiler.countOperation("asignmentInsertion", n, i - mij);
		profiler.countOperation("comparisonInsertion", n, i - mij);
		for (int j = i; j > mij; j--)
		{
			profiler.countOperation("asignmentInsertion", n);
			a[j] = a[j - 1];
		}

		profiler.countOperation("asignmentInsertion", n);
		a[st] = ret;
	}

}

void SelectionSort(int a[])
{
	int i, j, pozMin, temp;

	profiler.countOperation("comparisonSelection", n, n - 1);
	profiler.countOperation("asignmentSelection", n, n - 1);
	for (i = 1; i < n; i++)
	{

		profiler.countOperation("asignmentSelection", n);
		pozMin = i;

		profiler.countOperation("comparisonSelection", n, n - i);
		profiler.countOperation("asignmentSelection", n, n - i);
		for (j = i + 1; j <= n; j++)
		{

			profiler.countOperation("comparisonSelection", n);
			if (a[j] < a[pozMin])
			{
				profiler.countOperation("asignmentSelection", n);
				pozMin = j;
			}
		}

		profiler.countOperation("asignmentSelection", n, 3);
		temp = a[i];
		a[i] = a[pozMin];
		a[pozMin] = temp;

	}
}

void BubbleSort(int a[])
{
	int i, j, temp;

	profiler.countOperation("comparisonBubble", n, n - 1);
	profiler.countOperation("asignmentBubble", n, n - 1);
	for (i = 1; i < n; i++)
	{

		profiler.countOperation("comparisonBubble", n, n - i);
		profiler.countOperation("asignmentBubble", n, n - i);
		for (j = 1; j <= n - i; j++)
		{

			profiler.countOperation("comparisonBubble", n);
			if (a[j] > a[j + 1])
			{
				profiler.countOperation("asignmentBubble", n, 3);
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

ifstream in("x.in");
ofstream out("x.out");
int main()
{

	profiler.reset("SortingAlgorithms");

	for (n = 100; n <= 2000; n += 100)
	{
		FillRandomArray(a, n, 1, 10000, false, 1);
		FillRandomArray(b, n, 1, 10000, false, 1);
		FillRandomArray(c, n, 1, 10000, false, 1);
		InsertionSort(a);
		SelectionSort(b);
		BubbleSort(c);
	}

	profiler.createGroup("asignmentBest", "asignmentInsertion", "asignmentSelection", "asignmentBubble");
	profiler.createGroup("comparisonBest", "comparisonInsertion", "comparisonSelection", "comparisonBubble");

	profiler.addSeries("totalInsertion", "asignmentInsertion", "comparisonInsertion");
	profiler.addSeries("totalSelection", "asignmentSelection", "comparisonSelection");
	profiler.addSeries("totalBubble", "asignmentBubble", "comparisonBubble");

	profiler.createGroup("totalBest", "totalInsertion", "totalSelection", "totalBubble");

	profiler.reset("SortingAlgorithms");

	for (n = 100; n <= 2000; n += 100)
	{
		FillRandomArray(a, n, 1, 10000, false, 2);
		FillRandomArray(b, n, 1, 10000, false, 2);
		FillRandomArray(c, n, 1, 10000, false, 2);
		InsertionSort(a);
		SelectionSort(b);
		BubbleSort(c);
	}

	profiler.createGroup("asignmentWorst", "asignmentInsertion", "asignmentSelection", "asignmentBubble");
	profiler.createGroup("comparisonWorst", "comparisonInsertion", "comparisonSelection", "comparisonBubble");

	profiler.addSeries("totalInsertion", "asignmentInsertion", "comparisonInsertion");
	profiler.addSeries("totalSelection", "asignmentSelection", "comparisonSelection");
	profiler.addSeries("totalBubble", "asignmentBubble", "comparisonBubble");

	profiler.createGroup("totalWorst", "totalInsertion", "totalSelection", "totalBubble");

	profiler.reset("SortingAlgorithms");

	for (int i = 1; i <= 5; i++)
	{
		for (n = 100; n <= 2000; n += 100)
		{
			FillRandomArray(a, n, 1, 10000, false, 0);
			FillRandomArray(b, n, 1, 10000, false, 0);
			FillRandomArray(c, n, 1, 10000, false, 0);
			InsertionSort(a);
			SelectionSort(b);
			BubbleSort(c);
		}
	}

	profiler.divideValues("asignmentInsertion", 5);
	profiler.divideValues("comparisonInsertion", 5);

	profiler.divideValues("asignmentSelection", 5);
	profiler.divideValues("comparisonSelection", 5);

	profiler.divideValues("asignmentBubble", 5);
	profiler.divideValues("comparisonBubble", 5);

	profiler.createGroup("asignmentAverage", "asignmentInsertion", "asignmentSelection", "asignmentBubble");
	profiler.createGroup("comparisonAverage", "comparisonInsertion", "comparisonSelection", "comparisonBubble");

	profiler.addSeries("totalInsertion", "asignmentInsertion", "comparisonInsertion");
	profiler.addSeries("totalSelection", "asignmentSelection", "comparisonSelection");
	profiler.addSeries("totalBubble", "asignmentBubble", "comparisonBubble");

	profiler.createGroup("totalAverage", "totalInsertion", "totalSelection", "totalBubble");

	profiler.showReport();

	return 0;
}