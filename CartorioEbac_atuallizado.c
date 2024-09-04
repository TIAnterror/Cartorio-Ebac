#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() // Função responsável para cadastrar os usuários no sistema 
{
	        // Início da criação de variáveis/string  
	        char arquivo[40];
            char cpf[40];
            char nome[40];
            char sobrenome[40];
            char cargo[40];
             // Final da criação de variáveis/string
            
            printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
            scanf("%s", cpf); // %s refere-se as string
            
            strcpy(arquivo, cpf); // Responsável para copiar os valores das string
            
            FILE *file; // cria o arquivo
            file = fopen(arquivo, "w"); // cria o arquivo "w" significa escrever
            fprintf(file,cpf); // salva o valor da variável
            fclose(file); // fecha o arquivo
            
            file = fopen(arquivo, "a");
            fprintf(file,",");
            fclose(file);
            
            printf("Digite o nome a ser cadastrado: ");
            scanf("%s",nome); // %s refere-se as string
            
            file = fopen(arquivo, "a");
            fprintf(file,nome);
            fclose(file);
            
            file = fopen(arquivo, "a");
            fprintf(file,",");
            fclose(file);
            
            printf("Digite o sobrenome a ser cadastrado: ");
            scanf("%s",sobrenome); // %s refere-se as string
            
            file = fopen(arquivo, "a"); // cria o arquivo 
            fprintf(file,sobrenome);
            fclose(file);
            
            file = fopen(arquivo, "a"); // cria o arquivo 
            fprintf(file,",");
            fclose(file);
            
            printf("Digite o cargo a ser cadastrado: ");
            scanf("%s",cargo); // %s refere-se as string
            
            file = fopen(arquivo, "a"); // cria o arquivo 
            fprintf(file,cargo);
            fclose(file);
            
            system("pause");
            
}

int consulta()
{
	        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	        
	        // Início da criação de variáveis/string
	        char cpf[40];
	        char conteudo[200];
	        // Final da criação de variáveis/string
	        
	        printf("Digite o CPF a ser consultado: "); // coletando informação do usuário
	        scanf("%s", cpf); // %s refere-se as string
	        
	        FILE *file; // cria o arquivo
	        file = fopen(cpf,"r"); // cria o arquivo "r" significa ler
	        
	        if(file == NULL)
	        {
	        	printf("Não foi possível abrir o arquivo, não localizado!. \n");
			}
			
			while(fgets(conteudo, 200, file) != NULL)
			{
				printf("\nEssas são as informções do usuário: "); // coletando informação do usuário
				printf("%s", conteudo);
				printf("\n\n");
			}
			
			system("pause");
       
}      
	        

int deletar()
{
	    // Início da criação de variáveis/string 
	    char cpf[40];
	    // Final da criação de variáveis/string
		    
	    printf("Digite o CPF do usuário a ser deletado: "); // coletando informação do usuário
	    scanf("%s", cpf); // %s refere-se as string
	        
	    remove(cpf);
	        
	    FILE *file;
	    file = fopen(cpf,"r"); // cria o arquivo "r" significa ler
	        
	    if(file == NULL)
	    {
	        printf("O usuário não se encontra no sistema!.\n"); // coletando informação do usuário
	        system("pause");
		}
		
}

int main()
{
	int opcao=0; //Definindo as variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); // Responsável por limpar a tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		    
	    printf("### Cartório EBAC ###\n\n"); //Início do Menu
    	printf("Escolha a opção desejada do menu\n\n");
	    printf("\t1 - Registrar nomes\n\n");
	    printf("\t2 - Consultar nomes\n\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Opção: "); //Final do menu
	    
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); // Responsável por limpar a tela
	    
	    
	    switch(opcao) // Início da seleção do menu
	    {
		    case 1:
	        registro(); // Chamada de funções
   		    break;
   		 
   		    case 2:
   		    consulta(); // Chamada de funções
		    break;
		
		    case 3:
		    deletar(); // Chamada de funções
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		  		  	
		    default:
		    printf("Esta opção não está disponível!\n");
		    system("pause");
		    break; 
	    }
    	
   }
}

