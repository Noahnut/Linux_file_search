#include <iostream>
#include <dirent.h>
#include <algorithm>

#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H


using namespace std;

class text_analysis
{  
  public:
    void search_in_Server(string path_name,string &target);
  private: 
    bool string_compare(char name[], string &target);
    bool name_filter(char *name);
    bool dirctory_filter(const string &new_path);
    string make_pathname(string old_pathname, char *new_file);
    void Toupperstring(string &str)
    {
      transform(str.begin(), str.end(), str.begin(), (int (*) (int))toupper);
    }    
};






#endif 