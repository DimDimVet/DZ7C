#include <stdio.h>
#include <stdlib.h>
#define INTMIN -32767

int sizeArrTask1 = 5;         // in data task1
int sizeArrTask2 = 10;        // in data task2
int sizeArrTask3[2] = {4, 5}; // in data task3

void task1(int inSize);
void task2(int inSize);
void task3(int inSize[2]);
void consoleWriteData(int rezult, char *str);

int main()
{
    task1(sizeArrTask1);
    task2(sizeArrTask2);
    task3(sizeArrTask3);
    return 0;
}

void task1(int inSize)
{
    if (inSize <= 0)
    {
        consoleWriteData(0, "err");
        return; //"err";
    }
    else
    {
        consoleWriteData(0, "Executor Task1 DZ7");
    }

    int tempArr[inSize];
    float delta;

    for (int i = 0; i < inSize; i++)
    {
        tempArr[i] = (int)((inSize * i) + (i / inSize));
        consoleWriteData(tempArr[i], "iteration arr");
        delta += tempArr[i];
    }

    delta = delta / inSize;
    consoleWriteData(delta, "delta = ");
}

void task2(int inSize)
{
    if (inSize <= 0)
    {
        consoleWriteData(0, "err");
        return; //"err";
    }
    else
    {
        consoleWriteData(0, "Executor Task2 DZ7");
    }

    int tempArr[inSize];
    int volMax[2] = {INTMIN, 0}; //[0]-arg [1]-index

    for (int i = 0; i < inSize; i++)
    {
        tempArr[i] = (int)((inSize * i) + (i / inSize));
        consoleWriteData(tempArr[i], "iteration arr");
    }

    for (int y = 0; y < inSize; y++)
    {
        if (tempArr[y] > volMax[0])
        {
            volMax[0] = tempArr[y];
            volMax[1] = y;
        }
    }
    consoleWriteData(volMax[0], "vol max = ");
    consoleWriteData(volMax[1], "index max = ");
}

void task3(int inSize[2])
{
    int arrA[inSize[0]][inSize[1]];
    int arrB[inSize[0]];

    if (arrA == NULL)
    {
        consoleWriteData(0, "err");
        return; //"err";
    }
    else
    {
        consoleWriteData(0, "Executor Task3 DZ7");
    }

    // наполним массив
    for (int i = 0; i < inSize[0]; i++)
    {
        for (int j = 0; j < inSize[1]; j++)
        {
            if ((i % 2) == 0)
            {
                arrA[i][j] = ~(i * j * 5);
            }
            else
            {
                arrA[i][j] = i * j * 5;
            }
        }
    }

    // проверим
    for (int i = 0; i < inSize[0]; i++)
    {
        arrB[i] = arrA[i][0];
        if (arrA[i][0] >= 0) // max
        {
            for (int j = 1; j < 5; j++)
            {
                if (arrA[i][j] > arrB[i])
                {
                    arrB[i] = arrA[i][j];
                }
            }
        }
        else // min
        {
            for (int j = 1; j < 5; j++)
            {
                if (arrA[i][j] < arrB[i])
                {
                    arrB[i] = arrA[i][j];
                }
            }
        }
    }

    for (int i = 0; i < inSize[0]; i++)
    {
        consoleWriteData(i, "index arrB ");
        consoleWriteData(arrB[i], "vol = ");
    }
}

void consoleWriteData(int rezult, char *str)
{
    if (str == NULL)
    {
        char rezultStr[] = {};
        sprintf(rezultStr, "%d", rezult);
        printf("%s\n", rezultStr);
    }
    else
    {
        char rezultStr[20] = {};
        sprintf(rezultStr, "%s %d", str, rezult);
        printf("%s\n", rezultStr);
    }
}