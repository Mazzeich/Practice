#include <iostream>

int factorial(int j)
{
    if (j == 0) return 1;
    else return j * factorial(j - 1);
}

int main()
{
    int i;

    std::cin >> i;
    std::cout << factorial(i) << "\n";
    return 0;
}
