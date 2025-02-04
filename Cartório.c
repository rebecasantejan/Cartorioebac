#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espaco em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel  por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// in�cio da  cria��o de vari�veis 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das vari�veis 
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo e o "w" significa escrever
	fprintf(file, cpf); // Salvo o valor da vari�vel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char  cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" significa ler 
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deleta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}

}

int main()
{ 
	int opcao=0; // Difinindo variaveis 
	int laco=1;

	for(laco=1; laco=1;)
	{
		system ("cls"); //respons�vel por limpar a tela 

		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
		printf("### Cat�rio da EBAC ###\n\n"); // in�cio do menu 
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nome \n"); 
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");	
		printf("Op��o: "); // fim do menu 
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system ("cls");
		
		switch(opcao) // in�cio da sele��o do menu
		{
			case 1: 
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deleta();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		} // fim da sele��o
	
	}
}





