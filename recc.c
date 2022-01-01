/*
Develop a program that, given as input the cartesian coordinates of three vertices of a rectangle,
reports the area of that rectangle. You will recall that the area of a rectangle is the product of
the lengths of any two adjacent sides.
Input: The first line contains a positive integer n indicating how many rectangles are to be
analyzed. Each rectangle is described on a single line via six real numbers, x1, y1, x2, y2, x3,
and y3, separated by spaces. These provide the coordinates of three of the rectangle’s vertices,
namely P1(x1, y1), P2(x2, y2), and P3(x3, y3).
Output: For each rectangle provided as input, report its area


Sample input
------------
3
0.0 0.0 0.0 1.0 1.0 0.0
-1.0 2.0 3.0 5.0 1.0 1.0
5.0 9.0 -0.5 0.0 7.5 5.0
Resultant output
----------------
Area of rectangle with vertices (0.0,0.0),(0.0,1.0),(1.0,0.0) is 1.0
Area of rectangle with vertices (-1.0,2.0),(3.0,5.0),(1.0,1.0) is 10.0
Area of rectangle with vertices (5.0,9.0),(-0.5,0.0),(7.5,5.0) is 44.5


*/

#include <stdio.h>
#include <math.h>

typedef struct point
{
    float x, y;
} point;

typedef struct rect
{
    point a, b, c;
    float length, width, area;

} rect;

void input_no_rects(int *n)
{ // Input the number of rectangles
    printf("Enter the number of rectangles : \t");
    scanf("%d", n);
}


void input_rectangle(rect *r){
    printf("Enter the rectangle co-ordinates : \n");
    scanf("%f %f %f %f %f %f", &r->a.x, &r->a.y, &r->b.x, &r->b.y, &r->c.x, &r->c.y);
}


void input_n_rectangles(int n, rect rs[n])
{ // Input all the rectangles one by one
    for (int i = 0; i < n; i++)
    {
        printf("Rectangle No. %d \n", i + 1);
        //rs[i] = input_rectangle();
        input_rectangle(&rs[i]);
    }
}

float find_distance_between_two_points(point a, point b)
{ // Find the distance between two point
    // d=√((x_2-x_1)²+(y_2-y_1)²)
    float distance;
    distance = sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    return distance;
}

void get_area(int n,rect *r)
{
    /*
        Find the longest line, that will be the hypotenuse, other two lines will be length and breadth 
    */
    float ab, bc, ac;
    
    ab = find_distance_between_two_points(r->b, r->a);
    bc = find_distance_between_two_points(r->c, r->b);
    ac = find_distance_between_two_points(r->c, r->a);

    if (ab > bc && ab > ac)
    {   
        r->length = bc;
        r->width = ac;
        r->area = bc * ac;
    }
    else if (bc > ac)
    {
        r->length = ab;
        r->width = ac;
        r->area = ab * ac;
    }
    else if (ac > ab)
    {
        r->length = bc;
        r->width = ab;
        r->area =  bc * ab;
    }
    else if (ab == bc || ab == ac || bc == ac)
    {
        r->length = ab;
        r->width = ac;
        r->area =  ab * bc;
    }
}

void output_n_rects(int n, rect rs[n])
{

    for (int i = 0; i < n; i++)
    {
        get_area(n,&rs[i]);
        printf("Area of rectange with vertices (%0.2f,%0.2f),(%0.2f,%0.2f),(%0.2f,%0.2f) is %0.2f\n", rs[i].a.x, rs[i].a.y, rs[i].b.x, rs[i].b.y, rs[i].c.x, rs[i].c.y, rs[i].area);
    }
}

int main()
{
    int n;
    input_no_rects(&n);
    rect rs[n];
    input_n_rectangles(n,rs);
    output_n_rects(n, rs);
}