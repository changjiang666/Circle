#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>

#define R 200 
#define CIRCLE_NUM 30
#define POINT_NUM 10
#define SIZE 200


struct Pixel

{
	int x;
	int y;
};
struct Circle
{
	double x;
	double y;
	double r;
};
struct Circle _circle[CIRCLE_NUM];
struct Pixel _pixel[POINT_NUM];


void draw()
{
	line(0, 0, 2 * R, 0);
	line(0, 0, 0, 2 * R);
	line(2 * R, 0, 2 * R, 2 * R);
	line(0, 2 * R, 2 * R, 2 * R);
	srand((unsigned)time(NULL));
	for (int i = 0; i < POINT_NUM; i++)
	{
		_pixel[i].x = rand() % (2 * R);
		_pixel[i].y = rand() % (2 * R);
		fillcircle(_pixel[i].x, _pixel[i].y,2);
	}
}
double maxdis(double x,double y,int a)
{
	double dis = R;
	double tem;
	for (int i = 0; i < POINT_NUM; i++)
	{
		tem = sqrt(pow((x - _pixel[i].x),2)  +  pow((y - _pixel[i].y),2));
		if (tem < dis)
			dis = tem;
	}
	if (x < dis)
		dis = x;
	if (y < dis)
		dis = y;
	if (2 * R - x < dis)
		dis = 2 * R - x;
	if (2 * R - y< dis)
		dis = 2 * R - y;
	for (int m = 0; m < a; m++)
	{
		double length = sqrt(pow(x - _circle[m].x, 2) + pow(y - _circle[m].y, 2));
		if (length < _circle[m].r)
			return (-1);
		if (length - _circle[m].r < dis)
			dis = length - _circle[m].r;
	}
	return dis;
}
void shape()
{
	double dis;
	double temp;
	for (int i = 0; i < CIRCLE_NUM; i++)
		_circle[i].r = 0;
	for (int a = 0; a < CIRCLE_NUM; a++)
	{
		dis = 0;
		for (double i = 1.0 / SIZE; i < 2 * R; i = i + 2 * R * 1.0 / SIZE)
			for (double j = 1.0 / SIZE; j < 2 * R; j = j + 2 * R * 1.0 / SIZE)
			{    
				temp = maxdis(i, j, a);
				if (temp < 0)
					continue;
				if (dis < temp)
				{
					dis = temp;
					_circle[a].r = dis;
					_circle[a].x = i;
					_circle[a].y = j;
				}
			}
 	}
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
		circle(_circle[i].x, _circle[i].y, _circle[i].r);
		Sleep(100);
	}
}

void main()
{
	int driver, mode;
	driver = DETECT;
	mode = 0;
	initgraph(&driver, &mode, "");

	draw();
	shape();
	double j = _circle[0].x;
	double k = _circle[0].y;
	double b = _circle[0].r;
	printf("%lf ,%lf,%lf", j, k, b);
	system("pause");
}