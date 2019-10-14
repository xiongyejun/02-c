cl /c /DWIN32 /GS- entry.c malloc.c printf.c stdio.c string.c

lib entry.obj malloc.obj printf.obj stdio.obj string.obj /OUT:minicrt.lib