#include <iostream>

#define MAX_TABLE (10007)
typedef unsigned long long int ull;
typedef struct st
{
  int index;
  char name[21];
  struct st *next;
}POKETMON;

POKETMON HASH_TABLE[MAX_TABLE];
POKETMON POOL[100000 + 5000];
int pcnt;

POKETMON ARR[100000 + 5000];

ull hash(const char *str)
{
  ull hash = 5381;
  int c;

  while(c = *str++)
  {
    hash = (((hash << 5) + hash) + c) % MAX_TABLE;
  }

  return hash % MAX_TABLE;
}

void mystrcpy(char *a, char *b)
{
  while(*a++ = *b++);
}

int mystrcmp(const char *a, const char *b)
{
  while(*a && *a == *b) ++a,++b;
  return *a - *b;
}

// stoi
int change(char *str)
{
  int i,len;
  int sum, mul;

  sum =0;
  mul = 1;

  for(i = 0;str[i];i++);
  len = i;

  for(i = len -1; i >= 0; i--)
  {
    sum += (str[i] - '0') * mul;
    mul *= 10;
  }

  return sum;
}

int N,M;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  char str[21];
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> str;

    ull h = hash(str);
    POKETMON *nd = &POOL[pcnt++];

    nd->index = i;
    mystrcpy(nd->name, str);
    // 키 값 연결해주는 것
    nd->next = HASH_TABLE[h].next;
    HASH_TABLE[h].next = nd;
    mystrcpy(ARR[i].name, str);
  }

  for(int i = 0; i < M; i++)
  {
    std::cin >> str;

    if('0' < str[0] && str[0] <= '9')
    {
      int index = change(str);
      std::cout << ARR[index].name << "\n";
    }
    else
    {
      ull h = hash(str);
      POKETMON *nd = HASH_TABLE[h].next;

      while(nd)
      {
        if(!mystrcmp(nd->name, str))
        {
          std::cout << nd->index << "\n";
          break;
        }
        nd = nd->next;
      }
    }
  }
  return 0;
}