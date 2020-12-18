//Name:- Warren Fernandes
//Roll No:- 8940
//Batch:- B
//Title :- Write the program to implement Boundary fill and Flood fill algorithm using 8 connected approach. (5.a - Boundary fill algorithm and 5.b-Flood fill algorithm)
//Submission Date: 16/8/2020

#include <graphics.h>
#include<stdio.h>
//5.a Boundary Fill Algorithm 8 connected approach
void boundary(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color &&
       getpixel(x, y) != fill_color)
    {

        putpixel(x, y, fill_color);
        boundary(x+1,y, fill_color, boundary_color);
        boundary(x,y+1, fill_color, boundary_color);
        boundary(x-1,y, fill_color, boundary_color);
        boundary(x,y-1, fill_color, boundary_color);
        boundary(x+1,y+1, fill_color, boundary_color);
        boundary(x-1,y+1, fill_color, boundary_color);
        boundary(x-1,y-1, fill_color, boundary_color);
        boundary(x+1,y-1, fill_color, boundary_color);
    }
}

//5.b Flood Fill Algorithm 8 connected approach
void flood(int x,int y,int fillColor, int defaultColor)
{
    if(getpixel(x,y)==defaultColor)
    {
        putpixel(x,y,fillColor);
        flood(x+1,y,fillColor,defaultColor);
        flood(x-1,y,fillColor,defaultColor);
        flood(x,y+1,fillColor,defaultColor);
        flood(x,y-1,fillColor,defaultColor);
        flood(x+1,y+1,fillColor,defaultColor);
        flood(x-1,y+1,fillColor,defaultColor);
        flood(x+1,y-1,fillColor,defaultColor);
        flood(x-1,y-1,fillColor,defaultColor);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(50,50,500,150);
    rectangle(50,150,500,250);
    rectangle(50,250,500,350);
    boundary(60, 60, 12, 15);
    flood(51, 151, 15, 0);
    boundary(60, 260, 2, 15);
    setcolor(BLUE);
    circle(275,200,50);
    circle(275,200,5);
    delay(10000);
    getch();
    closegraph();
    return 0;
}
