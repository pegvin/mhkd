#include <X11/XF86keysym.h>

bool debug_print_spawned_command = false;

struct MouseEvent mouse_events[] = {
    // { ButtonPress,   Mod4Mask, Button1, IgnoreMouseInfo, "do_something down" },
    // { MotionNotify,  Mod4Mask, Button1, IgnoreMouseInfo, "do_something move" },
    // { ButtonRelease, Mod4Mask, Button1, IgnoreMouseInfo, "do_something up" },

    // { ButtonPress,   Mod4Mask, Button3, IgnoreMouseInfo, "do_something down" },
    // { MotionNotify,  Mod4Mask, Button3, IgnoreMouseInfo, "do_something move" },
    // { ButtonRelease, Mod4Mask, Button3, IgnoreMouseInfo, "do_something up" },

    /* When using AppendMouseInfo, additional information will be
     * appended to your command. For ButtonPress and ButtonRelease,
     * it's:
     *
     *   $command $x $y $window
     *
     * For MotionNotify:
     *
     *   $command $x $y $window $serial
     *
     * $x and $y are the location of the mouse pointer relative to the
     * root window. $window is the window ID currently below the
     * pointer.
     *
     * There is no guarantee that your commands will be run in correct
     * order. If you depend on ordering, you can use $serial to discard
     * events from the past by only processing events if the serial is
     * greater than what you have seen before.
     *
     * This serial number is a uint32_t. */
    // { ButtonPress,   Mod4Mask, Button2, AppendMouseInfo, "something_mouse down" },
    // { MotionNotify,  Mod4Mask, Button2, AppendMouseInfo, "something_mouse move" },
    // { ButtonRelease, Mod4Mask, Button2, AppendMouseInfo, "something_mouse up" },
    { 0, 0, 0, 0, NULL }
};

struct KeyEvent key_events[] = {
    // { KeyPress, 0, XF86XK_AudioLowerVolume, "bash ~/.local/bin/volume down" },
    // { KeyPress, 0, XF86XK_AudioMute, "bash ~/.local/bin/volume toggle" },
    // { KeyPress, 0, XF86XK_AudioRaiseVolume, "bash ~/.local/bin/volume up" },
    { 0, 0, 0, NULL }
};

