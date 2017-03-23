//
//  main.cpp
//  Zadanie1
//
//  Created by Katarzyna Golis on 13.03.2017.
//  Copyright © 2017 Katarzyna Golis. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

int partition (int d[], int l, int p)
{
    int x, y;
    x = d[l];
    l--;
    p++;
    do
    {
        while (d[--p] > x);
        while (d[++l] < x);
        if (l < p)
        {
            y = d[p];
            d[p] = d[l];
            d[l] = y;
        }
        else return p;
    }
    while (1);
}

void quick_rek (int d[], int l, int p)
{
    int s;
    if (l < p)
    {
        s = partition (d, l, p);
        quick_rek (d, l, s);
        quick_rek (d, s+1, p);
    }
}

void quick_iter (int d[], int l, int p)
{
    int s, n = p + 1, stosl[n], stosp[n], pos;
    pos = 0;
    do {
        if (l == p)
        {
            pos--;
            if (pos >= 0)
            {
                l = stosl[pos];
                p = stosp[pos];
            }
        }
        else
        {
            s = partition (d, l, p);
            stosl[pos] = s + 1;
            stosp[pos++] = p;
            p = s;
        }
    }
    while (pos >= 0);
}

int main()
{
    srand (time (NULL));
    int n = 60000, test = 0, *losowy, *tab1, *tab2, pomiar = 0;
    ofstream plik ("quick_1.txt");
    float wyniki[2][15], czas1 = 0, czas2 = 0, helper = 0;
    
    while (test < 15)
    {
        while (pomiar < 10)
        {
        losowy = new int [n];
        tab1 = new int [n];
        tab2 = new int [n];
        for (int i = 0; i < n; i++)
        {
            losowy[i] = rand ();
            tab1[i] = losowy[i];
            tab2[i] = losowy[i];
        }
        helper = clock();
        quick_rek(tab1, 0, n-1);
        czas1 += ((clock() - helper) / CLOCKS_PER_SEC);
        wyniki[0][test] = czas1;
        
        helper = clock ();
        quick_iter(tab2, 0, n-1);
        czas2 += ((clock() - helper) / CLOCKS_PER_SEC);
        wyniki[1][test] = czas2;
        
        delete [] losowy;
        delete [] tab1;
        delete [] tab2;
            
            pomiar++;
        }
        plik <<  czas1 << " "<<czas2<<endl;
        
        n = n + 60000;
        czas1 = 0;
        czas2 = 0;
        pomiar = 0;
        plik << czas1 << " "<<czas2;
        test++;
    }

    plik << "QUICKSORT" << endl;
    plik << "REKURENCYJNIE;";
    for (int i = 0; i < 15; i++)
    {
        plik << fixed << setprecision(6) << wyniki [0][i]/10.0 << ";";
    }
    plik << endl;
    plik << "ITERACYJNIE;";
    for (int i = 0; i < 15; i++)
    {
        plik << fixed << setprecision(6) << wyniki [1][i]/10.0 << ";";
    }
    plik << endl;
    
    
    
    return 0;
}
