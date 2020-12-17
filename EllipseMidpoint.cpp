//Name :- Warren Fernandes
//Roll No. - 8940
//Batch :- B
//Title :- Write the program to implement Mid point Ellipse drawing Algorithm.

 #include<stdio.h>
 #include<graphics.h>
 void ellipse(int xc,int yc,int rx,int ry);

 int main()
 {
   int gm=DETECT,gd;
   initgraph(&gm,&gd," ");
   int xc,yc,rx,ry;
   printf("Enter coordinates of center ");
   scanf("%d%d",&xc,&yc);
   printf("Enter radius of X and Y axis ");
   scanf("%d%d",&rx,&ry);
   ellipse(xc,yc,rx,ry);
   //ellipse(0,0,100,50);
   //ellipse(0,0,50,100);
   //ellipse(100,100,50,100);
   //ellipse(100,100,100,50);
   getch();
   closegraph();
 }
void ellipse(int xc,int yc,int rx,int ry)
{
   //declaring variables required according to the algorithm
   int x, y, p;
    //declaring variables for the axis
   int maxx,maxy;
    //divide the x and y axis by half
   maxx=getmaxx()/2;
   maxy=getmaxy()/2;
   //line for the axes
   line(0,maxy,maxx*2,maxy);
   line(maxx,0,maxx,maxy*2);
   x=0;
   y=ry;
   //initial decision parameter
   p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);

   while((2*x*ry*ry)<(2*y*rx*rx))
   {
        putpixel(maxx+xc+x,maxy-(yc-y),WHITE);
        putpixel(maxx+xc-x,maxy-(yc+y),WHITE);
        putpixel(maxx+xc+x,maxy-(yc+y),WHITE);
        putpixel(maxx+xc-x,maxy-(yc-y),WHITE);

        if(p<0)
        {
             x=x+1;
             p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
             x=x+1;
             y=y-1;
             p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
   }

   p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

   while(y>=0)
   {
        putpixel(maxx+xc+x,maxy-(yc-y),WHITE);
        putpixel(maxx+xc-x,maxy-(yc+y),WHITE);
        putpixel(maxx+xc+x,maxy-(yc+y),WHITE);
        putpixel(maxx+xc-x,maxy-(yc-y),WHITE);

        if(p>0)
        {
             y=y-1;
             p=p-(2*rx*rx*y)+(rx*rx);

        }
        else
        {
             y=y-1;
             x=x+1;
             p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
        }
   }

 }
