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

void insertion_sort (int *A, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = A[i];
        for (j = i-1; j >=0 && A[j] > key; j--)
        {
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }
}

void selection_sort (int *A, int size)
{
    int k;
    for (int i = 0; i < size; i++)
    {
        k = i;
        for (int j = i+1; j < size; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        std::swap(A[k], A[i]);
    }

}

void heapify (int *A, int i, int size)
{
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    int p = i;

    if (l < size && A[l] > A[i])
    {
        p = l;
    }
    if (r < size && A[r] > A[p])
    {
        p = r;
    }
    if (p != i)
    {
        std::swap (A[i], A[p]);
        heapify (A, p, size);
    }
}

void buildheap (int *A, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify (A, i, size);
    }
}

void heap_sort (int *A, int size)
{
    buildheap (A,size);
    for (int i = size - 1; i >= 1; i--)
    {
        std::swap (A[0], A[i]);
        heapify (A, 0, size - (size - i));
    }
}

void merge_sort (int *A, int l, int r, int *B)
{
    int m = (l + r) / 2;
    if ((m - l) > 0)
    {
        merge_sort (A, l, m, B);
    }
    if ((r - m) > 1)
    {
        merge_sort (A, m+1, r, B);
    }
    int i = l, j = m + 1;
    for (int k = l; k <= r; k++)
    {
        if ((i <= m && j > r) || ( i <= m && j <= r && A[i] <= A[j]))
            {
                B[k] = A[i];
                i++;
            }
        else
            {
                B[k] = A[j];
                j++;
            }
    }
    for (int k = l; k <= r; k++)
    {
        A[k] = B[k];
    }
}

int main()
{
    srand (time (NULL));
    int n = 0, random, test = 0;
    float losowy_czas, malejacy_czas, rosnacy_czas, staly_czas, vksztaltny_czas;
    float wyniki[5][60];
    ofstream plik ("wyniki.txt");
    while (test < 60)
    {
        if (test == 0 || test == 15 || test == 30 || test == 45)
        {
            n = 50000;
        }
        else n = n + 50000;

        int *losowy, *malejacy, *rosnacy, *staly, *vksztaltny, *POM;
        losowy = new int[n];
        malejacy = new int[n];
        rosnacy = new int[n];
        staly = new int[n];
        vksztaltny = new int[n];
        POM = new int[n];

        random = rand();
        for (int i = 0; i < n; i++)
        {
            losowy[i] = rand();
        }

        for (int i = 0; i < n; i++)
        {
            malejacy[i] = n-i;

        }

        for (int i = 0; i < n; i++)
        {
            rosnacy[i] = i;

        }

        for (int i = 0; i < n; i++)
        {
            staly[i] = random;

        }

        for (int i = 0; i <= n / 2; i++)
        {
            vksztaltny[i] = 2 * (n - 1);

        }

        for (int i = n / 2; i < n; i++)
        {
            vksztaltny[i] = (2 * i) + 1;

        }

        if (test < 15)
        {
            losowy_czas = clock();
            insertion_sort (losowy, n-1);
            losowy_czas = (clock() - losowy_czas) / CLOCKS_PER_SEC;
            wyniki[0][test] = losowy_czas;
            cout << fixed << setprecision(6) << wyniki[0][test] << " ";

            malejacy_czas = clock();
            insertion_sort (malejacy, n-1);
            malejacy_czas = (clock() - malejacy_czas) / CLOCKS_PER_SEC;
            wyniki[1][test] = malejacy_czas;
            cout << fixed << setprecision(6) << wyniki[1][test] << " ";


            rosnacy_czas = clock();
            insertion_sort (rosnacy, n-1);
            rosnacy_czas = (clock() - rosnacy_czas) / CLOCKS_PER_SEC;
            wyniki[2][test] = rosnacy_czas;
            cout << fixed << setprecision(6) << wyniki[2][test] << " ";


            staly_czas = clock();
            insertion_sort (staly, n-1);
            staly_czas = (clock() - staly_czas) / CLOCKS_PER_SEC;
            wyniki[3][test] = staly_czas;
            cout << fixed << setprecision(6) << wyniki[3][test] << " ";


            vksztaltny_czas = clock();
            insertion_sort (vksztaltny, n-1);
            vksztaltny_czas = (clock() - vksztaltny_czas) / CLOCKS_PER_SEC;
            wyniki[4][test] = vksztaltny_czas;
            cout << fixed << setprecision(6) << wyniki[4][test] << " ";

        }

        else if (test >= 15 && test < 30)
        {
            losowy_czas = clock();
            selection_sort (losowy, n-1);
            losowy_czas = (clock() - losowy_czas) / CLOCKS_PER_SEC;
            wyniki[0][test] = losowy_czas;
            cout << fixed << setprecision(6) << wyniki [0][test] << " ";


            malejacy_czas = clock();
            selection_sort (malejacy, n-1);
            malejacy_czas = (clock() - malejacy_czas) / CLOCKS_PER_SEC;
            wyniki[1][test] = malejacy_czas;
            cout << fixed << setprecision(6) << wyniki [1][test] << " ";


            rosnacy_czas = clock();
            selection_sort (rosnacy, n-1);
            rosnacy_czas = (clock() - rosnacy_czas) / CLOCKS_PER_SEC;
            wyniki[2][test] = rosnacy_czas;
            cout << fixed << setprecision(6) << wyniki [2][test] << " ";


            staly_czas = clock();
            selection_sort (staly, n-1);
            staly_czas = (clock() - staly_czas) / CLOCKS_PER_SEC;
            wyniki[3][test] = staly_czas;
            cout << fixed << setprecision(6) << wyniki [3][test] << " ";


            vksztaltny_czas = clock();
            selection_sort (vksztaltny, n-1);
            vksztaltny_czas = (clock() - vksztaltny_czas) / CLOCKS_PER_SEC;
            wyniki[4][test] = vksztaltny_czas;
            cout << fixed << setprecision(6) << wyniki [4][test] << " ";

        }

        else if (test >= 30 && test < 45)
        {
            losowy_czas = clock();
            merge_sort (losowy, 0, n-1, POM);
            losowy_czas = (clock() - losowy_czas) / CLOCKS_PER_SEC;
            wyniki[0][test] = losowy_czas;
            cout << fixed << setprecision(6) << wyniki [0][test] << " ";


            malejacy_czas = clock();
            merge_sort (malejacy, 0, n-1, POM);
            malejacy_czas = (clock() - malejacy_czas) / CLOCKS_PER_SEC;
            wyniki[1][test] = malejacy_czas;
            cout << fixed << setprecision(6) << wyniki [1][test] << " ";


            rosnacy_czas = clock();
            merge_sort (rosnacy, 0, n-1, POM);
            rosnacy_czas = (clock() - rosnacy_czas) / CLOCKS_PER_SEC;
            wyniki[2][test] = rosnacy_czas;
            cout << fixed << setprecision(6) << wyniki [2][test] << " ";


            staly_czas = clock();
            merge_sort (staly, 0, n-1, POM);
            staly_czas = (clock() - staly_czas) / CLOCKS_PER_SEC;
            wyniki[3][test] = staly_czas;
            cout << fixed << setprecision(6) << wyniki [3][test] << " ";


            vksztaltny_czas = clock();
            merge_sort (vksztaltny, 0, n-1, POM);
            vksztaltny_czas = (clock() - vksztaltny_czas) / CLOCKS_PER_SEC;
            wyniki[4][test] = vksztaltny_czas;
            cout << fixed << setprecision(6) << wyniki [4][test] << " ";


        }

        else if (test >= 45)
        {
            losowy_czas = clock();
            heap_sort (losowy, n-1);
            losowy_czas = (clock() - losowy_czas) / CLOCKS_PER_SEC;
            wyniki[0][test] = losowy_czas;
            cout << fixed << setprecision(6) << wyniki [0][test] << " ";


            malejacy_czas = clock();
            heap_sort (malejacy, n-1);
            malejacy_czas = (clock() - malejacy_czas) / CLOCKS_PER_SEC;
            wyniki[1][test] = malejacy_czas;
            cout << fixed << setprecision(6) << wyniki [1][test] << " ";


            rosnacy_czas = clock();
            heap_sort (rosnacy, n-1);
            rosnacy_czas = (clock() - rosnacy_czas) / CLOCKS_PER_SEC;
            wyniki[2][test] = rosnacy_czas;
            cout << fixed << setprecision(6) << wyniki [2][test] << " ";


            staly_czas = clock();
            heap_sort (staly, n-1);
            staly_czas = (clock() - staly_czas) / CLOCKS_PER_SEC;
            wyniki[3][test] = staly_czas;
            cout << fixed << setprecision(6) << wyniki [3][test] << " ";


            vksztaltny_czas = clock();
            heap_sort (vksztaltny, n-1);
            vksztaltny_czas = (clock() - vksztaltny_czas) / CLOCKS_PER_SEC;
            wyniki[4][test] = vksztaltny_czas;
            cout << fixed << setprecision(6) << wyniki [4][test] << " ";

        }

        delete [] staly;
        delete [] malejacy;
        delete [] rosnacy;
        delete [] losowy;
        delete [] vksztaltny;
        delete [] POM;
        cout << test << endl;
        test++;
    }

    plik << "INSERTION SORT;1;2;3;4;5;6;7;8;9;10;11;12;13;14;15;" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0) plik << "LOSOWY;";
        if (i == 1) plik << "MALEJACY;";
        if (i == 2) plik << "ROSNACY;";
        if (i == 3) plik << "STALY;";
        if (i == 4) plik << "VKSZTALTNY;";
        for (int j = 0; j < 15; j++)
        {
            plik << fixed << setprecision(6) << wyniki[i][j] << ";";
        }
        plik << endl;
    }

    plik << "SELECTION SORT;1;2;3;4;5;6;7;8;9;10;11;12;13;14;15;" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0) plik << "LOSOWY;";
        if (i == 1) plik << "MALEJACY;";
        if (i == 2) plik << "ROSNACY;";
        if (i == 3) plik << "STALY;";
        if (i == 4) plik << "VKSZTALTNY;";
        for (int j = 15; j < 30; j++)
        {
            plik << fixed << setprecision(6) << wyniki[i][j] << ";";
        }
        plik << endl;
    }

    plik << "MERGE SORT;1;2;3;4;5;6;7;8;9;10;11;12;13;14;15;" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0) plik << "LOSOWY;";
        if (i == 1) plik << "MALEJACY;";
        if (i == 2) plik << "ROSNACY;";
        if (i == 3) plik << "STALY;";
        if (i == 4) plik << "VKSZTALTNY;";
        for (int j = 30; j < 45; j++)
        {
            plik << fixed << setprecision(6) << wyniki[i][j] << ";";
        }
        plik << endl;
    }

    plik << "HEAP SORT;1;2;3;4;5;6;7;8;9;10;11;12;13;14;15;" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0) plik << "LOSOWY;";
        if (i == 1) plik << "MALEJACY;";
        if (i == 2) plik << "ROSNACY;";
        if (i == 3) plik << "STALY;";
        if (i == 4) plik << "VKSZTALTNY;";
        for (int j = 45; j < 60; j++)
        {
            plik << fixed << setprecision(6) << wyniki[i][j] << ";";
        }
        plik << endl;
    }

    plik.close();
    return 0;
}
