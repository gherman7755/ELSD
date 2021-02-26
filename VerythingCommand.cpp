#include <string>
#include <iostream>
#include "VerythingCommand.h"
using namespace std;

bool check_command(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
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
    else{
        cout << "Expected \';\'" << endl;
        exit(0);
    }
}

bool is_push(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
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