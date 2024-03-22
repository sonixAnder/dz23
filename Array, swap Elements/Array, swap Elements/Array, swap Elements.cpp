#include <iostream>
using namespace std;

void swapElements(int* arr, int size)
{
    for (int i = 0; i < size; i += 2)
    {
        int temp = *(arr + i);
        *(arr + i) = *(arr + i + 1);
        *(arr + i + 1) = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Как было: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    swapElements(arr, size);

    cout << "\nКак стало: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
