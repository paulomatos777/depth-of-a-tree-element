#include <stdio.h>
#include <string.h>
//(5(4(11(7()())(2()()))())  (8(13()())(4()(1()()))))
//(5(4(1(7()())(2()()))())  (8(13()())(4()(1()()))))
//(12(7(3()())(10()(11()())))(23(17()())(31()())))

int main(void) {
  char entrada[50];
  char digits[] = "0123456789";
  int i, j, num_procurado, soma_abertura = 0, soma_fechamento = 0, pos_atual = 0;;
  scanf("%[^\n]", entrada);
  scanf("%d", &num_procurado);

  char *ptr = strpbrk(entrada, digits);
  do{
    // lendo numero encontrado
    sscanf(ptr,"%d", &i);
    pos_atual = (ptr - entrada)/sizeof(char);
    if ( i == num_procurado){
       for (j = 0; j < pos_atual; j++){
        if(entrada[j] == '('){
          soma_abertura++;
        }else if(entrada[j] == ')'){
          soma_fechamento++;
        }
      }
      printf("ESTA NA ARVORE\n%d", soma_abertura - soma_fechamento - 1);
      break;
    }
    if(i >10)
      ptr = ptr + 2*sizeof(char);
    else
      ptr = ptr + sizeof(char);
    ptr = strpbrk(ptr, digits);
  }while(ptr != '\0');

  if(ptr == '\0'){
    printf("NAO ESTA NA ARVORE\n-1");
  }
  return 0;
}
