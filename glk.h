#ifclear _GLK_H
#set _GLK_H
 
#ifset VERSIONS
#message "Glk.h Version 1.1"
#endif
 
! Notes: run glkcheck from your init routine
 
global glk
 
 
routine glkcheck
{
	if display.windowlines > (display.screenheight + 100)
		glk = true
}
 
#endif