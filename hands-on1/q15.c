#include <string.h>
#include <stdio.h>
extern char **environ;
int matchPrefix(const char* str, const char* pre) {
    return strncmp(str, pre, strlen(pre)) == 0;
}
int main() {
    char **env = environ;
    while (*env != NULL) {
        if ( matchPrefix(*env, "USER") ) {
            printf("%s \n", *env);
        }
        env++;
    }
    return 0;
}