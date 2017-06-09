/*#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define R 200 
struct Circle //记录圆的基本信息
{
	double r;
	double x;
	double y;
};
Circle circle_1[3], circle_2[6], circle_3[3],circle_4[3],circle_finally[6];//存放4种类型的圆
void shape_1(int n) //n表示计算第n个圆的信息
{
	double total = 0;
	for (int i = 1; i < n; i++)
		total = total + circle_1[i].r;
	circle_1[n].r = (sqrt(2.0) * R - 2 * total -R)  / (sqrt(2.0) + 1);
	circle_1[n].x = (sqrt(2.0) * R - 2 * total - R) / (sqrt(2.0) + 1);
	circle_1[n].y = (sqrt(2.0) * R - 2 * total - R) / (sqrt(2.0) + 1);
}
void shape_2(int n ,double pred)//x2是预估值
{
	double x1,x2, y1, y2, r1;
	x2 = pred;
	x1 = circle_2[n - 1].x; y1 = circle_2[n - 1].y; r1 = circle_2[n - 1].r;
	for (int i = 0; i < 10; i++)
	{
		y2 = y1 + (double)sqrt((x2 + r1) * (x2 + r1) - (x2 - x1) * (x2 - x1));
		x2 = (y2 * y2 - 2 * R * y2 + R * R) / (4 * R);
	}
	circle_2[n].r = x2; circle_2[n].x = x2; circle_2[n].y = y2;
}
void shape_3(int n,double pred_1,double pred_2)
{
	double x1, x2, y1, y2, r1, r2, x, y, r;
	x = pred_1; r = pred_2;
	x1 = circle_2[n].x; y1 = circle_2[n].y; r1 = circle_2[n].r;
	x2 = circle_2[n + 1].x; y2 = circle_2[n + 1].y; r2 = circle_2[n + 1].r;
	for (int i = 0; i < 1; i++)
	{
		y = y2 - sqrt(abs((x - x2) * (x - x2) - (r + r2) * (r + r2)));
		x = R - sqrt(abs((r + R) * (r + R) - (y - R) * (y - R)));
		r = r1 - sqrt(abs((x - x1) * (x - x1) + (y - y1) * (y - y1)));
	}
	circle_3[n].r = r; circle_3[n].x = x; circle_3[n].y = y;
}
void shape_4(int n, double pred)
{
	double x1, x2, y1, y2, r1, r2, x, y;
	x = pred;
	if (n > 0)
		x = circle_4[n - 1].r / 2;
	x1 = circle_2[n].x; y1 = circle_2[n].y; r1 = circle_2[n].r;
	x2 = circle_2[n + 1].x;	y2 = circle_2[n + 1].y;	r2 = circle_2[n + 1].r;
	for (int i = 0; i < 3; i++)
	{
		y = y1 + sqrt((x + x1) * (x + x1) -(x - x1) * (x - x1));
		x = (y - y2) * (y - y2) / (4 * x2);
	}
	circle_4[n].r = x; circle_4[n].x = x; circle_4[n].y = y;
}
void draw()  //第一个圆是显而易见的，因此直接画出
{
	line(0, 0, 2 * R, 0);
	line(0, 0, 0, 2 * R);
	line(2 * R, 0, 2 * R, 2 * R);
	line(0, 2 * R, 2 * R, 2 * R);
	circle(R, R, R); //最大的圆默认为已知，编号为0
	circle_1[0].r = R; circle_1[0].x = R; circle_1[0].y = R;
	for (int i = 1; i < 3; i++)
	{
		shape_1(i);
		circle(circle_1[i].x, circle_1[i].y, circle_1[i].r);
		circle(2 * R - circle_1[i].x, circle_1[i].y, circle_1[i].r);
		circle(circle_1[i].x, 2 * R - circle_1[i].y, circle_1[i].r);
		circle(2 * R - circle_1[i].x, 2 * R - circle_1[i].y, circle_1[i].r);
	}
	circle_2[0].r = circle_1[1].r; circle_2[0].x = circle_1[1].x; circle_2[0].y = circle_1[1].y;
	for (int i = 1; i < 6; i++)
	{
		shape_2(i, circle_2[i - 1].x / 2);
		circle(circle_2[i].x, circle_2[i].y, circle_2[i].r);
		circle(circle_2[i].x, circle_2[i].y, circle_2[i].r);
		circle(2 * R - circle_2[i].x, circle_2[i].y, circle_2[i].r);
		circle(circle_2[i].x, 2 * R - circle_2[i].y, circle_2[i].r);
		circle(2 * R - circle_2[i].x, 2 * R - circle_2[i].y, circle_2[i].r);
	}
	for (int i = 0; i < 4; i++)
	{
		shape_3(i, circle_2[i + 1].x , circle_2[i + 1].r / 3);
		circle(circle_3[i].x, circle_3[i].y, circle_3[i].r);
	}
	for (int i = 0; i < 2; i++)
	{
		shape_4(i, circle_1[2].x);
		circle(circle_4[i].x, circle_4[i].y, circle_4[i].r);
	}
	
}
int main()
{
	int driver, mode;
	driver = DETECT;
	mode = 0;
	initgraph(&driver, &mode, "");
	draw();
	system("pause");
	return 0;
}*/