//1101.
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string bob, findd;
    getline(cin,bob);
    getline(cin,findd);
    
    int k=bob.find(findd);
    cout<<k;
    return 0;
}

//1102.
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string bob, findd;
    getline(cin,bob);
    getline(cin,findd);
    
    for(int i=0;i<bob.length();i++)
    {
        bob[i]=toupper(bob[i]);
    }
    for(int i=0;i<findd.length();i++)
    {
        findd[i]=toupper(findd[i]);
    }
    int k=bob.find(findd);
    cout<<k;
    return 0;
}
//1103.
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string bob, findd;
    getline(cin,bob);
    getline(cin,findd);
    
    int k=bob.rfind(findd);
    cout<<k;
    return 0;
}
//1104.
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string bob, s;
    getline(cin, bob);
    getline(cin, s);
    int k=bob.find_first_of(s);
    
    while(k!=-1)
    {
        bob[k++]='*';
        k=bob.find_first_of(s, k);
    }
    cout<<bob;
    return 0;
}
//1105.
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string bob;
    getline(cin, bob);
    
    int start=bob.find_first_not_of(32);
    int end=bob.find_last_not_of(32);
    
    bob.erase(0,start);
    bob.erase(end-1);
    
    string bob2=bob;
    
    for( int i=0;i<bob2.length()-1;i++)
    {
        if(bob2[i]==32)
        {
            int j=i+1;
            while(bob2[j]==32)
            {
                bob2.erase(j,1);
            }
        }
    }
    cout<<bob2;
    return 0;
}
//1106.
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string bob;
    getline(cin, bob);
    string bob2=bob;
    int k=bob.length()-1;
    for(int i=0;i<bob.length();i++)
    {
        bob[i]=bob2[k];
        k--;
    }
    cout<<bob;
    return 0;
}
//1107.
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string date;
  getline(cin, date);
  int sum=0, newint=0;
  if(date=="1")
  {
    cout<<1<<" "<<1;
    return 0;
  }

  for(int i=0;i<date.length();i++)
  {
    sum+=date[i]-'0';
  }
  if(sum<10)
  {
    cout<<sum<<" "<<1;
  }
  else
  {
    do{
      sum=0;
      stringstream a(date);
      int n=0;
      a>>n;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    n=sum;
    newint++;
    }while(sum>9);
  cout<<sum<<" "<<newint;
  }
  return 0;
}
//1008.
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string bob;
  getline(cin,bob);
  int k=bob.find_first_of("yaoieyuYAOIEYU");
    
    while(k!=-1)
    {
        bob.erase(k,1);
        k=bob.find_first_of("yaoieyuYAOIEYU", k);
    }
  
  for(int i=0;i<bob.size();i++)
  {
    if(bob[i]>='A'&&bob[i]<='Z')
    {
      bob[i]=bob[i]+32;
    }
    cout<<'.'<<bob[i];
  }
  return 0;
}
//1110.
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string bob,bib;
  getline(cin,bob);
  getline(cin,bib);
  if(bob.size()!=bib.size())
  {
    cout<<"NO";
    return 0;
  }
  sort(bob.begin(),bob.end());
  sort(bib.begin(),bib.end());
  if(bob!=bib)
  {
    cout<<"NO";
  }else
  {
    cout<<"YES";
  }
  return 0;
}