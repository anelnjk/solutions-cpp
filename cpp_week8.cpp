
//601.
#include <iostream>
#include<cmath>
#include<algorithm> //include new library to use min, max functions
using namespace std;

int min (int a, int b, int c, int d)
{
  int minimal=min(a,min(b,min(c,d)));          //find the minimum value out of all integers
return minimal;                               //return minimum value to the main function

/*or:
  int min;
  if(a>b){min=b;}
  else{min=a;}
  if(min>c){min=c;}
  if(min>d){min=d;}
  return min;
*/

}

int main() 
{
  int a,b,c,d;
    cin>>a>>b>>c>>d; //input variables
    cout<<min(a,b,c,d)<<endl; //calling the min function and output it
  return 0;
}

//602.
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double power (double a, int n)
{
  return pow(a,n); //find and return the value of a^n

/*or:
	int power=1;
	for(int i=1;i<=n;i++){
	power*=a;}
	return power;
*/

}


int main() 
{
  double a;
  int n;
    cin>>a>>n;
    cout<< power(a,n)<<endl;    //callinf the function
  return 0;
}

//603.
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

bool myXor (bool x, bool y)
{
  if(x==0&&y==1)
  {
    return 1;
  }
  else if(x==1&&y==0) //if only one of variables is true, output true
  {
    return 1;
  }
  else //in other cases output false
  {
    return 0;
  }
}
int main() 
{
  int x, y;
    cin>>x>>y;
    cout<<myXor(x,y)<<endl; 
  return 0;
}

//604.
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

bool election(bool x, bool y,bool z) 
{
  if(x==y||y==z) //if either x or z is equal to y, then two of them are the same, so output y
  {
    return y;
  }
  else //in other case x, because one of them is different does not matter x or z or y
  {
    return x;
  }
}
int main() 
{
  int x, y, z;
  cin >> x >> y >> z;
  cout << election(x, y, z) << endl;
  
  return 0;
}

//605.
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

char getSign(int a,int b)
{
  if(a<b) //compare two integers
  {
    cout << "<" <<endl;
  }else if(a>b)
  {
    cout << ">" << endl;
  }else 
  {
    cout << "=" << endl;
  }
  return 1;
}

int main() 
{
  int a, b;
  cin >> a >> b;
  cout << getSign(a, b) << endl;
  return 0;
}


//606.
#include <iostream>
using namespace std;

void sum (int bob1[], int bob2[], int n)
{
  int sum1=0, sum2=0;
  for(int i=0;i<n;i++){
    if(bob1[i]>0){
      sum1++;
    }
    if(bob2[i]>0){
      sum2++;
    }
  }
/*counted number of positive elements*/
   if(sum1>sum2){
     cout<<"Number of positives in the first array is greater";
    }
    else if(sum1<sum2){
      cout<<"Number of positives in the second array is greater";
    }
    else{
      cout<<"Numbers are equal";
    }
}
int main() 
{
 int bob1[100], bob2[100];
 int n;
 cin>>n;
 for(int i=0;i<n;i++){
   cin>>bob1[i];
 }
 for(int j=0;j<n;j++){
   cin>>bob2[j];
 }
  sum(bob1,bob2,n);
  return 0;
}


//607.
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int sumPos (int bob1[100], int m) //fuction counts the positive elements in the row 
{ int sum=0;
  for(int k=0;k<m;k++){
    if(bob1[k]>0){
      sum++;}
    }
  return sum;
}
int main()
{
  int n,m,max=0,max1;;
  cin>>n>>m;
  int bob[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>bob[i][j]; //input our array
    }
  }
  int need, index, need2,need3=0;
  need=sumPos(bob[0],m); //counting the positive elements in first row

  for(int i=1;i<n;i++){
    need2=sumPos(bob[i],m); //if positive elements in every row are equal, we save that and then will output that"numbers are equal" 
    if(need==need2)
    {need3++;}
  }
  for(int i=0;i<n;i++){
    need=sumPos(bob[i], m);
    if(need>max) //if numbers of positive elements are different then save the index of max numbered row
    {index=i+1;
    max=need;}
  }
  if(need3==n-1)
  {cout<<"Numbers are equal"<<"\n";} //only if all rows are equal output the phrase
  else
  {cout<<index;} //or output the index
  return 0;
}

//608.
#include <iostream>
#include<cmath>
using namespace std;

void morePos(int arr[100][100], int nRow, int nCol){
  int max=0, index, real=0;
  for(int i=0;i<nRow;i++)
  {
    int series=0;
    for(int j=1;j<nCol;j++)
    {
      if(arr[i][j-1]==arr[i][j]) //every time neighbour elements are the same, count 
      {
        series++;
      }
    }
    if(series>max) //if it is more than max, series becomes max
    {
      max=series; 
      index=i; //show the index of the row
      real=index; //save the value of maximum row
    }
  }
  if(real==index) //if there is no maximum after a particular row, output this row
  {
    cout<<"Longest series is in the string "<<index<<"\n";
  }
  else //else there are no series of equal elements
  {
    cout<<"No series of equal elements"<<"\n";
  }
}

int main() 
{
  int bob[100][100];
  int n, m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>bob[i][j]; //input array
    }
  }
  morePos(bob,n,m); //calling the function
  return 0;
}

//609.
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=20; //each string not more than 20 chars
int countAccurance(char arr[maxn], char ch)
{
  int res=0;
  int len=strlen(arr); //the length is the number of intered chars
  for(int i=0;i<len;i++)
  {
    if(arr[i]==ch) //if char is equal to the letter
    {
      res++; //counting
    }
  }
  return res;
}

int main() 
{
  char ch1, ch2;
  char str1[maxn], str2[maxn];
  cin>>ch1>>ch2;
  cin>>str1;
  cin>>str2;
  cout<<countAccurance(str1,ch1)<<" "<<ch1<<" "<<"characters in "<<str1<<"\n";
  cout<<countAccurance(str2,ch2)<<" "<<ch2<<" "<<"characters in "<<str2<<"\n";
  return 0;
}

//610.
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=20;
int countAccurance(char arr[maxn], char ch)
{
  int res=0;
  int len=strlen(arr);
  for(int i=0;i<len;i++)
  {
    if(arr[i]==ch)
    {
      res++;
    }
  }
  return res;
}

int main() 
{
  int n;
  cin>>n;
  char ch[n];
  char str[n][maxn];
  for(int i=0;i<n;i++)
  {
    cin>>ch[i]>>str[i];
  }
  for(int i=0;i<n;i++) //calling the function for each letter and string 
  {
    cout<<countAccurance(str[i], ch[i])<<" "<<ch[i]<<" in "<<str[i]<<"\n";
  }
  
  return 0;
}

//611.
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=20;
int countAccurance(char arr[maxn], char ch)
{
  int res=0;
  int len=strlen(arr);
  for(int i=0;i<len;i++)
  {
    if(arr[i]==ch)
    {
      res++;
    }
  }
  return res;
}

int main() 
{
  int n;
  cin>>n;
  char ch[n];
  char str[n][maxn];
  for(int i=0;i<n;i++)
  {
    cin>>ch[i]>>str[i];
  }
  for(int i=n-1;i>=0;i--) //calling the function for each letter and string and output them in inverse order
  {
    cout<<countAccurance(str[i], ch[i])<<" "<<ch[i]<<" in "<<str[i]<<"\n";
  }
  
  return 0;
}

//612.
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void oppositeCase(char arr[], int n) //void function because we dont return any valus
{
  for (int i=0; i<n; i++) 
    { 
      if (arr[i]>='a' && arr[i]<='z')
	{arr[i] = arr[i] - 32;}
 
/*in English alphabet we have 32 letters.
By ASCII table upper case letters go first, then lower case letters go, 
so we subtract 32 char to have the same letter of opposite case */
 
    }
    cout<<arr;
}
int main() 
{ 
  char bob[100];
  cin>>bob;
  oppositeCase(bob,sizeof(bob)); //call for function

return 0;
}

//613.
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void oppositeCase(char arr[], int n)
{
  for (int i=0; i<n; i++) 
    { 
      if (arr[i]>='a' && arr[i]<='z') 
        {arr[i] = arr[i] - 32;} 
        else if (arr[i]>='A' && arr[i]<='Z') 
        {arr[i] = arr[i] + 32;}

/*in English alphabet we have 32 letters.
By ASCII table upper case letters go first, then lower case letters go, 
so we subtract or add 32 char to have the same letter of opposite case */

    }
    cout<<arr;
}
int main() 
{ 
  char bob[100];
  cin>>bob;
  oppositeCase(bob,sizeof(bob));

return 0;
}

//614.
#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;

void oppositeCase(char arr[], int n)
{
  for (int i=0; i<n; i++) 
    { 
      if (arr[i]>='a' && arr[i]<='z') //turn lower case into upper
        {arr[i] = arr[i] - 32;} 
        else if (arr[i]>='A' && arr[i]<='Z') //turn upper case into lower
        {arr[i] = arr[i] + 32;}
        else 
        {
          arr[i]=' '; //turn signs into blank space
        }
    }
  char arr2[n];
  int l=0;
    for(int i=0;i<n;i++)
    {
      if(arr[i]!=' ') //add all of non blank space elements into another array
      {
        arr2[l]=arr[i];
        cout<<arr2[l]; //output letters
        l++;
      }
    }
}
int main() 
{ 
  char bob[100];
  cin>>bob;
  oppositeCase(bob,strlen(bob)); //calling the function
return 0;
}

//615.
#include <iostream>
#include<cmath>
using namespace std;

int turntoSec(int a, int b, int c)
//function that turns time into seconds
{
  int sec=(a*3600)+(b*60)+c;
  return sec;
}

int main() 
{ 
  int hh1, mm1, ss1;
  cin>>hh1>>mm1>>ss1;
  int hh2, mm2, ss2;
  cin>>hh2>>mm2>>ss2;
  int dif;
  dif=turntoSec(hh2,mm2,ss2)-turntoSec(hh1,mm1,ss1);
//subtract first time from second
  
  int hh3=dif/3600;
  int mm3=(dif/60)-(60*hh3);
  int ss3=dif-(hh3*3600)-(mm3*60);
  
  if(hh3<10){cout<<"0"<<hh3<<":";}
  else{cout<<hh3<<":";}
  if(mm3<10){cout<<"0"<<mm3<<":";}
  else{cout<<mm3<<":";}
  if(ss3<10){cout<<"0"<<ss3;}
  else{cout<<ss3;}
  
return 0;
}


//616.
#include<iostream>
using namespace std;

int binarytoDec(char bob1[], int a)
{
int dec = 0;
  int power = 1;
  for (int i = a - 1; i >= 0; i--) {
    dec += (bob1[i] - '0') * power;
/*use ASCII code, because 0-0=0 and 1-0=1 so we can convert binary to decimal by
multiplying every element(1 or 0) to a certain power of 2. */
    power *= 2;
/*power of 2 increases by multiplying 2 to 2 and so on*/
  }
  return dec;
}


int main() 
{
  int n;
  cin >> n;
  char bob[32];
  for (int i = 0; i < n; i++) {
    cin >> bob[i];
  }
  cout<<binarytoDec(bob,n); //calling the function
  return 0;
}

//617.
#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

void neighbours(int bob1[], int n)
{
  int need1,need2;
  int min=1000;
    for(int i=2;i<=n+1;i++)
    {
      if(abs(bob1[i]-bob1[i-1])<min) //if absolute value (positive) of difference of 2 neighbours is min
      {
        min=abs(bob1[i]-bob1[i-1]);  //min become abs.value
        need1=i;
        need2=i-1;
        if(need1>n) //when we finiched counting circle starts again (from the "1" numbered soldier)
        { need1=1; }
      }
    }
  cout<<need2<<" "<<need1<<"\n"; //output numbers of neighbours
}
int main()
{
  int n;
  cin>>n;
  int bob[n];
  for(int i=1;i<=n;i++)
  { cin>>bob[i]; } //input hights or soldiers
  bob[n+1]=bob[1];  //making a circle
  neighbours(bob, n); //calling the fuction
  return 0;
}