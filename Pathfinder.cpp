#include "Pathfinder.h"

string Pathfinder::toString()
{
    cout << "In toString" << endl;
    stringstream ss;
    for (int x = 0; x <= 9; x++)
    {
        for (int y = 0; y <= 9; y++)
        {
            for (int z = 0; z <= 9; z++)
            {
                ss << maze[x][y][z] << " ";
            }
            ss << endl;
        }
        ss << endl;
    }
    return (ss.str());
}
void Pathfinder::createRandomMaze()
{
    cout << "In createRandomMaze" << endl;
    for (int x = 0; x <= 9; x++)
    {
        for (int y = 0; y <= 9; y++)
        {
            for (int z = 0; z <= 9; z++)
            {
                maze[x][y][z] = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[9][9][9] = 1;
}
bool Pathfinder::importMaze(string file_name)
{
    cout << "In importMaze" << endl;
    cout << "importMaze from " << file_name << endl;
    ifstream file(file_name.c_str());
    if (file.is_open())
    {
        string line;
        int row_count = 0;
        for (int x = 0; x <= 9; x++)
        {
            getline(file, line);
            stringstream ss(line);
            for (int y = 0; y <= 9; y++)
            {
                for (int z = 0; z <= 9; z++)
                {
                }
            }
        }
    }
    return (true);
}
bool Pathfinder::findPath(int x, int y, int z)
{
    cout << "in findPath" << endl;
    stringstream ss;
    ss << x << "," << y << "," << z;
    P.push_back(ss.str());
    ss.str(string());
    if ((x < 0 || x >= X_SIZE) || 
        (y < 0 || y >= Y_SIZE) || 
        (z < 0 || z >= Z_SIZE)) return false;
    
    if (x == 9 && y == 9 && z == 9)
    {
        return true;
    }
    else if (maze[x + 1][y][z] == 1 || maze[x - 1][y][z] == 1 || maze[x][y + 1][z] == 1 || maze[x][y - 1][z] == 1 || maze[x][y][z + 1] == 1 || maze[x][y][z - 1] == 1)
    {
        maze[x][y][z] = 2;
    }
    else return false;
}
vector<string> Pathfinder::solveMaze()
{
    cout << "In solveMaze" << endl;
}