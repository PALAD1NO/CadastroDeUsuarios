#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em emória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[100];
	char cargo[50];
	//Final criação de variaveis/string
	
	printf("Você escolheu o REGISTRO DE NOMES!\n\n");
	printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
		scanf("%s", cpf);//%s se refere ao armazenamento da string
	
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
		FILE *file; // Cria o arquivo
		
		file = fopen(arquivo, "w"); // Cria o arquivo e o "W" significa escrever
		fprintf(file,cpf); // Salvo o valor da variavel
		fclose(file); // Fecho o arquivo
	
		file = fopen(arquivo,"a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,",");// insere "," no arquivo
		fclose(file);// Fecho o arquivo
	
	printf("Digite o NOME a ser cadastrado: ");//Coletando informação do usuário
		scanf("%s",nome);//%s se refere ao armazenamento da string
	
		file = fopen(arquivo, "a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,nome);// Salvo o valor da variavel
		fclose(file);// Fecho o arquivo
		
		file = fopen(arquivo,"a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,",");// insere "," no arquivo
		fclose(file);// Fecho o arquivo
		
	printf("Digite o SOBRENOME a ser cadastrado: ");//Coletando informação do usuário
		scanf("%s",sobrenome);//%s se refere ao armazenamento da string
	
		file = fopen(arquivo, "a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,sobrenome);// Salvo o valor da variavel
		fclose(file);// Fecho o arquivo
		
		file = fopen(arquivo,"a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,",");// insere "," no arquivo
		fclose(file);// Fecho o arquivo
	
	printf("Digite o CARGO a ser cadastrado: ");//Coletando informação do usuário
		scanf("%s",cargo);//%s se refere ao armazenamento da string
	
		file = fopen(arquivo, "a");// abre o arquivo em modo anexar, "a" significa anexar
		fprintf(file,cargo);// Salvo o valor da variavel
		fclose(file);// Fecho o arquivo	
	
	system("pause");//pausa a execução do programa, aguardando que o usuário pressione uma tecla.
}

int consulta()//Função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	char *token;
	//Fim criação de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando informação do usuário
	scanf("%s",cpf);//%s se refere ao armazenamento da string
	
	FILE *file;// Cria o arquivo
	file = fopen(cpf,"r");// Abre o arquivo em modo leitura, "r" significa "read" ler
		
	if(file==NULL)//Verifica se a variavel file existe
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n\n");//menssagem para o usuario
	}
		
	while(fgets(conteudo, 200, file) != NULL)//Existindo a variavel, informa seus valores
	{
		printf("\nEssas são as informações do usuário: \n\n");//menssagem para o usuario
		
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
	system("pause");//pausa a execução do programa, aguardando que o usuário pressione uma tecla.	
}

int deletar()//Função responsavel por deletar os usuários no sistema
{
	//Inicio criação de variaveis/string
	char cpf[40];
	//Fim criação de variaveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coletando informação do usuário
	scanf("%s", cpf);//%s se refere ao armazenamento da string
	
	remove(cpf);//Deleta a o usuario
	
	FILE *file;// Cria o arquivo
	file = fopen(cpf,"r");// Abre o arquivo em modo leitura, "r" significa "read" ler
		
	if(file == NULL)//Verifica se a variavel file existe
	{
		printf("\nO usuário não se encontra no sistema! \n\n");//menssagem para o usuario
		system("pause");//pausa a execução do programa, aguardando que o usuário pressione uma tecla.
	}
	
	else//executada quando a condição anterior "if" for falsa
	{
		printf("\nUsuário deletado do sistema! \n\n");//menssagem para o usuario
		system("pause");//pausa a execução do programa, aguardando que o usuário pressione uma tecla.
	}
	}

int main()//Função responsaveL pelo MENU
{
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");// Responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		//inicio do menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		//final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");// Responsavel por limpar a tela
		
		//inicio da seleção do MENU
		switch(opcao) 
		{
			case 1:
			registro();//Chamada de funções
			break;
			
			case 2:
			consulta();//Chamada de funções
			break;
			
			case 3:
			deletar();//Chamada de funções
			break;
			
			default:
			printf("Esta opção não está disponível\n\n");
			system("pause");//pausa a execução do programa, aguardando que o usuário pressione uma tecla.
			break;
		}//fim da seleção do MENU
	
	}
}
