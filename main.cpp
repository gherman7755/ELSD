#include <iostream>
#include <string>
#include <fstream>
#include "Queue_Execution.h"

using namespace std;

int main()
{

    string PATH = R"(C:\Users\Legion\CLionProjects\untitled\commands.txt)", commands;

    ifstream file;
    file.open(PATH);

    getline(file, commands);
    if (commands == "create_queue")
        while (commands != "draw()"){
            getline(file, commands);
            data_structure(commands);
        }

    file.close();


    return 0;

}
