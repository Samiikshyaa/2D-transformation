#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawtriangle(int[4][4]);
void rotation(int[4][4]);
void rotateaboutp(int[4][4]);
void refx(int[4][4]);
void refy(int[4][4]);
void reforigin(int[4][4]);
void refya(int[4][4]);
void refxb(int[4][4]);
void refyx(int[4][4]);
void refy_x(int[4][4]);
void refline(int[4][4]);
void main()
{
	int gd=DETECT,gm,i,a[4][4],ch;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	printf("SAMIKSHYA TIMALSINA\t\t\t\t\t\tHCE076BCT034");
	printf("\n\nEnter the coordinates of a triangle:");
	for(i=0; i<3; i++)
	{
		printf("\n(X%d , Y%d) = ",i,i);
		scanf("%d\t%d",&a[0][i],&a[1][i]);
	       //	printf("\n");
	}
	drawtriangle(a);
	do{
	printf("\n****MENU****");
	printf("\n1 -> Rotation");
	printf("\n2 -> Rotation about a point (a,b)");
	printf("\n3 -> Reflection through x-axis");
	printf("\n4 -> Reflection through y-axis");
	printf("\n5 -> Reflection through origin");
	printf("\n6 -> Reflection through a line y=a");
	printf("\n7 -> Reflection through a line x=b");
	printf("\n8 -> Reflection through a line y=x");
	printf("\n9 -> Reflection through a line y=-x");
	printf("\n10 -> Reflection through a line y=mx+c");
	printf("\n11 -> Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		rotation(a);
		break;
	case 2:
		rotateaboutp(a);
		break;
	case 3:
		refx(a);
		break;
	case 4:
		refy(a);
		break;
	case 5:
		reforigin(a);
		break;
	case 6:
		refya(a);
		break;
	case 7:
		refxb(a);
		break;
	case 8:
		refyx(a);
		break;
	case 9:
		refy_x(a);
		break;
	case 10:
		refline(a);
		break;
	default:
		printf("\nBYE");
	}
	}while (ch!=11);
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
void rotation(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2,angle;
	printf("Enter the angle \t");
	scanf("%f",&angle);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x=a[0][i];
		y=a[1][i];
		x1=((x*cos(angle))-(y*sin(angle)));
		y1=((x*sin(angle))+(y*cos(angle)));
		x=a[0][i+1];
		y=a[1][i+1];
		x2=((x*cos(angle))-(y*sin(angle)));
		y2=((x*sin(angle))+(y*cos(angle)));
		line(x1,y1,x2,y2);
		}
		else
		{
		x=a[0][i];
		y=a[1][i];
		x1=((x*cos(angle))-(y*sin(angle)));
		y1=((x*sin(angle))+(y*cos(angle)));
		x=a[0][i-2];
		y=a[1][i-2];
		x2=((x*cos(angle))-(y*sin(angle)));
		y2=((x*sin(angle))+(y*cos(angle)));
		line(x1,y1,x2,y2);
		}
	 }
}
void rotateaboutp(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2,xr,yr,angle;
	printf("Enter the points \t");
	scanf("%f%f",&xr,&yr);
	printf("Enter the angle \t");
	scanf("%f",&angle);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x=a[0][i];
		y=a[1][i];
		x1=(xr+((x-xr)*cos(angle))-((y-yr)*sin(angle)));
		y1=(yr+((x-xr)*sin(angle))+((y-yr)*cos(angle)));
		x=a[0][i+1];
		y=a[1][i+1];
		x2=(xr+((x-xr)*cos(angle))-((y-yr)*sin(angle)));
		y2=(yr+((x-xr)*sin(angle))+((y-yr)*cos(angle)));
		line(x1,y1,x2,y2);
		}
		else
		{
		x=a[0][i];
		y=a[1][i];
		x1=(xr+((x-xr)*cos(angle))-((y-yr)*sin(angle)));
		y1=(yr+((x-xr)*sin(angle))+((y-yr)*cos(angle)));
		x=a[0][i-2];
		y=a[1][i-2];
		x2=(xr+((x-xr)*cos(angle))-((y-yr)*sin(angle)));
		y2=(yr+((x-xr)*sin(angle))+((y-yr)*cos(angle)));
		line(x1,y1,x2,y2);
		}
	 }
}
void refx(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2;
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(x1,-y1,x2,-y2);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(x1,-y1,x2,-y2);
		}
	}
}
void refy(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2;
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(-x1,y1,-x2,y2);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(-x1,y1,-x2,y2);
		}
	}
}
void reforigin(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2;
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(-x1,-y1,-x2,-y2);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(-x1,-y1,-x2,-y2);
		}
	}
}
void refya(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2,s;
	printf("Enter the value of a: \t");
	scanf("%f",&s);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(x1,-y1+2*s,x2,-y2+2*s);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(x1,-y1+2*s,x2,-y2+2*s);
		}
	}
}

void refxb(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2,b;
	printf("Enter the value of b: \t");
	scanf("%f",&b);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(-x1+2*b,y1,-x2+2*b,y2);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(-x1+2*b,y1,-x2+2*b,y2);
		}
	}
}
void refyx(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2;
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(y1,x1,y2,x2);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(y1,x1,y2,x2);
		}
	}
}
void refy_x(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2;
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i+1];
		y2=a[1][i+1];
		line(-y1,-x1,-y2,-x2);
		}
		else
		{
		x1=a[0][i];
		y1=a[1][i];
		x2=a[0][i-2];
		y2=a[1][i-2];
		line(-y1,-x1,-y2,-x2);
		}
	}
 }
void refline(int a[4][4])
{
	int i;
	float x,y,x1,x2,y1,y2,m,c;
	printf("Enter the slope: \t");
	scanf("%f",&m);
	printf("Enter the constant, c: \t");
	scanf("%f",&c);
		for(i=0;i<3;i++)
	{
		if(i<2)
		{
		x=a[0][i];
		y=a[1][i];
		x1=(((1+(m*m))/(1+(m*m)))*x)+(((2*m)/(1+(m*m)))*y)-((2*c*m)/(1+(m*m)));
		y1=(((2*m)/(1+(m*m)))*x)+((((m*m)-1)/(1+(m*m)))*x)+((2*c*m)/(1+(m*m)));
		x=a[0][i+1];
		y=a[1][i+1];
		x2=(((1+(m*m))/(1+(m*m)))*x)+(((2*m)/(1+(m*m)))*y)-((2*c*m)/(1+(m*m)));
		y2=(((2*m)/(1+(m*m)))*x)+((((m*m)-1)/(1+(m*m)))*x)+((2*c*m)/(1+(m*m)));
		line(x1,y1,x2,y2);
		}
		else
		{
		x=a[0][i];
		y=a[1][i];
		x1=(((1+(m*m))/(1+(m*m)))*x)+(((2*m)/(1+(m*m)))*y)-((2*c*m)/(1+(m*m)));
		y1=(((2*m)/(1+(m*m)))*x)+((((m*m)-1)/(1+(m*m)))*x)+((2*c*m)/(1+(m*m)));
		x=a[0][i-2];
		y=a[1][i-2];
		x2=(((1+(m*m))/(1+(m*m)))*x)+(((2*m)/(1+(m*m)))*y)-((2*c*m)/(1+(m*m)));
		y2=(((2*m)/(1+(m*m)))*x)+((((m*m)-1)/(1+(m*m)))*x)+((2*c*m)/(1+(m*m)));
		line(x1,y1,x2,y2);
		}
	 }
}