#include "Queue_Execution.h"
#include <queue>
#include <string>
#include "VerythingCommand.h"

using namespace std;

queue<int> q;

void queue_edit(string input){

    int value = 0;

    int choose = analyze_input(input, &value);

    switch (choose) {
        case 1:
            cout << q.front() << endl;
            break;
        case 2:
            cout << q.back() << endl;
            break;
        case 3:
            cout << q.empty() << endl;
            break;
        case 4:
            cout << "Drawing" << endl;
            exit(0);
        case 5:
            q.pop();
            break;
        case 6:
            q.push(value);
            break;
        default:
            cout << "It is impossible" << endl;
            exit(0);
    }
}
