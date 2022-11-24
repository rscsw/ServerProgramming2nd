//#include <Windows.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#define WIDTH 7
//#define HEIGHT 6
//#define FIXED_X 2
//#define FIXED_Y 1
//
//int x = FIXED_X;
//int y = FIXED_Y;
//
//void Draw(const char* s)
//{
//	printf(s);
//}
//
//void DrawBoard(int image[])
//{
//	/* 0 = 색칠하면 안 되는 곳
//	   1 = 색칠해야 하는 곳
//	   2 = 색칠하면 안 되는 곳을 색칠했을 때
//	   3 = 색칠해야 하는 곳을 색칠했을 때 */
//
//	int i = 0;
//	int j = 0;
//	int k = 0;
//
//	for (i = 0; i < WIDTH + 2; i++) Draw("■");
//	Draw("\n");
//	for (i = 0; i < HEIGHT; i++)
//	{
//		Draw("■");
//		for (j = k; j < WIDTH + k; j++)
//		{
//			if (image[i+j] == 2)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				Draw("□");
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//			}
//			else if (image[i+j] == 3)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//				Draw("□");
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//			}
//			else
//			{
//				Draw("□");
//			}
//		}
//		Draw("■\n");
//		k += WIDTH;
//	}
//	for (i = 0; i < WIDTH + 2; i++) Draw("■");
//}
//
//void CursorView()
//{
//	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
//	cursorInfo.dwSize = 1;
//	cursorInfo.bVisible = FALSE;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}
//
//void CursorPosition(short x, short y)
//{
//	COORD position = { x , y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
//	Draw("☆");
//}
//
////void Move(int x, int y)
////{
////	if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
////	{
////		y--;
////		system("cls");
////		DrawBoard();
////	}
////	if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
////	{
////		y++;
////		system("cls");
////		DrawBoard();
////	}
////	if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
////	{
////		x--;
////		system("cls");
////		DrawBoard();
////	}
////	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
////	{
////		x++;
////		system("cls");
////		DrawBoard();
////	}
////
////	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || GetAsyncKeyState(VK_ESCAPE) & 0x8001)
////	{
////		exit(0);
////	}
////}
//
//int main(int argc, char* argv[])
//{
//	CursorView();
//
//	int imageTree[WIDTH * HEIGHT] = {
//		0,0,0,1,0,0,0,
//		0,0,1,1,1,0,0,
//		0,1,1,1,1,1,0,
//		1,1,1,1,1,1,1,
//		0,0,0,1,0,0,0,
//		0,0,0,1,0,0,0,
//	};
//
//	DrawBoard(imageTree);
//
//	while (true)
//	{
//		//Move(x, y);
//		CursorPosition(x, y);
//		if (x > FIXED_X + WIDTH * 2) { x = WIDTH * 2; system("cls"); DrawBoard(imageTree); }
//		if (x < FIXED_X) { x = FIXED_X; system("cls"); DrawBoard(imageTree); }
//		if (y > FIXED_Y + HEIGHT) { y = HEIGHT; system("cls"); DrawBoard(imageTree); }
//		if (y < FIXED_Y) { y = FIXED_Y; system("cls"); DrawBoard(imageTree); }
//
//		if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
//		{
//			y--;
//			system("cls");
//			DrawBoard(imageTree);
//		}
//		if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
//		{
//			y++;
//			system("cls");
//			DrawBoard(imageTree);
//		}
//		if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
//		{
//			x-=2;
//			system("cls");
//			DrawBoard(imageTree);
//		}
//		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
//		{
//			x+=2;
//			system("cls");
//			DrawBoard(imageTree);
//		}
//
//		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || GetAsyncKeyState(VK_ESCAPE) & 0x8001)
//		{
//			DrawBoard(imageTree);
//			CursorPosition(10, 20);
//			exit(0);
//		}
//
//		if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
//		{
//			int xx = (x / 2) - FIXED_X;
//			int yy = y - FIXED_Y;
//			if (imageTree[xx+yy] == 0)
//			{
//				imageTree[xx+yy] = 2;
//			}
//			else if (imageTree[xx+yy] == 1)
//			{
//				imageTree[xx+yy] = 3;
//			}
//			system("cls");
//			DrawBoard(imageTree);
//		}
//	}
//
//	return 0;
//}