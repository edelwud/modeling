CPMAddPackage(
        GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
        GIT_TAG master)

create_module(
        TYPE executable
        VERSION 0.0.1
        DESCRIPTION Random GUI visualizer
        DEPENDENCIES
            ftxui::screen
            ftxui::dom
            ftxui::component

            random
)