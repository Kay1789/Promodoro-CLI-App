# Promodoro-CLI-App

# 🧸 Pomodoro CLI Timer – C++ Edition

> A cozy lil' terminal-based Pomodoro timer, featuring cute ASCII animals, ANSI color styling, and modern C++ threading ✨  
Built with ✨ focus, 🍵 breaks, and 💻 vibes in mind.

---

## 🧠 What is this?

A fun and functional **Pomodoro timer** written in **C++**, made for productivity freaks and terminal lovers.

It includes:  
- ⏱️ 25-minute focus sessions with anime-style countdown and motivational ASCII art  
- 💤 5-minute short breaks and 🧠 15-minute long breaks after 4 sessions, triggered automatically  
- 🐱🐻🐰 Cute and chill ASCII art companions to keep you hyped  
- 🌈 ANSI terminal colors to spice things up, with colors changing near session end for dramatic effect  
- 🧵 Uses modern `std::this_thread::sleep_for()` for smooth timer delays and clean countdown visuals  
- 🔄 Option to choose built-in or custom breaks each session, with recommended default breaks for balance  
- 🎭 Dramatic prompts asking if you wanna continue or retreat — anime dojo vibes on point  

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

🍅 Start the Session [F]
❌ Quit [Q]

🐱 When you start a session:

(  )
  (    )
 (  🔥  )
  (    )
   (  )

⚔️ Time to rise. Focus, warrior!

🐻 When break time hits:

/\_/\
( o.o )
 > ^ <

🛑 Pause. Recharge your spirit.

🐰 On exit:

\o/
  |
 / \

👋 Until next time, hero.


---

🔧 Features & Tech

Modern C++17 with clean function modularity (countdown, breaks, prompts)

std::setw & std::setfill for pretty timer formatting

ANSI color macros with #define for easy customization

Dramatic session and break prompts with anime-inspired wording

Automatic long breaks after every 4 focus sessions — no extra input needed

User option for custom break lengths or recommended built-in breaks

Cute, minimal ASCII art keeping it chill but recognizable



---

🚧 Upcoming Power-Ups

> Still training. These upgrades are on the scroll:



🧠 Session XP System
Track how many sessions you’ve completed — level up your focus stats like a real RPG.

🔕 Silent Mode (--ninja)
For when you wanna go stealth mode — no ASCII, no prompts, just pure timer discipline.

🔔 Break/Focus Sound Cues
Get a terminal beep or sound to let you know when it's time to switch modes.

📊 Session Stats Dashboard
Daily/weekly stats: how many sessions you crushed, total hours focused, etc.

🧘 Zen Mode
Replace ASCII with motivational quotes or haiku during breaks.

🎵 Background Music (Experimental)
Optional lo-fi system call to launch your fave playlist or ambient track.

🛠️ Customizable Timer Durations
Set your own focus/break/long break times through config or CLI args.



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

🆕 What’s New in V2.0

Added anime-style ASCII art for focus, breaks, and exit screens to hype the user up

Improved timer visuals with color changes for dramatic countdown vibes (blue → red under 60s)

Added choice between built-in (recommended) breaks and custom breaks before each break session

Automatic long breaks after 4 sessions to encourage proper rest

Dramatic “Continue or Quit” prompt with countdown exit animation for that dojo farewell feel

Cleaner, modular C++ code with clear function separation for timers, countdowns, and UI

ANSI color macros for easy customization and more readable output



---
