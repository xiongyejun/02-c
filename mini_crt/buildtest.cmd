cl /c /DWIN32 test.c
link test.obj minicrt.lib kernel32.lib /NODEFAULTLIB /entry:mini_crt_entry