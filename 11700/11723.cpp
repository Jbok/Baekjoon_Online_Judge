#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;

    char myString[10];

    int arr[21] = {0, };

    cin >> n;

    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", myString);

        if (strcmp(myString, "add") == 0)
        {
            scanf("%d", &temp);
            arr[temp] = 1;
        }
        else if (strcmp(myString, "remove") == 0)
        {
            scanf("%d", &temp);
            arr[temp] = 0;
        }
        else if (strcmp(myString, "check") == 0)
        {
            scanf("%d", &temp);
            if (arr[temp] == 1)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if (strcmp(myString, "toggle") == 0)
        {
            scanf("%d", &temp);
            if (arr[temp] == 0)
            {
                arr[temp] = 1;
            }
            else
            {
                arr[temp] = 0;
            }
        }
        else if (strcmp(myString, "all") == 0)
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = 1;
            }
        }
        else if (strcmp(myString, "empty") == 0)
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = 0;
            }
        }
    }
}
