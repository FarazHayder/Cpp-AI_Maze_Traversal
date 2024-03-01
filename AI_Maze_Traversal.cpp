#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

const int rows = 9;
const int columns = 16;

void runMouse(int, int, int, int, int[][16], int[][16]);

int main()
{

	int mouseshape = 99;
	int cheeseshape = 55;
	int wallshape = -1;
	int boundary = 11;

	int maze[rows][columns] = {
		{boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary},
		{boundary, 0, 0, 0, wallshape, 0, 0, 0, wallshape, 0, wallshape, 0, 0, 0, 0, boundary},
		{boundary, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, wallshape, boundary},
		{boundary, wallshape, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, wallshape, boundary},
		{boundary, 0, 0, 0, 0, 0, wallshape, 0, 0, 0, wallshape, 0, 0, 0, 0, boundary},
		{boundary, 0, wallshape, wallshape, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, 0, boundary},
		{boundary, 0, wallshape, wallshape, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, 0, boundary},
		{boundary, cheeseshape, wallshape, 0, 0, 0, 0, 0, wallshape, 0, 0, 0, wallshape, wallshape, mouseshape, boundary},
		{boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary},
	};

	int dmaze[rows][columns] = {
		// displaymaze
		{boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary},
		{boundary, 0, 0, 0, wallshape, 0, 0, 0, wallshape, 0, wallshape, 0, 0, 0, 0, boundary},
		{boundary, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, wallshape, boundary},
		{boundary, wallshape, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, wallshape, boundary},
		{boundary, 0, 0, 0, 0, 0, wallshape, 0, 0, 0, wallshape, 0, 0, 0, 0, boundary},
		{boundary, 0, wallshape, wallshape, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, 0, boundary},
		{boundary, 0, wallshape, wallshape, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, 0, wallshape, wallshape, 0, boundary},
		{boundary, cheeseshape, wallshape, 0, 0, 0, 0, 0, wallshape, 0, 0, 0, wallshape, wallshape, mouseshape, boundary},
		{boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary, boundary},
	};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(2) << setfill('0') << maze[i][j] << " ";
		}
		cout << endl;
	}

	runMouse(mouseshape, cheeseshape, wallshape, boundary, maze, dmaze);

	return 0;
}

void runMouse(int mouseshape, int cheeseshape, int wallshape, int boundary, int maze[][16], int dmaze[][16])
{

	int t1 = 0, t2 = 0, i = 7, j = 14, a = 0, b = 0;
	char x;
	while (maze[a][b] != maze[7][1])
	{

		srand(time(0));
		x = (rand() % 4) + 1;
		Sleep(0.4);
		system("cls");

		switch (x)
		{
		case 1:
		{
			--t1;
			a = i + t1, b = j + t2;
			if (maze[a][b] == 0 || maze[a][b] == cheeseshape)
			{
				maze[a][b] = mouseshape;
				dmaze[a][b] = mouseshape;
				if (maze[a + 1 + 1][b] == 0 || maze[a + 1 - 1][b] == 0 || maze[a + 1][b + 1] == 0 || maze[a + 1][b - 1] == 0 || maze[a + 1 + 1][b] == 01 || maze[a + 1 - 1][b] == 01 || maze[a + 1][b + 1] == 01 || maze[a + 1][b - 1] == 01)
				{
					maze[a + 1][b] = 01;
					dmaze[a + 1][b] = 00;
				}
				else
				{
					maze[a + 1][b] = 02;
					dmaze[a + 1][b] = 00;
				}
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
			else if (maze[a][b] == 01)
			{
				if (maze[a + 1 + 1][b] == 0 || maze[a + 1 - 1][b] == 0 || maze[a + 1][b + 1] == 0 || maze[a + 1][b - 1] == 0 || maze[a + 1 + 1][b] == cheeseshape || maze[a + 1 - 1][b] == cheeseshape || maze[a + 1][b + 1] == cheeseshape || maze[a + 1][b - 1] == cheeseshape)
				{
					++t1;
					a = i + t1, b = j + t2;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
				else
				{
					maze[a][b] = mouseshape;
					dmaze[a][b] = mouseshape;
					maze[a + 1][b] = 02;
					dmaze[a + 1][b] = 00;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
			}
			else
			{
				++t1;
				a = i + t1, b = j + t2;
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
		}
		case 2:
		{
			++t1;
			a = i + t1, b = j + t2;
			if (maze[a][b] == 0 || maze[a][b] == cheeseshape)
			{
				maze[a][b] = mouseshape;
				dmaze[a][b] = mouseshape;
				if (maze[a - 1 + 1][b] == 0 || maze[a - 1 - 1][b] == 0 || maze[a - 1][b + 1] == 0 || maze[a - 1][b - 1] == 0 || maze[a - 1 + 1][b] == 01 || maze[a - 1 - 1][b] == 01 || maze[a - 1][b + 1] == 01 || maze[a - 1][b - 1] == 01)
				{
					maze[a - 1][b] = 01;
					dmaze[a - 1][b] = 00;
				}
				else
				{
					maze[a - 1][b] = 02;
					dmaze[a - 1][b] = 00;
				}
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
			else if (maze[a][b] == 01)
			{
				if (maze[a - 1 + 1][b] == 0 || maze[a - 1 - 1][b] == 0 || maze[a - 1][b + 1] == 0 || maze[a - 1][b - 1] == 0 || maze[a - 1 + 1][b] == cheeseshape || maze[a - 1 - 1][b] == cheeseshape || maze[a - 1][b + 1] == cheeseshape || maze[a - 1][b - 1] == cheeseshape)
				{
					--t1;
					a = i + t1, b = j + t2;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
				else
				{
					maze[a][b] = mouseshape;
					dmaze[a][b] = mouseshape;
					maze[a - 1][b] = 02;
					dmaze[a - 1][b] = 00;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
			}
			else
			{
				--t1;
				a = i + t1, b = j + t2;
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
		}
		case 3:
		{
			--t2;
			a = i + t1, b = j + t2;
			if (maze[a][b] == 0 || maze[a][b] == cheeseshape)
			{
				maze[a][b] = mouseshape;
				dmaze[a][b] = mouseshape;
				if (maze[a + 1][b + 1] == 0 || maze[a - 1][b + 1] == 0 || maze[a][b + 1 + 1] == 0 || maze[a][b - 1 + 1] == 0 || maze[a + 1][b + 1] == 01 || maze[a - 1][b + 1] == 01 || maze[a][b + 1 + 1] == 01 || maze[a][b - 1 + 1] == 01)
				{
					maze[a][b + 1] = 01;
					dmaze[a][b + 1] = 00;
				}
				else
				{
					maze[a][b + 1] = 02;
					dmaze[a][b + 1] = 00;
				}
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
			else if (maze[a][b] == 01)
			{
				if (maze[a + 1][b + 1] == 0 || maze[a - 1][b + 1] == 0 || maze[a][b + 1 + 1] == 0 || maze[a][b - 1 + 1] == 0 || maze[a + 1][b + 1] == cheeseshape || maze[a - 1][b + 1] == cheeseshape || maze[a][b + 1 + 1] == cheeseshape || maze[a][b - 1 + 1] == cheeseshape)
				{
					++t2;
					a = i + t1, b = j + t2;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
				else
				{
					maze[a][b] = mouseshape;
					dmaze[a][b] = mouseshape;
					maze[a][b + 1] = 02;
					dmaze[a][b + 1] = 00;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
			}
			else
			{
				++t2;
				a = i + t1, b = j + t2;
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
		}
		case 4:
		{
			++t2;
			int a = i + t1, b = j + t2;
			if (maze[a][b] == 0 || maze[a][b] == cheeseshape)
			{
				maze[a][b] = mouseshape;
				dmaze[a][b] = mouseshape;
				if (maze[a + 1][b - 1] == 0 || maze[a - 1][b - 1] == 0 || maze[a][b + 1 - 1] == 0 || maze[a][b - 1 - 1] == 0 || maze[a + 1][b - 1] == 01 || maze[a - 1][b - 1] == 01 || maze[a][b + 1 - 1] == 01 || maze[a][b - 1 - 1] == 01)
				{
					maze[a][b - 1] = 01;
					dmaze[a][b - 1] = 00;
				}
				else
				{
					maze[a][b - 1] = 02;
					dmaze[a][b - 1] = 00;
				}
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
			else if (maze[a][b] == 01)
			{
				if (maze[a + 1][b - 1] == 0 || maze[a - 1][b - 1] == 0 || maze[a][b + 1 - 1] == 0 || maze[a][b - 1 - 1] == 0 || maze[a + 1][b - 1] == cheeseshape || maze[a - 1][b - 1] == cheeseshape || maze[a][b + 1 - 1] == cheeseshape || maze[a][b - 1 - 1] == cheeseshape)
				{
					--t2;
					a = i + t1, b = j + t2;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
				else
				{
					maze[a][b] = mouseshape;
					dmaze[a][b] = mouseshape;
					maze[a][b - 1] = 02;
					dmaze[a][b - 1] = 00;
					for (int k = 0; k < rows; k++)
					{
						for (int l = 0; l < columns; l++)
						{
							cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
						}
						cout << endl;
					}
					break;
				}
			}
			else
			{
				--t2;
				a = i + t1, b = j + t2;
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
					{
						cout << setw(2) << setfill('0') << dmaze[k][l] << " ";
					}
					cout << endl;
				}
				break;
			}
		}
		}
	}
	cout << "Congratulations! The mouse has reached to the cheese.";
}