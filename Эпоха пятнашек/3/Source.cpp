#include <iostream>
#include <ctime>
#include <fstream>
int a[4][4];
int b, c, ox0, oy0;
int max = 3, min = 0;
int s0;
int m, p;
int v;
int q;
int b1, c1;
int c3, c4;
int c4_1, c4_2;
int n;
int c3_1;
int c3_2;
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
    if (oy0 > min)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0 - 1][ox0];
        a[oy0 - 1][ox0] = s0;
        oy0--;
    }
}
void goleft()
{
    if (ox0 > min)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0][ox0 - 1];
        a[oy0][ox0 - 1] = s0;
        ox0--;
    }
}
void godown()
{
    if (oy0 < max)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0 + 1][ox0];
        a[oy0 + 1][ox0] = s0;
        oy0++;
    }
}
void goright()
{
    if (ox0 < max)
    {
        s0 = a[oy0][ox0];
        a[oy0][ox0] = a[oy0][ox0 + 1];
        a[oy0][ox0 + 1] = s0;
        ox0++;
    }
}
void countm()
{
    m = 1;
    p = 0;
    for (b = 0; b <= 3; b++)
    {
        for (c = 0; c <= 3; c++)
        {
            if (a[b][c] == m % 16)
                p++;
            m++;
        }
    }
}
void countm1()
{
    m = 1;
    p = 0;
    for (b = 0; b <= 3; b++)
    {
        for (c = 0; c <= 3; c++)
        {
            if (a[b][c] == m)
                p++;
            m++;
        }
    }
}
void directions()
{
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
}
void countm2()
{
    b = 0;
    c = 0;
    c4 = 0;
    for (b = 0; b <= 3; b++)
    {
        for (c = 0; c <= 3; c++)
        {
            if (a[b][c] != 0)
            {
                q = a[b][c];
                b1 = (q - 1) / 4;
                c1 = (q - 1) % 4;
                b1 = b1 - b;
                c1 = c1 - c;
                c3 = (c1 * c1) + (b1 * b1);
                c4 = c4 + c3;
            }
        }
    }
}
void file()
{
    ofstream fout;
    fout.open("Vcount.txt");
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        fout << v << " ";
        fout.close();
    }
}
int main()
{
    srand(time(0));
    int p1;
    int nr = 0;
    int x0;
    int y0;
    int k;
    int h = 0;
    int hr;
    k = 1;
    int p2;
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
    countm();
    cout << p;
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
    countm2();
    printmass();
    cout << "\n" << "\n";
    countm();
    cout << "p=" << p;
    cout << "\n" << "\n";
    cout << "\n" << "c4=" << c4;
    while (nr < 10000)
    {
        for (b = 0; b <= 3; b++)
        {
            for (c = 0; c <= 3; c++)
            {
                if (a[b][c] == 1)
                {
                    q = a[b][c];
                    b1 = (q - 1) / 4;
                    c1 = (q - 1) % 4;
                    b1 = b1 - b;
                    c1 = c1 - c;
                    c3 = (c1 * c1) + (b1 * b1);
                }
            }
        }
        c3_2 = c3;
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
        while (nr < 1000)
        {
            for (b = 0; b <= 3; b++)
            {
                for (c = 0; c <= 3; c++)
                {
                    if (a[b][c] == 1)
                    {
                        q = a[b][c];
                        b1 = (q - 1) / 4;
                        c1 = (q - 1) % 4;
                        b1 = b1 - b;
                        c1 = c1 - c;
                        c3 = (c1 * c1) + (b1 * b1);
                    }
                }
            }
        }
        c3_1 = c3;
        if ((c3_1 - c3_2) > 0)
        {
            if (v == 0)
                godown();
            if (v == 2)
                goup();
            if (v == 1)
                goright();
            if (v == 3)
                goleft;
        }
        cout << c3;
        nr++;
    }
    countm();
    countm2();
    cout << "\n" << "\n";
    printmass();
    cout << "\n" << "\n";
    cout << "p=" << p;
    cout << "\n" << "\n";
    cout << "c4=" << c4;
}