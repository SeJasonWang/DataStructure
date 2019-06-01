//
//  bigo.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "bigo.h"

int f1(long n) {
    int k = 0;
    for (int i = 0; i < n; i++) {        // n
        for (int j = 0; j < n; j++) {    // n
            k++;    // Θ(1)
        }
    }
    return k;
}
// Total = n * n * Θ(1) = Θ(n^2)


void f2(long n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {        // 1+2+3+···+(n-1)
            k++;
        }
        for (int t = 0; t < 10000; t++) {    // 10000 * n
            k++;
        }
    }
}
// (1/2) * n * (n+1) + 10000 * n = Θ(n^2)

/*
 *  𝑇(𝑛) = 𝑎𝑇(𝑛/𝑏) + 𝑓(𝑛)
 *  (1). If 𝑓(𝑛) grows slower than 𝑛^log_𝑏⁡𝑎  then 𝑇(𝑛) = Θ(𝑛^log_𝑏⁡𝑎)
 *  (2). If 𝑓(𝑛) grows about the same as 𝑛^log_𝑏⁡𝑎   then 𝑇(𝑛) = Θ(𝑛^log_𝑏⁡𝑎ln⁡𝑛)
 *  (3). If 𝑓(𝑛) grows faster than 𝑛^log_𝑏⁡𝑎  then 𝑇(𝑛) = Θ(𝑓(𝑛))
 */
void f3(long n) {
    if (n > 0){
        f3(n / 2);
        f3(n / 2);
    }
}
// (1). 𝑛^log_2⁡ 2 = Θ(n)

void f4(long n) {
    if (n > 0){
        f4(n / 2);
        f4(n / 2);
        f2(n);  // n^2
    }
}
// (3). Θ(f2(𝑛)) = Θ(n^2)

void f5(long n) {
    int k = 0;
    for (int i = 0; i < 10; i++) { // 10
        long j = n;
        while (j > 0) { // n/2^k = 1 (k = log_2𝑛)
            k++;
            j = j / 2;
        }
    }
}
// 10 * log_2𝑛 = Θ(ln𝑛)

void f6(long n) {
    f2(n);  // Θ(n^2)
    f3(n);  // Θ(n)
    f5(n);  // Θ(ln𝑛)
}
// Θ(n^2) + Θ(n) + Θ(ln𝑛) = Θ(n^2)

void f7(long n) {
    int k = 0;
    for (int i = 0; i < n * n; i++) { // n^2
        k++;
    }
    for (int j = 0; j < n; j++) { // n
        k++;
    }
}
// n^2 + n = Θ(n^2)

void f8(long n) {
    int k = 0;
    for (int i = 0; i < f1(n); i++) { // n^2 * n^2
        k++;
    }
    for (int j = 0; j < n; j++) { // n
        k++;
    }
}
// n^4 + n = Θ(n^4)
