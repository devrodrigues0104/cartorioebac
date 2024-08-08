#include <stdio.h> //comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�o em mem�ria
#include <locale.h> //texto por regi�o
#include <string.h> //manipula��o de strings

int registrar()
{	//definindo vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Voc� escolher registrar nomes\n");
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	strcpy(arquivo, cpf);
	
	//criando arquivo e inserindo cpf no arquivo
	FILE* file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	FILE* file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Arquivo n�o encontrado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s\n", conteudo);
	}
	
	fclose(file);
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	FILE* file;
	file = fopen(cpf, "r");	
	
	if(file == NULL)
	{
		printf("O cpf %s n�o se encontra no sistema\n", cpf);
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
	}

}

int main()
{
	// declarando vari�veis
	int opcao = 0;
	int x = 1;
	
	//definindo idioma
	setlocale(LC_ALL, "Portuguese");
	
	//estrutura de repeti��o
	for (x = 1; x = 1;)
	{
		
		system("cls");
		//tela inicial
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: ");
		
		//armazenando op��o em opcao
		scanf("%d", &opcao);
		
		//limpamdo a tela
		system("cls");
		
		//escolhendo um caso
		switch(opcao)
		{
			case 1:
				registrar();
			break;
	
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel\n");
				system("pause");
			break;
		}
	}
}
