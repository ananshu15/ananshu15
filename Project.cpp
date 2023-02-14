#include<iostream>
#include <stdio.h>
#include<fstream>
#include<sstream>
#include<vector>
#include"PROJECT.h"
#include<queue>
#include <list>
using namespace std;
int choose; //user to select
const int r = 7; //size of map
const int c = 7; //size of map


map::map()
{

}
map::~map()
{

}
character::character()
{

}
character::~character()
{

}

graph::graph() //default constructor
{
	M = new int*[r];
	for (int i = 0; i < r; i++)
		curr = new int[r];
	for (int i = 0; i < r;i++)
		curr[i] = 0;
}

graph::~graph() //default destructor 
{
	delete[]M;
	delete[]curr;
}

bool graph::ischeck(int maze[n][n], int x, int y) // function to check whether x and y are valid index for maze
{
	if (x >= 0 && x < n && y >= 0 &&  y < n && maze[x][y]==1) //check whether x and y are inside maze
		return true;
	else
	return false;
}

void graph::display(int** M, int r, int c, char x)
{

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char c = ' ';
			switch (M[i][j])
			{
			case 0: c = '#'; break; //represents mountains
			case 1: c = x; break;   //represents for target
			case 2: c = 'F';break;  //represents for forest
			case 3: c = 'T';break;  //represents for tunnel
			case 4: c = 'o';break;  //represents for character
			}
			cout << c;
		}
		cout << endl;
	}
}

int graph::BFS(int current, int end) //function to find shortest path
{
	if (current == end)  //base model
		return 0;
	int* curr = new int[A];
	for (int i = 0; i < A; i++) //setting initial distance to -1
		curr[i] = -1;
	list<int>queue; //creating queue
	queue.push_back(current);
	list<int>::iterator i;

	while (!queue.empty())
	{
		current = queue.front(); //dequeuing 
		queue.pop_front();

		for (i = adj[current].begin(); i != adj[current].end(); ++i) //getting adj vertice of dequeue vertex 
		{
			
			if (curr[*i] < 0 || curr[*i] > curr[current] + 1)  //if adj not visited or not found then update and enqueue it
			{
				curr[*i] = curr[current] + 1;
				queue.push_back(*i);
			}
		}
	}


	return curr[end]; //returns shoretst path
}



// Example to display a matrix in the console and refresh what is displayed
int main()
{

	cout << "CSci 115 - Project" << endl;
      graph g;
	 // int a,b;
	ifstream myfile; //read a file
	while (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5) //menu for user to select
	{
		cout << "Select the map" << endl;
		cout << "please enter 1,2,3,4 or 5"<<endl; //five different maps
		cin >> choose;
	}
	if (choose == 1) //1 for map1
	{
		myfile.open("map.txt");
	}
	if (choose == 2) //2 for map2
	{
		myfile.open("map2.txt");
	}
	if (choose == 3) //3 for map3
	{
		myfile.open("map3.txt");
	}
	if (choose == 4) //4 for map4
	{
		myfile.open("map4.txt");
	}
	else
	{
		myfile.open("map5.txt"); //5 for map5
	}
	myfile >> r >> c;
	char maap[r][c]{};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			myfile >> maap[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << maap[i][j];
		}
		cout << endl;
	}
	// Allocate memory
	int** M = new int* [r];
	for (int i = 0; i < r; i++)
		M[i] = new int[c];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			M[i][j] = 1;

	for (int i = 0; i < r; i++)
		M[i][i] = 0;

	g.display(M, r, c, 'x');

	bool finish = false;
	while (!finish)
	{
		char input;
		cin >> input;
		system("cls"); // clear the commandline (to refresh the screen)
		switch (input)
		{
		case 'q': finish = true; break;
		case 'a': g.display(M, r, c, 'a'); break;
		case 'b': g.display(M, r, c, 'b'); break;
		}
	}

	// Free memory
	for (int i = 0; i < r; i++)
		delete[] M[i];
	delete[] M;
	return 0;
}
