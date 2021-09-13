include(FetchContent)
FetchContent_Declare(mahi-gui GIT_REPOSITORY https://github.com/mahilab/mahi-gui.git)
FetchContent_MakeAvailable(mahi-gui)

create_module(
        TYPE executable
        VERSION 0.0.1
        DESCRIPTION Random GUI visualization
        DEPENDENCIES mahi::gui distribution
)