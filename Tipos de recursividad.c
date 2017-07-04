#include <stdio.h>
#include <stdlib.h>

void saludo(int n);
int factorial(int n);
int fibonacci(int n);
int sacar_mcd(int a, int b);
int par(int n);
int impar(int n);
int multiplica(int a, int b);
int sumar_dig(int n);
int invertir(int n, int digitos);

int main(){

int opcion, cantidadsaludos, fact, fibo, a, b, paroimpar, sumad, x, digitos, tmp, rev, whipep=0;

do{
printf("  / / / Seleccione una opcion \\ \\ \\ \n");
printf(" ----------------------------------- \n");
printf("1 - Cartel Buenas tardes\n");
printf("2 - Factorial\n");
printf("3 - Fibonacci\n");
printf("4 - Maximo comun divisor\n");
printf("5 - Par devuelve 1, impar devuelve 0\n");
printf("6 - Multiplicacion\n");
printf("7 - Suma las cifras de un numero\n");
printf("8 - Coloca las cifras de un numero al revez\n");
putchar('\n');
printf("          ");
scanf("%d", &opcion);
putchar('\n');

switch (opcion){

    case 1:
            printf("Ingrese un numero: \n");
            scanf("%d", &cantidadsaludos);
            saludo(cantidadsaludos);
            putchar('\n');
            break;
    case 2:
            printf("Ingrese un numero: ");
            scanf("%d", &fact);
            printf("El factorial es %d\n", factorial(fact));
            putchar('\n');
            break;
    case 3:
            printf("Ingrese un numero: ");
            scanf("%d", &fibo);
            printf("El fibonacci es %d\n", fibonacci(fibo));
            putchar('\n');
            break;
    case 4:
            printf("Ingrese primer numero: ");
            scanf("%d", &a);
            printf("Ingrese segundo numero: ");
            scanf("%d", &b);
            printf("El maximo comun divisor es %d\n", sacar_mcd(a, b));
            putchar('\n');
            break;
    case 5:
            printf("Ingrese un numero: ");
            scanf("%d", &paroimpar);
            printf("El numero es %d\n", par(paroimpar));
            putchar('\n');
            break;
    case 6:
            printf("Ingrese primer numero: ");
            scanf("%d", &a);
            printf("Ingrese segundo numero: ");
            scanf("%d", &b);
            printf("El numero %d\n", multiplica(a, b));
            putchar('\n');
            break;
    case 7:
            printf("Ingrese un numero: ");
            scanf("%d", &sumad);
            printf("La suma de sus cifras es %d\n", sumar_dig(sumad));
            putchar('\n');
            break;
    case 8:
            printf("Ingrese un entero: ");
            scanf("%d", &x);
            digitos=1;
            tmp=x;
            while (tmp>=10){
            tmp=tmp/10;
            // printf("tmp es:%d\n",tmp);
            digitos=digitos*10;
            // printf("digitos es:%d\n",digitos );
            }
            rev=invertir(x, digitos);
            printf("El resultado es %d\n", rev);
            putchar('\n');
            break;

    default:
            printf("Caracter no valido\n");
            putchar('\n');
            break;
}

printf("Desea seguir intentando?\n");
printf("1- NO\n");
printf("2- SI\n");
scanf("%d", &whipep);
}while (whipep!=1);

system("pause");
return 0;
}
/*--------------------------------------------------------------*/
void saludo(int n){
if(n>0){
        printf("%d->Buenas tardes...\n", n);
        saludo(n-1);//llamada a si misma: RECURSITIVITY
        }
}
/*--------------------------------------------------------------*/
int factorial(int n){
        if(n==0) return 1; //AXIOMA
        else return n*factorial(n-1); // FORMULA
}
/*--------------------------------------------------------------*/
int fibonacci(int n){
        if((n==0) || (n==1)) return n;
        else return fibonacci(n-1)+fibonacci(n-2);
}
/*--------------------------------------------------------------*/
int sacar_mcd(int a, int b){
            if(b==0)
                    return a;
                else
                    return sacar_mcd(b, a%b);
}
/*--------------------------------------------------------------*/
int par(int n){
        if(n==0) return 1;
        else return impar(n-1);
        }
int impar(int n){
        if(n==0) return 0;
        else return par(n-1);
        }
/*--------------------------------------------------------------*/
int multiplica(int a, int b){
            if( b== 1){
                return a;
            }
             else{
              return a+multiplica(a, b-1);
             }
}
/*--------------------------------------------------------------*/
int sumar_dig(int n){
        if (n==0)
                return 0;
            else
                return sumar_dig (n/10)+(n%10);
}
/*--------------------------------------------------------------*/
int invertir(int n, int digitos){
int resto, cocie;
if (n<10) return n;
else{
    resto=n%10;
    cocie=n/10;
    return resto*digitos+invertir(cocie,digitos/10);
            }
}
/*--------------------------------------------------------------*/

