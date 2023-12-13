#include <iostream>
#include <clocale>
/*
 *  Л/р 6 Двумерные массивы
 * Пислегин Евгений Константинович ИВТ - 32
 * Дана матрица размера M × N и целое число K (1 ≤ K ≤ N ).
 * Удалить столбец матрицы с номером K
*/
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int m;
    int n;
    int k;
    cout << "Введите количество строк массива: ";
    cin >> m;
    cout << "Введите количество столбцов массива: ";
    cin >> n;
    cout << "Введите номер столбца: ";
    cin >> k;

    int** a = new int* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 10 - 1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if ((k-1) == j) {
                    for (int strok = 0; strok < m; strok++) {
                        for (int stolb = j; stolb < n; stolb++) {
                            a[strok][stolb] = a[strok][stolb + 1];
                        }
                    }
                    n--;
                    goto next;
            }
        }
    }
next:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++) {
        delete[] a[i];

    }
    delete[] a;
}