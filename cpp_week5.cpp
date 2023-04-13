
//501.
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[100][100];
	int n, m,min=1000;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] < min) 
			{
				min = arr[i][j];
			/*every number will become minimum if it is smaller than previous, and in the end 
			we have our minimum*/
			}
		}
	}
	cout << min << endl;
	return 0;
}

//502.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int arr[100][100];
	int n;
	cin >> n;
	int sum1=0,sum2=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j]; //input values of table
		}
		
	}
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (i == j)  //first diagonals elements are: (0,0) (1,1) (1,1)
			{
				sum1 += arr[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i+j == n-1)  //second diagonals elemets are (0,2)(1,1)(2,0) and n=3
			{
				sum2 += arr[i][j];
			}
		}
	}
	cout <<sum1<<" "<< sum2;

	return 0;
}

//503.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int bob[100][100];
	int n, m, row=0, col=0;
	cin >> n >> m;
	for (int s = 0; s < n; s++)
	{
		for (int t = 0; t < m; t++)
		{
			cin >> bob[s][t];
			if (bob[s][t] == 0)
			{
				row = s+1; //increment s and t to 1, because initialization starts from 0.
				col = t+1;
			}
		}
	}
	cout << row << " " << col << endl;
	return 0;
}

//504.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int bob[100][100];
	int n, m, row=0, col=0;
	cin >> n >> m;
	for (int s = 0; s < n; s++)
	{
		for (int t = 0; t < m; t++)
		{
			cin >> bob[s][t];
		}
	}

	for (int s = 0; s < n; s++)
	{
		for (int t = 0; t < m; t++)
		{
			if (bob[s][t] == -1) //output row and column of out -1
			{
				row = s + 1;
				col = t + 1;
				break;
			}
			if (row == 0 && col == 0) 
/*if row and column are equal to 0, that means we had no -1 element,
 because at the begining i initial. them as 0 and 0*/
			{
				row = -1;
				col = -1;
			}
		}
	}
	cout << row << " " << col << endl;
	return 0;
}

//505.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int boba[100][100], biba[100][100], marta[100][100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> boba[i][j];  //input first array
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> biba[i][j];  //input second array
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			marta[i][j]=boba[i][j]+biba[i][j]; //create third array
			cout << marta[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}

//506.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int mat[100][100];
	int n;
	cin >> n;
	bool sim; //create boolean var
	sim = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j]; //input our matrix
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] != mat[j][i]) //if matrix is not simmetric, bool is true
			{
				sim = true;
				break; 
			}
			else
			{
				sim = false; //if it is simmetric, bool is false
			}
		}
	}
	if (sim)
	{
		cout << "NO" << endl; //if it is not simmetric
	}
	else
	{
		cout << "YES" << endl; //if it is simmetric
	}
	
	return 0;
}

//507.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int mat[100][100];
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
/*if we write places of our elements under the diagonal we can see that they are like 
(1,0)(2,0)(2,1)(3,0)(3,1)(3,2) and so on. maximum j = i-1*/
		{
			sum += mat[i][j];
		}
	}
	cout << sum << endl;
	
	return 0;
}

//508.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int mat[100][100];
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j <n; j++)
/*if we write places of our elements above the diagonal we can see that they are like 
(0,1)(0,2)(0,3)(1,2)(1,3)(2,3) and so on. maximum j = i+1*/
		{
			sum += mat[i][j];
		}
	}
	cout << sum << endl;
	
	return 0;
}



//509.
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int bob[1000][100];
	int index, max = -2147483647, sum = 0; //max can be negative so we put range of integer var
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> bob[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		sum = 0; 
//we count sum of every colon apart from each other, every time we count new colomn
		for (int j = 0; j < n; j++)
		{
			sum += bob[j][i];
		}
		if (sum > max)
		{
			max = sum;
			index = i + 1;
		}
	}
	cout << index;
	return 0;
}

//510.
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int bob[100][100];
    int n, m, pos = 0;
    cin >> n >> m;
    int b[10000]{ 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> bob[i][j];  //input the matrix
            if (bob[i][j] > 0) //if element is positive, put it in b array
            {
                b[pos] = bob[i][j];
                pos++;  //count number of positive elements
            }
        }
    }
    cout << pos << endl;
    for (int i = 0; i < pos; i++)
    {
        for (int j = 0; j < pos-i-1; j++)  //use bubble sorting to organize the order of elements
        {
            if (b[j] > b[j + 1])
            {
                int need = b[j];
                b[j] = b[j + 1];
                b[j + 1] = need;
            }
        }
    }
    for (int i = 0; i < pos; i++)
    {
        cout << b[i] << " ";
    }
	return 0;
}

//511.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int bob[100][100];
	int val = pow(n, 2); //our matrix is n*n
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bob[i][j] = val;
			val -= n;  //first line is for example: 16 12 8
			cout << bob[i][j] << " ";
		}
		cout << endl;
		val = pow(n, 2) - (i + 1); //second line starts with 16-(0+1)=15 and loop works again
	}
	return 0;
}

//512.
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int need = m-1; //m-1 because element initialization starts from 0
	int bob[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> bob[i][j];
		}
	}
	for (int j = 0; need>=0; j++) //need is our row(line) number
	{
		for (int i = 0; i < n; i++) //n is colon number
		{
			cout << bob[i][need] << " "; 
/*when we rotate the matrix our elements in new matrix changes the order 
of their row number but colon number is the same in each new line*/
		}
		cout << endl;
		need--; 
	}
	return 0;
}

//513.
#include <iostream>
#include <cstring> //include new library to use strcpm
using namespace std;
int main()
{
	int i;
	char name[100];
	char numbers[100][100] = 
	{"Tom", "555-3322",

	"Mary", "555-8976",

	"Jon", "555-1037",

	"Rachel", "555-1400",

	"Sherry", "555-8873"};

	cin >> name; //input our name
	for ( i = 0; i < 9; i += 2)
	{
		if (strcmp(name, numbers[i]) == 0) 
//strcmp compare two strings, and if they are equal it means difference is 0
		{
			cout << numbers[i + 1];
			break;
		}
	}
	if (i == 10)
	{
		cout << "Not found";
	}
	return 0;
}


//514.
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long int bob[30][30];
	for (int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++)
		{
			if (j == 0) 
/*every of our new lines begins with 1, so no matter what line is it, first element is 1*/
			{
				bob[i][j] = 1;
			}
			else if (j == i)
/*every of our lines ends with 1, because first line contains only one value (1), 
number of line is equal to last element which is 1*/
			{
				bob[i][j] = 1;
			}
			else
/*other elements are calculated by Pascals triangle principle*/
			{
				bob[i][j] = bob[i - 1][j - 1] + bob[i - 1][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= i)
/*lines number is equal to number of elements in the last line*/
			{
				cout << bob[i][j]<<" ";
			}
		}
		cout << endl;
	}
	
	return 0;
}

//515.
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main() 
{
  int n, k, number;
    cin >> n>>k;
    bool bob[500];
    number = n;
    for (int i = 0; i < n; i++)
        {
          bob[i] = false; /*giving false value to every element (every person)*/
        }
    int i=-1;
    int j=0;
    while (number!= 1)/*loop works untill 1 person left*/
    {
       while (j < k) /*every person except the one with number of k will stay alive*/
        {
            ++i;
            if (i == n) /*if*/
            {i = 0;}
            if (bob[i]==0) /*alive people stay false*/
            {++j;}
        }
        bob[i] = true; /* every k person haves true value now*/
        j = 0;/*start counting people's order again*/
        --number;
    }
   for (int i = 0; i < n; ++i)
        if (bob[i]==0) /*output our alive person which had false value*/
        {
          cout  << i+1 <<endl; /*since elements counting starts from*/
        }
    return 0;
}

//516.
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[1000][100];
    int value;
    for (int i = 0; i < n; i++)
    {
        value = i * m;  
/*every our line starts with the number which is equal to i*m, first line from 0, second line from 1*m an so on*/
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i % 2 == 0)
/*elements of first line and lines with even number in order are increasing, others decreasing*/
            {
                a[i][j] = value;
                value++;
            }
            else
            {
                a[i][j] = value+m-1;
/*m-1 because after even numbered lines we can see that value++ increased to one, 
but in new line we do not need this increase*/
                value--;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


//517.
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main() {
    int bob[10][10];
    int length = 0;
    int max1 = 0, max2 = 0;
    int number = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++){
            cin >> bob[i][j];
        }
    }
/*input my matrix and start analysing each row horizontally from first*/
    for (int i = 0; i < 10; i++){
        length = 0;
/*every time my element is zero i count them and increase my the length*/
        for (int j = 0; j < 10; j++){
            if(bob[i][j] == 0){
                length += 1;
            }
/*every time my element is one i save the length as a max and start couting again*/
            if(bob[i][j] == 1){
                if(length > max1) 
                    max1 = length;
                length = 0;
            }
        }
/*find the max length out of all rows*/
        if (length > max1)
            max1 = length;
    }
    if (length > max1)
        max1 = length;
/*doing exactly the same with colomns vertically*/
    length = 0;
    for (int i = 0; i < 10; i++){
        length = 0;
        for (int j = 0; j < 10; j++){
            if(bob[j][i] == 0){
                length += 1;
            }
            if(bob[j][i] == 1){
                if(length > max2) 
                    max2 = length;
                length = 0;
            }
        }
        if (length > max2)
            max2 = length;
    }
    if (length > max2)
        max2 = length;
/*compare maximums of rows and columns and output final maximum*/
    if (max1 >= max2)
        cout << max1;
    else
        cout << max2;
    return 0;
}

//519.
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int bob[50][50];
	int zero = 0,one = 1, need; 
	int last_col = n - 1;
	int last_row = n - 1;
	int a = 0, b = 0;
	while (a <= last_row && b <= last_col)
/*i will print my matrix by each layer, so i use while loop.
it will print me each layer untill it reaches the middle element. by layers i mean every "square" from the outter to the inner*/
	{
		for (int i = b; i <= last_col; i++) /*print first line, which consist of the same elements, in our case it is "1"*/
		{
			bob[a][i] = one;
		}
		a++; /*next time we go to the next "inner" layer, so index of row increases to 1*/
		for (int i = a; i <= last_row; i++) /*a increased to one, so we start from second row and print last colomn*/
		{
			bob[i][last_col] = one;
		}
		last_col--;
		if (a <= last_row)/*we go left from the last colomn to the first colomn*/
		{
			for (int i = last_col; i >= b; i--)
			{
				bob[last_row][i] = one;
			}
			last_row--;
		}
		if (b <= last_col) /*go up from the last row*/
		{
			for (int i = last_row; i >= a; i--)
			{
				bob[i][b] = one;
				if (i== b + 1)/*we do not put "1" in complete colomn, because in second row our "0" starts*/
				{
					bob[i][b] = zero;
				}
			}
			b++;
		}
		need = one;/*we swappinf ones and zeros and do the same for inner layer with 0s, and then vice versa*/
		one = zero;
		zero = need;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << bob[i][j];
		}
		cout << endl;
	}
	return 0;
}