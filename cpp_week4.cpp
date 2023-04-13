
//401.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		cin >> arr[i];  //input our elements, the last one should be -1
		if (arr[i] == -1)
		{
			cout << i << endl; 
		/*when last element -1 is entered, output number of other elements, because array starts with 0'th element*/
			int n = i; //number of elements without -1 are "n"
			for (int i = 0; i < n; i++)  /*output our elements again, but without the last one which is -1*/
			{
				cout << arr[i]<<" ";
			}
			
		}
	}
	return 0;
}

//402.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	double arr[100];
	int i = -1;  //our i have to be equal to 0, so we start from i=-1 and in "do" loop increment it to 0
	do
	{
		i++;  //i=-1+1=0
		cin >> arr[i];  //input our elements

	} while (arr[i]!=0);  //input will be counted until it is 0
	int n = i;
	cout << i << endl;  //output number of our elements without 0
	for (int i = n-1; i >=0; i--) //inverse order: from last element to first
	{
		cout << sqrt(arr[i]) << endl; //finding roots
	}
	
	
	return 0;
}

//403.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[1000],n;
	cin >> n;  //enter the number of elements
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];  //enter the value
	}
	int min;  
	min = arr[0];  //count our first elements of arry as minimal number
	for (int i = 1; i < n; i++)
	/*if second elements arr[1] is smaller than arr[0] then our minimal number is arr[1]. next iteration: if arr[2] is smaller than arr[1] then minimal is arr[2]*/
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	cout << min;


	return 0;
}

//404.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[1000],n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int min, ind;  //new var for index
	min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];  //find our minimal elements as we did in 403rd problem
			ind = i; //find value of index
		}
	}
	cout << ind;


	return 0;
}

//405.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[1000],n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max, number=0;  //new var is number of maximum values
	max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	for (int i=0; i<n;i++)
	{
		if (max==arr[i])
		{
			number = number + 1;
		}
	}
	cout << number;


	return 0;
}

//406.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	char arr[1000];
	int n, number=0; //number of 'A' is zero at first
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i]=='A')
		{
			number += 1; //if any char of arry is 'A' then number increasing
		}
	}
	cout << number;
	return 0;
}


//408.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[1000];
	int n;
	cin >> n;
	int k, need, i = 0;
	for (; i < n; i++)
	{
		cin >> a[i];  //enter our elements
	}
	for (i = 0; i < n; i++)
	{
		for ( k = i+1; k < n; k++)  //a[i] is first element(0) and a[k] is second(1)
		{
			if (a[i] > a[k])  //if second element is smaller than we change the order
			{
				need = a[i];  
				a[i] = a[k];  //a[i] is second now
				a[k] = need;   //a[k] is first now
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	
	
	return 0;
}

//409.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int time[100];
	int n, hh,mm,ss,need;
	cin >> n; //input how many time intervals do we need
	for (int i = 0; i < n; i++)
	{
		cin >> hh >> mm >> ss; 
		time[i] = hh * 3600 + mm * 60 + ss; 
		/*we turn our hours and minutes to seconds, 
		so that we can compare all intervals in seconds*/

	}
	for (int i = 1; i < n; i++) //i=1, so we have time[i] which is time[1] and...
	{
		int j=0; //we have time[j] which is time[0]
		while (j < i)  
		{
			if (time[i] < time[j])
			/*compare two neighbour element, if time[1] is less than time[0] we change their order*/
			{
				need = time[i];  //using bubble sorting 
				time[i] = time[j];
				time[j] = need;
			}
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		hh = time[i] / 3600; //we turn our seconds into hours, minutes and find seconds again
		mm = (time[i] - hh * 3600) / 60;
		ss = time[i]%60;
		cout << hh << " " << mm << " " << ss << endl;
	}

	return 0;
}

//410.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int k, number=0;
	cin >> k;
	for (int i = 2; i < k; i++)  //i is not equal to 1 and k(number itself)
	{
		if (k % i == 0) //we divide our number to all number except 1 and number itself
		{
			number++; //if it can be divided by another number we count it
		}
	}
	if (number > 0)  //if there are any number that can divide our input, it is not prime number
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
	}

	return 0;
}

//411.

#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool bob; /*create boll var to check if number is prime or not*/
	for (int i = 2; i <= n; i++) //0 and 1 is not prime, so we start from 2
	{
		bob = true;
		int k = 2;
		while (k <= i/2)
			/*it is enough to divide i to k which is equal or less than the half of i,
			because for example 24/2=12 and there is no need to divide it like 24/16 etc. */
		{
			if (i % k == 0) //if i can be divided by any number except 1 and itself, then 
			{
				bob = false; //our number is not prime
			}
			k++;
		}
		if (bob) //if bool is true and i is prime number, then output i
		{
			cout << i << " ";
		}
	}
	return 0;
}