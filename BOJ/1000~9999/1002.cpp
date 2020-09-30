#include <iostream>
using namespace std;

int main(void)
{
    int num; // case 개수
    int x1, y1, x2, y2; // 좌표
    int r1, r2; // 떨어진 거리
    int d; // 좌표 간 거리

    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

        if(d == 0 && r1 == r2) cout << "-1" << endl;
        else if(d > (r1 + r2) * (r1 + r2) || d < (r1 - r2) * (r1 - r2)) cout << "0" << endl;
        else if(d == (r1 + r2) * (r1 + r2) || d == (r1 - r2) * (r1 - r2)) cout << "1" << endl;
        else cout << "2" << endl;
    }
    return 0;
}
