#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark {
	int posx, posy, speed, direct, size;
};

vector<Shark> now;
int R, C, M;
int answer = 0;

void fishing(int king_pos) {
	Shark target = Shark();
	target.posx = 102;
	target.size = 0;

	vector<Shark>::iterator it, target_pos;
	for (it = now.begin(); it != now.end(); it++) {
		if (it->posy == king_pos && target.posx > it->posx) {
			target = *it;
			target_pos = it;
		}			
	}	
	if (target.posx != 102) {
		now.erase(target_pos);
	}	
	answer += target.size;
}

void move() {
	for (auto &shark : now) {
		if (shark.direct == 1) {
			int move_dist = shark.speed % (2 * (R-1));
			shark.posx -= move_dist;
			if (shark.posx < 1) {
				shark.direct = 2;
				shark.posx = -(shark.posx-2);
			}
			if (shark.posx > R) {
				shark.direct = 1;
				shark.posx = R * 2 - shark.posx;
			}
		}
		else if (shark.direct == 2) {
			int move_dist = shark.speed % (2 * (R - 1));
			shark.posx += move_dist;
			if (shark.posx > R) {
				shark.direct = 1;
				shark.posx = R*2 - shark.posx;
			}
			if (shark.posx < 1) {
				shark.direct = 2;
				shark.posx = -(shark.posx - 2);
			}
		}
		else if (shark.direct == 3) {
			int move_dist = shark.speed % (2 * (C - 1));
			shark.posy += move_dist;
			if (shark.posy > C) {
				shark.direct = 4;
				shark.posy = C*2 - shark.posy;
			}
			if (shark.posy < 1) {
				shark.direct = 3;
				shark.posy = -(shark.posy - 2);
			}
		}
		else {
			int move_dist = shark.speed % (2 * (C - 1));
			shark.posy -= move_dist;
			if (shark.posy < 1) {
				shark.direct = 3;
				shark.posy = -(shark.posy-2);
			}
			if (shark.posy > C) {
				shark.direct = 4;
				shark.posy = C * 2 - shark.posy;
			}
		}
	}
}

bool compare(Shark A, Shark B) {
	if (A.posx == B.posx) {
		if (A.posy == B.posy) {
			return A.size > B.size;
		}
		else
			return A.posy < B.posy;
	}
	else
		return A.posx < B.posx;
}

void check() {
	if (now.size() <= 1) return;

	sort(now.begin(), now.end(), compare);
	int x = now[0].posx, y = now[0].posy;
	int target_size = now[0].size;

	vector<Shark>::iterator it;
	for (it = now.begin() + 1; it != now.end(); it++) {
		if (x != it->posx || y != it->posy) {
			x = it->posx;
			y = it->posy;
			target_size = it->size;			
			continue;
		}
		else {
			now.erase(it--);
		}
	}
}

int main(void) {
	cin >> R >> C >> M;
	
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		Shark shark;
		shark.posx = r;
		shark.posy = c;
		shark.speed = s;
		shark.direct = d;
		shark.size = z;
		now.push_back(shark);
	}

	for (int i = 1; i <= C; i++) {
		fishing(i);
		move();
		check();
	}
	
	cout << answer << "\n";
	return 0;
}