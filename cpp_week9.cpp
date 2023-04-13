
//901.
#include <bits/stdc++.h> //all libraries of c++
using namespace std;

void subString(char *arr, int n) //recieve the address of array and its size
{
  int aitu;
  for(int i=0;i<n-3;i++) //check every char of string
  {
    if((*(arr+i)=='A'||*(arr+i)=='a')&&(arr[i+1]=='I'||arr[i+1]=='i')&&(arr[i+2]=='T'||arr[i+2]=='t')&&(arr[i+3]=='U'||arr[i+3]=='u'))
    {
      aitu=1; //if there is a substring "aitu" break the checking loop
      break;
    }
    else{aitu=0;}
  }
  if(aitu==1){cout<<"YES";} //yes, if it is true
  else{cout<<"NO";} //"no" otherwise
}

int main() 
{
  char *pbob; //create a pointer
  char bob[1000]; //create an array
  pbob=bob; //pbob has the address of bob's first elements
  cin>>bob;
  subString(pbob, strlen(bob)); //passing by reference and the value
  return 0;
}

//902.
#include <bits/stdc++.h> //includes all libraries of c++
using namespace std;

void replace(char *source,char *dest); //signature of function

int main() 
{
  string a; 
  getline(cin,a); //enter string
  char bob[a.size()]; //create char array with size of our string
  strcpy(bob,a.c_str()); //copy string a into our char array bob
  replace(bob,bob); //calling the finction, pass by reference
  return 0;
}

void replace(char *source,char *dest)
{
  int n=strlen(source); //size of array
  for(int i=0;i<n;i++)
  {
    if(*(dest+i)=='!') //if "!" is in the string, replace it with "."
    {
      *(dest+i)='.';
    }
  }
  cout<<dest;
}
////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
void replace(char *arr, char *arr1){
  for (size_t n = 0; n<strlen(arr); ++n){
    if (arr[n] == '!'){ 
      arr1[n] = '.';
      continue;
    }
    arr1[n] = arr[n];
  }
}
int main() {
  std::string str;
  char arr[1000];
  char arr1[1000];
  std::getline(std::cin, str);
  strcpy(arr, str.c_str());
  replace(arr,arr1);
  std::cout << arr1;
}

//903.
#include <bits/stdc++.h> //includes all libraries
using namespace std;

void space(char* bob) //recieve address of first element of array
{
  int i, j;
  for(i=strlen(bob)-1,j=0; j<strlen(bob),i>=0; j++,i--) 
/*at the same time:
i=6(index of the last elements of array) and j=0(index of the first element of array)
j<7, so untill j is less than lenght of array, j++ output elements of array
i>=0, so untill i is not the first element of array, i-- it just decreases */
  {
    cout<<*(bob+j);
/*when it is the third element from the end, output blank space*/
    if(i%3==0)
    {cout<<" ";}
  }
}
int main()
{
  char bob[101]; //max size of array is 100 symbols and the last one is null
  cin>>bob;
  space(&bob[0]);
  return 0;
}
//////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
void outputFormatted(char *arr){
  int l;
  for (size_t i = 0; i<strlen(arr)/3+1; ++i){
    if (i == 0){
      for (l = 0; l<strlen(arr)%3; ++l) std::cout << arr[l];
      std::cout << " ";
      continue;
    }
    for (size_t j = 0; j<3; ++j){
      std::cout << arr[l];
      l++;
    }
    if (i != strlen(arr)/3) std::cout << " ";
  }
}
int main() {
  char arr[1000];
  std::cin >> arr;
  outputFormatted(arr);
}
//904.
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int max=1000;
  char bob[max];
  char*bob2;
  char *bob3[1000];
  int m=0;
  cin.getline(bob,max);
  bob2=strtok(bob, " ,.-!?:");
  while(bob2!=NULL)
  {
    bob3[m]=bob2;
    m++;
    bob2=strtok(NULL, " ,.-!?;");
  }
  bob2=bob3[m-1];
  for(int i=0;i<strlen(bob2);i++)
  {
    if(bob2[i]>='a'&&bob2[i]<='z')
    {
      bob2[i]=bob2[i]-32;
    }
  }
  cout<<bob2;
  return 0;
}
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
void upperCase(char *arr){
  for (size_t i = 0; i<strlen(arr); ++i){
    if (arr[i] >= 97 && arr[i] <= 122){
      arr[i] -= 32;
    }
  }
}
std::string mostRecent(char *arr){
  int wordCount = 0, max = 0, cnt = 0, repeat = 0;
  std::string word, maxWord, check;
  for (size_t i = 0; i<strlen(arr); ++i){
    if (arr[i] == ' ') wordCount++;
  }
  for (size_t i = 0; i<wordCount; ++i){
    while(true){
      if (arr[cnt] == ' ')
      break;
      word += arr[cnt];
      cnt++;
    }
    for (size_t j = 0; j<strlen(arr); ++j){
      if (arr[j] == ' '){
        if (word == check) repeat++;
        check = "";
      }
      check += arr[j];
    }
    if (repeat > max){
      max = repeat;
      maxWord = word;
    }
    word = "";
    repeat = 0;
  }
  return maxWord;
}
int main() {
  std::string str;
  char arr[1000];
  std::getline(std::cin, str);
  strcpy(arr, str.c_str());
  upperCase(arr);
  std::cout << mostRecent(arr);
}

//905.
#include <bits/stdc++.h> //includes all libraries of c++
using namespace std;

int need=1; //global var
void same(string *a,string b); //function signature

int main()
{
  string bob[1000]; //enter string
  string bob2; 
  cin>>bob[0]; //enter the first word
  while(cin>>bob2) //enter second word
  {same(bob,bob2);}  //calling for the function every time we enter next word

  for(int i=0;i<need;i++)
  {
    cout<<bob[i]<<" ";  //show string without deleted words
  }
  return 0;
}

void same(string *a,string b) //recieve address of first word; second word
{
  for(int i=0;i<need;i++) 
  {
    if(a[i]==b) //if they are equal, break, which means dont show second word(because it is a copy)
      break; 
    }
    else{  //if they are different
      if(i==need-1) 
      {
        a[need++]=b; 
/*this one is equal to: a[need]=b; need++;
so in case they are different words we just say that next word will be second word we entered,
so that we do not change anything, because there is no copy. and our global var need increments, as a result
we will enter 3rd word and compare with the second, and so on*/
      }
    }
  }
}

//906.
#include <bits/stdc++.h>
using namespace std;

void space(char* bob) //function that adds space that i used in problem #903
{
  int i, j;
  for(i=strlen(bob)-1,j=0; j<strlen(bob), i>=0; j++,i--)
  {
    cout<<*(bob+j);
    if(i%3==0)
    {cout<<" ";}
  }
}

int main()
{
  char whole[1000]; 
  cin.getline(whole, 1000); //enter the whole sentence (string)
  char *a;
  a= whole;

char maxnum[1000]= " ";
char need[1000];
int l=0;

  while (*a!= 0) //check every symbol(word)
{
    if ((*a>='0')&&(*a<='9')) //if it is an integer
      {
        need[l]= *a; //save that symbol into array
        l++;
      }
    else
    {
      if (l>strlen(maxnum)) //if letters started we save sequence of numbers into array as max number
        {
          need[l]= 0; 
          strcpy(maxnum, need); //copy number into maxnum array
        }
      l= 0;
    }
  a++; //a++ so that we start counting again from next word
}

if (l>0) //if we found sequence with number symbols
{
    if (l>strlen(maxnum))
      {
        need[l]= 0;
        strcpy(maxnum, need); //save this sequence as maximum number 
        l= 0; //l=0 so that we can check other words starting from need[0] and so on
      }
}

space(maxnum); //add spaces into the number
return 0;
}


//907.
#include <bits/stdc++.h>
using namespace std;

char enter[1000],answer[1000]; //create global variables so that we can use them in every fuction
int n=0,m=0,i,j;

void change(char *add)  //function that finds the final result(answer) 
{
  i=0;
  while(*add)
  {
    answer[i]=*add; //answer[] recieve char-s of string which is the max value out of 3 numbers 
    i++; //every element od answer[] becomes the same as add[] arrays
    add++; //increment add to go to next element of add[]
  }
  m=n; //set our max number(m) of char as number of char in answer[] array(n)
}

void check() //function checks if number of char is bigger than previous number's
{
  if(n>m) //if it is bigger(like 1-number was 6666(4) and second 787898(6), second is bigger)
  {
    change(enter); //send address of entered char array to "change" function to set it as final answer
  }
  if(n==m) //if we entered 6666(4) and 7777(4) 
  {
    for(i=0;i<n;i++) //check elements of arrays
    {
      if(enter[i]>answer[i]) 
/*if value of first elements is bigger in any array (6<7), we send the address of array with elements with bigger value*/
      {
        change(enter);
        break; //when we find bigger element we just break the loop
      }
      if(enter[i]<answer[i])
      {
        break;
      }
    }
  }
}

int main()
{
  for(int k=1;k<=3;k++) //3 numbers should be entered
  {
    cin>>enter;
    n=strlen(enter); //count how many elements does this array(number) have
    check(); //calling for the function that checks which number is bigger
//we have global variables, so there is no need to send anything in this function
  }
  cout<<answer; //output the answer
  return 0;
}
/////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
std::string biggestNumber(std::string s1, std::string s2, std::string s3){
  int maximum = std::max(s1.length(),std::max(s2.length(), s3.length()));
  if (s1.length() > s2.length() && s1.length() > s3.length())
  return s1;
  if (s2.length() > s1.length() && s2.length() > s3.length())
  return s2;
  if (s3.length() > s2.length() && s3.length() > s1.length())
  return s3;
  for (size_t i = 0; i<maximum; ++i){
    char *ss1 = &(s1[i]);
    char *ss2 = &(s2[i]);
    char *ss3 = &(s3[i]);
    if (*ss1 > *ss2 && *ss1 > *ss3)
    return s1;
    if (*ss2 > *ss1 && *ss2 > *ss3)
    return s2;
    if (*ss3 > *ss1 && *ss3 > *ss2)
    return s3;
  }
}
int main() {
  std::string s1,s2,s3;
  std::cin >> s1 >> s2 >> s3;
  std::cout << biggestNumber(s1,s2,s3);
}

//908.
#include <bits/stdc++.h>
using namespace std;

int MAX = 1001;
void AddVeryLongInt(char* ss1, char* ss2, char* ss3)
{
  cin>>ss1>>ss2; //enter 2 long numbers as strings
  string s1 = ss1;
  string s2 = ss2;

  int n1=s1.length(); //find the length(size) of strings
  int n2=s2.length();
 
  string s3; //our final string

  if(n1>n2) //first string should be bigger, because we will add this numbers "v stolbik"
  {
    swap(s1,s2); //in case second number is bigger we change their order
    swap(n1,n2);
  }
  
  reverse(s1.begin(), s1.end()); //reverse function mirrors our string, e.g. 123543->345321
  reverse(s2.begin(), s2.end()); //we need it to add numbers "v stolbik", because adding starts from the end of a number

  int plus=0; 
//this var saves the value of number, that we should add to the next (previous) number
/*e.g. 15+15=30, so we add 5 to 5 it is 10, we write 0 and save plus=1, 
and then 1+1=2 and we add this "plus" so 2+1=3 and we get 03(we will reverse it later)*/

  int sum, sum2;
  for(int i=0;i<n1;i++)
  {
    sum=((s1[i]-'0')+(s2[i]-'0')+plus); 
//add each element of a string ro each other which we turned to integers in advance by subtracting '0'(ASCII)

    s3.push_back(sum%10+'0');
/*push_back function does next: it adds one more element to our s3 string. This element will stay in the last position.
 sum%10 + '0' because we turn integers into symbols again(ASCII)*/

    plus=sum/10;
//if sum of our number was less than 10 (e.g. 5+2=7), there is no need to add +1, because 7/10 is 0. But if numbers were 8 and 2
// 8+2=10 so we write 0 (10%10=0)as the next symbol and save 1, after we will add 1 to next number(sum)

  }

  for(int i=n1;i<n2;i++) //in case entered numbers had different length we continue addind starting from i=length of shorter number 
  {
    sum2=((s2[i]-'0')+plus);
    s3.push_back(sum2%10+'0');
    plus=sum2/10;
  }

  if(plus!=0) //if there left another "plus" we just put it as the last symbol
  {
    s3.push_back(plus+'0');
  }
  reverse(s3.begin(), s3.end()); //reverse our final string 

  for(int i=0;i<s3.length();i++)
  {
    ss3[i]=s3[i]; //save each element of a string to char array and return it to the main func
  }
  return;
}

int main()
{
  char* ss1 = new char[MAX];
  char* ss2 = new char[MAX];
  char* ss3 = new char[MAX+1];
  AddVeryLongInt(ss1,ss2,ss3);
  cout<<ss3;
  delete[]ss1; //clean dynamic memory
  delete[]ss2;
  delete[]ss3;
  return 0;
}
//////////////////////////////////////////////////////////
#include <bits/stdc++.h>
void addVeryLongIntegers(char *arr1,char *arr2,char *arr3){
  int addNext = 0;
  for (int i = strlen(arr1)-1; i>=0 ; --i){
    int sumTwoChars = arr1[i] - '0' + arr2[i] - '0' + addNext;
    addNext = 0;
    if (sumTwoChars >= 10){
      sumTwoChars -= 10;
      addNext++;
      arr3[i] = sumTwoChars + '0';
      continue;
    }
    arr3[i] = sumTwoChars + '0';
  }
  if (addNext == 1){
    std::cout << 1;
  }
  for (size_t i = 0; i<strlen(arr3); ++i){
    if (arr3[i] >= 48 && arr3[i] <= 57)
      std::cout<<arr3[i];
  }
}
int main() {
  std::string s1,s2;
  std::cin >> s1 >> s2;
  int maximumLen = std::max(s1.length(), std::max(s1.length(), s2.length()));
  char arr1[maximumLen];
  char arr2[maximumLen];
  char arr3[maximumLen];
  if (s1.length() > s2.length()){
    strcpy(arr1, s1.c_str());
    for (size_t i = 0; i<maximumLen; ++i){
      if (i == maximumLen - s2.length()){
        for (size_t j = 0; j < maximumLen - i + 1; ++j){
          arr2[i] = s2[j];
          i++; 
        }
      }
      arr2[i] = '0';
    }
  }
  else if (s2.length() > s1.length()){
    strcpy(arr1, s2.c_str());
    for (size_t i = 0; i<maximumLen; ++i){
      if (i == maximumLen - s1.length()){
        for (size_t j = 0; j < maximumLen - i + 1; ++j){
          arr2[i] = s1[j];
          i++; 
        }
      }
      arr2[i] = '0';
    }
  }
  else {
    strcpy(arr1, s1.c_str());
    strcpy(arr2, s2.c_str());
  }
  addVeryLongIntegers(arr1, arr2, arr3);
}

//909.
#include <bits/stdc++.h> //all libraries of c++
using namespace std;

void divORnot(string num, int l) //recieve string and length of this string
{
  long int oddsum=0; //will count the sum of numbers on odd position
  long int evensum=0; //will count the sum of numbers on even position
  for(int i=0;i<l;i++) //check each element of a string
  {
    if(i%2==0)
    {evensum+=num[i]-'0';} //char -> integers
    else
    { oddsum+=num[i]-'0';}
  }

  if(oddsum==evensum) //if sum is equal it means this number is divisible (by the rule)
    {cout<<"YES";}
  else //in case they are not equal, difference of these two sums should be divisible to 11
  {
    if((oddsum-evensum)%11==0)
      {cout<<"YES";}
    else
      {cout<<"NO";}
  }
}
int main() 
{
  string bob;
  cin>>bob;
  int length=bob.length(); //count the length of the string
  void (*divpp)(string, int)=divORnot; //pointer to the function
  (*divpp)(bob,length);
  return 0;
}

//910.
#include <bits/stdc++.h>
using namespace std;

void Arrow(string, int); //function signature

int main() 
{
  string bob; //enter the string
  cin>>bob;
  int length=bob.length(); //count the length of a string
  void (*arrowp)(string, int)=Arrow; //pointer to the function
  arrowp(bob,length);
  
  return 0;
}

void Arrow(string seq, int l)
{
  int howmany=0;
  for(int i=0;i<l-4;i++)
  {
    if((seq[i]=='>'&&seq[i+1]=='>'&&seq[i+2]=='-'&&seq[i+3]=='-'&&seq[i+4]=='>')
||(seq[i]=='<'&&seq[i+1]=='-'&&seq[i+2]=='-'&&seq[i+3]=='<'&&seq[i+4]=='<'))
/*sequence should be either >>--> OR <--<<*/
    {
      howmany++; //count how many arrows do we have
    }
  }
  cout<<howmany<<"\n";
}

//911**
#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int n, m;
    cin>>n>>m;
    char bob[n][m];
    bool switchXdot;
    for(int i=0;i<n;i++)
    {
        if(n%2==0)
        {
            switchXdot=(i%2==0);
        }
        else
        {
            switchXdot=!(i%2==0);
        }
        for(int j=0;j<m;j++)
        {
            if(switchXdot)
            {
                bob[i][j]='X';
                switchXdot=false;
            }
            else
            {
                bob[i][j]='.';
                switchXdot=true;
            }
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<bob[i][j];
        }
        cout<<endl;
    }
    return 0;
}