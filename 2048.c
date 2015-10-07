#include<stdio.h>
int main(){
	int b[4][4],o,ranx,rany,a[4][4],i,j,k,l,n,m,flag=0,ele,trc;
	char c;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			a[i][j]=0;
	ranx=(rand())%4;
	rany=(rand())%4;
	a[ranx][rany]=2;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(a[i][j]!=0)
				printf("|	%d	",a[i][j]);
			else
				printf("|	 	");
		}
		printf("|\n");
	}
	while(flag!=1){
		system("/bin/stty raw");
		c=getchar();
		system("/bin/stty cooked");
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				b[i][j]=a[i][j];
		if(c=='w'){
			for(j=0;j<4;j++){
				int init=0;
				for(i=0;i<4;i++){
					if(a[i][j]==0)
						;
					else{
						a[init][j]=a[i][j];
						init++;
					}
				}
				for(i=init;i<4;i++)
					a[i][j]=0;
			}
			for(j=0;j<4;j++){
				ele=a[0][j];
				trc=0;
				for(i=1;i<4;i++){
					if(ele==a[i][j]){
						a[trc][j]=2*ele;
						for(l=trc+1;l<3;l++)
							a[l][j]=a[l+1][j];
						a[3][j]=0;
						trc++;
						ele=a[trc][j];
					}
					else{
						trc++;
						ele=a[trc][j];
					}
				}
			}

		}
		else if(c=='s'){
			for(j=0;j<4;j++){
					trc=3;
				for(i=3;i>=0;i--){
					if(a[i][j]==0);
					else{
						a[trc][j]=a[i][j];
						trc--;
					}
				}
				for(i=trc;i>=0;i--)
					a[i][j]=0;
			}
			ele=a[3][j];
			for(j=0;j<4;j++){
				ele=a[3][j];
				trc=3;
				for(i=2;i>=0;i--){
					if(ele==a[i][j]){
						a[trc][j]=2*ele;
						for(l=trc-1;l>0;l--)
							a[l][j]=a[l-1][j];
						a[0][j]=0;
						trc--;
						ele=a[trc][j];
					}
					else{
						trc--;
						ele=a[trc][j];
					}
				}
			}
		}
		else if(c=='a'){
			for(i=0;i<4;i++){
				trc=0;
				for(j=0;j<4;j++){
					if(a[i][j]==0)
						;
					else{
						a[i][trc]=a[i][j];
						trc++;
					}
				}
				for(l=trc;l<4;l++)
					a[i][l]=0;
			}
			for(i=0;i<4;i++){
				ele=a[i][0];
				trc=0;
				for(j=1;j<4;j++){
					if(a[i][j]==ele){
						a[i][trc]=2*ele;
						for(l=trc+1;l<3;l++)
							a[i][l]=a[i][l+1];
						a[i][3]=0;
						trc++;
						ele=a[i][trc];
					}
					else{
						trc++;
						ele=a[i][trc];
					}
				}
			}
		}
		else if(c=='d'){
			for(i=0;i<4;i++){
				trc=3;
				for(j=3;j>=0;j--){
					if(a[i][j]==0)
						;
					else{
						a[i][trc]=a[i][j];
						trc--;
					}
				}
				for(l=trc;l>=0;l--)
					a[i][l]=0;
			}
			for(i=0;i<4;i++){
				trc=3;
				ele=a[i][3];
				for(j=2;j>=0;j--){
					if(a[i][j]==ele){
						a[i][trc]=2*ele;
						for(l=trc-1;l>0;l--)
							a[i][l]=a[i][l-1];
						a[i][0]=0;
						trc--;
						ele=a[i][trc];
					}
					else{
						trc--;
						ele=a[i][trc];
					}
				}
			}
		}
		int flag2=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(a[i][j]!=b[i][j])
					flag2=1;
		if(flag2==1){
			printf("\n");
			ranx=(rand())%4;
			rany=(rand())%4;
			int flag1=0;
			while(flag1==0){
				if(a[ranx][rany]!=0){
					ranx=(rand())%4;
					rany=(rand())%4;
				}
				else{
					a[ranx][rany]=2;
					flag1=1;
				}
			}
			for(i=0;i<4;i++){
		printf("|***************************************************************|\n");
				for(j=0;j<4;j++){
					if(a[i][j]!=0)
						printf("|	%d	",a[i][j]);
					else
						printf("|	 	");
					}
				printf("|\n");
			}
	printf("|***************************************************************|\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		else ;
		if(c=='Q')
			return 0;
	}
	return 0;
}
