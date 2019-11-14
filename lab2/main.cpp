#include <algorithm>
#include <QtTest/QtTest>

std::pair<int, int> answer[50000] = { { 1, 1 }, { 1, 2 } };

int array_1[35000];
int array_2[35000];
int pre[100001];
int Ap[20];

int l;
int number_rifle;
int k_rubles;
int current_rubles;

int add(int* a, int* b)
{
    int ret = 0;

    for(int i = 0; i < l; i++){
        b[i] += a[i];

        if(b[i] >= current_rubles){
            b[i] -= current_rubles;
            b[i + 1]++;
            l = std::max(i + 2, l);
        }
        ret += pre[b[i]];
    }

    return ret;
}

void calcpre()
{
    Ap[0] = pre[0] = 0;
    for(int i = 1; i < current_rubles; i++){
        int j = 0;
        pre[i] = pre[i-1];
        Ap[j]++;

        while(true){
            pre[i]++;
            if(Ap[j] >= k_rubles){
                Ap[j] -= k_rubles;
                Ap[j+1]++;
                pre[i] -= k_rubles;
                j++;
            }
            else
                break;
        }
    }
}

int main()
{
    scanf("%d %d", &k_rubles, &number_rifle);

    array_1[0] = 1;
    array_2[0] = 1;

    l = 1;

    int* a = &array_1[0];
    int* b = &array_2[0];

    current_rubles = k_rubles;

    while(current_rubles * k_rubles < 100000){
        current_rubles *= k_rubles;
    }

    calcpre();

    for(int i = 2; i <= number_rifle; i++){
        answer[i].first  = add(a, b);
        answer[i].second = i + 1;

        std::swap(a, b);
    }

    std::sort(answer, answer + number_rifle);

    for(int i = 0; i < number_rifle; i++){
        printf("%d ", answer[i].second);
    }
}
