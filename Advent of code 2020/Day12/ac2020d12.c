#include <stdio.h>
#include <math.h>

struct PointXY
{
    int X;
    int Y;
};

enum Cardinals
{
    North,
    East = 90,
    South = 180,
    West = 270
};

int main(void)
{
    FILE* file = fopen("day12.txt", "r");
    if (!file)
    {
        printf("Error: Can't open file!\n");
        return 1;
    }

    char command;
    int value;
    struct PointXY position;
    position.X = 0;
    position.Y = 0;
    int rotation = East;
    while (fscanf(file, "%c%d\n", &command, &value) == 2)
    {
        int cached_value = value;
        switch (command)
        {
            case 'N':
            {
                position.Y += value;
            } break;

            case 'E':
            {
                position.X += value;
            } break;

            case 'S':
            {
                position.Y -= value;
            } break;

            case 'W':
            {
                position.X -= value;
            } break;

            case 'L':
            {
                rotation = (rotation - value + 360) % 360;
            } break;

            case 'R':
            {
                rotation = (rotation + value) % 360;
            } break;

            case 'F':
            {
                if (rotation == North || rotation == South)
                {
                    value *= ((rotation == North) * 1 + -1 * (rotation == South));
                    position.Y += value;
                }
                else
                {
                    value *= ((rotation == East) * 1 + -1 * (rotation == West));
                    position.X += value;
                }
               
            } break;

            default:
                printf("Command not found!\n");
                break;
        }
    }

    unsigned long long int answer = abs(position.X) + abs(position.Y);
    printf("Answer : %lu. X : %d | Y : %d", answer, abs(position.X), abs(position.Y));

    fclose(file);
    return 0;
}