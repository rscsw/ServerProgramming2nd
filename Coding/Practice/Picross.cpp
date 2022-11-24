#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define WIDTH 7
#define HEIGHT 6

vector<int> wv[HEIGHT];
vector<int> hv[WIDTH];

bool isGameRunning = true;
bool done = false;

int widthMax = 0;
int heightMax = 0;

int FIXED_X = 0;
int FIXED_Y = 0;

int x = 0;
int y = 0;

int heart = 3;

bool checkMode = false;

// 0 = 칠하면 안 되는 곳
// 1 = 칠해야 하는 곳
// 2 = 칠하면 안 되는 곳을 칠했을 때
// 3 = 칠해야 하는 곳을 칠했을 때
// 4 = 0 체크 마크
// 5 = 1 체크 마크

int imageTree[WIDTH * HEIGHT] = {
	0,1,0,1,0,1,0,
	0,0,1,1,1,0,0,
	0,1,1,1,1,1,0,
	1,1,1,1,1,1,1,
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0
};

void CursorPosition(short x, short y)
{
	COORD position = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

//가로 배열
void GetWidthVector(int width, int height, int image[], vector<int> widthVector[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	for (j = 0; j < width * height; j++)
	{
		i++;
		if (image[j] == 1) count++;
		else
		{
			if (count != 0)
			{
				widthVector[k].push_back(count);
				count = 0;
			}
		}
		if (i % width == 0)
		{
			if (count != 0)
			{
				widthVector[k].push_back(count);
			}
			k++;
			count = 0;
		}
	}
}

//가로값
int GetWidthMax(int height, vector<int> widthVector[])
{
	int i = 0;
	int j = 0;
	int widthMax = 0;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < widthVector[i].size(); j++)
		{
			if (widthMax < widthVector[i].size()) widthMax = widthVector[i].size() * 2 - 1;
		}
	}

	return widthMax;
}

//세로 배열
void GetHeightVector(int width, int height, int image[], vector<int> heightVector[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			if (image[j * width + i] == 1) count++;
			else
			{
				if (count != 0)
				{
					heightVector[k].push_back(count);
					count = 0;
				}
			}
		}
		if (count != 0)
		{
			heightVector[k].push_back(count);
		}
		k++;
		count = 0;
	}
}

//세로값
int GetHeightMax(int width, vector<int> heightVector[])
{
	int i = 0;
	int j = 0;
	int heightMax = 0;

	for (i = 0; i < width; i++)
	{
		for (j = 0; j < heightVector[i].size(); j++)
		{
			if (heightMax < heightVector[i].size()) heightMax = heightVector[i].size();
		}
	}

	return heightMax;
}

//프레임 출력
void PrintFrame(int x, int y, int width, int height, int widthMax, int heightMax, vector<int> widthVector[], vector<int> heightVector[], int fixed_x, int fixed_y)
{
	int i = 0;
	int j = 0;

	//가로 숫자 출력
	x = widthMax;
	y = heightMax + 2;
	for (i = 0; i < HEIGHT; i++)
	{
		x = widthMax;
		for (j = widthVector[i].size() - 1; j >= 0; j--)
		{
			CursorPosition(x, y);
			printf("%d", widthVector[i].at(j));
			x -= 2;
		}
		y++;
	}

	//세로 숫자 출력
	x = widthMax + 4;
	y = heightMax;
	for (i = 0; i < WIDTH; i++)
	{
		y = heightMax;
		for (j = heightVector[i].size() - 1; j >= 0; j--)
		{
			CursorPosition(x, y);
			printf("%d", heightVector[i].at(j));
			y--;
		}
		x += 2;
	}

	//위쪽 가로줄
	x = fixed_x - 2;
	y = fixed_y - 1;
	CursorPosition(x, y);
	for (i = 0; i < width + 2; i++) printf("■");

	//왼쪽 세로줄
	y = fixed_y;
	for (i = 0; i < height; i++)
	{
		x = fixed_x - 2;
		CursorPosition(x, y);
		printf("■");
		y++;
	}

	//오른쪽 세로줄
	y = fixed_y;
	for (i = 0; i < height; i++)
	{
		x = fixed_x + width * 2;
		CursorPosition(x, y);
		printf("■");
		y++;
	}

	//아래쪽 가로줄
	x = fixed_x - 2;
	y = fixed_y + height;
	CursorPosition(x, y);
	for (i = 0; i < width + 2; i++) printf("■");
}

//이미지(로직) 출력
void PrintImage(int x, int y, int width, int height, int fixed_x, int fixed_y, int image[])
{
	int i = 0;

	x = fixed_x;
	y = fixed_y;
	for (i = 0; i < width * height; i++)
	{
		CursorPosition(x, y);
		if (image[i] == 0 || image[i] == 1)
		{
			printf("□");
		}
		else if (image[i] == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (image[i] == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			printf("■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (image[i] == 4 || image[i] == 5)
		{
			printf("▩");
		}
		x += 2;
		if ((i + 1) % width == 0)
		{
			x = fixed_x;
			y++;
		}
	}
}

//커서 이동
void MoveCursor(int x, int y)
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x0001) x += 2;
	if (GetAsyncKeyState(VK_LEFT) & 0x0001) x -= 2;
	if (GetAsyncKeyState(VK_UP) & 0x0001) y--;
	if (GetAsyncKeyState(VK_DOWN) & 0x0001) y++;
}

//커서 탈출 제어
void CursorEscapeControl(int x, int y, int width, int height, int fixed_x, int fixed_y)
{
	//왼쪽 탈출 제어
	if (x < fixed_x) x = fixed_x;
	//오른쪽 탈출 제어
	if (x > fixed_x + width * 2 - 2) x = fixed_x + width * 2 - 2;
	//위쪽 탈출 제어
	if (y < fixed_y) y = fixed_y;
	//아래쪽 탈출 제어
	if (y > fixed_y + height - 1) y = fixed_y + height - 1;
}

//이미지 변경
void ChangeImage(int x, int y, int width, int height, int fixed_x, int fixed_y, int image[], bool checkMode)
{
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		int xx = (x - fixed_x) / 2;
		int yy = (y - fixed_y) * width;
		if (!checkMode)
		{
			if (image[xx + yy] == 0)
			{
				image[xx + yy] = 2;
				heart--;
			}
			else if (image[xx + yy] == 1)
			{
				image[xx + yy] = 3;
			}
		}
		else if (checkMode)
		{
			if (image[xx + yy] == 0 || image[xx + yy] == 1)
			{
				image[xx + yy] += 4;
			}
			else if (image[xx + yy] == 4 || image[xx + yy] == 5)
			{
				image[xx + yy] -= 4;
			}
		}
		PrintImage(x, y, width, height, fixed_x, fixed_y, image);
		CursorPosition(0, fixed_y + height + 2);
		printf("Life : %d", heart);
	}
}

//체크 마크 모드
void CheckMarkMode(bool check, int height, int fixed_y)
{
	if (GetAsyncKeyState(VK_LSHIFT) & 0x0001)
	{
		CursorPosition(0, fixed_y + height + 3);
		if (checkMode)
		{
			checkMode = false;
			printf("Check Mode : false");
		}
		else if (!checkMode)
		{
			checkMode = true;
			printf("Check Mode : true ");
		}
	}
}

//네모로직 완성 검사
bool CheckImageDone(int image[], int width, int height)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < width * height; i++)
	{
		if (image[i] == 1 || image[i] == 5) j++;
	}
	if (j == 0) return true;
	else return false;
}

//게임 종료 시
bool GameEnd(bool done, int height, int fixed_y, const char* name)
{
	if (done)
	{
		CursorPosition(0, fixed_y + height + 5);
		printf("You drew ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("%s", name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		return false;
	}
	return true;
}

int main()
{
	GetWidthVector(WIDTH, HEIGHT, imageTree, wv);
	widthMax = GetWidthMax(HEIGHT, wv);
	FIXED_X = widthMax + 3;
	GetHeightVector(WIDTH, HEIGHT, imageTree, hv);
	heightMax = GetHeightMax(WIDTH, hv);
	FIXED_Y = heightMax + 2;
	PrintFrame(x, y, WIDTH, HEIGHT, widthMax, heightMax, wv, hv, FIXED_X, FIXED_Y);
	PrintImage(x, y, WIDTH, HEIGHT, FIXED_X, FIXED_Y, imageTree);

	CursorPosition(0, FIXED_Y + HEIGHT + 2);
	printf("Life : %d", heart);

	CursorPosition(0, FIXED_Y + HEIGHT + 3);
	printf("Check Mode : false");

	x = FIXED_X;
	y = FIXED_Y;

	while (isGameRunning)
	{
		CursorPosition(x, y);

		//MoveCursor(x, y);
		//CursorEscapeControl(x, y, WIDTH, HEIGHT, FIXED_X, FIXED_Y);
		ChangeImage(x, y, WIDTH, HEIGHT, FIXED_X, FIXED_Y, imageTree, checkMode);
		CheckMarkMode(checkMode, HEIGHT, FIXED_Y);

		//커서 이동
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001) x += 2;
		if (GetAsyncKeyState(VK_LEFT) & 0x0001) x -= 2;
		if (GetAsyncKeyState(VK_UP) & 0x0001) y--;
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) y++;

		//왼쪽 커서 탈출 제어
		if (x < FIXED_X) x = FIXED_X;
		//오른쪽 커서 탈출 제어
		if (x > FIXED_X + WIDTH * 2 - 2) x = FIXED_X + WIDTH * 2 - 2;
		//위쪽 커서 탈출 제어
		if (y < FIXED_Y) y = FIXED_Y;
		//아래쪽 커서 탈출 제어
		if (y > FIXED_Y + HEIGHT - 1) y = FIXED_Y + HEIGHT - 1;

		//끝!
		done = CheckImageDone(imageTree, WIDTH, HEIGHT);
		isGameRunning = GameEnd(done, HEIGHT, FIXED_Y, "Tree");

		//사망
		if (heart <= 0)
		{
			CursorPosition(0, FIXED_Y + HEIGHT + 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("You Died");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			isGameRunning = false;
		}

		//게임 나가기
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) isGameRunning = false;
	}

	CursorPosition(0, 20);

	return 0;
}