#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
// #define LECTURE01
// #define LECTURE02
// #define LECTURE03
// #define LECTURE04
// #define LECTURE05
// #define LECTURE06
// #define LECTURE07
//#define LECTURE08
//#define LECTURE09
//#define LECTURE10
//#define LECTURE11
//#define LECTURE13
//#define LECTURE14
//#define LECTURE15
//#define LECTURE16
//#define LECTURE17
//#define LECTURE18
//#define LECTURE19
//#define LECTURE20
//#define LECTURE21
//#define LECTURE22
//#define LECTURE23
//#define LECTURE24
//#define LECTURE25
//#define LECTURE26
//#define LECTURE27
//#define LECTURE28
//#define LECTURE29
//#define LECTURE30
#define LECTURE31


using namespace std;

#ifdef LECTURE01

int main ()
{
	int n, m, i, sum = 0;
	cin >> n >> m;
	
	for (i = 1; i<=n; i++)
	{
		if(!(i%m)) sum+=i;
	}
	
	cout << sum << endl;
}

#endif

#ifdef LECTURE02



int main ()
{
	int n, m, sum = 0;
	cin >> n >> m;
	
	for (int i = n ; i <=m; i++)
	{
		
		sum +=i;
		cout << i;
		if(i == m) break;
		cout<<" + ";
	}
	
	cout << " = " << sum << endl;
}
#endif

#ifdef LECTURE03


int main ()
{
	int n, m, sum = 0;
	cin >> n;
	
	for (int i =1; i<n;i++)
	{
		if(n%i==0) 
		{
			if(i==1) 
			{
				cout << i;
				continue;
			}
			cout << " + ";
			cout << i;
			sum += i;
			
				
		}
		
		
	}
	
	cout << " = " << sum+1 << endl;
	
}

#endif

#ifdef LECTURE04



int main ()
{
	freopen("input.txt","rt",stdin);
	int n, m, sum = 0;
	int arr[101];
	int max = -INT_MAX;
	int min = INT_MAX;
		
	cin >> n;
	for(int i = 0 ; i<n;i++)
	{
		cin >> arr[i];
	}

	for(int i = 0 ; i<n;i++)
	{
		if(max < arr[i]) max = arr[i];
		if(min > arr[i]) min = arr[i];		
	}
	
	cout << max - min << endl;	
}

#endif

#ifdef LECTURE05

int main ()
{
	char num[15];
	cin >> num;
	
	int a, b = 0;
	
	if(num[7] == '1' || num[7] == '2') 
	{
		
		a = num[0] - '0';
		b = num[1] - '0';
		cout <<  119 - 10*a - b + 1;
		
		if(num[7] == '1') cout <<' ' << 'M' ;
		else			  cout <<' ' << 'W' ;
		
	}
	if(num[7] == '3' || num[7] == '4') 
	{
		a = num[0] - '0';
		b = num[1] - '0';
		cout <<  19 - 10*a - b + 1;
		
		if(num[7] == '3') cout <<' ' << 'M' ;
		else 			  cout <<' ' << 'W' ;	
	}

}
#endif

#ifdef LECTURE06

int main ()
{
	char str[51];
	char num[51];
	cin >> str;
	int sum, cnt = 0;
	int flag = 0;
	int ans = 0;
	//cout << str;
	for(int i = 0; i < strlen(str); i++ )
	{
		
		if(str[i] >='1' && str[i] <='9') flag = 1;
		
		if(flag && (str[i] >='0' && str[i] <='9'))
		{
			num[cnt] = str[i] ;
		//	cout << num[cnt];
			cnt++;	
		}
	}
	
	num[cnt]='\0';

	for(int i =0; i<strlen(num); i++)
	{
		cout << num[i];
	}
	
	for(int i = 0; i < strlen(num); i++)
	{
		sum += (int)(num[i]-'0') * pow(10, strlen(num) - i -1);
		//cout<< sum << endl;
	}
	
	for (int i = 1; i <= sum ; i++)
	{
		if (sum % i == 0) ans++;
		
		//cout << i << endl;
	}
 	cout << endl <<ans;
}
#endif


#ifdef LECTURE07

int main ()
{
	char str[101];
	char ans[101];
	
	int cnt = 0;
	gets(str);
	//cout << str; 
	for (int i = 0; i<strlen(str) ; i++)
	{
		if(str[i] == ' ') continue;
		else if(str[i] >='A' && str[i] <='Z') printf("%c",str[i] + ('a' - 'A'));
		else if(str[i] >='a' && str[i] <='z') printf("%c",str[i]);
	}
	

}

#endif

#ifdef LECTURE08

int main ()
{
	char str[31];
	
	
	cin >> str;
	int cnt = 0;
	int flag = 0;
	for (int i = 0; i<strlen(str);i++)
	{
		if(str[i] == '(') cnt++;
		else if(str[i] == ')') cnt--;
		
		
		if(cnt<0) 
		{
			flag = 1;
			break;
		}
		
		
	}
	
	if(flag) cout << "NO" << endl;
	else if(cnt == 0) cout << "YES" << endl;
	else  	      cout << "NO" << endl;
	
	
	

}

#endif

#ifdef LECTURE08

int main ()
{
	char str[31];
	
	
	cin >> str;
	int cnt = 0;
	int flag = 0;
	for (int i = 0; i<strlen(str);i++)
	{
		if(str[i] == '(') cnt++;
		else if(str[i] == ')') cnt--;
		
		
		if(cnt<0) 
		{
			flag = 1;
			break;
		}
		
		
	}
	
	if(flag) cout << "NO" << endl;
	else if(cnt == 0) cout << "YES" << endl;
	else  	      cout << "NO" << endl;
}
#endif

#ifdef LECTURE09

int main ()
{

	int div[50004];
	int input;


	cin >> input;
	for (int i = 1; i <=input; i++)
	{
		for(int j = i; j <= input; j=j+i)
		{
			div[j]++;
		}
	}

	for (int i = 1; i<=input ; i++)
	{
		cout << div[i] << ' ';
	}
	
	
}
#endif



#ifdef LECTURE10
int digit_sum (int x)
{
	int temp, sum = 0;
	while(x>0)
	{
		temp = x % 10;
		sum += temp;
		x = x/10;
	}
	
	return sum;
	// 자릿수 처리하는 방법  
}

int main (void)
{
	freopen("input.txt", "rt", stdin);
	int n , num, sum, max = -INT_MAX, res;
	
	scanf("%d", &n);
	
	for (int i = 0; i<n; i++)
	{
		scanf("%d",&num);
		sum = digit_sum(num);
		
		if(sum > max)
		{  
			res = num;
			max = sum;
		}
		else if (sum == max)
		{
			if(res < num) res = num;
		}
	}
	
	cout << res << endl;
	
}
#endif


#ifdef LECTURE11
int main (void)
{	
	int input, total = 0;
	//freopen("input.txt","rt",stdin);
	scanf("%d", &input);
	
	for(int i = 1; i<= input;i++)
	{
		if(i > 0 && i<10) total++;
		else if(i >= 10 && i<100)total+=2;
		else if(i >= 100 && i<1000)total+=3;
		else if(i >= 1000 && i<10000)total+=4;
		else if(i >= 10000 && i<100000)total+=5;
		else if(i >= 100000 && i<1000000)total+=6;
		else if(i >= 1000000 && i<10000000)total+=7;
		else if(i >= 10000000 && i<100000000)total+=8;
		else								total+=9;
	}
	
	cout << total << endl;
}


#endif


#ifdef LECTURE13
int main (void)
{
	char num[101];
	int max = -INT_MAX;
	int ans = 0;
	int arr[10] ={0, };
	cin >> num;
	for (int i =0; num[i]!='\0';i++)
	{
		if (num[i]=='0') arr[0]++;
		else if (num[i]=='1') arr[1]++;
		else if (num[i]=='2') arr[2]++;
		else if (num[i]=='3') arr[3]++;
		else if (num[i]=='4') arr[4]++;
		else if (num[i]=='5') arr[5]++;
		else if (num[i]=='6') arr[6]++;
		else if (num[i]=='7') arr[7]++;
		else if (num[i]=='8') arr[8]++;
		else if (num[i]=='9') arr[9]++;
	}
		
	for (int i =0; i<10 ; i++)
	{
		if(arr[i]>=max)
		{
			max = arr[i];
			ans = i;	
		} 
		
	}
	
	cout << ans << endl;
}

#endif

#ifdef LECTURE14
int reverse (int x)
{
	int temp = 0, sum = 0, res = 0;
	while(x>0)
	{
		temp = x % 10;
		res = res *10 + temp;
		x /=10;
	}
	
	return res;
}

bool isprime(int x)
{
	if(x==1) return 0;
	else if(x>=2)
	{
	
		for (int i = 2; i<=(int)sqrt(x);i++)
		{
			if(x%i==0) return 0;
		}
	}
	
	return 1;
}
int main (void)
{
	int n, num;
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d",&num);
		
		if(isprime(reverse(num))) cout << reverse(num) << ' ';
		
	}
}

#endif

#ifdef LECTURE15

bool isprime(int x)
{
	if(x==1) return 0;
	else if(x>=2)
	{
	
		for (int i = 2; i<=(int)sqrt(x);i++)
		{
			if(x%i==0) return 0;
		}
	}
	
	return 1;
}
int main (void)
{
	int input;
	
	int count = 0;
	scanf("%d",&input);
	for (int i =2; i<= input ; i++)
	{
		if(isprime(i)) count++;
	}
	
	cout << count;
	
}

#endif

#ifdef LECTURE16

int main (void)
{
	char str[2][101];
	int hash[2][256] = {0, };
	int flag = 1;
	cin >> str[0];
	cin >> str[1];
	
//	cout << str[0] << endl;
//	cout << str[1] << endl;
	
	for (int i = 0; str[0][i]!='\0';i++)
	{
		hash[0][(int)str[0][i]]++;
		//cout << (int)str[0][i] << endl;
	}
	for (int i = 0; str[1][i]!='\0';i++)
	{
		hash[1][(int)str[1][i]]++;
	}
	
	for(int i =0; i < 256; i++)
	{
	//	cout << hash[0][i] << ' ' <<hash[1][i] << endl;
		
	}
	for(int i =0; i < 256; i++)
	{
		if(hash[0][i]==hash[1][i]) continue;
		else 						flag = 0;
	}
	
	if(flag) cout << "YES";
	else 	 cout << "NO";
	
	
}


#endif

#ifdef LECTURE17

int main (void)
{
	int test, input,output;
	int temp = 0;
	cin >> test;
	
	while(test--)
	{
		cin >> input;
		cin >> output;
		
		temp = input * (input +1) / 2;
		
		if (output == temp) cout << "YES"; 
		else if (output != temp) cout << "NO";	
		
		
	}
}

#endif

#ifdef LECTURE18

int main (void)
{
	int arr[101] = {0, };
	int n, m;
	int alarm = 0, max = -INT_MAX;
//	freopen("input.txt","rt",stdin);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];		
	}
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>m) alarm++;
		else		 alarm=0;
		
		if(alarm > max) max = alarm;
	}
	
	if(max < 0 ) cout << "-1";
	else			cout << max;
	
}
#endif

#ifdef LECTURE19
bool israge(int arr[], int start, int end)
{
	if(start + 1 == end) return false;
	for(int i = start + 1 ; i<end;i++)	
	{
		
		if(arr[start] < arr[i]) return false;
	}
	
	return true;
}
int main (void)
{
	int n;
	int stu[101]={0, };
	int cnt = 0;
	int max = 0;
//	freopen("input.txt","rt",stdin);
	
	cin >> n;
	
	for(int i =1; i<=n;i++)
	{
		cin >> stu[i];
	//	cout << stu[i];
	}
	
	max = stu[n];
	for(int i = n-1; i>=1;i--)
	{
		if(max < stu[i])
		{
			max = stu[i];
			cnt++;
		}
		
	}

	cout << cnt;
}
		

#endif

#ifdef LECTURE20

#define ROCK 	2
#define SCISSOR 1
#define PAPER 	3
int main (void)
{
	//freopen("input.txt","rt",stdin);
	int n;
	int a[101], b[101];
	cin >> n;
	for(int i = 1; i<=n;i++)
	{
		cin >> a[i];
	}
	
	for(int i = 1; i<=n;i++)
	{
		cin >> b[i];
	}
	
	for(int i = 1; i<=n;i++)
	{
		if(a[i]==b[i]) cout << 'D' << endl;
		
		else if(a[i]== ROCK && b[i] == SCISSOR) 	cout << 'A'<< endl;
		else if(a[i]== SCISSOR && b[i] == PAPER) 	cout << 'A'<< endl;
		else if(a[i]== PAPER && b[i] == ROCK) 		cout << 'A'<< endl;
		
		else 										 cout << 'B'<< endl;
	}
	
}



#endif

#ifdef LECTURE21

int main (void)
{
//	freopen("input.txt","rt",stdin);
	int a[11] = {0, };
	int b[11] = {0, };
	int a_score = 0, b_score = 0;
	
	int a_flag = 0, b_flag = 0;
	for (int i = 1; i < 11; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i < 11; i++)
	{
		cin >> b[i];
	}
	
	for(int i = 1 ; i<=10;i++)
	{
		if(a[i] > b[i])
		{
			a_flag = 1;
			b_flag = 0;
		 	a_score+=3;
		}	
		else if(a[i] < b[i])
		{
			a_flag = 0;
			b_flag = 1;	  
			b_score+=3;
		}
		else if(a[i] == b[i])
		{
			a_score++;
			b_score++;	
		}		
	//	cout << a_score << ' ' << b_score << endl;
		
	}
	
	cout << a_score << ' ' << b_score << endl;
	
	if (a_score > b_score) cout << 'A';
	else if (a_score < b_score) cout << 'B';
	else 
	{
		if(a_flag) cout << 'A';
		else if(b_flag) cout << 'B';
		else cout << 'D';
		
	}
}

#endif

#ifdef LECTURE22

int main (void)
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> sum(n);
	int sigma = 0;
	int max = -INT_MAX;
	
	for (int i = 0; i<n; i++)
	{
		cin >>arr[i];
	}
	
	sum[0]=arr[0];
	for (int i = 1; i<n; i++)
	{
		sum[i] = sum[i-1] + arr[i];
	}	
	
	for (int i = 0; i<=n-k; i++)
	{
		sigma = sum[i+k-1]-sum[i]+arr[i];
		
		if(max < sigma) max = sigma;
		sigma = 0;
	}
	
	cout << max;
	
}
#endif


#ifdef LECTURE23

int main (void)
{
	int n, k;
	int max = -INT_MAX;
//	freopen("input.txt","rt",stdin);
	cin >> n;
	
	vector<int> arr(n);
	vector<int> len(n);
	for (int i = 0 ; i < n; i++)
	{
		cin >> arr[i];
		len[i] = 1;
	}
	for (int i = 0 ; i < n; i++)
	{
		if(arr[i+1] >= arr[i]) 
		{
			len[i+1] = len[i] + 1;
		}
	}
	for (int i = 0 ; i < n ; i++)
	{
		if(max < len[i]) max = len[i];
	}
	
	cout << max;
}
#endif


#ifdef LECTURE24

int main (void)
{
	int n, k;
	int max = -INT_MAX;
//	freopen("input.txt","rt",stdin);
	
	
	cin >> n;
	vector<int> arr(n);
	vector<int> num(n);
	vector<int> index(n);
	int temp = 0;
	int flag = 1;
	
	for (int i = 0; i<n;i++)
	{
		cin >> arr[i];
		
	//	cout << arr[i];
	}
	
	for(int i = 0; i<n-1;i++)
	{
		temp = arr[i]-arr[i+1];
		num[i]= temp > 0 ? temp : -temp;	
		//cout << num[i] << endl;;
	}
	
	for(int i = 0; i<n-1; i++)
	{
		
		index[num[i]] = 1;
		//cout << num[i]<< ' '<< index[num[i]] << endl;;
	}
	for(int i = 1; i<=n-1; i++) 
	{	
		if(!index[i])
		{ 
			flag = 0;
			cout << "NO";
			break;
		}
	}
	if(flag)	cout << "YES";
}
#endif

#ifdef LECTURE25

int main (void)
{
	
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> rank(n,1);
	for(int i = 0; i<n;i++)
	{
		cin >> arr[i];
	}
	
	//cout << rank[3];
	
	for(int i = 0; i<n;i++)
	{
		for (int j = 0; j<n;j++)
		{
			if(arr[i] < arr[j]) rank[i]++;	
		}	
	}
	
	for(int i = 0; i< n; i++)
	{
		cout << rank[i] << ' ';
	}
}
#endif

#ifdef LECTURE26

int main (void)
{
	int n;
	cin >> n;
	
	vector<int> arr(n);
	vector<int>	abt(n,1);
	
	for (int i = 0; i<n;i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 0; i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]>=arr[i]) abt[i]++;
		}
	}
	
	for (int i = 0; i<n;i++)
	{
		cout << abt[i] << ' ';
	}
}
#endif

#ifdef LECTURE27
bool isprime(int x)
{
	if(x==1) return 0;
	else if(x>=2)
	{
	
		for (int i = 2; i<=(int)sqrt(x);i++)
		{
			if(x%i==0) return 0;
		}
	}
	
	return 1;
}
int main (void)
{
	int n;
	int j;
	int tmp;
	cin >> n;
	
	vector<int> check(n+1);
	
	for (int i = 2; i<=n;i++)
	{
		tmp = i;
		j=2;
		while(1)
		{
			if(tmp%j==0)
			{
			
				tmp /= j;
				check[j]++;
			}
			else j++;
			
			if(tmp == 1) break;
		}
	} // 소인수 분해 처리
	 
	
	cout << n << "! = ";
	for (int i = 2; i<=n;i++)
	{
		if(isprime(i)) cout << check[i] << ' ';
	}
}
#endif

#ifdef LECTURE28


int main (void)
{
	int n;
	int j;
	int tmp;
	cin >> n;
	
	vector<int> check(n+1);
	
	for (int i = 2; i<=n;i++)
	{
		tmp = i;
		j=2;
		while(1)
		{
			if(tmp%j==0)
			{
			
				tmp /= j;
				check[j]++;
			}
			else j++;
			
			if(tmp == 1) break;
		}
	} // 소인수 분해 처리
	
	tmp = (check[2] <= check[5]) ? check[2] : check[5];
	
	cout << tmp;
	 

}
#endif

#ifdef LECTURE29


int main (void)
{
	int n;
	int j;
	int tmp;
	
	int cnt = 0;
	cin >> n;
	
	for (int i = 0; i<n;i++)
	{
		tmp = i;
		while(tmp>0)
		{
			if(tmp%10 == 3)  cnt++;
			tmp /= 10;
		}
	}
	
	cout << cnt;

	
}
#endif

#ifdef LECTURE30


int main (void)
{
	int n;
	//cin >> n;
	int res = 0, tmp = 0;
	int lt = 0, rt = 0;
	int r_idx;
	int l_idx = 0;
	int l_num = 0, r_num = 0;
	int total = 0;
	char arr[10];
	
	cin >> arr;
	l_idx = 0;
	r_idx = strlen(arr)-1;
	//cout << r_idx;
	for (int i = 0; i<strlen(arr)-1;i++)
	{
		rt = i+1;
		lt = i-1;
		tmp = i;
		if(i == 0)
		{
			while(rt <= r_idx)
			{
				r_num = 10 * r_num + (arr[rt] - '0');
				rt++;
				//cout << r_num << endl;
			}
			if(arr[i] >=3)
			{
				total += r_num;
			}
			else;
		}
		
		else if(i > 1 && i < (strlen(arr)-2))
		{
			while(rt <= r_idx)
			{
				r_num = 10 * r_num + (arr[rt] - '0');
				rt++;
				//cout << r_num << endl;
			}
			
			while(lt >= l_idx)
			{
				l_num = 10 * l_num + (arr[l_idx] - '0');
				l_idx++;
			}
			
			
			cout << l_num << ' ' << r_num << endl;
			if(arr[i] >3)			total += (l_num+1) * (strlen(arr)-1-i);
			else if (arr[i] ==3)	total += (l_num) * (strlen(arr)-1-i) + r_num + 1;
			else if (arr[i] < 3)    total += (l_num) * (strlen(arr)-1-i);
		
		}
		
		else
		{
			while(lt >= l_idx)
			{
				l_num = 10 * l_num + (arr[l_idx] - '0');
				l_idx++;
			}
			
			if(arr[i] >=3)
			{
				total += l_num;
			}
		}
		r_idx = strlen(arr)-1;
		l_idx = 0;
		l_num = 0;
		r_num = 0;
		
		
		//cout << 'A';
	}
	
	cout << total;
	

	
}
#endif


#ifdef LECTURE31


int main (void)
{
	char arr[100];
	
	cin >> arr;
	int c = 0, h=0;
	int i = 0;
	for (i = 1; arr[i]!='H';i++)
	{	
		//cout << 'T';
		c = c * 10 + (arr[i]-'0');
	}
	if(arr[0]=='C' && arr[1]=='H' ) c=1;
	
	for (int k = i+1; arr[k]!='\0';k++)
	{
		h = h * 10 + (arr[k]-'0');
	}
	if(arr[i]=='H' && arr[i+1]=='\0' ) h=1;
	//cout << c << ' ' << h << endl;
	
	cout << 12*c + h;
}
#endif
