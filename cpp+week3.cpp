
//301.
#include<iostream>
using namespace std;
int main()
{ 
	float x, y, z;
	cin >> x >> y >> z;
	if (x<y&&y<z)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	return 0;
}

//302.
#include<iostream>
using namespace std;
int main()
{ 
	float a, b, c;
	cin >> a >> b >> c;
	if (a<=b&&b<=c)
	{
		cout << a * 2 << endl;  //if condition is true, double our variables
		cout << b * 2 << endl;
		cout<<c * 2 << endl;
	}
	else
	{
		if (a<0)  //if number is negative, multiply to (-1) to have absolut value
		{
			cout << a * (-1) << " ";
		}
		else
		{
			cout << a<<" "; //if it is positive output this number
		}
		if (b < 0)
		{
			cout << b * (-1) << " ";
		}
		else
		{
			cout << b<<" ";
		}
		if (c < 0)
		{
			cout << c * (-1) << " ";
		}
		else
		{
			cout << c<<" ";
		}
		
	}
	return 0;
}

//303.
#include<iostream>
#include<cmath> //for mathematical operations
using namespace std;
int main()
{ 
	float a, b, c, D, x1, x2;
	cin >> a >> b >> c;
	D = (b*b) - (4 * a * c); //formula of discriminant
	x1 = ((-1)*b + sqrt(D)) / (2 * a); //first root
	x2 = ((-1)*b - sqrt(D)) / (2 * a); //second root
	if (D>0){cout << x1 <<" "<< x2;}  //if D>0 we have 2 roots
	else if (D==0){cout << x1;}   //if D=0 our roots are equal to each other x1=x2
	else{cout << "no solution" << endl;} //if D<0 we do not have roots
	return 0;
}

//304.
#include<iostream>
#include<cmath> //for mathematical operations
using namespace std;
int main()
{ 
	float x, y, z;
	cin >> x >> y >> z;
	if (x<y&&x<z) //finding our minimum number, if x is lower than y and than z, x is minimum number
	{
		cout << x << " ";
	}
	else if (y<x&&y<z) //if y is lower than x and than z, y is minimum number
	{
		cout << y << " ";
	}
	else  //if z is lower than x and than y, z is minimum number
	{
		cout << z << " ";
	}

	if (x>y&&x>z) //finding our maximum number, if x is bigger than y and than z, x is maximum number
	{
		cout << x << " ";
	}
	else if (y>x&&y>z)
	{
		cout << y << " ";
	}
	else
	{
		cout << z << " ";
	}
	return 0;
}

//305.
#include<iostream>
#include<cmath> //for mathematical operations
using namespace std;
int main()
{ 
	float x, y, z;
	cin >> x >> y >> z;
	if (x+y>z&&x+z>y&&z+y>x) //figure can be triangle only if sum of two sides is bigger than third side
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

	return 0;
}

//306.
#include<iostream>
using namespace std;
int main()
{ 
	int year;
	cin >> year;
	//leap year is divisible by 4 or by 400, but not by 4 and 100 at the same time
	if (year%4==0&&year%100!=0||year%400==0)
	{
		cout << "366";
	}
	else
	{
		cout << "365";
	}
	return 0;
}

//307.
#include<iostream>
using namespace std;
int main()
{ 
	int day, month, year;
	cin >> day >> month >> year;
//checking if it is a leap year:
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		if (month == 2 && day <= 29) //february has only 29 days in leap year
		{cout << "yes";}	
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day<=30) //month with not more than 30 days
				{cout << "yes";}
				else
				{cout << "no";}
			}
			else if (month == 1 || month == 3 || month == 5 || month == 8 || month == 10 || month == 12)
			{
				if (day <= 31) //month with not more than 31 days
				{cout << "yes";}
				else
				{cout << "no";}
			}
		else
		{cout << "no";}
	}
//for non-leap year:
	else {

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30)
			{cout << "yes";}
			else
			{cout << "no";}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31)
			{cout << "yes";}
			else
			{cout << "no";}
		}
		else if (month == 2 && day <= 28) //february has 28 days only
		{cout << "yes";}
		else
		{cout << "no";}
	}
	return 0;
}




//309.

#include<iostream>
using namespace std;
int main()
{
	int day, month, year;
	cin >> day >> month >> year;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) //leap year
	{
		if (month == 2 && day == 29)
		{
			day = 1;
			month = 3;
			cout << day <<" "<< month<< " " << year;
		}
		else if (day==30&&month == 4 || day == 30 && month == 6 || day == 30 && month == 9 || day == 30 && month == 11)
		{
			day = 1;
			month = month + 1;
			cout << day << " " << month << " " << year;
		}
		else if (day==31&&month == 1 || day == 31 && month == 3 || day == 31 && month == 5 || day == 31 && month == 8 || day == 31 && month == 10)
		{
			day = 1;
			month = month + 1;
			cout << day << " " << month << " " << year;
		}
		else if (month==12&&day==31)
		{
			day = 1;
			month = 1;
			year += 1;
			cout << day << " " << month << " " << year;
		}
		else
		{
			day = day + 1;
			cout << day << " " << month << " " << year;
		}	
	}
	else //not leap year
	{
		if (month == 2 && day == 28)
		{
			day = 1;
			month = 3;
			cout << day << " " << month << " " << year;
		}
		else if (day==30&&month == 4 || day == 30 && month == 6 || day == 30 && month == 9 || day == 30 && month == 11)
		{
			day = 1;
			month = month + 1;
			cout << day << " " << month << " " << year;
		}
		else if (day == 31&&month == 1 || day == 31 && month == 3 || day == 31 && month == 5 || day == 31 && month == 8 || day == 31 && month == 10)
		{
			day = 1;
			month = month + 1;
			cout << day << " " << month << " " << year;
		}
		else if (month == 12 && day == 31)
		{
			day = 1;
			year += 1;
			cout << day << " " << month << " " << year;
		}
		else
		{
			day = day + 1;
			cout << day << " " << month << " " << year;
		}
	}
	return 0;
}

//310.
#include<iostream>
using namespace std;
int main()
{ 
	int n;  //enter the range of power (5)
	cin >> n;
	int sum = 1;  //
	for (int i=1; i <= n; i++) 

	/* i=1, 1<5, sum=1*2=2
	i=2,2<5,sum=2*2=4
	i=3,3<5,sum=4*2=8
	i=4,4<5,sum=8*2=16
	i=5,5=5,sum=16*2=32*/

	{
		sum = sum * 2;
	}
	cout << sum;

	return 0;
}

//311.
#include<iostream>
using namespace std;
int main()
{ 
	int n;
	cin >> n; //enter number (4)
	int sum=1;
	for (int i = 1; i <=n; i++)
	/* i=1, 1<4, sum=1*1=1
	i=2,2<4,sum=1*2=2
	i=3,3<4,sum=2*3=6
	i=4,4=4,sum=6*4=24*/
	{
		sum = sum * i;
	}
	cout << sum;
	return 0;
}
//312.
#include<iostream>
using namespace std;
int main()
{ 
	int n;
	cin >> n;
	float sum=1;
	for (float i = 1; i <=n; i++)
	{
		sum = sum * (1 + (1 / (i *i)));  
	}
	cout << sum;
	return 0;
}

//314.
#include<iostream>
#include <cmath>   //for mathematical operations
using namespace std;
int main()
{ 
	int n;
	cin >> n;
	double sum = sqrt(2);
	for (int i = 1; i <n; i++)
	{
		sum = sqrt(sum + 2);
	}
	cout << sum;
	return 0;
}

//315.
	
#include<iostream>
using namespace std;
int main()
{
  double a,b;
  int n;
  cin >> a >> n;
  b = a;   //b have value of a and will not change 
  for (int i = 1; i <n; i++)
  {
    a = a + b;  //a changes every time, but b is the same
  }
  cout << a;
  return 0;
}

//316.
#include<iostream>
using namespace std;
int main()
{
	double a,sum;
	int n;
	cin >> a >> n;
	sum=1;
	for (int i = 0; i <n; i++)
	{
		sum = sum * (a + i);
	}
	cout << sum;
	return 0;
}

//317.
#include<iostream>
using namespace std;
int main()
{
	double a, n;
	cin >> a >> n;  //2 and 1
	double b,sum;
	sum = 0;
	b = 1;
	for (int i = 0; i <= n; i++)
	{
		b = b * (1 / (a + i));

		/* b=1*(1/(2+0))=0.5
		   sum=0.5+0=0.5

		   b=0.5*(1/3)=0.166667
		   sum=0.166667+0.5=0.666667 */

		sum = b + sum;
	}
	cout << sum; //0.666667
	return 0;
}

//318.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, n,sum;
	cin >>a>>n;
	sum = 0;
	sum = sum + 1 / pow(a, 1); //sum=0+(1/a)
	for (int i = 2; i <= 2 * n; i += 2)
	{
		sum += (1 / pow(a, i));  //sum=1/a + 1/a^2 +.....
	}
	cout << sum;
	return 0;
}

//319.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{	
	double x, sum, minus;
	cin >> x;
	minus = -1;
	sum = 0;
	for (int i = 3; i <= 13; i += 2)  //power of x is encreasing to 2
	{
		double fact = 1;   //nested loop
			for (int j = 1; j <= i; j += 1) //counting factorial of each denomirator
			{
				fact = fact * j; 
			} 

/* first, i=3, so factorial will be 1*2*3; after that outer loop works */

		minus = minus * (-1);  
/*"minus" is already equal to -1, so then it will be =1; 
but next time it will be equal to (-1) and sum + (-value) = sum - value*/
		sum += minus * (pow(x, i) / fact);
	}
	cout << x - sum;
	return 0;
}


//320.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, a;
	int n;
	cin >> x >> a >> n;
	double b;   
	b = pow((x + a), 2);
	for (int i = 1; i < n; i++)  
	{
		b = pow((b + a), 2);
		b = b + a;
	}
	cout << b;
	return 0;
}





//321.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, sum;
	cin >> x;
	sum = 1;
	for (int i = 1; i <=6; i++)
	{
		sum *= ((x - pow(2, i)) / (x + 1 - pow(2, i)));      /*(x-2)(x-4)..../(x+1-2)(x+1-4)....*/
	}
	cout << sum;
	return 0;
}

//322.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{	
	double sum;
	sum = 103;  
	int i = 101;   //start from the biggest value of i and every time i will dicrease to 2
	while (i>=1)
	{
		sum = i + (1 / sum);
		i -= 2;
	} 
	cout << 1 / sum;
	return 0;
}

//323.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{	
	double x, sum;
	cin >> x;
	sum = pow(x, 2);
	for (int i = 256; i >= 2; i = i / 2) 

       /* now we start from the end - from the biggest value of i(256) and divide it to 2
	   sum=x^2 + 256/x^2;
	   sum=x^2 + 128/(x^2 + 256/x^2) and so on*/

	{
		sum = x * x + (i / sum);
	} cout << x / sum;  
	return 0;
}


//324.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{	
	double sum;
	sum = 0;
	for (int i = 1; i <= 50; i++)
	{
		sum += 1 / (pow(i, 3));
	}
	cout << sum;
	return 0;
}

//325.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	double a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, b;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10;
	b = pow(a1, 1) + pow(a2, 2) + pow(a3, 3) + pow(a4, 4) + pow(a5, 5) + pow(a6, 6) + pow(a7, 7) + pow(a8, 8) + pow(a9, 9) + pow(a10, 10);
	cout << b;
	return 0;
}
