#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_saida(int b, int e, int m){

    int i,resultado = b;

    for(i=1;i<e;i++){
	     resultado *= b;
    }
    resultado %= m;
    printf("A exponencial modular %d elevado a %d (mod %d) eh %d\n", b, e, m, resultado);

}

void imprime_erro(){

    printf("O modulo nao eh primo.\n");

}

int eh_primo(int m) {

    int d,				/* candidato a divisor */
     EhPrimo;			/* para indicar se o numero dado n 'e primo ou nao     */
	/* Convencao: EhPrimo = TRUE se o numero dado 'e primo */
	/*  EhPrimo = FALSE se o numero dado nao 'e primo        */

    if (m <= 1 || (m != 2 && m % 2 == 0))
	EhPrimo = 0;	/* nenhum numero inteiro <= 1 ou par > 2 e' primo */
    else
	EhPrimo = 1;		/* o numero e' primo ate que se prove o contrario */
    d = 3;

    while (EhPrimo && d <= m / 2) {
	if (m % d == 0)
	    EhPrimo = 0;
	d = d + 2;		/* testamos so' os  impares: 3, 5, 7... */
    }

    if (EhPrimo)
        return (1);
    else
        return (0);

}

int le_modulo(){

    int m;
    printf("modulo: ");
    scanf("%d", &m);

    return(m);
}

int main () {

    int b, e, m, resposta;

    printf("base: ");
    scanf("%d", &b);
    printf("expoente: ");
    scanf("%d", &e);

    m = le_modulo();

    resposta = eh_primo(m);

    if (!resposta)
        imprime_erro();
    else
        imprime_saida(b, e, m);

return 0;
}
