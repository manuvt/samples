#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These strings are never used maliciously but will appear in the binary
const char *FAKE_C2 = "http://evil-server.example.com/login.php";
const char *FAKE_KEY = "1234-5678-ABCD-EFGH";
const char *CMD = "cmd.exe /c del C:\\Windows\\System32\\important.dll";

void suspicious_function() {
    // This function does nothing but references the strings
    printf("Simulating malicious behavior...\n");
    printf("Connecting to: %s\n", FAKE_C2);
}

int main() {
    printf("This is a benign program for educational analysis.\n"); 
    printf("It performs no harmful actions.\n");
    
    // To ensure the compiler doesn't optimize the strings away, we reference them
    if (strcmp(FAKE_KEY, "0000") == 0) {
        suspicious_function();
    }

    return 0;
}
