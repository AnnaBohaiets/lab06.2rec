#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* Create(int n, const int Low, const int High, int* a = 0, int i = 0)
{
    if (a == 0)
    {
        a = new int[n];
    }

    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(n, Low, High, a, i + 1);
    }
    return a;
}

void Print(int* a, int n, int i = 0) {
    if (i < n) {
        cout << setw(5) << a[i];
        Print(a, n, i + 1);
    }
    else {
        cout << endl;
    }
}


int Number(int* a, const int size, int i = 0)
{
    if (i >= size)
    {
        return 0;
    }
    int count = Number(a, size, i + 1);
    if ((a[i] % 2 != 0))
    {
        count++;
    }

    return count;

}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cin >> n;
    const int Low = -100;
    const int High = 100;

    int* a = Create(n, Low, High);
    Print(a, n);

    int count = Number(a, n);
    cout << "Number of odd elements  is " << count << endl;
    delete[] a; // Звільнення пам'яті

    return 0;
}
