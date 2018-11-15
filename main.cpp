#include <iostream>
#include <string>
#include <algorithm>
#include "text_analysis.h"
using namespace std;

//implenmet the text analysis

void Toupperstring(string &str)
{
    transform(str.begin(), str.end(), str.begin(), (int (*) (int))toupper);
}

int main()
{
    cout << "*************************************" << endl;
    cout << "**^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^**" << endl;
    cout << "**  Enter what you want to search  **" << endl;
    cout << "**^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^**" << endl;
    cout << "*************************************" << endl;
    text_analysis text;
    while(1){
        string user_input;
        getline(cin, user_input);
        Toupperstring(user_input);
        if(!user_input.empty()){
           if(user_input == "EXIT"){
             cout << "Thx you use it" << endl;
             return 0;
          }
          text.search_in_Server("/home/noah",user_input);
          cout << endl;
          cout << "*************************************" << endl;
          cout << "**^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^**" << endl;
          cout << "**  Enter what you want to search  **" << endl;
          cout << "**^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^**" << endl;
          cout << "*************************************" << endl;
        }
        else{
           cout << "Please Enter the Real name " << endl;
        }

    }
}

