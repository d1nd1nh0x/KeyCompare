#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 32

// Function to get password input from the user
void getPasswordInput(char *password, int maxLength) {
    printf("Digite a senha (max %d caracteres): ", maxLength);
    fgets(password, maxLength, stdin);

    // Remove newline character if present
    size_t length = strlen(password);
    if (length > 0 && password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }
}

// Simple comparison function
int simpleComparison(const char *password1, const char *password2) {
    return strcmp(password1, password2) == 0;
}

// Complex comparison function: returns a similarity score (0 to 100%)
float complexComparison(const char *password1, const char *password2) {
    int len1 = strlen(password1);
    int len2 = strlen(password2);
    int commonCount = 0;

    // Find common characters ignoring case
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (tolower(password1[i]) == tolower(password2[j])) {
                commonCount++;
                break;
            }
        }
    }

    int maxLength = len1 > len2 ? len1 : len2;
    return ((float)commonCount / maxLength) * 100;
}

int main() {
    char password1[MAX_LENGTH];
    char password2[MAX_LENGTH];
    int choice;

    printf("Escolha o tipo de comparacao:\n");
    printf("1 - Comparacao Simples\n");
    printf("2 - Comparacao Complexa\n");
    printf("Digite sua escolha: ");
    scanf("%d", &choice);
    getchar(); // Clear newline from input buffer

    getPasswordInput(password1, MAX_LENGTH);
    getPasswordInput(password2, MAX_LENGTH);

    if (choice == 1) {
        if (simpleComparison(password1, password2)) {
            printf("As senhas sao identicas.\n");
        } else {
            printf("As senhas sao diferentes.\n");
        }
    } else if (choice == 2) {
        float similarity = complexComparison(password1, password2);
        printf("As senhas sao %.2f%% similares.\n", similarity);
    } else {
        printf("Escolha invalida.\n");
    }

    return 0;
}
