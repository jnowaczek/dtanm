#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error() {
    printf("Error\n");
    exit(1);
}

int main(int argc, char *argv[]) {

    char *input = argv[1];

    char *expression, *token;
    char *tokens[3];
    char *saveptr1;
    signed short A, B, SUM, dividend, quotient;
    char oper;
    int i;

	if (argc < 2) {
		error();
	}
    
    for (expression = strtok_r(input, ",", &saveptr1); expression; expression = strtok_r(NULL, ",", &saveptr1)) {
        printf("Expression: %s\n", expression);
        // Get input
        for (i = 0, token = strtok(expression, " "); token; token = strtok(NULL, " "), i++) {
            printf("\tToken: %s\n", token);
            tokens[i] = token;
        }
        A = atoi(tokens[0]);
        oper = tokens[1][0];
        B = atoi(tokens[2]);
        
        // Do calculations
        switch(oper) {
            case '+':
                printf("%d\n", A+B);
                break;
            case '-':
                printf("%d\n", A-B);
                break;
            case '*':
                // Should we loop
                SUM = B;
                for (i = 1; i < B; i++) {
                    SUM += A;
                }
                printf("%d\n", SUM);
                break;
            case '/':
            
                //FYI: This has an off by one error currently
                dividend = A;
                quotient = 0;
                while (dividend > B) {
                    dividend -= B;
                    quotient++;
                }
                
                // TODO: add gcd
                
                printf("%d\n", quotient);
                break;
        }
    }
    
    return 0;
}
