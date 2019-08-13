#include <iostream>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct cup
{
    int now;
    int max;
}Cup;

typedef struct node
{
    Cup a;
    Cup b;
    Cup c;
}Node;

int main()
{
    int aL, bL, cL;
    cin >> aL >> bL >> cL;

    Cup aStart = { 0, aL };
    Cup bStart = { 0, bL };
    Cup cStart = { cL, cL };

    Node start = { aStart, bStart, cStart };
    
    // convert
    int tten = 10;
    int ddigit = 1;
    int rresult = 0;

    set<int> s;
    vector<int> v;
    deque<Node> dq;
    dq.push_back(start);

    s.insert(cL);

    while(1)
    {
        if (dq.empty())
        {
            break;
        }

        Node now = dq.front();
        dq.pop_front();

        Cup aNow = now.a;
        Cup bNow = now.b;
        Cup cNow = now.c;

        if (aNow.now == 0)
        {
            v.push_back(cNow.now);
        }


        for (int i = 0; i < 6; i++)
        {
            Cup aNext = now.a;
            Cup bNext = now.b;
            Cup cNext = now.c;
            
            int remain;
            if (i == 0) // a -> b
            {
                remain = bNow.max - bNow.now;
                if (remain >= aNow.now)
                {
                    bNext.now += aNext.now;
                    aNext.now = 0;
                }
                else
                {
                    bNext.now = bNext.max;
                    aNext.now = aNow.now - remain;
                }
            }
            else if (i == 1)    // a -> c
            {
                remain = cNow.max - cNow.now;
                if (remain >= aNow.now)
                {
                    cNext.now += aNext.now;
                    aNext.now = 0;
                }
                else
                {
                    cNext.now = cNext.max;
                    aNext.now = aNow.now - remain;
                }                
            }
            else if (i == 2)    // b -> a
            {
                remain = aNow.max - aNow.now;
                if (remain >= bNow.now)
                {
                    aNext.now += bNext.now;
                    bNext.now = 0;
                }
                else
                {
                    aNext.now = aNext.max;
                    bNext.now = bNow.now - remain;
                }                
            }
            else if (i == 3)    // b -> c
            {
                remain = cNow.max - cNow.now;
                if (remain >= bNow.now)
                {
                    cNext.now += bNext.now;
                    bNext.now = 0;
                }
                else
                {
                    cNext.now = cNext.max;
                    bNext.now = bNow.now - remain;
                }                   
            }
            else if (i == 4)    // c -> a
            {
                remain = aNow.max - aNow.now;
                if (remain >= cNow.now)
                {
                    aNext.now += cNext.now;
                    cNext.now = 0;
                }
                else
                {
                    aNext.now = aNext.max;
                    cNext.now = cNow.now - remain;
                }                
            }
            else if (i == 5)    // c -> b
            {
                remain = bNow.max - bNow.now;
                if (remain >= cNow.now)
                {
                    bNext.now += cNext.now;
                    cNext.now = 0;
                }
                else
                {
                    bNext.now = bNext.max;
                    cNext.now = cNow.now - remain;
                }                
            }


            // convert
            int ten = 10;
            int digit = 1;
            int result = 0;

            int temp = cNext.now;
            result += (temp % ten) * digit;
            
            digit = digit * 10;
            temp = temp / 10;
            result += (temp % ten) * digit;
            
            digit = digit * 10;
            temp = temp / 10;
            result += (temp % ten) * digit;

            digit = digit * 10;
            temp = bNext.now;
            result += (temp % ten) * digit;
            
            digit = digit * 10;
            temp = temp / 10;
            result += (temp % ten) * digit;
            
            digit = digit * 10;
            temp = temp / 10;
            result += (temp % ten) * digit;

            digit = digit * 10;
            temp = aNext.now;
            result += (temp % ten) * digit;
            
            digit = digit * 10;
            temp = temp / 10;
            result += (temp % ten) * digit;
            
            digit = digit * 10;
            temp = temp / 10;
            result += (temp % ten) * digit;

            if (s.count(result) == 0)
            {
                s.insert(result);
                dq.push_back({ aNext, bNext, cNext });
            }
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

}