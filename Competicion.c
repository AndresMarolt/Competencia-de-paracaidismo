#include <stdio.h>

int zona(int, int);

int main()
{
    int codigo, penalizaciones=-1, ganador;
    int X, Y;
    float puntaje, puntaje_ganador=0;

    printf("\t\t---COMPETENCIA DE PARACAIDISMO---\n\n");
    printf("Codigo de competidor (Ingresar numero menor que 0 para finalizar): ");
    scanf("%d", &codigo);
    while(codigo>0)
    {
        printf("Coordenadas (x, y): ");
        scanf("%d, %d", &X, &Y);

        if(zona(X, Y)==0)
            puntaje = 50;
        else if(zona(X, Y)==1)
            puntaje = 40;
        else if(zona(X, Y)==2)
            puntaje = 30;
        else if(zona(X, Y)==3)
            puntaje = 0;

        printf("Penalizaciones (entre 0 y 2): ");
        while(penalizaciones!=0 && penalizaciones !=1 && penalizaciones!=2)
        {
            scanf("%d", &penalizaciones);
            if(penalizaciones==0)
                puntaje = puntaje;
            else if(penalizaciones==1)
                puntaje -=(puntaje * 0.25);
            else if(penalizaciones==2)
                puntaje -= (puntaje * 0.5);
            else
                printf("Ingreso un numero que no esta entre 0 y 2. Por favor ingrese 0, 1 o 2: ");
        }
        penalizaciones = -1;

        if(puntaje>puntaje_ganador)
            {puntaje_ganador = puntaje;
            ganador = codigo;}

        printf("\nIngrese el codigo del siguiente participante (Ingresar numero menor que 0 para finalizar): ");
        scanf("%d", &codigo);
    }
    printf("\n\nCarga de datos finalizada. Gano el competidor %d con un puntaje de %.2f puntos.", ganador, puntaje_ganador);
    scanf("%d, %d", &X, &Y);
    printf("\nzona: %d", zona(X, Y));
}

int zona(int x, int y)
{
    float dist=0;
    dist = sqrt(x*x + y*y);
    if(dist<=5)
        return 0;
    else if(dist>5 && dist<=7.5)
        return 1;
    else if(dist>7.5 && dist<=15)
        return 2;
    else if(dist>15)
        return 3;
}

