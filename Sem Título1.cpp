#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	//strcpy(arquivo, cpf); 
	
	FILE *file;
	file = fopen(cpf, "w"); //criou o arquivo
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf);
	fclose(file);
	
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(cpf, "a"); 
	fprintf(file,"\nNome: ");
	fprintf(file,nome);
	fclose(file);
	
	
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(cpf, "a"); 
	fprintf(file,"\nSobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(cpf, "a"); 
	fprintf(file,"\nCargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //ler o arquivo
	
	if(file==NULL)
	{
		printf("Arquivo não localizado \n");
	}
	if(fgets(conteudo,200,file)!= NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{	
		printf("%s", conteudo);	
	}
	printf("\n");
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	remove(cpf);
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nArquivo não encontrado\n");
		system("pause");
	}

}

int main()
{
	int laco=1;
	for (laco=1;laco=1;)
	{
	int opcao=0;
	
	setlocale(LC_ALL, "Portuguese");
	

	
		system("cls");
		
		printf("--- CARTÓRIO DA EBAC --- \n\n");
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		
		printf("Opção: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
		 	
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema\n\n");
			return 0;
			break;
	
			default:
		
			printf("\t- Opção indisponível\n");
			system("pause");
			break;
		}
	}
}
