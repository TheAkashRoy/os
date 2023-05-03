#include<stdio.h>


main() {
  int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
  int s[10], fno[10][20];

  printf("\nEnter the memory size -- ");
  scanf("%d", & ms);

  printf("\nEnter the page size -- ");
  scanf("%d", & ps);

  nop = ms / ps;
  printf("\nThe no. of pages available in memory are -- %d ", nop);

  printf("\nEnter number of processes -- ");
  scanf("%d", & np);
  rempages = nop;
  for (i = 1; i <= np; i++)

  {

    printf("\nEnter no. of pages required for p[%d]-- ", i);
    scanf("%d", & s[i]);

    if (s[i] > rempages) {

      printf("\nMemory is Full");
      break;
    }
    rempages = rempages - s[i];

    printf("\nEnter pagetable for p[%d] --- ", i);
    for (j = 0; j < s[i]; j++)
      scanf("%d", & fno[i][j]);
  }

  printf("\nEnter Logical Address to find Physical Address ");
  printf("\nEnter process no. and pagenumber and offset -- ");

  scanf("%d %d %d", & x, & y, & offset);

  if (x > np || y >= s[x] || offset >= ps)
    printf("\nInvalid Process or Page Number or offset");

  else {
    pa = fno[x][y] * ps + offset;
    printf("\nThe Physical Address is -- %d", pa);

  }
}

// #include<stdio.h>
// void main()
// {
// int memsize=15;
// int pagesize,nofpage;
// int p[100];
// int frameno,offset;
// int logadd,phyadd;
// int i;
// int choice=0;
// printf("\nYour memsize is %d ",memsize);
// printf("\nEnter page size:");
// scanf("%d",&pagesize);

// nofpage=memsize/pagesize;

// for(i=0;i<nofpage;i++)
// {
// printf("\nEnter the frame of page%d:",i+1);
// scanf("%d",&p[i]);
// }

// do
// {
// printf("\nEnter a logical address:");
// scanf("%d",&logadd);
// frameno=logadd/pagesize;
// offset=logadd%pagesize;
// phyadd=(p[frameno]*pagesize)+offset;
// printf("\nPhysical address is:%d",phyadd);
// printf("\nDo you want to continue(1/0)?:");
// scanf("%d",&choice);
// }while(choice==1);
// }

// OUTPUT:
// Your memsize is 15
// Enter page size:5

// Enter the frame of page1:2

// Enter the frame of page2:4

// Enter the frame of page3:7

// Enter a logical address:3

// Physical address is:13
// Do you want to continue(1/0)?:1

// Enter a logical address:1

// Physical address is:11