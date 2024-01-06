/*
ID: avelynj1
TASK: test
LANG: C++                 
*/

#include <iostream>
using namespace std;

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 

int calc(int pos, int arr[][3], int N) {
    int point = 0;
    for(int i = 0; i < N; i++){
        if (pos == arr[i][0]) {
            pos = arr[i][1];
        }
        else if (pos == arr[i][1]) {
            pos = arr[i][0];
        }
        if (pos == arr[i][2]) {
            point++;
        }
    }
    return point;
}
int main() {
    IO("shell");
    int N;
    cin >> N;
    int arr[N][3];
    for(int i = 0; i < N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; 
    }
    
    cout << max(calc(3,arr,N), max(calc(2,arr,N), calc(1,arr,N))); 
    return 0;
}
