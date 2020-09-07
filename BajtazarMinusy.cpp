#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<bool> znaki;
    std::string output;
    output.push_back('-');
    
    //get inut
    for (int a = 0; a < n-1; a++)
    {
        char i;
        std::cin >> i;
        if (i == '+')
            znaki.push_back(1);
        else
            znaki.push_back(0);
    }

    int s = n, f = n;
    for (int a = 1; a < n-1; a++)
    {
        if (znaki[a] && !znaki[a-1])
        {
            output.push_back('(');
            output.push_back('-');
        }
        else if (znaki[a - 1] && !znaki[a])
        {
            output.push_back(')');
            output.push_back('-');
        }
        else
            output.push_back('-');
    }
    if (znaki[n - 2])
        output.push_back(')');

    std::cout << output;
}
/*
9
-
+
-
-
+
+
-
+

7
-
-
+
+
-
+
*/