#include <cctype>      // For std::toupper
#include <chrono>      // For std::chrono::seconds
#include <cstdlib>     // For exit()
#include <iomanip>     // For std::setw + std::setfill
#include <iostream>    // For std::cout, std::cin
#include <ostream>     // Not needed, already included by iostream
#include <thread>      // For std::this_thread::sleep_for

// ANSI color macros for terminal styling
#define Red "\x1b[31m"
#define Green "\x1b[32m"
#define Blue "\x1b[34m"
#define Reset "\x1b[0m"
#define Cyan "\033[0;36m"    
#define BG_Green "\033[0;42m"

// Timer display function — handles formatting mm:ss
auto promodoroTimer(int timeleft)->void{
    int mins = timeleft / 60;
    int secs = timeleft % 60;

    std::cout << "\r" << std::setw(2) << std::setfill('0') << mins << ":"
              << std::setw(2) << std::setfill('0') << secs << " " << std::flush;
}

// Countdown for focus/work session
auto pmodoroCounter(int totalTime)->void{
    while(totalTime >= 0){
        promodoroTimer(totalTime);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        totalTime--;
    }
}

// Timer display for breaks (duplicate of above, but allowed here since logic can't be touched)
auto promodoroBreak(int breakTime)->void{
    int mins = breakTime / 60;
    int secs = breakTime % 60;

    std::cout << "\r" << std::setw(2) << std::setfill('0') << mins << ":"
              << std::setw(2) << std::setfill('0') << secs << " " << std::flush;
}

// Countdown for break session
auto promodoroBreakCounter(int totalBreakTime)->void{
    while(totalBreakTime >= 0){
        promodoroBreak(totalBreakTime);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        totalBreakTime--;
    }
}

// Cute bear ASCII for break time
void showBreakBear() {
    std::cout << R"(
    ʕっ-ᴥ-ʔっ
   (っ˘︶˘ς)    zzz...
   ┏━🧸━━━━━━┓
   ┃ it's breakie     ┃
   ┃ go rest ya eyes~ ┃
   ┗━━━━━━━━━━━━━━┛
    )" << '\n';
}

// Cat focus ASCII for focus time
void showFocusCat() {
    std::cout << R"(
     ／ﾌﾌ 　(＾• ω •＾) 💻
   (　⌒)⌒)＿_ノ
   /　ﾉ⌒ ／ ／⌒ヽ
  ｜　/　| ｜   |｜
   しーＪ　しーＪ
   🐾 Typing away...
   ┏━ Focus Mode ━┓
   ┃ No distractions 😼┃
   ┗━━━━━━━━━━━━┛
    )" << '\n';
}

// Bunny goodbye ASCII for quitting
void showLeavingBunny() {
    std::cout << R"(
    (\(\
   ( -.-)       ✨
   o_(")(")    🧳
 ┏━ Time to go ━┓
 ┃ great job today~┃
 ┃ see you soon! ☁️┃
 ┗━━━━━━━━━━━━━━┛
    )" << '\n';
}

// Main function – CLI controller for pomodoro logic
auto main()->int{

    // Intro splash
    std::cout << "===========================================\n";
    std::cout << BG_Green << "  PROMODORO CLI APP V1.0                  " << Reset << "\n";
    std::cout << "============================================\n";
  
    char op;

    // Timer values
    int promodoroTime = 1500;      // 25 minutes
    int breakTime;                 // (Unused)
    int shortBreakTime = 300;      // 5 minutes
    int longBreakTime = 900;       // 15 minutes
    int Session = 0;               // Track completed sessions

    // Infinite loop for user interaction
    while(true){
        std::cout << Green << "🍅 Start the Session [S]" << Reset << Red << "\n" 
                  << "❌ Quit [Q] " << Reset << "\n";

        std::cin >> op;
        op = std::toupper(op);  // Allow lowercase input too

        switch(op){
            case 'S':
                showFocusCat();                   // Show cat
                pmodoroCounter(promodoroTime);   // Start focus timer
                Session++;                        // Add 1 session

                std::cout << "\n Promodoro Sessions : " << Session << "\n";

                if(Session == 4){
                    showBreakBear();  // Long break
                    std::cout << Blue << "Take a long break you've already done four promodoro sessions \n " << Reset;
                    promodoroBreakCounter(longBreakTime);
                    Session = 0;  // Reset session count
                } else {
                    showBreakBear();  // Short break
                    std::cout << Cyan << "Take a short Break \n " << Reset;
                    promodoroBreakCounter(shortBreakTime);
                }
                break;

            case 'Q':
                showLeavingBunny();  // Exit visual
                exit(EXIT_SUCCESS);  // Clean exit
                break;

            default:
                std::cout << Red << "Invalid input try again \n " << Reset;
                continue;
        }
    }
}
