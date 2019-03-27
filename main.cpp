#include <iostream>
#include <cstring> // подключаем строки
#include <fstream> // подключаем файлы
#include <stdio.h>
using namespace std; // используем стандартное пространство имен

string global[500];
string local[500];
string dinamic[500];
string int_ = "int";
string double_ = "double";
string bool_ = "bool";
int procedure = 0;

int main(){
    string s; // сюда будем класть считанные строки
    ifstream file("code.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
    procedure = 0;
    int g = 0;
    int l = 0;
    int d = 0;
    int yy=4;
    char st[100];
    while(getline(file,s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
      //cout << s <<  endl;
      if (s.find("{") != string::npos){
       procedure++;
       continue;
     }
      if (s.find("}") != string::npos){
       procedure--;
       continue;
     }
      if(s.find(int_) != string::npos){
		if(s.find("new") == string::npos){
        		if(procedure == 0){
          			global[g] = s.substr(0, s.find("=")- 1);
          			g++;
        		}
        		else{
          			local[l] = s.substr(0, s.find("=") - 1);
          			l++;
        		}
    		}
		else{
			dinamic[d] = s.substr(0, s.find("=")- 1);
			d++;
		}
	}
     if(s.find(double_) != string::npos){
		if(s.find("new") == string::npos){
        		if(procedure == 0){
          			global[g] = s.substr(0, s.find("=")- 1);
          			g++;
        		}
        		else{
          			local[l] = s.substr(0, s.find("=") - 1);
          			l++;
        		}
    		}
		else{
			dinamic[d] = s.substr(0, s.find("=")- 1);
			d++;
		}
	}
  	if(s.find(bool_) != string::npos){
		if(s.find("new") == string::npos){
        		if(procedure == 0){
          			global[g] = s.substr(0, s.find("=")- 1);
          			g++;
        		}
        		else{
          			local[l] = s.substr(0, s.find("=") - 1);
          			l++;
        		}
    		}
		else{
			dinamic[d] = s.substr(0, s.find("=")- 1);
			d++;
		}
	}






    }

    file.close(); // обязательно закрываем файл что бы не повредить его
	cout << "it's global" << endl;  
    for(int i = 0; i < g; i++){
      cout << global[i] << endl;

    }

	cout << "it's local" << endl;  
    for(int i = 0; i < l; i++){
      cout << local[i] << endl;

    }
	cout << "it's dinamic" << endl;  
    for(int i = 0; i < d; i++){
      cout << dinamic[i] << endl;

    }
    return 0;
}

