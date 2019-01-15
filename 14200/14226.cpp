    #include <iostream>
    #include <deque>

    using namespace std;

    typedef struct node
    {
        int out;
        int clip;
        int cnt;
    }Node;

    int check[2000][2000] = { 0, };

    int main()
    {
        int s;
        cin >> s;

        deque<Node> dq;

        check[1][0] = 1;

        Node now = { 1, 0, 0 };
        dq.push_back(now);

        int result;



        while (1)
        {
            now = dq.front();
            dq.pop_front();

            if (now.out == s)
            {
                result = now.cnt;
                break;
            }

            for (int i = 0; i < 3; i++)
            {
                Node next;
                if (i == 0)
                {
                    next = {now.out - 1, now.clip, now.cnt + 1};
                }
                else if (i == 1 && now.out != now.clip)
                {
                    next = {now.out, now.out, now.cnt + 1};
                }
                else if (now.clip != 0)
                {
                    next = {now.out + now.clip, now.clip, now.cnt + 1};
                }

                if (next.out > 0 && next.clip > 0 && next.out < 2000 && next.clip < 2000 && check[next.out][next.clip] == 0)
                {
                    dq.push_back(next);
                    check[next.out][next.clip] = 1;
                }
            }
        }

        printf("%d", result);

        return 0;
    }