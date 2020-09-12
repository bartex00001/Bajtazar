#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, temp;
    std::cin >> n >> m;
    std::vector<int> p, k;
    std::vector<bool> bylo;


    for (int a = 0; a < n; a++)
    {
        std::cin >> temp;
        p.push_back(temp);
        bylo.push_back(false);
    }

    for (int a = 0; a < m; a++)
    {
        std::cin >> temp;
        k.push_back(temp);
    }

    //urealnienie pulek
    int prev = p[0];
    for (int a = 1; a < n; a++)
    {
        if (p[a] >= prev)
            p[a] = prev;
        else
            prev = p[a];
    }

    //for (int a : p)
    //    std::cout << a << " ";
    //std::cout << "\n";

    int l, r;
    int minval = n;
    bool done;
    for (int a = 0; a < m; a++)
    {
        done = false;
        l = 0;      r = minval - 1;
        while (l < r)
        {
            int c = ((l + r) / 2) + 1;
            if (p[c] < k[a])
                r = c - 1;
            else
                l = c;
        }


        minval = l;
        if (minval == 0)
        {
            std::cout << 0;
            return 0;
        }
        //std::cout << k[a] << " -> " << l << "\n";


    }
    std::cout << minval+1;
}
/*
7 3
5 6 4 3 6 2 3
3 2 5

1 1
2
2

10 10
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
*/
