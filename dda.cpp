//Name - WARREN FERNANDES
//Roll No. - 8940
//Batch - B
//Title :- Write the program to implement DDA (Digital Differential Analyzer) Line drawing algorithm.

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

int main()
{
    //gdriver and gmode declaration
    int gd = DETECT ,gm, i;
    //declaring variables required according to the algorithm
    float x, y, dx, dy, steps, xinc, yinc;
    //declaring input value variables
    int x0, x1, y0, y1;
    //declaring variables for the axis
    float maxx,maxy;
    //initializing the graph
    initgraph(&gd, &gm, "");
    //divide the x axis by half
    maxx=getmaxx()/2;
    //divide the y axis by half
    maxy=getmaxy()/2;
    //line for the axes
    line(0,maxy,maxx*2,maxy);
    line(maxx,0,maxx,maxy*2);

    //input the coordinates of first point
    printf("Enter the co-ordinates of first point: ");
    scanf("%d%d", &x0, &y0);
    //input the coordinates of first point
    printf("Enter the co-ordinates of second point: ");
    scanf("%d%d", &x1, &y1);
    //difference values
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    //check whether dx or dy is greater and set steps accordingly
    if(abs(dx)>=abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    //finding the increment values
    xinc = dx/steps;
    yinc = dy/steps;
    //setting the values to the initial coordinate
    x = x0;
    y = y0;
    i = 1;

    while(i<= steps)
    {
        putpixel(maxx+x,maxy-y, WHITE);
        x += xinc;
        y += yinc;
        i=i+1;
    }

    getch();

    closegraph();
}
