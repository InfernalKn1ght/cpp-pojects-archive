#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
int mmas[1][100], nums, rems, x, x1, v;
int a[4][4], b, c;
int ox0, oy0, s0, max = 3, min = 0;
int chaos, chaos0, q, b0, c0;
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
    else
    {
        v = 4;
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
    else
    {
        v = 4;
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
    else
    {
        v = 4;
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
    else
    {
        v = 4;
    }
}
void countchaos()
{
    int priority[15] = { 100000, 10000, 8000, 7000, 1000, 1, 1, 1, 500, 1, 1, 1, 300, 1, 1 }; //constants for numbers
    b = 0;
    c = 0;
    chaos = 0;
    for (b = 0; b <= 3; b++)
    {
        for (c = 0; c <= 3; c++)
        {
            if (a[b][c] != 0)
            {
                q = a[b][c];
                b0 = (q - 1) / 4;
                c0 = (q - 1) % 4;
                b0 = b0 - b;
                c0 = c0 - c;
                chaos0 = (c0 * c0) + (b0 * b0);
                chaos0 = chaos0 * priority[q - 1];
                chaos = chaos + chaos0;
            }
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
void opposite_directions()
{
    if (v == 0)
    {
        godown();
    }
    if (v == 2)
    {
        goup();
    }
    if (v == 1)
    {
        goright();
    }
    if (v == 3)
    {
        goleft();
    }
}
void sistem4()
{
    for (x = 9; x >= 0; x--) //10 sistem to 4 sistem
    {
        rems = x1 % 4;
        mmas[0][x] = rems;
        x1 = x1 / 4;
    }
}
int main()
{
    srand(time(0));
    int q1 = 100000000000000, q2 = 0, randnum, randnum0 = 0, x2;
    x = 1;
    for (b = 0; b <= 3; b++) //0 state 
    {
        for (c = 0; c <= 3; c++)
        {
            a[b][c] = x % 16;
            x++;
        }
    }
    printmass();
    cout << "\n" << "\n";
    for (b = 0; b <= 3; b++) // 0 coordinates
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
    randnum = rand() % 1000000 + 10000;
    while (randnum0 <= randnum) //random shuffle
    {
        v = rand() % 4 + 0;
        directions();
        randnum0++;
    }
    countchaos();
    printmass(); //1 state
    cout << "\n";
    cout << "\n" << "chaos: " << chaos;
    cout << "\n" << "\n";
    for (x2 = 0; x2 <= 20; x2++) //moving to 0 state
    {
        for (nums = 0; nums <= 1048575; nums++) //best 5 steps search
        {
            x1 = nums;
            sistem4();
            for (x = 0; x <= 9; x++) //moves
            {
                v = mmas[0][x];
                directions();
                mmas[0][x] = v;
            }
            countchaos();
            if (chaos < q1) //best moves counter
            {
                q1 = chaos;
                q2 = nums;
            }
            for (x = 9; x >= 0; x--) //moving to 1 state
            {
                v = mmas[0][x];
                opposite_directions();
            }
        }
        x1 = q2;
        sistem4();
        for (x = 0; x <= 9; x++) //best moves
        {
            v = mmas[0][x];
            directions();
        }
        countchaos();
        if (chaos == 0)
        {
            cout << "Solved!" << x2;
            break;
        }
    }
    printmass();
    cout << "\n" << "\n";
    cout << "best chaos: " << q1 << "\n" << "number of cell: " << q2;
}
