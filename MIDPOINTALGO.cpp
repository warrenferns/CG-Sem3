//Name - Warren Fernandes
//Roll No. - 8940
//Batch - B
//Title:- Write the program to implement Midpoint Circle Drawing algorithm

#include<stdio.h>
#include<graphics.h>
void draw_circle(int x0, int y0, int rad);
int main()
{
    //gdriver and gmode declaration
	int gdriver = DETECT, gmode, error, x, y, rad;
	//initializing the graph
	initgraph(&gdriver, &gmode, " ");
	//declaring variables for the axis
    int maxx,maxy;
    //divide the x and y axis by half
    maxx=getmaxx()/2;
    maxy=getmaxy()/2;
    //line for the axes
    line(0,maxy,maxx*2,maxy);
    line(maxx,0,maxx,maxy*2);
    //input radius value
	printf("Enter the radius of circle: ");
	scanf("%d", &rad);
	//input the coordinates of the center
	printf("Enter the co-ordinates of center: ");
	scanf("%d%d", &x, &y);
    //call the function
	draw_circle(maxx+x, maxy-y, rad);

    getch();
    closegraph();

	return 0;
}
void draw_circle(int x0, int y0, int r)
{
    //declaring variables required according to the algorithm
    int x = 0;
    int y = r;
    int p = 1 - r;
    //choosing decision parameter and putting pixels
    while (x < y){
        if (p < 0){
	    x++;
	    p += 2*x + 1;
        }
        else{
	    x ++;
	    y--;
	    p += 2*(x-y) + 1;
        }
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 + y, y0 + x, WHITE);
        putpixel(x0 - y, y0 + x, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 - y, y0 - x, WHITE);
        putpixel(x0 + y, y0 - x, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
    }
}
