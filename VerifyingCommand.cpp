#include <string>
#include <iostream>
#include "VerythingCommand.h"
using namespace std;

void call_error(){
    cout << "Invalid command" << endl;
    exit(0);
}

bool valid_end(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1)
        return true;
    else{
        cout << "Expected \';\' or incorrect position" << endl;
        exit(0);
    }
}

bool are_brackets(string input){
    if (input.find('(') < input.size() and input.find(')') < input.size())
        return true;
    else
        return false;
}

bool valid_brackets(string input){
    bool are_empty_brackets = false;
    bool contains_value = false;
    bool brackets = are_brackets(input);
    string push_command = "push";
    string temp = input.substr(0,4);
    bool is_push_command = temp == push_command;

    if (brackets){
        if (input.find('(') + 1 == input.find(')')){
            are_empty_brackets = true;
        }
        else if(input.find('(') < input.find(')') - 1){
            contains_value = true;
        }
    }

    if(brackets) {
        if (!are_empty_brackets) {
            if(!contains_value and is_push_command){
                cout << "Expected value" << endl;
                exit(0);
            } else if(contains_value and is_push_command){
                return true;
            }
            if(!is_push_command){
                cout << "Unexpected value" << endl;
                exit(0);
            }
        } else if(is_push_command){
            cout << "Expected value" << endl;
            exit(0);
        }
    }
    else{
        cout << "Expected brackets" << endl;
        exit(0);
    }
}


int take_value(string input){
    char value[200] = "";
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
    return atoi(value);
}

int analyze_input(string input, int *val){
    if(input[0] == 'f'){
        if(is_mapping(input, "front")) {
            return 1;
        }else{
            call_error();
        }
    }
    else if(input[0] == 'b'){
        if(is_mapping(input, "back")){
            return 2;
        }else{
            call_error();
        }
    }
    else if(input[0] == 'e'){
        if(is_mapping(input, "empty")){
            return 3;
        }else{
            call_error();
        }
    }

    else if(input[0] == 'd'){
        if(is_mapping(input, "draw")){
            return 4;
        }
    }

    else if(input[0] == 'p'){
        if(!is_mapping(input, "pop")){
            if(!is_mapping(input, "push")){
                call_error();
            }
            else{
                (*val) = take_value(input);
                return 6;
            }
        }
        else{
            return 5;
        }
    }
    else{
        call_error();
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
                return false;
            }
        }
    }
}

