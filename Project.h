#ifndef PROJECT_H
#define PROJECT_H
constexpr auto n = 7; //defining maze size
class graph
{
public:
	graph(); //constructor
	~graph(); //destructor
	bool ischeck(int maze[n][n],int x, int y);  //function to check whether x and y are valid index for maze
	void display(int** M, int r, int c, char x); //function to display
	int BFS(int current, int end); //function to find shortest path

	int r; //rows
	int c; //columns
	int** M;
	int* curr;
	int A;
	list < int >* adj; //dynamic array for adj list

};
class character
{
public:
	character(); //default constructor 
	~character(); //default destructor 

};
class map
{
public:
	map(); //default constructor 
	~map(); //default destructor 

};

#endif