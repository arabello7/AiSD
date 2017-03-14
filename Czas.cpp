#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
int Time_IS[5][15][15];  // 5 - rodzaj ciagu (np. staly) // 15 - rozne liczby n // 15 - liczba pomiarow x
int start, stop, l, x;

void Insertion_Sort (long T[], int n, int num_sort, int rodz_tab) // num_sort - do odpowiedniego zapisania wyniku (ktora tablica)
{																	// rodz_tab - to samo, ale 
	int key, i;
	clock_t start = clock();
	for (int j = 1; j < n; j++)
	{
		key = T[j];
		i = j - 1;
		
		while (i > 0 && T[i] > key) // czy -1
		{
			T[i + 1] = T[i];
			i--;
		}		
		T[i + 1] = key;
	}
	clock_t stop = clock();
	
	switch (num_sort)
	{
		case 0: Time_IS[rodz_tab][l][x] = stop - start; break;
		//case 1: Time_SS[rodz_tab][l][x] = stop - start; break;
		//case 2: Time_HS[rodz_tab][l][x] = stop - start; break;
	}
}

void Selection_Sort ( long T[], int n )
{
	int max, i;
	for ( int j = n; j >= 2; j-- )
	{
		max = j;
		for ( i = j - 1; j >= 1; j-- )
		{
			if ( T[i] > T[max] ) max = i;
		}
		swap( T[j], T[max] );
	}
}
/*
void Heapsort ( long T[], int n )
{
	Build_heap ( T, n );
	int heapsize = n;
	for ( int i = n; i >= 2; i-- )
	{
		swap ( T[1], T[i] );
		heapsize -= 1;
		Heapify ( T, 1, heapsize )
	}
}

void Build_heap ( long T[], int n )
{
	int heapsize = n;
	for ( int i = n/2; i >= 1; i-- )
		Heapify( T, i, heapsize )
}

void Heapify ( long T[], int i, int heapsize )
{
	int l = 2 * i;
	int r = ( 2 * i ) + 1;
	
	if ( l <= heapsize && T[l] > T[i] ) int largest = l;
	else int largest = i;
	
	if ( r <= heapsize && T[r] > T[largest] ) largest = r;
	if ( largest <> i )
	{
		swap ( T[i], T[largest] );
		heapify ( T, largest, heapsize);
	}
}*/

void Cofnij_sort (long A[], long A_2[], int n) //!!chyba nie zmienia
{
	for (int j = 0; j < n; j++)
	{
		A[j] = A_2[j];
	} 
}

/* void print ()
{
	cout<<"Insertion sort"<<endl;
	int n = 1000, j;
	
    for ( int i = 0; i < 15; i++ )
    {
    	cout<<"n = "<<n<<endl;
    	cout<<"number time"<<endl;
    	
    	for ( j = 0; j < 15; j++ )
    	{
			cout<<j+1<<"	"<<Time_IS[0][i][j]<<endl;
		}
		
		cout<<endl;
		n += 1000;
	}
} */

int main()
{
	int j, n, sum;
	l = 0, n = 1000;
//	clock_t start = 0;
//	clock_t stop = 0;
	
	while ( l < 15 )
	{
		long rand_[n], rand_2[n], asc[n], asc_2[n], desc[n], desc_2[n], const_[n], const_2[n], v[n], v_2[n];
		int  x = 77, y = 99999; 
		
		for ( j = 0; j < n; j++ )  
		{
			rand_[j] = rand(); //RANDOM
			rand_2[j] = rand_[j]; //do ponownych pomiarow
			
			asc[j] = x; //ASCENDING
			asc_2[j] = x;
			x += 77;
			
			desc[j] = y; //DESCENDING
			desc_2[j] = y;
			y -= 77;
			
			const_[j] = 7777; //CONSTANS
			const_2[j] = 7777;
			
			if (j > n/2) //V - SHAPED
			{
				v[j] = y; 
				v_2[j] = y;
			}
			else 
			{
				v[j] = x;
				v[j] = x;
			}
		}
		
		for ( x = 0; x < 15; x++ ) // 15 pomiarow takich samych do porownania !!EW.dodaje do sumy i dziele /2
		{
			Insertion_Sort (rand_, n, 0, 0);
				Cofnij_sort ( rand_, rand_2, n);
			Insertion_Sort (asc, n, 0, 1);
				Cofnij_sort ( asc, asc_2, n);
			Insertion_Sort (desc, n, 0, 2);
				Cofnij_sort ( desc, desc_2, n);
			Insertion_Sort (const_, n, 0, 3);
				Cofnij_sort ( const_, const_2, n);
			Insertion_Sort (v, n, 0, 4);
				Cofnij_sort ( v, v_2, n);
		} 
		l++;
		n += 500;
	}
	
	for ( int i=0; i<15; i++)
	{
		for ( j=0; j<15; j++)
		{
			cout<<"rand: "<<Time_IS[0][i][j]<<endl;
			cout<<"asc: "<<Time_IS[1][i][j]<<endl;
			cout<<"desc: "<<Time_IS[2][i][j]<<endl;
			cout<<"const: "<<Time_IS[3][i][j]<<endl;
			cout<<"v-shape: "<<Time_IS[4][i][j]<<endl;
		}
		cout<<i+1<<endl;
	}
	
  //  print ();
 //   printf( "Czas wykonywania: %lu ms\n", stop - start );
}
