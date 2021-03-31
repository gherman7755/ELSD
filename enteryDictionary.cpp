#include <iostream>
#include <string>
#include "enteryDictionary.h"
using namespace std;

bool is_parameter(string input){
    string parameter = "queue";
    char par[100] = "";
    for (int i = input.find('_') + 1, j = 0; i <= input.size(); ++i) {
        if (input[i] == '(')
            break;

        else {
            par[j] = input[i];
            j++;
        }
    }
    if (par == parameter)
        return true;
    else{
        cout << "Invalid parameter" << endl;
        exit(0);
    }
}

bool is_create(string input){
    string create_command = "create";
    char temp[100] = "";
    for (int i = 0; i <= input.size(); i++) {
        if (input[i] != '_')
            temp[i] = input[i];
        else
            break;
    }

    if (temp == create_command){
        if(is_parameter(input))
            return true;
    }
    else{
        cout << "Invalid command" << endl;
        exit(0);
    }
}

bool are_empty_brackets(string input){
    if (input.find('(') + 1 == input.find(')')){
        if(is_create(input))
            return true;
        }
    else{
        cout << "Unexpected value in brackets" << endl;
        exit(0);
    }
}

bool check_brackets(string input){
    if (input.find('(') < input.size() and input.find(')') < input.size()){
        if(are_empty_brackets(input))
            return true;
    }
    else{
        cout << "Expected brackets" << endl;
        exit(0);
    }
}

bool valid_semicolon(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
        if(check_brackets(input))
            return true;
    }
    else{
        cout << "Expected \';\' or incorrect position" << endl;
        exit(0);
    }
}

bool valid_start(string input){
    char s = '_';
    if(input.find(s) < 20) {
        if(valid_semicolon(input)){
            return true;
        }
    }
    else{
        cout << "Expected \'_\' or invalid separation" << endl;
        exit(0);
    }
}
