// Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void DFS(vector<vector<int>> matrix, int  u, int n)
{
	
	static vector<int> visited( n, 0 );
	if (visited[u] == 0)
	{
		cout << u << " ";
		visited[u] = 1;

		for (int j = 1; j < n; j++)
		{
			if (matrix[u][j] == 1 && visited[j] == 0)
			{
				DFS(matrix, j, n);
			}
		}
	}
}

void BFS(vector<vector<int>> matrix, int  u, int n)
{
	
	static vector<int> visited(n, 0);
	static queue<int> q;
	cout << u << " ";
	visited[u] = 1;
	q.push(u);

	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for (int j = 1; j < n; j++)
		{
			if (matrix[u][j] == 1 && visited[j] == 0)
			{
				cout << j << " ";
				visited[j] = 1;
				q.push(j);
			}
		}
	}
}


in

int main() 
{
	vector<vector<int>> matrix = {
		{0,0,0,0,0,0,0},                 
		{0,0,1,1,0,0,0},                 
		{0,1,0,0,1,0,0},                 
		{0,1,0,0,1,0,0},                 
		{0,0,1,1,0,1,1},                 
		{0,0,0,0,1,0,0},                 
		{0,0,0,0,1,0,0} 
	};    

	cout << "DFS is : ";
	DFS(matrix, 4, 7);

	cout << endl;
	cout << "BFS is : ";
	BFS(matrix, 1, 7)
}


