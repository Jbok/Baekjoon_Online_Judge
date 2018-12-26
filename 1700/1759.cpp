#include <iostream>

using namespace std;

void Combination(int l, int c, int end, int depth, char arr[], char result[], int flag[])
{
    if (l == depth)
    {
        int consonant = 0;
        int vowel = 0;

        for (int i = 0; i < l; i++)
        {
            if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u')
                vowel++;
            else
                consonant++;
        }

        if (vowel < 1 || consonant < 2)
            return;

        for (int i = 0; i < l; i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }

    for (int i = end; i < c; i++)
    {
        result[depth] = arr[i];
        flag[i] = 1;
        Combination(l, c, i+1, depth+1, arr, result, flag);
        flag[i] = 0;
    }
}

int main()
{
    int l, c;
    cin >> l;
    cin >> c;

    char *arr = new char[c];
    char *result = new char[c];
    int *flag = new int[c];

    for (int i = 0; i < c; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < c-1; i++)
    {
        for (int j = i+1; j < c; j++)
        {
            if (arr[i] > arr[j])
            {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }


    Combination(l, c, 0, 0, arr, result, flag);

}
