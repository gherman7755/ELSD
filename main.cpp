#include <iostream>
#include <string>
#include <fstream>
#include "Queue_Execution.h"
#include "enteryDictionary.h"

using namespace std;

int main()
{

    string PATH = R"(C:\Users\Legion\CLionProjects\untitled\commands.txt)", commands;

    ifstream file;
    file.open(PATH);

    getline(file, commands);
    if (valid_start(commands))
        while (true){
            getline(file, commands);
            queue_edit(commands);
        }

    file.close();


    return 0;

}
