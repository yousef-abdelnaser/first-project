#include <iostream>
#include <string>
#include <map>
#include <deque>
using namespace std;
#define fast()               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define el '\n'
#define sp " "

/************************************/
map<int, deque<string>> spec;
map<string,string>Patients_Status;
class patients_data
{
    int specialization, status;
    char name[20];

public:
    patients_data();
    static void enter_patients_data(int a, char c[], int b)
    {
        if (spec[a].size() >= 5)
        {
            cout << "sorry there is no spac available\n";
        }
        else
        {
            if (b == 0)
            {
                Patients_Status[c] = "regular";
                spec[a].push_back(c);
            }
            else
            {
                Patients_Status[c] = "urgent";
                spec[a].push_front(c);
            }
        }
    }
    static void print_patients(int x)
    {
        if(x == 0)
        {
            for (auto [x, y] : spec)
            {
                for (auto q : y)
                {
                cout << "Name : " << q << "  ||  Spec : " << x
                << " || Status : " << Patients_Status[q] << el ;
                }
            }
        }
        else
        {
            for(auto q : spec[x]){
                cout << "Name : " << q << " || Status : " << Patients_Status[q] << el ;
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
    int num , SP , ST ; char N[20] ; string Name; 
    cout << "Enter your choice:\n" << "1) Add new patient\n" 
    << "2) Print all patients\n" << "3) Get next patient\n" << "4) Exit\n" ; 
    while(true){
        cin >> num ;
        if(num == 1){
            cout << "Enter patient's name : " ; cin >> N ;
            cout << "\nEnter specialization : " ; cin >> SP ; 
            cout << "\nEnter patient's status : " ; cin >> ST ; 
            patients_data::enter_patients_data(SP,N,ST);
        }
        else if(num == 2){
            int X ; 
            cout << "For all patients enter 0\nor enter the number of specialization\n";
            cin >> X ; 
            patients_data::print_patients(X);
        }
        else if(num == 3)
        {
            int S ;
            cout << "Enter Specialization : " ; cin >> S ; 
            patients_data::pick_patient(S);
        }
        else if(num == 4){return 0;}
        else{cout << "Please Enter a valid number\n";}
    }
}
