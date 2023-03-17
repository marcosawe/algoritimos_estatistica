#include <stdio.h>
#define SIZE 100 
#include <locale.h>

void mean(const int answer[]);
void median(int answer[]);
void mode(int frequency[],const int answer[]);
void bubbleSort(int a[]);
void printArray(const int a[]);

// Ponto de entrada da aplicação
int main()
{
    setlocale(LC_ALL,"PT-BR");
    int frequency[9];
    int responce[SIZE] = { //Inicializa a frequência do array
        6,  4,  6,  4,  7,  3,  9,  5,  3,  7,
        5,  9,  3,  3,  2,  5,  9,  1,  6,  6,
        9,  5,  6,  6,  2,  5,  7,  8,  9,  9,
        3,  5,  8,  9,  2,  9,  4,  3,  5,  3,
        6,  4,  1,  4,  3,  9,  6,  8,  8,  7,
        7,  6,  2,  9,  5,  9,  2,  5,  1,  8,
        6,  2,  6,  1,  5,  6,  2,  3,  8,  9,
        4,  7,  8,  1,  9,  5,  4,  3,  2,  6,
        6,  1,  7,  7,  5,  1,  9,  3,  4,  4,
        6,  4,  7,  3,  6,  3,  6,  4,  5,  7

    };
    // Evocando as funções
    mean(responce);
    median(responce);
    mode(frequency,responce);
    
    //Retornando o escopo da função main
    return 0;
}
//Calcula a média de todos os valores de resposta
void mean(const int answer[]){
    int j; //Contador para totalizar os elementos do array
    int total = 0; //Variável para manter a soma dos elementos do array
    
    printf("********* \n");
    printf("* MÉDIA * \n");
    printf("********* \n");
    
    for(j=0; j< SIZE; j++){
        total += answer[j];
    }
    
    double media = total / SIZE;
    
    printf("A média (Me) é calculada somando-se todos os valores de um conjunto \n" 
    "de dados e dividindo-se pelo número de elementos deste conjunto. \n");
    printf("O valor médio para esse conjunto que possui %d elementos é de"
    "%2.f\n",SIZE,media);
}//Fim da execução da média.

//Ordena array e determina valor do elemento mediano
void median(int answer[]){
    printf("***********\n");
    printf("* MEDIANA *\n");
    printf("***********\n");

    printArray(answer); // Exibe array não ordenado;
    bubbleSort(answer); //Ordena Array

    printf("\n\nO Array ordenado é:");
    printArray(answer);

    //Define o que é Médiana
    printf("\n\nA mediana é o valor central de um conjunto de números colocados por ordem de grandeza. Trata-se do número que se encontra exatamente no centro, de modo que 50%% dos números são superiores e 50%% são inferiores a essa mediana.\n\n");
    //Exibe os valores da Mediana
    printf("\n\nA mediana é o elemento %d do array ordenado de %d elementos.\n\n"
    "Para essa execução, a mediana é %d\n\n", SIZE/2,SIZE,answer[SIZE/2]);
}//Fim da execução da mediana

void mode(int frequency[],const int answer[]){
    int rating; //Contador para acessar os elementos de 1-9 do array frequency
    int j; //Contador para resumir os elementos de 0-98 do array answer
    int h;//Contador para contar os histogramas dos elementos no array answer
    int largest = 0; //Representa a maior frequência 
    int modeValue; //Representa a resposta mais frequente

    printf("********\n");
    printf("* MODA *\n");
    printf("********\n");

    //Inicializando a frequência em 0
    for ( rating = 0; rating <= 9; rating++){
        frequency[rating] = 0;
    }; //Fim do for
    
    //Frequência de resumos
    for ( j = 0; j < SIZE; j++){
        ++frequency[answer[j]];
    } //Fim do for

    printf("%s  %s  %s \n\n", "Respostas","Freqencia","Histograma"); 

    for ( rating = 1; rating <= 9; rating++){
        printf("%8d%11d",rating,frequency[rating]);
    
    
    //Acompanha o valor da moda e o valor da freqência
    if (frequency[rating]>largest){
        largest = frequency[rating];
        modeValue = rating;
    } //Fim do if

    //Barra de histograma de saída de impressão que representa o valor de frequência
    for ( h = 1; h <= frequency[rating]; h++){
        printf("    *");
    } //Fim do for interno
    
    printf("\n"); //Nova linha de saída

    } // Fim do for externo

    // Exibe o valor da moda
    printf("\n\nModa: o número mais frequente, ou seja, o número que aparece o maior número de vezes.\n"
    "Para essa execução, a moda é %d, que ocorreu %d vezes\n\n",modeValue,largest);

}//Fim da função mode

// Função que ordena um array em escalas com algoritimo com o algoritimo bubbleSort
void bubbleSort(int a[]){
    int pass; //Contador de passe
    int j; //Contador de comparação
    int hold; //Local temporario usado para troca de elementos

    //Loop para controlar números de passadas
    for ( pass = 1; pass < SIZE; pass++){

        //Loop para controlar número de comparações por passada
        for ( j = 0; j < SIZE-1; j++){
            //Troca elemetos se estiverem fora de ordem
            if (a[j] > a[j+1]){
                hold = a[j];
                a[j] = a[j+1];
                a[j+1] = hold;
            }//Fim do if
            
        }//Fim do for interno
        
    }//Fim do for externo
    
}//Fim da função bubbleSort

// Imprime o conteúdo do array de resultados (20 valores por linha)
void printArray(const int a[]){
    int j; //Contador

    //imprime o conteúdo do Array
    for(j = 0; j <SIZE; j++){
        
        //Inicia uma linha a cada 20 nvalores
        if(j % 20 == 0){
            printf("\n\n");
        }//Fim do if

        printf(" %2d ",a[j]);
    }//Fim do for

}//Fim da função do printArray