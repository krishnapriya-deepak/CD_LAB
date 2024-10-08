//Krishnapriya Deepak S7CS230
//Program 2
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *input;

void E();
void Eprime();
void T();
void Tprime();
void F();

void match_token() {
    if (strncmp(input, "id", 2) == 0) {
        printf("F -> id\n");
        input += 2;
    } else if (isalpha(*input)) {
        printf("F -> %c\n", *input);
        input++;
    } else if (isdigit(*input)) {
        printf("F -> %c\n", *input);
        input++;
    }
}

void E() {
    printf("E -> T E'\n");
    T();
    Eprime();
}

void Eprime() {
    if (*input == '+') {
        printf("E' -> + T E'\n");
        input++;
        T();
        Eprime();
    } else {
        printf("E' -> e\n");
    }
}

void T() {
    printf("T -> F T'\n");
    F();
    Tprime();
}

void Tprime() {
    if (*input == '*') {
        printf("T' -> * F T'\n");
        input++;
        F();
        Tprime();
    } else {
        printf("T' -> e\n");
    }
}

void F() {
    match_token();
}

int main() {
    char str[100];
    printf("Enter the input string: ");
    scanf("%s", str);

    input = str;
    E();

    if (*input == '\0') {
        printf("String is successfully parsed.\n");
    } else {
        printf("Error in parsing the string.\n");
    }

    return 0;
}

/*OUTPUT
Enter the input string: a+b*c
E -> T E'   
T -> F T'   
F -> a      
T' -> e     
E' -> + T E'
T -> F T'
F -> b
T' -> * F T'
F -> c
T' -> e
E' -> e
String is successfully parsed.
*/

