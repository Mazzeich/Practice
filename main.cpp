#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    
    std::cout << fact(N) << '\n';
    
    return 0;
}

long int fact(int n)
{
    if(N < 0)
    {
        return 0;
    }
    
    if(N == 0)
    {
        return 1;
    } else {
              return N*fact(N-1);
           }
}
