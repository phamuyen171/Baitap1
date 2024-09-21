#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <stack>
using namespace std;
void matranke(vector<vector<int>>& a, int& n, ifstream& inp) {
	inp >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(n);
		for (int j = 0; j < n; j++) {
			inp >> a[i][j];
		}
	}

}
void DFS(vector<vector<int>> a, int u, ofstream& out) {
	vector<bool> visited(a.size(), false);
	stack<int> st;
	st.push(u);
	while (!st.empty()) {
		int v = st.top(); st.pop();
		if (!visited[v]) {
			out << v << " ";
			visited[v] = true;
			for (int i = a[v].size() - 1; i > v; i--) {
				if (a[v][i] != 0 && !visited[i]) {
					st.push(i);
				}
			}
		}
	}
	out << endl;
}

bool ktLienthong(vector<vector<int>>& a, int n) {
	if (n <= 1) {
		return true;
	}

	vector<bool> visited(n, false);
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int d = q.front(); //d la dinh dang xet
		q.pop();
		visited[d] = true;

		for (int i = 0; i < n; i++) {
			if (a[d][i] != 0 && !visited[i]) {
				q.push(i);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			return false;
		}
	}

	return true;


}

int demTPLienthong(vector<vector<int>>& a, int n) {
	int dem = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			++dem;
			queue<int> q;
			q.push(i);

			while (!q.empty()) {
				int d = q.front();
				q.pop();
				visited[d] = true;

				for (int j = 0; j < n; j++) {
					if (a[d][j] == 1 && !visited[j]) {
						q.push(j);
					}
				}
			}
		}
	}
	return dem;
}

int main()
{
	int n;
	ifstream inp("input.txt");
	ofstream out("output.txt");
	vector<vector<int>> a;
	matranke(a, n, inp);
	if (ktLienthong(a, n)) out << "Do thi lien thong";
	else out << "Do thi khong lien thong";
	out << endl << "So thanh phan lien thong cua do thi: " << demTPLienthong(a, n);
	/*if (!ktLienthong(a, n))
	{
		out << endl << "Cac canh can them vao de do thi lien thong: ";
	}*/
	out << "Cac dinh cua do thi duyet theo DFS: ";
	DFS(a, 0, out); //Duyet bat dau tu dinh 0
	return 0;

}

