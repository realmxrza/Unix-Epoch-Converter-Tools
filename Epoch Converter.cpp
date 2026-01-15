#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void showMenu();
void dateToTs();
void tsToDate();

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        clear();
        cout << "    [EPOCH CONVERTER TOOL]    " << endl;
         cout << "==============================" << endl;
        cout << "\n[1] Date To Timestamp" << endl;
        cout << "[2] Timestamp To Date" << endl;
        cout << "[3] Current Time" << endl;
        cout << "[4] Live Time" << endl;
        cout << "[5] Kill" << endl;
        cout << "\nEnter number 1-5: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) dateToTs();
        else if (choice == 2) tsToDate();
        else if (choice == 3) {
            time_t now = time(0);
            cout << "\nEpoch: " << now << endl;
            cout << "Timestamp: " << ctime(&now);
        }
        else if (choice == 4) {
            cout << "Running... Press Ctrl + C to stop\n";
            while(true) {
                time_t t = time(0);
                cout << "\r" << t << " | " << ctime(&t);
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        }
        else if (choice == 5) {
            running = false;
        }

        if (choice != 4 && choice != 5) {
            cout << "\nHit enter to go back...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
// Converts date into a Unix Epoch timestamp
void dateToTs() {
    struct tm t = {0};
    int y, m, d, h, min, s;
    
    cout << "Enter Year (1970-2038): "; cin >> y;
    cout << "Month (1-12): "; cin >> m;
    cout << "Day (1-31): "; cin >> d;
    cout << "Hour (0-23): "; cin >> h;
    cout << "Minute (0-59): "; cin >> min;
    cout << "Second (0-59): "; cin >> s;

    if (y < 1970 || y > 2038 || m < 1 || m > 12 || d < 1 || d > 31 || 
        h < 0 || h > 23 || min < 0 || min > 59 || s < 0 || s > 59) {
        cout << "\n[ERROR] Please enter value within the right range" << endl;
        return;
    }

    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    t.tm_hour = h;
    t.tm_min = min;
    t.tm_sec = s;
    t.tm_isdst = -1;

    time_t res = mktime(&t);

    if (res == -1) {
        cout << "\n[ERROR] Conversion failed. The date might be invalid." << endl;
    } else {
        cout << "\nEpoch: " << res << endl;
    }
}

void tsToDate() {
    long long input;
    cout << "Enter timestamp: ";
    cin >> input;
    time_t t = (time_t)input;
    cout << "Date: " << ctime(&t);
}