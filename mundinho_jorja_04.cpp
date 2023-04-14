#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int cadastro () //fun��o respons�vel pelo cadastro de usu�rios no sistema
{	
	//in�cio da cria��o das vari�veis/strings
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Ocupacao[40];
	
	printf("Informe os dados abaixo: \n\n"); //coleta de informa��o do usu�rio
	
	printf("CPF: ");
	scanf("%s", CPF); //%s referente a strings
	
	strcpy(arquivo, CPF); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria��o do arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file,CPF); //salvamento do valor da vari�vel
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
	setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
	
	char CPF[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf ("\nN�o foi poss�vel encontrar o CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEstas s�o as informa��es do usu�rio: \n");
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
		printf("O CPF n�o foi encontrado no sistema. \n");
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
	int opcao=0; //defini��o de vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //limpeza de tela
				
		setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
	
		printf("###Fanbase Jorja Smith Brasil###\n\n"); //in�cio do menu
		printf("Escolha a op��o abaixo:\n\n");
		printf("\t1 - Cadastro na Fanbase\n");
		printf("\t2 - Consulta de Cadastro na Fanbase\n");
		printf("\t3 - Cancelamento de Cadastro na Fanbase\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d",&opcao);//armazenamento da escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //in�cio da sele��o
		{
			case 1:
			cadastro(); //chamada de fun��o
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
			printf("Esta op��o n�o est� dispon�vel\n");
			system("pause");
			break;//fim da sele��o
		}
	}

}
