#include <ctype.h>

int calculate(char* s) {
    long result = 0;
    long last = 0;
    long num = 0;
    char op = '+';

    for(int i = 0; s[i] != '\0'; i++) {
        
        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {

            if(op == '+') {
                result += last;
                last = num;
            }
            else if(op == '-') {
                result += last;
                last = -num;
            }
            else if(op == '*') {
                last = last * num;
            }
            else if(op == '/') {
                last = last / num;
            }

            op = s[i];
            num = 0;
        }
    }

    result += last;
    return result;
}
