
#include <stdio.h>
#include <stdlib.h>

struct emple {
    char nombre[20];
    int legajo;
    char cate;
    float sueldo;
    int valido;
};

void guardar(){
    FILE *archivo;
    struct emple nume;
    
    archivo=fopen("empleado.dat","a+b");
        printf("Ingrese legajo: ");
        scanf("%d", &nume.legajo);
        fflush(stdin);
        
        nume.valido=1;
        
        printf("Ingrese nombre: ");
        scanf("%s", nume.nombre);
        fflush(stdin);

        printf("Ingrese sueldo: ");
        scanf("%f", &nume.sueldo);
        fflush(stdin);
        
        printf("Ingrese categoria: ");
        scanf("\n%c", &nume.cate);
        fflush(stdin);
        
        fwrite(&nume, sizeof(nume), 1, archivo);
    fclose(archivo);
}

void emitir(){
    FILE *archivo;
    struct emple nume;
    int cantreg, i=0;
    
    printf("Los empleados son:\n");
    
    archivo=fopen("empleado.dat","rb");
        fseek(archivo, 0, SEEK_END);
        cantreg=ftell(archivo)/sizeof(nume);

        while(i<cantreg){
            fseek(archivo, i*sizeof(nume), SEEK_SET);
            fread(&nume, sizeof(nume), 1, archivo);
            if(nume.valido==1){
                printf("Legajo: %d\tNombre: %s\tSueldo: %.2f\tCategoria: %c\n", nume.legajo, nume.nombre, nume.sueldo, nume.cate);
            }
            i++;
        }

    fclose(archivo);
}

void buscaryemitir(){
    FILE *archivo;
    struct emple nume;
    int cantreg, i, leg;
    
    printf("Ingrese legajo: ");
    scanf("%d", &leg);

    archivo=fopen("empleado.dat","rb");
        fseek(archivo, 0, SEEK_END);
        cantreg=ftell(archivo)/sizeof(nume);

        for(i=0;i<cantreg;i++){
            fseek(archivo, i*sizeof(nume), SEEK_SET);
            fread(&nume, sizeof(nume), 1, archivo);
                if((nume.valido==1)&&(nume.legajo==leg)){
                    printf("Legajo: %d\tNombre: %s\tSueldo: %.2f\tCategoria: %c\n", nume.legajo, nume.nombre, nume.sueldo, nume.cate);
                }
        }

    fclose(archivo);
}

void modificardatos(){
    FILE *archivo;
    struct emple nume;
    int cantreg, i, leg;
    
    printf("Ingrese legajo: ");
    scanf("%d", &leg);

    archivo=fopen("empleado.dat","r+b");
        fseek(archivo, 0, SEEK_END);
        cantreg=ftell(archivo)/sizeof(nume);

        for(i=0;i<cantreg;i++){
            fseek(archivo, i*sizeof(nume), SEEK_SET);
            fread(&nume, sizeof(nume), 1, archivo);
            if((nume.valido==1)&&(nume.legajo==leg)){
                printf("Ingrese nombre: ");
                scanf("%s", nume.nombre);
                fflush(stdin);
        
                printf("Ingrese sueldo: ");
                scanf("%f", &nume.sueldo);
                fflush(stdin);
        
                printf("Ingrese categoria: ");
                scanf("%c", &nume.cate);
                fflush(stdin);
        
                fseek(archivo, -sizeof(nume), SEEK_CUR);
                fwrite(&nume, sizeof(nume), 1, archivo);
            }
        }
    
    fclose(archivo);
}

void dardebaja(){
    FILE *archivo;
    struct emple nume;
    int cantreg, i, leg;
    
    printf("Ingrese legajo: ");
    scanf("%d", &leg);

    archivo=fopen("empleado.dat","r+b");
        fseek(archivo, 0, SEEK_END);
        cantreg=ftell(archivo)/sizeof(nume);

        for(i=0;i<cantreg;i++){
            fseek(archivo, i*sizeof(nume), SEEK_SET);
            fread(&nume, sizeof(nume), 1, archivo);
        
            if((nume.legajo==leg)&&(nume.valido==1)){
                nume.valido=0;
                fseek(archivo, -sizeof(nume), SEEK_CUR);
                fwrite(&nume, sizeof(nume), 1, archivo);
            }
        }

    fclose(archivo);
}

void main(){
    int consulta;

    printf("MENU DE OPCIONES\n");
    printf("0-Salir\n");
    printf("1-Guardar empleado\n");
    printf("2-Emitir datos\n");
    printf("3-Buscar legajo y emitir\n");
    printf("4-Buscar legajo y modificar\n");
    printf("5-Dar de baja\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &consulta);

    while(consulta!=0){
        switch(consulta){
            case 1:
                guardar();
                break;
            case 2:
                emitir();
                break;
            case 3:
                buscaryemitir();
                break;
            case 4:
                modificardatos();
                break;
            case 5:
                dardebaja();
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }

        // system("pause");
        // system("cls");
        system("read -p 'Presione Enter para continuar...' var");
        system("clear");
        printf("MENU DE OPCIONES\n");
        printf("0-Salir\n");
        printf("1-Guardar empleado\n");
        printf("2-Emitir datos\n");
        printf("3-Buscar legajo y emitir\n");
        printf("4-Buscar legajo y modificar\n");
        printf("5-Dar de baja\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &consulta);
    }
    // system("pause");
    system("read -p 'Presione Enter para continuar...' var");
}
