#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 7
#define HEIGHT 6
#define FIXED_X 2
#define FIXED_Y 1

int x = FIXED_X;
int y = FIXED_Y;

void Draw(const char* s)
{
	printf(s);
}

void DrawBoard()
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < WIDTH + 2; i++) Draw("бс");
	Draw("\n");
	for (i = 0; i < HEIGHT; i++)
	{
		Draw("бс");
		for (j = k; j < k + WIDTH; j++)
		{
			Draw("бр");
		}
		Draw("бс\n");
		k += WIDTH;
	}
	for (i = 0; i < WIDTH + 2; i++) Draw("бс");
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void CursorPosition(short x, short y)
{
	COORD position = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	Draw("б┘");
}

void Move(int x, int y)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
	{
		y--;
		system("cls");
		DrawBoard();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		y++;
		system("cls");
		DrawBoard();
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		x--;
		system("cls");
		DrawBoard();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		x++;
		system("cls");
		DrawBoard();
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || GetAsyncKeyState(VK_ESCAPE) & 0x8001)
	{
		exit(0);
	}
}

int main(int argc, char* argv[])
{
	CursorView();

	int Image[WIDTH * HEIGHT] = {
		0,0,0,1,0,0,0,
		0,0,1,1,1,0,0,
		0,1,1,1,1,1,0,
		1,1,1,1,1,1,1,
		0,0,0,1,0,0,0,
		0,0,0,1,0,0,0,
	};

	DrawBoard();

	while (true)
	{
		//Move(x, y);
		CursorPosition(x, y);
		if (x > FIXED_X + WIDTH * 2) { system("cls"); DrawBoard(); x = WIDTH * 2; }
		if (x < FIXED_X) { system("cls"); DrawBoard(); x = FIXED_X; }
		if (y > FIXED_Y + HEIGHT) { system("cls"); DrawBoard(); y = HEIGHT; }
		if (y < FIXED_Y) { system("cls"); DrawBoard(); y = FIXED_Y; }

		if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
		{
			y--;
			system("cls");
			DrawBoard();
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			y++;
			system("cls");
			DrawBoard();
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
		{
			x-=2;
			system("cls");
			DrawBoard();
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
		{
			x+=2;
			system("cls");
			DrawBoard();
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{
			CursorPosition(10, 20);
			exit(0);
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
		{
			int ix = (x - FIXED_X) / 2;
			int iy = y - FIXED_Y;
			if (Image[ix + iy - 1] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				Draw("бс");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				Draw("бс");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
		}
	}

	return 0;
}