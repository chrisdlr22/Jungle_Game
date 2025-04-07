# CSCI 178 Midterm - Christian De La Rosa

## Task

For my CSCI 178 Midterm, I was tasked with creating multiple functional screens for my game using the provided game engine. These screens include:

- A **Landing Page**
- A **Main Menu Page**
- A **Gameplay Page**
- A **Help Page**
- A **Popup Menu Page**

Each screen needed to follow a specific sequence and user interaction pattern as outlined in the midterm instructions.

---

## Instructions

Upon launching the game, the user is greeted by the **Landing Page**, which displays the name of the game, **"Jungle Adventure"**, along with a prompt to press **Enter** to proceed.

Pressing **Enter** leads to the **Main Menu**, which displays the game title and three options:

- **New Game** – Press **'N'** to start a new game and enter the **Gameplay Page**.
- **Help** – Press **'H'** to view the **Help Page**.
- **Quit** – Press **Escape** to exit the game.

### Gameplay Page:
While in the game:
- Pressing **Escape** opens a **Popup Menu**, pausing the game and prompting the user to confirm exit:
  - Press **Enter** to **exit** the game.
  - Press **Escape** to **resume** gameplay.

### Help Page:
The **Help Page** displays instructions on how to play the game (note: this version includes placeholder content as it's a demo).  
- Press **Escape** to return to the **Main Menu**.

You can also return to the **Landing Page** at any time from the **Main Menu** by pressing **'L'**.

---

## Approach

My initial approach was inspired by web design, where I wanted to create interactive button elements similar to those found on websites. I created a `Button` class with `initButton` and `drawButton` functions to display button images on top of the background for both the **Landing Page** and **Main Menu**.

However, I encountered difficulties when attempting to detect mouse hover and clicks over these buttons. Specifically, I struggled with accurately tracking mouse `x` and `y` coordinates, which made the click detection unreliable.

After spending a few days trying differrent approaches to this, I pivoted to a more keyboard-focused model. Instead of clickable buttons, I implemented a keyboard-driven navigation system.

I introduced an `enum Page` definition that controls the current screen state with four main states:
- `Landing`
- `Main Menu`
- `Game`
- `Help`

I then created a `Menu` class to manage the page flow and initialized the game to start on the **Landing Page**.

Within my `winMsg` function (inside `scene`), I implemented key handlers for the following controls:

### Controls Summary:

**Landing Page**
- Press **Enter** to go to the Main Menu

**Main Menu**
- Press **'N'** for New Game
- Press **'H'** for Help
- Press **Escape** to Quit
- Press **'L'** to return to Landing Page

**Help Page**
- Press **Escape** to return to the Main Menu

**Gameplay Page**
- Press **Escape** to pause the game and open the Popup

**Pause Popup**
- Press **Enter** to exit the game
- Press **Escape** to resume the game

## Final Thoughts

This keyboard-based navigation allowed me to meet all the requirements specified in the midterm instructions, while also maintaining a clean and functional interface. While I originally intended to implement mouse interactions, the final result uses keyboard input exclusively to provide a smoother user experience. In the future I want to actually implement a functioning feature with mouse interactions and working buttons but that will come with my finished final project. 
