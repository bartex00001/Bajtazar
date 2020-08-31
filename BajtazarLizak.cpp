#include <iostream>
#include <map>

std::map<int, std::pair<int, int> > przedzial;
std::string smak;

//rekurencyjna kalkulacja wyników O(k)
void Spamientaj(int l, int r, int k)
{
    przedzial[k] = { l + 1, r + 1 };
    //std::cout << k << "\n";

    if (k >= 3)
    {
        if (smak[l] == 'T')  Spamientaj(l + 1, r, k - 2);
        else if (smak[r] == 'T') Spamientaj(l, r - 1, k - 2);
        else  Spamientaj(l + 1, r - 1, k - 2);
    }
}

int main()
{
    std::pair<int, int> nil = { 0, 0 };//{-2, -2};
    int n, m, suma = 0, l, r, k;
    std::cin >> n >> m >> smak;


    //oblicz sumê  O(n)
    for (int a = 0; a < n; a++)
    {
        if (smak[a] == 'W')  suma += 1;
        else  suma += 2;
    }

    ////wype³nij mapê nil O(n)
    //for (int a = 0; a <= suma; a++)
    //    przedzial[a] = nil;

    //dla pierwszej parzystosci
    Spamientaj(0, n - 1, suma);
    l = -1; r = -1;
    
    //znajdz jedynki O(n)
    for (int a = 0; a < n; a++)
    {
        if (smak[a] == 'W') 
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
            Spamientaj(0, r - 1, suma - 2 * (n - (r + 1)) - 1);
        else
            Spamientaj(l + 1, n - 1, suma - 2 * (l)-1);
    }

    //wypisz wyniki O(m)
    for (int a = 0; a < m; a++)
    {
        std::cin >> k;
        if (k > suma)
            std::cout << "NIE\n";
        else if (przedzial[k] == nil && k >= 3)
            std::cout << "NIE\n";
        else  
            std::cout << przedzial[k].first << " " << przedzial[k].second << "\n";
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