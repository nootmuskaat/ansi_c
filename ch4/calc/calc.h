#define NUMBER '0'
#define MATH_1 '1'
#define MATH_2 '2'

double math1(char [], double x);
double math2(char [], double x, double y);
int getop(char []);
void push(double);
double pop(void);
void ptop(void);
void duptop(void);
void swaptop(void);
void clrstk(void);
int getch(void);
void ungetch(int);
