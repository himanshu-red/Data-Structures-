#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rowMin = 0;
    int colMin = 0;
    int rowMax =  matrix.size() - 1;
    int colMax = matrix[0].size() - 1;
    int prevSize = 0;
    bool flag = false;
    vector<int> v;
    cout << colMax << " " << rowMax << endl;
    while (1)
    {
        cout << "RowMin : " << rowMin << endl;
        cout << "ColMax : " << colMax << endl;
        cout << "rowmax : " << rowMax << endl;
        cout << "ColMin :  " << colMin << endl
             << endl;

        for (int i = colMin; i <= colMax; i++)
        {
            v.push_back(matrix[rowMin][i]);
        }
        rowMin++;
        for (int i = rowMin; i <= rowMax; i++)
        {
            v.push_back(matrix[i][colMax]);
        }
        colMax--;
        for (int i = colMax; i >= colMin; i--)
        {
            v.push_back(matrix[rowMax][i]);
        }
        rowMax--;
        for (int i = rowMax; i >= rowMin; i--)
        {
            v.push_back(matrix[i][colMin]);
        }
        colMin++;
        if (prevSize == v.size())
            break;
        else
            prevSize = v.size();
    }
    return v;
}
void printVec(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    vector<vector<int>> v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    // cout << "RowSize : " << v.size() << endl;
    // cout << "ColSize : " << v[0].size() << endl;
    vector<int> ret = spiralOrder(v);
    printVec(ret);
}
