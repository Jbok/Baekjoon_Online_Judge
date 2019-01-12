#include <iostream>
#include <list>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    int *arr = new int[n+1];

    list<int> lt;

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
        lt.push_back(i);
    }

    int start, end, temp;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        temp = arr[start];

        for (int i = start + 1; i <= end; i++)
        {
            lt.remove(i);
        }
    }

    cout << lt.size() << endl;

}
