#include <stdio.h>
int main() {
	while(1)
	{
		float f,a,pi=3.1415926;
		scanf("%f",&f);
		if(f==0)
		break;
		else
		a=(0.5)*(f*f/pi);
		printf("%.2f\n",a);
	}
	return 0;
}
