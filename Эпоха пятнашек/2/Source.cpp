#include <iostream>
#include <ctime>
#include <fstream>
//int fifteenMatrix[4][4]; //a
int b, c, ox0, oy0;
const int maxn = 3, minn = 0;
int s0;
int m, p;
//int v;
int q;
int b1, c1;
int c3, c4;
int c4_1, c4_2;
int n;
int c3_1;
int c3_2;

using namespace std;


void printFifteenMatrix(int**& fifteenMatrix) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << fifteenMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void zeroMove(int**& fifteenMatrix, int*& zeroCoordinates, int direction) {
    switch (direction) {
    case 1:
        if (zeroCoordinates[0] > 0) {
            int buf = fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]];
            fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]] = fifteenMatrix[zeroCoordinates[0] - 1][zeroCoordinates[1]];
            fifteenMatrix[zeroCoordinates[0] - 1][zeroCoordinates[1]] = buf;
            zeroCoordinates[0] = zeroCoordinates[0] - 1;
        }
        break;
    case 2:
        if (zeroCoordinates[1] > 0) {
            int buf = fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]];
            fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]] = fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1] - 1];
            fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1] - 1] = buf;
            zeroCoordinates[1] -= 1;
        }
        break;
    case 3:
        if (zeroCoordinates[0] < 3) {
            int buf = fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]];
            fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]] = fifteenMatrix[zeroCoordinates[0] + 1][zeroCoordinates[1]];
            fifteenMatrix[zeroCoordinates[0] + 1][zeroCoordinates[1]] = buf;
            zeroCoordinates[0] += 1;
        }
        break;
    case 4:
        if (zeroCoordinates[1] < 3) {
            int buf = fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]];
            fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1]] = fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1] + 1];
            fifteenMatrix[zeroCoordinates[0]][zeroCoordinates[1] + 1] = buf;
            zeroCoordinates[1] += 1;
        }
        break;
    }

}

//void goup()
//{
//    if (oy0 > minn)
//    {
//        s0 = a[oy0][ox0];
//        a[oy0][ox0] = a[oy0 - 1][ox0];
//        a[oy0 - 1][ox0] = s0;
//    }
//    else
//    {
//        v = 4;
//    }
//}
//void goleft()
//{
//    if (ox0 > minn)
//    {
//        s0 = a[oy0][ox0];
//        a[oy0][ox0] = a[oy0][ox0 - 1];
//        a[oy0][ox0 - 1] = s0;
//    }
//    else
//    {
//        v = 4;
//    }
//}
//void godown()
//{
//    if (oy0 < maxn)
//    {
//        s0 = a[oy0][ox0];
//        a[oy0][ox0] = a[oy0 + 1][ox0];
//        a[oy0 + 1][ox0] = s0;
//    }
//    else
//    {
//        v = 4;
//    }
//}
//void goright()
//{
//    if (ox0 < maxn)
//    {
//        s0 = a[oy0][ox0];
//        a[oy0][ox0] = a[oy0][ox0 + 1];
//        a[oy0][ox0 + 1] = s0;
//    }
//    else
//    {
//        v = 4;
//    }
//}
//void countm()
//{
//    m = 1;
//    p = 0;
//    for (b = 0; b <= 3; b++)
//    {
//        for (c = 0; c <= 3; c++)
//        {
//            if (a[b][c] == m % 16)
//                p++;
//            m++;
//        }
//    }
//}
//void countm1()
//{
//    m = 1;
//    p = 0;
//    for (b = 0; b <= 3; b++)
//    {
//        for (c = 0; c <= 3; c++)
//        {
//            if (a[b][c] == m)
//                p++;
//            m++;
//        }
//    }
//}
//void directions()
//{
//    if (v == 0)
//    {
//        goup();
//    }
//    if (v == 1)
//    {
//        goleft();
//    }
//    if (v == 2)
//    {
//        godown();
//    }
//    if (v == 3)
//    {
//        goright();
//    }
//}

int distanceValue(int**& fifteenMatrix) {
    int value = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (fifteenMatrix[i][j] != 0) {
                value += pow((fifteenMatrix[i][j] - 1) / 4 - i, 2) + pow((fifteenMatrix[i][j] - 1) % 4 - j, 2);
            }
        }
    }
    return value;
}

void shuffle(int**& fifteenMatrix, int*& zeroCoordinates) {
    srand(time(0));
    int value = rand() % 100000 + 500000;
    for (int i = 0; i < value; ++i) {
        int move = rand() % 4 + 0;
        zeroMove(fifteenMatrix, zeroCoordinates, move);
    }
}

//void countm2()
//{
//    b = 0;
//    c = 0;
//    c4 = 0;
//    for (b = 0; b <= 3; b++)
//    {
//        for (c = 0; c <= 3; c++)
//        {
//            if (a[b][c] != 0)
//            {
//                q = a[b][c];
//                b1 = (q - 1) / 4;
//                c1 = (q - 1) % 4;
//                b1 = b1 - b;
//                c1 = c1 - c;
//                c3 = (c1 * c1) + (b1 * b1);
//                c4 = c4 + c3;
//            }
//        }
//    }
//}
int main() {
    int** fifteenMatrix = new int* [4];
    int* zeroCoordinates = new int[2];

    zeroCoordinates[0] = 3;
    zeroCoordinates[1] = 3;

    for (int i = 0; i < 4; ++i) {
        fifteenMatrix[i] = new int[4];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            fifteenMatrix[i][j] = (4 * i + (j + 1)) % 16;
        }
    }
    
    printFifteenMatrix(fifteenMatrix);
    shuffle(fifteenMatrix, zeroCoordinates);
    printFifteenMatrix(fifteenMatrix);
    

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
        zero();
        h++;
    }
    countm2();
    printmass();
    cout << "\n" << "\n";
    countm();
    cout << "p=" << p;
    cout << "\n" << "\n";
    cout << "\n" << "c4=" << c4;
    /*while (nr < 10000000)
    {
        countm1();
        p2 = p;
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
        countm1();
        p1 = p;
        if ((p2 - p1) > 0)
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
        nr++;
    }
    while (nr < 10000000)
    {
        countm2();
        c4_2 = c4;
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
        countm2();
        c4_1 = c4;
        if ((c4_1 - c4_2) > 0)
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
        nr++;
    }*/
    int zx[30];
    int zxx;
    int v1;
    while (nr < 1000000)
    {
        zero();
        /* cout << "\n";
         cout << "intro:";
         printmass();
         cout << "\n";
         countm2();
         cout << "c4=" << c4;
         cout << "\n";
         cout << "mass:";
         for (b = 0; b <= 5; b++)
         {
             cout << zx[b];
         }
         cout << "\n" << "\n";*/
        countm2();
        c4_2 = c4;
        for (zxx = 0; zxx <= 29; zxx++)
        {
            zero();
            v = rand() % 4 + 0;
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
            zx[zxx] = v;
        }
        zero();
        countm2();
        c4_1 = c4;
        /*cout << "before:";
        printmass();
        cout << "\n";
        cout << "c4=" << c4;
        cout << "\n";
        cout << "mass:";
        for (b = 0; b <= 4; b++)
        {
            cout << zx[b];
        }
        cout << "\n" << "\n";*/
        if ((c4_1 - c4_2) > 0)
        {
            for (zxx = 29; zxx >= 0; zxx--)
            {
                v1 = zx[zxx];
                if (v1 == 0)
                {
                    godown();
                }
                if (v1 == 2)
                {
                    goup();
                }
                if (v1 == 1)
                {
                    goright();
                }
                if (v1 == 3)
                {
                    goleft();
                }
                //cout << "v1:" << v1 << " ";
                zero();
            }
        }
        /*cout << "\n" << "\n";
         cout << "after:";
         countm2();
         printmass();
         cout << "\n";
         cout << "c4=" << c4;
         cout << "\n";
         cout << "mass:";
         for (b = 0; b <= 4; b++)
         {
             cout << zx[b];
         }
         cout << "\n";*/
        nr++;
    }
    /*while (nr < 10000)
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
    }*/

    printmass();
    cout << "\n" << "\n";
    countm();
    countm2();
    cout << "\n" << "\n";
    printmass();
    cout << "\n" << "\n";
    cout << "p=" << p;
    cout << "\n" << "\n";
    cout << "c4=" << c4;


}