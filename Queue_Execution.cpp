#include "Queue_Execution.h"
#include <queue>
#include <string>

using namespace std;

queue<int> q;

string command_empty = "empty", command_pop = "pop";
string command_front = "front", command_back = "back";
string command_push = "push";



void data_structure(string input){

    string current_command;
    string value;

    for(char i : input){
        if(i != '('){
            current_command += i;
        }
        else{break;}
    }


    if(current_command == command_push){
        for(char i : input.substr(5)){
            if(i != ')')
                value += i;
        }
        q.push(stoi(value));
        return;
    }

    else if(current_command == command_pop){
        q.pop();
        return;
    }

    else if(current_command == command_front){
        cout << q.front() << endl;
        return;
    }

    else if(current_command == command_back){
        cout << q.back() << endl;
        return;
    }

    else if(current_command == command_empty){
        cout << q.empty() << endl;
        return;
    }

}