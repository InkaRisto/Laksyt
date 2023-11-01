#include <iostream>
#include <random>
#include <tuple>

using namespace std;

tuple<int, int, int> get_random_number() {
    random_device seed; // Random seed
    int low, high;
    cout << "Anna pelille alin ja ylin arvo: ";
    cin >> low;
    cin >> high;
    uniform_int_distribution<int> distribution(low, high);
    mt19937 gen(seed()); // Seed the engine
    int random_number = distribution(gen); // Generate from parameters given
    return make_tuple(random_number, low, high);
}

int get_guess(int low, int high) {
    int guess;
    while (true) {
        cout << "\nArvaa luku (" << low << "-" << high << "): " << endl;
        cin >> guess;
        if (guess >= low && guess <= high) {
            return guess;
        }
        else {
            cout << "Pysy antamissasi arvoissa! (Vain lailliset arvaukset lasketaan.) \n";

        }
    }
}

int react(int guess, int goal) {
    if (guess > goal) {
        cout << "Liian suuri!\n";
        return 1;
    }
    if (guess < goal) {
        cout << "Liian pieni\n";
        return 1;
    }
    return 0;
}

int lets_play() {
    int comnumber;
    int guesses = 1;
    int low;
    int high;
    tuple<int, int, int> game_rules = get_random_number();

    comnumber = get<0>(game_rules);
    low = get<1>(game_rules);
    high = get<2>(game_rules);

    while (true) {
        int user_guess = get_guess(low, high);
        int result = react(user_guess, comnumber);
        if (result == 0) {
            break; // Correct guess, exit the loop
        }
        guesses += 1;
    }
    cout << "Oikein! Teit " << guesses << " arvausta." << endl;
    return 0;
}

int main() {
    lets_play();
}
 