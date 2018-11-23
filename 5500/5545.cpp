#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main(){

    int topping;
    cin >> topping;

    int doughPrice;
    cin >> doughPrice;

    int toppingPrice;
    cin >> toppingPrice;

    int doughCalorie;
    cin >> doughCalorie;

    int toppingCalorie[100];
    for (int i = 0; i < topping; i++){
        cin >> toppingCalorie[i];
    }

    sort(toppingCalorie, toppingCalorie + topping, greater<int> ());

    int bestPizza = doughCalorie / doughPrice;

    int calorieSum = 0;
    for (int i = 0; i < topping; i++){
        int temp;
        calorieSum += toppingCalorie[i];

        temp = (doughCalorie + calorieSum) / (doughPrice + (i+1)*toppingPrice);
        if (temp >= bestPizza){
            bestPizza = temp;
        }else{
            break;
        }
    }

    cout << bestPizza << endl;

}
