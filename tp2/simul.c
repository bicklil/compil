#include "afnd.h"

int main(int argc, char * argv[])
{
  afnd  A;
  
  initafnd(&A);
 /* addinit(&A, 0);
  addfinal(&A, 2);
  addtrans(&A, 0, 1,'-');
  addtrans(&A, 0, 2,'a');
  addtrans(&A, 1, 0, 'b');
  addtrans(&A, 1, 2, '-');
  addtrans(&A, 1, 1, 'b');
  addtrans(&A, 2, 1, '-');
  addtrans(&A, 2, 0, 'a');
  addtrans(&A, 2, 2, 'a');*/
	finitafn(&A, "afd.txt");
  printafnd(&A);
	printf("%lld\n",epsilon(2,&A));
  return 0;
}
