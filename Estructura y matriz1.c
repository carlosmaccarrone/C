#include <stdio.h>

struct empleados {
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
};

void cargaremple(struct empleados emple[]);
void emitiremple(struct empleados emple[]);
void ordenarleg(struct empleados emple[]);
void buscarleg(struct empleados emple[]);
void cargarmatriz(float matven[5][6]);
void emitirmatriz(float matven[5][6]);

main(){
struct empleados emple[4];
int opcion, whipep=0;
float matven[5][6]={{433,486,334,835,419,766},
                    {707,136,250,967,455,180},
                    {529,971,373,801,325,866},
                    {763,461,194,675,501,831},
                    {178,105,199,760,409,619}};
do{
printf("OPCIONES\n");
printf("1-Cargar empleados\n");
printf("2-Emitir empleados\n");
printf("3-Ordenar por numero legajo\n");
printf("4-Buscar por legajo\n");
printf("5-Cargar matriz\n");
printf("6-Ver matriz\n");
printf("7-salir\n");
scanf("%d", &opcion);
switch(opcion){

    case 1:
            cargaremple(emple);
            putchar('\n');
            break;
    case 2:
            emitiremple(emple);
            putchar('\n');
            break;
    case 3:
            ordenarleg(emple);
            putchar('\n');
            break;
    case 4:
            buscarleg(emple);
            putchar('\n');
            break;
    case 5:
            cargarmatriz(matven);
            putchar('\n');
            break;
    case 6:
            emitirmatriz(matven);
            putchar('\n');
            break;
    case 7:
            whipep=1;
            break;
    default:
            printf("Opcion invalida\n");
            break;


}
}while(whipep!=1);

}

void cargaremple(struct empleados emple[]){
int i;

for(i=0;i<=3;i++){
    printf("Ingrese N Legajo: ");
    scanf("%d", &emple[i].legajo);

    printf("Ingrese nombre: ");
    scanf("%s", emple[i].nombre);

    printf("Ingrese apellido: ");
    scanf("%s", emple[i].apellido);

    printf("Ingrese el sueldo: ");
    scanf("%f", &emple[i].sueldo);
    }
}

void emitiremple(struct empleados emple[]){
int i;

for(i=0;i<=3;i++){
    printf("Legajo N: %d\n", emple[i].legajo);
    printf("Nombre: %s\n", emple[i].nombre);
    printf("Apellido: %s\n", emple[i].apellido);
    printf("Sueldo: %.2f\n", emple[i].sueldo);
    putchar('\n');
    }
}

void ordenarleg(struct empleados emple[]){
int i, j;
struct empleados aux;

for(i=1;i<=3;i++){
j=i;
aux=emple[j];
        while(j>0 && aux.legajo<emple[j-1].legajo){
            emple[j]=emple[j-1];
            j--;
            }
   emple[j]=aux;
    }
}

void buscarleg(struct empleados emple[]){
int i, j;
struct empleados aux;
printf("Ingrese numero legajo a buscar: ");
scanf("%d", &j);

for(i=0;i<=3;i++){
    if(j==emple[i].legajo)
        aux=emple[i];
}

printf("Legajo: %d\nNombre: %s\nApellido: %s\nSueldo: %.2f\n", aux.legajo, aux.nombre, aux.apellido, aux.sueldo);
putchar('\n');
}

void cargarmatriz(float matven[5][6]){
int i, j;

for(i=0;i<=4;i++){
    for(j=0;j<=5;j++){
        printf("Tabla[%d][%d]: ", i, j);
        scanf("%f", &matven[i][j]);
        }
    }
}

void emitirmatriz(float matven[][6]){
int i, j;

for(i=0;i<=4;i++){
    for(j=0;j<=5;j++){
        printf("[%d][%d]= %.2f\t ", i, j, matven[i][j]);
        }
        putchar('\n');
    }
}
