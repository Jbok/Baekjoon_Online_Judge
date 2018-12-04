#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[301][301];
    int result[10000];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    int k;
    cin >> k;
    for (int u = 0; u < k; u++){
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        for(int v = i; v <= x; v++){
            for(int w = j; w <= y; w++){
                result[u] += arr[v][w];
            }
        }
    }


    for (int i = 0; i < k; i++){
        cout << result[i] << endl;
    }
    

}
