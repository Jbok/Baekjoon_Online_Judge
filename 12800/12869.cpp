#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int hp[3] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> hp[i];
    }

    deque<int> dq;
    
    dq.push_back(hp[0]);
    dq.push_back(hp[1]);
    dq.push_back(hp[2]);
    dq.push_back(0);

    while (1)
    {
        if (dq.empty())
            break;
        
        int tempHP[3] = { 0, };
        
        int flag = 0;
        for (int i = 0; i < 3; i++)
        {
            tempHP[i] = dq.front();
            if (tempHP[i] > 0)
                flag = 1;
            dq.pop_front();
        }

        int cnt = dq.front();
        dq.pop_front();

        if (flag == 0)
        {
            printf("%d\n", cnt);
            break;
        }

        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
            {
                dq.push_back(tempHP[0] - 9);
                dq.push_back(tempHP[1] - 3);
                dq.push_back(tempHP[2] - 1);
            }
            else if (i == 1)
            {
                dq.push_back(tempHP[0] - 9);
                dq.push_back(tempHP[1] - 1);
                dq.push_back(tempHP[2] - 3);
            }
            else if (i == 2)
            {
                dq.push_back(tempHP[0] - 3);
                dq.push_back(tempHP[1] - 9);
                dq.push_back(tempHP[2] - 1);
            }
            else if (i == 3)
            {
                dq.push_back(tempHP[0] - 3);
                dq.push_back(tempHP[1] - 1);
                dq.push_back(tempHP[2] - 9);
            }
            else if (i == 4)
            {
                dq.push_back(tempHP[0] - 1);
                dq.push_back(tempHP[1] - 3);
                dq.push_back(tempHP[2] - 9);
            }
            else
            {
                dq.push_back(tempHP[0] - 1);
                dq.push_back(tempHP[1] - 9);
                dq.push_back(tempHP[2] - 3);
            }
            dq.push_back(cnt+1);
        }
    }

}
