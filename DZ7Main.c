#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INTMIN -32767

int sizeArrTask1 = 5;         // in data task1
int sizeArrTask2 = 10;        // in data task2
int sizeArrTask3[2] = {4, 5}; // in data task3
int sizeArrTask4 = 10;        // in data task4

void task1(int inSize);
void task2(int inSize);
void task3(int inSize[2]);
void task4();
void consoleWriteArr(int arrX[], int arrY[], int size); // task4
void consoleWriteArr(int arrX[], int arrY[], int size); // task4
bool isSort(int arr[], int size);                       // task4

void main()
{
    task1(sizeArrTask1);
    task2(sizeArrTask2);
    task3(sizeArrTask3);
    task4();
    return;
}

void task1(int inSize)
{
    if (inSize <= 0)
    {
        printf("err");
        return; //"err";
    }
    else
    {
        printf("\nExecutor Task1 DZ7\n");
    }

    int tempArr[inSize];
    float delta;

    for (int i = 0; i < inSize; i++)
    {
        tempArr[i] = (int)((inSize * i) + (i / inSize));
        printf("iteration arr = %d\n", tempArr[i]);
        delta += tempArr[i];
    }

    delta = delta / inSize;
    printf("delta = %f\n", delta);

    printf("End Task1\n");
}

void task2(int inSize)
{
    if (inSize <= 0)
    {
        printf("err");
        return; //"err";
    }
    else
    {
        printf("\nExecutor Task2 DZ7\n");
    }

    int tempArr[inSize];
    int volMax[2] = {INTMIN, 0}; //[0]-arg [1]-index

    for (int i = 0; i < inSize; i++)
    {
        tempArr[i] = (int)((inSize * i) + (i / inSize));
        printf("iteration arr = %d\n", tempArr[i]);
    }

    for (int y = 0; y < inSize; y++)
    {
        if (tempArr[y] > volMax[0])
        {
            volMax[0] = tempArr[y];
            volMax[1] = y;
        }
    }
    printf("index max =%d , vol max = %d\n", volMax[1], volMax[0]);

    printf("End Task2\n");
}

void task3(int inSize[2])
{
    float arrA[inSize[0]][inSize[1]];
    float arrB[inSize[0]];

    if (arrA == NULL)
    {
        printf("err");
        return; //"err";
    }
    else
    {
        printf("\nExecutor Task3 DZ7\n");
    }

    // full arr
    for (int i = 0; i < inSize[0]; i++)
    {
        for (int j = 0; j < inSize[1]; j++)
        {
            if ((i % 2) == 0)
            {
                arrA[i][j] = (i + j) - 5.5;
            }
            else
            {
                arrA[i][j] = (i + j) + 5.5;
            }
            printf("[%d][%d] = %f | ", i, j, arrA[i][j]);
        }
        printf("\n");
    }

    // control arr
    for (int i = 0; i < inSize[0]; i++)
    {
        arrB[i] = arrA[i][0];
        if (arrA[i][0] >= 0) // max
        {
            for (int j = 1; j < inSize[1]; j++)
            {
                if (arrA[i][j] > arrB[i])
                {
                    arrB[i] = arrA[i][j];
                }
            }
        }
        else // min
        {
            for (int j = 1; j < inSize[1]; j++)
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
        printf("arrB[%d] = %f\n", i, arrB[i]);
    }

    printf("End Task3\n");
}

void task4()
{
    printf("\nExecutor Task4 DZ7\n");

    int arrX[sizeArrTask4], arrY[sizeArrTask4];
    int input;
    int sizeContol[2] = {sizeArrTask4, sizeArrTask4}; //[0]-input sizeContol arrX,[1]-input sizeContol arrY
    int count = sizeArrTask4 * 2;

    printf("Input Digital\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &input);

        if (sizeContol[0] > 0)
        {
            sizeContol[0]--;
            arrX[i] = input;
            printf("Input Digital arrX: %d\n keep arrX: %d\n", arrX[i], sizeContol[0]);
        }
        else if (sizeContol[1] > 0)
        {
            sizeContol[1]--;
            arrY[i - sizeArrTask4] = input;
            printf("Input Digital arrY: %d\n keep arrY: %d\n", arrY[i - sizeArrTask4], sizeContol[1]);
        }
        else
        {
            break;
        }
    }
    consoleWriteArr(arrX, arrY, sizeArrTask4);
    nullTransformationArr(arrX, sizeArrTask4);
    nullTransformationArr(arrY, sizeArrTask4);
    consoleWriteArr(arrX, arrY, sizeArrTask4);

    printf("End Task4\n");
}

void consoleWriteArr(int arrX[], int arrY[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("arrX[%d] = %d | arrY[%d] = %d\n", i, arrX[i], i, arrY[i]);
    }
}

void nullTransformationArr(int arr[], int size)
{
    printf("\nTransormation Arr");
    if (isSort(arr, size))
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > 0)
            {
                arr[i] = 0; //
            }
        }
    }
}

bool isSort(int arr[], int size) // true -sortirovan, false -not sortirovan
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
