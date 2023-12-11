#include<iostream>
#include<time.h>

void selectionSort(int*& array, const int size);
void quickSort(int*& array, const int size);

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int SIZE(10);
	int* array = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
		array[i] = rand() % 100;

	for (int i = 0; i < SIZE; ++i)
		std::cout << array[i] << ' ';
	std::cout << std::endl;

	//selectionSort(array, SIZE);
	quickSort(array, SIZE);

	for (int i = 0; i < SIZE; ++i)
		std::cout << array[i] << ' ';
	std::cout << std::endl;

	delete[]array;
	return 0;
}

void selectionSort(int*& array, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIndex(i);
		for (int j = i; j < size; ++j)
			if (array[j] < array[minIndex])
				minIndex = j;
		std::swap(array[i], array[minIndex]);
	}
}

void quickSort(int*& array, const int size)
{
	if (size <= 2)
	{
		if (size <= 1)
			return;
		else if (size == 2)
			if (array[0] <= array[1])
				return;
			else
				std::swap(array[0], array[1]);
	}
	else
	{
		int middle(size / 2);
		int sizeLow(0), sizeHigh(0);
		for (int i = 0; i < size; ++i)
			if (i == middle)
				continue;
			else if (array[i] <= array[middle])
				++sizeLow;
			else
				++sizeHigh;

		int* arrLow = new int[sizeLow];
		int* arrHigh = new int[sizeHigh];

		int countLow(0), countHigh(0);
		for (int i = 0; i < size; ++i)
			if (i == middle)
				continue;
			else if (array[i] <= array[middle])
				arrLow[countLow++] = array[i];
			else
				arrHigh[countHigh++] = array[i];

		quickSort(arrLow, sizeLow);
		quickSort(arrHigh, sizeHigh);

		int count(0), middleValue(array[middle]);
		for (int i = 0; i < sizeLow; ++i, ++count)
			array[count] = arrLow[i];
		array[count++] = middleValue;
		for (int i = 0; i < sizeHigh; ++i,++count)
			array[count] = arrHigh[i];

		delete[]arrLow;
		delete[]arrHigh;
	}
}
