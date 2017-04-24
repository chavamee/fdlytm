#ifndef APPLICATION_CTG_MENU_H_
#define APPLICATION_CTG_MENU_H_

#include "ncf/Menu.hpp"
#include "EntriesMenu.hpp"
#include "fdly.hpp"

class Categories : public ncf::Menu {
    public:
        Categories();

        Categories(Fdly& server, ncf::Menu& entriesMenu) :
            Menu(),
            m_entriesMenu {entriesMenu},
            m_server {server}
        {
        }

        virtual ~Categories();

        void onItemAction(ncf::Menu::Item* item) override;

        void markCategoryRead();

        int onKeyEvent(int ch) override;

    private:
        Menu& m_entriesMenu = nullptr;
        Fdly& m_server;
        std::string lastReadEntryId = "";
};

#endif
