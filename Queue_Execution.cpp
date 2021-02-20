#include "Queue_Execution.h"
#include <queue>
#include <string>

using namespace std;

queue<int> q;

void queue_edit(string input){

    string();
    char temp[200] = "";


    if(input[0] == 'f'){
        string command = "front()";
        for(int i = 0; i < input.size(); i++){
            temp[i] = input[i];
        }

        if(temp == command) {
            cout << q.front() << endl;
            return;
        }
    }


    else if(input[0] == 'b'){
        string command = "back()";
        for(int i = 0; i < input.size(); i++){
            temp[i] = input[i];
        }

        if(temp == command) {
            cout << q.back() << endl;
            return;
        }
    }

    else if(input[0] == 'e'){
        string command = "empty()";
        for(int i = 0; i < input.size(); i++){
            temp[i] = input[i];
        }

        if(temp == command) {
            cout << q.empty() << endl;
            return;
        }
    }

    else if(input[0] == 'p'){
        bool is_command = false;
        string command = "push";
        for(int i = 0; i < input.size(); ++i){
            while(input[i] != '('){
                temp[i] = input[i];
                ++i;
            }
            break;
        }

        if(temp == command)
            is_command = true;

        command = "pop()";
        for(int i = 0; i < input.size(); i++){
            temp[i] = input[i];
        }
        if(temp == command){
            q.pop();
            return;
        }

        char value[200] = "";
        if(is_command){
            for(int i = 0, j = 0; i < input.size(); i++){
                if(input[i] == '('){
                    i++;
                    while(input[i] != ')'){
                        value[j] = input[i];
                        i++;
                        j++;
                    }
                }
            }
            q.push(stoi(value));
            return;
        }
    }


}
