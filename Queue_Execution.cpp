#include "Queue_Execution.h"
#include <queue>
#include <string>
#include "VerythingCommand.h"

using namespace std;

queue<int> q;

void queue_edit(string input){

    char temp[200] = "";


    if(input[0] == 'f'){
        if(check_command(input)) {
            string command = "front";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                cout << q.front() << endl;
                return;
            }
            else{
                cout << "Invalid command" << endl;
                exit(0);
            }
        }
    }


    else if(input[0] == 'b'){
        if(check_command(input)) {
            string command = "back";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                cout << q.back() << endl;
                return;
            }
            else{
                cout << "Invalid command" << endl;
                exit(0);
            }
        }
    }

    else if(input[0] == 'e'){
        if(check_command(input)) {
            string command = "empty";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                cout << q.empty() << endl;
                return;
            }
            else{
                cout << "Invalid command" << endl;
                exit(0);
            }
        }
    }

    else if(input[0] == 'd'){
        if(check_command(input)) {
            string command = "draw";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                exit(0);
            }
            else{
                cout << "Invalid command" << endl;
                exit(0);
            }
        }
    }

    else if(input[0] == 'p'){
            bool is_admit = false;
            bool is_command = false;
            string command = "push";
            for(int i = 0; i < input.size(); ++i){
                if(input[i] == '('){
                    break;
                }
                else
                    temp[i] = input[i];
            }

            if(temp == command) {
                is_command = true;
                is_admit = is_push(input);
            }


            command = "pop";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
                }
            if (temp == command) {
                if(check_command(input)){
                    q.pop();
                    return;
                }
            }else if(not is_command){
                    cout << "Invalid command" << endl;
                    exit(0);
                }

        char value[200] = "";
        if(is_command and is_admit){
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
    else{
        cout << "Invalid command" << endl;
        exit(0);
    }
}
