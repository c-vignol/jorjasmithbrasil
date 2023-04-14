#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

int cadastro () //função responsável pelo cadastro de usuários no sistema
{	
	//início da criação das variáveis/strings
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Ocupacao[40];
	
	printf("Informe os dados abaixo: \n\n"); //coleta de informação do usuário
	
	printf("CPF: ");
	scanf("%s", CPF); //%s referente a strings
	
	strcpy(arquivo, CPF); //responsável por copiar os valores das strings
	
	FILE *file; //criação do arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file,CPF); //salvamento do valor da variável
	fclose(file); //fechamento do arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Nome: ");
	scanf("%s", Nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, Nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Sobrenome: ");
	scanf ("%s", Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, Sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Ocupacao: ");
	scanf ("%s", Ocupacao);
	
	file = fopen(arquivo, "a");
	fprintf(file, Ocupacao);
	fclose(file);
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //definição de linguagem
	
	char CPF[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf ("\nNão foi possível encontrar o CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEstas são as informações do usuário: \n");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
	
}

int cancelamento ()
{
	char CPF[40];
	
	printf("Digite o CPF cadastrado: \n");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF, "r");	
	
	if (file == NULL)
	{
		printf("O CPF não foi encontrado no sistema. \n");
		system("pause");
	}
	else 
	{
		remove(CPF);
		printf("O cadastro foi cancelado com sucesso! \n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0; //definição de variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //limpeza de tela
				
		setlocale(LC_ALL, "Portuguese"); //definição de linguagem
	
		printf("###Fanbase Jorja Smith Brasil###\n\n"); //início do menu
		printf("Escolha a opção abaixo:\n\n");
		printf("\t1 - Cadastro na Fanbase\n");
		printf("\t2 - Consulta de Cadastro na Fanbase\n");
		printf("\t3 - Cancelamento de Cadastro na Fanbase\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d",&opcao);//armazenamento da escolha do usuário
	
		system("cls");
		
		switch(opcao) //início da seleção
		{
			case 1:
			cadastro(); //chamada de função
			break;	
			
			case 2:
			consulta();
			break;
			
			case 3:	
			cancelamento();
			break;
			
			case 4:
			printf("Obrigada por entrar em nosso sistema :)\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível\n");
			system("pause");
			break;//fim da seleção
		}
	}

}
