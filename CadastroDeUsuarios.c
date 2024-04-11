#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em em�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[100];
	char cargo[50];
	//Final cria��o de variaveis/string
	
	printf("Voc� escolheu o REGISTRO DE NOMES!\n\n");
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
		scanf("%s", cpf);//%s se refere ao armazenamento da string
	
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
		FILE *file; // Cria o arquivo
		
		file = fopen(arquivo, "w"); // Cria o arquivo e o "W" significa escrever
		fprintf(file,cpf); // Salvo o valor da variavel
		fclose(file); // Fecho o arquivo
	
		file = fopen(arquivo,"a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,",");// insere "," no arquivo
		fclose(file);// Fecho o arquivo
	
	printf("Digite o NOME a ser cadastrado: ");//Coletando informa��o do usu�rio
		scanf("%s",nome);//%s se refere ao armazenamento da string
	
		file = fopen(arquivo, "a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,nome);// Salvo o valor da variavel
		fclose(file);// Fecho o arquivo
		
		file = fopen(arquivo,"a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,",");// insere "," no arquivo
		fclose(file);// Fecho o arquivo
		
	printf("Digite o SOBRENOME a ser cadastrado: ");//Coletando informa��o do usu�rio
		scanf("%s",sobrenome);//%s se refere ao armazenamento da string
	
		file = fopen(arquivo, "a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,sobrenome);// Salvo o valor da variavel
		fclose(file);// Fecho o arquivo
		
		file = fopen(arquivo,"a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,",");// insere "," no arquivo
		fclose(file);// Fecho o arquivo
	
	printf("Digite o CARGO a ser cadastrado: ");//Coletando informa��o do usu�rio
		scanf("%s",cargo);//%s se refere ao armazenamento da string
	
		file = fopen(arquivo, "a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,cargo);// Salvo o valor da variavel
		fclose(file);// Fecho o arquivo	
	
	system("pause");//pausa a execu��o do programa, aguardando que o usu�rio pressione uma tecla.
}

int consulta()//Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	char *token;
	//Fim cria��o de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando informa��o do usu�rio
	scanf("%s",cpf);//%s se refere ao armazenamento da string
	
	FILE *file;// Cria o arquivo
	file = fopen(cpf,"r");// Abre o arquivo em modo leitura, "r" significa "read" ler
		
	if(file==NULL)//Verifica se a variavel file existe
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n\n");//menssagem para o usuario
	}
		
	while(fgets(conteudo, 200, file) != NULL)//Existindo a variavel, informa seus valores
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");//menssagem para o usuario
		
		token = strtok(conteudo, ",");//divide a string com base no delimitador ","
		printf("CPF: %s\n", token);//informa o CPF
			
		token = strtok(NULL, ",");//divide a string com base no delimitador ","
		printf("NOME: %s\n", token);//informa o NOME
	
		token = strtok(NULL, ",");//divide a string com base no delimitador ","
		printf("SOBRENOME: %s\n", token);//informa o SOBRENOME
		
		token = strtok(NULL, ",");//divide a string com base no delimitador ","
		printf("CARGO: %s\n", token);//informa o CARGO
		
		printf("\n");//pula uma linha
	}
	system("pause");//pausa a execu��o do programa, aguardando que o usu�rio pressione uma tecla.	
}

int deletar()//Fun��o responsavel por deletar os usu�rios no sistema
{
	//Inicio cria��o de variaveis/string
	char cpf[40];
	//Fim cria��o de variaveis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//Coletando informa��o do usu�rio
	scanf("%s", cpf);//%s se refere ao armazenamento da string
	
	remove(cpf);//Deleta a o usuario
	
	FILE *file;// Cria o arquivo
	file = fopen(cpf,"r");// Abre o arquivo em modo leitura, "r" significa "read" ler
		
	if(file == NULL)//Verifica se a variavel file existe
	{
		printf("\nO usu�rio n�o se encontra no sistema! \n\n");//menssagem para o usuario
		system("pause");//pausa a execu��o do programa, aguardando que o usu�rio pressione uma tecla.
	}
	
	else//executada quando a condi��o anterior "if" for falsa
	{
		printf("\nUsu�rio deletado do sistema! \n\n");//menssagem para o usuario
		system("pause");//pausa a execu��o do programa, aguardando que o usu�rio pressione uma tecla.
	}
	}

int main()//Fun��o responsaveL pelo MENU
{
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");// Responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		//inicio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		//final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");// Responsavel por limpar a tela
		
		//inicio da sele��o do MENU
		switch(opcao) 
		{
			case 1:
			registro();//Chamada de fun��es
			break;
			
			case 2:
			consulta();//Chamada de fun��es
			break;
			
			case 3:
			deletar();//Chamada de fun��es
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel\n\n");
			system("pause");//pausa a execu��o do programa, aguardando que o usu�rio pressione uma tecla.
			break;
		}//fim da sele��o do MENU
	
	}
}
