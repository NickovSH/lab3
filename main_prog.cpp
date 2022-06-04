#include <iostream>

using namespace std;

// Финкция ассемблера для удаления строки и слобца
extern "C" int proc(int* ptr_matrix, int* ptr_newMatrix, 
        int N, int M,
        int row, int column);


// Функция отображения матрицы
void show (int *matrix, int N, int M)
{
    // Проход по каждой строке
    for (int i = 0; i < N; i++)
    {
        // Проход по каждому столбцу
        for (int j = 0; j < M; j++)
            // Вывод элемента
            cout << matrix[i*M + j] << " ";
        // Новая строка, чтоб элементы не были в одну строку
        cout << endl;
    }
    cout << endl;
}


int main()
{
    // Для рандомных значений
    srand(time(0));

    // Размерность изначальной матрицы
    const int N = 5;
    const int M = 4;
    // Главная матрица
    int matrix[N][M];
    // Указатель на перый элемент матрицы
    int* ptr_matrix = &matrix[0][0];

    // Генерация матрицы
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            // Генерация значений от 0 до 99
            matrix[i][j] = rand() % 100;

    // Вывод полученной матрицы
    show(ptr_matrix, N, M);

    // Создание новой матрицы, которая на 1 меньше с каждой стороны
    int newArray[N-1][M-1];

    // Строка и столбец, которые будем удалять
    int row, column;
    // Ввод номера удаляемой строки до тех пор, пока не введется норм знач.
    while (true)
    {
        cout << "Enter row: ";
        cin >> row;

        // Проверка введенного значения на правильность
        if (row < 1 || row > N)
            cout << "Error enter row \n\n";
        // Если правильно, то выходим из цикла
        else 
            break;
    }
    // Уменьшаем на 1, так как отчет в массивах нач. с 0
    row--;

    // Аналогично для стоблца
    while (true)
    {
        cout << "Enter column: ";
        cin >> column;

        if (column < 1 || column > M)
            cout << "Error enter row \n\n";
        else
            break;
    }
    column--;

    cout << endl;

    // Указатель на первый элемент новой матрицы
    int* ptr_newMatrix = &newArray[0][0];

    // Создание новой матрицы
    proc(ptr_matrix, ptr_newMatrix, N, M, row, column);
    
    // Отображение новой матрицы
    show(ptr_newMatrix, N - 1, M - 1);

    return 0;
}
