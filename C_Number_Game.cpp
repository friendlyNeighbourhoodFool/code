#include <bits/stdc++.h>
int i, m, n, p, t;
int main()
{
    for (std::cin >> t; t--;)
    {
        for (std::cin >> n, i = m = 1; ~n & 1; m *= 2)
            n /= 2;
        for (p = 0; ++i * i <= n;)
            n % i ?: p = 1;
        std::cout << (m<2 & n> 1 | m > 1 & (m < 4 & n<2 | n> 1 & (p || m ^ 2)) ? "Ashishgup" : "FastestFinger") << '\n';
    }
}