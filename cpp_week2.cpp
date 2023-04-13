//Problem 201.
#include <iostream>
using namespace std;
int main()
{
  int a;
  cin >> a; //input
  cout << a; //output
  return 0;
}

//Problem 202.
#include <iostream>
using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}

//Problem 203.
#include <iostream>
using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;
  cout << a * b;
  return 0;
}

//Problem 204.
#include <iostream>
using namespace std;
int main()
{
  int x,y,z;
  cin >> x>>y>>z;
  cout << x * x + y - z / 2;
  return 0;
}

//Problem 205.
#include <iostream>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  if (a%b==0)    //checking if our condition is true and first number is multiple to second
  {
    cout << "yes";  //if a can be divided by b without any residue
  }
  else
  {
    cout << "no"; //if a/b has some residue
  }
  return 0;
}

//Problem 206.
#include <iostream>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  if (a<b)
  {
    cout << "<";
  }
  else if (a>b) //nested if, because we have 3 different logical options: <,> or =

  {
    cout << ">";
  }
  else
  {
    cout << "=";
  }
  return 0;
}

//Problem 207.
#include <iostream>
using namespace std;
int main()
{
  float a, b, c; //for not only whole, but also floating numbers
  cin >> a >> b;
  c = (a + b) / 2;
  cout << c;
  return 0;
}

//Problem 208.
#include <iostream>
using namespace std;
int main()
{
  int a, b,c;
  cin >> a >> b;
  c = a % b;
  cout << c;
  return 0;
}

//Problem 209.
#include <iostream>
using namespace std;
int main()
{
  int k, c;
  float y;
  cin >> k >> c; 
  y = k * 0.1 + c;     //in first case x is equal to 0.1
  cout << "x=0.1: y=" << y<<endl;
  y = k * 1 + c;       //in second case x is equal to 1
  cout << "x=1: y=" << y<<endl;
  y = k * 5 + c;       //in third case x is equal to 5
  cout << "x=5: y=" << y<<endl;
  return 0;
}

//Problem 210.
#include <iostream>
using namespace std;
int main()
{
  float x, y;
  cin >> x >> y;
  cout <<((x - 2*y) * x) / (-2 * y);
  return 0;
}