# Promodoro-CLI-App

# 🧸 Pomodoro CLI Timer – C++ Edition

> A cozy lil' terminal-based Pomodoro timer, featuring cute ASCII animals, ANSI color styling, and modern C++ threading ✨  
Built with ✨ focus, 🍵 breaks, and 💻 vibes in mind.

---

## 🧠 What is this?

A fun and functional **Pomodoro timer** written in **C++**, made for productivity freaks and terminal lovers.

It includes:
- ⏱️ 25-minute focus sessions
- 💤 5-minute short breaks
- 🧠 15-minute long breaks after 4 sessions
- 🐱🐻🐰 Cute ASCII art companions to keep you company
- 🌈 ANSI terminal colors to spice things up
- 🧵 Uses modern `std::this_thread::sleep_for()` for timing

---

## 🎮 How to Run It

1. Clone this repo:
   ```bash
   git clone https://github.com/YOUR_USERNAME/pomodoro-cli-cpp.git
   cd pomodoro-cli-cpp

2. Compile the program:

g++ -std=c++17 -o pomodoro pomodoro.cpp


3. Run it!

./pomodoro



> 💡 Make sure your terminal supports ANSI colors (most modern ones do).




---

📸 Sneak Peek

🍅 Start the Session [S]
  ❌ Quit [Q]

🐱 When you start a session:

／ﾌﾌ 　(＾• ω •＾) 💻
(　⌒)⌒)＿_ノ
...
🐾 Typing away...
┏━ Focus Mode ━┓
┃ No distractions 😼┃
┗━━━━━━━━━━━━┛

🐻 When break time hits:

ʕっ-ᴥ-ʔっ
(っ˘︶˘ς)    zzz...
┏━🧸━━━━━━┓
┃ it's breakie     ┃
┃ go rest ya eyes~ ┃
┗━━━━━━━━━━━━━━┛

🐰 On exit:

(\(\
( -.-)       ✨
o_(")(")    🧳
┏━ Time to go ━┓
┃ great job today~┃
┃ see you soon! ☁️┃
┗━━━━━━━━━━━━━━┛


---

🔧 Features & Tech

Modern C++17

Cleanly separated logic (promodoroCounter, promodoroBreakCounter, etc.)

Uses std::setw, std::setfill for timer formatting

ANSI color macros with #define

Fun ASCII art built in 😎



---

✅ To-Do / Ideas

[ ] Configurable times (e.g., set your own break durations)

[ ] Sound/beep at the end of timers

[ ] Background music via system calls? 🎶

[ ] Stats tracking (sessions per day, total time)

[ ] Cute loading animation for fun



---

🧠 Why I Made This

> Just practicing logic + modern C++ while making something fun.
Inspired by ADHD brains like mine who need breaks + rewards 🤪💅
Also: terminal apps are cool and way more customizable than mobile apps.




---

💖 Credits

Made with love (and a bit of caffeine) by Nyx
ASCII art handcrafted using raw vibe ✨


---
