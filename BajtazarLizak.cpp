#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <bits/stdc++.h>

std::map<int, std::pair<int, int> > przedzial;
std::vector<bool> smak;

//iteracja zmniejszajac lizkak O(k)
// jezeli k >= 3 to morzemy wyznaczyc przedzial o k - 2
void Zmniejsz(int l, int r, int k)
{
    while(true)
    {
        przedzial[k] = { l + 1, r + 1};
        if(k < 3)
            break;
            
        if (smak[l])  
        {
            l++;
            k -= 2;
        }
        else if (smak[r]) 
        {
            r--;
            k -= 2;
        }
        else
        {
            l++;
            r--;
            k -= 2;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::pair<int, int> nil = { 0, 0 };//{-2, -2};
    int n, m, suma = 0, l, r, k;
    std::cin >> n >> m;
    char v;

    for (int a = 0; a < n; a++)
    {
        std::cin >> v;

        if (v == 'W')
            smak.push_back(false);
        else
            smak.push_back(true);
    }


    //oblicz sumę  O(n)
    for (int a = 0; a < n; a++)
    {
        if (smak[a])  suma += 2;
        else  suma += 1;
    }

    ////wypełnij mapę nil O(n)
    //for (int a = 0; a <= suma; a++)
    //    przedzial[a] = nil;

    //dla pierwszej parzystosci
    Zmniejsz(0, n - 1, suma);
    l = -1; r = -1;
    
    //znajdz jedynki O(n)
    for (int a = 0; a < n; a++)
    {
        if (!smak[a]) 
        {
            if(l == -1)
                l = a;

            r = a;
        }
    }
    //std::cout << "l: " << l << " r: " << r << "\n";

    if (r != -1)
    {
        if (n - (r + 1) <= l)
            Zmniejsz(0, r - 1, suma - 2 * (n - (r + 1)) - 1);
        else
            Zmniejsz(l + 1, n - 1, suma - 2 * (l)-1);
    }

    //wypisz wyniki O(m)
    for (int a = 0; a < m; a++)
    {
        std::cin >> k;
        
        if (k > suma)
            printf("%s", "NIE\n");
        else if (przedzial[k] == nil && k >= 3)
            printf("%s", "NIE\n");
        else
            printf("%i%s%i%s", przedzial[k].first, " ", przedzial[k].second, "\n");
    }
    /*
    for (int a = 1; a <= suma; a++)
    {
        std::cout << a << ": " << przedzial[a].first << " " << przedzial[a].second << "\n";
    }
    */
}
/*
5 3
TWTWT


5 0
TWWWW

5 0
WWWWT
*/