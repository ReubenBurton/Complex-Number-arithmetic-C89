#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#define M_PI 3.14159265
#define RAD M_PI/180
#define DEG 180/M_PI

/*---------forward decs-------------*/

void cont(int *con);

char start_menu();
void op(char operation, int repeat, double *i, double *j);

void parallel(int repeat, double *prev_i, double *prev_j);

void addition(int repeat, double *prev_i, double *prev_j);
void add_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans);

void subtraction(int repeat, double *prev_i, double *prev_j);
void subtract_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans);

void multiplication(int repeat, double *i, double *j);
void multiply_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans);

void division(int repeat, double *i, double *j);
void divide_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans);

void prompt(double *i, double *j, char* string);
void prompt2(char option, int* ans);
void answer(double i_ans, double j_ans);

void get_polar(double* amplitude, double* angle);
void get_rect(double* i, double* j);

int happy();

double get_float();

void print_polar(double amplitude, double angle);
void print_rect(double i, double j);

void polar_to_rec(double amplitude, double angle, double *i, double *j);
void rec_to_polar(double *amplitude, double *angle, double i, double j);

void check_yourself(double *i, double *j);


int main()
{
    int repeat = 0;
    double i = 0.00;
    double j = 0.00;
    do
    {
        op(start_menu(), repeat, &i, &j);
        cont(&repeat);
    }while(repeat != 0);
    answer(i, j);
    return 1;
}

void cont(int *con)
{
    char c;
    printf("Do you want to continue? (y n): ");
    scanf(" %1s", &c);
    if(c == 'y')
    {
        *con = *con+1;
    }
    else
    {
        *con = 0;
    }
    system("clear");
}
char start_menu()
{
    char operation;
    printf("m for multiplication\n");
    printf("d for division\n");
    printf("s for subtraction\n");
    printf("a for addition\n");
    printf("\n");
    printf("Special Options:\n");
    printf("p for Parallel Impedence\n");
    scanf(" %1s", &operation);
    return operation;
}

void op(char operation, int repeat, double *i, double *j)
{
    switch(operation)
    {
        case 'm':
            multiplication(repeat, i, j);
            break;
        case 'd':
            division(repeat, i, j);
            break;
        case 's':
            subtraction(repeat, i, j);
            break;
        case 'a':
            addition(repeat, i, j);
            break;
        case 'p':
            parallel(repeat, i, j);
            break;
        default:
            break;
    }
}

void parallel(int repeat, double *prev_i, double *prev_j)
{
    double i1, j1, i2, j2;
    double num_i, num_j, denom_i, denom_j;
    int option;
    
    char* string = "Enter 1st term";
    char* string2 = "Enter 2nd term";
    if(repeat == 0)
    {
        system("clear");
        prompt(&i1, &j1, string);
        system("clear");
        prompt(&i2, &j2, string2);
        system("clear");
    }
    else if(repeat > 0)
    {
        prompt2('p', &option);
        if(option == 1)
        {
            i1 = *prev_i;
            j1 = *prev_j;
            system("clear");
            prompt(&i2, &j2, string2);
            system("clear");
        }
        else if(option == 2)
        {
            i2 = *prev_i;
            j2 = *prev_j;
            system("clear");
            prompt(&i1, &j1, string);
            system("clear");
        }
    }
    multiply_complex(i1, j1, i2, j2, &num_i, &num_j);
    add_complex(i1, j1, i2, j2, &denom_i, &denom_j);
    divide_complex(num_i, num_j, denom_i, denom_j, prev_i, prev_j);
    check_yourself(prev_i, prev_j);
    answer(*prev_i, *prev_j);
}

void check_yourself(double *i, double *j)
{
    double r1, t1;
    rec_to_polar(&r1, &t1, *i, *j);
    polar_to_rec(r1, t1, i, j);
}

void addition(int repeat, double *prev_i, double *prev_j)
{
    double i1, j1, i2, j2;
    int option;
    
    char* string = "Enter 1st term";
    char* string2 = "Enter 2nd term";
    if(repeat == 0)
    {
        system("clear");
        prompt(&i1, &j1, string);
        system("clear");
        prompt(&i2, &j2, string2);
        system("clear");
    }
    else if(repeat > 0)
    {
        prompt2('a', &option);
        if(option == 1)
        {
            i1 = *prev_i;
            j1 = *prev_j;
            system("clear");
            prompt(&i2, &j2, string2);
            system("clear");
        }
        else if(option == 2)
        {
            i2 = *prev_i;
            j2 = *prev_j;
            system("clear");
            prompt(&i1, &j1, string);
            system("clear");
        }
    }
    add_complex(i1, j1, i2, j2, prev_i, prev_j);
    answer(*prev_i, *prev_j);
}

void add_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans)
{
    *i_ans = i1+i2;
    *j_ans = j1+j2;
}

void subtraction(int repeat, double *prev_i, double *prev_j)
{
    double i1, j1, i2, j2;
    int option;
    char* string = "Enter 1st term";
    char* string2 = "Enter 2nd term";
    if(repeat == 0)
    {
        system("clear");
        prompt(&i1, &j1, string);
        system("clear");
        prompt(&i2, &j2, string2);
        system("clear");
    }
    else if(repeat > 0)
    {
        prompt2('s', &option);
        if(option == 1)
        {
            i1 = *prev_i;
            j1 = *prev_j;
            system("clear");
            prompt(&i2, &j2, string2);
            system("clear");
        }
        else if(option == 2)
        {
            i2 = *prev_i;
            j2 = *prev_j;
            system("clear");
            prompt(&i1, &j1, string);
            system("clear");
        }
    }
    subtract_complex(i1, j1, i2, j2, prev_i, prev_j);
    answer(*prev_i, *prev_j);
}


void subtract_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans)
{
    *i_ans = i1-i2;
    *j_ans = j1-j2;
}

void multiplication(int repeat, double *i, double *j)
{
    double i1, j1, i2, j2;
    int option;
    
    char* string = "Enter 1st term";
    char* string2 = "Enter 2nd term";
    if(repeat == 0)
    {
        system("clear");
        prompt(&i1, &j1, string);
        system("clear");
        prompt(&i2, &j2, string2);
        system("clear");
    }
    else if(repeat > 0)
    {
        prompt2('m', &option);
        if(option == 1)
        {
            i1 = *i;
            j1 = *j;
            system("clear");
            prompt(&i2, &j2, string2);
            system("clear");
        }
        else if(option == 2)
        {
            i2 = *i;
            j2 = *j;
            system("clear");
            prompt(&i1, &j1, string);
            system("clear");
        }
    }

    multiply_complex(i1, j1, i2, j2, i, j);
    answer(*i, *j);
}

void multiply_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans)
{
    double t1, t2, t3, t4;
    t1 = i1 * i2;
    t2 = i1 * j2;
    t3 = j1 * i2;
    t4 = j1 * j2 * -1.00;
    *i_ans = t1 + t4;
    *j_ans = t2 + t3;
}
/*
void multiply_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans)
{
    double r1, t1, r2, t2, r_ans, t_ans;
    rec_to_polar(&r1, &t1, i1, j1);
    rec_to_polar(&r2, &t2, i2, j2);
    r_ans = r1*r2;
    t_ans = t1+t2;
    polar_to_rec(r_ans, t_ans, i_ans, j_ans);
}
*/
void division(int repeat, double *i, double *j)
{
    double i1, j1, i2, j2;
    int option;
    char* string = "Enter Numerator";
    char* string2 = "Enter Denominator";
    if(repeat == 0)
    {
        system("clear");
        prompt(&i1, &j1, string);
        system("clear");
        prompt(&i2, &j2, string2);
        system("clear");
    }
    else if(repeat > 0)
    {
        prompt2('d', &option);
        if(option == 1)
        {
            i1 = *i;
            j1 = *j;
            system("clear");
            prompt(&i2, &j2, string2);
            system("clear");
        }
        else if(option == 2)
        {
            i2 = *i;
            j2 = *j;
            system("clear");
            prompt(&i1, &j1, string);
            system("clear");
        }
    }
    
    divide_complex(i1, j1, i2, j2, i, j);
    answer(*i, *j);
}

void divide_complex(double i1, double j1, double i2, double j2, double *i_ans, double *j_ans)
{
    double r1, t1, r2, t2, r_ans, t_ans;
    rec_to_polar(&r1, &t1, i1, j1);
    rec_to_polar(&r2, &t2, i2, j2);
    r_ans = r1/r2;
    t_ans = t1-t2;
    polar_to_rec(r_ans, t_ans, i_ans, j_ans);
}

/*----------menu functions---------------*/

void prompt(double *i, double *j, char* string)
{
    double r, t;
    int cont = 0;
    char choice[2];
    system("clear");
    printf("polar or rectangular?(p/r)\n");
    scanf("%1s", choice);
    switch(*choice)
    {
        case 'p':
            do{
                system("clear");
                printf("%s\n", string);
                get_polar(&r, &t);
                system("clear");
                printf("%s\n", string);
                print_polar(r, t);
                polar_to_rec(r, t, i, j);
                cont = happy();
            }
            while (cont == 0);
            break;
        case 'r':
            do{
                system("clear");
                printf("%s\n", string);
                get_rect(i, j);
                system("clear");
                printf("%s\n", string);
                print_rect(*i, *j);
                cont = happy();
            }
            while (cont == 0);
            break;
        default:
            break;
    }
    
}

void prompt2(char option, int* ans)
{
    system("clear");
    switch(option)
    {
        case 'm':
            printf("(i1+j1) * (i2+j2))\n");
            printf("1st term or 2nd term? (1/2):\n");
            scanf("%d", ans);
            break;
        case 'd':
            printf("(i1+j1) / (i2+j2)\n");
            printf("numerator or denominator? (1/2):\n");
            scanf("%d", ans);
            break;
        case 's':
            printf("(i1+j1) - (i2+j2)\n");
            printf("1st term or 2nd term?(1/2):\n");
            scanf("%d", ans);
            break;
        case 'a':
            printf("(i1+j1) + (i2+j2)\n");
            printf("1st term or 2nd term?(1/2):\n");
            scanf("%d", ans);
            break;
        case 'p':
            printf("(i1+j1) // (i2+j2)\n");
            printf("1st term or 2nd term?(1/2):\n");
            scanf("%d", ans);
            break;
        default:
            break;

    }
}

void answer(double i_ans, double j_ans)
{
    double r_ans, t_ans;
    system("clear");
    printf("rectangular:\n");
    print_rect(i_ans, j_ans);
    rec_to_polar(&r_ans, &t_ans, i_ans, j_ans);
    printf("polar:\n");
    print_polar(r_ans, t_ans);
    printf("\n");
}

void get_polar(double* amplitude, double* angle)
{
    *amplitude = 0.00;
    *angle = 0.00;
    print_polar(*amplitude, *angle);
    printf("Enter amplitude(r):\n");
    *amplitude = get_float();
    system("clear");
    print_polar(*amplitude, *angle);
    printf("Enter angle(θ):\n");
    *angle = get_float();
}

void get_rect(double* i, double* j)
{
    *i = 0.00;
    *j = 0.00;
    
    print_rect(*i, *j);
    

    printf("Enter i: \n");
    *i = get_float();
    system("clear");
    print_rect(*i, *j);
    printf("Enter j:\n");
    *j = get_float();
}


int happy()
{
    char string;
    int cont;
    printf("\ncontinue? y-n ");
    scanf(" %c", &string);
    if(string == 'y')
        cont = 1;
    else
        cont = 0;
    return cont;
}

/*-----------typesafe functions-----------*/
/* must include <errno.h>,<stdlib.h> and <stdio.h> */
double get_float()
{
    char string[10]; /* arbitrary length of string 10 */
    char *ptr;
    double result;
    double output;
    
    scanf(" %10s", string);
    errno = 0;
    result = strtod(string, &ptr);
    if(ERANGE != errno && !*ptr)
    {
        output = result;
    }
    else
        output = 0.00;
    return output;
}

void print_polar(double amplitude, double angle)
{
    printf("r = %.3f\n", amplitude);
    printf("θ = %.3f\n", angle);
}

void print_rect(double i, double j)
{
    printf("i = %.3f\n", i);
    printf("j = %.3f\n", j);
}

void polar_to_rec(double amplitude, double angle, double *i, double *j)
{
    double t1, t2;
    t1 = cos(angle*RAD);
    t2 = sin(angle*RAD);
    *i = amplitude*t1;
    *j = amplitude*t2;
}

void rec_to_polar(double *amplitude, double *angle, double i, double j)
{
    double t1, t2;
    t1 = ((i*i)+(j*j));
    t2 = (j/i);
    *amplitude = sqrt(t1);
    *angle = DEG * atan(t2);
}


