#include <iostream>

using namespace std;

int main(void)
{
    int N, min, max, num;

    cin >> N;

    cin >> min;
    max = min;

    for(int i = 1; i < N; i++)
    {
        cin >> num;
        min = min < num ? min : num;
        max = max > num ? max : num;
    }
    cout << min << " " << max << endl;
    return 0;
}
