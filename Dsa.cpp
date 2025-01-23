#include <iostream>
using namespace std;

const int MAX = 5;
int st[MAX], top = -1;

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int length(int st[]); // Already implemented
int count(int st[]);  // New function

int main() {
    int val, option;
    do {
        cout << "\n **MAIN MENU**";
        cout << "\n 1. PUSH";
        cout << "\n 2. POP";
        cout << "\n 3. PEEK";
        cout << "\n 4. DISPLAY";
        cout << "\n 5. LENGTH";
        cout << "\n 6. COUNT";
        cout << "\n 7. EXIT";
        cout << "\n Enter your option: ";
        cin >> option;
        switch(option) {
            case 1:
                cout << "\n Enter the number to be pushed on stack: ";
                cin >> val;
                push(st, val);
                break;
            case 2:
                val = pop(st);
                if(val != -1)
                    cout << "\n The value deleted from stack is: " << val;
                break;
            case 3:
                val = peek(st);
                if(val != -1)
                    cout << "\n The value stored at top of stack is: " << val;
                break;
            case 4:
                display(st);
                break;
            case 5:
                cout << "\n The current length of the stack is: " << length(st);
                break;
            case 6:
                cout << "\n The number of elements in the stack is: " << count(st);
                break;
        }
    } while(option != 7);
    return 0;
}

void push(int st[], int val) {
    if(top == MAX-1) {
        cout << "\n STACK OVERFLOW";
    } else {
        top++;
        st[top] = val;
    }
}

int pop(int st[]) {
    int val;
    if(top == -1) {
        cout << "\n STACK UNDERFLOW";
        return -1;
    } else {
        val = st[top];
        top--;
        return val;
    }
}

void display(int st[]) {
    int i;
    if(top == -1)
        cout << "\n STACK IS EMPTY";
    else {
        for(i = top; i >= 0; i--)
            cout << "\n " << st[i];
        cout << "\n";
    }
}

int peek(int st[]) {
    if(top == -1) {
        cout << "\n STACK IS EMPTY";
        return -1;
    } else
        return(st[top]);
}

int length(int st[]) {
    return top + 1;  // Returns the current number of elements in the stack
}

int count(int st[]) {
    return top + 1;  // Same logic as length()
}
