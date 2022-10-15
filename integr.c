//program uses 3 methods
//3 types of rectangles

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*******************************************

presuming that function is cosh(x)

--------------------------------------------

function that counts sub-integral shape area

c here is variable for custom start (right and middle rect)

modify gives ability to use  trapezoidal method

            !!!NOTIFICATION!!! 
use modify correctly. int replaces bool type
                god bless C

***********************************************/

double areaCount(double step, int n, double c, int modify)
{
    double ans = 0; int boof = c;
    //boof keeps first value

    for (int i = 1; i <= n; i++)
    {
        ans += cosh(c);
        c += step;
    }

    //changes for trapezoidal method
    if (modify == 1)
    {
        /*one step ahead because
        this is the only method that requiers [0,n]*/

        ans+=cosh(c);
        //deduct halfs of the first and last elements
        ans -= (cosh(c)/2)+(cosh(boof)/2);
    }

    ans *= step;
    return(ans);
}

int main()
{
    //getting a number of rectangles and range [a,b]
    //plus asking about method of calculations
    int n, choice; double a, b;
    printf("print:\n1 for left rectangles\n2 for right rectangeles\n3 for middle rectangles\n");
    printf("4 for trapezoidal method\n5 for Simpson's rule\n>");
    scanf("%d", &choice);
    printf("range is [a,b]\nenter a >");
    scanf("%lf", &a);
    printf("enter b >");
    scanf("%lf", &b);

    //Sympsons method requiers even number of steps
    //for that case:
    if (choice == 5)
    {
        printf("enter even number of steps >");
        scanf("%d", &n);
        if (n % 2 != 0)
        {
            printf("An unknown error occused\n");
            exit(0);
        }
    }
    //if we choose different method
    else
    {
        printf("enter number of steps >");
        scanf("%d", &n);
    }

    //exeption
    if(a == b)
    {
        printf("area is 0");
        exit(0);
    }

    double answer=0;

    //step for dividing
    double step = (double)abs((b - a)) / n;


    /*---------------------------------------------------------------------*/


    switch (choice)
    {
    case(1):

        //left rectangles
    {
        answer = areaCount(step, n, a, 0);
        break;
    }
    case(2):
       
        //right rectangles
    {
        answer = areaCount(step, n, a + step, 0);
        break;
    }
    case(3):
        
        //middle rectangles
    {
        answer = areaCount(step, n, a+(step/2), 0);
        break;
    }
    case(4):

        //trapezoidal method

    {
        answer = areaCount(step, n, a, 1);
        break;
    }
    case(5):

        //simpson's rule

    {
        for (int i = 0; i <= n; i++)
        {
            //first and last - without modifications
            if ((i == 0) || (i == n))
                answer += cosh(a);

            //every even doubles
            else if (i % 2 == 0)
                answer += 2 * cosh(a);

            //every odd multiplies by 4
            else
                answer += 4 * cosh(a);

            a += step;
        }
        
        answer *= step / 3;
        break;
    }
    default:
        printf("An unknown error occused\n");
        exit(0);
    }
    printf("area is %lf", answer);
}