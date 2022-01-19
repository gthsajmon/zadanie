
# zadanie
Lokalne repozytorium w oparciu o ceedling.

Zgodnie z życzeniem sforkowałem też repozytorium phoenix-rtos-tests. Jedak jak już wcześniej wspomniałem
nie wiem jak dodać power.c oraz test_power.c i Makefile aby runner na githubie uruchomił moje testy razem z już istniejącymi.
Dodałem po prostu katalog "zadanie" do tego repozytorium.

Dlatego zamieszczam moje lokalne repozytorium które utworzyłem aby uruchomić testy
implementacji pow() dla rtosa na ceedlingu.

Struktura katalogów:

src/math/power.c
Mamy testowaną implementację pow() dla rtosa.
Uwaga! musiałem zmienić jej nazwę na pow_rtos() na potrzeby testu
ponieważ samo unity.h includuje już systemową deklarację pow().

src/test/math/test_power.c
Wektory testowe dla pow_rtos(). Zostały zmockowane wszystkie zewnętrzne wywołania.

src/test/math/test_power_nomock.c
Pozwoliłem sobie porównać implementację systemową i dla rtosa na pewnych losowych danych.
Zauważyłem że pow() systemu z ujemną podstawą potęgi np. pow(-2.0, 2.0) zwraca wyniki dodatnie zamiast ujemnych.
Co mnie trochę zaskoczyło.

src/test/support/
Nagłówki niezbędne do zmockowania zależności w pow_rtos()


Wnioski:
Funkcja pow_rtos() bazując na funkcji eksponencjalnej i logarytmicznej stara się zmniejszyć złożoność obliczeniową.
testuje to 1 wektor: void test_pow_rtosNormalVector(void).
Dodatkowo zastosowano optymalizację na quickPow() dla zaktesu liczb całkowitych.
Uwzględnia to 2 wektor: void test_pow_rtosIntegerExponentVector(void).
Testując przypadki brzegowe INT_MIN/INT_MAX i wyjście poza ich zakres.

Dalej mamy obsługę specyficznych sytuacji:
void test_pow_rtosZeroBaseExponentVector(void).  Zerowy wykładnik i potęga
void test_pow_rtosZeroExponentVector(void). Zawsze 1.0
void test_pow_rtosZeroBaseVector(void). Zawsze 0.0
void test_pow_rtosZeroBaseNegExponent(void). INFINITY ze znakiem

Zamiast (exponent == 0.0 || exponent == -0.0)
użyłem funkcji klasyfikującej fpclassify() jako rozwiązania bardziej przenośnego.
to samo dotyczy signbit()
