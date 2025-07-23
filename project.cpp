#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<long long, null_type, greater<long long>,
             rb_tree_tag, tree_order_statistics_node_update>
    orderedSet;

void Erase(orderedSet &s, int val)
{
    int rank = s.order_of_key(val);
    auto it = s.find_by_order(rank);
    s.erase(it);
}

#define fast()               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define el '\n'
#define sp " "
#define yes "YES\n"
#define no "NO\n"

/************************************/
map<int, deque<string>> spec;
class patients_data
{
    int specialization, status;
    char name[20];

public:
    patients_data();
    static void enter_patients_data(int a, int b, char c[])
    {
        if (spec[a].size() >= 5)
        {
            cout << "sorry there is no spac available\n";
        }
        else
        {
            if (b == 0)
            {
                spec[a].push_back(c);
            }
            else
            {
                spec[a].push_front(c);
            }
        }
    }
    static void print_patients()
    {
        for (auto [x, y] : spec)
        {
            for (auto q : y)
            {
                cout << "Name : " << q << "  ||  Spec : " << x << el;
            }
        }
    }
    static void pick_patient(int Spec){
        if(spec[Spec].size() > 0){
            cout << spec[Spec].front() << " please go with the doctor\n" ;
            spec[Spec].pop_front();
        }
        else{cout << "No patients\n";}
    }
};

int main()
{
    patients_data::enter_patients_data(1, 1, "yousef");
    patients_data::enter_patients_data(1, 0, "yousef1");
    patients_data::enter_patients_data(1, 1, "yousef2");
    patients_data::enter_patients_data(1, 0, "yousef3");
    patients_data::enter_patients_data(1, 0, "yousef4");
    patients_data::enter_patients_data(1, 1, "yousef5");

    patients_data::print_patients();

    patients_data::pick_patient(1);
    patients_data::pick_patient(1);
    patients_data::pick_patient(5);
}
