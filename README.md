🧸 Promodoro CLI Timer – C++ Edition (V3.4-0)

> Terminal-based Pomodoro timer with colorful ANSI visuals, anime-inspired ASCII art, and smooth C++ threading ✨
Built for focus, chill breaks, and good coding vibes.




---

🧠 What is this?

A fun and functional Pomodoro CLI timer written in modern C++, designed to keep you motivated and entertained while coding.

It now includes:

⏱️ 25-minute focus sessions with dramatic countdown, color transitions (Blue → Red near end), and anime-style motivational ASCII art

💤 5-minute short breaks and 15-minute long breaks automatically after every 4 focus sessions

🐱🐻🐰 Cute ASCII companions for focus, break, and exit prompts

🌈 24-bit RGB ANSI colors, plus fallback 4-bit color macros for terminals that don’t support full RGB

🔄 Choice between built-in or custom breaks each session

🎭 Dramatic “Continue or Quit” prompts with mini exit countdown for dojo vibes

🧵 Smooth timer delay using std::this_thread::sleep_for()



---

🎮 How to Run It

1. Clone this repo:



git clone https://github.com/YOUR_USERNAME/promodoro-cli.git
cd promodoro-cli

2. Compile the program:



g++ -std=c++17 -o promodoro promodoro.cpp

3. Run it:



./promodoro

> 💡 Make sure your terminal supports ANSI colors (most modern terminals do).




---

📸 Sneak Peek

Start a focus session:

(  )
  (    )
 (  🔥  )
  (    )
   (  )

⚔️ Time to rise. Focus, warrior!

During break:

/\_/\
( o.o )
 > ^ <

🛑 Pause. Recharge your spirit.

On exit:

\o/
  |
 / \

👋 Until next time, hero.


---

🔧 Features & Tech

Modern C++17 with clear modular functions (countdowns, breaks, UI prompts)

std::setw & std::setfill for neat MM:SS timer formatting

24-bit RGB color macros with optional 4-bit fallback

Built-in vs custom break selection per session

Automatic long break every 4 focus sessions

Mini exit countdown with dramatic ASCII art



---

🚧 Upcoming Power-Ups

🧠 Session XP System – track completed sessions like an RPG

🔕 Silent Mode (--ninja) – stealth timer with no ASCII art

🔔 Break/Focus sound cues – terminal beeps for mode changes

📊 Session Stats Dashboard – track daily/weekly productivity

🧘 Zen Mode – motivational quotes/haiku during breaks

🎵 Optional background music/lo-fi tracks

🛠️ Custom timer durations via CLI or config file



---

💖 Why I Made This

> Practicing logic + modern C++ while making something fun.
Inspired by ADHD brains like mine who need breaks, rewards, and a little anime hype 🤪💻




---

🆕 What’s New in v4.5

Added 24-bit RGB ANSI colors for focus, break, and exit screens

Maintains built-in & custom break choices each session

Automatic long breaks after 4 sessions

Exit countdown animation with mini timer

Cleaner modular code, keeping your anime/dojo vibes intact

Minor bug fixes and better session handling



---

💖 Credits

Made with love and caffeine by Nyx
ASCII art handcrafted for maximum anime vibes ✨


---