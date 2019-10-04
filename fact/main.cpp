#include <iostream>

int factorial(int n)
{
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

int main()
{
    int n;

    std::cin >> n;

    std::cout << factorial(n) << "\n";

    return 0;
}
