/**
 * Write versions of the library functions strncpy , strncat , and strncmp ,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s .
 * Full descriptions are in Appendix B
 **/

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);
int test_strncpy(void);
int test_strncat(void);
int test_strncmp(void);

int main() {
    test_strncpy();
    test_strncat();
    test_strncmp();
    return 0;
}


void my_strncpy(char *s, char *t, int n){
    return;
}

void my_strncat(char *s, char *t, int n){
    return;
}

int my_strncmp(char *s, char *t, int n){
    return 0;
}

int test_strncpy(void){
    return 0;
}

int test_strncat(void){
    return 0;
}

int test_strncmp(void){
    return 0;
}
