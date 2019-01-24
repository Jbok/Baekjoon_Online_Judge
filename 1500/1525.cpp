#include <iostream>
#include <deque>
//#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef struct node
{
    int x;
    int cnt;
}Node;

int ccount = 0;

int main()
{
    int str[9];

    // 입력 받은 숫자 순서를 배열로 저장
    for (int i = 0; i < 9; i++)
    {
        cin >> str[i];
    }

    // 입력 받은 숫자를 순서대로 정수로 변환
    // ex> 
    // 1 2 3
    // 4 5 6
    // 7 8 0
    // ==> 123456780
    int result = 0;
    int ten = 100000000;
    for (int i = 0; i < 9; i++)
    {
        result += ten * str[i];
        ten = ten / 10;
    }

    // bfs를 위한 deque 선언
    deque<Node> dq;
    
    // 방문한 숫자 조합을 판단하기 위한 vector 선언
    //vector<int> v;
    set<int> s;

    // 시작 숫자
    Node start = { result, 0 };


    //v.push_back(result);
    s.insert(result);
    dq.push_back(start);
    
    while (1)
    {
        // bfs가 비어 있으면 -1 출력 => 답이 없는 경우 -1 출력
        if (dq.empty())
        {
            cout << -1;
            break;
        }

        // 현재 노드를 deque에서 뽑아온다
        Node now = dq.front();
        dq.pop_front();

        // 뽑은 숫자가 정렬이 되어 있으면 123456780이면 bfs의 count 값을 출력
        if (now.x == 123456780)
        {
            printf("%d", now.cnt);
            break;
        }

        // 뽑은 숫자가 정렬이 되어 있지 않다면
        // 0을 상하좌우의 숫자와 바꾸는 BFS
        // 상하좌우 4방향이기 때문에 4개로 반복
        for (int i = 0; i < 4; i++)
        {
            
            int arr[9];
            int zeroX;
            int tempX = now.x;


            // 현재 정렬된 숫자에서 0을 찾기 편하게 하기 위해서
            // 숫자를 다시 배열로 바꾼다
            // ex
            // 123450786 를 
            //   
            //   
            // 1 2 3    배열로 바꾼다
            // 4 5 0
            // 7 8 6  
            for (int i = 8; i >= 0; i--)
            {
                arr[i] = tempX % 10;
                tempX = tempX / 10;
                if (arr[i] == 0)
                    zeroX = i;
            }


            // 상하좌우로 가능한 경우에 값을 바꾼다
            // 1 2 3
            // 4 5 0
            // 7 8 6
            // 을 위에 있는 수와 바꾸는 것으로 예를들면
            // 1 2 0
            // 4 5 3
            // 7 8 6
            // 으로 바꾸고 이 작업을 for 문 안에서 4번 반복한다.
            if (i == 0 && zeroX != 0 && zeroX != 1 && zeroX != 2)
            {
                int temp = arr[zeroX - 3];
                arr[zeroX - 3] = 0;
                arr[zeroX] = temp;
            }

            if (i == 1 && zeroX != 2 && zeroX != 5 && zeroX != 8)
            {
                int temp = arr[zeroX + 1];
                arr[zeroX + 1] = 0;
                arr[zeroX] = temp;
            }

            if (i == 2 && zeroX != 0 && zeroX != 3 && zeroX != 6)
            {
                int temp = arr[zeroX - 1];
                arr[zeroX - 1] = 0;
                arr[zeroX] = temp;
            }

            if (i == 3 && zeroX != 6 && zeroX != 7 && zeroX != 8)
            {
                int temp = arr[zeroX + 3];
                arr[zeroX + 3] = 0;
                arr[zeroX] = temp;
            }

            // 배열로 저장된 배열을 다시 정수로 변환
            int rresult = 0;
            int tten = 100000000;
            for (int i = 0; i < 9; i++)
            {
                rresult += tten * arr[i];
                tten = tten / 10;
            }

            
            // 정수를 vector에서 찾고 만약 없는 경우에만 bfs를 진행
            //if (find(v.begin(), v.end(), rresult) == v.end())
            if (!s.count(rresult))
            {
                Node next = { rresult, now.cnt + 1 };
                //v.push_back(rresult);
                s.insert(rresult);
                dq.push_back(next);
            }
        }
    }
 

}