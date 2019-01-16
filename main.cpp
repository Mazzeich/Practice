#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class MethDihonometria
{
private:
    double a;
    double b;
    double eps;
    double delt;
    double n;
    double x0;

    void NumbOfOperations()
    {
        n = log2((b - a - delt)/(eps - delt));
        cout << ceil(n) << endl;
        n = ceil(n);
    }

    double CalculFun(double x)
    {
        double f = pow(x - 15, 2) + 5;
        return f;
    }

    void SomeFunc()
    {
        double x1;
        double x2;
        double f1;
        double f2;

        int k = 0;

        for (int i = 0; i < n; i++)
        {
            x0 = (b + a) / 2;
            x1 = x0 - delt;
            x2 = x0 + delt;
            f1 = CalculFun(x1);
            f2 = CalculFun(x2);
            k++;
            if (f1 < f2)
            {
                b = x2;
            } else {
                       a = x1;
                   }
        }

        cout << "k  = " << k << endl;
        cout << "a  = " << a << endl;
        cout << "b  = " << b << endl;
        x0 = (b + a) / 2;
        cout << "f0 = " << CalculFun(x0) << endl;
    }

public:
    MethDihonometria(double a, double b, double eps)
    {
        this->a     = a;
        this->b     = b;
        this->eps   = eps;
        this->delt  = eps/4;
    }

    double Calculate()
    {
        NumbOfOperations();
        SomeFunc();
        return x0;
    }
};


class MethGold
{
private:
    double a;
    double b;
    double eps;
    double delt;
    double n;
    double x0;

    void NumbOfOperations()
    {
        n = log(eps / (b - a)) / log((sqrt(5) - 1) / 2);
        cout << ceil(n) << endl;
        n = ceil(n);
    }

    double CalculFun(double x)
    {
        double f = pow(x - 15, 2) + 5;;
        return f;
    }

    void SomeFunc()
    {
        double x1;
        double x2;
        double f1;
        double f2;

        x1 = b - ((b - a) / ((sqrt(5) + 1)/2));
        cout << "x1 = " << x1 << endl;
        x2 = a + ((b - a) / ((sqrt(5) + 1)/2));
        cout << "x2 = " << x2 << endl;

        f1 = CalculFun(x1);
        f2 = CalculFun(x2);

        if (f1 < f2)
        {
            b = x2;
            cout << "a  = " << a << endl;
            cout << "b  = " << b << endl;
        } else {
                   a = x1;
                   cout << "a  = " << a << endl;
                   cout << "b  = " << b << endl;
               }

        for (int i = 1; i < n; i++)
        {
            x2 = x1;
            x1 = b - ((b - a) / ((sqrt(5) + 1) / 2));
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            f1 = CalculFun(x1);
            f2 = CalculFun(x2);

            if (f1 < f2)
            {
                b = x2;
                cout << "a  = " << a << endl;
                cout << "b  = " << b << endl;
            } else {
                       a = x1;
                       cout << "a  = " << a << endl;
                       cout << "b  = " << b << endl;
                   }
        }

        cout << "a  = "    << a << endl;
        cout << "b  = "    << b << endl;

        x0 = (b + a)/2;
        cout << "f0 = " << CalculFun(x0) << endl;
    }

public:
    MethGold(double a, double b, double eps)
    {
        this->a     = a;
        this->b     = b;
        this->eps   = eps;
        this->delt  = eps/4;
    }

    double Calculate()
    {
        NumbOfOperations();
        SomeFunc();
        return x0;
    }
};




class MethFibbonachi
{
private:
    double a;
    double b;
    double eps;
    double delt;
    double n;
    double x0;

    void NumbOfOperations()
    {
        n = log(eps/(b - a))/log((sqrt(5) - 1)/2);
        cout << ceil(n) << endl;
        n = ceil(n);
    }

    double CalculFun(double x)
    {
        double f = pow(x - 15, 2) + 5;;
        return f;
    }

    double Fib(int num)
    {
        double f1 = 2;
        double f2 = 3;
        double f3 = 5;
        for (int i(0); i < num; i++)
        {
            f1 = f2;
            f2 = f3;
            f3 = f1 + f3;
        }
        return f1;
    }

    void SomeFunc()
    {
        double x1;
        double x2;
        double f1;
        double f2;

        int i = 0;

        while  (n != 0)
        {
            x1 = a + ((b - a) * (Fib(n - 2) / Fib(n)));
            x2 = a + ((b - a) * (Fib(n - 1) / Fib(n)));
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            f1 = CalculFun(x1);
            f2 = CalculFun(x2);
            n--;
            i++;

            if (f1 > f2)
            {
                a  = x1;
                x1 = x2;
                x2 = b - (x1 - a);
                cout << "a  = " << a << endl;
                cout << "b  = " << b << endl;
            } else {
                        b  = x2;
                        x2 = x1;
                        x1 = a + (b - x2);
                        cout << "a  = " << a << endl;
                        cout << "b  = " << b << endl;
                    }
        }

        x0 = (b + a)/2;

        cout << "n  = "  << i             << endl;
        cout << "a  = "  << a             << endl;
        cout << "b  = "  << b             << endl;
        cout << "f0 = "  << CalculFun(x0) << endl;
    }

public:
    MethFibbonachi(double a, double b, double eps)
    {
        this->a     = a;
        this->b     = b;
        this->eps   = eps;
        this->delt  = eps/4;
    }

    double Calculate()
    {
        NumbOfOperations();
        SomeFunc();
        return x0;
    }
};


int main()
{
    MethDihonometria t(2, 200, 0.1);
    cout << t.Calculate() << endl << endl;

    MethGold s(0, 100, 0.1);
    cout << s.Calculate() << endl << endl;

    MethFibbonachi a(0, 100, 0.1);
    cout << a.Calculate() << endl << endl;

    system("Pause");
}
