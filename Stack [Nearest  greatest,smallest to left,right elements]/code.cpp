#include <bits/stdc++.h>
using namespace std;
vector<int> getNearestGreatestToRight(vector<int> v)
{
    stack<int> stack;
    vector<int> data;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (data.size() == 0)
        {
            stack.push(v[i]);
            data.push_back(-1);
        }
        else
        {
            while (!(stack.empty()) && stack.top() < v[i])
                stack.pop();
            if (stack.empty())
                data.push_back(-1);
            else
                data.push_back(stack.top());
            stack.push(v[i]);
        }
    }
    reverse(data.begin(), data.end());
    return data;
}
vector<int> getNearestGreatestToLeft(vector<int> v)
{
    stack<int> stack;
    vector<int> data;
    for (int i = 0; i < v.size(); i++)
    {
        if (data.size() == 0)
        {
            stack.push(v[i]);
            data.push_back(-1);
        }
        else
        {
            while (!(stack.empty()) && stack.top() < v[i])
                stack.pop();
            if (stack.empty())
                data.push_back(-1);
            else
                data.push_back(stack.top());
            stack.push(v[i]);
        }
    }
    return data;
}
vector<int> getNearestSmallestToRight(vector<int> v)
{
    stack<int> stack;
    vector<int> data;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (data.size() == 0)
        {
            stack.push(v[i]);
            data.push_back(-1);
        }
        else
        {
            while (!(stack.empty()) && stack.top() > v[i])
                stack.pop();
            if (stack.empty())
                data.push_back(-1);
            else
                data.push_back(stack.top());
            stack.push(v[i]);
        }
    }
    reverse(data.begin(), data.end());
    return data;
}
vector<int> getNearestSmallestToLeft(vector<int> v)
{
    stack<int> stack;
    vector<int> data;
    for (int i = 0; i < v.size(); i++)
    {
        if (data.size() == 0)
        {
            stack.push(v[i]);
            data.push_back(-1);
        }
        else
        {
            while (!(stack.empty()) && stack.top() > v[i])
                stack.pop();
            if (stack.empty())
                data.push_back(-1);
            else
                data.push_back(stack.top());
            stack.push(v[i]);
        }
    }
    return data;
}
int main()
{
    int size;
    cin >> size;
    vector<int> v(size);
    for (auto &i : v)
        cin >> i;
    vector<int> gToLeft = getNearestGreatestToLeft(v);
    vector<int> gToRight = getNearestGreatestToRight(v);
    vector<int> sToLeft = getNearestSmallestToLeft(v);
    vector<int> sToRight = getNearestSmallestToRight(v);
    cout << "Printing nearest Greatest to the Left" << endl;
    for (auto &i : gToLeft)
        cout << i << " ";
    cout << endl
         << "Printing nearest Greatest To the Right" << endl;
    for (auto &i : gToRight)
        cout << i << " ";
    cout << endl
         << "Printing nearest Smallest to Left" << endl;
    for (auto &i : sToLeft)
        cout << i << " ";
    cout << endl
         << "Printing nearest Greatest to Right" << endl;
    for (auto &i : sToRight)
        cout << i << " ";
}
