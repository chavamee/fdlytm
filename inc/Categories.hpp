#ifndef APPLICATION_CTG_MENU_H_
#define APPLICATION_CTG_MENU_H_

#include "Entries.hpp"
#include <ncf/Menu.hpp>

class Categories : public ncf::Menu {
    public:
        Categories(Fdly& server, ncf::Menu& entriesMenu);

        virtual ~Categories();

        void onItemAction(ncf::Menu::Item* item) override;

        void markCategoryRead();

        int onKeyEvent(int ch) override;

    private:
        Menu& m_entriesMenu;
        Fdly& m_server;
        std::string lastReadEntryId = "";
};

#endif
