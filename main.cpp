#include <iostream>
#include <vector>
using namespace std;

vector<int> structVec;


void makeMap(){
    structVec.push_back(0);
    int point = 0;
    while (true){
        if(structVec[point] > 100000000)
            break;
        structVec.push_back(structVec[point] + point + 1);
        point++;
    }
}

int binarySearch(int left, int right, int point){
    if(left == right)
        return left;
    if(structVec[(right + left) / 2] == point)
        return (right + left) / 2;
    else if(structVec[(right + left) / 2] > point)
        return binarySearch(left, (right + left) / 2, point);
    else
        return binarySearch((right + left) / 2 + 1 , right, point);



}

void drawMap(){
    cout << "先輸出Map看一下" << endl;
    for(int i = 1; i < structVec.size(); i++)
    {
        cout << structVec[i] << " ";
        if(i % 10 == 0)
            cout << endl;
    }
}

int main() {
    makeMap();
//    drawMap();
    int input;

    while(cin >> input){
        if(!input)
            break;

        int target = binarySearch(1, structVec.size() - 1, input);

//        cout << "tartget = " << target << endl;
        if(input == structVec[target])
            cout << target + 1 << " " << target + 1 << endl;
        else
            cout << structVec[target] - input << " " << target << endl;
    }
    return 0;
}
