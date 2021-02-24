#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int wordsCounter(string row)
{
	int count = 0;

	int i = 0;
	while (i < row.length())
	{
		while (row[i] == ' ') i++;
		while (row[i] != ' ' && row[i] != '\n' && row[i] != '\0') i++;
		count++;
	}
	return count;
}

int rowCounter(ifstream& file)
{
	string line;
	int count = 0;
	file.clear();
	file.seekg(0);
	while (getline(file, line))
	{
		count++;
	}
	file.clear();
	file.seekg(0);
	return count;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream input("F1.txt");

	int n1, n2, rowCount, lastRowWordsCount;

	if (input.is_open())
	{
		ofstream output("F2.txt");

		rowCount = rowCounter(input);

		if (rowCount < 10)
		{
			cout << "Количество строк в исходном файле должно быть не менее 5!\n";
			cout << "Измените файл и запустите программу снова.";
			output.close();
		}
		else
		{
			cout << "Количество строк в исходном файле: " << rowCount - 4 << endl;

			cout << "Введите число N1 (1-" << rowCount - 4 << "): ";
			cin >> n1;
			while (n1 <= 0 || n1 > rowCount - 4)
			{
				cout << "N1 введено неверно.\n";
				cout << "Введите число N1 (1-" << rowCount << "): ";
				cin >> n1;
			}

			cout << "\nВведите число N2 (" << n1 + 1 << "-" << rowCount - 3 << "): ";
			cin >> n2;
			while (n2 <= 0 || n2 <= n1)
			{
				cout << "N2 введено неверно.\n";
				cout << "\nВведите число N2 (" << n1 + 1 << "-" << rowCount - 3 << "): ";
				cin >> n2;
			}

			int rowNum = 1;
			while (rowNum <= rowCount)
			{
				string row;

				if (rowNum >= n1 && rowNum <= n2)
				{
					getline(input, row);
					if (row[0] == 'А' || row[0] == 'а')
					{
						output << row << endl;
					}
				}
				else if (rowNum >= (n2 + 3) && rowNum <= rowCount)
				{
					getline(input, row);
					output << row << endl;
					if (rowNum == rowCount)
					{
						lastRowWordsCount = wordsCounter(row);
					}
				}
				else getline(input, row);
				rowNum++;
			}
			cout << "\nФайл успешно построен.\n";
			cout << "Количество слов в последней строке: " << lastRowWordsCount;
			output.close();
		}
		
	}
	else cout << "Не удалось открыть файл F1.txt";
	input.close();

	return 0;
}
