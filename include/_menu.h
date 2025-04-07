#ifndef _MENU_H
#define _MENU_H

enum Page{
    Page_Landing = 0,
    Page_MainMenu = 1,
    Page_Game = 2,
    Page_Help = 3
    };

class _menu
{
    public:
        _menu();
        virtual ~_menu();
        Page gPage = Page_Landing; // Initial Page is the landing page
        void DisplayMainMenu();
        void DisplayGame();
        void display();
    protected:

    private:
};

#endif // _MENU_H
