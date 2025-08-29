#include <cctype>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

// ====== Basic Color Macros (4-bit & 24-bit ANSI codes) ======
#define Red "\033[0;31m"
#define Blue "\033[0;34m"
#define Yellow "\033[0;33m"
#define Green "\033[0;32m"
#define Reset "\033[0m"

// 24-bit (RGB) foreground and background colors
#define RGB_Color(r,g,b) "\033[38;2;" #r ";" #g ";" #b "m"
#define RGB_Color_BG(r,g,b) "\033[48;2;" #r ";" #g ";" #b "m"

// ====== ASCII art messages ======
auto breakStarting() -> void {
    // Message + art for breaks
    std::cout << "\n" << RGB_Color(81, 53, 68) << R"(
 /\_/\
( o.o )
 > ^ <

🛑 Pause. Recharge your spirit.
)" << Reset << "\n";
}

auto sessionStarting() -> void {
    // Message + art for focus sessions
    std::cout << "\n" << RGB_Color(110, 0, 0) << R"(
   (  )
  (    )
 (  🔥  )
  (    )
   (  )

⚔️ Time to rise. Focus, warrior!
)" << Reset << "\n";
}

auto leaving() -> void {
    // Message + art when user quits
    std::cout << "\n" << RGB_Color(34, 137, 130) << R"(
 \o/
  |
 / \

👋 Until next time, hero.
)" << Reset << "\n";
}

// ====== Timer functions ======

// Display timer in MM:SS format (switches color depending on time left)
auto PromodoroCount(int promo_Count)->void{
    int promo_Mins = promo_Count / 60;
    int promo_Secs = promo_Count % 60;

    // If more than 1 min left → Blue, else Red
    std::string colorForTime = (promo_Count >= 60)? Blue : Red;

    std::cout << colorForTime 
              << "\r" << std::setw(2) << std::setfill('0') << promo_Mins 
              << ":" << std::setw(2) << std::setfill('0') << promo_Secs 
              << " " << std::flush << Reset;
}

// Countdown loop for sessions/breaks
auto PromodoroCountDown(int promo_Count_Down)->void{
    while(promo_Count_Down >= 0){
        PromodoroCount(promo_Count_Down);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        promo_Count_Down--;
    }
}

// Fake mini countdown (used on exit animation)
auto fakePromoCount(int fakeCount)->void{
    int noMins = 0;
    int fakeSecs = fakeCount % 60;

    std::cout << RGB_Color(178,34,34) 
              << "\r" << std::setw(2) << std::setfill('0') << noMins 
              << ":" << std::setw(2) << std::setfill('0') << fakeSecs 
              << " " << std::flush << Reset;
}

auto fakePromoCountDown(int fake_Count_Down)->void{
    while(fake_Count_Down >= 0){
        fakePromoCount(fake_Count_Down);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fake_Count_Down--;
    }
}

// Convert minutes → seconds
auto TimeConverter(int m)->int { return m * 60; }

// Ask user if they want to continue or exit
auto promoDecssion()->void{
    char op;

    std::cout << RGB_Color(176,196,222) 
              << "Do you wanna Continue? \nYes [Y] \nNo [N] " 
              << Reset << "\n";
    std::cin >> std::ws >> op;
    op = std::toupper(op);

    if(op != 'Y'){
        std::cout << Red << "Exiting..." << Reset << "\n";
        leaving();
        fakePromoCountDown(3);
        exit(EXIT_SUCCESS); 
    }
}

// ====== MAIN PROGRAM ======
auto main()->int{
    std::cout << RGB_Color(230,230,250) 
              << "beta v4,5 Promodoro CLI App " << Reset << "\n";

    // Default session/break times
    int workMins = 25;
    int sBreakMins = 5;
    int bBreakMins = 15;
    int Upromodoro_break; // for custom break input
    int session = 0;      // track number of completed sessions
    char op;              // main start/quit choice
    char ope;             // break menu choice

    // Convert all to seconds
    int WM = TimeConverter(workMins);
    int sBM = TimeConverter(sBreakMins);
    int bBM = TimeConverter(bBreakMins);

    // Session counter color (green until >= 2, then yellow)
    std::string ColorForSession = (session >= 2)? Yellow : Green;

    // ====== UI Intro ======
    std::cout << RGB_Color(171, 149, 50) << "|~_~_~_~_~_~_~_~_~|" << Reset << "\n";
    std::cout << RGB_Color(28, 53, 92) << RGB_Color_BG(115, 123, 126) 
              << "   ⚔️  PROMODORO APP V2.0  ⚔️   " << Reset << "\n";
    std::cout << RGB_Color(171, 149, 50) << "|~_~_~_~_~_~_~_~_~|" << Reset << "\n";
    std::cout << RGB_Color(225, 232, 162) << "    『 Focus Mode Engaged 』    " << Reset << "\n";
    std::cout << RGB_Color(225, 232, 162) << "   🌸 Let the coding saga begin 🌸  " << Reset << "\n";

    // Start/Quit menu
    std::cout << RGB_Color(6, 84, 51) 
              << "🔥『Start Session』[S] — Time to unleash your inner warrior!\n" << Reset;
    std::cout << RGB_Color(180, 19, 27) 
              << "💀『Quit』[Q] — Retreat if you must, but the battle awaits!\n" << Reset;
    std::cin >> std::ws >> op;
    op = std::toupper(op);

    while(true){
        switch(op){
            case 'S': {
                // ====== Focus Session ======
                std::cout << RGB_Color(92, 89, 123) 
                          << "🔥『Focus no Jutsu!』Engaged. Become the main character." 
                          << Reset << "\n";
                sessionStarting();
                PromodoroCountDown(WM); 
                session++;

                // Show session progress
                std::cout << "\n" << ColorForSession << "===============================\n";
                std::cout << "Current Session : " << session << "\n";
                std::cout << "===============================" << Reset << "\n";

                // ====== Break Menu ======
                std::cout << RGB_Color(245, 245, 220) << "1️⃣  Built-in Break  (5 minutes) 🌿" << Reset << "\n";
                std::cout << RGB_Color(245, 245, 220) 
                          << "    🧘‍♂️ *Recommended by the wise masters of time. Balance is power.*" 
                          << Reset << "\n\n";

                std::cout << RGB_Color(245, 245, 220) << "2️⃣  Custom Break ⏱️\n";
                std::cout << RGB_Color(245, 245, 220) 
                          << "    🌀 *Forge your own destiny, set your own limits.*" 
                          << Reset << "\n\n";

                std::cout << RGB_Color(245, 245, 220) 
                          << "💭 Choose your path, young warrior (1 or 2): " << Reset;
                std::cin >> std::ws >> ope;
                ope = toupper(ope);

                // ====== Custom Break Flow ======
                if('2' == ope){
                    std::cout << RGB_Color(245, 245, 220) 
                              << "🌀 The wind whispers... ‘How long will your soul rest before the next battle?’" 
                              << Reset << "\n";
                    std::cout << RGB_Color(245, 245, 220) 
                              << "⏳ Enter your desired break duration in **minutes**, brave warrior: " 
                              << Reset;
                    std::cin >> Upromodoro_break;
                    int UP_B = TimeConverter(Upromodoro_break);
                    PromodoroCountDown(UP_B);

                    promoDecssion();

                // ====== Built-in Break Flow ======
                }else if('1' == ope){
                    breakStarting();
                    std::cout << "\n" << RGB_Color(245, 245, 220) 
                              << "🌙 — Intermission Unlocked —" << Reset << "\n";
                    std::cout << RGB_Color(245, 245, 220) 
                              << "🎐 “A true warrior sharpens both sword and soul between battles.”" 
                              << Reset << "\n";
                    std::cout << RGB_Color(245, 245, 220) 
                              << "⏳ Break Time: 5 minutes" << Reset <<"\n\n";

                    PromodoroCountDown(sBM);

                    std::cout << RGB_Color(245, 245, 220) 
                              << "\n🌅 The dawn breaks... your rest is complete." << Reset << "\n";
                    std::cout << RGB_Color(245, 245, 220) 
                              << "⚔️ The next battle awaits, warrior — stand tall and fight!" 
                              << Reset << "\n\n";

                    promoDecssion();
                }

                // ====== Long Break Flow ======
                if(4 == session){
                    std::cout << "\n" << RGB_Color(245, 245, 220) 
                              << "🌸 — Arc Complete: Four Seasons Conquered —" << Reset << "\n";
                    std::cout << RGB_Color(245, 245, 220) 
                              << "🔥 This is your *Long Break*." << Reset << "\n";
                    std::cout << RGB_Color(245, 245, 220) 
                              << "⏳ Break Time: 15 minutes" << Reset << "\n\n";
                    std::cout << "\n" << RGB_Color(245, 245, 220) 
                              << "🔥 Energy restored, your spirit blazes anew!" << Reset << "\n\n";
                    breakStarting();
                    PromodoroCountDown(bBM); 
                    session = 0; // reset session counter
                    promoDecssion();
                }
            }
            break;

            case 'Q': {
                // Quit flow
                std::cout << Red << "Exiting..." << Reset << "\n";
                leaving();
                exit(EXIT_SUCCESS);
                break;
            }

            default: 
                std::cout << "Invalid input"; 
                break;
        }
    }
  return 0;
}