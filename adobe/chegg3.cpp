#include <iostream>
#include <climits>
#include <cmath>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<float.h>
using namespace std;

int count = 0;
//int countDC = 0;
int p1Index = 0;
int p2Index = 0;

int x;
int y;

struct Point {double x, y;};

// sort by x
inline int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// sort by y
inline int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// find the distance between two points
inline double dist(Point p1, Point p2)
{
    return sqrt( (float(p1.x) - float(p2.x))*(float(p1.x) - float(p2.x)) +
                 (float(p1.y) - float(p2.y))*(float(p1.y) - float(p2.y)) );
}

double bruteForce(Point P[], int n, Point &p1, Point &p2)
{
    double min = DBL_MAX;
    for (int i = 0; i < n; ++i)
    {

        for (int j = i+1; j < n; ++j)
        {
   count = count +1;
            if (dist(P[i], P[j]) < min)
            {
                min = dist(P[i], P[j]);
          p1.x = P[i].x, p1.y = P[i].y;
          p2.x = P[j].x, p2.y = P[j].y;

    p1Index = i;
          p2Index = j;
         }
  }
 }
    return min;
}

// returns minimum of two values
inline double min(double x, double y)
{
    return (x < y)? x : y;
}


// find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted by y.
double stripPoints(Point strip[], int size, double d, Point &p1, Point &p2)
{
    double min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);

    // Pick all points one by one and try the next points
    // till the difference between y's is smaller than d.
    for (int i = 0; i < size; ++i)
    {

        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
        {

            if (dist(strip[i],strip[j]) < min)
            {
    count = count + 1;
                min = dist(strip[i], strip[j]);

                p1Index = i;
    p2Index = j;

          p1.x = strip[i].x, p1.y = strip[i].y;
          p2.x = strip[j].x, p2.y = strip[j].y;
         }
  }
 }

    return min;
}

// find the smallest distance recursively.
// All point in array P are sorted by x
double closest(Point P[], Point strip[], int n, Point &p1, Point &p2)
{
    static Point ptemp1, ptemp2, ptemp3, ptemp4;

    qsort(P, n, sizeof(Point), compareX);

    // use brute force when there are not enough points
    if (n <= 3)
    {
  //countDC = countDC +1;
        return bruteForce(P, n, ptemp1, ptemp2);
 }

    // mid point
    int mid = n/2;
    Point midPoint = P[mid];

    // calculate the smallest distance
    // dl: left of mid point
    // dr: right side of the mid point
    double dl = closest(P, strip, mid, ptemp1, ptemp2);
    double dr = closest(P + mid, strip, n-mid, ptemp3, ptemp4);

    // assign the pair that has smaller distance
    if(dl < dr) {
    p1.x = ptemp1.x; p1.y = ptemp1.y;
    p2.x = ptemp2.x; p2.y = ptemp2.y;
    }

    else
    {
     p1.x = ptemp3.x; p1.y = ptemp3.y;
     p2.x = ptemp4.x; p2.y = ptemp4.y;
    }

    double dmin = min(dl, dr);

    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < dmin)
            strip[j++] = P[i];

    double dmin_strip = stripPoints(strip, j, dmin, ptemp1, ptemp2);
    double final_min = dmin;
    if(dmin_strip < dmin)
    {
        p1.x = ptemp1.x;
        p1.y = ptemp1.y;
        p2.x = ptemp2.x;
        p2.y = ptemp2.y;
        final_min = dmin_strip;
    }
    return final_min;
}

void initpoints(Point P[], int n, int range, int seed=-1)
{
 if (seed < 0)
  seed = clock();

 srand(seed);
 // Fill array with unique points[i] for i from 0 .. n-1
 int i = 0;
 int j;

 while (i < n)
 {
  //Point p(rand() % range, rand() % range);  // Create random point within range

  Point p;
  p.x = rand() % range;
  p.y = rand() % range;

  for (j = 0; j < i; ++j)
  {
   // Search to see if new point is unique
   if (P[j].x == p.x && P[j].y == p.y)
     break; // already existing point
  }

  if (j >= i)
  {
   P[i] = p; // Unique point -- save it
   i++;  // Move on to next point
  }
 }
}


void display(Point P[], int n)
{
 Point p1 = {DBL_MAX, DBL_MAX}, p2 = {DBL_MAX, DBL_MAX};

 Point *strip = new Point[n];


 int point1i;
 int point2i;
 count = 0;

 cout<<"Points[" << n << "]\n";
 for(int i =0; i < n; i++)
 {
  cout<<"[ " << P[i].x << ", " << P[i].y << "] ";
 }

 cout<<"\n\nBrute Force";
 cout<<"\nThe samllest distance is " << bruteForce(P, n, p1, p2);
 cout << " --> P"<< p1Index <<"[" << P[p1Index].x << "," << P[p1Index].y << "]"
  << " : P" << p2Index <<"[" << P[p2Index].x << "," << P[p2Index].y << "]";
 cout<<"\n-->\t" << count << " point-to-point distance calculations\n\n";

 point1i = p1Index;
 point2i = p2Index;
 count = 0;

 cout<<"\nDivide & Conquer";
 cout<<"\nThe samllest distance is " << closest(P, strip, n, p1, p2);

 cout<< "--> P"<< point1i <<"[" << p1.x << "," << p1.y << "]"
  << " : P" << point2i <<"[" << p2.x << "," << p2.y << "]";
 cout<<"\n-->\t" << count << " point-to-point distance calculations\n\n";

 cout<<"\n--------------------------------------------------------------------------------\n\n";

  delete[] strip;


}

int main()
{
 int point1i;
 int point2i;

 Point Pbig[100];
 initpoints(Pbig, 100, 1000, 0);

 Point Pbig2[1000];
 initpoints(Pbig2, 1000, 1000, 0);

    Point P[] = { {2,3}, {12,30}, {40, 50}, {5,1}, {12,10}, {3,4}};

    Point P1[] = {{1,1}, {2,5}, {15, 1}, {16, 1}, {36, 4}, {39, 1}};

    Point P2[] = {{1,1}, {2,5}, {15, 1}, {23, 1}, {36, 4}, {39, 1}};

    Point P3[] = {{1,1}, {2,24}, {15, 1}, {23, 1}, {36, 4}, {39, 1}};


 int n;

 n = sizeof(P) / sizeof(P[0]);
    display(P, n);

    n = sizeof(P1) / sizeof(P1[0]);
 display(P1, n);


 n = sizeof(P2) / sizeof(P2[0]);
 display(P2, n);

 n = sizeof(P3) / sizeof(P3[0]);
 display(P3, n);

 /*
 n = sizeof(Pbig) / sizeof(Pbig[0]);
 display(Pbig, n);

 n = sizeof(Pbig2) / sizeof(Pbig2[0]);
 display(Pbig2, n);
 */

 system("pause");
    return 0;
}
