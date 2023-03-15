#include<stdio.h>

struct No {
    int valor;
    No *proximo;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->proximo = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->proximo = NULL;
            cauda->proximo = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() { // O(n)
        /*for (No *aux = cabeca; aux != NULL; aux = aux->proximo) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->proximo;
        }
    }

    int tamanho() { // O(1)
        return n;
    }

    void excluirInicio() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->proximo;
                delete(aux);
            }
            n--;
        }
    }

    void excluirFinal() { // O(n)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->proximo != cauda) {
                    penultimo = penultimo -> proximo;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->proximo = NULL;
            }
            n--;
        }
    }
    
    void excluirNValores(int v) { // O(n*v)
    	while (v != 0) {
		excluirFinal();	
		v--;
		}
	}
	
	void excluirSegundoElemento(){
		if (!vazia()) {
			if (tamanho() == 1);
			else if (tamanho() == 2) excluirFinal();
			else{
				No *aux = cabeca->proximo;
				cabeca->proximo = aux->proximo;
				delete(aux);
				n--;
				
			}
		}
	}
	
	void introduzirTamanho(){
		inserirFinal(tamanho());
	}
	
	void imprimirMenorqueN(int v){
		No *aux = cabeca;
        while (aux != NULL) {
            if (v >= aux->valor)printf("%d\n", aux->valor);
            aux = aux->proximo;
        }
	}
	
	    void introduzirPenultimo(int v) { // O(n)
        if (!vazia()) {
            if (tamanho() == 1);
            else {
                No *penultimo = cabeca;
                while (penultimo->proximo != cauda) {
                    penultimo = penultimo->proximo;
                }
                No *novo = new No();
        		novo->valor = v;
                penultimo->proximo = novo;
                novo->proximo = cauda;
                n++;
            }  
        }
    }
};

int main() {

    return 0;
}
