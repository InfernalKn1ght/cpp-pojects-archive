#include <iostream>
#include <ctime>
int a[4][4];
int b, c, ox0, oy0;
int maxn = 3, minn = 0;
int s0;
using namespace std;
void printmass()
{
    for (b = 0; b <= 3; b++)
    {
        cout << "\n";
        for (c = 0; c <= 3; c++)
        {
            cout << a[b][c] << " ";
        }
    }
}
void goup()
{
    if (oy0 > minn)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0 - 1][ox0];
        a[oy0 - 1][ox0] = s0;
        oy0--;
    }
}
void goleft()
{
    if (ox0 > minn)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0][ox0 - 1];
        a[oy0][ox0 - 1] = s0;
        ox0--;
    }
}
void godown()
{
    if (oy0 < maxn)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0 + 1][ox0];
        a[oy0 + 1][ox0] = s0;
        oy0++;
    }
}
void goright()
{
    if (ox0 < maxn)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0][ox0 + 1];
        a[oy0][ox0 + 1] = s0;
        ox0++;
    }
}
int main()
{
    srand(time(0));
    int x0;
    int b1;
    int c1;
    int y0;
    int n;
    int m;
    int k;
    string t;
    int h = 0;
    int hr;
    k = 1;
    for (b = 0; b <= 3; b++)
    {
        for (c = 0; c <= 3; c++)
        {
            a[b][c] = k % 16;
            k++;
        }
    }
    printmass();
    cout << "\n" << "\n";
    for (b = 0; b <= 3; b++)
    {
        for (c = 0; c <= 3; c++)
        {
            if (a[b][c] == 0)
            {
                ox0 = c;
                oy0 = b;
            }
        }
    }
    cout << "0 coordinates" << "\n" << "x:" << ox0 << "\n" << "y:" << oy0;
    cout << "\n" << "\n";
    hr = rand() % 1000000 + 10000;
    int l = 1;
    int l1 = 1;
    int l2 = 1;
    int l3 = 1;
    int max = 3;
    int min = 0;
    while (h <= hr)
    {
        int v = rand() % 4 + 0;
        if (v == 0)
        {
            goup();
        }
        if (v == 1)
        {
            goleft();
        }
        if (v == 2)
        {
            godown();
        }
        if (v == 3)
        {
            goright();
        }
        h++;
    }
    printmass();
    cout << "\n" << "\n";
    n = 0;
    while (n == 0)
    {
        cin >> t;
        if (t == "w")
        {
            goup();
        }
        if (t == "a")
        {
            goleft();
        }
        if (t == "s")
        {
            godown();
        }
        if (t == "d")
        {
            goright();
        }
        if (t == "q")
            break;
        printmass();
        cout << "\n" << "\n";
        //Определение победы
        m = 1;
        for (b = 0; b <= 3; b++)
        {
            for (c = 0; c <= 3; c++)
            {
                if (a[b][c] == m % 16)
                    m++;
            }
        }
        if (m == 17)
        {
            cout << "Victory!";
            break;
        }
    }
}