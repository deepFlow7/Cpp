#include <stdexcept>

class ujemny_rozmiar_wektora : public std::logic_error
{
public :
    ujemny_rozmiar_wektora() : logic_error("Rozmiar wektora nie może być ujemny"){}
};

class ujemny_rozmiar_macierzy : public std::logic_error
{
public :
    ujemny_rozmiar_macierzy() : logic_error("Rozmiar macierzy nie może być ujemny"){}
};

class zmiana_rozmiaru_wektora : public std::logic_error
{
public :
    zmiana_rozmiaru_wektora() : logic_error("Rozmiar wektora nie może zostać zmieniony"){}
};

class zmiana_rozmiaru_macierzy : public std::logic_error
{
public :
    zmiana_rozmiaru_macierzy() : logic_error("Rozmiar macierzy nie może zostać zmieniony"){}
};

class rozne_rozmiary_wektorow : public std::logic_error
{
public :
    rozne_rozmiary_wektorow(std::string info) : logic_error("Rozmiary wektorów" + info + " muszą być równe"){}
};

class rozne_rozmiary_macierzy : public std::logic_error
{
public :
    rozne_rozmiary_macierzy(std::string info) : logic_error("Rozmiary macierzy" + info + " muszą być równe"){}
};

class niepoprawny_index : public std::logic_error
{
public :
    niepoprawny_index() : logic_error("Niepoprawny index"){}
};
