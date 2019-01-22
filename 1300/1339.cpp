#include <iostream>
#include <string.h>

using namespace std;

typedef struct node
{
    char ch;
    int cnt;
}Node;

int check[30] = { 0, };

int main()
{
    int n;
    cin >> n;

    char str[11][11];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int ten = 1;
        for (int j = strlen(str[i])-1; j >= 0; j--)
        {
            check[str[i][j]-'A'] += ten;
            ten = ten * 10; 
        }
    }

    Node arr[30];
    int temp = 0;
    for (int i = 0; i < 30; i++)
    {
        if (check[i] != 0)
        {
            Node t;
            t.ch = 'A' + i;
            t.cnt = check[i];
            
            arr[temp++] = t;
        }
    }

    for (int i = 0; i < temp-1; i++)
    {
        for (int j = i+1; j <temp; j++)
        {
            Node t;
            if (arr[i].cnt < arr[j].cnt)
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }


    int number = 9;
    int sum = 0;
    for (int i = 0; i < temp; i++)
    {
        sum += number * arr[i].cnt;
        number--;
    }

    printf("%d", sum);

}