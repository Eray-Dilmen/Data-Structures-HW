#include <stdio.h>
#include <stdlib.h>

///Question 1
void Algo1(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("Hello World\n");
    }
}
/// Answer : O(n)
/// Reason: One loop, runs n times.(Sebep: Tek döngü, n kez çalışır.)




/// Question 2
void Algo2(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Hello World\n");
        }
    }
}
/// Answer : O(n^2)
/// Reason: Two nested n-loops.(Sebep: İç içe iki tane n’lik döngü.)



///Question 3
void Algo3(int n) {
    int i;
    for (i = 1; i < n; i = i * 2) {
        printf("Hello World\n");
    }
}
/// Answer : O(log[base 2]n)
///Reason: i doubles with each step.(Sebep: i her adımda 2 katına çıkıyor.)
/// It can be simplified if we want -> O(log n)
/**I discarded the base and coefficients according to Big-O notation.
The base of the logarithm is irrelevant.
The coefficients are irrelevant.
Only the growth type remains.
(Big-O kurallarına göre tabanı ve katsayıları attım. Logaritmanın tabanı önemsizdir. Katsayılar önemsizdir.Sadece büyüme türü kalır) */

///Question 4
void Algo4(int n) {
    int i;
    for (i = n; i > 0; i = i / 5) {
        printf("Hello World\n");
    }
}
/// Answer : O(log[base 5] n)
///Reason: i is divided by 5 at each step.(Sebep: i her adımda 5’e bölünüyor.)
/// It can be simplified if we want -> O(log n)
/**I discarded the base and coefficients according to Big-O notation.
The base of the logarithm is irrelevant.
The coefficients are irrelevant.
Only the growth type remains.
(Big-O kurallarına göre tabanı ve katsayıları attım. Logaritmanın tabanı önemsizdir. Katsayılar önemsizdir.Sadece büyüme türü kalır) */



/// Question 5
void Algo5(int n) {
    int i;
    for (i = 1; i < n * n * n; i = i * 5) {
        printf("Hello World\n");
    }
}
/// Answer : O(log[base 5] n^3)
///It can be simplified if we want -> O(log n)
/**I discarded the base and coefficients according to Big-O notation.
The base of the logarithm is irrelevant.
The coefficients are irrelevant.
Only the growth type remains.
(Big-O kurallarına göre tabanı ve katsayıları attım. Logaritmanın tabanı önemsizdir. Katsayılar önemsizdir.Sadece büyüme türü kalır) */





/// Question 6
void Algo6(int n) {
    int i;
    for (i = 1; i * i <= n; i++) {
        printf("Hello World\n");
    }
}
/// Answer : O(√n)
///Reason: i^2 ≤ n -> i ≤ √n



/// Question 7
void Algo7(int n) {
    int i = 1;
    int k = 1;

    while (k <= n) {
        i++;
        k = k + i;
        printf("Hello World\n");
    }
}
/// Answer : O(√n)
///Reason: k = 1 + 2 + 3 + ... + i → i ≈ √n


int main(void) {

    ///  7 question have to answered as Big O Notation

}
