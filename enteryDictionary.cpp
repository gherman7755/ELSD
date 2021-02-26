#include <iostream>
#include <string>
#include "enteryDictionary.h"
using namespace std;

bool valid_start(string input){
    char s = '_';
    if(input.find(s) < 20) {
        bool is_end = false;
        bool are_brackets = false;
        bool is_parameter = false;
        bool is_create_command = false;
        bool are_empty_brackets = false;
        string create_command = "create";
        string queue_parameter = "queue";


        if (input.size() - 1 == input.find(';'))
            is_end = true;

        if (input.find('(') < input.size() and input.find(')') < input.size())
            are_brackets = true;

        if (are_brackets)
            if (input.find('(') + 1 == input.find(')'))
                are_empty_brackets = true;

        char temp[100] = "";
        for (int i = 0; i <= input.size(); i++) {
            if (input[i] != '_')
                temp[i] = input[i];
            else
                break;
        }

        if (temp == create_command)
            is_create_command = true;

        char par[100] = "";
        for (int i = input.find('_') + 1, j = 0; i <= input.size(); ++i) {
            if (input[i] == '(')
                break;

            else {
                par[j] = input[i];
                j++;
            }
        }
        if (par == queue_parameter)
            is_parameter = true;

        if (is_end) {
            if (are_brackets) {
                if (are_empty_brackets) {
                    if (is_create_command) {
                        if (is_parameter)
                            return true;
                        else{
                            cout << "Invalid parameter" << endl;
                            exit(0);
                        }
                    } else{
                        cout << "Invalid command" << endl;
                        exit(0);
                    }
                } else {
                    cout << "Unexpected value in brackets" << endl;
                    exit(0);
                }
            }
            else{
                cout << "Expected brackets" << endl;
                exit(0);
            }
        }
        else {
            cout << "Expected \';\'" << endl;
            exit(0);
        }
    }
    else{
        cout << "Expected \'_\' or invalid separation" << endl;
        exit(0);
    }
}
