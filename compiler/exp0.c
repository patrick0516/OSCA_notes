#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int tokenIdx = 0;
char *tokens;

int E();
int F();

void error(char *msg) {
  printf("%s", msg);
  assert(0);
}

// 取得目前字元
char ch() {
  char c = tokens[tokenIdx];
  return c;
}

// 取得目前字元，同時進到下一格
char next() {
  char c = ch();
  tokenIdx++;
  return c;
}

// ex: isNext("+-") 用來判斷下一個字元是不是 + 或 -
int isNext(char *set) {
  char c = ch();
  return (c!='\0' && strchr(set, c)!=NULL);
}

// 產生下一個臨時變數的代號， ex: 3 代表 t3。
int nextTemp() {
  static int tempIdx = 0;
  return tempIdx++;
}

// F =  Number | '(' E ')'
// 如果碰到一個數字就讀掉 print 出, e.g. t0 = 1
int F() {
  int f;
  char c = ch();
  if (isdigit(c)) {
    next(); // skip c
    f = nextTemp();
    printf("t%d=%c\n", f, c);        // f是0, c是1
  } else if (c=='(') { // '(' E ')'
    next();
    f = E();
    assert(ch()==')');
    next();
  } else {
    error("F = (E) | Number fail!");
  }
  return f; 
}

// E = F ([+-] F)*
int E() {
  int i1 = F();      // 臨時變數 e.g. t0 = 1     
  while (isNext("+-")) {
    char op=next();
    int i2 = F();    // 臨時變數 e.g. t1 = 2
    int i = nextTemp();
    printf("t%d=t%d%ct%d\n", i, i1, op, i2);    // 產生 t3 = t0 + t1
    i1 = i;
  }
  return i1;
}

void parse(char *str) {
  tokens = str;
  E();
}

int main(int argc, char * argv[]) {
  printf("argv[0]=%s argv[1]=%s\n", argv[0], argv[1]);
  printf("=== EBNF Grammar =====\n");
  printf("E=F ([+-] F)*\n");
  printf("F=Number | '(' E ')'\n");
  printf("==== parse:%s ========\n", argv[1]);
  parse(argv[1]);
}
