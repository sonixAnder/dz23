#include<iostream>
using namespace std;

void createThirdArray(int* A, int n, int* B, int m)
{
    int totalSize = n + m;
    int* thirdArray = new int[totalSize];
    int index = 0;

    // Элементы обоих массивов
    for (int i = 0; i < n; i++)
    {
        thirdArray[index] = A[i];
        index++;
    }

    for (int i = 0; i < m; i++)
    {
        thirdArray[index] = B[i];
        index++;
    }

    // Общие элементы двух массивов
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j])
            {
                thirdArray[index] = A[i];
                index++;
                break;
            }
        }
    }

    // Элементы массива A, которые не включаются в B
    for (int i = 0; i < n; i++)
    {
        bool isInB = false;
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j])
            {
                isInB = true;
                break;
            }
        }
        if (!isInB)
        {
            thirdArray[index] = A[i];
            index++;
        }
    }

    // Элементы массива B, которые не включаются в A
    for (int i = 0; i < m; i++)
    {
        bool isInA = false;
        for (int j = 0; j < n; j++)
        {
            if (B[i] == A[j])
            {
                isInA = true;
                break;
            }
        }
        if (!isInA)
        {
            thirdArray[index] = B[i];
            index++;
        }
    }

    // Элементы массивов A и B, которые не являются общими для них
    for (int i = 0; i < n; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            thirdArray[index] = A[i];
            index++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < n; j++)
        {
            if (B[i] == A[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            thirdArray[index] = B[i];
            index++;
        }
    }

    // Вывод третьего массива
    for (int i = 0; i < index; i++)
    {
        cout << thirdArray[i] << " ";
    }
    cout << endl;


}

int main()
{
    int A[] = { 1, 2, 3, 4, 5 };
    int B[] = { 3, 4, 5, 6, 7 };

    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    createThirdArray(A, n, B, m);

    return 0;
}