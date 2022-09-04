#include <bits/stdc++.h>

using namespace std;

template <size_t N>
struct PrimeTable {
  constexpr PrimeTable() : sieve() {
    sieve[0] = sieve[1] = false;
    for (size_t i = 2; i < N; i++) sieve[i] = true;
    for (size_t i = 2; i < N; i++) {
      if (sieve[i])
        for (size_t j = i*i; j < N; j += i) sieve[j] = false;
    }
  }
  bool sieve[N];
};

int main() {
    constexpr auto table = PrimeTable<1000>();
}
