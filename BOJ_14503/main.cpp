#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int N, M;
int r, c, d;
vvi field;

const auto dr = vi{ -1, 0, 1, 0 };
const auto dc = vi{ 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N >> M;
	field = vvi(N, vi(M));

	cin >> r >> c >> d;

	for (auto&& rows : field) {
		for (auto&& p : rows) {
			cin >> p;
		}
	}

	auto ans = int{ 0 };
	while (true) {
		if (0 == field[r][c]) {
			field[r][c] = 2;
			++ans;
			continue;
		}

		auto hasEmpty = bool{ false };
		for (auto s = 0; s < 4; ++s) {
			const auto sr = r + dr[s];
			const auto sc = c + dc[s];

			if (0 == field[sr][sc]) {
				hasEmpty = true;
				break;
			}
		}

		if (!hasEmpty) {
			const auto br = r - dr[d];
			const auto bc = c - dc[d];

			if (1 == field[br][bc]) {
				cout << ans;
				return 0;
			}

			r = br;
			c = bc;
			continue;
		}

		while (true) {
			--d;
			if (d < 0) {
				d += 4;
			}

			const auto fr = r + dr[d];
			const auto fc = c + dc[d];
			if (0 == field[fr][fc]) {
				r = fr;
				c = fc;
				break;
			}
		}
	}

	return 0;
}