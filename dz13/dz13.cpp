// dz13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


////Опрацювати приклади на стор. 4 - 5
//
//#include <iostream>
//using namespace std;
//// Створення користувацького типу даних (структури)
//// для зберігання дати.
//// Усі дані, що стосуються одного об'єкта, зібрані разом.
//struct date
//{
//    int day; // день
//    int month; //місяць
//    int year;//рік
//    int weekday; // день тижня
//    char mon_name[15];// назва місяця
//};
//int main() {
//    // створення об'єкта з типом date та його
//    // ініціалізація при створенні
//    date myBirthday = { 20,7,1981,1,"July" };
//    // вивід вмісту об'єкта на екран
//    // звернення до окремого члена структури
//    // здійснюється через оператор крапка (.)
//    cout << "________MY BIRTHDAY __________\n\n";
//    cout << "DAY " << myBirthday.day << "\n\n";
//    cout << "MONTH " << myBirthday.month << "\n\n";
//    cout << "YEAR " << myBirthday.year << "\n\n";
//    cout << "WEEK DAY " << myBirthday.weekday << "\n\n";
//    cout << "MONTH NAME ";
//    cout << myBirthday.mon_name << "\n\n";
//    // Створення порожнього об'єкта і заповнення його
//    // з клавіатури date your_birthday;
//    cout << "DAY ? ";
//    cin >> your_birthday.day;
//    cout << "MONTH ?";
//    cin >> your_birthday.month;
//    cout << "YEAR ?";
//    cin >> your_birthday.year;
//    cout << "WEEK DAY ?";
//    cin >> your_birthday.weekday;
//    cout << "MONTH NAME ?";
//    cin >> your_birthday.mon_name;
//    cout << "______YOUR BIRTHDAY_____\n\n";
//    cout << "DAY " << your_birthday.day << "\n\n";
//    cout << "MONTH " << your_birthday.month << "\n\n";
//    cout << "YEAR " << your_birthday.year << "\n\n";
//    cout << "WEEK DAY " << your_birthday.weekday << "\n\n";
//    cout << "MONTH NAME ";
//    cout << your_birthday.mon_name << "\n\n";
//    return 0;
//}
//
////Опрацювати приклади на стор.  12 - 13
//
//#include <iostream>
//using namespace std;
//struct date {
//    int day;
//    int month;
//    int year;
//    char mon_name[12];
//};
///*
//Об'єкт структури передається у функцію за значенням
//Можлива також передача за посиланням і за покажчиком
//*/
//void Show(date a) {
//    // вивід вмісту об'єкта a
//    cout << a.day << " ";
//    cout << a.year << " ";
//    cout << a.month << " ";
//    cout << a.mon_name << "\n\n";
//}
//date Put() {
//    // формування об'єкта
//    date temp;
//    cout << "DAY ? ";
//    cin >> temp.day;
//    cout << "MONTH ? ";
//    cin >> temp.month;
//    cout << "YEAR ? ";
//    cin >> temp.year;
//    cout << "MONTH NAME ? ";
//    cin >> temp.mon_name;
//    return temp;
//}
//int main() {
//    date a = { 14,7,1954,"July" };
//    date b;
//    // передача об'єкта у функцію
//    Show(a);
//    // отримання об'єкта як значення,
//    // що повертається
//    b = Put();
//    // вивід вмісту об'єкта b
//    Show(b);
//    return 0;
//}

//2.	Створити структуру ВІДЕОФІЛЬМ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct VideoFilm {
    string title;
    string director;
    string genre;
    int popularityRating;
    double price;
};


void displayFilm(const VideoFilm& film) {
    cout << "Title: " << film.title << endl;
    cout << "Director: " << film.director << endl;
    cout << "Genre: " << film.genre << endl;
    cout << "Popularity Rating: " << film.popularityRating << endl;
    cout << "Price: " << film.price << endl << endl;
}


void displayAllFilms(const vector<VideoFilm>& films) {
    for (const auto& film : films) {
        displayFilm(film);
    }
}


void addFilm(vector<VideoFilm>& films, const VideoFilm& newFilm) {
    films.push_back(newFilm);
}


void removeFilm(vector<VideoFilm>& films, const string& title) {
    auto it = remove_if(films.begin(), films.end(), [&title](const VideoFilm& film) {
        return film.title == title;
        });
    films.erase(it, films.end());
}


void searchByTitle(const vector<VideoFilm>& films, const string& title) {
    for (const auto& film : films) {
        if (film.title == title) {
            displayFilm(film);
            return;
        }
    }
    cout << "Film with title \"" << title << "\" not found." << endl;
}


void searchByGenre(const vector<VideoFilm>& films, const string& genre) {
    cout << "Films in genre \"" << genre << "\":" << endl;
    for (const auto& film : films) {
        if (film.genre == genre) {
            displayFilm(film);
        }
    }
}


void searchByDirector(const vector<VideoFilm>& films, const string& director) {
    cout << "Films directed by \"" << director << "\":" << endl;
    for (const auto& film : films) {
        if (film.director == director) {
            displayFilm(film);
        }
    }
}


void searchMostPopularByGenre(const vector<VideoFilm>& films, const string& genre) {
    int maxRating = 0;
    VideoFilm mostPopularFilm;
    for (const auto& film : films) {
        if (film.genre == genre && film.popularityRating > maxRating) {
            maxRating = film.popularityRating;
            mostPopularFilm = film;
        }
    }
    cout << "Most popular film in genre \"" << genre << "\":" << endl;
    displayFilm(mostPopularFilm);
}


double calculateTotalPrice(const vector<VideoFilm>& films) {
    double totalPrice = 0.0;
    for (const auto& film : films) {
        totalPrice += film.price;
    }
    return totalPrice;
}


void sortByRating(vector<VideoFilm>& films) {
    sort(films.begin(), films.end(), [](const VideoFilm& a, const VideoFilm& b) {
        return a.popularityRating > b.popularityRating;
        });
}

int main() {

    vector<VideoFilm> films = {
        {"Film 1", "Director 1", "Genre 1", 8, 10.99},
        {"Film 2", "Director 2", "Genre 2", 7, 9.99},
        {"Film 3", "Director 1", "Genre 1", 9, 12.99},
         {"Film 4", "Director 3", "Genre 3", 6, 8.99},
        {"Film 5", "Director 2", "Genre 2", 8, 11.99}
    };

    
    displayAllFilms(films);

    
    VideoFilm newFilm = { "Film 6", "Director 3", "Genre 3", 7, 14.99 };
    addFilm(films, newFilm);

    
    removeFilm(films, "Film 2");

    
    searchByTitle(films, "Film 4");

    
    searchByGenre(films, "Genre 1");

    
    searchByDirector(films, "Director 2");

    
    searchMostPopularByGenre(films, "Genre 3");

    
    cout << "Total price: " << calculateTotalPrice(films) << endl;

    
    sortByRating(films);

    
    cout << "Sorted by rating:" << endl;
    displayAllFilms(films);

    return 0;
}

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
