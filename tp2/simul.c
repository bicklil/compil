#include "afnd.h"

int main(int argc, char * argv[])
{
  afnd  A;
  initafnd(&A);
  /*addinit(&A, 0);
  addfinal(&A, 2);
  addtrans(&A, 0, 1,'-');
  addtrans(&A, 0, 2,'a');
  addtrans(&A, 1, 0, 'b');
  addtrans(&A, 1, 2, '-');
  addtrans(&A, 1, 1, 'b');
  addtrans(&A, 2, 1, '-');
  addtrans(&A, 2, 0, 'a');
  addtrans(&A, 2, 2, 'a');
  printafnd(&A);*/

  finitafn(&A, "./test.txt");
  printafnd(&A);
  afd B;
  B = determinisation(&A);
  /*ullong e = epsilon(0, &A);
  printf("%lld\n", e);*/
  /*printf("etat12 %d\n", utile(12, &A));
  printf("etat1 %d\n", utile(1, &A));
  printf("etat3 %d\n", utile(3, &A));*/
  return 0;
}
