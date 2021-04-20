#include "Pathfinder.h"

string Pathfinder::toString()
{
  cout << "In toString" << endl;
  string out = "";
  for (int x = 0; x < SIZE; x++)
  {
      for (int y = 0; y < SIZE; y++)
      {
          for (int z = 0; z < SIZE; z++)
          {
          	out+= to_string(maze[x][y][z]);
						if (z < SIZE-1) out+=' ';
          }
          out+="\n";
      }	
		if (x < SIZE-1) out+="\n";
  }
  return (out);
}
void Pathfinder::createRandomMaze()
{
    cout << "In createRandomMaze" << endl;
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            for (int z = 0; z < SIZE; z++)
            {
                maze[x][y][z] = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[5][5][5] = 1; 
}
bool Pathfinder::importMaze(string file_name)
{
	cout << "In importMaze" << endl;
  cout << "importMaze from " << file_name << endl;
  ifstream file(file_name.c_str());
	string line ="";
  if (file.is_open())
  {
		for(int x = 0; x < SIZE; x++){  
   	for (int y = 0; y < SIZE; y++)
   	{ 
			line ="";
   	  if (getline(file, line)){
				if (line!=""){     	  
					istringstream ss(line);
   	  		for (int z = 0; z < SIZE; z++)
   	  		{
						string input;
						ss >> input;
						if (input=="1"||input=="0")maze[x][y][z]= stoi(input);
						else{ cout << "hi" << endl;return false;}
   	  		}
				}
			}
   	 }
		getline(file, line);
		}
  }
  return (true);
}
bool Pathfinder::findPath(int x, int y, int z)
{
	string out = "";
	out += to_string(x) +"," + to_string(y) + "," + to_string(z);
  P.push_back(out);
  if ((x < 0 || x >= SIZE) || 
    (y < 0 || y >= SIZE) || 
    (z < 0 || z >= SIZE)||
		maze[x][y][z]==2||
		maze[x][y][z]==0) {
		P.pop_back();
		return false;}
  maze[x][y][z] = 2;
  if (x == SIZE-1 && y == SIZE-1 && z == SIZE-1)
  {
    return true;
  }
  else if (findPath(x+1,y,z) || findPath(x-1,y,z) ||findPath(x,y+1,z) || findPath(x,y-1,z) || findPath(x,y,z+1) || findPath(x,y,z-1))
  {
    return true;  
  }
  else {
		P.pop_back();
		return false;}
}
vector<string> Pathfinder::solveMaze()
{
  cout << "In solveMaze" << endl;
	int copy_maze[5][5][5];
	for (int x = 0; x < SIZE; x++)
   {
     for (int y = 0; y < SIZE; y++)
     {
     	for (int z = 0; z < SIZE; z++)
     	{
				copy_maze[x][y][z]=maze[x][y][z];
     	}
     }	
   }
	findPath(0,0,0);
		for (int x = 0; x < SIZE; x++)
   {
     for (int y = 0; y < SIZE; y++)
     {
     	for (int z = 0; z < SIZE; z++)
     	{
				maze[x][y][z]=copy_maze[x][y][z];
     	}
     }	
   }
	return P;
}