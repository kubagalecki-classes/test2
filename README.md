# Kolokwium II - Warzywniak
_Czas pracy: 90 minut_

## Zadanie 1
Napisz klasę `Warzywo`, która posiada:
- prywatne pole typu `std::string`, reprezentujące nazwę warzywa
- prywatne pole typu `double`, reprezentujące cenę warzywa (za kg)
- prywatne pole typu `int`, reprezentujące kolor warzywa
- prywatne pole statyczne typu `unsigned`, reprezentujące liczbę istniejących obecnie warzyw. Pole to powinno mieć początkowo wartość 0.
- publiczny konstruktor parametryczny `Warzywo(const std::string&, double, int)`, który inkrementuje dodatkowo liczbę istniejących warzyw
- publiczny destruktor, które dekrementuje liczbę istniejących warzyw
- publiczną metodę statyczną `unsigned getVeg()`, zwracającą liczbę istniejących warzyw (wartość pola statycznego)
- publiczą metodę `void opis(std::ostream&) const`, drukującą do podanego strumienia informację `[nazwa]: [cena], [kolor][znak końca linii]`. **Uwaga**: zwróć uwagę na poprawne formatowanie.

**Uwaga**: `zad1.hpp` będzie załączane przez inne pliki, w związku z czym jeżeli zdefiniujemy zmienne statyczne w tym nagłówku, linker zobaczy to jako wielokrotną definicję i linkowanie zakończy się błędem. Aby temu zapobiec mamy 2 opcje:
1. Przenieść definicję zmiennej statycznej do pliku `zad1.cpp` (oczywiście deklaracja pozostaje jak zwykle w ciele klasy).
2. Dołączyć na początku deklaracji oraz definicji zmiennej statycznej słowo kluczowe `inline`. 

## Zadanie 2
Napisz klasę `Ogorek`, posiadającą publiczną abstrakcyjną metodę `std::string chrup()`. Następnie napisz dwie publicznie dziedziczące po niej klasy: `Zielony` i `Kiszony`. Niech klasy te nadpisują metodę `chrup`. `Zielony` powinien zwracać wynik zawołania funkcji `chrupZielony` (dostarczonej przez prowadzącego), a `Kiszony` wynik zawołania funkcji `chrupKiszony` (także dostarczonej przez prowadzącego). Napisz także funkcję `jedzOgorek`, która:
- przyjmuje jeden argument typu `Ogorek*`
- zwraca obiekt typu `std::string`
- jeżeli pod podanym adresem znajduje się obiekt typu `Zielony`, zwraca tekst `Zielony: [wynik zawołania metody chrup]`
- jeżeli pod podanym adresem znajduje się obiekt typu `Kiszony`, zwraca tekst `Kiszony: [wynik zawołania metody chrup]`

**Podpowiedź**: tekst dwóch obiektów typu `std::string` można łączyć za pomocą operatora `+` (`string3 = string1 + string2`). Do sprawdzania typu obiektów pochodnych użyj rzutowania dynamicznego.

## Zadanie 3
Napisz szablon funkcji `gotujZupe`, sparametryzowany typem `T`, który:
- przyjmuje jako pierwszy argument stałą referencję do obiektu typu `Warzywo`
- przyjmuje jako drugi argument stałą referencję do obiektu typu `T`
- zwraca podniesiony do kwadratu wynik zawołania metody `gotuj` drugiego argumentu funkcji `gotujZupe`, przyjmującej jako argument tej metody pierwszy argument funkcji `gotujZupe`. Załóż że odpowiednia metoda istnieje i zwraca liczbę typu `unsigned`.

## Zadanie 4
Napisz funkcję `jedzOstatnieWarzywa`, która:
- przyjmuje jako pierwszy argument stałą referencję do wektora (w znaczeniu `std::vector`) obiektów typu `Warzywo`
- przyjmuje drugi argument typu `unsigned` (dalej `n`)
- przyjmuje trzeci argument typu `std::ostream&`
- nie zwraca żadnej wartości
- jeżeli `n` jest większe lub równe długości wektora, rzuca wyjątkiem typu `std::logic_error` (argument konstruktora wyjątku dowolny)
- drukuje do podanego strumienia informacje o warzywach zawartych w wektorze przy pomocy metody `opis`. Drukowana powinna być informacja o `n` warzywach, począwszy od przedostatniego elementu wektora i idąc w stronę jego początku. Na przykład, jeżeli podany zostanie wektor zawierający 5 elementów oraz `n == 3`, to najpierw powinna zostać wywołana metoda `opis` czwartego elementu wektora, następnie trzeciego, a następnie drugiego (argumentem do wszystkich wywołań tej metody jest oczywiście podany do funkcji strumień).

## Zadanie 5
Napisz algorytm (szablon funkcji) `liczKolejneWarzywa`, który:
- przyjmuje jako pierwsze dwa argumenty iteratory do pewnego zakresu obiektów typu `Warzywo` (typ iteratorów powinien być parametrem szablonu).
- przyjmuje jako trzeci argument liczbę typu `unsigned` (dalej `n`)
- przyjmuje jako czwarty argument stałą referencję do obiektu typu `std::string` (dalej `s`)
- zwraca wartość `bool`
- jeżeli podany zakres zawiera `n` kolejnych wystąpień warzyw o nazwie równej `s` zwraca `true`, w innym wypadku `false`
- wykorzystuje algorytm `std::search_n`

Ponieważ pole reprezentujące nazwę warzywa jest prywatne, do realizacji tego zadania konieczne jest dodanie odpowiedniego publicznego gettera do klasy `Warzywo`. Pamiętaj żeby oznaczyć getter jako `const`.
