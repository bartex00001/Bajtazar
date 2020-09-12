#include <iostream>
#include <map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::map<int, int> verts;
	int n, m, temp1, temp2, vertSum = 0;
	
	std::cin >> n >> m;
	for (int a = 0; a < m; a++)
	{
		std::cin >> temp1 >> temp2;
		verts[temp1]++;
		verts[temp2]++;
	}

	for (int a = 1; a <= n; a++)
	{
		vertSum += verts[a] * (n - 1 - verts[a]);
	}
	vertSum /= 2;

	std::cout << (n * (n - 1) * (n - 2)) / 6 - vertSum;
}
/*
6
9
1 2
2 3
2 5
1 4
1 6
3 4
4 5
5 6
3 6

4
3
1 3
4 3
2 3
*/