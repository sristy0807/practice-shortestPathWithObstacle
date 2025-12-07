#define MAX 1000

#include <iostream>

using namespace std;

int M;
int N;
int K;

int grid[MAX][MAX];
bool visited[MAX][MAX][MAX];
int qDist[MAX];

int qX[MAX];
int qY[MAX];
int qK[MAX];

int dirX[4] = { -1,0,0,1 };
int dirY[4] = { 0,-1,1,0 };

int shortestPath() {
	int head = 0;
	int tail = 0;
	
	qX[head] = 0;
	qY[head] = 0;
	qK[head] = 0;
	qDist[head] = 0;
	head++;

	while (tail < head) {
		int r = qX[tail];
		int c = qY[tail];
		int k = qK[tail];
		int d = qDist[tail];

		tail++;

		if (r == M - 1 && c == N - 1) {
			return d;
		}

		for (int i = 0; i < 4; i++)
		{
			int nR = r + dirX[i];
			int nC = c + dirY[i];
			
			if (nR >= M || nC >= N || nR<0 || nC<0) continue;
			
			if (grid[nR][nC] == 1) {
				k = k + 1;
			}

			if (k > K) continue;
			
			if (visited[nR][nC][k]) continue;
			
			visited[nR][nC][k] = true;
			qX[head] = nR;
			qY[head] = nC;
			qK[head] = k;
			qDist[head] = d + 1;

			head++;
		}
	}

	return -1;
}

int main() {
	cin >> M;
	cin >> N;
	cin >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int l = 0; l < K; l++)
			{
				visited[i][j][l] = false;
			}
		}
	}

	int sp = shortestPath();

	cout << sp<<endl;
}