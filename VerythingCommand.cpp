#include <string>
#include <iostream>
#include "VerythingCommand.h"
using namespace std;

bool valid_end(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1)
        return true;
    else{
        cout << "Expected \';\'" << endl;
        exit(0);
    }
}

bool valid_brackets(string input){
    bool are_brackets = false;
    bool are_empty_brackets = false;

    if (input.find('(') < input.size() and input.find(')') < input.size())
        are_brackets = true;

    if (are_brackets){
        if (input.find('(') + 1 == input.find(')'))
            are_empty_brackets = true;
    }

    if(are_brackets) {
        if (are_empty_brackets) {
            return true;
        } else {
            cout << "Unexpected value in brackets or incorrect closing" << endl;
            exit(0);
        }
    }
    else{
        cout << "Expected brackets" << endl;
        exit(0);
    }
}

int analyze_input(string input, int *val){
    if(input[0] == 'f'){
        if(is_mapping(input, "front"))
            return 1;
    }
    else if(input[0] == 'b'){
        if(is_mapping(input, "back"))
            return 2;
    }
    else if(input[0] == 'e'){
        if(is_mapping(input, "empty"))
            return 3;
    }

    else if(input[0] == 'd'){
        if(is_mapping(input, "draw"))
            return 4;
    }

    else if(input[0] == 'p'){
        bool is_admit = false;
        bool is_command = false;
        char temp[100] = "";
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
            if(valid_end(input) and valid_brackets(input)){
                return 5;
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
            (*val) = atoi(value);
            return 6;
        }

    }
    else{
        cout << "Invalid command" << endl;
        exit(0);
    }
}


bool is_push(string input){
    if(valid_end(input)){
        bool are_brackets = false;
        bool contains_value = false;

        if (input.find('(') < input.size() and input.find(')') < input.size())
            are_brackets = true;

        if (are_brackets){
            if (input.find('(') < input.find(')') - 1)
                contains_value = true;
        }
        if(are_brackets) {
            if (contains_value) {
                return true;
            } else {
                cout << "Expected value in brackets or incorrect closing" << endl;
                exit(0);
            }
        }
        else{
            cout << "Expected brackets" << endl;
            exit(0);
        }
    }
    else{
        cout << "Expected \';\'" << endl;
        exit(0);
    }
}

bool is_mapping(string input, string command){
    if(valid_end(input)){
        if(valid_brackets(input)){
            char temp[100] = "";
            for(int i = 0; i < input.size(); i++){
                if(input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if(temp == command){
                return true;
            }
            else{
                cout << "Invalid command" << endl;
                exit(0);
            }
        }
    }
}

