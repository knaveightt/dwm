# dwm
My build of dwm by suckless
> For version dwm-6.4, for use in my "SPADE" desktop environment (see my repositories)

## Merged Patches
- [restartsig](https://dwm.suckless.org/patches/restartsig/dwm-restartsig-20180523-6.2.diff)
- [autostart](https://dwm.suckless.org/patches/autostart/dwm-autostart-20210120-cb3f58a.diff)
- [alternativetags](https://dwm.suckless.org/patches/alternativetags/dwm-alternativetags-6.3.diff)
- [hide_vacant_tags](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff)
- [underlinetags](https://dwm.suckless.org/patches/underlinetags/dwm-underlinetags-6.2.diff)
- [rainbowtags-modified](https://pastebin.com/raw/MpYmWZyp)
- [statusbutton](https://dwm.suckless.org/patches/statusbutton/dwm-statusbutton-20180524-c8e9479.diff)
- [layoutmenu](https://dwm.suckless.org/patches/layoutmenu/dwm-layoutmenu-6.2.diff)
- [awesomebar](https://dwm.suckless.org/patches/awesomebar/dwm-awesomebar-20220925-6.3.diff)
- [winicon](https://dwm.suckless.org/patches/winicon/dwm-winicon-6.3-v2.1.diff)
- [status2d with systray](https://dwm.suckless.org/patches/status2d/dwm-status2d-systray-6.4.diff)
- [statuscmd](https://dwm.suckless.org/patches/statuscmd/dwm-statuscmd-status2d-20210405-60bb3df.diff)

## Other Modifications
- *viewoccupied* function to allow numeric keys to match numbering of 'occupied tags' only, when selecting a tag to view

## Technical Fixes
- *awesomebar* required a fix that prevented a crash in dwm when clicking in an area where a client window was expected
  to be there in the bar. The fix I implemented was from [this reddit post](https://reddit.com/r/suckless/ibwzhh/with_dwmawesomebar_patch_crash/)