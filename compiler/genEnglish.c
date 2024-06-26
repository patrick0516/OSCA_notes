#include "rlib.h"

// === EBNF Grammar =====
// S = NP VP
// NP = DET N
// VP = V NP
// N = dog | cat
// V = chase | eat
// DET = a | the

char* n[] = {"dog", "cat"};
char* v[] = {"chase", "eat"};
char* det[] = {"a", "the"};

// 兩個選一個
void N() {
  printf("%s", randSelect(n, 2));
}

void V() {
  printf("%s", randSelect(v, 2));
}

void DET() {
  printf("%s", randSelect(det, 2));
}

void NP() {
  DET();                 // 定詞
  printf(" ");           // 空格
  N();                   // 名詞
}

void VP() {
  V();                   // 動詞
  printf(" ");           // 空格
  NP();                  // 名詞子句
}

void S() {
  NP();                  // 名詞子句
  printf(" ");           // 空格
  VP();                  // 動詞子句
  printf("\n");
}

// 主程式，呼叫S()產生一個句子。
int main() {
  timeSeed();
  S();
}
