#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Bigger(int a, int b){ 
	int max;
	if (a < b) { max = b; }
	else { max = a; }
	return max;
}
int LBlock(int start, int n) {
	if (start < 0) { start = 0; }//ограничение поиска слева
	return start;
}
int RBlock(int end, int n) {
	if (end > n) { end = n; }//ограничение поиска справа
	return end;
}
int** makeMatrix(int n) {
	int **A = new int*[n];
	for (int c = 0; c < n; c++) {
		A[c] = new int[n];
	}
	return A ;
}
void initialize(int** A, int n)// Функция заполнения
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 100;
		}
	}
}
void BfromA(int **A,int **B,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int Max = A[i][j]; //переменная содержащая максимальное значение для элемента
			int k, start, end;

			//проход поиска элементов по высоте
			for (int h = (i + 1); h < n; h++) {
				k = h - i;//каофицент показывающий размер обхвата поиска в рядке
				start = j - k;//элемент рядка с которого начинается поиск
				end = j + k + 1;//элемент рядка на котором заканчивается поиск

			   //чтобы поиск не выходил за пределы матрицы
				start = LBlock(start, n);
				end = RBlock(end, n);

				//перебор элементов строки

				for (int w = start; w < end; w++) {
					Max = Bigger(Max, A[h][w]);

				}
			}
			B[i][j] = Max;//передача максимального значения элементу
		}
	}
}
int** outMatrix(int **A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "\t" << "\n";
	}
	return 0;
}

int main() {

	int n; cout << "n: "; cin >> n;//введение размерности матрицы
	int **A = makeMatrix(n);
	int **B = makeMatrix(n);
	initialize(A, n);
	BfromA(A, B, n);
	
	cout << "A:\n";
	outMatrix(A, n);

	cout << "B:\n";
	outMatrix(B, n);

	system("pause");
	return 0;
}