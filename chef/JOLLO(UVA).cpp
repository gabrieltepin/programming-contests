#include <iostream>
#define MIN(x, y) ((x <= y) ? x : y)
#define MAX(x, y) ((x > y) ? x : y)
#define MIN3(x, y, z) ((x <= y && x <= z) ? x :(y <= x && y <= z)?y:z)
#define MAX3(x, y, z) -(MIN3(-x, -y, -z))
#define MED3(x, y, z) (MAX(MIN(x, y),MIN(MAX(x, y), z)))
 
int main(void)
{
  int a,b,c,x,y;
  int r1, r2, p1, p2, p3;
  while(scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), a){
    r1 = MIN(x, y);
    r2 = MAX(x, y);
    p1 = MIN3(a, b, c);
    p2 = MED3(a, b, c);
    p3 = MAX3(a, b, c);
 
    if(r2 < p1)  /* 1 rrppp */
      printf("-1");
    else if(r1 < p1 && r2 > p1 && r2 < p2) /* 2 rprpp */
      printf("-1");
    else if(r1 < p1 &&r2 > p2 && r2 < p3) /* 3 rpprp */
      printf("-1");
    else if(r1 < p1 && r2 > p3){ /* 4 rpppr */
      if(p3 + 1 != r2)printf("%d", p3 + 1);
      else if(r2 + 1 != 53)printf("%d", r2 + 1);
      else printf("-1");
    }
    else if(r1 > p1 && r2 < p2) /* 5 prrpp */
      printf("-1");
    else if(r1 > p1 && r1 < p2 && r2 > p2 && r2 < p3)
      printf("-1"); /* 6 prprp */
    else if(r1 > p1 && r1 < p2 && r2 > p3){ /* 7 prppr */
      if(p3 + 1 != r2)printf("%d", p3 + 1);
      else if (r2 + 1 != 53)printf("%d", r2 + 1);
      else printf("-1");
    }
    else if(r1 > p2 && r2 < p3){ /* 8 pprrp */
      if(p2 + 1 != r1)printf("%d", p2 + 1);
      else if(r1 + 1 != r2) printf("%d", r1 + 1);
      else if(r2 + 1 != p3) printf("%d", r2 + 1);
      else if(p3 + 1 != 53) printf("%d", p3 + 1);
      else printf("-1");
    }
    else if(r1 > p2 && r1 < p3 && r2 > p3){ /* 9 pprpr */
      if(p2 + 1 != r1)printf("%d", p2 + 1);
      else if(r1 + 1 != p3)printf("%d", r1 + 1);
      else if(p3 + 1 != r2)printf("%d", p3 + 1);
      else if(r2 + 1 != 53)printf("%d", r2 + 1);
      else printf("-1");
    }
    else if(r1 > p3){ /* 10 ppprr */
      if(p1 != 1)printf("1");
      else if(p2 != 2)printf("2");
      else if(p3 != 3)printf("3");
      else if(r1 != 4)printf("4");
      else if(r2 != 5)printf("5");
      else printf("6");
    }
    printf("\n");
  }
  return 0;
}
