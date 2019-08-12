#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 5


struct empleados{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldob;
    char fecha_nac[11];
    char cargo[20];
    int cant_horasex;
    float sueldo_cobra;
};

void cargaemple(struct empleados emple[]);
void cargahorax(int extras[4][5]);
void emisionhorax(int extras[4][5]);
void promedios(int extras[4][5]);
void subirsueldo(struct empleados emple[], int extras[4][5]);
void quien_hizo_mas(struct empleados emple[], int extras[4][5]);


void main(){
    int whipep=0, opcion;
    struct empleados emple[4];
    int horasex[4][5]={ {5,8,5,8,3},
                        {1,6,1,1,3},
                        {1,8,9,8,9},
                        {9,2,5,9,1}};

    do{
        system("read -p 'Presione Enter para continuar...' var");
        system("clear");

        printf("INFORMACION DE EMPLEADOS\n");
        printf("1-Cargar empleados\n");
        printf("2-Cargar horas extras\n");
        printf("3-Emitir horas extras\n");
        printf("4-Sacar promedios\n");
        printf("5-Subir sueldos\n");
        printf("6-Quien hizo mas horas extras\n");
        printf("7-Salir\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                cargaemple(emple);
                putchar('\n');
                break;
            case 2:
                cargahorax(horasex);
                putchar('\n');
                break;
            case 3:
                emisionhorax(horasex);
                putchar('\n');
                break;
            case 4:
                promedios(horasex);
                putchar('\n');
                break;
            case 5:
                subirsueldo(emple, horasex);
                putchar('\n');
                break;
            case 6:
                quien_hizo_mas(emple,horasex);
                putchar('\n');
                break;
            case 7:
                whipep=1;
                break;
            default:
                printf("Opcion no valida\n");
        }

    }while(whipep!=1);
}

void cargaemple(struct empleados emple[]){
    int i;

    for(i=0;i<=3;i++){
        printf("Ingrese legajo: ");
        scanf("%d", &emple[i].legajo);

        printf("Ingrese nombre: ");
        scanf("%s", emple[i].nombre);

        printf("Ingrese apellido: ");
        scanf("%s", emple[i].apellido);

        printf("Ingrese sueldo basico: ");
        scanf("%f", &emple[i].sueldob);

        printf("Ingrese fecha de nacimiento: ");
        scanf("%s", emple[i].fecha_nac);

        printf("Ingrese cargo: ");
        scanf("%s", emple[i].cargo);
    }
}

void emisionhorax(int extras[4][5]){
    int i, j, k;

    for(i=0;i<=3;i++){
        for(j=0;j<=4;j++){
            printf("[%d][%d]=%d\t",i, j, extras[i][j]);
        }
        putchar('\n');
    }

    putchar('\n');
}


void cargahorax(int extras[4][5]){
    int i, j ,k;

    for(i=0;i<=3;i++){
        for(j=0;j<=4;j++){
            printf("Ingrese valor de la tabla[%d][%d]\n",i,j);
            scanf("%d", &extras[i][j]);
        }
    }
}

void promedios(int extras[4][5]){
    int i, j, aux1=0, aux2=0;
    float promemple[4], promdia[5];

    /*PROMEDIO POR FILA*/
    for(i=0;i<=3;i++){
        for(j=0;j<=4;j++){
            aux1+=extras[i][j];
        }
        promemple[i]=(float)aux1/5;
        aux1=0;
    }

    for(i=0;i<=3;i++){
        printf("El promedio por empleado es %.2f\n", promemple[i]);
    }
    putchar('\n');

    /*PROMEDIO POR COLUMNA*/
    for(i=0;i<=3;i++){
        aux2=0;
        for(j=0;j<=3;j++){
            aux2+=extras[j][i];
        }
        promdia[i]=(float)aux2/4;
    }

    for(i=0;i<=3;i++){
        printf("El promedio por dia es %.2f\n", promdia[i]);
    }
    putchar('\n');
}



void subirsueldo(struct empleados emple[], int extras[4][5]){
    int sumar[5], aux1=0, aux2=0, i, j;

    /*SUMATORIA DE FILAS PARA SABER CANTIDAD DE HORAS*/
    for(i=0;i<=3;i++){
        for(j=0;j<=4;j++){
            aux1+=extras[i][j];
        }
        emple[i].cant_horasex=aux1;
        aux1=0;
    }

    /*IMPORTE PARA AGREGAR AL SUELDO*/
    for(i=0;i<=3;i++){
        aux2=(emple[i].sueldob*0.02);
        for(j=0;j<=4;j++){
            sumar[i]=aux2*emple[i].cant_horasex;
        }
    }

    /*SUELDO A COBRAR*/
    for(i=0;i<=3;i++){
        emple[i].sueldo_cobra=(sumar[i]+emple[i].sueldob);
    }

    for(i=0;i<=3;i++){
        printf("El sueldo de %s es ahora %.2f\n", emple[i].nombre, emple[i].sueldo_cobra);
    }
}


void quien_hizo_mas(struct empleados emple[], int extras[4][5]){
    int i, j, horas_ex[4];

    for(i=0;i<=3;i++){
        horas_ex[i]=0;
        for(j=0;j<=4;j++){
            horas_ex[i]+=extras[i][j];
        }
    }

    for(i=0;i<=3;i++){
        printf("%s hizo %d hs extras en total\n", emple[i].nombre, horas_ex[i]);
    }

    for(i=0;i<=3;i++){
        printf("%s Lunes: %d hs - Martes: %d hs - Miercoles: %d hs - Jueves: %d hs - Viernes: %d hs\n", emple[i].nombre, extras[i][0], extras[i][1], extras[i][2], extras[i][3], extras[i][4]);
    }
}

