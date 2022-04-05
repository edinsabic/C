<img align="center" width="100%" height="80%" src="https://www.retrogames-online.com/wp-content/themes/retrogames/images/retrogames_logo_v01.png">

---

<p float="left">
  <img align="center" width="200" src="https://user-images.githubusercontent.com/8678755/160507919-ac2d7c53-36fa-4c38-80ae-05623c18482b.png">
  <img align="center" width="200" src="https://www.ubuy.vn/productimg/?image=aHR0cHM6Ly9tLm1lZGlhLWFtYXpvbi5jb20vaW1hZ2VzL0kvODFaTlJISitjSUwuX0FDX1NMMTUwMF8uanBn.jpg">
<p>
  
---
 

  
  <br>
   
## Compile and run (linux, ncurses)
```
cd <game>
gcc -v -o main.exe main.c -lncurses
./main.exe

```

## Create exe distribution for 32 and 64 (windows)
```
cd 003_tick_tac_toe_oop_sdl
./make.bat
cd dist64
./003_tick_tac_toe_oop_sdl.exe
```

## Clang style

```
{BasedOnStyle: WebKit, IndentCaseLabels: true, BreakBeforeBraces: Custom, AllowShortEnumsOnASingleLine: true, AllowShortCaseLabelsOnASingleLine: true,  AllowShortLoopsOnASingleLine: true, BraceWrapping: { AfterFunction: false}, AllowShortIfStatementsOnASingleLine: true, IndentWidth: 2, ColumnLimit: 0, Cpp11BracedListStyle: false, PointerAlignment: Left}"
```