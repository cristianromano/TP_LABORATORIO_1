#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"


int menu()
{

    int opcion = 0;

    printf("1.INGRESAR NUMEROS\n");
    printf("2.SUMAR\n");
    printf("3.RESTAR\n");
    printf("4.MULTIPLICAR\n");
    printf("5.DIVIDIR\n");
    printf("6.FACTORIZAR\n");
    printf("7.HACER TODOS LOS CALCULOS\n");
    printf("8.SALIR\n");


    printf("eliga una opcion: ");
    scanf("%d",&opcion);

    return opcion;


}

void clean()
{
    system("cls");
}

void pause()
{
    system("pause");
}


float ingreseNumero()
{
    clean();
    float numero = 0;
    printf("ingrese el numero:");
    scanf("%f",&numero);


    return numero;

}


void mostrarNumero(float x)
{

    printf("1.numero: (A=%.1f)\n",x);
}

void mostrarNumeroB(float x)
{

    printf("2.numero: (B=%.1f)\n",x);

}

void bannerdemierda()
{
    printf("*******************\n");
}


float sumar(float a, float b)
{
    float suma = a + b;
    printf("la suma equivale a: %.2f\n",suma);
    return suma;

}

float restar(float a, float b)
{
    float resta = a - b;
    printf("la resta equivale a: %.2f\n",resta);
    return resta;

}

float multiplicar(float a, float b)
{
    float multiplicar = a * b;
    printf("la multiplicacion equivale a: %.2f\n",multiplicar);
    return multiplicar;

}


float division(float a, float b)
{

    if(b != 0)
    {
        float division = a / b;
        printf("la division equivale a: %.2f\n",division);
        return division;
    }
    else
    {
        printf("no se puede dividir por cero.\n");

    }


    return -1;
}


int factorialA(int a)
{

    int resultado=1, iteracion;

    if(a<0)
    {
        printf("no se puede factoriar %d es un numero negativo.\n",a);
    }

    else
    {
        for(iteracion=a ; iteracion>0; iteracion--)
        {
            resultado=resultado*iteracion;
        }
        printf("el numero factorizado de A es: %d\n",resultado);
    }


    return resultado;

}

int factorialB(int b)
{

    int resultado=1, iteracion;

    if(b<0)
    {
        printf("no se puede factoriar %d es un numero negativo.\n",b);
    }

    else
    {
        for(iteracion=b ; iteracion>0; iteracion--)
        {
            resultado=resultado*iteracion;
        }
        printf("el numero factorizado de B es: %d\n",resultado);
    }


    return resultado;

}


void funcionFactorial(float a, float b)
{

    char rta = ' ';
    int trigger = 0;

    int cambioA = (int) a;
    int cambioB = (int) b;

do{

    printf("cual de los dos numeros desea factorizar - A o B ?: ");
    fflush(stdin);
    scanf("%c",&rta);

    char s = toupper(rta);

    switch(s)
    {
    case 'A':
        if(a < 0)
        {
            printf("no se puede factoriar un numero negativo.\n");
        }

        else
        {
            factorialA(cambioA);
            trigger = 1;
        }
        break;

    case 'B':

        if(b < 0)
        {
            printf("no se puede factoriar un numero negativo.\n");
        }

        else
        {
            factorialB(cambioB);
            trigger = 1;
        }
        break;

    default:
        printf("eliga opcion A o B\n");
        break;

    }


}while(trigger==0);

}


void saludar()
{
    printf("adios.\n\n");
}

void msjErr()
{
    printf("\nNO ES UNA OPCION\n");
}

void verificacion()
{
    printf("\nINGRESE LOS NUMEROS PRIMERO\n");
}
void realizarTodo(float a, float b)
{
    printf("RESULTADOS\n");
    printf("***********\n");
    mostrarNumero(a);
    mostrarNumeroB(b);
    printf("***********\n");
    printf("\n");
    sumar(a,b);
    restar(a,b);
    multiplicar(a,b);
    division(a,b);
    factorialA(a);
    factorialB(b);
    printf("\n\n");

}


void esqueleto()
{
    char seguir = 's';
    int opcion = 0, trigger = 0;
    float A = 0, B = 0;


    do
    {

        mostrarNumero(A);
        mostrarNumeroB(B);
        bannerdemierda();

        opcion = menu();

        switch(opcion)
        {
        case 1:
            A = ingreseNumero();
            B = ingreseNumero();
            trigger = 1;
            break;

        case 2:
            if(trigger == 1)
            {
                clean();
                sumar(A,B);
            }

            else
            {
                verificacion();
            }
            break;

        case 3:
            if(trigger == 1)
            {
                clean();
                restar(A,B);

            }

            else
            {
                verificacion();
            }

            break;

        case 4:
            if(trigger == 1)
            {
                clean();
                multiplicar(A,B);

            }

            else
            {
                verificacion();
            }

            break;

        case 5:
            if(trigger == 1)
            {
                clean();
                division(A,B);

            }

            else
            {
                verificacion();
            }

            break;

        case 6:
            if(trigger == 1)
            {
                clean();
                funcionFactorial(A,B);

            }

            else
            {
                verificacion();
            }

            break;

        case 7:
            if(trigger == 1)
            {
                clean();
                realizarTodo(A,B);

            }

            else
            {
                verificacion();
            }

            break;

        case 8:
            clean();
            seguir = 'n';

            break;

        default:
            msjErr();
            limpiarBuffer();

            break;
        }


        pause();
        clean();

    }
    while(seguir == 's');


}

void limpiarBuffer()
{
    fflush(stdin);
}





























