/*
    PROJETO FINAL: PET SHOP
    PROFESSOR: THESKO
    MATÉRIA: ALGORITMOS 1
    INTEGRANTES: RAFAEL ROMANELO e LUIZ FELIPE BAPTISTA
    
    
Resta: Indentar o código, implementar funções e corrigir funções coesas.
POR FAVOR, TESTE TODAS AS FUNCIONALIDADES SEMPRE QUE POSSÍVEL.
    
Obs: como segue abaixo, funções OU são coesas OU são completas (uma qualidade exclui a outra).
As demais não listadas não foram feitas ou implementadas.

Funções Coesas(FUNCIONAM, MAS NÃO ESTÃO COMPLETAS):
g: restam informações na struct

Funções Completas(NÃO PRECISAM DE ALTERAÇÃO): 
b
e
c
e
f
i
j

lUIZ FELIEPE BAPTISTA GAY
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Struct da data + validação de data
typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

Data data;

int validarData(Data data){
    if (data.ano < 1 || data.ano > 2023){
        return 0;
    }    
    if (data.mes < 1 || data.mes > 12){
        return 0;
    }    
    if (data.dia < 1 || data.dia > 30){
        return 0; 
    }
    return 1; 
}

//Tirar \n do fgets
void ler (char n[], int tam){
    fgets(n, tam - 2, stdin);
    n[strlen(n) - 1] = '\0';
}

//validar numero
int validNum(char num[]){
    if(strlen(num) >= 13 || strlen(num) <= 10){
        return 0;
    }
    
    if(num[0] != '0'){
        return 0;
    }
    
    return 1;
}

//validar nome
int validNome(char nm[]){
    if(strlen(nm) < 4){
        return 0;
    }
    
    if(nm[0] == ' '){
        return 0;
    }
    
    return 1;
}

//Struct cadastro cliente
typedef struct{
    char nome[50];
    char tnum[15];
}tpCliente;

//Struct para lançar cadastro no sistema


//Struct cadastro animal
typedef struct{
    tpCliente dono;
    Data nascimento;
    char agressive;    
    char animal[52];
    int especie;     
         
} tpAnimal; 

void buscar_c (tpCliente clientes[], tpAnimal animais[], int cont_c, int cont_a){

    int i, feito=0;
    char n[52];
    
    fgets(n, 50, stdin);
    n[strlen(n) - 1] = '\0';
    
    for(i=0;i<cont_c;i++){
        if(strcasecmp(n, clientes[i].nome)==0){
            printf("%-20sTelefone: %-20s", clientes[i].nome, clientes[i].tnum);
            feito++;
        }
    }
    
    for(i=0;i<cont_a;i++){
        if(strcasecmp(n, animais[i].dono.nome)==0){
            printf("Pet: %s\n", animais[i].animal);

        }
    }
    
    
    if(feito==0){
        printf("\nNão há nenhum %s\n", n);
    }
    
}

void listar (tpAnimal x[], int cont_a){
    
        int i, j;
        tpAnimal a;
        
        for(i=0; i<cont_a; i++){
                for(j=0; j<(cont_a - 1); j++){
                        if (strcasecmp(x[j].animal, x[j + 1].animal) > 0){
                                a = x[j];
                                x[j] = x[j + 1];
                                x[j + 1] = a;
                        }
                }
        }
        

//Saída de dados        
        printf("%-20s%-20s%s\n", "Animal", "Cliente", "Telefone");
        for(i=0; i<cont_a; i++){
                printf("%-20s%-20s%s\n", x[i].animal, x[i].dono.nome, x[i].dono.tnum);
                
        }
        
        
}

void aniversario (tpAnimal x[], int cont, int d, int m){
    int i,j;
    tpAnimal dia[13][32];
    
    
    
    for(i=0; i<13; i++){
        for(j=0; j<32; j++){
            dia[i][j].nascimento.dia = 0;
            dia[i][j].nascimento.mes = 0;
        }
    }
    
    for(i=0; i<cont; i++){
        dia[x[i].nascimento.mes][x[i].nascimento.dia] = x[i];
    }
    
    printf("%-20s Dia/Mes\n", "Pet");
    
    for(i=0;i<7;i++){
        if(m<=12){
            if (d < 31){
                d++;
                if(dia[m][d].nascimento.dia != 0){
                    printf("%-20s %02d/%02d\n", dia[m][d].animal, dia[m][d].nascimento.dia, dia[m][d].nascimento.mes);
                }
            } else {
                d = 0;
                m++;
            }
        }
    }
    
    
}

void listar_especies (tpAnimal x[], int cont){
    int i, j, num_animais=0;
    
    for(j=1;j<=4;j++){
    
        switch (j){
            case 1:
                printf("Cães:\n");
                    for(i=0; i<cont; i++){
                        if(x[i].especie==j){
                            printf("%-15s%d/%-15d", x[i].animal, x[i].nascimento.dia, x[i].nascimento.mes);
                            if(x[i].agressive == 'S' || x[i].agressive == 's'){
                                printf("Este animal é perigoso\n");
                            } else {
                                printf("Este animal é amigável\n");
                            }
                            num_animais++;
                        }
                    }
                    if(num_animais == 0){
                        printf("Não há animais dessa espécie.\n");
                    }
                    num_animais = 0;
                    break;
            case 2:
                printf("Gatos:\n");
                for(i=0; i<cont; i++){
                    if(x[i].especie==j){
                        printf("%-15s%d/%-15d", x[i].animal, x[i].nascimento.dia, x[i].nascimento.mes);
                            if(x[i].agressive == 'S' || x[i].agressive == 's'){
                                printf("Este animal é perigoso\n");
                            } else {
                                printf("Este animal é amigável\n");
                            }
                        num_animais++;
                    }
                }
                if(num_animais == 0){
                        printf("Não há animais dessa espécie.\n");
                    }
                num_animais = 0;
                break;
            case 3:
                printf("Pássaros:\n");
                for(i=0; i<cont; i++){
                    if(x[i].especie==j){
                       printf("%-15s%d/%-15d", x[i].animal, x[i].nascimento.dia, x[i].nascimento.mes);
                            if(x[i].agressive == 'S' || x[i].agressive == 's'){
                                printf("Este animal é perigoso\n");
                            } else {
                                printf("Este animal é amigável\n");
                            }
                        num_animais++;
                    }
                }
                if(num_animais == 0){
                        printf("Não há animais dessa espécie.\n");
                    }
                num_animais = 0;
                break;
            case 4:
                printf("Outros:\n");
                for(i=0; i<cont; i++){
                    if(x[i].especie==j){
                        printf("%-15s%d/%-15d", x[i].animal, x[i].nascimento.dia, x[i].nascimento.mes);
                            if(x[i].agressive == 'S' || x[i].agressive == 's'){
                                printf("Este animal é perigoso\n");
                            } else {
                                printf("Este animal é amigável\n");
                            }
                        num_animais++;
                    }
                }
                if(num_animais == 0){
                        printf("Não há animais dessa espécie.\n");
                    }
                num_animais = 0;
                break;
        }
        
        
    }
    

    
    
}

int main(){
    
//variaveis do menu principal
    char buscar[50];
    int menu,
        menu3,
        menuServicos,
        auxc,
        auxn,
        cont_clientes = 0,
        cont_pets = 0,
        k=0,
        l=0,
        m=-1,
        j,
        buscar_dia,
        buscar_mes,
        agressivos = 0;
    char ncd;

    tpAnimal animais[100];
    tpCliente clientes[100];
    
    strcpy(clientes[30].nome,"Mario");
    strcpy(clientes[30].tnum, "043996111715");
    strcpy(animais[30].animal, "Rex");
    strcpy(animais[30].dono.nome, "Mario");
    animais[30].nascimento.dia = 2;
    animais[30].nascimento.mes = 02;
    animais[30].agressive = 'n';
    animais[30].especie = 1;
    strcpy(animais[31].animal, "Meg");
    strcpy(animais[31].dono.nome, "Mario");
    animais[31].nascimento.dia = 3;
    animais[31].nascimento.mes = 03;
    animais[31].agressive = 's';
    animais[31].especie = 2;
    strcpy(animais[32].animal, "Leo");
    strcpy(animais[32].dono.nome, "Mario");
    animais[32].nascimento.dia = 4;
    animais[32].nascimento.mes = 04;
    animais[32].agressive = 's';
    animais[32].especie = 3;
    
//Senha e user para logar no admin
    char user[] = "admin",
         str[1000];
    char senha[] = "admin",
         pass[1000];
         
    
//Structc do cadastro cliente


//Struct do cadastro nanimal

//Struct do cadastro no sistema

//Colocando pessoas ja cadastradas



    //Interface Inicial
    printf("Olá, seja bem vindo ao RL Pet Shop!\n");
    printf("Qual o serviço desejado?:\n");
    do{
        printf("1- Cadastrar um cliente\n2- Cadastrar Animal\n3- Entrar como administrador\n4- Lançar um serviço\n5- Numero de Animais Agressivos\n6-Buscar Aniversariantes\n7-Listar por espécie\n8-Sair\n");
    
        scanf("%d", &menu);
        getchar();
        if(menu == 1){
            
            do{
                printf("Insira o nome completo:\n"); 
               
                //receber e validar o nome
                do{
                    fgets(clientes[cont_clientes].nome, 50, stdin);
                    clientes[cont_clientes].nome[strlen(clientes[cont_clientes].nome) - 1] = '\0';
                    
                    //função de validar nome
                    auxc = validNome(clientes[cont_clientes].nome);
                    if(auxc == 0){
                        printf("Nome inválido!\nDigite o nome novamente:\n");
                    }
                }while(auxc == 0);
                
                printf("Insira o número de telefone:\n");
              
                //receber e validar o numero
                do{
                    fgets(clientes[cont_clientes].tnum, 15, stdin);
                    
                    clientes[cont_clientes].tnum[strlen(clientes[cont_clientes].tnum) - 1] = '\0';
                    
                    //função de validar numero
                    auxn = validNum(clientes[cont_clientes].tnum);
                    if(auxn == 0){
                        printf("número inválido!\nDigite novamente o número:");
                    }
        
                }while(auxn == 0);
                printf("Cadastro Realizado!\n");
                
                //lançar cadastro no sistema
                printf("%s %s\n", clientes[cont_clientes].nome, clientes[cont_clientes].tnum);
                cont_clientes++;
                
                printf("Gostaria de cadastrar mais algum cliente? Pressione:\n(S)Sim\n(N)Não\n");
                scanf("%c", &ncd);
                getchar();
                
            }while(ncd == 'S'||ncd == 's');
            
        }else if (menu == 2){
            //Cadastro de animal
            printf("Para cadastrar o animal, digite o nome do dono:\n");
            ler(animais[cont_pets].dono.nome, 52);
            for(k=0;k<100;k++){
                if(strcasecmp(animais[cont_pets].dono.nome, clientes[k].nome)==0){
                    strcpy(animais[cont_pets].dono.nome, clientes[k].nome);
                    strcpy(animais[cont_pets].dono.tnum, clientes[k].tnum);
                    l++;
                }
            }
            
            if(l==0){
                    printf("Esse cliente não está cadastrado. Cães não se cadastram sozinhos.\n");
                    
                }else{
                
                printf("Digite o nome do animal:\n");
                ler(animais[cont_pets].animal, 52);
                
                printf("Digite o dia do nascimento do animal separando por espaços:\nDia Mes Ano\n");
                scanf("%d %d %d", &animais[cont_pets].nascimento.dia, &animais[cont_pets].nascimento.mes, &animais[cont_pets].nascimento.ano);
                getchar();
                
                printf("Digite a especie do animal de acordo com a tabela:\n(1)Cachorro\n(2)Gato\n(3)Passaro\n(4)Outro\n");
                scanf("%d", &animais[cont_pets].especie);
                getchar();
                    
                printf("É agressivo? (responda com 'S' para 'sim' e 'N' para 'não'\n");
                scanf("%c", &animais[cont_pets].agressive);
                if(animais[cont_pets].agressive == 'S'||animais[cont_pets].agressive == 's'){
                    agressivos++;
                }
                cont_pets++;
                l=0;
                printf("Número de Agressivos: %d\n", agressivos);
                
            }
        } 
           //Codigo para a parte administrativa    
         else if(menu == 3){
            
                printf("Funções de administrador:\n");
                printf("1- Lista de cadastrados\n2- Animais cadastrados\n3- Serviços pagos\n4- Pagamentos pendentes\n5- Buscar Clientes\n6- Buscar Animais\n");
                
                scanf("%d", &menu3);
                getchar();
                
                    if(menu3 == 5){
                            printf("Digite o nome do cliente:\n");
                            buscar_c (clientes, animais, cont_clientes, cont_pets);
                            
                            
                    } 
                    else if (menu3 == 2){
                        listar (animais, cont_pets);
                    }
                
            
         } else if(menu == 5){
             if(agressivos > 1){
                printf("Existem %d animais agressivos no RL PetShop, mas trabalhamos para chegar em 0.\n", agressivos);
             } else if(agressivos == 1){
                 printf("Há apenas um pet problemático, é o badboy da turma.");
             } else{
                 printf("Não existem animais agressivos no RL PetShop. É o paraíso.\n");
             }
         } else if (menu == 6){
             scanf("%d %d", &buscar_dia, &buscar_mes);
             getchar();
             aniversario (animais, cont_pets, buscar_dia, buscar_mes);
             
             
         } else if (menu == 7){
             
             listar_especies (animais, cont_pets);
         }
        
        
    }while(menu != 8);    


    return 0;
    
}

    

 
