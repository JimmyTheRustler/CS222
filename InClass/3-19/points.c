#include <stdio.h>
#include <math.h>

struct point{

	double x;
	double y;

};

double distance(struct point* a, struct point* b){
	double deltaX = a->x- b->x;
	double deltaY = a->y - b->y;
	return sqrt(deltaX*deltaX + deltaY*deltaY);

}

int main(){
	struct point point1;
	struct point point2;

	point1.x = 4;
	point1.y = 20;

	point2.x = 3;
	point2.y = 60;

	printf("Distance: %f\n", distance(&point1, &point2));
	
	return 0;
}
