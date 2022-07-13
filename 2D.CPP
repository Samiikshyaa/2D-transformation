#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawtriangle(int[4][4]);
void translate(int[4][4]);
void scale(int[4][4]);
void scalefix(int[4][4]);
void main()
{
	int gd=DETECT,gm,i,a[4][4],ch;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	printf("SAMIKSHYA TIMALSINA\t\t\t\tHCE076BCT034");
	printf("\n\nEnter the coordinates of a triangle:");
	for(i=0; i<3; i++)
	{
		printf("\n(X%d , Y%d) = ",i,i);
		scanf("%d\t%d",&a[0][i],&a[1][i]);
	}
	drawtriangle(a);
	do{
	printf("\n****MENU****");
	printf("\n1 -> Translation");
	printf("\n2 -> Scaling");
	printf("\n3 -> Scaling about a fixed point");
	printf("\n4 -> Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		translate(a);
		break;
	case 2:
		scale(a);
		break;
	case 3:
		scalefix(a);
		break;
	default:
		printf("\nBYE");
	}
	}while (ch!=4);
	getch();
	closegraph();
}
void drawtriangle(int a[4][4])
{
	int i;
	for(i=0;i<3;i++)
	{
		if(i<2)
		{
		line(a[0][i],a[1][i],a[0][i+1],a[1][i+1]);
		}
		else
		{
		 line(a[0][i],a[1][i],a[0][i-2],a[1][i-2]);
		}
	}
}
void translate(int a[4][4])
{
	int i;
	float tx,ty;
	printf("Enter the translating distances: \t");
	scanf("%f%f",&tx,&ty);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		line((tx+a[0][i]),(a[1][i]+ty),(a[0][i+1]+tx),(a[1][i+1]+ty));
		}
		else
		{
		 line((tx+a[0][i]),(ty+a[1][i]),(tx+a[0][i-2]),(ty+a[1][i-2]));
		}
	 }
}
void scale(int a[4][4])
{
	int i;
	float sx,sy;
	printf("Enter the scaling distances: \t");
	scanf("%f%f",&sx,&sy);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		line((sx*a[0][i]),(a[1][i]*sy),(a[0][i+1]*sx),(a[1][i+1]*sy));
		}
		else
		{
		 line((sx*a[0][i]),(sy*a[1][i]),(sx*a[0][i-2]),(sy*a[1][i-2]));
		}
	 }
}
void scalefix(int a[4][4])
{
	int i;
	float sx,sy,p,q;
	printf("Enter the scaling distances: \t");
	scanf("%f%f",&sx,&sy);
	printf("\nEnter the fixed points: \t");
	scanf("%f%f",&p,&q);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		line(((sx*a[0][i])-((p*sx)+p)),((a[1][i]*sy)-((q*sy)+q)),((a[0][i+1]*sx)-((p*sx)+p)),((a[1][i+1]*sy)-((q*sy)+q)));
		}
		else
		{
		 line(((sx*a[0][i])-((p*sx)+p)),((sy*a[1][i])-((q*sy)+q)),((sx*a[0][i-2])-((p*sx)+p)),((sy*a[1][i-2])-((q*sy)+q)));
		}
	 }
}

