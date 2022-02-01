#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
	double a,b,c,d,area,width,height;

	if(R1->x >= R2->x+R2->w || R2->x >= R1->x+R1->w || R1->y <= R2->y-R2->h || R2->y <= R1->y-R1->h) return 0;
	
	if(R1->x > R2->x){
		a = R1->x;
	}else if(R1->x < R2->x){
		a = R2->x;
	}
	
	if(R1->x+R1->w > R2->x+R2->w){
		b = R2->x+R2->w;
	}else if(R1->x+R1->w < R2->x+R2->w){
		b = R1->x+R1->w;
	}

	if(R1->y > R2->y){
		c = R2->y;
	}else if(R1->y < R2->y){
		c = R1->y;
	}

	if(R1->y-R1->h > R2->y-R2->h){
		d = R1->y-R1->h;
	}else if(R1->y-R1->h < R2->y-R2->h){
		d = R2->y-R2->h;
	}

	width = b - a;
	if(width >= 0){
		width = width;
	}else{
		width = -width;
	} 

	height = c - d;
	if(height >= 0){
		height = height;
	}else{
		height = -height;
	}

	area = width*height ;
	return area;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};
	cout << overlap(&R1,&R2);
	return 0;
}


