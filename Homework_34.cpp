#include <iostream>
#include <windows.h>
#include <map>

using namespace std;

struct arrAtribute
{
    int** pointer;
    int rows;
    int collumns;
    bool switcher;
};

template <class Key,
    class Type,
    class traits = less<Key>,
    class Allocator = allocator<pair<const Key, Type>>
> class myMap;

void task_1();
void task_2();
void arrShow(int** arr, int rows, int coll);
void arrGen(int** arr, int rows, int coll);
int countUnique(std::map<int, arrAtribute> arr);
void saveUnique(std::map<int, arrAtribute> arr, int* sum);
int countSame0(std::map<int, arrAtribute> arr);
void saveSame0(std::map<int, arrAtribute> arr, int* sum);
int countSame1(std::map<int, arrAtribute> arr);
void saveSame1(std::map<int, arrAtribute> arr, int* sum);
int countMinus(std::map<int, arrAtribute> arr);
void saveMinus(std::map<int, arrAtribute> arr, int* arrSum);
void deleter(int** arr, int rows);

int main()
{
    srand(time(0));
    short choise = 0;
    while (true)
    {
        cout << "choose task:\n1 - secondName sort\n2 - complex of sorting\n";
        cin >> choise;
        if (choise == 1)
        {
            task_1();
        }
        else if (choise == 2)
        {
            task_2();
        }
        else
        {
            exit(1);
        }
    }
}

void task_1()
{
    const int size = 5;
    char* arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new char[12];
        cout << "Enter " << i + 1 << " student secondname: ";
        cin >> arr[i];
    }
    char* temp = nullptr;
    int lengt;
    for (int sort = 0; sort < size - 1; sort++)
    {
        for (int helper = 0; helper < size - sort - 1; helper++)
        {
            if (strlen(arr[helper]) < strlen(arr[helper + 1]))
            {
                lengt = strlen(arr[helper]);
            }
            else
            {
                lengt = strlen(arr[helper + 1]);
            }
            for (int procc = 0; procc < lengt; procc++)
            {
                if (arr[helper][procc] < arr[helper + 1][procc])
                {
                    cout << helper << ", " << procc << "; " << arr[helper][procc] << ";" << arr[helper + 1][procc] << "\n";
                    temp = arr[helper];
                    arr[helper] = arr[helper + 1];
                    arr[helper + 1] = temp;
                    break;
                }
                else if (arr[helper][procc] != arr[helper + 1][procc])
                {
                    break;
                }
            }
        }
    }
    for (int out = 0; out < 5; out++)
    {
        for (int chr = 0; chr < strlen(arr[out]); chr++)
        {
            cout << arr[out][chr];
        }
        cout << "\n";
    }
    for (int del = 0; del < 5; del++)
    {
        delete[] arr[del];
    }
    delete[] arr;
    delete[] temp;
}

void arrShow(int** arr, int rows, int coll)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < coll; col++)
        {
            cout << arr[row][col] << ", ";
        }
        cout << "\n";
    }
}

void arrGen(int** arr, int rows, int coll)
{
    int minus;
    for (int row = 0; row < rows; row++)
    {
        arr[row] = new int[coll];
        for (int col = 0; col < coll; col++)
        {
            minus = (rand() % 2 == 0 ? 1 : -1);
            arr[row][col] = rand() * minus % 10;
        }
    }
}

void saveUnique(std::map<int, arrAtribute> arr, int* sum)
{ 
    int counter = 0;
    for (int row = 0; row < arr.at(0).rows; row++)
    {
        for (int coll = 0; coll < arr.at(0).collumns; coll++)
        {
            arr.at(0).switcher = true;
            //arr_0 start
            for (int rowEq1 = 0; rowEq1 < arr.at(1).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(1).collumns; collEq1++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(1).pointer[rowEq1][collEq1])
                    {
                        arr.at(0).switcher = false;
                        break;
                    }
                }
                if (!arr.at(0).switcher)
                {
                    break;
                }
            }
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(0).switcher = false;
                        break;
                    }
                }
                if (!arr.at(0).switcher)
                {
                    break;
                }
            } // arr_0 end cycle
            if (arr.at(0).switcher)
            {
                sum[counter] = arr.at(0).pointer[row][coll];
                counter++;
            }
        }
    }
    for (int row = 0; row < arr.at(1).rows; row++)
    {
        for (int coll = 0; coll < arr.at(1).collumns; coll++)
        {
            arr.at(1).switcher = true;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(1).switcher = false;
                        break;
                    }
                }
                if (!arr.at(1).switcher)
                {
                    break;
                }
            }
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(1).switcher = false;
                        break;
                    }
                }
                if (!arr.at(1).switcher)
                {
                    break;
                }
            }
            if (arr.at(1).switcher)
            {
                sum[counter] = arr.at(1).pointer[row][coll];
                counter++;
            }//arr_1 end cycle
        }
    }
    for (int row = 0; row < arr.at(2).rows; row++)
    {
        for (int coll = 0; coll< arr.at(2).collumns; coll++)
        {
            //arr_2 start
            arr.at(2).switcher = true;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(2).switcher = false;
                        break;
                    }
                }
                if (!arr.at(2).switcher)
                {
                    break;
                }
            }
            for (int rowEq2 = 0; rowEq2 < arr.at(1).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(1).rows; collEq2++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(1).pointer[rowEq2][collEq2])
                    {
                        arr.at(2).switcher = false;
                        break;
                    }
                }
                if (!arr.at(2).switcher)
                {
                    break;
                }
            }
            if (arr.at(2).switcher)
            {
                sum[counter] = arr.at(2).pointer[row][coll];
                counter++;
            }//arr_2 end cycle;
        }
    }
}

int countUnique(std::map<int, arrAtribute> arr)
{
    int counter = 0;
    for (int row = 0; row < arr.at(0).rows; row++)
    {
        for (int coll = 0; coll < arr.at(0).collumns; coll++)
        {
            arr.at(0).switcher = true;
            for (int rowEq1 = 0; rowEq1 < arr.at(1).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(1).collumns; collEq1++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(1).pointer[rowEq1][collEq1])
                    {
                        arr.at(0).switcher = false;
                        break;
                    }
                }
                if (!arr.at(0).switcher)
                {
                    break;
                }
            }
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(0).switcher = false;
                        break;
                    }
                }
                if (!arr.at(0).switcher)
                {
                    break;
                }
            }
            if (arr.at(0).switcher)
            {
                counter++;
            }// arr_0 end cycle
        }
    }
    for (int row = 0; row < arr.at(1).rows; row++)
    {
        for (int coll = 0; coll < arr.at(1).collumns; coll++)
        {
            //arr_1 start
            arr.at(1).switcher = true;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(1).switcher = false;
                        break;
                    }
                }
                if (!arr.at(1).switcher)
                {
                    break;
                }
            }
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(1).switcher = false;
                        break;
                    }
                }
                if (!arr.at(1).switcher)
                {
                    break;
                }
            }
            if (arr.at(1).switcher)
            {
                counter++;
            }//arr_1 end cycle
        }
    }
    for (int row = 0; row < arr.at(2).rows; row++)
    {
        for (int coll = 0; coll < arr.at(2).collumns; coll++)
        {
            //arr_2 start
            arr.at(2).switcher = true;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(2).switcher = false;
                        break;
                    }
                }
                if (!arr.at(2).switcher)
                {
                    break;
                }
            }
            for (int rowEq2 = 0; rowEq2 < arr.at(1).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(1).rows; collEq2++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(1).pointer[rowEq2][collEq2])
                    {
                        arr.at(2).switcher = false;
                        break;
                    }
                }
                if (!arr.at(2).switcher)
                {
                    break;
                }
            }
            if (arr.at(2).switcher)
            {
                counter++;
            }
        }
    }
    return(counter);
}

int countSame0(std::map<int, arrAtribute> arr)
{
    int counter = 0;
    for (int row = 0; row < arr.at(0).rows; row++)
    {
        for (int coll = 0; coll < arr.at(0).collumns; coll++)
        {
            arr.at(1).switcher = false;
            for (int rowEq1 = 0; rowEq1 < arr.at(1).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(1).collumns; collEq1++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(1).pointer[rowEq1][collEq1])
                    {
                        arr.at(1).switcher = true;
                        break;
                    }
                }
                if (arr.at(1).switcher)
                {
                    break;
                }
            }
            arr.at(2).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(2).switcher = true;
                        break;
                    }
                }
                if (arr.at(2).switcher)
                {
                    break;
                }
            }
            if (arr.at(1).switcher && arr.at(2).switcher)
            {
                counter++;
            }
        }
    }
    for (int row = 0; row < arr.at(1).rows; row++)
    {
        for (int coll = 0; coll < arr.at(1).collumns; coll++)
        {
            arr.at(0).switcher = false;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(0).switcher = true;
                        break;
                    }
                }
                if (arr.at(0).switcher)
                {
                    break;
                }
            }
            arr.at(2).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(2).switcher = true;
                        break;
                    }
                }
                if (arr.at(2).switcher)
                {
                    break;
                }
            }
            if (arr.at(0).switcher && arr.at(2).switcher)
            {
                counter++;
            }
        }
    }
    for (int row = 0; row < arr.at(2).rows; row++)
    {
        for (int coll = 0; coll < arr.at(2).collumns; coll++)
        {
            arr.at(0).switcher = false;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(0).switcher = true;
                        break;
                    }
                }
                if (arr.at(0).switcher)
                {
                    break;
                }
            }
            arr.at(1).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(1).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(1).rows; collEq2++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(1).pointer[rowEq2][collEq2])
                    {
                        arr.at(1).switcher = true;
                        break;
                    }
                }
                if (arr.at(1).switcher)
                {
                    break;
                }
            }
            if (arr.at(0).switcher && arr.at(1).switcher)
            {
                counter++;
            }
        }
    }
    cout << "countSame0: " << counter << "\n";
    return(counter);
}

void saveSame0(std::map<int, arrAtribute> arr, int* sum)
{
    int counter = 0;
    for (int row = 0; row < arr.at(0).rows; row++)
    {
        for (int coll = 0; coll < arr.at(0).collumns; coll++)
        {
            arr.at(0).switcher = false;
            for (int rowEq1 = 0; rowEq1 < arr.at(1).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(1).collumns; collEq1++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(1).pointer[rowEq1][collEq1])
                    {
                        arr.at(0).switcher = true;
                        break;
                    }
                }
                if (arr.at(0).switcher)
                {
                    break;
                }
            }
            arr.at(2).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(1).switcher = true;
                        break;
                    }
                }
                if (arr.at(1).switcher)
                {
                    break;
                }
            }
            if (arr.at(0).switcher && arr.at(1).switcher)
            {
                sum[counter] = arr.at(0).pointer[row][coll];
                counter++;
            }
        }
    }
    for (int row = 0; row < arr.at(1).rows; row++)
    {
        for (int coll = 0; coll < arr.at(1).collumns; coll++)
        {
            arr.at(1).switcher = false;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(1).switcher = true;
                        break;
                    }
                }
                if (arr.at(1).switcher)
                {
                    break;
                }
            }
            arr.at(2).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).rows; collEq2++)
                {
                    if (arr.at(1).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(2).switcher = true;
                        break;
                    }
                }
                if (arr.at(2).switcher)
                {
                    break;
                }
            }
            if (arr.at(1).switcher && arr.at(2).switcher)
            {
                sum[counter] = arr.at(1).pointer[row][coll];
                counter++;
            }
        }
    }
    for (int row = 0; row < arr.at(2).rows; row++)
    {
        for (int coll = 0; coll < arr.at(2).collumns; coll++)
        {
            arr.at(2).switcher = false;
            for (int rowEq1 = 0; rowEq1 < arr.at(0).rows; rowEq1++)
            {
                for (int collEq1 = 0; collEq1 < arr.at(0).collumns; collEq1++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(0).pointer[rowEq1][collEq1])
                    {
                        arr.at(2).switcher = true;
                        break;
                    }
                }
                if (arr.at(2).switcher)
                {
                    break;
                }
            }
            arr.at(1).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(1).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(1).rows; collEq2++)
                {
                    if (arr.at(2).pointer[row][coll] == arr.at(1).pointer[rowEq2][collEq2])
                    {
                        arr.at(1).switcher = true;
                        break;
                    }
                }
                if (arr.at(1).switcher)
                {
                    break;
                }
            }
            if (arr.at(2).switcher && arr.at(1).switcher)
            {
                sum[counter] = arr.at(2).pointer[row][coll];
                counter++;
            }
        }
    }
}

void saveSame1(std::map<int, arrAtribute> arr, int* sum)
{
    int counter = 0;
    for (int row = 0; row < arr.at(0).rows; row++)
    {
        for (int coll = 0; coll < arr.at(0).collumns; coll++)
        {
            arr.at(0).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).collumns; collEq2++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(0).switcher = true;
                        break;
                    }
                }
                if (arr.at(0).switcher)
                {
                    break;
                }
            }
            if (arr.at(0).switcher)
            {
                sum[counter] = arr.at(0).pointer[row][coll];
                counter++;
            }
        }
    }
}

int countSame1(std::map<int, arrAtribute> arr)
{
    int counter = 0;
    for (int row = 0; row < arr.at(0).rows; row++)
    {
        for (int coll = 0; coll < arr.at(0).collumns; coll++)
        {
            arr.at(0).switcher = false;
            for (int rowEq2 = 0; rowEq2 < arr.at(2).rows; rowEq2++)
            {
                for (int collEq2 = 0; collEq2 < arr.at(2).collumns; collEq2++)
                {
                    if (arr.at(0).pointer[row][coll] == arr.at(2).pointer[rowEq2][collEq2])
                    {
                        arr.at(0).switcher = true;
                        break;
                    }
                }
                if (arr.at(0).switcher)
                {
                    break;
                }
            }
            if (arr.at(0).switcher)
            {
                counter++;
            }
        }
    }
    cout << "countSame1: " << counter << "\n";
    return(counter);
}

int countMinus(std::map<int, arrAtribute> arr)
{
    int* minusStorage = nullptr;
    int counter;
    bool hasBeen;
    for (int optimize = 0; optimize < 2; optimize++)
    {
        counter = 0;
        for (int row = 0; row < arr.at(0).rows; row++)
        {
            for (int coll = 0; coll < arr.at(0).collumns; coll++)
            {
                hasBeen = false;
                if (arr.at(0).pointer[row][coll] < 0 && optimize < 1)
                {
                    counter++;
                }
                else if (optimize > 0 && arr.at(0).pointer[row][coll] < 0)
                {
                    for (int equal = 0; equal < (counter > 0 ? counter : 1); equal++)
                    {
                        if (arr.at(0).pointer[row][coll] == minusStorage[equal])
                        {
                            hasBeen = true;
                            break;
                        }
                    }
                    if (!hasBeen)
                    {
                        minusStorage[counter] = arr.at(0).pointer[row][coll];
                        counter++;
                    }
                }
            }
        }
        for (int row = 0; row < arr.at(1).rows; row++)
        {
            for (int coll = 0; coll < arr.at(1).collumns; coll++)
            {
                hasBeen = false;
                if (arr.at(1).pointer[row][coll] < 0 && optimize < 1)
                {
                    counter++;
                }
                else if (optimize > 0 && arr.at(1).pointer[row][coll] < 0)
                {
                    for (int equal = 0; equal < (counter > 0 ? counter : 1); equal++)
                    {
                        if (arr.at(1).pointer[row][coll] == minusStorage[equal])
                        {
                            hasBeen = true;
                            break;
                        }
                    }
                    if (!hasBeen)
                    {
                        minusStorage[counter] = arr.at(1).pointer[row][coll];
                        counter++;
                    }
                }
            }
        }
        for (int row = 0; row < arr.at(2).rows; row++)
        {
            for (int coll = 0; coll < arr.at(2).collumns; coll++)
            {
                hasBeen = false;
                if (arr.at(2).pointer[row][coll] < 0 && optimize < 1)
                {
                    counter++;
                }
                else if (optimize > 0 && arr.at(2).pointer[row][coll] < 0)
                {
                    for (int equal = 0; equal < (counter > 0 ? counter : 1); equal++)
                    {
                        if (arr.at(2).pointer[row][coll] == minusStorage[equal])
                        {
                            hasBeen = true;
                            break;
                        }
                    }
                    if (!hasBeen)
                    {
                        minusStorage[counter] = arr.at(2).pointer[row][coll];
                        counter++;
                    }
                }
            }
        }
        if (optimize < 1)
        {
            minusStorage = new int[counter];
            for (int fill = 0; fill < counter; fill++)
            {
                minusStorage[fill] = 0;
            }
        }
    }
    delete[] minusStorage;
    return(counter);
}

void saveMinus(std::map<int, arrAtribute> arr, int* arrSum)
{
    int* minusStorage = nullptr;
    int counter;
    bool hasBeen;
    for (int optimize = 0; optimize < 2; optimize++)
    {
        counter = 0;
        for (int row = 0; row < arr.at(0).rows; row++)
        {
            for (int coll = 0; coll < arr.at(0).collumns; coll++)
            {
                hasBeen = false;
                if (arr.at(0).pointer[row][coll] < 0 && optimize < 1)
                {
                    counter++;
                }
                else if (optimize > 0 && arr.at(0).pointer[row][coll] < 0)
                {
                    for (int equal = 0; equal < (counter > 0 ? counter : 1); equal++)
                    {
                        if (arr.at(0).pointer[row][coll] == minusStorage[equal])
                        {
                            hasBeen = true;
                            break;
                        }
                    }
                    if (!hasBeen)
                    {
                        minusStorage[counter] = arr.at(0).pointer[row][coll];
                        arrSum[counter] = arr.at(0).pointer[row][coll];
                        counter++;
                    }
                }
            }
        }
        for (int row = 0; row < arr.at(1).rows; row++)
        {
            for (int coll = 0; coll < arr.at(1).collumns; coll++)
            {
                hasBeen = false;
                if (arr.at(1).pointer[row][coll] < 0 && optimize < 1)
                {
                    counter++;
                }
                else if (optimize > 0 && arr.at(1).pointer[row][coll] < 0)
                {
                    for (int equal = 0; equal < (counter > 0 ? counter : 1); equal++)
                    {
                        if (arr.at(1).pointer[row][coll] == minusStorage[equal])
                        {
                            hasBeen = true;
                            break;
                        }
                    }
                    if (!hasBeen)
                    {
                        minusStorage[counter] = arr.at(1).pointer[row][coll];
                        arrSum[counter] = arr.at(1).pointer[row][coll];
                        counter++;
                    }
                }
            }
        }
        for (int row = 0; row < arr.at(2).rows; row++)
        {
            for (int coll = 0; coll < arr.at(2).collumns; coll++)
            {
                hasBeen = false;
                if (arr.at(2).pointer[row][coll] < 0 && optimize < 1)
                {
                    counter++;
                }
                else if (optimize > 0 && arr.at(2).pointer[row][coll] < 0)
                {
                    for (int equal = 0; equal < (counter > 0 ? counter : 1); equal++)
                    {
                        if (arr.at(2).pointer[row][coll] == minusStorage[equal])
                        {
                            hasBeen = true;
                            break;
                        }
                    }
                    if (!hasBeen)
                    {
                        minusStorage[counter] = arr.at(2).pointer[row][coll];
                        arrSum[counter] = arr.at(2).pointer[row][coll];
                        counter++;
                    }
                }
            }
        }
        if (optimize < 1)
        {
            minusStorage = new int[counter];
            for (int fill = 0; fill < counter; fill++)
            {
                minusStorage[fill] = 0;
            }
        }
    }
    delete[] minusStorage;
}

void deleter(int** arr, int rows)
{
    for (int deleter = 0; deleter < rows; deleter++)
    {
        delete[] arr[deleter];
    }
    delete[] arr;
}

void task_2()
{
    int rows0;
    int coll0;
    cout << "Enter number of rows: ";
    cin >> rows0;
    int** arr_0 = new int* [rows0];
    cout << "Enter number of collmns: ";
    cin >> coll0;
    arrGen(arr_0, rows0, coll0);
    int rows1;
    int coll1;
    cout << "Enter number of rows: ";
    cin >> rows1;
    int** arr_1 = new int* [rows1];
    cout << "Enter number of collmns: ";
    cin >> coll1;
    arrGen(arr_1, rows1, coll1);
    int rows2;
    int coll2;
    cout << "Enter number of rows: ";
    cin >> rows2;
    int** arr_2 = new int* [rows2];
    cout << "Enter number of collmns: ";
    cin >> coll2;
    arrGen(arr_2, rows2, coll2);
    bool switcher0 = true;
    bool switcher1 = true;
    bool switcher2 = true;
    int counter = 0;
    std::map<int, arrAtribute> mass = { {0, arrAtribute{arr_0, rows0, coll0, switcher0}},
                                           {1, arrAtribute{arr_1, rows1, coll1, switcher1}},
                                           {2, arrAtribute{arr_2, rows2, coll2, switcher2}} };
    int* arrSum;
    cout << "first array:\n";
    arrShow(arr_0, rows0, coll0);
    cout << "second array:\n";
    arrShow(arr_1, rows1, coll1);
    cout << "third array:\n";
    arrShow(arr_2, rows2, coll2);
    counter = countUnique(mass);
    if (counter > 0)
    {
        arrSum = new int[counter];
        saveUnique(mass, arrSum);
        cout << "unique numbers for A, B and C:\n";
        arrShow(&arrSum, 1, counter);
        delete[] arrSum;
    }
    else
    {
        cout << "no unique numbers for A, B and C\n";
    }
    counter = countSame0(mass);
    if (counter > 0)
    {
        arrSum = new int[counter];
        saveSame0(mass, arrSum);
        cout << "Same numbers for A, B and C:\n";
        arrShow(&arrSum, 1, counter);
        delete[] arrSum;
    }
    else
    { 
        cout << "no same nmbers for A, B and C\n";
    }
    counter = countSame1(mass);
    if (counter > 0)
    {
        arrSum = new int[counter];
        saveSame1(mass, arrSum);
        cout << "Same numbers for A and C:\n";
        arrShow(&arrSum, 1, counter);
        delete[] arrSum;
    }
    else
    {
        cout << "no same numbers for A and C\n";
    }
    counter = countMinus(mass);
    if (counter > 0)
    {
        arrSum = new int[counter];
        saveMinus(mass, arrSum);
        cout << "Non-repeateble numbers < 0 for A, B and C:\n";
        arrShow(&arrSum, 1, counter);
        delete[] arrSum;
    }
    else
    {
        cout << "no non-repeateble numbers < 0 for A, B and C";
    }
    deleter(arr_0, rows0);
    deleter(arr_1, rows1);
    deleter(arr_2, rows2);
}
