#include <bits/stdc++.h>
using namespace std;

// void print_vec(vector<vector<int>> vec)
// {
//     for (int i = 0; i < vec.size(); i++)
//     {
//         for (int j = 0; j < vec[i].size(); j++)
//         {
//             cout << vec[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void print_arr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<vector<int>> initialize_vector()
{
    vector<vector<int>> bucket;
    vector<int> negOne;
    for (int i = 0; i <= 9; i++)
    {
        negOne.push_back(-1);
        bucket.push_back(negOne);
        negOne.clear();
        // we add -1 at each arr[i][0] index where 0<=i<=9
    }
    return bucket;
    //returns bucket to add_in_buckets() function after initialization. 
}

vector<vector<int>> add_in_buckets(vector<int> arr, int tens)
{
    vector<vector<int>> buckets;
    buckets = initialize_vector();
    // buckets are initialized 
    int digit;
    for (int i = 0; i < arr.size(); i++)
    {
        digit = (arr[i] / tens) % 10;
        // digit filters the digits at different places value
        // like at ones, tens, hundres, thousands
        buckets[digit].push_back(arr[i]);
        //we store the current element to the digit index
        //for example if no is 12345
        //--------------------------
        //for ones- digit = 5 so in bucket 1 the element will be stores at i=5
        //for tens- digit = 4 so in bucket 2 the element will be stored at i=4
    }
    return buckets;
    //return buckets to redixSort() function. 
}

int find_largest_dig(vector<int> arr, int size)
{
    int tens = 1, flag = 0, count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] / tens != 0)
            {
                flag = 1;
                // flag check whether there are no with (i) 
                // digits or not
                break;
                //if found, numbers with (i) digits, break
            }
        }
        tens *= 10;
        if (flag == 0)
        {
            break;
            //It shows that no of numbers with i digits is zero, 
            //so break
        }
        else
            count++;
            //count stores the largest digit found yet .
        flag = 0; 
    }
    return count;
}

vector<int> copy_to_array(vector<vector<int>> buckets, int size)
{
    int k = 0;
    vector<int> arr;
    for (int i = 0; i < buckets.size(); i++)
    {
        for (int j = 1; j < buckets[i].size(); j++)
        {
            arr.push_back(buckets[i][j]);
        }
    }
    return arr;
}

vector<int>  radixSort(vector<int> arr, int size)
{
    int largestDigit = find_largest_dig(arr, size);
    // find the largest no of digits a number has
    // cout << "Largest Digit : " << largestDigit << endl;
    vector<vector<int>> buckets;
    // create a 2d vector to be used as buckets
    int tens = 1;
    //this variable stores numbers in power of 10
    //1 10 100 1000 (like that)
    for (int i = 1; i <= largestDigit; i++)
    // total no of buckets  = largest no of digits found in the current array
    {
        buckets = add_in_buckets( arr, tens);
        //initialize the buckets 
        arr = copy_to_array(buckets, arr.size());
        //copy values of buckets in array
        buckets.clear();
        //clear the elements in the bucket
        tens *= 10;
        //increase tens (*10) for each iteration
    }
    return arr;
}

int main()
{
    int size;
    cout << "Enter the size : ";
    cin >> size;
    vector<int> vec;
    int input;
    cout << "Enter the elements in the array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> input;
        vec.push_back(input);
    }
    cout << "Array before sorting" << endl;
    print_arr(vec);
    vec = radixSort(vec, size); // calling the radixSort function for sorting
    cout << "Array after sorting" << endl;
    print_arr(vec);
}