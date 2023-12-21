#include <iostream>
#include <cctype>

using namespace std;

enum State {
    START,              
    AFTER_DOT,          
    AFTER_UNDERSCORE,   
    AFTER_IDENTIFIER,   
    AFTER_SEMICOLON,    
    FINAL
};

bool isValidIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}

bool isDot(char ch) {
    return ch == '.';
}

bool isSemicolon(char ch) {
    return ch == ';';
}

bool isHash(char ch) {
    return ch == '#';
}

bool isStartChar(char ch) {
    return isalpha(ch) || ch == '_';
}

bool isFinalState(State state) {
    return state == FINAL;
}

bool isInvalidState(State state) {
    return state == START;
}

bool isValidSequence(const string& sequence) {
    State currentState = START;
    
    for(int i = 0; i<sequence.length(); i++)
    {
        char ch = sequence[i];
        switch (currentState) {
            case START:
                if (isStartChar(ch)) {
                    currentState = AFTER_IDENTIFIER;
                } else {
                    return false;
                }
                break;
            case AFTER_DOT:
                if (isValidIdentifierChar(ch)) {
                    currentState = AFTER_IDENTIFIER;
                } else if(isHash(ch)) {
                    currentState = FINAL;
                } else {
                    return false;
                }
                break;
            case AFTER_UNDERSCORE:
                if (isStartChar(ch)) {
                    currentState = AFTER_IDENTIFIER;
                } else if(isHash(ch)) {
                    currentState = FINAL;
                } else {
                    return false;
                }
                break;
            case AFTER_IDENTIFIER:
                if (isValidIdentifierChar(ch)) {
                    // Оставаться в том же состоянии
                } else if (isDot(ch)) {
                    currentState = AFTER_DOT;
                } else if (isSemicolon(ch)) {
                    currentState = AFTER_SEMICOLON;
                } else if(isHash(ch)) {
                    currentState = FINAL;
                } else {
                    return false;
                }
                break;
            case AFTER_SEMICOLON:
                if (isStartChar(ch)) {
                    currentState = AFTER_IDENTIFIER;
                } else if(isHash(ch)) {
                    currentState = FINAL;
                } else {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return isFinalState(currentState);
}

int main() {
    string input;
    getline(cin, input);


    if (isValidSequence(input)) 
    {
        cout << "STRING is RIGHT\n";
    } else 
    {
        cout << "STRING is WRONG\n";
    }

    return 0;
}