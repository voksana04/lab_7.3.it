#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int CountRowsWithoutZero(int** a, const int rowCount, const int colCount);
void FindMaxRepeated(int** a, const int rowCount, const int colCount, int& maxRepeated);

int main()
{
    int Low = -10;
    int High = 10;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Create(a, rowCount, colCount, Low, High);
    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int count = CountRowsWithoutZero(a, rowCount, colCount);
    cout << "Кількість рядків без нульових елементів: " << count << endl;

    int maxRepeated;
    FindMaxRepeated(a, rowCount, colCount, maxRepeated);
    cout << "Максимальне число, що зустрічається більше одного разу: " << maxRepeated << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << "Матриця:" << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int CountRowsWithoutZero(int** a, const int rowCount, const int colCount)
{
    int count = 0;
    for (int i = 0; i < rowCount; i++)
    {
        bool hasZero = false;
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] == 0)
            {
                hasZero = true;
                break;
            }
        }
        if (!hasZero)
            count++;
    }
    return count;
}

void FindMaxRepeated(int** a, const int rowCount, const int colCount, int& maxRepeated)
{
    int max = INT_MIN;
    bool found = false;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            int current = a[i][j];
            int count = 0;
            for (int k = 0; k < rowCount; k++)
            {
                for (int l = 0; l < colCount; l++)
                {
                    if (a[k][l] == current)
                        count++;
                }
            }
            if (count > 1 && current > max)
            {
                max = current;
                found = true;
            }
        }
    }

    if (found)
        maxRepeated = max;
    else
        cout << "Немає чисел, що зустрічаються більше одного разу." << endl;
}