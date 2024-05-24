#include <stdio.h>
#include <locale.h>

char produto1[20], produto2[20], produto3[20];
int quantidade1, quantidade2, quantidade3;

void write(){

    FILE *BD;
    BD =  fopen("bd_desafio", "w");
    if (BD == NULL) {
      printf("Erro ao abrir o arquivo.");
    }

    fwrite(&produto1, sizeof(produto1), 1, BD);
    fwrite(&produto2, sizeof(produto2), 1, BD);
    fwrite(&produto3, sizeof(produto3), 1, BD);
    fwrite(&quantidade1, sizeof(quantidade1), 1, BD);
    fwrite(&quantidade2, sizeof(quantidade2), 1, BD);
    fwrite(&quantidade3, sizeof(quantidade3), 1, BD);

    fclose(BD);

}

void read(){

    FILE *BD;
    BD =  fopen("bd_desafio", "r");
    if (BD == NULL) {
      printf("Erro ao abrir o arquivo.");
    }

    fread(&produto1, sizeof(produto1), 1, BD);
    fread(&produto2, sizeof(produto2), 1, BD);
    fread(&produto3, sizeof(produto3), 1, BD);
    fread(&quantidade1, sizeof(quantidade1), 1, BD);
    fread(&quantidade2, sizeof(quantidade2), 1, BD);
    fread(&quantidade3, sizeof(quantidade3), 1, BD);

    //printf("%s - %d\n%s - %d\n %s - %d", produto1, quantidade1, produto2, quantidade2, produto3, quantidade3);

    fclose(BD);

}

void entradaArq(){

    int retorno, i;
    char tentativa1[20], tentativa2[20];

    printf("Digite o nome do 1° produto: ");
    gets(produto1);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade1);
    getchar();

    do{
        printf("Digite o nome do 2° produto: ");
        gets(tentativa1);
        retorno = 0;
        i = 0;
        while (tentativa1[i] != '\0' && produto1[i] != '\0') {
            if (tentativa1[i] != produto1[i]) {
                retorno = 1;
            }
            i++;
        }

        if(retorno == 0){
            printf("Produto já existente\n");
        }
    }
    while(retorno == 0);
    for(i=0; tentativa1[i] != '\0'; i++){
        produto2[i] = tentativa1[i];
    }
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade2);
    getchar();

    do{
        printf("Digite o nome do 3° produto: ");
        gets(tentativa2);
        retorno = 0;
        i = 0;
        while (tentativa2[i] != '\0' || produto1[i] != '\0') {
            if (tentativa2[i] != produto1[i]) {
                retorno = 1;
            }
            i++;
        }
        if(retorno == 1){
            retorno = 0;
            i = 0;
            while (tentativa2[i] != '\0' || produto2[i] != '\0') {
                if (tentativa2[i] != produto2[i]) {
                    retorno = 1;
                }
                i++;
            }
            if(retorno == 0){
                printf("Produto já existente\n");
            }
        }
    }
    while(retorno == 0);
    for(i=0; tentativa2[i] != '\0'; i++){
        produto3[i] = tentativa2[i];
    }
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade3);
    getchar();

    //printf("%s - %d\n%s - %d\n%s - %d", produto1, quantidade1, produto2, quantidade2, produto3, quantidade3);

    write();
}

void pesquisaProd(){

    read();

    int result1 = 1, result2 = 1, result3 = 1, i = 0;
    char pesquisa[20];

    printf("Digite o nome do produto desejado: ");
    gets(pesquisa);
    //getchar();
    while (pesquisa[i] != '\0' || produto1[i] != '\0') {
        if (pesquisa[i] != produto1[i]) {
            result1 = 0;
        }
        i++;
    }
    if(result1 == 0){
        i = 0;
        while (pesquisa[i] != '\0' || produto2[i] != '\0') {
            if (pesquisa[i] != produto2[i]) {
                result2 = 0;
            }
            i++;
        }
        if(result2 == 0){
            i = 0;
            while (pesquisa[i] != '\0' || produto3[i] != '\0') {
                if (pesquisa[i] != produto3[i]) {
                    result3 = 0;
                }
                i++;
            }
            if(result3 == 0){
                printf("Não há resultados para '%s'.\n\n", pesquisa);
            }
            else if(result3 == 1){
                printf("Produto: %s, quantidade: %d.\n\n", produto3, quantidade3);
            }
        }
        else{
            printf("Produto: %s, quantidade: %d.\n\n", produto2, quantidade2);
        }
    }
    else{
        printf("Produto: %s, quantidade: %d.\n\n", produto1, quantidade1);
    }
}

void listaDados(){

    read();

    if(produto1[0] != '*'){
        printf("1 - %s: %d\n", produto1, quantidade1);
    }
    if(produto2[0] != '*'){
        printf("2 - %s: %d\n", produto2, quantidade2);
    }
    if(produto3[0] != '*'){
        printf("3 - %s: %d\n\n", produto3, quantidade3);
    }

}

void pesquisaLetra(){

    read();

    char letra;

    printf("Digite a letra: ");
    scanf("%c", &letra);
    getchar();

    if(letra == produto1[0]){
        printf("1 - %s: %d\n\n", produto1, quantidade1);
    }
    if(letra == produto2[0]){
        printf("2 - %s: %d\n\n", produto2, quantidade2);
    }
    if(letra == produto3[0]){
        printf("3 - %s: %d\n\n", produto3, quantidade3);
    }
    if(letra != produto1[0] && letra != produto2[0] && letra != produto3[0]){
        printf("Produto não encontrado\n\n");
    }

}

void alteraDados(){

    read();

    int result1 = 1, result2 = 1, result3 = 1, retorno, i = 0;
    char pesquisa[20], novoprod[20];

    printf("Digite o nome do produto desejado: ");
    gets(pesquisa);
    //getchar();
    while (pesquisa[i] != '\0' || produto1[i] != '\0') {
        if (pesquisa[i] != produto1[i]) {
            result1 = 0;
        }
        i++;
    }
    if(result1 == 0){
        i = 0;
        while (pesquisa[i] != '\0' || produto2[i] != '\0') {
            if (pesquisa[i] != produto2[i]) {
                result2 = 0;
            }
            i++;
        }
        if(result2 == 0){
            i = 0;
            while (pesquisa[i] != '\0' || produto3[i] != '\0') {
                if (pesquisa[i] != produto3[i]) {
                    result3 = 0;
                }
                i++;
            }
            if(result3 == 0){
                printf("Não há resultados para '%s'.\n", pesquisa);
            }
            if(result3 == 1){
                do{
                    retorno = 0;
                    printf("Digite o novo nome do produto: ");
                    gets(novoprod);
                    i = 0;
                    while (novoprod[i] != '\0' || produto1[i] != '\0') {
                        if (novoprod[i] != produto1[i]) {
                            retorno = 1;
                        }
                        i++;
                    }
                    if(retorno == 1){
                        retorno = 0;
                        i = 0;
                        while (novoprod[i] != '\0' || produto2[i] != '\0') {
                            if (novoprod[i] != produto2[i]) {
                                retorno = 1;
                            }
                            i++;
                        }
                        if(retorno == 0){
                            printf("Produto já existente\n");
                        }
                    }
                }while(retorno == 0);
                for(i=0; produto3[i] != '\0' || novoprod[i] != '\0'; i++){
                        produto3[i] = novoprod[i];
                }
                printf("Digite a nova quantidade: ");
                scanf("%d", &quantidade3);
                getchar();
                write();
                printf("Produto alterado com sucesso\n\n");
            }
        }
        else{
            do{
                retorno = 0;
                printf("Digite o novo nome do produto: ");
                gets(novoprod);
                i = 0;
                while (novoprod[i] != '\0' || produto1[i] != '\0') {
                    if (novoprod[i] != produto1[i]) {
                        retorno = 1;
                    }
                    i++;
                }
                if(retorno == 1){
                    retorno = 0;
                    i = 0;
                    while (novoprod[i] != '\0' || produto3[i] != '\0') {
                        if (novoprod[i] != produto3[i]) {
                            retorno = 1;
                        }
                        i++;
                    }
                    if(retorno == 0){
                        printf("Produto já existente\n");
                    }
                }
            }while(retorno == 0);
            for(i=0; produto2[i] != '\0' || novoprod[i] != '\0'; i++){
                    produto2[i] = novoprod[i];
            }
            printf("Digite a nova quantidade: ");
            scanf("%d", &quantidade2);
            getchar();
            write();
            printf("Produto alterado com sucesso\n\n");
        }
    }
    else{
        do{
            retorno = 0;
            printf("Digite o novo nome do produto: ");
            gets(novoprod);
            i = 0;
            while (novoprod[i] != '\0' || produto3[i] != '\0') {
                if (novoprod[i] != produto3[i]) {
                    retorno = 1;
                }
                i++;
            }
            if(retorno == 1){
                retorno = 0;
                i = 0;
                while (novoprod[i] != '\0' || produto2[i] != '\0') {
                    if (novoprod[i] != produto2[i]) {
                        retorno = 1;
                    }
                    i++;
                }
                if(retorno == 0){
                    printf("Produto já existente\n");
                }
            }
        }while(retorno == 0);
        for(i=0; produto1[i] != '\0' || novoprod[i] != '\0'; i++){
                produto1[i] = novoprod[i];
        }
        printf("Digite a nova quantidade: ");
        scanf("%d", &quantidade1);
        getchar();
        write();
        printf("Produto alterado com sucesso\n\n");
    }
}

void excluiDados(){

    read();

    int result1 = 1, result2 = 1, result3 = 1, i = 0;
    char pesquisa[20];

    printf("Digite o nome do produto desejado: ");
    gets(pesquisa);
    //getchar();
    while (pesquisa[i] != '\0' || produto1[i] != '\0') {
        if (pesquisa[i] != produto1[i]) {
            result1 = 0;
        }
        i++;
    }
    if(result1 == 0){
        i = 0;
        while (pesquisa[i] != '\0' || produto2[i] != '\0') {
            if (pesquisa[i] != produto2[i]) {
                result2 = 0;
            }
            i++;
        }
        if(result2 == 0){
            i = 0;
            while (pesquisa[i] != '\0' || produto3[i] != '\0') {
                if (pesquisa[i] != produto3[i]) {
                    result3 = 0;
                }
                i++;
            }
            if(result3 == 0){
                printf("Não há resultados para '%s'.\n\n", pesquisa);
            }
            else if(result3 == 1){
                produto3[0] = '*';
                quantidade3 = 0;
                write();
                printf("Produto excluído\n\n");
            }
        }
        else{
            produto2[0] = '*';
            quantidade2 = 0;
            write();
            printf("Produto excluído\n\n");
        }
    }
    else{
        produto1[0] = '*';
        quantidade1 = 0;
        write();
        printf("Produto excluído\n\n");
    }

}

int main (){

    setlocale(LC_ALL, "");

    int menu;


    printf("1 - Entrada de arquivos\n");
    printf("2 – Listar todos os dados na tela\n");
    printf("3 - Pesquisar um produto pelo nome completo\n");
    printf("4 – Pesquisar os produtos pela 1° letra\n");
    printf("5 – Alterar dados\n");
    printf("6 – Exclui dados\n");
    printf("7 - Sair\n");

    do{
        printf("Digite sua opção: ");
        scanf("%d", &menu);
        getchar();
        switch(menu){
            case 1:
                entradaArq();
                break;
            case 2:
                listaDados();
                break;
            case 3:
                pesquisaProd();
                break;
            case 4:
                pesquisaLetra();
                break;
            case 5:
                alteraDados();
                break;
            case 6:
                excluiDados();
                break;
            case 7:
                break;
            default:
                printf("Número inválido\n");
                break;
        }
    }while(menu != 7);

    return 0;
}
