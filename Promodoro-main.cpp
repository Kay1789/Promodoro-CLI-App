#include <cctype>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

// Terminal color macros
#define Red "\033[0;31m"
#define Green "\033[0;32m"
#define Blue "\033[0;34m"
#define BG_Cyan "\033[0;106m"
#define Reset "\033[0m"
#define BHI_Magenta "\033[1;95m"
#define BHI_Cyan "\033[1;96m"
#define BHI_Green "\033[1;92m"
#define Cyan "\033[0;36m"

// Draws the timer in mm:ss format with color based on remaining time
auto PromodoroTimer(int totalTimer) -> void {
    int mins = totalTimer / 60;
    int secs = totalTimer % 60;

    std::string colorForTime = (totalTimer <= 60) ? Red : Blue;

    std::cout << colorForTime << "\r"
              << std::setw(2) << std::setfill('0') << mins << ":"
              << std::setw(2) << std::setfill('0') << secs << " "
              << std::flush << Reset;
}

// Handles the countdown loop, ticking down every second
auto PromodoroCountDown(int totalCountDown) {
    while (totalCountDown >= 0) {
        PromodoroTimer(totalCountDown);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        totalCountDown--;
    }
}

// Shows a static countdown without logic (used for exiting)
auto contiuneCountDown(int exitTime) -> void {
    int noMins = 0;

    std::cout << Green << "\r"
              << std::setw(2) << std::setfill('0') << noMins << ":"
              << std::setfill('0') << exitTime << " "
              << std::flush << Reset;
}

// Break-time ASCII art & message
auto breakStarting() -> void {
    std::cout << BHI_Cyan << R"(
 /\_/\
( o.o )
 > ^ <

🛑 Pause. Recharge your spirit.
)" << Reset;
}

// Focus-time ASCII art & message
auto sessionStarting() -> void {
    std::cout << BHI_Green << R"(
   (  )
  (    )
 (  🔥  )
  (    )
   (  )

⚔️ Time to rise. Focus, warrior!
)" << Reset;
}

// Goodbye ASCII art & message
auto leaving() -> void {
    std::cout << BHI_Magenta << R"(
 \o/
  |
 / \

👋 Until next time, hero.
)" << Reset;
}

// Asks user whether they wanna continue or quit
auto WannaContiune() -> void {
    char ch;
    int exitOk = 3;

    std::cout << Cyan << "\n➤ Shall we press on to the next mission? [Y/N]: " << Reset;
    std::cin >> ch;
    ch = std::toupper(ch);

    // If they said no, do a dramatic exit countdown and quit
    if (ch != 'Y') {
        std::cout << Red << "Logging out of the dojo... See you next battle!\n" << Reset;
        while (exitOk >= 0) {
            contiuneCountDown(exitOk);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            exitOk--;
        }
        leaving();
        exit(EXIT_SUCCESS);
    }
}

// 🧠 Main program logic: handles flow between focus + breaks + custom breaks
auto main() -> int {
    char op, ope, ch;
    int promodoro_focus = 1500;       // 25 min
    int Spromodoro_break = 300;       // 5 min short break
    int Lpromodoro_break = 900;       // 15 min long break
    int Upromodoro_break;             // custom break
    int Session = 0;                  // track session count

    // 💻 Intro UI stuff
    std::cout << BHI_Magenta << "|~_~_~_~_~_~_~_~_~|" << Reset << "\n";
    std::cout << Blue << BG_Cyan << "   ⚔️  PROMODORO APP V2.0  ⚔️   " << Reset << "\n";
    std::cout << BHI_Magenta << "|~_~_~_~_~_~_~_~_~|" << Reset << "\n";
    std::cout << Blue << "    『 Focus Mode Engaged 』    " << Reset << "\n";
    std::cout << Blue << "   🌸 Let the coding saga begin 🌸  " << Reset << "\n";

    std::cout << Green << "🔥『Start Session』[F] — Time to unleash your inner warrior!\n" << Reset;
    std::cout << Red << "💀『Quit』[Q] — Retreat if you must, but the battle awaits!\n" << Reset;

    std::cin >> op;
    op = std::toupper(op);

    while (true) {
        switch (op) {
            case 'F': {
                sessionStarting();
                std::cout << "🔥『Focus no Jutsu!』Engaged. Become the main character.\n";
                Session++;
                PromodoroCountDown(promodoro_focus);

                // Focus session done
                std::cout << "\n⚔️ Training arc: COMPLETE.\n";
                std::cout << "💤 Rest well, young warrior... the next challenge awaits.\n";

                std::string SessionColor = (Session >= 2) ? Green : Red;

                std::cout << SessionColor << "===============================\n";
                std::cout << "Current Session : " << Session << "\n";
                std::cout << "===============================" << Reset << "\n";

                // Ask for break type
                std::cout << "1️⃣  Built-in Break  (5 minutes) 🌿\n";
                std::cout << "    🧘‍♂️ *Recommended by the wise masters of time. Balance is power.*\n\n";

                std::cout << "2️⃣  Custom Break ⏱️\n";
                std::cout << "    🌀 *Forge your own destiny, set your own limits.*\n\n";

                std::cout << "💭 Choose your path, young warrior (1 or 2): ";
                std::cin >> ope;
                ope = toupper(ope);

                if (ope != '1') {
                    // Custom break flow
                    std::cout << "\n🌀 The wind whispers... ‘How long will your soul rest before the next battle?’\n";
                    std::cout << "⏳ Enter your desired break duration in **minutes**, brave warrior: ";
                    std::cin >> Upromodoro_break;
                    PromodoroCountDown(Upromodoro_break * 60);

                    WannaContiune();
                } else {
                    // Built-in short break flow
                    breakStarting();
                    std::cout << "\n🌙 — Intermission Unlocked —\n";
                    std::cout << "🎐 “A true warrior sharpens both sword and soul between battles.”\n";
                    std::cout << "⏳ Break Time: 5 minutes\n\n";

                    PromodoroCountDown(Spromodoro_break);

                    std::cout << "\n🌅 The dawn breaks... your rest is complete.\n";
                    std::cout << "⚔️ The next battle awaits, warrior — stand tall and fight!\n\n";

                    WannaContiune();

                    // Long break logic after 4 sessions
                    if (Session == 4) {
                        std::cout << "\n🌸 — Arc Complete: Four Seasons Conquered —\n";
                        std::cout << "🔥 This is your *Long Break*.\n";
                        std::cout << "⏳ Break Time: 15 minutes\n\n";

                        PromodoroCountDown(Lpromodoro_break);
                        Session = 0;

                        std::cout << "\n🔥 Energy restored, your spirit blazes anew!\n";
                        WannaContiune();
                    }
                }
                break;
            }

            case 'Q': leaving(); exit(EXIT_SUCCESS); break;

            default:
                std::cout << "Invalid input try again \n";
                continue;
        }
    }
}
