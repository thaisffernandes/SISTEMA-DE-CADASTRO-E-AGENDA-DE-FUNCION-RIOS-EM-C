/*SISTEMA DE CADASTRO E AGENDA DE FUNCIONÁRIOS EM C 

Curso: Ciência da Computação
Disciplina: Introdução à Ciência da Computação
Grupo: Ana Julia Ferreira Mendes, João Vitor Rodrigues Lima e Thais Fernandes Silva
*/ 

#include <stdio.h> 
#include <string.h> 

//Declaração de cada uma das funções que serão utilizadas no código

int cadastrarFuncionario(char nome[][50], char email[][30], float salario[], int qtd); 
void mostrarFuncionarios(char nome[][50], char email[][30], float salario[], int qtd);  
void buscarFuncionarios(char nome[][50], char email[][30], float salario[], int qtd);
void maiorSalario(char nome[][50], float salario[], int qtd);
void mediaSalarial(float salario[], int qtd);


int main() {     
    char nome[10][50];   //Declaração das matrizes, vetores e das variáveis
    char email[10][30];     
    float salario[10];    

    int opcao;     
    int qtd = 0;      

//Utilização do do-while para que o menu apareça ao menos uma vez e possa repetir até que o usuário digite “6”

    do     {         
        printf("\n MENU DE OPÇOES\n");         
        printf("1 - Cadastrar novo funcionario\n");         
        printf("2 - Mostrar todos os funcionarios\n");         
        printf("3 - Buscar funcionario\n");         
        printf("4 - Mostrar maior salario\n");        
        printf("5 - Mostrar media salarial\n");         
        printf("6 - Sair\n");         
        printf("Escolha uma opcao: ");         
        scanf("%d", &opcao);     

//Cada opção levará para uma função

        switch(opcao)         
        {             
            case 1:                 
                qtd = cadastrarFuncionario(nome, email, salario, qtd);                
                break;  

            case 2: 
                mostrarFuncionarios(nome, email, salario, qtd);                 
                break;      

            case 3:                 
                buscarFuncionarios(nome, email, salario, qtd);                 
                break;     

            case 4:                 
                maiorSalario(nome, salario, qtd);                 
                break; 

            case 5:                 
                mediaSalarial(salario, qtd);               
                break;           

            case 6:                 
                printf("Programa encerrado.\n");                 
                break;        

            default:                 
                printf("Opcao invalida.\n");         
            }   

        } while(opcao != 6);      
        return 0; 
    
//Função que irá cadastrar os funcionários, guardando o nome, email e o salário (opção 1)

    }  
    int cadastrarFuncionario(char nome[][50], char email[][30], float salario[], int qtd) 
    {     
        if(qtd == 10)     
        {         
            printf("\nAgenda cheia! Nao e possivel cadastrar mais funcionários.\n");         
            return qtd;     
        }      
        printf("\nDigite o nome do funcionario: ");     
        scanf(" %[^\n]", nome[qtd]);  

        printf("Digite o e-mail: ");     
        scanf(" %[^\n]", email[qtd]);  

        printf("Digite o salario: ");     
        scanf("%f", &salario[qtd]);   

        printf("\nFuncionário cadastrado com sucesso!\n");      
        
        return qtd + 1; 
    }  
    
//Função que irá mostrar na tela todas as informações dos usuários cadastrados (opção 2)

    void mostrarFuncionarios(char nome[][50], char email[][30], float salario[], int qtd) 
    {     
        int i;      
        if(qtd == 0)     
        {         
            printf("\nNenhum funcionário cadastrado.\n");         
            return;     
        }   

        printf("\nFUNCIONARIOS CADASTRADOS \n");  
        for(i = 0; i < qtd; i++) 
        { 
            printf("\nFuncionario %d\n", i + 1); 
            printf("Nome: %s\n", nome[i]); 
            printf("E-mail: %s\n", email[i]); 
            printf("Salario: R$ %.2f\n", salario[i]); 
        }  
    }

//Função responsável por buscar um funcionário e mostrar suas informações (opção 3)

    void buscarFuncionarios(char nome[][50], char email[][30], float salario[], int qtd)
    {
        char nome_compl[50];
        int encontrado = 0;
        
        if(qtd == 0){         
            printf("\nNenhum funcionário cadastrado.\n");         
            return;     
        } 
        
        printf("Digite o nome completo: ");
        scanf(" %[^\n]", nome_compl);
        
        for (int i = 0; i < 10; i++){
                if ((strcmp(nome[i], nome_compl) == 0)){
                    encontrado = 1;
                    printf("\nNome: %s\n", nome_compl);
                    printf("Índice: %d\n", i);
                    printf("Email: %s\n", email[i]);
                    printf("Salário: %.2f\n", salario[i]);
                }
        }
        if (encontrado == 0){
            printf("Não foi encontrado!\n");
        }
    }

//Função responsável por mostrar o maior salário e o nome da pessoa (opção 4)

    void maiorSalario(char nome[][50], float salario[], int qtd){
        
        float maior_sal;
        char nome_maior[50];
        
        if(qtd == 0){         
            printf("\nNenhum funcionário cadastrado.\n");         
            return;     
        } 
        
        maior_sal = salario[0];
        for (int i = 1; i < qtd; i++){
            if (salario[i] > maior_sal){
                maior_sal = salario[i];
                strcpy(nome_maior, nome[i]);
            }
        }
        printf("\nO maior salário é de %s. O valor é %.2f\n", nome_maior, maior_sal);
    }

// Função que mostra a média salarial (opção 5)

void mediaSalarial(float salario[ ], int qtd) {
if (qtd == 0) {
printf("Nenhum funcionário cadastrado.\n");
return;
}

float soma = 0;

for (int i = 0; i < qtd; i++) {
    soma += salario[i];
}

printf("Media: %.2f\n", soma / qtd);

}

