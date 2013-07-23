This workaround is for Poppler installations without CairoOutputDev.h.

It's not really a good workaround. If there is no CairoOutputDev.h we use
the header files from here, which may not match the current installed Poppler version.

Andreas Butti


I have altered this a little. It's still not good but xournalpp is now packaged with
poppler-0.12.4, and workaround.sh will compile it if the installed (old) library
is not found. The problem is that poppler versions >0.18 have a very different API and
a lot of the code will need to be changed to keep up.

W Brenna

