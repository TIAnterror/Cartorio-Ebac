#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() // Fun��o respons�vel para cadastrar os usu�rios no sistema 
{
	        // In�cio da cria��o de vari�veis/string  
	        char arquivo[40];
            char cpf[40];
            char nome[40];
            char sobrenome[40];
            char cargo[40];
             // Final da cria��o de vari�veis/string
            
            printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
            scanf("%s", cpf); // %s refere-se as string
            
            strcpy(arquivo, cpf); // Respons�vel para copiar os valores das string
            
            FILE *file; // cria o arquivo
            file = fopen(arquivo, "w"); // cria o arquivo "w" significa escrever
            fprintf(file,cpf); // salva o valor da vari�vel
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
	        
	        // In�cio da cria��o de vari�veis/string
	        char cpf[40];
	        char conteudo[200];
	        // Final da cria��o de vari�veis/string
	        
	        printf("Digite o CPF a ser consultado: "); // coletando informa��o do usu�rio
	        scanf("%s", cpf); // %s refere-se as string
	        
	        FILE *file; // cria o arquivo
	        file = fopen(cpf,"r"); // cria o arquivo "r" significa ler
	        
	        if(file == NULL)
	        {
	        	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
			}
			
			while(fgets(conteudo, 200, file) != NULL)
			{
				printf("\nEssas s�o as inform��es do usu�rio: "); // coletando informa��o do usu�rio
				printf("%s", conteudo);
				printf("\n\n");
			}
			
			system("pause");
       
}      
	        

int deletar()
{
	    // In�cio da cria��o de vari�veis/string 
	    char cpf[40];
	    // Final da cria��o de vari�veis/string
		    
	    printf("Digite o CPF do usu�rio a ser deletado: "); // coletando informa��o do usu�rio
	    scanf("%s", cpf); // %s refere-se as string
	        
	    remove(cpf);
	        
	    FILE *file;
	    file = fopen(cpf,"r"); // cria o arquivo "r" significa ler
	        
	    if(file == NULL)
	    {
	        printf("O usu�rio n�o se encontra no sistema!.\n"); // coletando informa��o do usu�rio
	        system("pause");
		}
		
}

int main()
{
	int opcao=0; //Definindo as vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); // Respons�vel por limpar a tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		    
	    printf("### Cart�rio EBAC ###\n\n"); //In�cio do Menu
    	printf("Escolha a op��o desejada do menu\n\n");
	    printf("\t1 - Registrar nomes\n\n");
	    printf("\t2 - Consultar nomes\n\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o: "); //Final do menu
	    
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); // Respons�vel por limpar a tela
	    
	    
	    switch(opcao) // In�cio da sele��o do menu
	    {
		    case 1:
	        registro(); // Chamada de fun��es
   		    break;
   		 
   		    case 2:
   		    consulta(); // Chamada de fun��es
		    break;
		
		    case 3:
		    deletar(); // Chamada de fun��es
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		  		  	
		    default:
		    printf("Esta op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break; 
	    }
    	
   }
}

