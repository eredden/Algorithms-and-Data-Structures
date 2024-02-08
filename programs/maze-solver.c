typedef struct
{
    int x;
    int y;
} point_t;

int walk(char **maze, int maze_x_length, int maze_y_length, 
        int **seen, char wall, point_t curr, point_t end)
{
    if (curr.x < 0 || curr.x >= maze_x_length ||
        curr.y < 0 || curr.y >= maze_y_length)
    {
        return -1;
    }

    if (maze[curr.y][curr.x] == wall)
    {
        return -1;
    }

    if (curr.x == end.x && curr.y == end.y)
    {
        return 0;
    }

    if (seen[curr.y][curr.x])
    {
        return -1;
    }
}

// note: needs to be adjusted to return list
point_t solve(char maze[][], int maze_x_length, int maze_y_length, 
            int **seen, char wall, point_t start, point_t end)
{

}

int main(void)
{
    char maze[3][7] = {
        {'#', '#', '#', '#', '#', 'E', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', 'S', '#', '#', '#', '#', '#'}
    };

    int maze_x_length = sizeof(maze[0]) - sizeof(maze[0][0]);
    int maze_y_length = sizeof(maze) - sizeof(maze[0]);

    int seen[3][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    
    char wall = '#';

    point_t start;
    start.x = 1;
    start.y = 2;

    point_t end;
    end.x = 5;
    end.y = 0;

    // solve(maze, maze_x_length, maze_y_length, seen, wall, start, end);

    return 0;
}
