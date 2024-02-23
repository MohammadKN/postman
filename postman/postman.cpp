#include <iostream>
#include <cmath>

using namespace std;


class Point {
public:
    int x;
    int y;
    char tag;
    float distance;
    bool isChecked;
public:
    Point() {
        x = rand() % 15;
        y = rand() % 15;
    }
};



int main()
{

    srand(time(0));
    const int count = 10;
    Point point[count];
    Point postman;
    const int radius = 15;
    char map[radius][radius];
    char road[count];

    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            map[i][j] = '.';

        }
    }
    for (int i = 0; i < count; i++) {
        map[point[i].x][point[i].y] = (char)(i + 65);

        point[i].tag = (char)(i + 65);

    }
    map[postman.x][postman.y] = '@';

    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            cout << map[i][j] << "   ";
        }
        cout << endl << endl;
    }

    for (int j = 0; j < count; j++) {
        for (int i = 0; i < count; i++) {
            point[i].distance = sqrt(pow((point[i].x - postman.x), 2) + pow((point[i].y - postman.y), 2));
        }

        float min = point[0].distance;
        for (int i = 0; i < count; i++) {
            if (point[i].distance < min) min = point[i].distance;
        }
        for (int i = 0; i < count; i++) {
            if (point[i].distance == min) {
                map[point[i].x][point[i].y] = (char)j + 97;
                road[i] = point[i].tag;
                postman.x = point[i].x;
                postman.y = point[i].y;
                point[i].x = 100;
                point[i].y = 100;
            }
        }
    }
    cout << endl;

    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            cout << map[i][j] << "   ";
        }
        cout << endl << endl;
    }

    return 0;
}


