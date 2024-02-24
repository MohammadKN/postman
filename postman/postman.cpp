#include <iostream>
#include <cmath>
#include <json/json.h>

using namespace std;
using namespace Json;

Value decode(string jsontxt = "")
{
    Value root;
    Reader reader;
    bool parsingSuccessful = reader.parse(jsontxt, root);
    if (!parsingSuccessful)
    {
        cout << "Error parsing the string" << endl;
    }

    const Value tripps = root["trips"];

    for (int index = 0; index < tripps.size(); ++index)
    {
        cout << tripps[index] << endl;
    }
    return tripps;
}
string encode(string totDistance, string duration, string road)
{
    Value root;
    root = decode();
    Value trips;
    Value trip;

    trip["Driver Name"] = "MIKE";
    trip["Total Distance"] = totDistance;
    trip["Duration"] = duration;
    trip["Road"] = road;

    trips.append(trip);

    root["trips"] = trips;

    // Convert the JSON Value to a string
    ostringstream jsonStream;
    StreamWriterBuilder writer;
    string jsonString = writeString(writer, root);

    return jsonString;
}

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
    float totalDistance = 0;
    Point point[count];
    Point postman;
    string path = "            ";
    const int radius = 15;
    char map[radius][radius];

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
            if (point[i].distance < min) {
                min = point[i].distance;
                path[j] = map[point[i].x][point[i].y];
            }
        }
        //cout << min<<" ";
        totalDistance += min;
        for (int i = 0; i < count; i++) {
            if (point[i].distance == min) {
                map[point[i].x][point[i].y] = (char)j + 97;
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
    //cout << totalDistance<<"(km)"<< endl;
    //cout << "Estimated Time = " << (totalDistance / 50) + (count * 0.033) << "h";
    decode(encode(to_string(totalDistance), to_string((totalDistance / 50) + (count * 0.033)), path));

    return 0;
}


