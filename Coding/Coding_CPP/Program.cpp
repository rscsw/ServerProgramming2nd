#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int* Union(int* Group1, int* Group2)
{
	int sibalArr[20];
	int sibalNum = 0;
	for (int i = 0; i < _msize(Group1) / sizeof(int); i++)
	{
		for (int j = 0; j < _msize(Group2) / sizeof(int); j++)
		{
			if (Group1[i] == Group2[j])
			{
				break;
			}
			else
			{
				sibalArr[sibalNum] = Group2[j];
				sibalNum++;
			}
		}
	}
	for (int i = 0; i < _msize(Group1) / sizeof(int); i++)
	{
		sibalArr[sibalNum] = Group1[i];
		sibalNum++;
	}
	return sibalArr;
}

int main()
{
	int *Group1, *Group2, *UnionGroup;

	Group1 = (int*)malloc(sizeof(int) * 7);
	Group2 = (int*)malloc(sizeof(int) * 7);
	Group1[0] = 9;
	Group1[1] = 11;
	Group1[2] = 16;
	Group1[3] = 21;
	Group1[4] = 28;
	Group1[5] = 36;
	Group1[6] = 5;
	Group2[0] = 3;
	Group2[1] = 9;
	Group2[2] = 10;
	Group2[3] = 29;
	Group2[4] = 40;
	Group2[5] = 45;
	Group2[6] = 7;
	
	UnionGroup = Union(Group1, Group2);

	for (int i = 0; i < _msize(UnionGroup) / sizeof(int); i++)
	{
		cout << UnionGroup[i];
	}

	free(Group1);
	free(Group2);
	free(UnionGroup);

	return 0;
}