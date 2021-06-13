#include <stdio.h>

void dec_bin( unsigned int n)
{int binar[8],i=0,j;
 while(i<8){

 	binar[i]=n%2;
 	n=n/2;
 	i++;
 }
 
 for(j=i-1;j>=0;j--){

 	printf("%d",binar[j]);
 }
}

int main()
{   unsigned int m1,m2,m3,m4,MSK_2,ip11,ip12,ip13,ip14,ip21,ip22,ip23,ip24;
	unsigned int masca,adr11,adr12,adr13,adr14,adb1,adb2,adb3,adb4;
	unsigned int adr21,adr22,adr23,adr24,MSK_1;
	unsigned int n1,n2,n3,n4,msk;
	int nrset,i,N,ok,poz,k;
	
	scanf("%d",&nrset);

	for(k=1;k<=nrset;k++){

		scanf("%u.%u.%u.%u",&m1,&m2,&m3,&m4); //citire MSK_1;
		MSK_1=MSK_1|m1; MSK_1=MSK_1<<8;
        MSK_1=MSK_1|m2; MSK_1=MSK_1<<8;
        MSK_1=MSK_1|m3; MSK_1=MSK_1<<8;
        MSK_1=MSK_1|m4;

		scanf("%u",&MSK_2); //citire MSK_2;

		scanf("%u.%u.%u.%u",&ip11,&ip12,&ip13,&ip14); //citire IP_1;

		scanf("%u.%u.%u.%u",&ip21,&ip22,&ip23,&ip24); //citire IP_2;

		

    printf("%d\n",k );
	printf("-%d ", 0); //task 0;
	printf("%u.%u.%u.%u/%u\n",ip11,ip12,ip13,ip14,MSK_2);


	printf("-%d ", 1); //task 1;
	masca= (0xFFFFFFFF << (32 - MSK_2)) & 0xFFFFFFFF;
	printf("%u.%u.%u.%u\n",(masca>>24)&0xFF,(masca>>16)&0xFF,
		   (masca>>8)&0xFF,masca&0xFF);


	printf("-%d ", 2); //task 2;
	printf("%o.%o.%o.%o ",m1,m2,m3,m4); 
	printf("%X.%X.%X.%X\n",m1,m2,m3,m4);

	printf("-%d ", 3); //task 3;
	adr11=(masca>>24)& ip11;
	adr12=(masca>>16)& ip12;
	adr13=(masca >> 8) & ip13;
	adr14=masca & ip14; 
	//adr11,adr12,adr13,adr14 reprezinta octetii adresei de retea,IP_1, MSK_2;
	printf("%u.%u.%u.%u\n",adr11,adr12,adr13,adr14);


	printf("-%d ", 4); //task 4;
	adb1= (ip11 | (((0xFFFFFFFF >> MSK_2)>>24)&0xFF));
	adb2= (ip12 | (((0xFFFFFFFF >> MSK_2)>>16)&0xFF));
	adb3= (ip13 | (((0xFFFFFFFF >> MSK_2)>>8)&0xFF));
	adb4= (ip14 | ((0xFFFFFFFF >> MSK_2)&0xFF)); 
	//adb1,adb2,adb3,adb4 reprezinta octetii adresei de retea;
	printf("%u.%u.%u.%u\n",adb1,adb2,adb3,adb4);


	printf("-%d ", 5); //task 5;
	adr21=(masca>>24)& ip21;
	adr22=((masca>>16)& 0xFF)& ip22;
	adr23=((masca >> 8) & 0xFF)& ip23;
	adr24=(masca & 0xFF)& ip24; 
	//adr21,adr22,adr23,adr24 reprezinta octetii adresei de retea ,IP_2,MSK_2;
    if( (adr11==adr21) && (adr12==adr22) && (adr13==adr23) && (adr14==adr24)){

    	printf("DA\n");

    }

    else{

    	 printf("NU\n");
    }





    printf("-%d ", 6); //task 6;
    
    ok=0;

  for(i=0;i<=31;i++){

    if((MSK_1 & (1<<i))!=0){

      ok=1;
      poz=i;
     
    }

    if(ok==1){

      break;
    }

  }


  for(i=poz;i<=31;i++){

    if((MSK_1 & (1<<i))==0){

      ok=10;
            
    }

    if(ok==10){

      break;
    }

  }

  

  if(ok==10)

    printf("NU\n");

  else 

    printf("DA\n");


   
   printf("-%d ", 7); //task 7;
   
   if(ok!=10){

   		printf("%u.%u.%u.%u\n",m1,m2,m3,m4);

   }

   else {

    poz=32;
    i=31;
    while(poz==32){

      if((MSK_1&(1<<i))==0){

        poz=i;
      }

      i--;
    }

    MSK_1=(0xFFFFFFFF>> (poz+1))<<(poz+1);
   	printf("%u.%u.%u.%u\n",MSK_1>>24,(MSK_1<<8)>>24,
               (MSK_1<<16)>>24,(MSK_1<<24)>>24);

}

   
	printf("-%d ", 8); //task 8;
	dec_bin(ip11);
	printf(".");
	dec_bin(ip12);
	printf(".");
	dec_bin(ip13);
	printf(".");
	dec_bin(ip14);
	printf("\n");



	printf("-%d ", 9); //task 9;

	scanf("%u",&N); //citire N;

		for(i=0;i<=N-1;i++){

			scanf("%u.%u.%u.%u/%u ",&n1,&n2,&n3,&n4,&msk);
			masca=(0xFFFFFFFF << (32-msk))&0xFFFFFFFF;

			if((((masca>>24)&ip21)==((masca>>24)&n1)) && 
			   (((masca>>16)&ip22)==((masca>>16)&n2)) &&
         	           (((masca>>8)&ip23)==((masca>>8)&n3)) && 
         	           (((masca>>0)& ip24)==((masca>>0)&n4))){

      
			printf("%d ",i);
			
          }

         }

		
		
printf("\n");

	

}

}

