/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
#define ICONSIZE bh   /* icon size (bh = bar height) */
#define ICONSPACING 5 /* space between icon and title */
static const char buttonbar[]       = "󰣑 |";
static const char *fonts[]          = { "Hermit:pixelsize=14:antialias=true:autohint=true","Symbols Nerd Font:pixelsize=18:antialias=true:autohint=true"};
static const char dmenufont[]       = "monospace:size=10";

/* colors definitions */
static const char default_bg[]      = "#282d2a";
static const char default_fg[]      = "#f6f3e8";
static const char default_gray[]    = "#656868";
static const char col_midgray[]     = "#635770";
static const char col_lightblue[]   = "#8ac6f2";
static const char col_coral[]       = "#f28b86";
static const char col_lightpurple[] = "#bf93c3";
static const char col_orange[]      = "#ea9847";
static const char col_lightgreen[]  = "#86b187";
static const char col_sand[]        = "#e0d063";
static const char col_pink[]        = "#e18cbb";
static const char col_teal[]        = "#65a399";
static const char col_red[]         = "#e2434c";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_purple[]      = "#8542ff";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { default_fg, default_bg, default_fg },
	[SchemeSel]  = { col_sand, default_bg,  col_sand  },
	[SchemeHid]  = { col_midgray,  default_bg,  default_bg },
	[SchemeButn] = { default_fg,   default_bg, default_bg },
	[SchemeLayt] = { default_fg, default_bg, default_bg},
};

static const char *tagsel[][2][2] = {
	/*      norm                          sel       */
	/*  fg          bg              fg          bg  */
	{ { col_lightblue  , default_bg }, { default_fg, default_bg } },
	{ { col_coral      , default_bg }, { default_fg, default_bg } },
	{ { col_lightpurple, default_bg }, { default_fg, default_bg } },
	{ { col_orange     , default_bg }, { default_fg, default_bg } },
	{ { col_lightgreen , default_bg }, { default_fg, default_bg } },
	{ { col_sand       , default_bg }, { default_fg, default_bg } },
	{ { col_pink       , default_bg }, { default_fg, default_bg } },
	{ { col_teal       , default_bg }, { default_fg, default_bg } },
	{ { col_red        , default_bg }, { default_fg, default_bg } },
};

/* tagging and rules */
static const char *tags[] = { "", "󰣆", "", "", "", "󰙯", "", "", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int momentaryalttags = 1; /* 1 means alttags will show only when key is held down*/
static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  	/* class      instance    title       tags mask     switchtotag    isfloating   monitor */

        { "Gimp",     NULL,       NULL,       0,            1,             1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 4,       1,             0,           -1 },
	{ "Emacs",    NULL,       NULL,       1 << 2,       1,             0,           -1 }, 
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "| []=",      tile },    /* first entry is default */
	{ "| [M]",      monocle },
	{ "| [@]",      spiral },
	{ "| [\\]",     dwindle },
	{ "| H[]",      deck },
	{ "| TTT",      bstack },
	{ "| ===",      bstackhoriz },
	{ "| HHH",      grid },
	{ "| ###",      nrowgrid },
	{ "| ---",      horizgrid },
	{ "| :::",      gaplessgrid },
	{ "| =M=",      centeredmaster },
	{ "| >M>",      centeredfloatingmaster },
	{ "| ><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask /* changed from Mod1Mask (default) to Mod4Mask (Super key) */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      viewoccupied,    {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *roficmd[] = { "spade-rofi-launch.sh", NULL};
static const char *rofiwincmd[] = { "spade-rofi-win.sh", NULL};
static const char *termcmd[]  = { "st", "-z", "19", NULL };
static const char *xmenucmd[] = { "spade-xmenu.sh", NULL };
static const char *layoutmenu_cmd = "layoutmenu.sh";

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY,                       XK_s,      showall,        {0} },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_s,      show,           {0} },
	{ MODKEY|ShiftMask,             XK_h,      hide,           {0} },

	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_y,      incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_u,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_y,      defaultgaps,    {0} },

	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_v,      setlayout,      {.v = &layouts[13]} },
	{ MODKEY,                       XK_d,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[11]} },
	{ MODKEY,                       XK_r,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_g,      zoom,           {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_n,      togglealttag,   {0} },

	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_w,      spawn,          {.v = rofiwincmd } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkButton,		0,		Button1,	spawn,		{.v = xmenucmd } },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button1,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
