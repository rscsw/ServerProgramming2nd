//Test 1

int max = 50;

Console.Write("아무거나 입력하세요 : ");
string s = Console.ReadLine();
Fuck(s);

void Fuck(string s)
{
    char[] rv = s.ToCharArray();
    if (rv.Length >= max)
    {
        for (int i = max - 1; i >= 0; i--)
        {
            Console.Write(rv[i]);
        }
    }
    else
    {
        for (int i = rv.Length - 1; i >= 0; i--)
        {
            Console.Write(rv[i]);
        }
    }
}

//Test2

int[,] b = new int[,] { { 9, 11, 16, 21, 28, 36, 5 }, { 3, 9, 10, 29, 40, 45, 7 }, { 2, 5, 12, 14, 24, 39, 33 }, { 1, 6, 13, 37, 38, 40, 9 }, { 1, 21, 25, 29, 34, 37, 36 }};

Console.WriteLine("\n\n짜잔! 합집합 출력!");
Mendokusai();

void Mendokusai()
{
    for(int i = 0; i < b.GetLength(0); i++)
}