#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main()
{
    stack<int, vector<int>> iStack;
    
    for (int i = 1; i <= 5; i++){
        cout << "Pushing " << i << "...\n";
        iStack.push(i);
    }
    
    stack<int, vector<int>> tempStack;
    
    tempStack = iStack;
        
    while (!tempStack.empty()){
        cout << tempStack.top() << endl;
        tempStack.pop();
    }
    
    return 0;
}

