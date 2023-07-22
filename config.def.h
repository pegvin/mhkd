/* This file is an example. You must configure this yourself. */

bool debug_print_spawned_command = false;

struct MouseEvent mouse_events[] = {
    { ButtonPress,   Mod4Mask, Button1, IgnoreMouseInfo, "katriac client_move_mouse down" },
    { MotionNotify,  Mod4Mask, Button1, IgnoreMouseInfo, "katriac client_move_mouse motion" },
    { ButtonRelease, Mod4Mask, Button1, IgnoreMouseInfo, "katriac client_move_mouse up" },

    { ButtonPress,   Mod4Mask, Button3, IgnoreMouseInfo, "katriac client_resize_mouse down" },
    { MotionNotify,  Mod4Mask, Button3, IgnoreMouseInfo, "katriac client_resize_mouse motion" },
    { ButtonRelease, Mod4Mask, Button3, IgnoreMouseInfo, "katriac client_resize_mouse up" },

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
    { ButtonPress,   Mod4Mask, Button2, AppendMouseInfo, "something_mouse down" },
    { MotionNotify,  Mod4Mask, Button2, AppendMouseInfo, "something_mouse move" },
    { ButtonRelease, Mod4Mask, Button2, AppendMouseInfo, "something_mouse up" },
};

struct KeyEvent key_events[] = {
    /* katriawm */
    { KeyPress, Mod4Mask, XK_j, "katriac client_select next" },
    { KeyPress, Mod4Mask, XK_k, "katriac client_select prev" },
    { KeyPress, Mod4Mask, XK_o, "katriac client_select recent" },

    /* Applications */
    { KeyPress, Mod4Mask, XK_Return, "terminal-wrapper" },
    { KeyPress, Mod4Mask, XK_space, "browser-inputline" },
    { KeyPress, Mod4Mask | ShiftMask, XK_c, "browser-clipboard-wrapper" },
    { KeyPress, Mod4Mask | Mod1Mask | ShiftMask, XK_y, "jslock" },
};

