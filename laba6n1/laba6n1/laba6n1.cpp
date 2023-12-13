#include <iostream>
#include <clocale>

/*
 *  Л/р 6 Двумерные массивы
 * Пислегин Евгений Константинович ИВТ - 32
 * Дана матрица размера M × N. 
 * Вывести ее элементы в следующем порядке:
 * первый столбец сверху вниз,
 * второй столбец снизу вверх, 
 * третий столбец сверху вниз,
 * четвертый столбец снизу вверх и т. д.
*/


using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int m;
    int n;
    cout << "Введите количество строк массива: ";
    cin >> m;
    cout << "Введите количество столбцов массива: ";
    cin >> n;

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

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j % 2 == 0) {
                cout << a[i][j] << "\t";
            }
            else {
                cout << a[m - i - 1][j] << "\t";
            }
        }
        cout << ("\n");
    }

    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}

