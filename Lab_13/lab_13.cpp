#include <iostream>
using namespace std;

int board[8][8];

void ShowBoard()
{
	cout << "---------------------------------\n";
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j] == -1) cout << "| Q ";
			else cout << "|   ";
		}
		cout << "|\n---------------------------------\n";
	}
}

void SetQueen(int x, int y)
{
	for (int i = 0; i < 8; ++i)
	{
		++board[i][y];
		++board[x][i];
		int diag = y - x + i;
		if (diag >= 0 && diag < 8) ++board[i][diag];
		diag = y + x - i;
		if (diag >= 0 && diag < 8) ++board[i][diag];
		board[x][y] = -1;
	}
}

void Reset(int x, int y)
{
	for (int i = 0; i < 8; ++i)
	{
		--board[i][y];
		--board[x][i];
		int diag = y - x + i;
		if (diag >= 0 && diag < 8) --board[i][diag];
		diag = y + x - i;
		if (diag >= 0 && diag < 8) --board[i][diag];
		board[x][y] = 0;
	}
}

bool TryQueen(int i)
{
	bool res = false;
	for (int j = 0; j < 8 && !res; ++j)
	{
		if (board[i][j] == 0)
		{
			SetQueen(i, j);
			if (i == 7) res = !res;
			else if (!(res = TryQueen(i + 1))) Reset(i, j);
		}
	}
	return res;
}

int main()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) board[i][j] = 0;
	TryQueen(0);
	ShowBoard();
}
