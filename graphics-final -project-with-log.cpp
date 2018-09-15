#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <math.h>

#define MIN(x,y) ((x>y)?y:x)
#define MAX(x,y) ((x>y)?x:y)

void drawCircle (int cx, int cy, int cr)
{
    float x,y,r=cr,h=cx,k=cy,th;
    for(float th=0; th<=3.1416*2; th+=0.01)
    {
        x=r*cos(th);
        y=r*sin(th);
        putpixel(h+x, k+y, WHITE);
        printf("\n%d %d",x,y);
        delay(5);
    }

}

void drawEllipse(float xe, float ye, float sa, float ea, float mx, float my)
{
    float a=mx, b=my,h=xe,k=ye, start_angle=sa, end_angle=ea, x,y;
    if(start_angle>end_angle)
    {
        for(float theta=start_angle; theta>=end_angle; theta=theta-.01)
        {
            x=a*cos(theta);
            y=b*sin(theta);
            putpixel(x+h,y+k,WHITE);
            printf("\n%lf\t%lf\t%lf",x+h,y+k,theta);
            delay (5);
        }

    }
    else
    {
        for(float theta=start_angle; theta<=end_angle; theta=theta+.01)
        {
            x=a*cos(theta);
            y=b*sin(theta);
            putpixel(x+h,y+k,WHITE);
            printf("\n%lf\t%lf\t%lf",x+h,y+k,theta);
            delay (5);
        }
    }

}

void drawLine(int x1, int y1, int x2, int y2 )
{
    float dx,dy,m,b,y,x_start,x_end;
    if (x1==x2)
    {
        if (y1>y2)
        {
            for (int i=y1; i>=y2; i--)
            {
                putpixel(x1, i, WHITE);
                printf("\n%d %d",x1,i);
                delay(5);
            }
        }
        else
        {
            for (int i=y1; i<=y2; i++)
            {
                putpixel(x1, i, WHITE);
                printf("\n%d %d",x1,i);
                delay(5);
            }
        }
    }
    else if (y1==y2)
    {
        if (x1>x2)
        {
            for (int i=x2; i<=x1; i++)
            {
                putpixel(i, y1, WHITE);
                printf("\n%d %d",y1,i);
                delay(5);
            }
        }
        else
        {
            for (int i=x1; i<=x2; i++)
            {
                putpixel(i, y1, WHITE);
                printf("\n%d %d",y1,i);
                delay(5);
            }
        }
    }
    else
    {

        dx=x2-x1;
        dy=y2-y1;
        m=dy/dx;
        b=y1-m*x1;
        x_start=MIN(x1,x2);
        x_end=MAX(x1,x2);
        for(int x=x_start; x<=x_end; x++)
        {
            setbkcolor(15);
            y=m*x+b;
            putpixel(x,y,WHITE);
            printf("\n%d %d",x,y);
            delay(5);
        }
    }

}

int main()
{
    int gd,gm;
    gd=DETECT;
    initgraph(&gd, &gm,"C:\\TC\\bgi");
    //draw a circle
    drawCircle (206, 134, 10);
    //draw two ellipse
    drawEllipse(210,125,8.5,6.4,20,20);
    drawEllipse(211,147,5.62,8.05,25,34);
    //draw lines
    drawLine(206,181,260,195);
    drawLine(260,195,260,115);
    drawLine(260,120,280,120);
    //set color for paper
    setcolor(15);
    //draw paper
    rectangle(400,120,500,250);
    for(int n=130; n < 250; n+=10)
    {
        //draw line at paper
        setcolor(4);
        line(405,n,495,n);
    }
    getch();
    closegraph();
    return 0;
}
