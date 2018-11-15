#include <iostream>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include "text_analysis.h"
using namespace std;


void 
text_analysis::search_in_Server(string pathname, string &target)
{
   struct dirent **ent_list;
   int count;
   count = scandir(pathname.c_str(), &ent_list, 0, alphasort);
   //if(count < 0){return;}
   for(int i = 0; i < count; i++){
      string new_path;
      struct dirent *ent;
      ent = ent_list[i];
      if(name_filter(ent->d_name)){
        new_path = make_pathname(pathname, ent->d_name);
        if(dirctory_filter(new_path)){
           search_in_Server(new_path, target);
        }
        else{
          if(string_compare(ent->d_name, target)){
              cout << new_path << endl;
          }
        }
      }      
   }
   free(ent_list);
   return;
}


bool 
text_analysis::dirctory_filter(const string &new_path)
{
    struct stat s_buf;
    lstat(new_path.c_str(), &s_buf);
    switch(s_buf.st_mode & S_IFMT){
        case S_IFDIR: return true; break;
        case S_IFREG: return false; break;
    }
    return false;
}

bool 
text_analysis::string_compare(char name[], string &target)
{
    int number = 1; 
    string temp = string(name);
    Toupperstring(temp);
    number = strncmp(temp.c_str(), target.c_str(), 4);
    if(number == 0){return true;}
    else{return false;}

}

bool 
text_analysis::name_filter(char *name)
{
  if(name[0] == '.'){
      return false;
  }
  else{return true;}
}

string
text_analysis::make_pathname(string old_pathname, char *new_file)
{
  string new_temp = string(new_file);
  old_pathname = old_pathname + "/" + new_temp;
  return old_pathname;
  
}