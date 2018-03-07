#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;

int main()
{

    string a = "312831303130313130313031312831303130313130313031312831303130313130313031312831303130313130313031"; //28282828
    string b = "312831303130313130313031312931303130313130313031312831303130313130313031312831303130313130313031"; //28292828
    string c = "312931303130313130313031312831303130313130313031312831303130313130313031312831303130313130313031"; //29282828
    string d = "312831303130313130313031312831303130313130313031312931303130313130313031312831303130313130313031"; //28282928
    string e = "312831303130313130313031312831303130313130313031312831303130313130313031312931303130313130313031"; //28282829

    int N;
    while (cin >> N)
    {
        string temp;
        string tt;
        for (int i = 0; i < N; i++)
        {
            cin >> tt;
            temp.push_back(tt[0]);
            temp.push_back(tt[1]);
        }

        int flag = 0;
        if (a.find(temp, 0) != string::npos)
        {
            flag = 1;
        }
        if (b.find(temp, 0) != string::npos)
        {
            flag = 1;
        }
        if (c.find(temp, 0) != string::npos)
        {
            flag = 1;
        }
        if (d.find(temp, 0) != string::npos)
        {
            flag = 1;
        }
        if (e.find(temp, 0) != string::npos)
        {
            flag = 1;
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
