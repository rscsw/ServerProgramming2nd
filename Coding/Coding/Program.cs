//----------------------------------------------------------------------------------------------



//전역변수 저장소

//1번 문제
int max = 50;
char[] rv;

//2번 문제
int[,] b = new int[,] { { 9, 11, 16, 21, 28, 36, 5 },
                        { 3, 9, 10, 29, 40, 45, 7 },
                        { 2, 5, 12, 14, 24, 39, 33 },
                        { 1, 6, 13, 37, 38, 40, 9 },
                        { 1, 21, 25, 29, 34, 37, 36 }};
List<int> bp = new List<int>();
bool addit = true;

//3번 문제
char[] sibal;
List<char> imsy = new List<char>();
Random random = new Random();
int rand;

//4번 문제
int year;
int month;
int sunday = 0;
int day;
DateTime findsunday;

//5번 문제
int r = 25;

//6번 문제
List<string> files = new List<string>();
files.Add("20200309_최종.png");
files.Add("20200309_최종_수정.png");
files.Add("20200309_최종_수정(1).png");
files.Add("20200309_최종_수정(2).png");
files.Add("20200309_최종_확정.png");
files.Add("20200309_최종_확정2.png");
string filename;
bool addfile = true;
bool save = false;
int over = 0;
string path = @"D:\VR20222\ServerProgramming\Coding\Test6\";

//7번 문제
int repeatnum = 6;



//----------------------------------------------------------------------------------------------



//실행하고 싶은 문제를 이곳에 입력하세요

//Test1();
//Test2();
//Test3();
//Test4();
//Test5();
//Test6();
//Test7();
Console.Write("\n\n");
while (true)
{
    Test6();
}



//----------------------------------------------------------------------------------------------



void Test1()
{
    Console.WriteLine("\n\n[1번 문제] ");
    Console.Write("아무거나 입력하세요 : ");
    rv = Console.ReadLine().ToCharArray();
    Console.Write("뒤집어드립니다 : ");
    if (rv.Length > max)
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



//----------------------------------------------------------------------------------------------



void Test2()
{
    Console.WriteLine("\n\n[2번 문제] ");
    Console.WriteLine("다음과 같은 정수로 이루어진 배열들이 있습니다");
    for (int i = 0; i < b.GetLength(0); i++)
    {
        for (int j = 0; j < b.GetLength(1); j++)
        {
            Console.Write(b[i, j] + " ");
        }
        Console.WriteLine();
    }
    Console.WriteLine("짜잔! 합집합 출력!");
    for (int i = 0; i < b.GetLength(0); i++)
    {
        for (int j = 0; j < b.GetLength(1); j++)
        {
            for (int k = 0; k < bp.Count; k++)
            {
                if (b[i, j] == bp[k])
                {
                    addit = false;
                    break;
                }
            }
            if (addit)
            {
                bp.Add(b[i, j]);
            }
            else
            {
                addit = true;
            }
        }
    }
    for (int i = 0; i < bp.Count; i++)
    {
        Console.Write(bp[i] + " ");
    }
}



//----------------------------------------------------------------------------------------------



void Test3()
{
    Console.WriteLine("\n\n[3번 문제] ");
    Console.Write("아무거나 입력하세요 : ");
    sibal = Console.ReadLine().ToCharArray();
    for (int i = 0; i < sibal.Length; i++)
    {
        rand = random.Next(0, sibal.Length);
        if (sibal[rand] == '\0')
        {
            i--;
        }
        else
        {
            imsy.Add(sibal[rand]);
            sibal[rand] = '\0';
        }
    }
    Console.Write("섞어드립니다 : ");
    for (int i = 0; i < imsy.Count; i++)
    {
        Console.Write(imsy[i]);
    }
}



//----------------------------------------------------------------------------------------------



void Test4()
{
    Console.WriteLine("\n\n[4번 문제] ");
    year = DateTime.Now.Year;
    month = DateTime.Now.Month;
    Console.WriteLine("이번 달은 " + year + "년 " + month + "월입니다");
    if (DateTime.IsLeapYear(year) && month == 2)
    {
        day = 29;
    }
    else if (month == 2)
    {
        day = 28;
    }
    else if ((month % 2 == 0 && month <= 7) || (month % 2 != 0 && month >= 8))
    {
        day = 30;
    }
    else
    {
        day = 31;
    }
    for (int i = 1; i <= day; i++)
    {
        findsunday = new DateTime(year, month, i);
        if (findsunday.DayOfWeek == DayOfWeek.Sunday)
        {
            sunday++;
        }
    }
    Console.Write("이번 달에는 일요일이 총 " + sunday + "번 있습니다");
}
void Test4_Wrong()
{
    Console.WriteLine("\n\n[4번 문제] ");
    while (true)
    {
        while (true)
        {
            try
            {
                Console.Write("년도를 입력하세요 : ");
                year = Convert.ToInt32(Console.ReadLine());
                if (year > 0)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("기원전은 계산할 수 없습니다");
                }
            }
            catch (FormatException)
            {
                Console.WriteLine("숫자만 입력하세요 뒤지기 싫으면");
            }
            catch (OverflowException)
            {
                Console.WriteLine("멍청한 컴퓨터가 계산하기엔 너무 먼 미래거나 말도 안 되는 기원전입니다");
            }
        }
        while (true)
        {
            try
            {
                Console.Write("월을 입력하세요 : ");
                month = Convert.ToInt32(Console.ReadLine());
                if (month >= 1 && month <= 12)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("그런 월은 존재하지 않습니다");
                }
            }
            catch (FormatException)
            {
                Console.WriteLine("숫자만 입력하세요 뒤지기 싫으면");
            }
            catch (OverflowException)
            {
                Console.WriteLine("그런 월은 존재하지 않습니다");
            }
        }
        try
        {
            if (DateTime.IsLeapYear(year) && month == 2)
            {
                day = 29;
            }
            else if (month == 2)
            {
                day = 28;
            }
            else if ((month % 2 == 0 && month <= 7) || (month % 2 != 0 && month >= 8))
            {
                day = 30;
            }
            else
            {
                day = 31;
            }
            for (int i = 1; i <= day; i++)
            {
                findsunday = new DateTime(year, month, i);
                if (findsunday.DayOfWeek == DayOfWeek.Sunday)
                {
                    sunday++;
                }
            }
            break;
        }
        catch (ArgumentOutOfRangeException)
        {
            Console.WriteLine("멍청한 컴퓨터는 " + year + "년 " + month + "월이 언제인지 모릅니다");
            sunday = 0;
        }
    }
    Console.Write(year + "년 " + month + "월에는 일요일이 총 " + sunday + "번 있습니다");
}



//----------------------------------------------------------------------------------------------



void Test5()
{
    Console.WriteLine("\n\n[5번 문제]");
    for (int i = -r; i < r; i++)
    {
        for (int j = -r; j < r; j++)
        {
            if (i * i + j * j <= r * r)
            {
                Console.Write("ㅇ");
            }
            else
            {
                Console.Write("  ");
            }
        }
        Console.WriteLine();
    }
}



//----------------------------------------------------------------------------------------------



void Test6_BeforeFix()
{
    Console.WriteLine("\n\n[6번 문제] ");
    Console.WriteLine("저장된 파일들의 이름 : ");
    for (int i = 0; i < files.Count; i++)
    {
        Console.WriteLine(files[i]);
    }
    Console.Write("저장할 파일의 이름을 입력하세요 : ");
    filename = Console.ReadLine();
    for (int i = 0; i < files.Count; i++)
    {
        if (files[i].Equals(filename))
        {
            addfile = false;
            over = i;
            break;
        }
    }
    if (addfile)
    {
        files.Add(filename);
    }
    else
    {
        if (filename.Contains(")."))
        {
            string[] cut = filename.Split('(', ')', '.');
            string[] overcut = files[over].Split('(', ')');
            try
            {
                int filenum = Convert.ToInt32(overcut[overcut.Length - 2]);
                filenum++;
                string newnumfile = null;
                for (int i = 0; i < cut.Length - 3; i++)
                {
                    newnumfile += cut[i];
                }
                while (!save)
                {
                    string sss = newnumfile + "(" + filenum + ")." + cut[cut.Length - 1];
                    bool done = false;
                    for (int i = 0; i < files.Count; i++)
                    {
                        if (files[i].Equals(sss))
                        {
                            done = false;
                            filenum++;
                            break;
                        }
                        else
                        {
                            done = true;
                        }
                    }
                    if (done)
                    {
                        files.Add(sss);
                        save = true;
                    }
                }
            }
            catch (FormatException)
            {
                Test6_BeforeFix_OverlapCode();
            }
        }
        else
        {
            Test6_BeforeFix_OverlapCode();
        }
    }
    Console.Write("저장된 파일들의 이름 : ");
    for (int i = 0; i < files.Count; i++)
    {
        Console.Write("\n" + files[i]);
    }
}
void Test6_BeforeFix_OverlapCode()
{
    string[] ss = filename.Split('.');
    string s = null;
    for (int i = 0; i < ss.Length - 1; i++)
    {
        s += ss[i];
    }
    int num = 1;
    while (!save)
    {
        string sss = s + "(" + num + ")." + ss[ss.Length - 1];
        bool done = false;
        for (int i = 0; i < files.Count; i++)
        {
            if (files[i].Equals(sss))
            {
                done = false;
                num++;
                break;
            }
            else
            {
                done = true;
            }
        }
        if (done)
        {
            files.Add(sss);
            save = true;
        }
    }
}
void Test6()
{
    Console.WriteLine("\n\n[6번 문제] ");
    Console.Write("저장할 파일의 이름을 입력하세요 : ");
    filename = Console.ReadLine();
    if (File.Exists(path + filename))
    {
        if (filename.Contains(")."))
        {
            string[] cut = filename.Split('(', ')');
            try
            {
                int filenum = Convert.ToInt32(cut[cut.Length - 2]);
                string newnumfile = "(" + filenum.ToString() + ")" + cut[cut.Length - 1];
                Console.WriteLine(newnumfile);
                string[] hell = filename.Split(newnumfile);
                Console.WriteLine(hell[0]);
                while (true)
                {
                    string ss = hell[0] + "(" + filenum.ToString() + ")" + cut[cut.Length - 1];
                    if (!File.Exists(path + ss))
                    {
                        File.Create(path + ss);
                        break;
                    }
                    filenum++;
                }
            }
            catch (FormatException)
            {
                Test6_OverlapCode();
            }
        }
        else
        {
            Test6_OverlapCode();
        }
    }
    else
    {
        File.Create(path + filename);
    }
}
void Test6_OverlapCode()
{
    string[] ss = filename.Split('.');
    string s = null;
    for (int i = 0; i < ss.Length - 2; i++)
    {
        s += ss[i] + ".";
    }
    s += ss[ss.Length - 2];
    int num = 1;
    while (true)
    {
        string sss = s + "(" + num + ")." + ss[ss.Length - 1];
        if (File.Exists(path + sss))
        {
            num++;
        }
        else
        {
            File.Create(path + sss);
            break;
        }
    }
}



//----------------------------------------------------------------------------------------------



void Test7()
{
    Console.WriteLine("\n\n[7번 문제]");
    string gemi = "1";
    while (repeatnum > 0)
    {
        Console.WriteLine(gemi);
        char nowgemi = gemi[0];
        int gemisu = 0;
        string imsygemi = null;
        for (int i = 0; i < gemi.Length; i++)
        {
            if (nowgemi == gemi[i])
            {
                gemisu++;
            }
            else
            {
                imsygemi = imsygemi + nowgemi.ToString() + gemisu.ToString();
                nowgemi = gemi[i];
                gemisu = 1;
            }
            if (i + 1 == gemi.Length)
            {
                imsygemi = imsygemi + nowgemi.ToString() + gemisu.ToString();
            }
        }
        gemi = imsygemi;
        repeatnum--;
    }
}